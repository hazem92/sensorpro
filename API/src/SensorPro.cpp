#include "SensorPro.h"



SensorPro::SensorPro () {
	this->sensorList = SimpleList<Sensor*>();
	this->periode = UNDEFINED_PERIOD;
	this->sensor_periodicity_lcm = UNDEFINED_PERIOD;
}

SensorPro::~SensorPro () { }


void SensorPro::setSensor_periodicity_lcm(int t){
	sensor_periodicity_lcm = t;
}

int SensorPro::getSensor_periodicity_lcm(){
	return sensor_periodicity_lcm;
}
/*
 */
Sensor SensorPro::addSensor (Sensor *sensor)
{
	if(sensor==NULL)
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
	int a = sensor_periodicity_lcm;
	if( a == UNDEFINED_PERIODE ) // if no data added to sensor yet
	{
		a = sensor->getData_periodicity_lcm();
	}
	int b = sensor->getData_periodicity_lcm();
	int r(0);
	while(b!=0){
		r = a%b;
		a = b;
		b = r;
	}
	this->setSensor_periodicity_lcm(a);

	return *sensor ;
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
	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {
		if((*i)->getId() == sensor_id){
			(*i)->enableSensor();
		}
	}


}

/**
 * @param  sensor_id
 */
void SensorPro::desactivateSensor (short sensor_id) {

	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {
		if((*i)->getId() == sensor_id){
			(*i)->disableSensor();
		}
	}

}

/**
 */
bool SensorPro::checkStateSensor (short sensor_id_) {
	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {
		if((*i)->getId() == sensor_id_){
			return (*i)->getState();
		}
	}

}



void SensorPro::changeAlertValue (short alert_id, float value, bool save) {

	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {
		SimpleList<Data*> dataList = (*i)->listData();
		for ( SimpleList<Data*>::iterator k  = dataList.begin(); k != dataList.end(); k++ ) {
			SimpleList<Alert*> alertList = (*k)->getListAlerts();
			for ( SimpleList<Alert*>::iterator m  = alertList.begin(); m != alertList.end(); m++ ) {
				if((*m)->getId() == alert_id){
					(*m)->setValue(value,save);
				}
			}
		}
	}
}



void SensorPro::deleteAlert (short alert_id) {

	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {
		SimpleList<Data*> dataList = (*i)->listData();
		for ( SimpleList<Data*>::iterator k  = dataList.begin(); k != dataList.end(); k++ ) {
			SimpleList<Alert*> alertList = (*k)->getListAlerts();
			for ( SimpleList<Alert*>::iterator m  = alertList.begin(); m != alertList.end(); m++ ) {
				if((*m)->getId() == alert_id){
					alertList.erase(m);
				}


			}
		}
	}
}




void SensorPro::listAlert(){
	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {
		//(*i)->getInfos();

		SimpleList<Data*> dataList = (*i)->listData();

		for ( SimpleList<Data*>::iterator k  = dataList.begin(); k != dataList.end(); k++ ) {
			(*k)->listAssociateAlerts();

		}
	}
}




void SensorPro::activateAlert (short alert_id) {

	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {
		SimpleList<Data*> dataList = (*i)->listData();
		for ( SimpleList<Data*>::iterator k  = dataList.begin(); k != dataList.end(); k++ ) {
			SimpleList<Alert*> alertList = (*k)->getListAlerts();
			for ( SimpleList<Alert*>::iterator m  = alertList.begin(); m != alertList.end(); m++ ) {
				if((*m)->getId() == alert_id){
					(*m)->enableAlert();
				}
			}
		}
	}
}





void SensorPro::desactivateAlert (short alert_id) {
	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {

		SimpleList<Data*> dataList = (*i)->listData();
		for ( SimpleList<Data*>::iterator k  = dataList.begin(); k != dataList.end(); k++ ) {

			SimpleList<Alert*> alertList = (*k)->getListAlerts();
			for ( SimpleList<Alert*>::iterator m  = alertList.begin(); m != alertList.end(); m++ ) {

				if((*m)->getId() == alert_id){
					(*m)->disableAlert();
				}
			}
		}
	}
}





bool SensorPro::checkStateAlert(short alert_id){

	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {
		SimpleList<Data*> dataList = (*i)->listData();
		for ( SimpleList<Data*>::iterator k  = dataList.begin(); k != dataList.end(); k++ ) {
			SimpleList<Alert*> alertList = (*k)->getListAlerts();
			for ( SimpleList<Alert*>::iterator m  = alertList.begin(); m != alertList.end(); m++ ) {
				if((*m)->getId() == alert_id){
					return (*m)->getState();
				}
			}
		}
	}

}






Data SensorPro::addData(Data* data, short id_sensor){
	if(data == NULL)
		return *data;

	SimpleList<Data*> dataList = findSensorById(id_sensor).listData();
	SimpleList<Data*>::iterator i  ;
	for ( i = dataList.begin(); i != dataList.end(); i++ ) {
		if ( (*i)->getId() == data->getId() ) {
			return *(*i);
		}

	}

	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {
		if((*i)->getId() == id_sensor){
			(*i)->addData(data);
		}
	}

}



void SensorPro::deleteData (short sensor_id ,short data_id){

	Serial.print("je vais deleter");

	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {
		if((*i)->getId() == sensor_id){

			Serial.print((*i)->getId());
			(*i)->deleteData(data_id);





		}

	}


}



DataList SensorPro::listDataBySensor (short sensor_id)
{
	Sensor sensor = findSensorById(sensor_id) ;
	return sensor.listData () ;

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
void SensorPro::setDataSendPeriode (short sensor_id, short data_id, int periode)
{
	Sensor sensor = findSensorById(sensor_id) ;
	Data data = sensor.findDataById (data_id) ;
	//data.setFrequency (frequency) ;
	data.setPeriode(periode);
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

	Sensor* sensor ;

	for (SimpleList<Sensor*>::iterator i = sensorList.begin(); i != sensorList.end(); i++ ) {
		if ( (*i)->getId() == sensor_id ){
			sensor = (*i) ;

		}
	}
	return *sensor ;
}





Alert SensorPro::findAlertById (short alert_id) {
	Alert* alert;
	for ( SimpleList<Sensor*>::iterator i  = sensorList.begin(); i != sensorList.end(); i++ ) {
		SimpleList<Data*> dataList = (*i)->listData();
		for ( SimpleList<Data*>::iterator k  = dataList.begin(); k != dataList.end(); k++ ) {
			SimpleList<Alert*> alertList = (*k)->getListAlerts();
			for ( SimpleList<Alert*>::iterator m  = alertList.begin(); m != alertList.end(); m++ ) {
				if((*m)->getId() == alert_id){

					alert = (*m) ;

				}
			}
		}
	}
	return *alert;
}



void SensorPro::update (){
	Serial.print("Début ------------------------------------------------------------\n");
	long timeStamp_ = millis() ;


	SimpleList<Sensor*>::iterator i  ;
	for ( i = sensorList.begin(); i != sensorList.end(); i++ ) {
		(*i)->updateData();
	}
	long timeStamp = millis() - timeStamp_ ;

	long delayTime = sensor_periodicity_lcm - timeStamp;
	Serial.print(delayTime);
	delay(delayTime);
	Serial.print("Fin------------------------------------------------------------\n");

}


