
#ifndef DATA_H
#define DATA_H

#ifndef NULL
#define NULL 0
#endif



#include "Arduino.h"
#include <SimpleList.h>
#include "Alert.h"
#include "DataConfig.h"




typedef SimpleList<Alert*> AlertList;
typedef char* string ;
typedef float (*PtrFonct)(void);


//typedef list<DataConfig*> dataConfig;



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
 		  float frequency,float min_allowed,float max_allowed,bool save,PtrFonct pf);

  virtual ~Data ();

  void enableDataAutoSend ();
  
  

  /**
   */
  void disableDataAutoSend ();
  
  

  /**
   * user implements this function depending on the sensor he uses
   * the library uses this function to get the value of the data (of a sensor)
   *
   * @return float
   */
  virtual float calculate ();
  
  

  /**
   */
  void checkAlerts ();
  
  
  /*
   *
   */
  void update () ;
  /*
   *
   */
  Alert findAlertById (short id);
  /**
   */
  void listAssociateAlerts ();
  
  

  /**
   */
  AlertList getListAlerts ();
  
  

  /**
   */
  void deleteAssociateAlert (short id);
  
  

  /**
   */
  void addAssociateAlert (Alert alert);
  
  

  /**
   * Set the value of id
   * @param new_var the new value of id
   */
  void setId (short new_var)   ;

  void setPointer (PtrFonct new_var)   ;

  /**
   * Get the value of id
   * @return the value of id
   */
  short getId ()   ;


  /**
   * Set the value of type
   * @param new_var the new value of type
   */
  string setType (string new_var)   ;
  

  /**
   * Get the value of type
   * @return the value of type
   */
  string getType ()   ;
  

  /**
   * Set the value of sensor_id
   * @param new_var the new value of sensor_id
   */
  void setSensor_id (string new_var)   ;
  

  /**
   * Get the value of sensor_id
   * @return the value of sensor_id
   */
  string getSensor_id ()   ;
  

  /**
   * Set the value of send_auto
   * @param new_var the new value of send_auto
   */
  void setSend_auto (bool new_var)   ;
  

  /**
   * Get the value of send_auto
   * @return the value of send_auto
   */
  bool getSend_auto ()   ;
  

  /**
   * Set the value of min_measure
   * @param new_var the new value of min_measure
   */
  void setMin_measure (float new_var)   ;
  

  /**
   * Get the value of min_measure
   * @return the value of min_measure
   */
  float getMin_measure ()   ;
  

  /**
   * Set the value of max_measure
   * @param new_var the new value of max_measure
   */
  void setMax_measure (float new_var)   ;
  

  /**
   * Get the value of max_measure
   * @return the value of max_measure
   */
  float getMax_measure ()   ;
  
  /**
   * Set the value of precision
   * @param new_var the new value of precision
   */
  void setPrecision (int new_var)  ; 
  

  /**
   * Get the value of precision
   * @return the value of precision
   */
  int getPrecision ()   ;
  

  /**
   * Set the value of step
   * @param new_var the new value of step
   */
  float setStep (float new_var)  ; 
  

  /**
   * Get the value of step
   * @return the value of step
   */
  float getStep ()   ;
  

  /**
   * Set the value of frequency
   * @param new_var the new value of frequency
   */
  float setFrequency (float new_var)   ;
  

  /**
   * Get the value of frequency
   * @return the value of frequency
   */
  float getFrequency ()   ;
  

  /**
   * Set the value of min_allowed
   * @param new_var the new value of min_allowed
   * @return the new value if everything went correctly
   */
  float setMin_allowed (float new_var)   ;
  

  /**
   * Get the value of min_allowed
   * @return the value of min_allowed
   */
  float getMin_allowed ()   ;
  

  /**
   * Set the value of max_allowed
   * @param new_var the new value of max_allowed
   *@return the new value if everything went correctly
   */
  float setMax_allowed (float new_var) ;  
  

  /**
   * Get the value of max_allowed
   * @return the value of max_allowed
   */
  float getMax_allowed ()   ;
  

  /**
   * Set the value of value
   * @param new_var the new value of value
   */
  void setValue (float new_var)   ;

  /**
   * Get the value of value
   * @return the value of value
   */
  float getValue ()   ;
  

  void sendValue () ;

  void getInfos () ;


private:

  short id;
  string type;
  short sensor_id;
  bool send_auto;
  float min_measure;
  float max_measure;
  float precision;
  float step;
  int  periode ;
  float min_allowed;
  float max_allowed;
  float value;
  PtrFonct pf;
  DataConfig dataConfig ;



  AlertList alertList ;
  //DataConfig dataConfig ;
  long nextTimeStamp;
  long lastTimeStamp;


};

#endif // DATA_H
