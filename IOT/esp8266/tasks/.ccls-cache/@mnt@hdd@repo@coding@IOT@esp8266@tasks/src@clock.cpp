#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <U8g2lib.h>
#include <WiFiClient.h>

// #define DEBUG

U8G2_SSD1306_128X64_NONAME_1_HW_I2C dpy(U8G2_R0, U8X8_PIN_NONE);

const String WIFI_SSID = "PRIADI_5G";
const String WIFI_PASS = "prince123**";

const String url = "http://api.timezonedb.com/v2.1/"
                   "get-time-zone";

const String API = "UEV7YP2DBI0V";
const String REGION = "Asia/Kolkata";

int offset = 0;

int hours = 0;
int minutes = 0;
int seconds = 0;

char final_hm[6];
char final_s[3];

char hr[3];
char mn[3];
char sec[3];

void setup() {
    dpy.begin();

#ifdef DEBUG
    Serial.begin(115200);
    Serial.print("\nConnecting");
#endif
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
#ifdef DEBUG
        Serial.print('.');
#endif
        delay(1000);
    }
#ifdef DEBUG
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
#endif
}

void loop() {

    if (WiFi.status() == WL_CONNECTED && seconds == 0) {
        WiFiClient client;
        HTTPClient http;

        String path = url + "?key=" + API + "&by=zone&zone=" + REGION;
        http.begin(client, path);
        int http_response = http.GET();

        if (http_response > 0) {
#ifdef DEBUG
            Serial.print("HTTP Response code: ");
            Serial.println(http_response);
#endif
            char *payload = strdup(http.getString().c_str());
            payload = strstr(payload, "formatted");
            *strchr(payload, '<') = '\0';
            payload =
                strchr(payload, ' ') + 1; // +1 to skip over the blank thingy
#ifdef DEBUG
            Serial.println(payload);
#endif

            hr[0] = payload[0];
            hr[1] = payload[1];
            hr[2] = '\0';

            mn[0] = payload[3];
            mn[1] = payload[4];
            mn[2] = '\0';

            sec[0] = payload[6];
            sec[1] = payload[7];
            sec[2] = '\0';

            hours = atoi(hr);
            minutes = atoi(mn);
            seconds = atoi(sec);

        } else {
#ifdef DEBUG
            Serial.print("Error code: ");
            Serial.println(http_response);
#endif
        }

        http.end();
    }

    seconds++;
    if (seconds == 60) {
        seconds = 0;
        minutes++;
    }
    if (minutes == 60) {
        minutes = 0;
        hours++;
    }
    if (hours == 12) {
        hours = 0;
    }

    snprintf(final_hm, sizeof(final_hm), "%02d:%02d", hours, minutes);
    snprintf(final_s, sizeof(final_s), "%02d", seconds);

    dpy.firstPage();
    do {
        dpy.setFont(u8g2_font_logisoso32_tn);
        dpy.drawStr(4, 64 - 20, final_hm);
        offset = dpy.getStrWidth(final_hm);
        dpy.setFont(u8g2_font_fub17_tn);
        dpy.drawStr(offset + 4, 64 - 20, final_s);

    } while (dpy.nextPage());
    delay(1000);
}
