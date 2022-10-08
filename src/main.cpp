/*******************************************************************************
*                          DESCRIPCION DEL PROYECTO                            *
*******************************************************************************/

/*******************************************************************************
*                          MODULOS IMPORTADOS                                  *
*******************************************************************************/

#include <Arduino.h>

/*******************************************************************************
*                          DEFINICIONES Y MACROS                               *
*******************************************************************************/

const int intPin1 = 4;
const int intPin2 = 5;
const int intPin3 = 6;
const int intPin4 = 7;
volatile int ISRCounter = 0;
int counter = 0;

/*******************************************************************************
*                          TYPEDEFS Y ESTRUCTURAS                              *
*******************************************************************************/

/*******************************************************************************
*                          PARAMETROS GLOBALES                                 *
*******************************************************************************/

/*******************************************************************************
*                               FUNCIONES                                      *
*******************************************************************************/

void setup()
{
    pinMode(intPin1, INPUT_PULLUP);
    pinMode(intPin2, INPUT_PULLUP);
    pinMode(intPin3, INPUT_PULLUP);
    pinMode(intPin4, INPUT_PULLUP);
    Serial.begin(9600);
    // attachInterrupt(digitalPinToInterrupt(intPin), debounceCount, FALLING);
}

void loop()
{
    int value = digitalRead(intPin3);
    Serial.print("Boton 3  ");
    Serial.print(value);
    Serial.print("\t");
    value = digitalRead(intPin1);
    Serial.print("Boton 1  ");
    Serial.print(value);
    Serial.print("\n");
    value = digitalRead(intPin4);
    Serial.print("Boton 4  ");
    Serial.print(value);
    Serial.print("\t");
    value = digitalRead(intPin2);
    Serial.print("Boton 2  ");
    Serial.print(value);
    Serial.print("\n");
    Serial.print("\n");
    delay(1000);
}