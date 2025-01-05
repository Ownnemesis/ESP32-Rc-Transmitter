#include <WiFi.h>
#include <esp_now.h>

int IN1 = 0;       //first motor
int IN2 = 1;       //first motor
int IN3 = 2;       //second motor
int IN4 = 3;      //second motor

int motor_speed;
int motor_speed1;

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
      
      //Motor Pins


  lastRecvTime = millis(); 
}

void setup() 
{

  WiFi.mode(WIFI_STA);

  
  pinMode(IN1, OUTPUT);  
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);  
  pinMode(IN4, OUTPUT);


  if (esp_now_init() != 0) {
    
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
      
  }



 int x_pos = receiverData.lxAxisValue;                                              
 int y_pos = receiverData.lyAxisValue;                        


if (x_pos>120 && x_pos <135 && y_pos>120 && y_pos <135){  //Joystick center position
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
if (x_pos < 120){   
    motor_speed = map(x_pos, 120, 0, 0, 255);
    motor_speed1 = 0;
    digitalWrite(IN1, LOW);
    analogWrite(IN2, motor_speed);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, motor_speed);
  } 
else if (x_pos > 135){    
    motor_speed = map(x_pos, 135, 255, 0, 255);
    motor_speed1 = 0;
    analogWrite(IN1, motor_speed);
    digitalWrite(IN2, LOW);
    analogWrite(IN3, motor_speed);
    digitalWrite(IN4, LOW);
  }
   
if (y_pos < 125){         
    motor_speed1 = map(y_pos, 125, 0, 0, 255);
    motor_speed = 0;
    digitalWrite(IN1, LOW);
    analogWrite(IN2, motor_speed1);
    digitalWrite(IN4, LOW);
    analogWrite(IN3, motor_speed1);
  }

 
else if (y_pos > 135){
    motor_speed1 = map(y_pos, 135, 255, 0, 255);
    motor_speed = 0;
    analogWrite(IN1, motor_speed1);
    digitalWrite(IN2, LOW);
    analogWrite(IN4, motor_speed1);
    analogWrite(IN3, LOW);
  }

  
}















    
