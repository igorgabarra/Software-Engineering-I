/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef unit_Model_h
#define unit_Model_h

#include "System.h"
#include "Flow.h"
#include "Model.h"

#include <string>

using namespace std;

class ModelTest : public Model{
public:
	bool unit_setName(string);
	
	bool unit_add(Flow*);
	bool unit_add(System*);

	bool unit_removeFlow(string);
	bool unit_removeSystem(string);

//	bool unit_execute(int); It's already all functional tests

	bool unit_operatorIsEqual(Model&, Model&);
	bool unit_operatorAssignment(Model&, Model&);
};

#endif