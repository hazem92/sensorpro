
#ifndef DATACONFIG_H
#define DATACONFIG_H

#include "Arduino.h"




/**
  * class DataConfig
  * 
  */

class DataConfig
{
public:

	  DataConfig ();
	  DataConfig (short id, int precision, float step,
	  		float frequency, float min_allowed, float max_allowed,bool save) ;

  virtual ~DataConfig ();

  /**
     * Set the value of id
     * @param new_var the new value of id
     */
    void setId (short new_var,bool save)   {}

    /**
     * Get the value of id
     * @return the value of id
     */
    short getId ()   {}

    /**
     * Set the value of precision
     * @param new_var the new value of precision
     */
    void setPrecision (int new_var,bool save)   {}

    /**
     * Get the value of precision
     * @return the value of precision
     */
    int getPrecision ()   {}

    /**
     * Set the value of step
     * @param new_var the new value of step
     */
    void setStep (float new_var,bool save)   {}

    /**
     * Get the value of step
     * @return the value of step
     */
    float getStep ()   {}

    /**
     * Set the value of frequency
     * @param new_var the new value of frequency
     */
    void setFrequency (float new_var,bool save)  {}

    /**
     * Get the value of frequency
     * @return the value of frequency
     */
    float getFrequency ()   {}

    /**
     * Set the value of min_allowed
     * @param new_var the new value of min_allowed
     */
    void setMin_allowed (float new_var,bool save)  {}

    /**
     * Get the value of min_allowed
     * @return the value of min_allowed
     */
    float getMin_allowed ()  {}

    /**
     * Set the value of max_allowed
     * @param new_var the new value of max_allowed
     */
    void setMax_allowed (float new_var,bool save)  {}

    /**
     * Get the value of max_allowed
     * @return the value of max_allowed
     */
    float getMax_allowed ()   {}


private:

  short id;
  int precision;
  float step;
  float frequency;
  float min_allowed;
  float max_allowed;
  int adress ;



};

#endif // DATACONFIG_H
