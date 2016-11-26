#include "Sensor.h"


Sensor::Sensor () {
}

Sensor::Sensor (short id, string pin, int classe) {
	this->id = id ;
	this->pin = pin;
	this->state = true;
	this->classe = classe;
	this->dataList = SimpleList<Data*>();
	this->data_periodicity_lcm = UNDEFINED_PERIODE ;
}

Sensor::~Sensor () { }


/**
 */
 void Sensor::enableSensor ()
 {
	 this->state = true ;
 }

 /**
  */
 void Sensor::disableSensor ()
 {
	 this->state = false ;

 }

 /**
  */
 bool Sensor::getState ()   {
	 return this->state;
 }

 /**
  */
 Data Sensor::findDataById (short data_id)
 {
	 SimpleList<Data*>::iterator i  ;
	 Data * data = NULL  ;
	 for ( i = dataList.begin(); i != dataList.end(); i++ ) {
		 if ( (*i)->getId() == data_id )
			 data = (*i) ;
	 }
	 return (*data) ;
 }

 /**
  */
 DataList Sensor::listData ()
 {
	 return dataList ;
 }


 void Sensor::listAssociateData ()
 {
	 SimpleList<Data*>::iterator i  ;
	 for ( i = dataList.begin(); i != dataList.end(); i++ ) {
		 (*i)->getInfos() ;
	 }
 }



 /**
  */
 void Sensor::updateData ()
 {
	 SimpleList<Data*>::iterator i  ;
	 for ( i = dataList.begin(); i != dataList.end(); i++ ) {
		 (*i)->update() ;
	 }
 }

 /*
  */


 Data Sensor::addData(Data* data) {

	 if (data == NULL) return *data;
	 dataList.push_back(data) ;


	 //float a = data_frequency_lcm ;
	 int a = data_periodicity_lcm;


	 if( a == UNDEFINED_PERIODE ) // if no data added to sensor yet
	 {
		 a = data->getPeriode();
	 }

	 int b = data->getPeriode();

	 int result(getPGCD(a,b));

	 setData_periodicity_lcm(result);

	 return *data;
 }


 int Sensor::getPGCD(int a, int b){
	 int r(0);
	 while(b!=0){
		 r = a%b;
		 a = b;
		 b = r;
	 }
	 return a;


 }


 int Sensor::getPPCM(int x, int y){
	 int a =x;
	 int b =y;
	 while(a!=b){
		 while(a>b) b = b+y;
		 while (a<b) a = a+x;
	 }
	 return a;
 }

 /*
  *
  */
 void Sensor::deleteData (short id) {
	 SimpleList<Data*>::iterator i  ;
	 for ( i = dataList.begin(); i != dataList.end(); i++ ) {
		 if ( (*i)->getId() == id ){
			 dataList.erase(i) ;

		 }
	 }
 }

 /**
  */
 short Sensor::getId ()   {
	 return id;
 }

 /**
  */
 void Sensor::setPin (string  new_var)   {
	 if (new_var != NULL )
		 pin = new_var;
 }

 /**
  */
 string Sensor::getPin ()   {
	 return pin;
 }


 /**
  */
 void Sensor::setClass (int new_var)   {
	 if (new_var != NULL)
		 classe = new_var;
 }

 /**
  */
 int Sensor::getClass ()   {
	 return classe;
 }



 void Sensor::setData_periodicity_lcm (int new_var)   {
	 data_periodicity_lcm = new_var;
 }




 int Sensor::getData_periodicity_lcm ()   {
	 return data_periodicity_lcm;
 }

 void Sensor::getInfos () {
	 Serial.println("");
	 Serial.print("Sensor id : ");
	 Serial.println(id);
	 Serial.print("pin: ");
	 Serial.println(pin);
	 Serial.print("classe: ");
	 Serial.println(classe);
	 Serial.print("state: ");
	 Serial.println(state);
	 Serial.print("periodicity : ");
	 Serial.println(data_periodicity_lcm);
 }


 void Sensor::enableAutoSend (short data_id)
 {
	 SimpleList<Data*>::iterator i  ;
	 for ( i = dataList.begin(); i != dataList.end(); i++ ) {
		 if ( (*i)->getId() == data_id ){
			 // Serial.print("Classe sensor enableAutoSend id\n");
			 //Serial.print("i.getId\n");
			 // Serial.println((*i)->getId());
			 // Serial.print("data_id\n");
			 // Serial.println(data_id);
			 //(*i)->enableDataAutoSend () ;
			 (*i)->setDataAutoSend(true);
		 }
	 }
 }

 /**
  */
 void Sensor::disableAutoSend (short data_id){

	 SimpleList<Data*>::iterator i  ;
	 for ( i = dataList.begin(); i != dataList.end(); i++ ) {
		 if ( (*i)->getId() == data_id ){
			 //Serial.print("Classe sensor disableAutoSend id\n");
			 //Serial.print("i.getId\n");
			 //Serial.println((*i)->getId());
			 //Serial.print("data_id\n");
			 //Serial.println(data_id);
			 //(*i)->disableDataAutoSend () ;
			 (*i)->setDataAutoSend(false);
		 }
	 }
 }
