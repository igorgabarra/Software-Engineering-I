/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#ifndef functionaltests_h
#define functionaltests_h


#include "System.h"

#include "Flow.h"
#include "FlowFunction.h"

#include "Model.h"
#include "ModelImplemented.h"

#include <cassert>
#include <cmath>

using namespace std;

void Interface_functionalTest_One(){
	Model* model = ModelImplemented::createModel("functional test 1");

	System* pop1 = model->createSystem("pop1", 100.0);
	System* pop2 = model->createSystem("pop2", 0.0);

	assert(pop1->getValue() == 100);
	assert(pop2->getValue() == 0.0);

	assert(!(pop1 == pop2));	

	Flow* exponential = model->createFlow<ExponentialFlow>("exponential",  pop1, pop2);

	model->execute(100);

	assert(abs(model->getFlow("exponential")->getSource() ->getValue() - 36.6032) < 0.001);
	assert(abs(model->getFlow("exponential")->getDestiny()->getValue() - 63.3968) < 0.001);

	model->deleteSystem(pop2);
	model->deleteSystem(pop1);

	model->deleteFlow<ExponentialFlow>(exponential);
	ModelImplemented::deleteModel(model);
}

void Interface_functionalTest_Two(){
	Model*  model    = ModelImplemented::createModel("functional test 2");
	System* p1       = model->createSystem("p1", 100);
	System* p2       = model->createSystem("p2", 10);
	Flow*   logistic = model->createFlow<LogisticFlow>("logistic", p1, p2);

	model->execute(100);

	assert(abs(model->getFlow("logistic")->getSource() ->getValue() - 88.2167) < 0.0001);
	assert(abs(model->getFlow("logistic")->getDestiny()->getValue() - 21.7834) < 0.0001);

	model->deleteSystem(p2);
	model->deleteSystem(p1);
	model->deleteFlow<LogisticFlow>(logistic);

	ModelImplemented::deleteModel(model);
}


void Interface_functionalTest_Three(){
	Model* model = ModelImplemented::createModel("functional test 3");

	System* Q1 = model->createSystem("Q1", 100.0);
	System* Q2 = model->createSystem("Q2", 0.0);
	System* Q3 = model->createSystem("Q3", 100.0);
	System* Q4 = model->createSystem("Q4", 0.0);
	System* Q5 = model->createSystem("Q5", 0.0);	

	Flow* f = model->createFlow<ExponentialFlow>("f", Q1, Q2);
	Flow* t = model->createFlow<ExponentialFlow>("t", Q2, Q3);
	Flow* u = model->createFlow<ExponentialFlow>("u", Q3, Q4);
	Flow* v = model->createFlow<ExponentialFlow>("v", Q4, Q1);
	Flow* g = model->createFlow<ExponentialFlow>("g", Q1, Q3);
	Flow* r = model->createFlow<ExponentialFlow>("r", Q2, Q5);

	model->execute(100);

	assert(fabs(Q1->getValue() - 31.8513) < 0.0001);
	//First test: it's really robust?
	//Maybe increase number of precision (< 0.00001)?
	
	assert(fabs(Q2->getValue() - 18.4003) < 0.0001);
	assert(fabs(Q3->getValue() - 77.1143) < 0.0001);
	assert(fabs(Q4->getValue() - 56.1728) < 0.0001);
	assert(fabs(Q5->getValue() - 16.4612) < 0.0001);

	model->deleteSystem(Q1);
	model->deleteSystem(Q2);
	model->deleteSystem(Q3);
	model->deleteSystem(Q4);
	model->deleteSystem(Q5);


	model->deleteFlow<ExponentialFlow>(f);
	model->deleteFlow<ExponentialFlow>(t);
	model->deleteFlow<ExponentialFlow>(u);
	model->deleteFlow<ExponentialFlow>(v);
	model->deleteFlow<ExponentialFlow>(g);
	model->deleteFlow<ExponentialFlow>(r);

	ModelImplemented::deleteModel(model);
//	cout << "Done!" << endl;
//	Working!
}

#endif
