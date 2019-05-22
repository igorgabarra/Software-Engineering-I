/*
	Autor: Igor Gabarra (17.2.4190)
	BCC322 - Engenharia de Software I
	Universidade Federal de Ouro Preto
*/

#include <iostream>

#include "Model.h"
#include "System.h"
#include "Flow.h"

#include "FunctionalTests.h"
#include "unitTests.h"

using namespace std;

int main(){

	/* ------ Unit Tests ------- */
	
	system_UnitTests();
	/* ------------------------- */
	//flow_UnitTests();
	/* ------------------------- */
	model_UnitTests();
	
	/* --- end of Unit Tests --- */


	/* --- Functional Tests ---- */

	functionalTest_One();
	/* ------------------------- */
	functionalTest_Two();
	/* ------------------------- */
	functionalTest_Three();

	/*  end of Functional Tests  */

	return 0;
}