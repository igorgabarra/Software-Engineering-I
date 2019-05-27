/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "ModelImplemented.h"
#include "SystemImplemented.h"
#include "System.h"
#include "Flow.h"
#include "FlowFunction.h"
#include "Model.h"

#include <string>

using namespace std;

ModelImplemented::ModelImplemented(): name(""){}

ModelImplemented::ModelImplemented(string name): name(name){}

ModelImplemented::ModelImplemented(Model& copy){
	if(this != &copy){
		name = ((ModelImplemented)copy).getName();

		if(flows == ((ModelImplemented)copy).flows){}
		else{
			vector<int> auxiliar;
			//Necessary to dynamic_cast each flow (discover exponential or logistic)

			for(auto it : flows)
				if(it != NULL)
					delete it;

			ExponentialFlow* exp;
			LogisticFlow* log;

			for(auto it : ((ModelImplemented)copy).flows){
				if( (exp = dynamic_cast<ExponentialFlow*>(it)) != NULL)
					add(new ExponentialFlow(exp->getName(), exp->getSource(), exp->getDestiny()));

				else if((log = dynamic_cast<LogisticFlow*>(it)) != NULL)
					add(new LogisticFlow(log->getName(), log->getSource(), log->getDestiny()));
			}
		}

		if(systems == ((ModelImplemented)copy).systems){}
		else{
			for(auto it : systems){
				SystemImplemented* del = dynamic_cast<SystemImplemented*>(it);
				
				if(del != NULL)	
					delete del;
			}

			for(auto it : ((ModelImplemented)copy).systems)
				add(new SystemImplemented(it->getName(), it->getValue()));
		}
	}
}

ModelImplemented::~ModelImplemented(){}

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
	for(unsigned int i=0; i<flows.size(); i++)
		if(flows[i]->getName() == name){
			flows.erase(flows.begin()+i);
			return true;
		}

	return false;
}

bool ModelImplemented::removeSystem(string name){
	for(unsigned int i=0; i<systems.size(); i++)
		if(systems[i]->getName() == name){
			systems.erase(systems.begin()+i);
			return true;
		}

	return false;
}

Flow* ModelImplemented::getFlow(string name){
	for(unsigned int i=0; i<flows.size(); i++)
		if(flows[i]->getName() == name){
			return flows[i];
		}

	return NULL;
}

System* ModelImplemented::getSystem(string name){
	for(unsigned int i=0; i<systems.size(); i++)
		if(systems[i]->getName() == name){
			return systems[i];
		}

	return NULL;
}

void ModelImplemented::execute(int time){
	int count = 0;

	for(int i = 0; i < time; i++){
		vector<double> results;

		for(vector<Flow*>::iterator flow = flows.begin(); flow != flows.end(); ++flow){
			results.push_back((*flow)->function());
		}


		for(vector<Flow*>::iterator flow = flows.begin(); flow != flows.end(); ++flow){
					
			(*flow)->getDestiny()->setValue((*flow)->getDestiny()->getValue() + results[count]);
			(*flow)->getSource()->setValue((*flow)->getSource()->getValue() - results[count]);

			count++;
		}

		for(vector<System*>::iterator system = systems.begin(); system != systems.end(); ++system){
			(*system)->setValue((*system)->getValue());
		}

		results.clear();
		count = 0;
	}
}


bool ModelImplemented::operator==(Model& object){
	if(name != ((ModelImplemented)object).getName())
		return false; 

	int count = 0;

	for(auto it : flows){
		if(it == ((ModelImplemented)object).flows[count]){}

		else return false;

		count++;
	}

	count = 0;

	for(auto it : systems){
		if(it == ((ModelImplemented)object).systems[count]){}
		
		else return false;

		count++;
	}

	return true;
}

Model& ModelImplemented::operator=(Model& copy){
	if(this == &copy)
		return *this;

	name = ((ModelImplemented)copy).getName();

	if(flows == ((ModelImplemented)copy).flows){}
	else{
		vector<int> auxiliar;
		//Necessary to dynamic_cast each flow (discover exponential or logistic)

		for(auto it : flows)
			if(it != NULL)
				delete it;

		flows.clear();

		ExponentialFlow* exp;
		LogisticFlow* log;

		for(auto it : ((ModelImplemented)copy).flows){
			if( (exp = dynamic_cast<ExponentialFlow*>(it)) != NULL)
				add(new ExponentialFlow(*exp));

			else if((log = dynamic_cast<LogisticFlow*>(it)) != NULL)
				add(new LogisticFlow(*log));
		}
	}


	if(systems == ((ModelImplemented)copy).systems){}
	else{
		for(auto del : systems)			
			if(del != NULL)
				delete del;

		systems.clear();

		for(auto it : ((ModelImplemented)copy).systems)
			add(new SystemImplemented(*it));
	}

	return *this;
}