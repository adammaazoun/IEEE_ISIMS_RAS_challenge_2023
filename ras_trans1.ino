#include "Wire.h"
#include<SoftwareSerial.h>
#include <SR04.h> 
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10);
const byte address[6] = "00001"; 
int IN3=A2,IN4=A3,IN1=A0,IN2=A1,ENA=5,ENB=6; 
int speed=100; 
int trig=A5;
int echo1=4,echo2=7,echo3=8;
char t;
SR04 sr04(echo1, trig); // Echo pin, Trig pin
SR04 sr04_2(echo2, trig); 
SR04 sr04_3(echo3, trig); 
SoftwareSerial mySerial(2, 3); // RX, TX
void setup() 
{ Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);      
  mySerial.begin(9600);
  radio.begin();                  //Starting the Wireless communication
  radio.openWritingPipe(address); //Setting the address where we will send the data
  radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.stopListening();          //This sets the module as transmitter 
  
}
 
 void forward(int is_speed){ 
  
  digitalWrite(IN1,HIGH); 
  analogWrite(ENA,is_speed);  
  digitalWrite(IN3,HIGH);  
  analogWrite(ENB,is_speed);
}

void back(int is_speed){
  digitalWrite(IN2,HIGH); 
  analogWrite(ENA,is_speed); 
  digitalWrite(IN4 ,HIGH); 
  analogWrite(ENB,is_speed);
}

void right(int is_speed){
  digitalWrite(IN2,HIGH);
  digitalWrite(IN1,LOW); 
  analogWrite(ENA,is_speed); 
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);  
  analogWrite(ENB,is_speed); 

}

void left(int is_speed){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENA,is_speed); 
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENB,is_speed);
}

void halt(){

  analogWrite(ENA,0); 
  analogWrite(ENB,0); 
}

void stoprobot()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void farleft(int is_speed)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA,is_speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB,is_speed);
}

void farright(int is_speed)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA,is_speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB,is_speed);
}

void bacleft(int is_speed)
{
   digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB,is_speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA,is_speed);
  
}

void bacright(int is_speed)
{
   digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB,is_speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA,is_speed);
}
void loop()
{ int d1 = sr04.Distance();
  int d2 = sr04_2.Distance();
  int d3 = sr04_3.Distance();
  //Serial.print(d1);
  //Serial.print(d2);
  //Serial.print(d3);
  Serial.println();
  
  while (mySerial.available())
 {  
  t=mySerial.read();   }
   if (t== '0')  
   {                            
      speed=0;
        }
  else if(t== '1')                               
      {speed=20;
       }
  else if (t== '2')                 
      {speed=40;
        }
  else if (t== '3')
        {speed=70;
        }
  else if (t== '4')                    
        {speed=100;
        }
  else if (t== '5')                                           
        {speed=120;
         }  
  else if (t== '6')                               
        {speed=120;
        }
  else if (t== '7')                                
        {speed=155;
        }
  else if (t== '8')                
        {speed=220;
        }
  else if (t== '9')
        {speed=255;
        }
  else if (t== 'q')
        {speed=250;
        }
     
  if (t=='F')
        forward(speed);
  else if (t=='B')    
        back(speed);
  else if(t=='R')
        right(speed);
  else if (t=='L')
        left(speed); 
  else if (t=='G')
        farleft(speed);
  else if (t=='I')
        farright(speed);
  else if (t=='H')
        bacleft(speed);
  else if (t=='J')
        bacright(speed);
  else 
        stoprobot();
  
  

   
 
                                                              
   if (mySerial.available() < 0)                              
    {
      halt();       
      stoprobot(); 
    }
    int text[] = {speed, d1, d2, d3};
    radio.write(&text, sizeof(text));
    Serial.print("data:speed= ");
  
      Serial.print(text[0]);
      Serial.print(" left front distance=");
       Serial.print(text[1]);
       Serial.print(" right front distance=");
       Serial.print(text[2]);
       Serial.print(" back distance=");
       Serial.print(text[3]);
  
    Serial.println();
}
