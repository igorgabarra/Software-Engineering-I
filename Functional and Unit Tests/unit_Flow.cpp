/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "unit_Flow.h"
#include "Flow.h"
#include "System.h"

#include <string>

using namespace std;

// ---------------------- Logistic Flow Unitary Tests ----------------------

LogisticTest::LogisticTest():LogisticFunction("", NULL, NULL){}

LogisticTest::~LogisticTest(){}

bool LogisticTest::unit_setName(string name){
	setName(name);

	return (getName() == name);
}

bool LogisticTest::unit_insert(System* source, System* destiny){
	insert(source, destiny);

	return (getSource() == source && getDestiny() == destiny);
}

bool LogisticTest::unit_function(){
	return (function() == function());
}

bool LogisticTest::unit_operatorIsEqual(LogisticFunction& one, LogisticFunction& two){
	return (one == two);
}

bool LogisticTest::unit_operatorAssignment(LogisticFunction& one, LogisticFunction& two){
	two = one;

	return (one == two);
}


// ------------------- end of Logistic Flow Unitary Tests ------------------




// -------------------- Exponential Flow Unitary Tests ---------------------

ExponentialTest::ExponentialTest():ExponentialFunction("", NULL, NULL){}

ExponentialTest::~ExponentialTest(){}

bool ExponentialTest::unit_setName(string name){
	setName(name);

	return (getName() == name);
}

bool ExponentialTest::unit_insert(System* source, System* destiny){
	insert(source, destiny);

	return (getSource() == source && getDestiny() == destiny);
}

bool ExponentialTest::unit_function(){
	return (function() == function());
}

bool ExponentialTest::unit_operatorIsEqual(ExponentialFunction& one, ExponentialFunction& two){
	return (one == two);
}

bool ExponentialTest::unit_operatorAssignment(ExponentialFunction& one, ExponentialFunction& two){
	two = one;

	return (one == two);
}


// ------------------ end of Exponential Flow Unitary Tests ----------------