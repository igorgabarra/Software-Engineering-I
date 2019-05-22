/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "unit_System.h"
#include "System.h"

#include <string>

using namespace std;

// ---------------------- System Unitary Tests ----------------------


bool SystemTest::unit_setName(string name){
	setName(name);

	return (getName() == name);
}

bool SystemTest::unit_setValue(double value){
	setValue(value);

	return (getValue() == value);
}

bool SystemTest::unit_operatorIsEqual(System& one, System& two){
	return (one == two);
}

bool SystemTest::unit_operatorAssignment(System& one, System& two){
	two = one;

	return (one == two);
}

// ------------------- end of System Unitary Tests ------------------