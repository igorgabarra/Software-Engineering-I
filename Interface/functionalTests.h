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

//#include "Model.h"

#include <cassert>
#include <cmath>

using namespace std;

void functionalTest_One(){
	System* pop1 = new SystemImplemented("pop1", 100.0);
	System* pop2 = new SystemImplemented("pop2", 0.0);

	assert(pop1->getValue() == 100);
	assert(pop2->getValue() == 0.0);

	//pop1->setValue(1000);

	//assert(pop1->getValue() == 1000);

	assert(!(pop1 == pop2));	

	Flow* exponential = new ExponentialFlow("exponential", pop1, pop2);

	//assert(exponential->getSource()->getValue() == 1000);

	Flow* exponential1 = new ExponentialFlow("exponential1", pop2, pop1);	

	cout << exponential1->getSource()->getValue() << endl;
	exponential1 = exponential;
	cout << exponential1->getSource()->getValue() << endl;

}

/*
void functionalTest_Two(){
	System* p1 = new System("p1", 100);
	System* p2 = new System("p2", 10);

	LogisticFunction* logistic = new LogisticFunction("logistic", p1, p2);

	Model model1("functional test 2");

	model1.add(logistic);

	model1.execute(100);

	assert(abs(model1.getFlow("logistic")->getSource()->getValue() - 88.2167) < 0.0001);
	assert(abs(model1.getFlow("logistic")->getDestiny()->getValue() - 21.7834) < 0.0001);
}

void functionalTest_Three(){
	System* Q1 = new System("Q1", 100.0);
	System* Q2 = new System("Q2", 0.0);
	System* Q3 = new System("Q3", 100.0);
	System* Q4 = new System("Q4", 0.0);
	System* Q5 = new System("Q5", 0.0);	

	Model model1("functional test 3");

	model1.add(Q1);
	model1.add(Q2);
	model1.add(Q3);
	model1.add(Q4);
	model1.add(Q5);

	ExponentialFunction* f = new ExponentialFunction("f", Q1, Q2);
	ExponentialFunction* t = new ExponentialFunction("t", Q2, Q3);
	ExponentialFunction* u = new ExponentialFunction("u", Q3, Q4);
	ExponentialFunction* v = new ExponentialFunction("v", Q4, Q1);
	ExponentialFunction* g = new ExponentialFunction("g", Q1, Q3);
	ExponentialFunction* r = new ExponentialFunction("r", Q2, Q5);
	
	model1.add(f);
	model1.add(t);
	model1.add(u);
	model1.add(v);
	model1.add(g);
	model1.add(r);

	model1.execute(100);

	assert(fabs(Q1->getValue() - 31.8512) < 0.0001);
	//First test: it's really robust?
	//Maybe increase number of precision (< 0.0001)?
	
	assert(fabs(Q2->getValue() - 18.4003) < 0.0001);
	assert(fabs(Q3->getValue() - 77.1143) < 0.0001);
	assert(fabs(Q4->getValue() - 56.1728) < 0.0001);
	assert(fabs(Q5->getValue() - 16.4612) < 0.0001);
}
*/
#endif