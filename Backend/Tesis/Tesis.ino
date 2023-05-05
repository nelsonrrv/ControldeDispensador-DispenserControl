//
//Thanks to Adafruit forums member Asteroid for the original sketch!
//
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>
#include <RTClib.h>
#include <WiFiClient.h> 
#include <SoftwareSerial.h>
#include <NewPing.h>
#include <LiquidCrystal.h>
#define LENGTH 20
int i_1, i_2, i_3, i_4;

 
String t_1,t_2,t_3,t_4;




// include the library code:


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, di4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, di4, d5, d6, d7);

// Librería para la comunicación I2C y la RTClib

int V1 = 32; //Salida valvula 1
int V2 = 33; //Salida valvula 2
int V3 = 34; //Salida valvula 3
int V4 = 35; //Salida valvula 4


int W1 = 50; //Salida led amarrillo 1
int W2 = 51; //Salida led amarrillo 2
int W3 = 52; //Salida led amarrillo 3
int W4 = 53; //Salida led amarrillo 4

 // Prototipos de funciones
void dispensar();


// Declaramos un RTC DS3231
RTC_DS3231 rtc;

const int Trigger_1 = 40;   //Pin digital 2 para el Trigger del sensor
const int Echo_1 = 41;   //Pin digital 3 para el Echo del sensor

const int Trigger_2 = 42;   //Pin digital 2 para el Trigger del sensor
const int Echo_2 = 43;   //Pin digital 3 para el Echo del sensor

const int Trigger_3 = 44;   //Pin digital 2 para el Trigger del sensor
const int Echo_3 = 45;   //Pin digital 3 para el Echo del sensor

const int Trigger_4 = 46;   //Pin digital 2 para el Trigger del sensor
const int Echo_4  = 47;   //Pin digital 3 para el Echo del sensor


  bool tanque_1, tanque_2, tanque_3, tanque_4;
  long cantidad_1, cantidad_2, cantidad_3, cantidad_4;
  int ml_ini_1, ml_ini_2, ml_ini_3, ml_ini_4;
  int altura_final_1, altura_final_2,altura_final_3,altura_final_4;
  int ml_final_1, ml_final_2, ml_final_3, ml_final_4; 
  int altura_finalfinal_1, altura_finalfinal_2, altura_finalfinal_3, altura_finalfinal_4;
  int area_base = 42;
  int altura_tanque = 5;
  int altura_actual_1,altura_actual_2,altura_actual_3,altura_actual_4                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       ;
  long t1, t2, t3, t4; //timepo que demora en llegar el eco
  long d1, d2, d3, d4; //distancia en centimetros


 
 
void setup(void)
{

Serial.begin(9600);//iniciailzamos la comunicación

// set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

 cantidad_1 = 10;
 cantidad_2 = 10;
 cantidad_3 = 10;
 cantidad_4 = 10; 
    
 tanque_1 = true;
 tanque_2 = true;
// tanque_3 = false;
 //tanque_4 = false;

 t_1="OFF";
 t_2="OFF";
 t_3="OFF";
 t_4="OFF";
 
  // put your setup code here, to run once:
  pinMode(V1, OUTPUT); //Sets the pin as an output
  pinMode(V2, OUTPUT); //Sets the pin as an output
  pinMode(V3, OUTPUT); //Sets the pin as an output
  pinMode(V4, OUTPUT); //Sets the pin as an output
  
  pinMode(W1, OUTPUT); //Sets the pin as an output
  pinMode(W2, OUTPUT); //Sets the pin as an output
  pinMode(W3, OUTPUT); //Sets the pin as an output
  pinMode(W4, OUTPUT); //Sets the pin as an output

  pinMode(Trigger_1, OUTPUT); //pin como salida
  pinMode(Echo_1, INPUT);  //pin como entrada
  digitalWrite(Trigger_1, LOW);//Inicializamos el pin con 0
  delay(3000);

  pinMode(Trigger_2, OUTPUT); //pin como salida
  pinMode(Echo_2, INPUT);  //pin como entrada
  digitalWrite(Trigger_2, LOW);//Inicializamos el pin con 0
  delay(3000);

  pinMode(Trigger_3, OUTPUT); //pin como salida
  pinMode(Echo_3, INPUT);  //pin como entrada
  digitalWrite(Trigger_3, LOW);//Inicializamos el pin con 0
  delay(3000);

  pinMode(Trigger_4, OUTPUT); //pin como salida
  pinMode(Echo_4, INPUT);  //pin como entrada
  digitalWrite(Trigger_4, LOW);//Inicializamos el pin con 0
  delay(3000);

  
  // Comprobamos si tenemos el RTC conectado
 if (! rtc.begin()) {
 Serial.println("No hay un módulo RTC");
 while (1);
 }
 
 // Ponemos en hora, solo la primera vez, luego comentar y volver a cargar.
 // Ponemos en hora con los valores de la fecha y la hora en que el sketch ha sido compilado.
 //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));


}


