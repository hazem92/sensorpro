 /*
  Alert.h : user can create an alert and specify the condition to start the alert
  Data may be associated to many alerts and alert may be associated to many data
  
  SensorPro.h - Library for sensors management .
  Created by Hazem Amara, Telecom Bretagne, Feb. 2015.

*/

#ifndef ALERT_H
#define ALERT_H

#ifndef NULL
#define NULL 0
#endif
#include "Arduino.h"

typedef enum comparator { INF,
			 SUP,
                         EGL,
			 IEGL,
			 SEGL
		} ;


class Alert
{
public:

  Alert ();
  Alert (short id, comparator condition,float  value,bool save) ;

  virtual ~Alert ();

  /**
   */
  void enableAlert ();
  
  /**
   */
  void disableAlert ();

  /**
   * check if the value passed in parameter verify the condition or not
   * @return boolean
   */
    bool checkAlert (float value);
    
    /*
     *
     */
    void sendAlert () ;

  /**
    * Get the value of state
    * @return the value of state
    */
   bool getState ()   ;

  /**
   * Get the value of id
   * @return the value of id
   */
  short getId ()   ;

  /**
   * Set the value of condition
   * @param new_var the new value of condition
   */
  void setCondition (comparator new_var,bool save)   ;

  /**
    * Set the value of id
    * @param new_var the new value of id
    */
   void setId (short new_var,bool save)   ;

  /**
   * Get the value of condition
   * @return the value of condition
   */
  comparator getCondition ()   ;

  /**
   * Set the value of value
   * @param new_var the new value of value
   */
  void setValue (float new_var,bool save)   ;

  /**
   * Get the value of value
   * @return the value of value
   */
  float getValue ()   ;

  /*
   * Description of the alert
   */
  void getInfos () ;

  short id;
  comparator condition;
  bool state;
  float value;
  int adress ;

};

#endif // ALERT_H
