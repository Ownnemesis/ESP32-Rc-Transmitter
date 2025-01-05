#include <ESP8266WiFi.h>
#include <espnow.h>
#include "SBUS.h"
#include <SoftwareSerial.h>


#define rxPin 2
#define txPin 0
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

#define SIGNAL_TIMEOUT 1000  // This is signal timeout in milli seconds. We will reset the data if no signal


SBUS x8r(Serial);
// channel, fail safe, and lost frames data
uint16_t channels[16];
bool failSafe;
bool lostFrame;

unsigned long lastRecvTime = 0;

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
PacketData receiverData;

// callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) 
{
  if (len == 0)
  {
    return;
  }
  
       
  lastRecvTime = millis(); 
}
void sendSbusCommands() {

  static unsigned long lastSbusTime;
  uint16_t channels[16]; // 0 - 15

  if (millis() - lastSbusTime > 14) { // Send the data every 14ms
      lastSbusTime = millis();

     channels[0] = map(receiverData.lxAxisValue, 30, 220, 172, 1811); //LENKUNG
     channels[1] = map(receiverData.lyAxisValue, 30, 220, 172, 1811); //gas
     channels[2] = map(receiverData.rxAxisValue, 30, 220, 172, 1811);
     channels[3] = map(receiverData.ryAxisValue, 30, 220, 172, 1811);
     if (receiverData.switch1Value) channels[4] = 1811; else channels[4] = 991;
     if (receiverData.switch2Value) channels[4] = 172; else channels[4] = 991;
     if (receiverData.switch3Value) channels[5] = 1811; else channels[5] = 991;
     if (receiverData.switch4Value) channels[5] = 172; else channels[5] = 991;
     if (receiverData.switch5Value) channels[6] = 1811; else channels[6] = 991;
     if (receiverData.switch6Value) channels[6] = 172; else channels[6] = 991;
     if (receiverData.switch7Value) channels[7] = 1811; else channels[7] = 991;
     if (receiverData.switch8Value) channels[7] = 172; else channels[7] = 991;
     if (receiverData.switch7Value) channels[8] = 1811; else channels[8] = 991;
     if (receiverData.switch8Value) channels[8] = 172; else channels[8] = 991;
    
     channels[9] = 991;
     channels[10] = 991;
     channels[11] = 991;
     channels[12] = 991;
     channels[13] = 991;
     channels[14] = 991;
     channels[15] = 991;

     x8r.write(&channels[0]);

}
    
}

void setup() 
{

  WiFi.mode(WIFI_STA);
  x8r.begin(3, 1, false, 100000);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(115200);

  if (esp_now_init() != 0) {
    
    return;
  }
 
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);


}

 


void loop()
{



  unsigned long now = millis();
  if ( now - lastRecvTime > SIGNAL_TIMEOUT ) 
  {
    mySerial.println("No Signal");
      
  }

    sendSbusCommands();
      
   }
















    
