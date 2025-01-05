#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <espnow.h>
#include <SoftwareSerial.h>

#include <RecurringTask.h>

SoftwareSerial SerialIBUS(0, 2); // RX, TX

typedef struct
{
    uint8_t header1;
    uint8_t header2;
    uint16_t channels[14];
    uint16_t checksum;
} IBUS_Packet;

IBUS_Packet packet = {};

uint16_t calc_checksum(IBUS_Packet &p)
{
    uint16_t checksum = 0xFFFF;
    checksum -= p.header1;
    checksum -= p.header2;

    for (int i = 0; i < 14; i++)
    {
        checksum -= p.channels[i] & 0xFF;
        checksum -= (p.channels[i] >> 8) & 0xFF;
    }

    return checksum;
}

void send_packet(IBUS_Packet &p)
{
    SerialIBUS.write((uint8_t *)&p, sizeof(IBUS_Packet));
}

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
       
}

void setup()
{
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    SerialIBUS.begin(115200);

    packet.header1 = 0x20;
    packet.header2 = 0x40;

    for (int i = 0; i < 14; i++)
    {
        packet.channels[i] = 0x5dc;
    }
    // Init ESP-NOW
  esp_now_init();

    esp_now_register_recv_cb(OnDataRecv);
    packet.checksum = calc_checksum(packet);
}

void loop()
{
    
            packet.channels[0] = map(receiverData.lxAxisValue, 30, 220, 1000, 2000);
            packet.channels[1] = map(receiverData.lyAxisValue, 30, 220, 1000, 2000);
            packet.channels[2] = map(receiverData.rxAxisValue, 30, 220, 1000, 2000);
            packet.channels[3] = map(receiverData.ryAxisValue, 30, 220, 1000, 2000);
            if (receiverData.switch1Value == 1)
            {packet.channels[4] = 1000;}
              else if (receiverData.switch2Value == 1)
            {packet.channels[4] = 2000;}
            else
            {packet.channels[4] = 1500;}

            if (receiverData.switch3Value == 1)
            {packet.channels[5] = 1000;}
              else if (receiverData.switch4Value == 1)
            {packet.channels[5] = 2000;}
            else
            {packet.channels[5] = 1500;}

            if (receiverData.switch5Value == 1)
            {packet.channels[6] = 1000;}
              else if (receiverData.switch6Value == 1)
            {packet.channels[6] = 2000;}
            else
            {packet.channels[6] = 1500;}

            if (receiverData.switch7Value == 1)
            {packet.channels[7] = 1000;}
              else if (receiverData.switch8Value == 1)
            {packet.channels[7] = 2000;}
            else
            {packet.channels[7] = 1500;}
            
            packet.channels[8] = 1500;
            packet.channels[9] = 1500;
            packet.channels[10] = 1500;
            packet.channels[11] = 1500;
            packet.channels[12] = 1500;
            
            
    
    packet.checksum = calc_checksum(packet);
    

    send_packet(packet);

    


    delay(14);
}