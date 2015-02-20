#include "Sensor.h"

// Constructors/Destructors
//  

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
 *
 */

void Sensor::addData(short id, string type, short sensor_id,int precision, float step,
		  float frequency,float min_allowed,float max_allowed,bool save,PtrFonct pf) {

	Data * data ;
	data = new Data ( id,type,sensor_id,precision,step,frequency,min_allowed,max_allowed,save,pf) ;

	this->dataList.push_back(data) ;

	// updating the LCM of data frequencies

	float a = data_frequency_lcm ;
	float b = frequency ;

    while( a != b) {
    	if (a>b)
    		b= frequency +b ;
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
void Sensor::setPin (string new_var)   {
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

string Sensor::getInfos () {

}

