/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef flowfunction_h
#define flowfunction_h

#include "FlowImplemented.h"

using namespace std;

class ExponentialFlow : public FlowImplemented {
public:
	ExponentialFlow(string, System*, System*);
	ExponentialFlow();
	ExponentialFlow(Flow&);
	
	double function();
};

class LogisticFlow : public FlowImplemented {
public:
	LogisticFlow(string, System*, System*);
	LogisticFlow();
	LogisticFlow(Flow&);

	double function();
};

#endif