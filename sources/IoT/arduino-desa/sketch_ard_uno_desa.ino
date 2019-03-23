// Include Libraries
#include "Arduino.h"
#include <SoftwareSerial.h>
#include <TinyGPS.h>

// Definición de PIN
#define PIEZOVIBRATION_PIN_NEG	A3


// Variables Globales
TinyGPS gps;
SoftwareSerial ss(4, 3); //GPS
SoftwareSerial SIM900(7, 8); //GSMR (SMS)


const unsigned long ID = 1203048493;

bool newData = false;
float flat, flon;
unsigned long age;

char c;

void setup()
{
  ss.begin(9600);
  SIM900.begin(19200);
  delay(20000);
}


void loop()
{
 
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (ss.available())
    {
      c = ss.read();
	  
      if (gps.encode(c)){ 
        leerGps();
      }
    }
  }
  if (analogRead(A3) > 1100) {
	if(ss.available()){
		leerGPS();
	  }
      sendSMS();
    }
}

void leerGPS(){
      c = ss.read();
      if (gps.encode(c)) {
		gps.f_get_position(&flat, &flon, &age);
	  }
 }

void sendSMS() {
  SIM900.print("AT+CMGF=1\r");
  delay(100);

  // Teléfono de emergencias
  SIM900.println("AT + CMGS = \"+112\"");
  delay(100);
  
  //Formato de presentación de los datos para el parseador
  SIM900.println("lat,long,ID");
  
  // Enviar localizacion GPS y ID del arduino
  SIM900.println("%.9f,%.9f,%lu", flat, flon, ID);
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26);
  
  delay(100);
  SIM900.println();
  
  // Tiempo para poner mandar el SMS
  delay(5000);
}