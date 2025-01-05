#include <esp_now.h>
#include <WiFi.h>


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

     
     

int   led1 = 22;

#define ENA 13
#define IN1 2
#define IN2 15
#define ENB 4
#define IN3 17
#define IN4 16

int motor_speed = 0;
int motor_speed1 = 0;
int rx_pos = 127;                                               
int ry_pos = 127;


//Assign default input received values
void setInputDefaultValues()
{
  // The middle position for joystick. (254/2=127)
  receiverData.lxAxisValue = 127;
  receiverData.lyAxisValue = 127;
  receiverData.rxAxisValue = 127;
  receiverData.ryAxisValue = 127;
  
  receiverData.switch1Value = LOW;
    
}

void mapAndWriteValues()
{
  
  digitalWrite(led1, receiverData.switch1Value);
  rx_pos = receiverData.lxAxisValue;                                               
  ry_pos = receiverData.lxAxisValue;  
}

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) 
{
  if (len == 0)
  {
    return;
  }
  
}

void setUpPinModes()
{
  
  pinMode(ENA, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(led1, OUTPUT);
  setInputDefaultValues();
  mapAndWriteValues();
}

void setup() 
{
  setUpPinModes();
 
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) 
  {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
}
 


void loop(){

                    
 
 int x_pos = rx_pos;                                               
 int y_pos = rx_pos;
 motor_speed = 0;
 motor_speed1 = 0;
 
 

if ( x_pos < 125) {
      // Set Motor A backward
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      // Set Motor B backward
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
      motor_speed = map(x_pos, 125, 30, 0, 255);
      motor_speed1 = map(x_pos, 125, 30, 0, 255);
      analogWrite(ENA, motor_speed); // Send PWM signal to motor A
      analogWrite(ENB, motor_speed1); // Send PWM signal to motor B
     }
    else if (x_pos > 129) {
      // Set Motor A forward
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      // Set Motor B forward
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
      motor_speed = map(x_pos, 129, 255, 0, 255);
      motor_speed1 = map(x_pos, 129, 255, 0, 255);
      analogWrite(ENA, motor_speed); // Send PWM signal to motor A
      analogWrite(ENB, motor_speed1); // Send PWM signal to motor B
    }
    // If joystick stays in middle the motors are not moving
    else {
      
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      motor_speed = 0;
      motor_speed1 = 0;
      analogWrite(ENA, motor_speed); // Send PWM signal to motor A
      analogWrite(ENB, motor_speed1); // Send PWM signal to motor B
    }

 Serial.println("x_pos");
 Serial.print(x_pos);
 


    
  //Check Signal lost.
  unsigned long now = millis();
  if ( now - lastRecvTime > SIGNAL_TIMEOUT ) 
  {
    setInputDefaultValues();
    mapAndWriteValues();  
  
  }
}
