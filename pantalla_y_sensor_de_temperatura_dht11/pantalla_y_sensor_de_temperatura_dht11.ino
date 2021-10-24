
/*Programa para arduino uno, con display lcd 16x2 y sensor de temperatura
 * y humedad DHT11.
 * Hay que instalar la biblioteca DHT sensor library  y Adafruit Unified Sensor
Si no logra medir la temperatura el programar muestra un mensaje de ERROR.

*/
#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define  PIN8 8


//definimos los pines del display lcd e inicializamos el objeto
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//inicializamos el sensor de temperatura 
DHT dht(PIN8, DHTTYPE);  
float temp; 

void setup() {


lcd.begin(16, 2);
dht.begin();
lcd.print("Temp actual:  ");

}

void loop() {

delay(2000);
temp = dht.readTemperature();  
 lcd.setCursor(0, 1);
 if (isnan(temp)) {
    lcd.print("Error");
    return;
  }
 else{
     lcd.print(temp);
     lcd.print(" C");
 }
  
}
