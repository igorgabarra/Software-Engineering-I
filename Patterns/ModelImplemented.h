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
private:
	static ModelImplemented* instance;

protected:
	string name;
	vector<Flow*> flows;
	vector<System*> systems;
	ModelImplemented(string);
	ModelImplemented();
	ModelImplemented(Model&);


public:
	virtual ~ModelImplemented();

	System* createSystem(string, double);
	bool deleteSystem(System*);

	static Model* createModel(string);
	static bool deleteModel(Model*);

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
