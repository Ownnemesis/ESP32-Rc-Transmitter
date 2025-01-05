#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "SBUS.h" // https://github.com/TheDIYGuy999/SBUS

SBUS x8r(Serial);


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define I2C_Freq 100000
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


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
  Serial2.println(inputValuesString); 
      
  lastRecvTime = millis(); 
}

void sendSbusCommands() {

  static unsigned long lastSbusTime;
  uint16_t channels[16]; // 0 - 15

  if (millis() - lastSbusTime > 14) { // Send the data every 14ms
      lastSbusTime = millis();

     channels[0] = map(receiverData.lxAxisValue, 30, 220, 172, 1811); //LENKUNG
     channels[1] = map(receiverData.lxAxisValue, 30, 220, 172, 1811); //gas
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

     display.clearDisplay();
     display.setCursor(0,10);
     display.print("S1:");             
     display.print(channels[0]);
     display.setCursor(40,10);     
     display.print("S2:");  
     display.print(channels[1]);
     display.setCursor(80,10);
     display.print("S3:");             
     display.print(channels[2]);
     display.setCursor(0,30);
     display.print("S4:");             
     display.print(channels[3]);
     display.setCursor(40,30);
     display.print("S5:");             
     display.print(channels[4]);
     display.setCursor(80,30);     
     display.print("S6:");  
     display.print(channels[5]);
     display.setCursor(0,50);     
     display.print("S7:");  
     display.print(channels[6]);
     display.setCursor(40,50);     
     display.print("S8:");  
     display.print(channels[7]);
     display.display();
}
}
void setup() 
{
  Serial2.begin(115200);
  WiFi.mode(WIFI_STA);
  Wire.begin();
  x8r.begin(3, 1, true);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);             //Set text size
  display.setTextColor(WHITE);        //Choose color
  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) 
  {
    Serial2.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_register_recv_cb(OnDataRecv);
}
 


void loop()
{
  //Check Signal lost.
  unsigned long now = millis();
  if ( now - lastRecvTime > SIGNAL_TIMEOUT ) 
  {
    Serial2.println("No Signal");
    display.clearDisplay();
    display.setCursor(85,50);            //Select where to print 124 x 64
    display.print("No Signal");
    display.display();  
  }
sendSbusCommands();


}

