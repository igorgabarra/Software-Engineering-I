/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "Model.h"
#include "System.h"
#include "Flow.h"

#include <string>
#include <vector>

using namespace std;


Model::Model(): name(""){}

Model::Model(string name): name(name){}

Model::Model(Model& copy){
	if(this != &copy){
		this->name = copy.getName();
		this->flows = copy.flows;
		this->systems = copy.systems;
	}
}

Model::~Model(){}

string Model::getName(){
	return name;
}

void Model::setName(string name){
	this->name = name;
}

void Model::add(Flow* flow){
	flows.push_back(flow);
}

void Model::add(System* system){
	systems.push_back(system);
}

bool Model::removeFlow(string name){
	for(int i=0; i<flows.size(); i++)
		if(flows[i]->getName() == name){
			flows.erase(flows.begin()+i);
			return true;
		}

	return false;
}

bool Model::removeSystem(string name){
	for(int i=0; i<systems.size(); i++)
		if(systems[i]->getName() == name){
			systems.erase(systems.begin()+i);
			return true;
		}

	return false;
}

Flow* Model::getFlow(string name){
	for(int i=0; i<flows.size(); i++)
		if(flows[i]->getName() == name){
			return flows[i];
		}

	return NULL;
}

System* Model::getSystem(string name){
	for(int i=0; i<systems.size(); i++)
		if(systems[i]->getName() == name){
			return systems[i];
		}

	return NULL;
}

bool Model::operator==(Model& object){
	return (this->name == object.getName());
}

Model& Model::operator=(Model& copy){
	if(this == &copy)
		return *this;

	this->name = copy.getName();
	this->flows = copy.flows;
	this->systems = copy.systems;

	return *this;
}