#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

int received;  //To store received value
char receivedChar;  //To store received value in character

const char turnON = 'H';
const char turnOFF = 'L';
const char blink = 'B';
const int LEDpin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SerialBT.begin("ESP32_Bluetooth_LED");

  Serial.println("The device is Started and now you can pair the bluetooth");
  Serial.println("To turnON type H and to turnOFF type L");

  pinMode(LEDpin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  receivedChar = (char)SerialBT.read();

  //if (Serial.available()){
   // SerialBT.write(Serial.read());
  //}

  if (SerialBT.available()){
    SerialBT.println("Received :");
    SerialBT.println(receivedChar);

    Serial.println("Received: ");
    Serial.println(receivedChar);

    if (receivedChar == turnON){
      SerialBT.println("LED ON");
      Serial.println("LED ON");

      digitalWrite(LEDpin, HIGH);
    }
    else if (receivedChar == turnOFF){
      SerialBT.println("LED OFF");
      Serial.println("LED OFF");

      digitalWrite(LEDpin, LOW);

    }
    else if (receivedChar == blink){
      SerialBT.println("LED Blink");
      Serial.println("LED BLINK");

      digitalWrite(LEDpin, HIGH);
      delay(500);
      digitalWrite(LEDpin, LOW);
      delay(500);

    }
  }
  delay(20);

}
