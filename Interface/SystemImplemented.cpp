/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "SystemImplemented.h"

#include <string>

using namespace std;


SystemImplemented::SystemImplemented():name(""), value(0.0){} //, actualValue(0.0) {}
SystemImplemented::SystemImplemented(string name, double value): name(name), value(value){}

SystemImplemented::SystemImplemented(System& copy){
	if(this == &copy){}

	else{
		setName(((SystemImplemented)copy).getName());
		setValue(((SystemImplemented)copy).getValue());
	}
}

SystemImplemented::~SystemImplemented(){}

string SystemImplemented::getName(){
	return name;
}

void SystemImplemented::setName(string name){
	this->name = name;
}

double SystemImplemented::getValue(){
	return value;
}

void SystemImplemented::setValue(double initialValue){
	this->value = initialValue;
}

bool SystemImplemented::operator==(System& object){
	return (this->name == ((SystemImplemented)object).name && this->value == ((SystemImplemented)object).value);
}

System& SystemImplemented::operator=(System& copy){
	if(this == &copy)
		return *this;


	setName(((SystemImplemented)copy).getName());
	setValue(((SystemImplemented)copy).getValue());
	
	return *this;
}