void loop()
{

  digitalWrite(Trigger_1, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger_1, LOW);
  
  t1 = pulseIn(Echo_1, HIGH); //obtenemos el ancho del pulso
  d1 = t1/59;             //escalamos el tiempo a una distancia en cm

  Serial.print("Distancia 1: ");
  Serial.print(d1);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);         

  digitalWrite(Trigger_2, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger_2, LOW);
  
  t2 = pulseIn(Echo_2, HIGH); //obtenemos el ancho del pulso
  d2 = t2/59;             //escalamos el tiempo a una distancia en cm
 
 
 Serial.print("Distancia 2: ");
  Serial.print(d2);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100); 

  
  digitalWrite(Trigger_3, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger_3, LOW);
  
  t3 = pulseIn(Echo_3, HIGH); //obtenemos el ancho del pulso
  d3 = t3/59;             //escalamos el tiempo a una distancia en cm


 Serial.print("Distancia 3: ");
  Serial.print(d3);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100); 

  
  digitalWrite(Trigger_4, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger_4, LOW);
  
  t4 = pulseIn(Echo_4, HIGH); //obtenemos el ancho del pulso
  d4 = t4/59;             //escalamos el tiempo a una distancia en cm
  
 Serial.print("Distancia 4: ");
  Serial.print(d4);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100); 

  
if(d1< 4){
    delay (100);
    digitalWrite(W1 , LOW);
           
  } else {
    delay(100);
    digitalWrite(W1 , HIGH); 
    }

if(d2< 4){
    delay (100);
    digitalWrite(W2 , LOW);
           
  } else {
    delay(100);
    digitalWrite(W2 , HIGH); 
    }

if(d3< 4){
    delay (100);
    digitalWrite(W3 , LOW);
           
  } else {
    delay(100);
    digitalWrite(W3 , HIGH); 
    }

if(d4< 4){
    delay (100);
    digitalWrite(W4 , HIGH);
           
  } else {
    delay(100);
    digitalWrite(W4 , HIGH); 
    }

dispensar();

  
}

