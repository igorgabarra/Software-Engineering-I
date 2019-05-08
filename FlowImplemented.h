/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef flowimplemented_h
#define flowimplemented_h

#include <string>
#include "system.h"

using namespace std;

class FlowImplemented : public Flow{
	string name;
	System* source;
	System* destiny;

public:
	FlowImplemented();
	FlowImplemented(string, System*, System*);
	FlowImplemented(FlowImplemented&);

	virtual ~FlowImplemented(){};

	string getName();
	void setName(string);
	
	void insert(System*, System*);

	System* getSource();
	System* getDestiny();

	virtual float function() = 0;

	bool operator==(FlowImplemented&);
	FlowImplemented& operator=(FlowImplemented&);
};