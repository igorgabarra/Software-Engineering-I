/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef modelimplemented_h
#define modelimplemented_h

#include <string>
#include "Flow.h"
#include "System.h"
#include "Model.h"

#include <vector>

using namespace std;

class ModelImplemented : public Model{
protected:
	string name;
	vector<Flow*> flows;
	vector<System*> systems;

public:
	ModelImplemented();
	ModelImplemented(string);
	ModelImplemented(Model&);
	virtual ~ModelImplemented();

	string getName();
	void setName(string);

	void add(Flow*);
	void add(System*);

	bool removeFlow(string);
	bool removeSystem(string);

	Flow* getFlow(string);
	System* getSystem(string);

	void execute(int);

	bool operator==(Model&);
	Model& operator=(Model&);
};

#endif
