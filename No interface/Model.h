/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef Model_h
#define Model_h

#include <string>
#include <vector>

#include "Flow.h"
#include "System.h"

using namespace std;

class Model{
	string name;
	vector<Flow*> flows;
	vector<System*> systems;

public:
	Model();
	Model(string);
	Model(Model&);
	virtual ~Model();

	string getName();
	void setName(string);

	void add(Flow*);
	void add(System*);

	bool removeFlow(string);
	bool removeSystem(string);

	Flow* getFlow(string);
	System* getSystem(string);

	void execute(int, int, int);

	bool operator==(Model&);
	Model& operator=(Model&);
};


#endif