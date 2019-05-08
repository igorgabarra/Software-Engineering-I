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
private:
	string name;
	float initialValue;
	float actualValue;

public:
	SystemImplemented();
	SystemImplemented(string = "", float = 0.0, float = 0.0);
	SystemImplemented(SystemImplemented&);
	virtual ~SystemImplemented(){}

	string getName();
	void setName(string);

	float getInitial_Value();
	void setInitial_Value(float);

	float getActual_Value();
	void setActual_Value(float);
	
	bool operator==(SystemImplemented&);
	SystemImplemented& operator=(SystemImplemented&);
};