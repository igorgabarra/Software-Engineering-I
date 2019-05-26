/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include <iostream>

//#include "Model.h"
#include "System.h"
//#include "Flow.h"

#include "FunctionalTests.h"
//#include "unitTests.h"

using namespace std;

int main(){

	/* --- Functional Tests ---- */
	//functionalTest_Two();
	Interface_functionalTest_Two();
	/* ------------------------- */
	Interface_functionalTest_One(); //Seg Fault but working
	/* ------------------------- */
	//functionalTest_Three();

	/*  end of Functional Tests  */

	return 0;
}