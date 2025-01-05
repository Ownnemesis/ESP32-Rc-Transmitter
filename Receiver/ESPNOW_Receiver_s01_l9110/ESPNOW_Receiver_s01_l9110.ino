#include <ESP8266WiFi.h>
#include <espnow.h>

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
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) 
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
  Serial.println(inputValuesString); 
      
      


  lastRecvTime = millis(); 
}





void setup() 
{

  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  
  


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
    Serial.println("No Signal");  
  }

      

      
   
}















    
