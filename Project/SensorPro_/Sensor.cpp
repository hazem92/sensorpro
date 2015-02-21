#include "Sensor.h"


Sensor::Sensor () {
}

Sensor::Sensor (short id, string pin, int classe) {
	        this->id = id ;
		this->pin = pin;
		this->state = true;
		this->classe = classe;
		this->dataList = {} ;
}

Sensor::~Sensor () { }


/**
 */
void Sensor::enableSensor ()
{
	state = true ;
}

/**
 */
void Sensor::disableSensor ()
{
	state = false ;

}

/**
 */
bool Sensor::getState ()   {
  return state;
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
Data Sensor::addData(Data *data) {
	
	if (data = NULL) 
		return *data;

	// Alert.id can't be already taken
	SimpleList<Data*>::iterator i  ;
	for ( i = dataList.begin(); i != dataList.end(); i++ ) {
		 if ( (*i)->getId() == data->getId() ) {
 			 return *(*i);
		}
	}

	this->dataList.push_back(data) ;

	// updating the LCM of data frequencies

	float a = data_frequency_lcm ;
	float b = data->getFrequency() ;

    while( a != b) {
    	if (a>b)
    		b= data->getFrequency() +b ;
    	else
    		a= data_frequency_lcm +a ;
    }

    setData_frequency_lcm (a) ;
}

/*
 *
 */
  void Sensor::deleteData (short id) {
		SimpleList<Data*>::iterator i  ;
		for ( i = dataList.begin(); i != dataList.end(); i++ ) {
		 if ( (*i)->getId() == id ){
			 dataList.erase(i) ;
			 (*i)->~Data();
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

/**
 */
void Sensor::setData_frequency_lcm (float new_var)   {
    data_frequency_lcm = new_var;
}

/**
 */
float Sensor::getData_frequency_lcm ()   {
  return data_frequency_lcm;
}

void Sensor::getInfos () {
	Serial.println("");
	Serial.print("Sensor id : ");
	Serial.print(id);
	Serial.println("pin: ");
	Serial.print(pin);
	Serial.println("classe: ");
	Serial.print(classe);
	Serial.println("state: ");
	Serial.print(state);
	Serial.println("frequency: ");
	Serial.print(data_frequency_lcm);	
}


void Sensor::enableAutoSend (short data_id)
{
	SimpleList<Data*>::iterator i  ;
	for ( i = dataList.begin(); i != dataList.end(); i++ ) {
		 if ( (*i)->getId() == data_id )
			 (*i)->enableDataAutoSend () ;
	}
}

/**
 */
void Sensor::disableAutoSend (short data_id){ 

	SimpleList<Data*>::iterator i  ;
	for ( i = dataList.begin(); i != dataList.end(); i++ ) {
		 if ( (*i)->getId() == data_id )
			 (*i)->disableDataAutoSend () ;
	}
}
