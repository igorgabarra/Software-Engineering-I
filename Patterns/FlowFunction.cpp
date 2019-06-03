/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include "System.h"
#include "Flow.h"
#include "FlowFunction.h"
#include "FlowImplemented.h"

#include <string>

using namespace std;

ExponentialFlow::ExponentialFlow():FlowImplemented("", NULL, NULL){}

ExponentialFlow::ExponentialFlow(string name, System* source, System* destiny): FlowImplemented(name, source, destiny){}

ExponentialFlow::ExponentialFlow(Flow& copy){
	if(this == &copy){}

	else{
		setName(((ExponentialFlow)copy).getName());
		insert(((ExponentialFlow)copy).getSource(), ((ExponentialFlow)copy).getDestiny());
	}
}

double ExponentialFlow::function(){
	return this->getSource()->getValue() * 0.01;
}


LogisticFlow::LogisticFlow():FlowImplemented("", NULL, NULL){}

LogisticFlow::LogisticFlow(string name, System* source, System* destiny): FlowImplemented(name, source, destiny){}

LogisticFlow::LogisticFlow(Flow& copy){
	if(this == &copy){}

	else{
		setName(((LogisticFlow)copy).getName());
		insert(((LogisticFlow)copy).getSource(), ((LogisticFlow)copy).getDestiny());
	}
}


double LogisticFlow::function(){
	double p2 = this->getDestiny()->getValue();
	return 0.01*p2*(1-p2/70);
}