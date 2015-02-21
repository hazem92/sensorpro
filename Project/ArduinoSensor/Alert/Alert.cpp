#include "Alert.h"

// Constructors/Destructors
//  

Alert::Alert () {
}

Alert::Alert (short id, comparator condition,float value,bool save) {
	setId (id,save) ;
	setCondition (condition,save) ;
	setValue(value,save) ;
}


Alert::~Alert () { }


/**
 */
void Alert::enableAlert ()
{
	state = true ;
}

/**
 */
void Alert::disableAlert ()
{
	state = false ;
}


/*
 *
 */
 void Alert::checkAlert (float value) {
	 bool result = false ;

	 switch(condition) {
	 case INF : result = (value < this->value) ; break ;
	 case SUP : result = (value > this->value) ; break ;
	 case EGL : result = (value = this->value) ; break ;
	 case IEGL : result = (value <= this->value) ; break ;
	 case SEGL : result = (value >= this->value) ; break ;

	 }

	 if (result == true )
		 this->sendAlert() ;
 }

 }

 /*
 *
 */
 void Alert::sendAlert () {
	 Serial.print("alert id : ") ;
	 Serial.print(this->id) ;
	 Serial.println();
 }

/**
  */
 bool Alert::getState ()   {
   return state;
 }

/**
 */
short Alert::getId ()   {
  return id;
}

void Alert::setId (short new_var,bool save)   {
      id = new_var;
      if (save == true)
    	  EEPROM.write(adress,id) ;
  }


/**
 */
void Alert::setCondition (comparator new_var,bool save)   {
    condition = new_var;
    if (save == true)
    		EEPROM.write(adress+2,id) ;
}

/**
 */
comparator Alert::getCondition ()   {
  return condition;
}



/**
 */
void Alert::setValue (float new_var,bool save)   {
    value = new_var;
    if (save == true)
    	EEPROM.write(adress+6,id) ;
}

/**
 */
float Alert::getValue ()   {
  return value;
}

/*
 *
 */
void Alert::getInfos () {

}
