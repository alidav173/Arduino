

/*definimos los 8 pines del led cátodo común
 * La función de este programa en el arduino es mostrar los números en hexadecimal. Del 0 a F.
 * Cuando se presiona el botón reset, el contador vuelve a 0.
 * Cuando se presiona el botón UP, se incrementa el número.
 * Cuando se presiona el botón DOWN, se disminuye el número.
 * 
 * 
 */*/
#define LUZB 8
#define LUZA 7
#define LUZF 6
#define LUZG 5
#define LUZE 4
#define LUZD 3
#define LUZC 2

//tope para la mostrar los numeros en hexadecimal
#define TOPE 16

//declaramos los 3 botones
#define PULSAUP 9
#define PULSADOWN 10
#define PULSARESET 12


//inicializamos las variables globales
int valor = 0;
int valorUp = 0;
int valorDown = 0;
int contador = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LUZA,OUTPUT);
  pinMode(LUZB,OUTPUT);
  pinMode(LUZC,OUTPUT);
  pinMode(LUZD,OUTPUT);
  pinMode(LUZE,OUTPUT);
  pinMode(LUZF,OUTPUT);
  pinMode(LUZG,OUTPUT);
  pinMode(PULSAUP,INPUT_PULLUP);
  pinMode(PULSADOWN,INPUT_PULLUP);
  pinMode(PULSARESET,INPUT_PULLUP);
  
}

void loop()
{
 //leemos el valor de los botones con la funcion digitalRead()
  valor = digitalRead(PULSARESET);
  if(valor == LOW){
    contador = 0;
    encenderNumero(contador);
  }
    valorUp = digitalRead(PULSAUP);
    if(valorUp == LOW && contador < TOPE){
      contador++;
       apagarNumero();
      delay(1000);
      encenderNumero(contador);

    }
    
      valorDown = digitalRead(PULSADOWN);
    if(valorDown == LOW && contador >0){
      contador--;
       apagarNumero();
      delay(1000);
      encenderNumero(contador);

    }
  
}

void encenderNumero(int contador){
  switch(contador){
    case 0:
  digitalWrite(LUZC,HIGH);
  digitalWrite(LUZD,HIGH);
  digitalWrite(LUZE,HIGH);
  digitalWrite(LUZF,HIGH);
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZD,HIGH);
  digitalWrite(LUZB,HIGH);
    break;
    
    case 1:
  digitalWrite(LUZB,HIGH);
  digitalWrite(LUZC,HIGH);
    break;
    
    case 2:
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZB,HIGH);
  digitalWrite(LUZG,HIGH);
  digitalWrite(LUZE,HIGH);
  digitalWrite(LUZD,HIGH);
    break;

    case 3:
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZB,HIGH);
  digitalWrite(LUZC,HIGH);
  digitalWrite(LUZG,HIGH);
  digitalWrite(LUZD,HIGH);
    break;

      case 4:
  digitalWrite(LUZF,HIGH);
  digitalWrite(LUZG,HIGH);
  digitalWrite(LUZB,HIGH);
  digitalWrite(LUZC,HIGH);
    break;

      case 5:
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZF,HIGH);
  digitalWrite(LUZG,HIGH);
  digitalWrite(LUZC,HIGH);
  digitalWrite(LUZD,HIGH);
    break;

      case 6:
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZF,HIGH);
  digitalWrite(LUZG,HIGH);
  digitalWrite(LUZC,HIGH);
  digitalWrite(LUZD,HIGH);
  digitalWrite(LUZE,HIGH);
    break;

      case 7:
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZB,HIGH);
  digitalWrite(LUZC,HIGH);
    break;

    case 8:
  digitalWrite(LUZC,HIGH);
  digitalWrite(LUZD,HIGH);
  digitalWrite(LUZE,HIGH);
  digitalWrite(LUZF,HIGH);
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZD,HIGH);
  digitalWrite(LUZG,HIGH);
  digitalWrite(LUZB,HIGH);
    break;

     case 9:
  digitalWrite(LUZC,HIGH);
  digitalWrite(LUZD,HIGH);
  digitalWrite(LUZF,HIGH);
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZD,HIGH);
  digitalWrite(LUZG,HIGH);
  digitalWrite(LUZB,HIGH);
    break;

   case 10:
  digitalWrite(LUZC,HIGH);
  digitalWrite(LUZE,HIGH);
  digitalWrite(LUZF,HIGH);
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZG,HIGH);
  digitalWrite(LUZB,HIGH);
    break;

     case 11:
  digitalWrite(LUZC,HIGH);
  digitalWrite(LUZD,HIGH);
  digitalWrite(LUZE,HIGH);
  digitalWrite(LUZF,HIGH);
  digitalWrite(LUZG,HIGH);
    break;

        case 12:
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZF,HIGH);
  digitalWrite(LUZE,HIGH);
  digitalWrite(LUZD,HIGH);
    break;

      case 13:
  digitalWrite(LUZC,HIGH);
  digitalWrite(LUZD,HIGH);
  digitalWrite(LUZE,HIGH);
  digitalWrite(LUZG,HIGH);
  digitalWrite(LUZB,HIGH);
    break;

      case 14:
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZF,HIGH);
  digitalWrite(LUZE,HIGH);
  digitalWrite(LUZG,HIGH);
  digitalWrite(LUZD,HIGH);
    break;

        case 15:
  digitalWrite(LUZA,HIGH);
  digitalWrite(LUZE,HIGH);
  digitalWrite(LUZF,HIGH);
  digitalWrite(LUZG,HIGH);
    break;
  }
}

void apagarNumero(){
  digitalWrite(LUZC,LOW);
  digitalWrite(LUZD,LOW);
  digitalWrite(LUZE,LOW);
  digitalWrite(LUZF,LOW);
  digitalWrite(LUZA,LOW);
  digitalWrite(LUZD,LOW);
  digitalWrite(LUZG,LOW);
  digitalWrite(LUZB,LOW);

}
