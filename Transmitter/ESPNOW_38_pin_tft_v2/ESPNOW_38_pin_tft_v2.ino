
#include "Arduino.h"
#include "PCF8574.h"
#include "TFT_eSPI.h"
#include <esp_now.h>
#include <WiFi.h>
#include <SPI.h>
//#include <Wire.h>
#include <Adafruit_GFX.h>

TFT_eSPI tft = TFT_eSPI();

int RawValue = 0;
int LastPercent = 0;

int RawValue1 = 0;
int LastPercent1 = 0;

int RawValue2 = 0;
int LastPercent2 = 0;

int RawValue3 = 0;
int LastPercent3 = 0;

int modnum = 1;
int modmax = 3;



// Variables will change:

int buttonState = 0;        // current state of the button
int lastButtonState = 0;
byte switch1 = 0; 


#define BACKCOLOR 0x18E3
#define BARCOLOR 0x0620
#define SCALECOLOR 0xFFFF

// Set i2c HEX address
PCF8574 pcf8574(0x27);
unsigned long timeElapsed;

/* REPLACE WITH YOUR RECEIVER MAC Address*/

uint8_t receiverAddress[3][6] = {{0xC8, 0xC9, 0xA3, 0xCE, 0xF8, 0xC0},
                                 {0xC8, 0xC9, 0xA3, 0xCF, 0x03, 0x98},
                                 {0xF4, 0xCF, 0xA2, 0x71, 0x36, 0xCB}};
esp_now_peer_info_t peerInfo[3];


struct PacketData
{
  byte lxAxisValue;
  byte lyAxisValue;
  byte rxAxisValue;
  byte ryAxisValue;
 
  byte switch1Value;
  byte switch2Value;
  byte switch3Value;
  byte switch4Value;  
  byte switch5Value;
  byte switch6Value;
  byte switch7Value;
  byte switch8Value;  
};
PacketData data;


//This function is used to map 0-4095 joystick value to 0-254. hence 127 is the center value which we send.
//It also adjust the deadband in joystick.
//Jotstick values range from 0-4095. But its center value is not always 2047. It is little different.
//So we need to add some deadband to center value. in our case 1800-2200. Any value in this deadband range is mapped to center 127.
int mapAndAdjustJoystickDeadBandValues(int value, bool reverse)
{
  if (value >= 2200)
  {
    value = map(value, 2200, 4095, 127, 254);
  }
  else if (value <= 1800)
  {
    value = (value == 0 ? 0 : map(value, 1800, 0, 127, 0));  
  }
  else
  {
    value = 127;
  }

  if (reverse)
  {
    value = 254 - value;
  }
  //Serial.println(value);  
  return value;
}

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{
  Serial.print("\r\nLast Packet Send Status:\t ");
  Serial.println(status);
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Message sent" : "Message failed");
}


  


void setup() {

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  //Wire.begin(SDA, SCL);
  // Init ESP-NOW
  esp_now_init();
  pinMode(0,INPUT_PULLUP);
  pcf8574.begin();
  pcf8574.pinMode(P0, INPUT_PULLUP);
  pcf8574.pinMode(P1, INPUT_PULLUP);
  pcf8574.pinMode(P2, INPUT_PULLUP);
  pcf8574.pinMode(P3, INPUT_PULLUP);
  pcf8574.pinMode(P4, INPUT_PULLUP);
  pcf8574.pinMode(P5, INPUT_PULLUP);
  pcf8574.pinMode(P6, INPUT_PULLUP);
  pcf8574.pinMode(P7, INPUT_PULLUP);
  
esp_now_register_send_cb(OnDataSent);

  for(int i=0; i<3; i++){
        memcpy(peerInfo[i].peer_addr, receiverAddress[i], 6);
        peerInfo[i].channel = 0;
        peerInfo[i].encrypt = false;
        if (esp_now_add_peer(&peerInfo[i]) != ESP_OK) {
            Serial.println("Failed to add peer");
            return;
        }
       }   

       
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(BACKCOLOR);
  
   
    
     
}
 
void loop() 
{


 
 
PCF8574::DigitalInput di = pcf8574.digitalReadAll();
  

  data.lxAxisValue    = mapAndAdjustJoystickDeadBandValues(analogRead(32), false);
  data.lyAxisValue    = mapAndAdjustJoystickDeadBandValues(analogRead(33), false);
  data.rxAxisValue    = mapAndAdjustJoystickDeadBandValues(analogRead(34), false);
  data.ryAxisValue    = mapAndAdjustJoystickDeadBandValues(analogRead(35), false);
  data.switch1Value   = di.p0;
  data.switch2Value   = di.p1;
  data.switch3Value   = di.p2;
  data.switch4Value   = di.p3;
  data.switch5Value   = di.p4;
  data.switch6Value   = di.p5;
  data.switch7Value   = di.p6;
  data.switch8Value   = di.p7;


switch1 = !digitalRead(0);

  buttonState = switch1;
if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      modnum ++;
      if (modnum > modmax) modnum = 1;

    // delay(50);
  }
}

  lastButtonState = buttonState;

int rx = map(modnum, 1, 3, 0, 2);

  esp_now_send(receiverAddress[rx], (uint8_t *) &data, sizeof(data));

  drawButtonT();
  drawButtonM(); 
  drawBars();           
  drawScale();
  drawinfos();
  
    
  

  delay(10);
}
//***********************************************************************************************

