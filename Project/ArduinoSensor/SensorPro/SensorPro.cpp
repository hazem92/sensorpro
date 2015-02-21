#include "SensorPro.h"

// Constructors/Destructors
//  

SensorPro::SensorPro () {}

SensorPro::~SensorPro () { }


/**
 */
void SensorPro::setSensor_frequency_lcm (float new_var)   {
    sensor_frequency_lcm = new_var;
}

/**
 */
float SensorPro::getSensor_frequency_lcm ()   {
  return sensor_frequency_lcm;
}


/**
 */
Sensor SensorPro::addSensor (Sensor *p,short id, string pin, int classe)
{
	//Nom_de_la_classe * Nom_du_pointeur;
	//Nom_du_pointeur = new Nom_de_la_classe;

	p = new Sensor (id,pin,classe) ;
	sensorList.push_back(p) ;


}


/**
 */
void SensorPro::deleteSensor (short sensor_id)
{
	std::list<Sensor*>::iterator i  ;
	for ( i = sensorList.begin(); i != sensorList.end(); i++ ) {
		 if ( (*i)->getId() == sensor_id )
			 sensorList.erase(i) ;
	}

	// delete (*sensor_id) ;
}


/**
 */
void SensorPro::listSensors ()
{
	std::list<Sensor*>::iterator i  ;
		for ( i = sensorList.begin(); i != sensorList.end(); i++ ) {
			(*i)->getInfos() ;
		}
}


/**
 * @param  sensor_id
 */
void SensorPro::activateSensor (short sensor_id) {
	Sensor sensor ;
	sensor = findSensorById(sensor_id) ;
	sensor.enableSensor() ;
}

/**
 * @param  sensor_id
 */
void SensorPro::desactivateSensor (short sensor_id) {
	Sensor sensor ;
		sensor = findSensorById(sensor_id) ;
		sensor.disableSensor() ;
}


/**
 */
bool SensorPro::checkStateSensor (short sensor_id) {
	Sensor sensor ;
			sensor = findSensorById(sensor_id) ;
			sensor.getState();
}


/**
 */
void SensorPro::changeAlertValue (short alert_id, float value) {

}


/**
 */
void SensorPro::deleteAlert (short alert_id)
{
}


/**
 */
void SensorPro::listAlert ()
{
}


/**
 */
void SensorPro::activateAlert (short alert_id)
{
}


/**
 */
void SensorPro::desactivateAlert (short alert_id)
{
}


/**
 */
bool SensorPro::checkStateAlert (short alert_id)
{
}


/**
 */
void SensorPro::deleteData (short data_id)
{
}


/**
 */
void SensorPro::listDataBySensor (short sensor_id)
{
}


/**
 */
void SensorPro::activateAutoSend (short data_id, short sensor_id)
{
}


/**
 */
void SensorPro::desactivateAutoSend (short data_id, short sensor_id)
{
}


/**
 */
float SensorPro::dataMinMeasured (short sensor_id, short data_id)
{
}


/**
 */
float SensorPro::dataMaxMeasured (short sensor_id, short data_id)
{
}


/**
 */
void SensorPro::resetDataMinMeasured (short sensor_id, short data_id)
{
}


/**
 */
void SensorPro::resetDataMaxMeasured (short sensor_id, short data_id)
{
}


/**
 */
void SensorPro::setDataPrecision (short sensor_id, short data_id, int precision)
{
}


/**
 */
void SensorPro::setDataStep (short sensor_id, short data_id, float step)
{
}


/**
 */
void SensorPro::setAllowedMinDataValue (short sensor_id, short data_id, float minAllowed)
{
}


/**
 */
void SensorPro::setDataSendFrequency (short sensor_id, short data_id, float frequency)
{
}


/**
 */
Sensor SensorPro::findSensorById (short sensor_id){
	std::list<Sensor*>::iterator i  ;
	Sensor sensor = NULL  ;
	for ( i = sensorList.begin(); i != sensorList.end(); i++ ) {
		 if ( (*i)->getId() == sensor_id )
			 sensor = (*i) ;
	}
}

/*
 *
 */
Sensor SensorPro::findAlertById (short sensor_id) {
	std::list<Alert*>::iterator i  ;
		Alert alert = NULL  ;
		for ( i = alertList.begin(); i != alertList.end(); i++ ) {
			 if ( (*i)->getId() == sensor_id )
				 alert = (*i) ;
		}
 }


/**
 */
void SensorPro::setAllowedMaxDataValue (short sensor_id, short data_id, float max_allowed)
{
}


/**
 */
void SensorPro::update ()
{
}


/**
 */
void SensorPro::getSensorFrequencyLcm ()
{
}


/**
 */
void SensorPro::setSensorFrequencyLcm ()
{
}


