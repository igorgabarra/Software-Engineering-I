/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef System_h
#define System_h

#include <string>

using namespace std;

class System{ 
private:
	string name;
	double value;

public:
	System();
	System(string = "", double = 0.0);
	System(System&);
	virtual ~System();

	string getName();
	void setName(string);

	double getValue();
	void setValue(double);

	bool operator==(System&);
	System& operator=(System&);
};


#endif