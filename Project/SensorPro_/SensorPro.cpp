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




/*
 *
 */
Sensor SensorPro::addSensor (Sensor *sensor)
{
	
	if(sensor!=NULL)
		sensorList.push_back(sensor) ;
}


/**
 */
void SensorPro::deleteSensor (short sensor_id)
{
	SimpleList<Sensor*>::iterator i  ;
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
	SimpleList<Sensor*>::iterator i  ;
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

/*
 *
 */
Sensor SensorPro::addAlert (Alert *alert)
{
	if(alert!=NULL)
		alertList.push_back(alert) ;
}


/**
 */
void SensorPro::changeAlertValue (short alert_id, float value, bool save) {
	Alert alert ;
	alert = findAlertById(alert_id) ;
	alert.setValue(value,save) ;
}


/**
 */
void SensorPro::deleteAlert (short alert_id) {
	SimpleList<Alert*>::iterator i  ;
		for ( i = alertList.begin(); i != alertList.end(); i++ ) {
		 if ( (*i)->getId() == alert_id )
			 alertList.erase(i) ;
	}
}


/**
 */
void SensorPro::listAlert () {
	SimpleList<Alert*>::iterator i  ;
	for ( i = alertList.begin(); i != alertList.end(); i++ ) {
		(*i)->getInfos() ;
	}
}


/**
 */
void SensorPro::activateAlert (short alert_id) {
	Alert alert = findAlertById(alert_id) ;
	alert.enableAlert() ;
}


/**
 */
void SensorPro::desactivateAlert (short alert_id) {
	Alert alert = findAlertById(alert_id) ;
		alert.disableAlert() ;
}


/**
 */
bool SensorPro::checkStateAlert (short alert_id) {
	Alert alert = findAlertById(alert_id) ;
			alert.getState();
}


/*
 *
 */
Sensor SensorPro::addData (Data *data)
{
	if(data!=NULL)
		dataList.push_back(data) ;
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
void SensorPro::setAllowedMaxDataValue (short sensor_id, short data_id, float max_allowed)
{
}

/**
 */
Sensor SensorPro::findSensorById (short sensor_id){
	SimpleList<Sensor*>::iterator i  ;
	Sensor * sensor ;
	sensor = new Sensor() ;
	sensor = NULL ;
	for ( i = sensorList.begin(); i != sensorList.end(); i++ ) {
		 if ( (*i)->getId() == sensor_id )
			 sensor = (*i) ;
	}
	return *sensor ;
}

/*
 *
 */
Alert SensorPro::findAlertById (short alert_id) {
	SimpleList<Alert*>::iterator i  ;
	Alert * alert ;
	alert = new Alert() ;
	alert = NULL ;
	for ( i = alertList.begin(); i != alertList.end(); i++ ) {
		 if ( (*i)->getId() == alert_id )
			 alert = (*i) ;
	}
	return *alert ;	
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


