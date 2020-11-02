//=======================================================Flame Sensor===========================================================

int valorSensor0 = 0;
int valorSensor1 = 0;
int valorSensor2 = 0;
int valorSensor3 = 0;
int valorSensor4 = 0;

//=========================================================Temp Sensor=============================================================

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celsius = 0;
float Fahrenheit = 0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void setup() {
  // put your setup code here, to run once:

//===========================================================Flame Sensor============================================================
  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);

//===========================================================Temp Sensor=============================================================

  pinMode(3,OUTPUT);
  sensors.begin();
  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
//=========================================================Flame Sensor==================================================================
  
  valorSensor0 = analogRead (A0) ;   // reads the status of the flame sensor
  valorSensor1 = analogRead (A1) ;
  valorSensor2 = analogRead (A2) ;
  valorSensor3 = analogRead (A3) ;
  valorSensor4 = analogRead (A4) ;

  if( valorSensor0 >= 100 || valorSensor1 >= 100 || valorSensor2 >= 100 || valorSensor3 >= 100 || valorSensor4 >= 100 )
  {
     digitalWrite(13,HIGH);  
  }

  else

     digitalWrite(13,LOW);

//========================================================Temp Sensor====================================================================

  sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);

  if(Celsius > 82)
  {
    digitalWrite(12,HIGH);
  }

  else
    digitalWrite(12,LOW);
  
  Serial.print("Sensor 0 value:");
  Serial.println(valorSensor0);
  Serial.print("Sensor 1 value:");
  Serial.println(valorSensor1);
  Serial.print("Sensor 2 value:");
  Serial.println(valorSensor2);
  Serial.print("Sensor 3 value:");
  Serial.println(valorSensor4);
  Serial.print("Sensor 4 value:");
  Serial.println(valorSensor4);
  Serial.println();
  
  Serial.print(Celsius);
  Serial.print(" C  ");
  Serial.print(Fahrenheit);
  Serial.println(" F");
  Serial.println();
  Serial.println();
  
}
