/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef unit_Flow_h
#define unit_Flow_h

#include "System.h"
#include "Flow.h"

#include <string>

using namespace std;

class LogisticTest : public LogisticFunction{
public:
	bool unit_setName(string);
	bool unit_insert(System*, System*);

	bool unit_function();

	bool unit_operatorIsEqual(Flow&, Flow&);
	bool unit_operatorAssignment(Flow&, Flow&);
};

class ExponentialTest : public ExponentialFunction{
public:
	bool unit_setName(string);
	bool unit_insert(System*, System*);

	bool unit_function();

	bool unit_operatorIsEqual(Flow&, Flow&);
	bool unit_operatorAssignment(Flow&, Flow&);
};

#endif
