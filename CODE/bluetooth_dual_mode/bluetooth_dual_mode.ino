#include <SoftwareSerial.h>   //Software Serial Port

#define RxD 2
#define TxD 3
#define vitesse_arduino 9600
#define vitesse_bluetooth 57600

SoftwareSerial blueToothSerial(RxD,TxD);

String recvChar;
String emitChar;

void setup()
{
  Serial.begin(vitesse_arduino);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  
  
  Serial.println("Debut setup");
  blueToothSerial.begin(vitesse_bluetooth);
  blueToothSerial.flush();
  blueToothSerial.print("AT");
  Serial.println(blueToothSerial.readString());
  blueToothSerial.print("AT+NAMEEDR.dual.01"); //Nom Module
  Serial.print("Nom du module (EDR) : ");
  Serial.println(blueToothSerial.readString());
  blueToothSerial.print("AT+NAMBBLE.dual.01"); //Nom Module
  Serial.print("Nom du module (BLE) : ");
  Serial.println(blueToothSerial.readString());
  blueToothSerial.print("AT+SCAN?"); //Nom Module
  Serial.print("SCAN : ");
  Serial.println(blueToothSerial.readString());
  Serial.print("Vitesse de transmission : ");
  blueToothSerial.print("AT+BAUD?"); // Vitesse Transmission
  Serial.println(blueToothSerial.readString());
  Serial.print("Code Pin (EDR): ");
  blueToothSerial.print("AT+PINE?"); // Code PIN
  Serial.println(blueToothSerial.readString());
  Serial.print("Code Pin (BLE): ");
  blueToothSerial.print("AT+PINB?"); // Code PIN
  Serial.println(blueToothSerial.readString());
  Serial.print("Version : ");
  blueToothSerial.print("AT+VERS?"); // Version
  Serial.println(blueToothSerial.readString());
  Serial.print("Adresse MAC (EDR): ");
  blueToothSerial.print("AT+ADDE?"); // Température du module
  Serial.println(blueToothSerial.readString());
  Serial.print("Adresse MAC (BLE): ");
  blueToothSerial.print("AT+ADDB?"); // Température du module
  Serial.println(blueToothSerial.readString());
  Serial.print("Adresse DUAL : ");
  blueToothSerial.print("AT+DUAL?"); // Température du module
  Serial.println(blueToothSerial.readString());
  Serial.println("Fin setup");
  delay(2000);
  blueToothSerial.flush();
}

void loop()
{
  
  if(blueToothSerial.available()>0)
  {
    recvChar = blueToothSerial.readString();
    Serial.println(recvChar);
//    Serial.print(blueToothSerial.read());
//    Serial.write(blueToothSerial.read());
  }
  if(Serial.available()>0)
  {
    emitChar  = Serial.readString();
    Serial.println(emitChar);
    blueToothSerial.print(emitChar);
//    blueToothSerial.write(Serial.read());
//    blueToothSerial.print(Serial.read());
  }
}
