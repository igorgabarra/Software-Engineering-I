/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef flow_h
#define flow_h

#include <string>
#include "system.h"

using namespace std;

class Flow{

public:
	virtual ~Flow(){};

	virtual string getName()				= 0;
	virtual void setName(string)			= 0;

	virtual void insert(System*, System*)	= 0;

	virtual System* getSource()				= 0;
	virtual System* getDestiny()			= 0;

	virtual float function()				= 0;

	virtual bool operator==(Flow&)			= 0;
	virtual Flow& operator=(Flow&)			= 0;
};