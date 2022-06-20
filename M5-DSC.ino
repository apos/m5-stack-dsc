#include <WiFi.h>
#include "Encoder.h"
#include <M5Stack.h>
Encoder encoder0(21, 22); // AZ axis: Ch A to GPIO 21, Ch B to GPIO22 (26 & 36 DO NOT WORK - looses ticks)
Encoder encoder1(16, 17); // ALT axis: Ch A to GPIO16, Ch B to GPIO17
WiFiServer wifiServer(8888);
void setup() {
  M5.begin(); // Initialize the M5Stack object
  M5.Lcd.writecommand(ILI9341_DISPOFF);
  M5.Lcd.setBrightness(0);
  
  btStop();
  
  WiFi.mode(WIFI_AP);
  uint8_t mac[6];
  WiFi.softAPmacAddress(mac);
  String AP_Name = "M5-DSC_BLK";
  char AP_NameChar[AP_Name.length() + 1];
  memset(AP_NameChar, 0, AP_Name.length() + 1);
  for (int i=0; i<AP_Name.length(); i++)
    AP_NameChar[i] = AP_Name.charAt(i);

  String passwd = "$123qwe%";
  char AP_PwdChar[passwd.length() + 1];
  memset(AP_PwdChar, 0, passwd.length() + 1);
  for (int i=0; i<passwd.length(); i++)
    AP_PwdChar[i] = passwd.charAt(i);
    
  boolean result = WiFi.softAP(AP_NameChar, AP_PwdChar);
  if(result == true)
  {
    wifiServer.begin();
  }
  delay(100);

  M5.Speaker.begin();
  M5.Speaker.tone(900, 300);
  delay(300);
  M5.Speaker.end();
  

}
void loop() {
  WiFiClient client = wifiServer.available(); // wait for connection
  if (client) {
    if (client.connected()) {
      while (client.available()>0) {
        uint8_t c = client.read();
        if (c == 81) {  //ascii for "Q"
             long encoder0Pos = encoder0.read();
             long encoder1Pos = encoder1.read();
             client.printf("%+06d\t%+06d\r",encoder0Pos,encoder1Pos);
        }
      }
    }
    client.stop();
  }
  
  // delay(10);  // delay probaly needed - in my case not
}
