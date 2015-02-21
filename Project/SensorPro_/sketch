
#include <Data.h>
//#include <DataUser.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 3 on the Arduino
#define ONE_WIRE_BUS 3
 
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

float temperature (void) {
  //return 0 ;
  sensors.requestTemperatures(); 
  return sensors.getTempCByIndex(0) ;
}  

float val ;
float micro (void) {
  val = analogRead(6);
  return val ;
}

Data data_Tmp(115,"hh",0,3,1,1,0,120,false,&temperature);
Data data_Mic(116,"hh",0,3,4,1,100,1000,false,&micro);

//Alert alert(12,SUP,800,false);
//DataUser data1(116,"hh",0,2,0.1,1,0,80,false);



void setup() {   
Serial.begin(57600) ;
Serial.println("Dallas Temperature IC Control Library Demo"); 
pinMode(2,INPUT);
digitalWrite(2, HIGH);

sensors.begin();

//data.addAssociateAlert(alert);

}

long tmp1 ;
long tmp2;
float i,j ;

void loop() {
  tmp1 = millis() ;
  data_Tmp.update() ;
  data_Mic.update() ;
  tmp2 = millis() ;
  Serial.print("temps pris par update ");
  Serial.println((tmp2-tmp1));
  i = temperature() ;
  j = micro() ;
  Serial.print("ind temp ");
  Serial.print(i);
  Serial.print("  mic ");
  Serial.println(j);

  delay(500) ;

}
