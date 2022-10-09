/*******************************************************************************
*                          DESCRIPCION DEL PROYECTO                            *
*******************************************************************************/

/*******************************************************************************
*                          MODULOS IMPORTADOS                                  *
*******************************************************************************/

#include <Arduino.h>

#include <Wire.h>               /* Necesaria para el I2C */
#include <Adafruit_GFX.h>       /* Librería genericas textos y pantallas */
#include <Adafruit_SSD1306.h>   /* Librería específica del controlador */

/*******************************************************************************
*                          DEFINICIONES Y MACROS                               *
*******************************************************************************/

#define BUTTON_UP_LEFT        6
#define BUTTON_DOWN_LEFT      7
#define BUTTON_UP_RIGHT       4
#define BUTTON_DOWN_RIGHT     5

// const int intPin1 = 4;
// const int intPin2 = 5;
// const int intPin3 = 6;
// const int intPin4 = 7;

#define ANCHO_OLED      128
#define ALTO_OLED       32
#define OLED_RESET      -1
#define DIR_I2C_OLED    0x3C

/*******************************************************************************
*                          TYPEDEFS Y ESTRUCTURAS                              *
*******************************************************************************/

/*******************************************************************************
*                          PARAMETROS GLOBALES                                 *
*******************************************************************************/

/* Se crea el objeto */
Adafruit_SSD1306 oled(ANCHO_OLED, ALTO_OLED, &Wire, OLED_RESET);

/*******************************************************************************
*                               FUNCIONES                                      *
*******************************************************************************/

void ActualizaPantalla (void)
{
    /* Se limpia la pantalla */
    oled.clearDisplay ();

    /* Se imprime el valor de humedad */
    oled.setTextSize (1);
    oled.setCursor (0, 0);
    oled.print ("-Imprimir carcasa P-TODO\n");
    oled.print ("-Hacer commit ScreenImplementation\n");
    oled.print ("-Otro texto");
    oled.display ();
}

void setup()
{
    pinMode(BUTTON_UP_LEFT, INPUT_PULLUP);
    pinMode(BUTTON_DOWN_LEFT, INPUT_PULLUP);
    pinMode(BUTTON_UP_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_DOWN_RIGHT, INPUT_PULLUP);
    Serial.begin(9600);
    // attachInterrupt(digitalPinToInterrupt(intPin), debounceCount, FALLING);

    Wire.begin ();
    oled.begin (SSD1306_SWITCHCAPVCC, DIR_I2C_OLED);
    oled.setTextColor (WHITE);
    oled.setTextSize (1);
 
    // /* Se gira la pantalla OLED 180 grados */
    // /* Mirror vertical */
    // Wire.beginTransmission (DIR_I2C_OLED);
    // Wire.write (0x80);
    // Wire.write (SSD1306_COMSCANINC);
    // Wire.endTransmission ();

    // /* Mirror horizontal */
    // Wire.beginTransmission (DIR_I2C_OLED);
    // Wire.write (0x80);
    // Wire.write (SSD1306_SEGREMAP);
    // Wire.endTransmission ();
}

void loop()
{
    // /* Se actualiza la información de la pantalla */
    // ActualizaPantalla ();

    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setCursor(0, 0);
    oled.setTextColor(SSD1306_WHITE);
    oled.println("Menu test");
    oled.println("");

    oled.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    oled.println("Opcion 1");
    oled.setTextColor(SSD1306_WHITE);
    oled.println("Opcion 2");
    // oled.setTextColor(SSD1306_WHITE);
    // oled.println("Opcion 3");

    oled.display ();

    int value = digitalRead(BUTTON_UP_LEFT);
    Serial.print("Boton 3  ");
    Serial.print(value);
    Serial.print("\t");
    value = digitalRead(BUTTON_UP_RIGHT);
    Serial.print("Boton 1  ");
    Serial.print(value);
    Serial.print("\n");
    value = digitalRead(BUTTON_DOWN_LEFT);
    Serial.print("Boton 4  ");
    Serial.print(value);
    Serial.print("\t");
    value = digitalRead(BUTTON_DOWN_RIGHT);
    Serial.print("Boton 2  ");
    Serial.print(value);
    Serial.print("\n");
    Serial.print("\n");
    delay(1000);
}