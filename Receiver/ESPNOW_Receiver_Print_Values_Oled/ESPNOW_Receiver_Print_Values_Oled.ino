#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

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
  Serial.println(inputValuesString); 
      
  lastRecvTime = millis(); 
}

void setup() 
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);             //Set text size
  display.setTextColor(WHITE);        //Choose color
  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) 
  {
    Serial.println("Error initializing ESP-NOW");
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
    Serial.println("No Signal");
    display.clearDisplay();
    display.setCursor(0,14);            //Select where to print 124 x 64
    display.print("No Signal");
    display.display();  
  }

  display.clearDisplay();            //Clear the display       
  display.setCursor(0,14);            //Select where to print 124 x 64
  display.print("CH1: ");             
  display.print(receiverData.lxAxisValue);
  display.setCursor(70,14);     
  display.print("CH2: ");  
  display.print(receiverData.lyAxisValue);    
  display.setCursor(0,28);
  display.print("CH3: ");             
  display.print(receiverData.rxAxisValue);
  display.setCursor(70,28);     
  display.print("CH4: ");  
  display.print(receiverData.ryAxisValue); 
  display.setCursor(0,41);
  display.print("S1:");             
  display.print(receiverData.switch1Value);
  display.setCursor(33,41);     
  display.print("S2:");  
  display.print(receiverData.switch2Value);
  display.setCursor(65,41);
  display.print("S3:");             
  display.print(receiverData.switch3Value);
  display.setCursor(100,41);
  display.print("S4:");             
  display.print(receiverData.switch4Value);
  display.setCursor(0,54);
  display.print("S5:");             
  display.print(receiverData.switch5Value);
  display.setCursor(33,54);     
  display.print("S6:");  
  display.print(receiverData.switch6Value);
  display.setCursor(65,54);     
  display.print("S7:");  
  display.print(receiverData.switch7Value);
  display.setCursor(100,54);     
  display.print("S8:");  
  display.print(receiverData.switch8Value);
     
  display.display();




}















    