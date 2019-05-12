/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "Flow.h"
#include <string>

using namespace std;

Flow::Flow():name(""), source(NULL), destiny(NULL){}

Flow::Flow(string name, System* source, System* destiny): name(name), source(source), destiny(destiny){}

Flow::Flow(Flow& copy){
	if(this == &copy){}

	else{
		setName(copy.getName());
		insert(copy.getSource(), copy.getDestiny());
	}
}

Flow::~Flow(){}

string Flow::getName(){
	return name;
}

void Flow::setName(string name){
	this->name = name;
}

void Flow::insert(System* source, System* destiny){
	this->source  = source;
	this->destiny = destiny;
}

System* Flow::getSource(){
	return source;
}

System* Flow::getDestiny(){
	return destiny;
}

bool Flow::operator==(Flow& object){
	return (this->name == object.getName() && this->source == object.getSource() && this->destiny == object.getDestiny());
}

Flow& Flow::operator=(Flow& copy){
	if(this == &copy)
		return *this;

	setName(copy.getName());
	insert(copy.getSource(), copy.getDestiny());

	return *this;
}

/* ---------------------------- object FlowFunction ----------------------------- */

float FlowFunction::function(){
	return this->getSource()->getActual_Value() * 0.3;
}

/* ------------------------- end of object FlowFunction ------------------------- */