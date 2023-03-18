#include <LiquidCrystal.h>
#include <Keypad.h>

char teclaAnt;
char teclAct='a';
char tecTemp;
int short cont = 1;


//definimos los pines del display lcd e inicializamos el objeto
const int rs = 3, en = 2, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//definimos los pines del teclado  e inicializamos el objeto
const byte numRows= 4;
const byte numCols= 4;

char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};


byte rowPins[numRows] = {11,10,9,8};
byte colPins[numCols]=  {7,6,5,4};

Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);


}

void loop() {
    char keypressed = myKeypad.getKey();
    if (keypressed != NO_KEY){
    teclAct= keypressed;
    lcd.setCursor(0, 0);
    lcd.print(String("tecla act: ") + String(teclAct));  
        if(teclAct !='a' && cont <1){
        teclaAnt = tecTemp;       
        lcd.setCursor(0, 1);
        lcd.print(String("tecla ant: ") + String(teclaAnt));
        }
    cont--;
    tecTemp = teclAct;
    }        
      }

