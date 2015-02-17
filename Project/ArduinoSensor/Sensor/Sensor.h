
#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
using namespace std;
#include <string>
#include <list>
using std::string ;
using std::list ;

typedef list<Data*> DataList;



/**
  * class Sensor
  * 
  */

class Sensor
{
public:


  Sensor ();
  Sensor (short id, string pin, int classe) ;


  virtual ~Sensor ();

  /**
   */
  void enableSensor ()
  {
  }


  /**
   */
  void disableSensor ()
  {
  }

  /**
   * Get the value of state
   * @return the value of state
   */
  bool getState ()   {}

  /**
   * @return Data
   * @param  data_id
   */
  Data findDataById (short data_id)
  {
  }


  /**
   */
  DataList listData ()
  {
  }


  /**
   */
  void updateData ()
  {
  }

  /*add new data associated to this Sensor, if you want that the library creates automatically a DataConfig
   * associated to the data choose save = true
   *
   */
  void addData(short id, string type, short sensor_id,int precision, float step,
 		  float frequency,float min_allowed,float max_allowed,bool save) {}

/*
 *
 */
  void deleteData (short id) {}


  /**
   * Get the value of id
   * @return the value of id
   */
  short getId ()   {}

  /**
   * Set the value of pin
   * @param new_var the new value of pin
   */
  void setPin (string new_var)   {}

  /**
   * Get the value of pin
   * @return the value of pin
   */
  string getPin ()   {}

  /**
   * Set the value of class
   * @param new_var the new value of class
   */
  void setClass (int new_var)   {}

  /**
   * Get the value of class
   * @return the value of class
   */
  int getClass ()   {}

  /**
   * Set the value of data_frequency_lcm
   * @param new_var the new value of data_frequency_lcm
   */
  void setData_frequency_lcm (float new_var)   {}

  /**
   * Get the value of data_frequency_lcm
   * @return the value of data_frequency_lcm
   */
  float getData_frequency_lcm ()   { }

  string getInfos () {}



public :

  short id;
  string pin;
  bool state;
  int classe;
  float data_frequency_lcm;
  DataList dataList ;

};

#endif // SENSOR_H
