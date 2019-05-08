/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "SystemImplemented.h"

#include <string>

using namespace std;

SystemImplemented::SystemImplemented():name(""), initialValue(0.0), actualValue(0.0) {}

SystemImplemented::SystemImplemented(string name, float initialValue, float actualValue): name(name), initialValue(initialValue), actualValue(actualValue) {}

SystemImplemented::SystemImplemented(SystemImplemented& copy){
	if(this == copy)
		return *this;

	setName(copy->getName());
	setInitial_Value(copy->getInitial_Value());
	setActual_Value(copy->getActual_Value());

	return *this;
}

SystemImplemented::~SystemImplemented(){}

string SystemImplemented::getName(){
	return name;
}

void SystemImplemented::setName(string name){
	this->name = name;
}

float SystemImplemented::getInitial_Value(){
	return initialValue;
}

void SystemImplemented::setInitial_Value(float initialValue){
	this->initialValue = initialValue;
}

float SystemImplemented::getActual_Value(){
	return actualValue;
}

void SystemImplemented::setActual_Value(float actualValue){
	this->actualValue = actualValue;
}

bool SystemImplemented::operator==(SystemImplemented& object){
	return (this->name == object->name && this->initialValue == object->initialValue && this->actualValue == object->actualValue);
}

SystemImplemented& SystemImplemented::operator=(SystemImplemented& copy){
	if(this == copy)
		return *this;

	setName(copy->getName());
	setInitial_Value(copy->getInitial_Value());
	setActual_Value(copy->getActual_Value());

	return *this;
}

