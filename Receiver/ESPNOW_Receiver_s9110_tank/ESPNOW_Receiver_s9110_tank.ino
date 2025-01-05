#include <esp_now.h>
#include <WiFi.h>
#include <ESP32Servo.h>

#define SIGNAL_TIMEOUT 1000  // This is signal timeout in milli seconds. We will reset the data if no signal

unsigned long lastRecvTime = 0;

struct PacketData {
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


int IN1 = 16;
int IN2 = 17;
int IN3 = 13;
int IN4 = 15;

int motor_speed = 0;
int motor_speed1 = 0;

int led1 = 22;

//Assign default input received values
void setInputDefaultValues() {
  // The middle position for joystick. (254/2=127)
  receiverData.lxAxisValue = 127;
  receiverData.lyAxisValue = 127;
  receiverData.rxAxisValue = 127;
  receiverData.ryAxisValue = 127;
  receiverData.switch1Value = HIGH;
}
void mapAndWriteValues() {

  digitalWrite(led1, receiverData.switch1Value);
}

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  if (len == 0) {
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
  mapAndWriteValues();

  lastRecvTime = millis();
}

void setUpPinModes() {


  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(led1, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  setInputDefaultValues();
}

void setup() {
  setUpPinModes();

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
}



void loop() {
  setInputDefaultValues();
    mapAndWriteValues();
  unsigned long now = millis();
  if ( now - lastRecvTime > SIGNAL_TIMEOUT ) 
  {
        
    Serial.println("No Signal");  
  }

 int x_pos = receiverData.lxAxisValue;                                               
 int y_pos = receiverData.lyAxisValue;                         

if (x_pos < 125){   
    motor_speed = map(x_pos, 125, 0, 0, 255);
    motor_speed1 = 0;
    digitalWrite(IN1, LOW);
    analogWrite(IN2, motor_speed);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, motor_speed);
  }
 if (x_pos > 129){    
    motor_speed = map(x_pos, 129, 255, 0, 255);
    motor_speed1 = 0;
    analogWrite(IN1, motor_speed);
    digitalWrite(IN2, LOW);
    analogWrite(IN3, motor_speed);
    digitalWrite(IN4, LOW);
    
  }
  else if (x_pos ==127 &&  y_pos == 127 ){  //Joystick center position
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0); 
  } 
if (y_pos < 125){         
    motor_speed1 = map(y_pos, 125, 0, 0, 255);
    motor_speed = 0;
    digitalWrite(IN1, LOW);
    analogWrite(IN2, motor_speed1);
    digitalWrite(IN4, LOW);
    analogWrite(IN3, motor_speed1);
  }
else if (y_pos > 129){
    motor_speed1 = map(y_pos, 129, 255, 0, 255);
    motor_speed = 0;
    analogWrite(IN1, motor_speed1);
    digitalWrite(IN2, LOW);
    analogWrite(IN4, motor_speed1);
    digitalWrite(IN3, LOW);
  }
 
}