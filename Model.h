/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef model_h
#define model_h

#include <string>
#include "FlowFunction.h"
#include "SystemImplemented.h"

using namespace std;

class Model{

public:
	virtual ~Model(){};

	virtual string getName()					= 0;
	virtual void setName(string)				= 0;

	virtual void add(Flow*)						= 0;
	virtual void add(System*)					= 0;

	virtual bool removeFlow()					= 0;
	virtual bool removeSystem(string)			= 0;

	virtual FLow* getFlow()						= 0;
	virtual System* getSystem(string)			= 0;

	virtual bool operator==(Model&)				= 0;
	virtual Model& operator=(Model&)			= 0;
};