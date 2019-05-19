/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "System.h"

#include <string>

using namespace std;

System::System():name(""), value(0.0){} //, actualValue(0.0) {}
System::System(string name, double value): name(name), value(value){}

System::System(System& copy){
	if(this != &copy){
		setName(copy.getName());
		setValue(copy.getValue());
	}
}

System::~System(){}

string System::getName(){
	return name;
}

void System::setName(string name){
	this->name = name;
}

double System::getValue(){
	return value;
}

void System::setValue(double initialValue){
	this->value = initialValue;
}

bool System::operator==(System& object){
	return (this->name == object.name && this->value == object.value);
}

System& System::operator=(System& copy){
	if(this == &copy)
		return *this;

	setName(copy.getName());
	setValue(copy.getValue());
	
	return *this;
}

