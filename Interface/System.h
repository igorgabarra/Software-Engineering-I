/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef system_h
#define system_h

#include <string>

using namespace std;

class System{
public:
	virtual string getName()				= 0;
	virtual void setName(string)			= 0;

	virtual double getValue()				= 0;
	virtual void setValue(double)			= 0;

	virtual bool operator==(System&)		= 0;
	virtual System& operator=(System&)		= 0;

};


#endif