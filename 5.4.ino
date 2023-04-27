
#include <Keypad.h>

const byte filas = 4;
const byte columnas = 4;
char letras[filas][columnas]= {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}

};

byte pinesf[filas] = {A0,A1,A2,A3};
byte pinesc[columnas] = {6,7,8,9};
Keypad teclado = Keypad(makeKeymap(letras),pinesf,pinesc,filas,columnas);
char estado;

const int radarPin = 2;
const int buzzerPin = 11;
char contra[6]=  "5812B";
char ponercontra[6];
int indice=0;

void setup()
{
Serial.begin(9600);
  pinMode(radarPin, INPUT);
  pinMode(buzzerPin,OUTPUT);
}

void loop(){
  
  
  
  
estado = teclado.getKey();
Serial.println(estado);
  
  
 int radarValue = digitalRead(radarPin);
  if (radarValue == HIGH) { 
    Serial.println("Movement detected!");
          digitalWrite(buzzerPin, HIGH); 
  

  
  
  if(estado){
  ponercontra[indice]=estado;
    indice++;
    Serial.println(estado);
       
  }
  
  if(indice==6){
    
    if(strcmp(contra,ponercontra)==0){
    Serial.println("Acceso permitido");
      delay(100);
      digitalWrite(buzzerPin,LOW);
      delay(5000);
    }
    else{
    Serial.println("Acceso denegado");
      delay(100);
    }
  }
  }
}