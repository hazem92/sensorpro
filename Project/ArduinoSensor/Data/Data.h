
#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;
#include <string>
#include <list>
using std::string ;
using std::list ;

typedef list<Alert*> AlertList;
typedef list<DataConfig*> dataConfig;



/**
  * class Data
  * 
  */

class Data
{
public:

  Data ();
  // If you want to create a new DataConfig with these values and save it on the EEPROM choose save = true
  Data ( short id, string type, short sensor_id,int precision, float step,
 		  float frequency,float min_allowed,float max_allowed,bool save);

  virtual ~Data ();

  void enableDataAutoSend ()
  {
  }

  /**
   */
  void disableDataAutoSend ()
  {
  }

  /**
   * user implements this function depending on the sensor he uses
   * the library uses this function to get the value of the data (of a sensor)
   *
   * @return float
   */
  float calculate ()
  {
  }

  /**
   */
  void checkAlerts ()
  {
  }

  /*
   *
   */
  void update () {}
  /*
   *
   */
  Alert findAlertById (short id) {

  }
  /**
   */
  AlertList listAssociateAlerts ()
  {
  }

  /**
   */
  void deleteAssociateAlert (short id)
  {
  }

  /**
   */
  void addAssociateAlert (short id)
  {
  }

  /**
   * Set the value of id
   * @param new_var the new value of id
   */
  void setId (short new_var)   {
      id = new_var;
  }

  /**
   * Get the value of id
   * @return the value of id
   */
  short getId ()   {
  }

  /**
   * Set the value of type
   * @param new_var the new value of type
   */
  void setType (string new_var)   {
  }

  /**
   * Get the value of type
   * @return the value of type
   */
  string getType ()   {
  }

  /**
   * Set the value of sensor_id
   * @param new_var the new value of sensor_id
   */
  void setSensor_id (string new_var)   {
  }

  /**
   * Get the value of sensor_id
   * @return the value of sensor_id
   */
  string getSensor_id ()   {
  }

  /**
   * Set the value of send_auto
   * @param new_var the new value of send_auto
   */
  void setSend_auto (bool new_var)   {
  }

  /**
   * Get the value of send_auto
   * @return the value of send_auto
   */
  bool getSend_auto ()   {
  }

  /**
   * Set the value of min_measure
   * @param new_var the new value of min_measure
   */
  void setMin_measure (float new_var)   {
  }

  /**
   * Get the value of min_measure
   * @return the value of min_measure
   */
  float getMin_measure ()   {
  }

  /**
   * Set the value of max_measure
   * @param new_var the new value of max_measure
   */
  void setMax_measure (float new_var)   {
  }

  /**
   * Get the value of max_measure
   * @return the value of max_measure
   */
  float getMax_measure ()   {
  }

  /**
   * Set the value of precision
   * @param new_var the new value of precision
   */
  void setPrecision (int new_var)   {
  }

  /**
   * Get the value of precision
   * @return the value of precision
   */
  int getPrecision ()   {
  }

  /**
   * Set the value of step
   * @param new_var the new value of step
   */
  void setStep (float new_var)   {
  }

  /**
   * Get the value of step
   * @return the value of step
   */
  float getStep ()   {
  }

  /**
   * Set the value of frequency
   * @param new_var the new value of frequency
   */
  void setFrequency (float new_var)   {
  }

  /**
   * Get the value of frequency
   * @return the value of frequency
   */
  float getFrequency ()   {
  }

  /**
   * Set the value of min_allowed
   * @param new_var the new value of min_allowed
   */
  void setMin_allowed (float new_var)   {
  }

  /**
   * Get the value of min_allowed
   * @return the value of min_allowed
   */
  float getMin_allowed ()   {
  }

  /**
   * Set the value of max_allowed
   * @param new_var the new value of max_allowed
   */
  void setMax_allowed (float new_var)   {
  }

  /**
   * Get the value of max_allowed
   * @return the value of max_allowed
   */
  float getMax_allowed ()   {
  }

  /**
   * Set the value of value
   * @param new_var the new value of value
   */
  void setValue (float new_var)   {
  }

  /**
   * Get the value of value
   * @return the value of value
   */
  float getValue ()   {
  }

  /**
   * Set the value of lastSentValue
   * @param new_var the new value of lastSentValue
   */
  void setLastSentValue (float new_var)   {
  }

  /**
   * Get the value of lastSentValue
   * @return the value of lastSentValue
   */
  float getLastSentValue ()   {
  }

  /**
   * Set the value of cycle
   * @param new_var the new value of cycle
   */
  void setCycle (float new_var)   {
  }

  /**
   * Get the value of cycle
   * @return the value of cycle
   */
  float getCycle ()   {
  }

  void sendValue () {}

  string getInfos () {}


private:

  short id;
  string type;
  short sensor_id;
  bool send_auto;
  float min_measure;
  float max_measure;
  int precision;
  float step;
  float frequency;
  float min_allowed;
  float max_allowed;
  float value;
  float lastSentValue;
  float cycle;
  AlertList alertList ;
  DataConfig dataConfig ;


};

#endif // DATA_H
