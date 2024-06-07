#include <BluetoothSerial.h>
#include <ESP32Servo.h>

BluetoothSerial SerialBT;
Servo myServo;

String angle;
char receivedChar;  //To store received value in character

const char turnON = 'H';
const char turnOFF = 'L';

int servo1Angle =90;
int servo1AngleMin =0;
int servo1AngleMax = 180;
const int servoPin = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("ESP32_Bluetooth_LED");

  Serial.println("The device is Started and now you can pair the bluetooth");
  Serial.println("To turnON type H and to turnOFF type L");
  Serial.println("To Rotate Motor type R");
  myServo.attach(servoPin);

}

void loop() {
  // put your main code here, to run repeatedly:
  receivedChar = (char)SerialBT.read();
  

  //if (Serial.available()){
   // SerialBT.write(Serial.read());
  //}

  while (SerialBT.available()){
    receivedChar = (char)SerialBT.read();
    angle += receivedChar;
    if (receivedChar == '\n'){
      SerialBT.print("Received:");// write on BT app
      SerialBT.println(angle);// write on BT app   

      Serial.print("Received:");//print on Serial Monitor
      Serial.println(angle); //print on Serial Monitor     
    
      servo1Angle = angle.toInt() ;//convert it to integer

      if(servo1Angle <=servo1AngleMax && servo1Angle >=servo1AngleMin){
        myServo.write(servo1Angle);//move servo to that angle  
      }

      angle = "";
      }
    }
  delay(20);
}