void dispensar () {


  
  if (tanque_1==true) {
    
      int alturas_1 [i_1];
      altura_actual_1= altura_tanque - d1;

      alturas_1[i_1]= altura_actual_1;
       i_1++; 

      delay(100);
      // Reiniciando variables
      ml_ini_1 = ml_ini_1 - ml_ini_1;
      ml_final_1= ml_final_1 - ml_final_1;
      altura_final_1= altura_final_1 - altura_final_1;
      altura_finalfinal_1= altura_finalfinal_1 - altura_finalfinal_1;

       delay(100);
      // Calculos
      ml_ini_1 = area_base * alturas_1[0] ;
      ml_final_1 = ml_ini_1 - cantidad_1;
      altura_final_1 = ml_final_1 / area_base;
      altura_finalfinal_1 = altura_final_1 - altura_tanque;

    if(d1 <= 3 ){
        
      
      digitalWrite(V1 , HIGH);
      t_1= "ON";
      
    }      else {
        delay(100);
        digitalWrite(V1 , LOW);
        t_1= "OFF";
        tanque_1 = false;
        cantidad_1 =0;
        memset(alturas_1, 0, i_1);
        i_1 = 0;
        
      
       } 
       
  } 
  
  if (tanque_2==true) {

      int alturas_2 [i_2];
      altura_actual_2= altura_tanque - d2;
      alturas_2[i_2]= altura_actual_2;
      i_2++;

      delay(100);
      // Reiniciando variables
      ml_ini_2 = ml_ini_2 - ml_ini_2;
      ml_final_2 = ml_final_2 - ml_final_2;
      altura_final_2 = altura_final_2 - altura_final_2;
      altura_finalfinal_2 = altura_finalfinal_2 - altura_finalfinal_2;

      delay(100);
      // Haciendo Calculos
      ml_ini_2 = area_base * alturas_2[0] ;
      ml_final_2 = ml_ini_2 - cantidad_2;
      altura_final_2 = ml_final_2 / area_base;
      altura_finalfinal_2 = altura_final_2 - altura_tanque;
      
       
    if (d2 <= 3) {
      digitalWrite(V2 , HIGH);
      t_2="ON";
      
      } 
      else {
        
        delay(100);
        digitalWrite(V2 , LOW);
        tanque_2 = false;
        cantidad_2 =0;
        memset(alturas_2, 0, i_2);
        i_2 = 0;
        t_2="OFF";
        
       }

       } 
       
 if (tanque_3==true) {

      int alturas_3 [i_3];
      altura_actual_3= altura_tanque - d3;
      alturas_3[i_3]= altura_actual_3;
      i_3++;

      delay(100);
      // Reiniciando variables
      ml_ini_3 = ml_ini_3 - ml_ini_3;
      ml_final_3 = ml_final_3 - ml_final_3;
      altura_final_3 = altura_final_3 - altura_final_3;
      altura_finalfinal_3 = altura_finalfinal_3 - altura_finalfinal_3;

      delay(100);
      // Calculos
      ml_ini_3 = area_base * alturas_3[0] ;
      ml_final_3 = ml_ini_3 - cantidad_3;
      altura_final_3 = ml_final_3 / area_base;
      altura_finalfinal_3 = altura_final_3 - altura_tanque;
        
        if(ml_final_3 > 0){
          
    if (d3 > altura_finalfinal_3) {
      
      digitalWrite(V3 , HIGH);
      t_3="ON";
      
      }
      else{

        t_3="OFF";
        digitalWrite(V3 , LOW);
        tanque_3 = false;
        cantidad_3 =0;
        memset(alturas_3, 0, i_3);
        i_3 = 0;
        
        }
        
       }else {

          Serial.println("La cantidad no puede ser mayor a lo restante en el tanque");
        
       }
       } 
       
       
if (tanque_4==true) {
          
          
          int alturas_4 [i_4];
          altura_actual_4= altura_tanque - d4;
          alturas_4[i_4]= altura_actual_4;
          i_4++;
          
          delay(100);
          // Reinicio de variables
          ml_ini_4 = ml_ini_4 - ml_ini_4;
          ml_final_4 = ml_final_4 - ml_final_4;
          altura_final_4 = altura_final_4 - altura_final_4;
          altura_finalfinal_4 = altura_finalfinal_4 - altura_finalfinal_4;

          delay(100);
          // Calculos
          ml_ini_4 = area_base * alturas_4[0] ;
          ml_final_4 = ml_ini_4 - cantidad_4;
          altura_final_4 = ml_final_4 / area_base;
          altura_finalfinal_4 = altura_final_4 - altura_tanque;

           delay(100);
if(ml_final_4 > 0){
       if (d4 > altura_finalfinal_4) {
      
      digitalWrite(V4 , HIGH);
      t_4="ON";
      
      } else {

       delay(100);
      digitalWrite(V4 , LOW);
         tanque_4 = false;
        cantidad_4 =0;
        memset(alturas_4, 0, i_4);
        i_4 = 0;
        t_4="OFF";
        
          }
          
        }          else {

          Serial.println("La cantidad no puede ser mayor a lo restante en el tanque");
        
       }
          } 

  }



 
