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



#define ENA 13
#define IN1 12
#define IN2 15
#define ENB 4
#define IN3 16
#define IN4 17

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
  receiverData.switch1Value = LOW;
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
  mapAndWriteValues();
  mapAndWriteValues();
  lastRecvTime = millis();
}

void setUpPinModes() {

  pinMode(ENA, OUTPUT);
  pinMode(ENA, OUTPUT);
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
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, motor_speed);    
  }
else if (x_pos > 129){    
    motor_speed = map(x_pos, 129, 255, 0, 255);
    motor_speed1 = 0;
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, motor_speed);
  }
  else// (x_pos>400 && x_pos <600 && y_pos>400 && y_pos <600){  //Joystick center position
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
  //} 
if (y_pos < 125){         
    motor_speed1 = map(y_pos, 125, 0, 0, 255);
    motor_speed = 0;
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
    analogWrite(ENA, motor_speed);
  }
else if (y_pos > 129){
    motor_speed1 = map(y_pos, 129, 255, 0, 255);
    motor_speed = 0;
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN3, LOW);
    analogWrite(ENA, motor_speed);
  }
else
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW); 
    analogWrite(ENA, 0);     
}