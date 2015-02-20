
#ifndef SENSORPRO_H
#define SENSORPRO_H

#include "Arduino.h"
#include "SimpleList.h"
#include "Alert.h"
#include "Data.h"
#include "Sensor.h"
#include "DataConfig.h"

typedef SimpleList<Sensor*> SensorList;
typedef SimpleList<Alert*>  AlertList;
typedef SimpleList<Data*>  dataList;
typedef SimpleList<DataConfig*>  dataConfigList;






/**
  * class SensorPro
  * 
  */

class SensorPro
{
public:

  SensorPro ();

  virtual ~SensorPro ();

  /**
   * Set the value of sensor_frequency_lcm
   * @param new_var the new value of sensor_frequency_lcm
   */
  void setSensor_frequency_lcm (float new_var) ;  

  /**
   * Get the value of sensor_frequency_lcm
   * @return the value of sensor_frequency_lcm
   */
  float getSensor_frequency_lcm () ;  


  /*
   *
   */
  Sensor addSensor (Sensor *sensor) ;

  /**
   * @param  sensor_id
   */
  void deleteSensor (short sensor_id) ;
  
  


  /**
   */
  void listSensors () ;
  
  


  /**
   * @param  sensor_id
   */
  void activateSensor (short sensor_id) ;
  
  


  /**
   * @param  sensor_id
   */
  void desactivateSensor (short sensor_id) ;
  
  


  /**
   * @return bool
   * @param  sensor_id
   */
  bool checkStateSensor (short sensor_id) ;
  
  

/*
 *
 */
  Sensor addAlert (Alert *alert);


  /**
   * Choose save = true if you want to change and save the value in the EEPROM
   * @param  alert_id
   * @param  value
   */
  void changeAlertValue (short alert_id, float value,bool save) ;
  
  


  /**
   * @param  alert_id
   */
  void deleteAlert (short alert_id) ;
  
  


  /**
   */
  void listAlert () ;
  
  


  /**
   * @param  alert_id
   */
  void activateAlert (short alert_id) ;
  
  


  /**
   * @param  alert_id
   */
  void desactivateAlert (short alert_id) ;
  
  


  /**
   * @return bool
   * @param  alert_id
   */
  bool checkStateAlert (short alert_id) ;
  
  

  /*
   *
   */
  Sensor addData (Data *data); 

  /**
   * @param  data_id
   */

  void deleteData (short data_id) ; 
  
  


  /**
   * @param  sensor_id
   */
  void listDataBySensor (short sensor_id); 
  
  


  /**
   * @param  data_id
   * @param  sensor_id
   */
  void activateAutoSend (short data_id, short sensor_id); 
  
  


  /**
   * @param  data_id
   * @param  sensor_id
   */
  void desactivateAutoSend (short data_id, short sensor_id) ;
   
  

  /**
   * @return float
   * @param  sensor_id
   * @param  data_id
   */
  float dataMinMeasured (short sensor_id, short data_id) ;
  
  


  /**
   * @return float
   * @param  sensor_id
   * @param  data_id
   */
  float dataMaxMeasured (short sensor_id, short data_id) ;
  
  


  /**
   * @param  sensor_id
   * @param  data_id
   */
  void resetDataMinMeasured (short sensor_id, short data_id) ;
  
  


  /**
   * @param  sensor_id
   * @param  data_id
   */
  void resetDataMaxMeasured (short sensor_id, short data_id) ;
  
  


  /**
   * @param  sensor_id
   * @param  data_id
   * @param  precision
   */
  void setDataPrecision (short sensor_id, short data_id, int precision) ;
  
  


  /**
   * @param  sensor_id
   * @param  data_id
   * @param  step
   */
  void setDataStep (short sensor_id, short data_id, float step) ;
  
  

  /**
   * @param  sensor_id
   * @param  data_id
   * @param  minAllowed
   */
  void setAllowedMinDataValue (short sensor_id, short data_id, float minAllowed) ;
  
  


  /**
   * @param  sensor_id
   * @param  data_id
   * @param  frequency
   */
  void setDataSendFrequency (short sensor_id, short data_id, float frequency) ;
  
  

  /**
   * @param  sensor_id
   * @param  data_id
   * @param  max_allowed
   */
  void setAllowedMaxDataValue (short sensor_id, short data_id, float max_allowed) ;
  
  

  /**
   * @return Sensor
   * @param  sensor_id
   */
  Sensor findSensorById (short sensor_id) ;
  
  

  /**
    * @return Sensor
    * @param  sensor_id
    */
   Alert findAlertById (short alert_id) ;
   
   

  /**
   */
  void update () ;
  
  


  /**
   */
  void getSensorFrequencyLcm () ;
  
  


  /**
   */
  void setSensorFrequencyLcm () ; 
 
 


private:

  float sensor_frequency_lcm;
  SensorList sensorList ;
  AlertList alertList ;
  DataList dataList ;


};

#endif // SENSORPRO_H
