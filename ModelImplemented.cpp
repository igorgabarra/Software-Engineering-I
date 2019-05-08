/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "ModelImplemented.h"
#include "System.h"
#include "Flow.h"

#include <string>

using namespace std;


ModelImplemented::ModelImplemented(): name(""){}

ModelImplemented::ModelImplemented(string name): name(name){}

ModelImplemented::ModelImplemented(Model& copy){
	if(this == copy)
		return *this;

	this->name = copy->getName();
	this->flows = copy->flows;
	this->systems = copy->systems;

	return *this;
}

ModelImplemented::~Model(){}

string ModelImplemented::getName(){
	return name;
}

void ModelImplemented::setName(string name){
	this->name = name;
}

void ModelImplemented::add(Flow* flow){
	flows.push_back(flow);
}

void ModelImplemented::add(System* system){
	systems.push_back(system);
}

bool ModelImplemented::removeFlow(string name){
	for(int i=0; i<flows.end(); i++)
		if(flows[i]->getName() == name){
			flows.erase(flows.begin()+i);
			return true;
		}

	return false;
}

bool ModelImplemented::removeSystem(string name){
	for(int i=0; i<systems.end(); i++)
		if(systems[i]->getName() == name){
			systems.erase(systems.begin()+i);
			return true;
		}

	return false;
}

Flow* ModelImplemented::getFlow(string name){
	for(int i=0; i<flows.end(); i++)
		if(flows[i]->getName() == name){
			return flows[i];
		}

	return NULL;
}

System* ModelImplemented::getSystem(string name){
	for(int i=0; i<systems.end(); i++)
		if(systems[i]->getName() == name){
			return systems[i];
		}

	return NULL;
}

bool ModelImplemented::operator==(Model& object){
	return (this->name == object->getName);
}

ModelImplemented& ModelImplemented::operator=(Model& copy){
	if(this == copy)
		return *this;

	this->name = copy->getName();
	this->flows = copy->flows;
	this->systems = copy->systems;

	return *this;
}