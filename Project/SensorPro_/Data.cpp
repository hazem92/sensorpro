 
#include "Data.h"
//#include "float.h"

Data::Data () {}

Data::Data ( short id, string type, short sensor_id,int precision, float step,
		  float frequency,float min_allowed,float max_allowed,bool save,PtrFonct pf) {

	this->id = id ;
	this->type = type ;
	this->sensor_id = sensor_id ;
	this->setPrecision(precision) ;
	this->step = step ;
	this->setFrequency(frequency);
	this->min_allowed = min_allowed ;
	this->max_allowed = max_allowed ;
	this->send_auto = true ;
	this->alertList = {} ;
	this->nextTimeStamp=millis();
//	this->setMin_measure(FLT_MAX);
//	this->setMax_measure(FLT_MIN);
 	this->setMin_measure(10000);
	this->setMax_measure(-10000);
	this->pf = pf ;


	if (save == true ) {
		DataConfig * data ;
		data = new DataConfig ( id,  precision,  step,
		  		 frequency,  min_allowed,  max_allowed,true) ;
		dataConfig = (*data) ;
	}

	this->update();

}

Data::Data ( short id, string type, short sensor_id,int precision, float step,
		  float frequency,float min_allowed,float max_allowed,bool save) {

	this->id = id ;
	this->type = type ;
	this->sensor_id = sensor_id ;
	this->setPrecision(precision) ;
	this->step = step ;
	this->setFrequency(frequency);
	this->min_allowed = min_allowed ;
	this->max_allowed = max_allowed ;
	this->send_auto = true ;
	this->alertList = {} ;
	this->nextTimeStamp=millis();
//	this->setMin_measure(FLT_MAX);
//	this->setMax_measure(FLT_MIN);
 	this->setMin_measure(10000);
	this->setMax_measure(-10000);
	this->pf = NULL ;


	if (save == true ) {
		DataConfig * data ;
		data = new DataConfig ( id,  precision,  step,
		  		 frequency,  min_allowed,  max_allowed,true) ;
		dataConfig = (*data) ;
	}

	this->update();

}

Data::~Data () {return ; }

void Data::enableDataAutoSend ()
{
	send_auto = true ;
}

/**
 * @return float
 */
 float Data::calculate ()
{		
	float tmp = (*pf)() ;
	return  tmp;
}

/**
 */
	void Data::checkAlerts ()
	{
		SimpleList<Alert*>::iterator i  ;
				float value = this->getValue() ;
			for ( i = alertList.begin(); i != alertList.end(); i++ ) {
				 if ( (*i)->checkAlert(value) )
					 (*i)->sendAlert() ;
			}
	}

/*
 * Les variables "xxtimeStamp" sont utilisées pour déterminer le bon moment
 * de mis à jour de la donnée (selon sa fréquence)
 */
void Data::update() {
		long timeStamp=millis();
		if (timeStamp>=nextTimeStamp|| lastTimeStamp>timeStamp ){
			this->setValue(calculate());
			this->lastTimeStamp=timeStamp;
		}
}

/*
 */  Alert Data::findAlertById (short id) {

		SimpleList<Alert*>::iterator i  ;
		Alert * alert ;
		alert = new Alert() ;
		alert = NULL ;
	for ( i = alertList.begin(); i != alertList.end(); i++ ) {
		 if ( (*i)->getId() == id )
			 alert = (*i) ;
	}
	return *alert ;
  }

/**
 */
void Data::listAssociateAlerts ()
{
	SimpleList<Alert*>::iterator i  ;
			for ( i = alertList.begin(); i != alertList.end(); i++ ) {
				(*i)->getInfos() ;
			}
}
/**
 */
AlertList Data::getListAlerts () {
	return alertList ;
}

/**
 */
void Data::deleteAssociateAlert (short id) {
	SimpleList<Alert*>::iterator i  ;
for ( i = alertList.begin(); i != alertList.end(); i++ ) {
	 if ( (*i)->getId() == id )
		 alertList.erase(i) ;

}
}

/**
 */
void Data::addAssociateAlert (Alert alert)
{
	alertList.push_back (&alert) ;
}

/**
 */
