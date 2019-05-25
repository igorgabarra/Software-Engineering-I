/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef systemimplemented_h
#define systemimplemented_h

#include <string>
#include "System.h"

using namespace std;

class SystemImplemented : public System{ 
protected:
	string name;
	double value;

public:
	SystemImplemented();
	SystemImplemented(string = "", double = 0.0);
	SystemImplemented(System&);
	virtual ~SystemImplemented();

	string getName();
	void setName(string);

	double getValue();
	void setValue(double);

	bool operator==(System&);
	System& operator=(System&);

};

#endif