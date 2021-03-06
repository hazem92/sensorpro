 /*
  Sensor.h : this class calculate the necessary frequency to call update function of all data
  	  
  
  SensorPro.h - Library for sensors management .
  Created by Hazem Amara, Telecom Bretagne, Feb. 2015.

*/

#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"
#include "SimpleList.h"
#include "Alert.h"
#include "Data.h"

typedef SimpleList<Data*> DataList;
#define UNDEFINED -1
#define UNDEFINED_PERIODE 0

class Sensor
{

public:

  Sensor ();
  Sensor (short id, string pin, int classe ) ;


  virtual ~Sensor ();

  /**
   */
  void enableSensor () ; 
  
  /**
   */
  void disableSensor () ;
  
  /**
   * Get the value of state
   * @return the value of state
   */
  bool getState () ;

  /**
   * @return Data
   * @param  data_id
   */
  Data findDataById (short data_id);
  
  /**
   */


  int getPGCD(int a, int b);
  int getPPCM(int a, int b);

  DataList listData () ;
  void listAssociateData();
  /**
   */
  void updateData () ;

  /*add new data associated to this Sensor, if you want that the library creates automatically a DataConfig
   * associated to the data choose save = true
   *
   */
  /* BACKUP
  Data addData(Data *data) ;
 FIN BACK UP*/

  Data addData(Data* data) ;

/*
 */
  void deleteData (short id) ;

  /**
   * Get the value of id
   * @return the value of id
   */
  short getId ()  ; 

  /**
   * Set the value of pin
   * @param new_var the new value of pin
   */
  void setPin (string new_var)  ; 

  /**
   * Get the value of pin
   * @return the value of pin
   */
  string getPin () ;  

  /**
   * Set the value of class
   * @param new_var the new value of class
   */
  void setClass (int new_var) ;  

  /**
   * Get the value of class
   * @return the value of class
   */
  int getClass () ;  

  /**
   * Set the value of data_frequency_lcm
   * @param new_var the new value of data_frequency_lcm
   */
  //void setData_frequency_lcm (float new_var) ;
  void setData_periodicity_lcm (int var);



  /**
   * Get the value of data_frequency_lcm
   * @return the value of data_frequency_lcm
   */
 // float getData_frequency_lcm () ;

  int getData_periodicity_lcm();

  void getInfos () ;

 /**
   * @param  data_id
   * @param  sensor_id
   */
  void enableAutoSend (short data_id); 

  /**
   * @param  data_id
   * @param  sensor_id
   */
  void disableAutoSend (short data_id) ;
   
private :

  short id;
  string pin;
  bool state;
  int classe;
  //float data_frequency_lcm;
  int data_periodicity_lcm;
  DataList dataList ;

};

#endif // SENSOR_H
