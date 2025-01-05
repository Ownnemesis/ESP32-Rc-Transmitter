#include <ESP8266WiFi.h>
#include <espnow.h>
#include "SBUS.h" // https://github.com/TheDIYGuy999/SBUS




SBUS x8r(Serial);



#define SIGNAL_TIMEOUT 1000  // This is signal timeout in milli seconds. We will reset the data if no signal

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
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) 
{
  if (len == 0)
  {
    return;
  }
  memcpy(&receiverData, incomingData, sizeof(receiverData));

  char inputValuesString[100];
  sprintf(inputValuesString, 
          "%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d,%3d",
           receiverData.lxAxisValue,
           receiverData.lyAxisValue,
           receiverData.rxAxisValue,
           receiverData.ryAxisValue,
           receiverData.switch1Value,
           receiverData.switch2Value,
           receiverData.switch3Value,
           receiverData.switch4Value,
           receiverData.switch5Value,
           receiverData.switch6Value,
           receiverData.switch7Value,
           receiverData.switch8Value);
  //Serial.println(inputValuesString); 
      
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
  x8r.begin(3, 1, true);
  
  // Init ESP-NOW
  if (esp_now_init() != 0) {
    
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}
 


void loop()
{
  //Check Signal lost.
  unsigned long now = millis();
  if ( now - lastRecvTime > SIGNAL_TIMEOUT ) 
  {
    
    
  }
sendSbusCommands();


}

