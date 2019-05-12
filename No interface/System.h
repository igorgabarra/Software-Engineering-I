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
	float initialValue;
	float actualValue;

public:
	System();
	System(string = "", float = 0.0, float = 0.0);
	System(System&);
	virtual ~System();

	string getName();
	void setName(string);

	float getInitial_Value();
	void setInitial_Value(float);

	float getActual_Value();
	void setActual_Value(float);
	
	bool operator==(System&);
	System& operator=(System&);
};


#endif