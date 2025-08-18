#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <U8g2lib.h>

WiFiClientSecure client;

U8G2_SSD1306_128X64_NONAME_F_HW_I2C dpy(U8G2_R0, U8X8_PIN_NONE);

const String WIFI_SSID = "PRIADI_5G";
const String WIFI_PASS = "prince123**";

const String host = "leetcode-stats.tashif.codes";
const String username = "/aditya23043";

void setup() {
    Serial.begin(115200);

    dpy.begin();
    dpy.setFont(u8g2_font_logisoso16_tf);

    dpy.clearBuffer();
    dpy.drawStr(10, 20, "Connecting...");
    dpy.sendBuffer();

    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }

    dpy.clearBuffer();
    dpy.drawStr(10, 20, "Connected!");
    dpy.sendBuffer();

    client.setInsecure();
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        if (client.connect(host, 443)) {
            client.print(String("GET ") + username + " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" + "User-Agent: ESP8266\r\n" +
                         "Connection: close\r\n\r\n");
            while (client.connected()) {
                String line = client.readStringUntil('\n');
                if (line == "\r")
                    break;
            }

            String body;
            while (client.available()) {
                body += client.readStringUntil('\n');
            }

            client.stop();

            Serial.println(body);

            const char *ptr;

            if ((ptr = strstr(body.c_str(), "\"totalSolved\"")) != NULL) {
                ptr = strchr(ptr, ':'); // Move to colon
                if (ptr != NULL) {
                    ptr++; // Move past colon
                    while (*ptr == ' ')
                        ptr++; // Skip whitespace

                    char solvedCount[10];
                    int i = 0;

                    // Copy digits into solvedCount buffer
                    while (isdigit(*ptr) && i < sizeof(solvedCount) - 1) {
                        solvedCount[i++] = *ptr++;
                    }
                    solvedCount[i] = '\0';

                    dpy.clearBuffer();
                    dpy.drawStr(0, 20, "Total");
                    dpy.drawStr(0, 40, "Leet");
                    dpy.drawStr(0, 60, "Code");
                    // dpy.setFont(u8g2_font_osr41_tn);
                    dpy.setFont(u8g2_font_logisoso58_tn);
                    dpy.drawStr(55, 61, solvedCount);
                    dpy.setFont(u8g2_font_logisoso16_tf);
                    dpy.sendBuffer();
                }
            }

        } else {
            dpy.clearBuffer();
            dpy.drawStr(0, 30, "Cannot ping API");
            dpy.sendBuffer();
        }
    } else {
        dpy.clearBuffer();
        dpy.drawStr(0, 30, "WiFI not connected!");
        dpy.sendBuffer();
    }
    delay(60000);
}
