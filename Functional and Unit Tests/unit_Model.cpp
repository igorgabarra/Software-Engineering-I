/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "unit_Model.h"

#include "Flow.h"
#include "System.h"
#include "Model.h"

#include <string>

using namespace std;

// ---------------------- Model Unitary Tests ----------------------

bool ModelTest::unit_setName(string name){
	setName(name);

	return (getName() == name);
}


bool ModelTest::unit_add(Flow* flow){
	add(flow);

	return removeFlow(flow->getName()); //Find flow: returns true, else returns false
}


bool ModelTest::unit_add(System* system){
	add(system);

	return removeSystem(system->getName()); //Find system: returns true, else returns false
}


bool ModelTest::unit_removeFlow(string name){
	removeFlow(name);

	return (!removeFlow(name)); //already removed, so returns false bc wasn't found
}


bool ModelTest::unit_removeSystem(string name){
	removeSystem(name);

	return (!removeSystem(name)); //already removed, so returns false bc wasn't found
}


bool ModelTest::unit_operatorIsEqual(Model& one, Model& two){
	return (one == two);
}


bool ModelTest::unit_operatorAssignment(Model& one, Model& two){
	two = one;

	return (one == two);
}

// ------------------ end of Model Unitary Tests -------------------