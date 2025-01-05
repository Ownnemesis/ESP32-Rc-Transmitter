//This are the bytes for the EN logo
static const unsigned char PROGMEM  my_logo[] =
{/* 0X00,0X01,0X7C,0X00,0X40,0X00, */
0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XF0,0X00,0X18,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XF8,0X00,0X7C,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X3C,0XFC,0X03,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X7C,0XF8,0X1F,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XFC,0XF0,0XFE,0X78,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X7D,0XE0,0XFC,0X30,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XC0,0XFC,0X30,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XE0,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XF8,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XF8,0XF9,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XF8,0XF9,0XF8,0X00,0X06,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X01,0XF0,0XF9,0XFE,0X00,0X3C,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X01,0XF9,0XF8,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X01,0XF8,0X80,0XFF,0XFF,0XE0,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X20,0X20,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X18,0X00,0X0C,0X00,0X00,0X04,0X00,0X08,0X00,0X00,0X40,0X30,0X00,0X00,0X00,
0X01,0XF8,0X00,0XFC,0X00,0X0F,0XFF,0X80,0XFF,0X80,0X07,0XC1,0XF0,0X07,0X00,0X00,
0X07,0XF8,0X73,0XFC,0X03,0X1F,0XFF,0XC3,0XF3,0XC0,0X0F,0XC7,0XE0,0X7F,0X04,0XE0,
0X07,0X18,0XE3,0X8C,0X0F,0XBE,0X3D,0XC3,0XF9,0XE7,0X9F,0XC7,0XF1,0XFF,0X1F,0XE0,
0X0E,0X01,0XE7,0X00,0X7F,0X2E,0X39,0XC7,0XF1,0XF7,0X1F,0XCF,0XE1,0XE7,0XBF,0X00,
0X1F,0XC3,0XEF,0XE1,0XE3,0X0C,0X3B,0X86,0X73,0XFF,0X3B,0X8C,0XE1,0XC7,0XFF,0X00,
0X1F,0X83,0XCF,0XC1,0XE2,0X1C,0X3F,0X0E,0XF3,0XBF,0X33,0X9D,0XE3,0XFC,0X1F,0XC0,
0X1C,0X07,0XCE,0X01,0XE0,0X1C,0X3F,0XCE,0XE7,0XBF,0X77,0X9D,0XC3,0XFE,0X03,0XE0,
0X3C,0XE7,0X9E,0X71,0XC0,0X1C,0X79,0XCF,0XE7,0X1F,0X7F,0X1F,0XC7,0XCE,0X03,0XC0,
0X3F,0XE7,0X9F,0XF1,0XE0,0X3C,0X73,0XCF,0XE7,0X1F,0X7F,0X1F,0XC7,0XDE,0X7F,0XC0,
0XFF,0X0F,0X3F,0X81,0XFF,0XF8,0X7B,0XC7,0X8E,0X0E,0X3E,0X0F,0X0F,0XFF,0XFF,0X00,
0X00,0X0F,0X04,0X00,0XFF,0XE0,0X40,0X01,0X18,0X06,0X0C,0X02,0X0F,0XFF,0XFC,0X00,
0X00,0X0F,0X1C,0X00,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X08,0X60,0X00,
0X00,0X1F,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X3F,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X00,0X00,0X00,0X00,0X00,
0X00,0X70,0X00,0X00,0X00,0X07,0XFC,0X00,0X00,0X01,0XC0,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X0F,0XAF,0X00,0X00,0X03,0XE0,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X38,0X03,0X80,0X00,0X03,0X60,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X78,0X41,0XC0,0X00,0X03,0XE0,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X63,0XFC,0X60,0X00,0X07,0X60,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0XC7,0XFE,0X70,0X00,0X3F,0XFE,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0XCF,0XFF,0X30,0X00,0X7F,0X7F,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0X9E,0XC7,0X10,0X00,0X6B,0XAB,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0X9B,0X7B,0XB8,0X00,0X7E,0XFF,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0XBD,0XBF,0X98,0X00,0X7F,0X7F,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X03,0X3F,0XAD,0X98,0X00,0X1F,0XFC,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X03,0X37,0XEF,0X98,0X00,0X03,0X60,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X03,0X3D,0XBB,0XD8,0X00,0X03,0XE0,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X03,0X3A,0XED,0X88,0X00,0X03,0X60,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0X9F,0X6F,0X98,0X00,0X03,0XE0,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0X9D,0XFB,0X98,0X79,0XE1,0XC0,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0X9E,0XCF,0X30,0X79,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0XCF,0X7E,0X30,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0XC7,0XFE,0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X61,0XF0,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X38,0X03,0XC0,0X7F,0XE7,0XFC,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X1E,0X07,0X80,0X7F,0XE7,0XFC,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X0F,0XFE,0X00,0X60,0X66,0X0C,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X03,0XF8,0X00,0X60,0X64,0X0C,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XE7,0XF4,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XE7,0XFC,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
  };



