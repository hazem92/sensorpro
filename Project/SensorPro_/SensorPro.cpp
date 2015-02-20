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
	
	if(sensor=NULL)
		return *sensor;
	// sensor.id can't be already taken
	SimpleList<Sensor*>::iterator i  ;
	for ( i = sensorList.begin(); i != sensorList.end(); i++ ) {
		 if ( (*i)->getId() == sensor->getId() ) {
 			 return *(*i);
		}
	}
	
	// adding new sensor
	sensorList.push_back(sensor) ;
	
	// updating the LCM of sensor frequencies
	float a = sensor_frequency_lcm;
	float b = sensor->getData_frequency_lcm ()  ;

    while( a != b) {
    	if (a>b)
    		b= sensor->getData_frequency_lcm ()  +b ;
    	else
    		a= sensor_frequency_lcm; +a ;
    }
   setSensorFrequencyLcm (a) ;
}



/**
 */
void SensorPro::deleteSensor (short sensor_id)
{
	SimpleList<Sensor*>::iterator i  ;
	for ( i = sensorList.begin(); i != sensorList.end(); i++ ) {
		 if ( (*i)->getId() == sensor_id ) {
 			 sensorList.erase(i) ;
			(*i)->~Sensor();
		}
	}
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
	Sensor sensor = findSensorById(sensor_id) ;
	return sensor.getState() ; 
}

/*
 *
 */
Alert SensorPro::addAlert (Alert *alert)
{
	if(alert=NULL)
		return *alert ;

	// sensor.id can't be already taken
	SimpleList<Alert*>::iterator i  ;
	for ( i = alertList.begin(); i != alertList.end(); i++ ) {
		 if ( (*i)->getId() == alert->getId() ) {
 			 return *(*i);
		}
	}

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
			if ( (*i)->getId() == alert_id ) {
				alertList.erase(i) ;
				(*i)->~Alert();
			}
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
void SensorPro::deleteData (short sensor_id ,short data_id)
{
	Sensor sensor = findSensorById(sensor_id) ;
	sensor.deleteData(data_id) ;	
}


/**
 */
DataList SensorPro::listDataBySensor (short sensor_id)
{
	Sensor sensor = findSensorById(sensor_id) ;
	sensor.listData () ;
}


/**
 */
void SensorPro::enableAutoSend (short data_id, short sensor_id)
{
	Sensor sensor = findSensorById(sensor_id) ;
	sensor.enableAutoSend (data_id) ;
}


/**
 */
void SensorPro::disableAutoSend (short data_id, short sensor_id)
{
	Sensor sensor = findSensorById(sensor_id) ;
	sensor.disableAutoSend (data_id) ;
}


/**
 */
float SensorPro::dataMinMeasured (short sensor_id, short data_id)
{
	Sensor sensor = findSensorById(sensor_id) ;
	Data data = sensor.findDataById (data_id) ;
	return data.getMin_measure () ;
}


/**
 */
float SensorPro::dataMaxMeasured (short sensor_id, short data_id)
{
	Sensor sensor = findSensorById(sensor_id) ;
	Data data = sensor.findDataById (data_id) ;
	return data.getMax_measure () ;
}


/**
 */
void SensorPro::resetDataMinMeasured (short sensor_id, short data_id)
{
	Sensor sensor = findSensorById(sensor_id) ;
	Data data = sensor.findDataById (data_id) ;
	data.setMin_measure (10000) ;
}


/**
 */
void SensorPro::resetDataMaxMeasured (short sensor_id, short data_id)
{
	Sensor sensor = findSensorById(sensor_id) ;
	Data data = sensor.findDataById (data_id) ;
	data.setMax_measure (-10000) ;
}


/**
 */
void SensorPro::setDataPrecision (short sensor_id, short data_id, int precision)
{
	Sensor sensor = findSensorById(sensor_id) ;
	Data data = sensor.findDataById (data_id) ;
	data.setPrecision (precision) ;
}


/**
 */
void SensorPro::setDataStep (short sensor_id, short data_id, float step)
{
	Sensor sensor = findSensorById(sensor_id) ;
	Data data = sensor.findDataById (data_id) ;
	data.setStep (step) ;
}


/**
 */
void SensorPro::setAllowedMinDataValue (short sensor_id, short data_id, float minAllowed)
{
	Sensor sensor = findSensorById(sensor_id) ;
	Data data = sensor.findDataById (data_id) ;
	data.setMin_allowed (minAllowed) ;
}


/**
 */
void SensorPro::setDataSendFrequency (short sensor_id, short data_id, float frequency)
{
	Sensor sensor = findSensorById(sensor_id) ;
	Data data = sensor.findDataById (data_id) ;
	data.setFrequency (frequency) ;
}

/**
 */
void SensorPro::setAllowedMaxDataValue (short sensor_id, short data_id, float max_allowed)
{
	Sensor sensor = findSensorById(sensor_id) ;
	Data data = sensor.findDataById (data_id) ;
	data.setMax_allowed (max_allowed) ;
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
 	long timeStamp = millis() ;
	SimpleList<Sensor*>::iterator i  ;
	for ( i = sensorList.begin(); i != sensorList.end(); i++ ) {
		 (*i)->updateData();
}
	timeStamp = millis() - timeStamp ;
	delay(periode - timeStamp);
}

/**
 */
float SensorPro::getSensorFrequencyLcm ()
{
	return sensor_frequency_lcm ;
}


/**
 */
void SensorPro::setSensorFrequencyLcm (float new_var)
{	
	sensor_frequency_lcm = new_var ;
	periode = 1/ new_var ;
}


