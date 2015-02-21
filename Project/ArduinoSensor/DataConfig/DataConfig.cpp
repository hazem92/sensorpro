#include "DataConfig.h"


DataConfig::DataConfig () {
}

DataConfig::DataConfig (short id, int precision, float step,
	  		float frequency, float min_allowed, float max_allowed,bool save) {

	setId(id,save) ;
	setPrecision (precision,save) ;
	setStep (step,save) ;
	setFrequency (frequency,save) ;
	setMin_allowed (min_allowed,save) ;
	setMax_allowed (max_allowed,save) ;

}


DataConfig::~DataConfig () { }

/*
 *
 */
void DataConfig::setId (short new_var,bool save)   {
	id = new_var ;
	if (save == true)
		EEPROM.write(adress,id);
}

   /**
    */
   short DataConfig::getId ()   {
     return id;
   }

   /**
    */
   void DataConfig::setPrecision (int new_var,bool save)   {
       precision = new_var;
       if (save == true)
    	   EEPROM.write(adress+2,id);
   }

   /**
    */
   int DataConfig::getPrecision ()   {
     return precision;
   }

   /**
    */
   void DataConfig::setStep (float new_var,bool save)   {
       step = new_var;
       if (save == true)
    	   EEPROM.write(adress+4,id);
   }

   /**
    */
   float DataConfig::getStep ()   {
     return step;
   }

   /**
    */
   void DataConfig::setFrequency (float new_var,bool save)   {
       frequency = new_var;
       if (save == true)
    	   EEPROM.write(adress+8,id);
   }

   /**
    */
   float DataConfig::getFrequency ()   {
     return frequency;
   }

   /**
    */
   void DataConfig::setMin_allowed (float new_var,bool save)   {
       min_allowed = new_var;
       if (save == true)
    	   EEPROM.write(adress+12,id);
   }

   /**
    */
   float DataConfig::getMin_allowed ()   {
     return min_allowed;
   }

   /**
    */
   void DataConfig::setMax_allowed (float new_var,bool save)   {
       max_allowed = new_var;
       if (save == true)
    	   EEPROM.write(adress+16,id);
   }

   /**
    */
   float DataConfig::getMax_allowed ()   {
     return max_allowed;
   }

