/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef unitTests_h
#define unitTests_h

#include "Flow.h"
#include "System.h"
#include "Model.h"

#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"

#include <cassert>
#include <cmath>

using namespace std;

void system_UnitTests(){
	SystemTest test;

	System unit("unit1", 100.0);

	assert(test.unit_setName("test1"));
	assert(test.unit_setValue(10.9));
	assert(test.unit_operatorIsEqual(unit, unit));
	assert(test.unit_operatorAssignment(unit, unit));
}


void flow_UnitTests(){
	System* one = new System("one", 1.0);
	System* two = new System("two", 2.2);

	LogisticTest test;

	LogisticFunction unitFlow("unit", one, two);

	assert(test.unit_setName("test"));
	assert(test.unit_insert(two, one));

	assert(test.unit_operatorIsEqual(unitFlow, unitFlow));
	assert(test.unit_operatorAssignment(unitFlow, unitFlow));


	ExponentialTest test1;

	ExponentialFunction unitEFlow("unit", one, two);

	assert(test1.unit_setName("test"));
	assert(test1.unit_insert(two, one));

	assert(test1.unit_operatorIsEqual(unitEFlow, unitEFlow));
	assert(test1.unit_operatorAssignment(unitEFlow, unitEFlow));
}


void model_UnitTests(){
	ModelTest test;

	Model model("model");

	System* one = new System("one", 1.0);
	System* two = new System("two", 2.2);

	ExponentialFunction* flow = new ExponentialFunction("flow", one, two);

	assert(test.unit_setName("unitTest"));
	assert(test.unit_add(one));
	assert(test.unit_add(flow));
	assert(test.unit_removeFlow("flow"));
	assert(test.unit_removeSystem("one"));
	assert(test.unit_operatorIsEqual(model, model));
	assert(test.unit_operatorAssignment(model, model));
}

#endif