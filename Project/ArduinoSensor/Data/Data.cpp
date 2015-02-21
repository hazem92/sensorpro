#include "Data.h"


Data::Data () {}

Data::Data ( short id, string type, short sensor_id,int precision, float step,
		  float frequency,float min_allowed,float max_allowed,bool save) {
	this->id = id ;
	this->type = type ;
	this->sensor_id = sensor_id ;
	this->precision = precision ;
	this->step = step ;
	this->frequency = frequency ;
	this->min_allowed = min_allowed ;
	this->max_allowed = max_allowed ;
	this->send_auto = true ;
	this->alertList = NULL ;

	if (save == true ) {
		DataConfig * data ;
		// DataConfig id ???
		data = new DataConfig ( id,  precision,  step,
		  		 frequency,  min_allowed,  max_allowed,true) ;
		dataConfig = (*data) ;
	}

}

Data::~Data () { }

void Data::enableDataAutoSend ()
{
	send_auto = true ;
}

/**
 * @return float
 */
float Data::calculate ()
{
}

/**
 */
void Data::checkAlerts ()
{
	std::list<Alert*>::iterator i  ;
			Alert alert = NULL  ;
			float value = this->getValue() ;
		for ( i = alertList.begin(); i != alertList.end(); i++ ) {
			 if ( (*i)->checkAlert(value) )
				 (*i)->sendAlert() ;
		}
}

/*
 *
 */
void Data::update() {
	/*
	// respecter la fréquence imposée pour le rafraichissement des données
		// cycle est multiple de frequency (ppcm)
		cycle = cycle - frequency ;
		if ( cycle == 0 )
			cycle = SensorPro.getSensorFrequencyLcm() ;
		else
			break ;
	*/
		float tmp = calculate() ;
		if (value == tmp )
		// Si la valeur n'est pas changée il est inutile de continuer
			break ;
		else
			value = tmp ;

		// la valeur de value doit respecter la plage des valeures permises
		if (value > max_allowed )
			value = max_allowed ;
		else if (value < min_allowed )
			value = min_allowed ;

		// envoyer la donnée s'il y a un chgt sup au pas
		if (( abs(value-lastSentValue) > step ) and (send_auto ==true))
			sendValue() ;

		// mettre à jour les min et max mesurés
		if (value > max_measure )
			value = max_measure ;
		else if (value < min_measure )
			value = min_measure ;

		// vérifier les alertes
		checkAlerts() ;

}

/*
 *
 */  Alert Data::findAlertById (short id) {

		std::list<Alert*>::iterator i  ;
		Alert alert = NULL  ;
	for ( i = alertList.begin(); i != alertList.end(); i++ ) {
		 if ( (*i)->getId() == id )
			 alert = (*i) ;
	}
  }

/**
 */
void Data::listAssociateAlerts ()
{
	std::list<Alert*>::iterator i  ;
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
	std::list<Alert*>::iterator i  ;
for ( i = alertList.begin(); i != alertList.end(); i++ ) {
	 if ( (*i)->getId() == id )
		 alertList.erase(i) ;
}

}

/**
 */
void Data::addAssociateAlert (short id)
{
	Alert *alert = findAlertById (id) ;
	alertList.push_back (alert) ;
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
  void Data::setType (string new_var)   {
      type = new_var;
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
      max_measure = new_var;
  }

  /**
   */
  float Data::getMax_measure ()   {
    return max_measure;
  }

  /**
   */
  void Data::setPrecision (int new_var)   {
      precision = new_var;
  }

  /**
   */
  int Data::getPrecision ()   {
    return precision;
  }

  /**
   */
  void Data::setStep (float new_var)   {
      step = new_var;
  }

  /**
   */
  float Data::getStep ()   {
    return step;
  }

  /**
   */
  void Data::setFrequency (float new_var)   {
      frequency = new_var;
  }

  /**
   */
  float Data::getFrequency ()   {
    return frequency;
  }

  /**
   */
  void Data::setMin_allowed (float new_var)   {
      min_allowed = new_var;
  }

  /**
   */
  float Data::getMin_allowed ()   {
    return min_allowed;
  }

  /**
   */
  void Data::setMax_allowed (float new_var)   {
      max_allowed = new_var;
  }

  /**
   */
  float Data::getMax_allowed ()   {
    return max_allowed;
  }

  /**
   */
  void Data::setValue (float new_var)   {
      value = new_var;
  }

  /**
   */
  float Data::getValue ()   {
    return value;
  }

  /**
   */
  void Data::setLastSentValue (float new_var)   {
      lastSentValue = new_var;
  }

  /**
   */
  float Data::getLastSentValue ()   {
    return lastSentValue;
  }

  /**
   */
  void Data::setCycle (float new_var)   {
      cycle = new_var;
  }

  /**
   */
  float Data::getCycle ()   {
    return cycle;
  }

  void sendValue () {
	  Serial.print("new value ");
	  Serial.print(this->getValue()) ;
	  Serial.print();

  }

  string getInfos () {


  }

