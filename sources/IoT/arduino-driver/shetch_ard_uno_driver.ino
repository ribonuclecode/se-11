// Include Libraries
#include "Arduino.h"
#include "Buzzer.h"
#include "LED.h"
#include "Button.h"


// Pin Definitions
#define BUZZER_PIN_SIG	2
#define LEDR_PIN_VIN	5
#define PIEZOVIBRATION_PIN_NEG	A3
#define PUSHBUTTONMOMENTARY_PIN_2	3



// Global variables and defines

// object initialization
Buzzer buzzer(BUZZER_PIN_SIG);
LED ledR(LEDR_PIN_VIN);
Button pushButtonMomentary(PUSHBUTTONMOMENTARY_PIN_2);


// define vars for testing menu

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
  int buttState = digitalRead(3);
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    while(buttState = digitalRead(3)) //Mejora el algoritmo y su velocidad
    {
      if(analogRead(A3)>1100){
        digitalWrite(ledR, HIGH); // Encender el LED de localización
      //tone(buzzer, 440, 1000) //Activar el tono a 440Hz durante 1 segundo y desactivarlo (esperando 0,5s)
        digitalWrite(2, HIGH); //Manda una señal de alto al buzzer, lo que hace que emita un sonido al ser buzzer activo
        delay(1000); //Emite el sonido 1 segundo
        digitalWrite(2,LOW); //Manda la señal a 0V al buzzer
        delay(500);
      }
    }
}
