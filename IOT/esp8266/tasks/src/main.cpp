#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <U8g2lib.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C dpy(U8G2_R3, U8X8_PIN_NONE);

const String WIFI_SSID = "PRIADI_5G";
const String WIFI_PASS = "prince123**";

int r = 0, g = 0, b = 0;

WiFiServer server(80);

char tasks[16][128] = {0};
int _index = 0;

void lshift(char *buf, int index) {
    if (index == 0) {
        return;
    }
    for (int i = index; i < strlen(buf); i++) {
        buf[i] = buf[i + 1];
    }
    // no needs to do bound checking cuz strlen goes to the char before the null
    // byte and hence it automatically shifts the null byte as well (goog
    // thingy)
}

void setup() {

    Serial.begin(115200);

    dpy.begin();

    dpy.clearBuffer();
    dpy.setFont(u8g2_font_likeminecraft_te);
    dpy.drawStr(0, 10, "Connecting...");
    dpy.sendBuffer();

    Serial.println("Connecting to WiFi....");

    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }

    char buffer[128] = "";

    Serial.println("Connected!");
    snprintf(buffer, sizeof(buffer), "%s", WiFi.localIP().toString().c_str());

    dpy.clearBuffer();
    dpy.drawStr(0, 10, "Connected! IP:");
    dpy.drawStr(0, 30, buffer);
    dpy.sendBuffer();

    server.begin();
}

void loop() {

    char buffer[128] = "";
    int i = 0;
    char c;

    int flag = 0;

    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client = server.accept();
        if (client) {
            client.println(
                "HTTP/1.1 200 OK\r\nContent-Type: "
                "text/html\r\n\r\n"
                "<!doctype html><html lang='en'>  <head>    <meta "
                "charset='UTF-8' />    <meta name='viewport' "
                "content='width=device-width, initial-scale=1.0' />    "
                "<title>Tasks</title>    <link rel='stylesheet' "
                "href='style.css' />  <style>    * {      font-family: 'SF "
                "Mono';    }    .container {      height: 100vh;      display: "
                "flex;      align-items: center;      justify-content: center; "
                "     flex-direction: column;    }    input {      font-size: "
                "1.5rem;      padding: 1.2rem;      margin: 1rem;    }    "
                "button {      font-size: 1.2rem;      padding: 0.5rem 1rem;   "
                "   margin: 1rem;    }  </style>  </head>  <body>	  <div "
                "class='container'>		<h1>TASKS</h1>		<input "
                "autofocus placeholder='task name' value='' "
                "id='task'></input>		<button onclick='Submit()' "
                "id='btn'>Add</button>	  </div>	  <script>      var "
                "input = document.getElementById('task');      "
                "input.addEventListener('keypress', function(event) {        "
                "if (event.key === 'Enter') {          event.preventDefault(); "
                "         document.getElementById('btn').click();          "
                "input.value = '';        }      });			"
                "function Submit() {				fetch('/' + "
                "document.getElementById('task').value);		"
                "	}	  </script>  </body></html>");
            while (client.connected()) {
                if (client.available()) {
                    c = client.read();

                    if (c == '/') {
                        flag = 1;
                        continue;
                    }
                    if (strlen(buffer) + 1 < sizeof(buffer) && flag) {
                        buffer[i++] = c;
                        buffer[i] = '\0';
                    }
                    if (c == ' ' && flag) {
                        break;
                    }
                }
            }

            if (strcmp(buffer, "favicon.ico") != 0 && strlen(buffer) != 0) {

                for (int i = 0; i < strlen(buffer); i++) {
                    if (i < strlen(buffer) - strlen("%20")) {
                        if (buffer[i] == '%') {
                            if (buffer[i + 1] == '2') {
                                if (buffer[i + 2] == '0') {
                                    buffer[i] = ' ';
                                    buffer[i + 1] = ' ';
                                    buffer[i + 2] = ' ';
                                    lshift(buffer, i);
                                }
                            }
                        }
                    }
                }

                strcpy(tasks[_index++], buffer);
            }
        }

    } else {
        dpy.clearBuffer();
        dpy.drawStr(0, 10, "WiFi not connected!");
        dpy.sendBuffer();
    }

    if (_index == 0) {
        dpy.clearBuffer();
        dpy.drawStr(0, 10, WiFi.localIP().toString().c_str());
        dpy.sendBuffer();
    } else {
        dpy.clearBuffer();
        dpy.drawStr(0, 10, "[TASKS]");
        for (int i = 0; i < _index; i++) {
            dpy.drawStr(10, 10 * i + 20, tasks[i]);
        }
        dpy.sendBuffer();
    }

    delay(100);
}
