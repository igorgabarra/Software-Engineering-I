/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef functionaltests_h
#define functionaltests_h


#include "Flow.h"
#include "FlowFunction.h"
#include "System.h"
#include "SystemImplemented.h"
#include "Model.h"
#include "ModelImplemented.h"

//#include "Model.h"

#include <cassert>
#include <cmath>

using namespace std;

void Interface_functionalTest_One(){
	System* pop1 = new SystemImplemented("pop1", 100.0);
	System* pop2 = new SystemImplemented("pop2", 0.0);

	assert(pop1->getValue() == 100);
	assert(pop2->getValue() == 0.0);

	assert(!(pop1 == pop2));	

	Flow*  exponential  = new ExponentialFlow ("exponential",  pop1, pop2);
	Model* model        = new ModelImplemented("functional test 1");

	model->add(exponential);

	model->execute(100);

	assert(abs(model->getFlow("exponential")->getSource() ->getValue() - 36.6032) < 0.001);
	assert(abs(model->getFlow("exponential")->getDestiny()->getValue() - 63.3968) < 0.001);

	delete model;
	delete exponential;
	delete pop2;
	delete pop1;
}

void Interface_functionalTest_Two(){
	System* p1 = new SystemImplemented("p1", 100);
	System* p2 = new SystemImplemented("p2", 10);

	Flow* logistic = new LogisticFlow("logistic", p1, p2);

	Model* model  = new ModelImplemented("functional test 2");

	model->add(logistic);

	model->execute(100);

	assert(abs(model->getFlow("logistic")->getSource() ->getValue() - 88.2167) < 0.0001);
	assert(abs(model->getFlow("logistic")->getDestiny()->getValue() - 21.7834) < 0.0001);

	delete model;
	delete logistic;
	delete p2;
	delete p1;

	cout << "Done!" << endl;
}


void Interface_functionalTest_Three(){
	System* Q1 = new SystemImplemented("Q1", 100.0);
	System* Q2 = new SystemImplemented("Q2", 0.0);
	System* Q3 = new SystemImplemented("Q3", 100.0);
	System* Q4 = new SystemImplemented("Q4", 0.0);
	System* Q5 = new SystemImplemented("Q5", 0.0);	

	Model* model = new ModelImplemented("functional test 3");

	model->add(Q1);
	model->add(Q2);
	model->add(Q3);
	model->add(Q4);
	model->add(Q5);

	Flow* f = new ExponentialFlow("f", Q1, Q2);
	Flow* t = new ExponentialFlow("t", Q2, Q3);
	Flow* u = new ExponentialFlow("u", Q3, Q4);
	Flow* v = new ExponentialFlow("v", Q4, Q1);
	Flow* g = new ExponentialFlow("g", Q1, Q3);
	Flow* r = new ExponentialFlow("r", Q2, Q5);
	
	model->add(f);
	model->add(t);
	model->add(u);
	model->add(v);
	model->add(g);
	model->add(r);

	model->execute(100);

	assert(fabs(Q1->getValue() - 31.8513) < 0.0001);
	//First test: it's really robust?
	//Maybe increase number of precision (< 0.0001)?
	
	assert(fabs(Q2->getValue() - 18.4003) < 0.0001);
	assert(fabs(Q3->getValue() - 77.1143) < 0.0001);
	assert(fabs(Q4->getValue() - 56.1728) < 0.0001);
	assert(fabs(Q5->getValue() - 16.4612) < 0.0001);

	delete model;

	delete f;
	delete t;
	delete u;
	delete v;
	delete g;
	delete r;

	delete Q1;
	delete Q2;
	delete Q3;
	delete Q4;
	delete Q5;

	cout << "Done!" << endl;
	//Working!
}

#endif