#include <esp_now.h>
#include <WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define I2C_Freq 100000
//#define SDA 22
//#define SCL 19
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// REPLACE WITH YOUR RECEIVER MAC Address
//uint8_t receiverAddress[] = {0xC8, 0xC9, 0xA3, 0xCF, 0x03, 0x98};
uint8_t receiverAddress[] = {0xF4,0xCF,0xA2,0x71,0x36,0xCB};
esp_now_peer_info_t peerInfo;

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
  Serial.println(value);  
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
  Wire.begin(SDA, SCL);
  // Init ESP-NOW
  esp_now_init();

  memcpy(peerInfo.peer_addr, receiverAddress, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    esp_now_add_peer(&peerInfo);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)  
  delay(100);
  display.clearDisplay();
  display.setTextSize(1);             //Set text size
  display.setTextColor(WHITE);        //Choose color
  display.drawBitmap(0, 0,  my_logo, 128, 64, 1);  
  display.display();
  delay(1000);

  
  pinMode(19,INPUT_PULLUP);
  pinMode(18,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(0,INPUT_PULLUP); 
   
     
}
 
void loop() 
{
  data.lxAxisValue    = mapAndAdjustJoystickDeadBandValues(analogRead(32), false);
  data.lyAxisValue    = mapAndAdjustJoystickDeadBandValues(analogRead(33), false);
  data.rxAxisValue    = mapAndAdjustJoystickDeadBandValues(analogRead(34), false);
  data.ryAxisValue    = mapAndAdjustJoystickDeadBandValues(analogRead(35), false);
  data.switch1Value   = !digitalRead(19);
  data.switch2Value   = !digitalRead(18);
  data.switch3Value   = !digitalRead(5);
  data.switch4Value   = !digitalRead(0);
   
  
  esp_now_send(receiverAddress, (uint8_t *) &data, sizeof(data));

  
  
  display.clearDisplay();            //Clear the display 
  display.setCursor(0,0); 
  display.print("RX ");
  display.print("0:");  
  display.setCursor(30,0);            //Select where to print 124 x 64
      
  display.print("V");
  display.setCursor(70,0);
  display.print("TX:");  
  display.setCursor(90,0);            //Select where to print 124 x 64
        
  display.print("V");       
  display.setCursor(0,14);            //Select where to print 124 x 64
  display.print("CH1: ");             
  display.print(data.lxAxisValue);
  display.setCursor(70,14);     
  display.print("CH2: ");  
  display.print(data.lyAxisValue);    
  display.setCursor(0,28);
  display.print("CH3: ");             
  display.print(data.rxAxisValue);
  display.setCursor(70,28);     
  display.print("CH4: ");  
  display.print(data.ryAxisValue); 
  display.setCursor(0,41);
  display.print("S1:");             
  display.print(data.switch1Value);
  display.setCursor(33,41);     
  display.print("S2:");  
  display.print(data.switch2Value);
  display.setCursor(65,41);
  display.print("S3:");             
  display.print(data.switch3Value);
  display.setCursor(100,41);
  display.print("S4:");             
  display.print(data.switch4Value);
  
     
  display.display();

  delay(50);
}


    
