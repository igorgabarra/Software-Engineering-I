/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef unit_System_h
#define unit_System_h

#include "System.h"
#include <string>

using namespace std;

class SystemTest : public System{
public:
	bool unit_setName(string);
	bool unit_setValue(double);

	bool unit_operatorIsEqual(System&, System&);
	bool unit_operatorAssignment(System&, System&);
};

#endif