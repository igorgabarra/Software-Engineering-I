/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "FlowImplemented.h"

#include <string>

using namespace std;

FlowImplemented::FlowImplemented():name(""), source(NULL), destiny(NULL){}

FlowImplemented::FlowImplemented(string name, System* source, System* destiny): name(name), source(source), destiny(destiny){}

FlowImplemented::FlowImplemented(Flow& copy){
	if(this == copy)
		return *this;

	setName(copy->getName());
	insert(copy->getSource(), copy->getDestiny());

	return *this;
}

FlowImplemented::~FlowImplemented(){}

string FlowImplemented::getName(){
	return name;
}

void FlowImplemented::setname(string name){
	this->name = name;
}

void FlowImplemented::insert(System* source, System* destiny){
	this->source  = source;
	this->destiny = destiny;
}

System* FlowImplemented::getSource(){
	return source;
}

System* FlowImplemented::getDestiny(){
	return destiny;
}

bool FlowImplemented::operator==(FlowImplemented& object){
	return (this->name == object->getName() && this->source == object->getSource() && this->destiny == object->getDestiny());
}

FlowImplemented& FlowImplemented::operator=(FlowImplemented& copy){
	if(this == copy)
		return *this;

	setName(copy->getName());
	insert(copy->getSource(), copy->getDestiny());

	return *this;
}