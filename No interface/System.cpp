/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "System.h"

#include <string>

using namespace std;

System::System():name(""), initialValue(0.0), actualValue(0.0) {}

System::System(string name, float initialValue, float actualValue): name(name), initialValue(initialValue), actualValue(actualValue) {}

System::System(System& copy){
	if(this != &copy){
		setName(copy.getName());
		setInitial_Value(copy.getInitial_Value());
		setActual_Value(copy.getActual_Value());
	}
}

System::~System(){}

string System::getName(){
	return name;
}

void System::setName(string name){
	this->name = name;
}

float System::getInitial_Value(){
	return initialValue;
}

void System::setInitial_Value(float initialValue){
	this->initialValue = initialValue;
}

float System::getActual_Value(){
	return actualValue;
}

void System::setActual_Value(float actualValue){
	this->actualValue = actualValue;
}

bool System::operator==(System& object){
	return (this->name == object.name && this->initialValue == object.initialValue && this->actualValue == object.actualValue);
}

System& System::operator=(System& copy){
	if(this == &copy)
		return *this;

	setName(copy.getName());
	setInitial_Value(copy.getInitial_Value());
	setActual_Value(copy.getActual_Value());

	return *this;
}

