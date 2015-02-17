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
Sensor SensorPro::addSensor (short id, string pin, int classe)
{
	//Nom_de_la_classe * Nom_du_pointeur;
	//Nom_du_pointeur = new Nom_de_la_classe;

	Sensor * id;
	id = new Sensor (id,pin,classe) ;


}


/**
 */
void SensorPro::deleteSensor (short sensor_id)
{
	delete (*sensor_id) ;
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
void activateSensor (short sensor_id)
{
}


/**
 * @param  sensor_id
 */
void desactivateSensor (short sensor_id)
{
}


/**
 */
bool checkStateensor (short sensor_id)
{
}


/**
 */
void changeAlertValue (short alert_id, float value)
{
}


/**
 */
void deleteAlert (short alert_id)
{
}


/**
 */
void listAlert ()
{
}


/**
 */
void activateAlert (short alert_id)
{
}


/**
 */
void desactivateAlert (short alert_id)
{
}


/**
 */
bool checkStateAlert (short alert_id)
{
}


/**
 */
void deleteData (short data_id)
{
}


/**
 */
void listDataBySensor (short sensor_id)
{
}


/**
 */
void activateAutoSend (short data_id, short sensor_id)
{
}


/**
 */
void desactivateAutoSend (short data_id, short sensor_id)
{
}


/**
 */
float dataMinMeasured (short sensor_id, short data_id)
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
Sensor SensorPro::findSensorById (short sensor_id)
{
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


