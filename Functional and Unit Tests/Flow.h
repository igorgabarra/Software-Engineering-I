/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef Flow_h
#define Flow_h

#include <string>
#include "System.h"

using namespace std;

class Flow{
	string name;
	System* source;
	System* destiny;

public:
	Flow();
	Flow(string, System*, System*);
	Flow(Flow&);

	virtual ~Flow();

	string getName();
	void setName(string);
	
	void insert(System*, System*);

	System* getSource();
	System* getDestiny();

	virtual double function() = 0;

	bool operator==(Flow&);
	Flow& operator=(Flow&);
};

class ExponentialFunction : public Flow{
public:
	ExponentialFunction(string, System*, System*);
	~ExponentialFunction();
	double function();
};


class LogisticFunction : public Flow{
public:
	LogisticFunction(string, System*, System*);
	~LogisticFunction();
	double function();
};


#endif