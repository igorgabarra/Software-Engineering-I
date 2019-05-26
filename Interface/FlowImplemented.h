/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef flowimplemented_h
#define flowimplemented_h

#include <string>
#include "System.h"
#include "Flow.h"

using namespace std;

class FlowImplemented : public Flow{
protected:
	string name;
	System* source;
	System* destiny;

public:
	FlowImplemented();
	FlowImplemented(string, System*, System*);
	FlowImplemented(Flow&);

	virtual ~FlowImplemented();

	string getName();
	void setName(string);
	
	void insert(System*, System*);

	System* getSource();
	System* getDestiny();

	virtual double function() = 0;

	bool operator==(Flow&);
	Flow& operator=(Flow&);
};

#endif