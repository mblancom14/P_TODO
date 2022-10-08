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
    oled.setCursor (0, 1);
    oled.print ("-Imprimir carcasa P-TODO\n");
    oled.print ("-Hacer commit ScreenImplementation");
    oled.display ();
}

void setup()
{
    Serial.begin (9600);

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
    /* Se actualiza la información de la pantalla */
    ActualizaPantalla ();

    delay (10);
}