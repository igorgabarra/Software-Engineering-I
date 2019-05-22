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
	LogisticTest();
	virtual ~LogisticTest();

	bool unit_setName(string);
	bool unit_insert(System*, System*);

	bool unit_function();

	bool unit_operatorIsEqual(LogisticFunction&, LogisticFunction&);
	bool unit_operatorAssignment(LogisticFunction&, LogisticFunction&);
};

class ExponentialTest : public ExponentialFunction{
public:
	ExponentialTest();
	virtual ~ExponentialTest();
	bool unit_setName(string);
	bool unit_insert(System*, System*);

	bool unit_function();

	bool unit_operatorIsEqual(ExponentialFunction&, ExponentialFunction&);
	bool unit_operatorAssignment(ExponentialFunction&, ExponentialFunction&);
};

#endif