void Data::disableDataAutoSend ()
{
	send_auto = false ;
}

  /**
   */
  short Data::getId ()   {
    return id;
  }

  /**
   */
  string Data::setType (string new_var)   {
      if (new_var != "")
    	  type = new_var;
      return getType() ;
  }

  /**
   */
  string Data::getType ()   {
    return type;
  }

  /**
   */
  bool Data::getSend_auto ()   {
    return send_auto;
  }

  /**
   */
  void Data::setMin_measure (float new_var)   {
	if (new_var < min_measure )
      min_measure = new_var;
  }

  /**
   */
  float Data::getMin_measure ()   {
    return min_measure;
  }

  /**
   */
  void Data::setMax_measure (float new_var)   {
		if (new_var > max_measure )
			max_measure = new_var ;
  }

  /**
   */
  float Data::getMax_measure ()   {
    return max_measure;
  }

  /**
   */
  void Data::setPrecision (int new_var)   {
      precision =  1.0 ;
	for( int i=1; i<new_var ; i++) {
		 precision = precision/10 ;
	}
		
  }

  /**
   */
  int Data::getPrecision ()   {
	float tmp = precision ;
	int precisionInt = 0; 
	while( tmp < 1) {
	tmp= tmp*10 ;
	precisionInt= precisionInt+1 ;
}

    return precisionInt;
  }

  /**
   */
  float Data::setStep (float new_var)   {
	  if (new_var > 0)
		  step = new_var;
	  return getStep() ;
  }

  /**
   */
  float Data::getStep ()   {
    return step;
  }

  /**
   */
  float Data::setFrequency (float frequency)   {
	  if (frequency > 0)
		  periode =1000/frequency;
	  return getFrequency();
  }

  /**
   */
  float Data::getFrequency ()   {
    return (1000.0/periode);
  }

  /**
   */
  float Data::setMin_allowed (float new_var)   {
	  if ((new_var != NULL) && (new_var< getMax_allowed()))
		  min_allowed = new_var;
      return getMin_allowed () ;
  }

  /**
   */
  float Data::getMin_allowed ()   {
    return min_allowed;
  }

  /**
   */
  float Data::setMax_allowed (float new_var)   {
	  if ((new_var != NULL) && (new_var > getMin_allowed()))
		  max_allowed = new_var;
      return getMax_allowed() ;
  }

  /**
   */
  float Data::getMax_allowed ()   {
    return max_allowed;
  }

  /**
   */
  void Data::setValue (float new_value)   {
	       if ( abs(value-new_value) < precision )		
			return;
		
		if (value == new_value )
		// Si la valeur n'est pas changée il est inutile de continuer
			return;
		// la valeur de value doit respecter la plage des valeures permises
		if (new_value> max_allowed )
			new_value = max_allowed ;
		else if (new_value < min_allowed )
			new_value = min_allowed ;

		bool send=send_auto && abs(value-new_value) >= step;
		value = new_value ;
		nextTimeStamp= millis()+periode*1000 ;
		// envoyer la donnée s'il y a un chgt sup au pas
		if (send)
			sendValue() ;
		// mettre à jour les min et max mesurés
		setMax_measure(value);
		setMin_measure(value);
		// vérifier les alertes
		checkAlerts();
  }

  /**
   */
  float Data::getValue ()   {
    return value;
  }

  void Data::sendValue () {
	  if (this->send_auto == false)
		return ;
	  float tmp ;
	  Serial.print("new value on data id : ");
	  tmp = this->getId();
	  Serial.print(tmp) ;
	  Serial.print(" connected to sensor id : ");
	  tmp = this->sensor_id();
	  Serial.print(tmp) ;
	  Serial.print(" value : ");
	  tmp = this->getValue();
	  Serial.print(tmp) ;

  }

  void Data::getInfos () {
	Serial.println("");
	Serial.print("data id : ");
	Serial.print(id);
	Serial.println("type: ");
	Serial.print(type);
	Serial.println("related to sensor: ");
	Serial.print(sensor_id);
	Serial.println("precision: ");
	Serial.print(precision);
	Serial.println("frequency: ");
	Serial.print(1.0/periode);
	Serial.println("min allowed ");
	Serial.print(min_allowed);
	Serial.println("max allowed ");
	Serial.print(max_allowed);
  }

  /*
  * respect the type of the pointer
  */
  void Data::setPointer (PtrFonct new_var)   {
	pf = new_var ;
}

