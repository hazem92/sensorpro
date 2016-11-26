#include "Alert.h"
#include "EEPROM.h"
Alert::Alert () {
}

Alert::Alert (short id, comparator condition,float value,float activeTime,bool save) {
	setId (id,save) ;
	setCondition (condition,save) ;
	setValue(value,save) ;
	setActiveTime(activeTime);
	this->lastTimeStamp =0;
	this->checkedOnce = false;


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
 */
bool Alert::checkAlert (float value) {
	bool result = false ;
	switch(condition) {
	case INF : result = (value < this->value) ;  break ;
	case SUP : result = (value > this->value)  ;break ;
	case EGL : result = (value == this->value) ; break ;
	case IEGL : result = (value <= this->value) ; break ;
	case SEGL : result = (value >= this->value) ; break ;
	}



	if (result == true ){
		if (activeTime == 0){
			this->sendAlert() ;
		}

		if(activeTime == -1 && checkedOnce == false){
			this->sendAlert();
			checkedOnce = true;

		}

		if(activeTime > 0){
			if (millis() - lastTimeStamp > activeTime*1000 || lastTimeStamp ==0 ){
				this->sendAlert();
				this->lastTimeStamp=millis();
			}
		}
	}

	if(result == false and checkedOnce == true){
		checkedOnce = false;
	} //gestion du


	return result;
}



/*
 */
void Alert::sendAlert () {
	Serial.println("");
	Serial.print("alert id : ") ;
	Serial.println(this->id) ;
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
	 this->value = new_var;

	 if (save == true)
		 EEPROM.write(adress+6,id) ;
 }

 /**
  */
 float Alert::getValue ()   {
	 return value;
 }



 void Alert::setActiveTime(float t){
	 this->activeTime = t;
 }


 /*
  */
 void Alert::getInfos () {
	 Serial.println("");
	 Serial.print("Alert id : ");
	 Serial.println(id);
	 Serial.print("value : ");
	 Serial.println(value);
	 Serial.print("comparator : ");
	 Serial.println(condition);

 }



