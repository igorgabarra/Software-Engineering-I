/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "Flow.h"
#include "System.h"
#include "FlowImplemented.h"
#include "SystemImplemented.h"

#include <string>

using namespace std;

FlowImplemented::FlowImplemented():name(""), source(NULL), destiny(NULL){}

FlowImplemented::FlowImplemented(string name, System* source, System* destiny): name(name), source(source), destiny(destiny){}

FlowImplemented::FlowImplemented(Flow& copy){
	if(this == &copy){}

	else{
		setName(copy.getName());
		insert(copy.getSource(), copy.getDestiny());
	}
}

FlowImplemented::~FlowImplemented(){
	SystemImplemented* del;

	del = dynamic_cast<SystemImplemented*>(source);
	
	if(del != NULL)
		delete del;

	del = dynamic_cast<SystemImplemented*>(destiny);
	
	if(del != NULL)
		delete del;

	source  = NULL;
	destiny = NULL;

}

string FlowImplemented::getName(){
	return name;	
}

void FlowImplemented::setName(string name){
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

bool FlowImplemented::operator==(Flow& object){
	return (this->name == object.getName() && this->source == object.getSource() && this->destiny == object.getDestiny());
}

Flow& FlowImplemented::operator=(Flow& copy){
	if(this == &copy)
		return *this;

	setName(copy.getName());
	insert(copy.getSource(), copy.getDestiny());	

	return *this;
}