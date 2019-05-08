/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef modelimplemented_h
#define modelimplemented_h

#include <string>
#include "FlowImplemented.h"
#include "SystemImplemented.h"

using namespace std;

class ModelImplemented : public Model{
	string name;
	vector<Flow*> flows;
	vector<System*> systems;

public:
	ModelImplemented();
	ModelImplemented(string = "");
	ModelImplemented(ModelImplemented&);
	virtual ~Model(){};

	string getName();
	void setName(string);

	void add(Flow*);
	void add(System*);

	bool removeFlow();
	bool removeSystem(string);

	FLow* getFlow(string);
	System* getSystem(string);

	bool operator==(ModelImplemented&);
	ModelImplemented& operator=(ModelImplemented&);
};