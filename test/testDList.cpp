/**	Mathis MARGOT
 *	Project title : data-structures
 *	Package : data-structures
 *	File : testList.cpp
 *
 *	Decription : test of the DList.
 *	Compile : g++ testDList.cpp dlist.hpp -o <exeName>
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "dlist.hpp"

using namespace std;

int main(){
	srand(time(NULL));

	DList<int> mylist;
	for (int i = 0 ; i < 100 ; ++i){
		mylist.pushBack(rand()%1000);
	}
	cout << "Before sorting : " << endl << mylist << endl;
	mylist.mergeSort();
	cout << "After sorting : " << endl << mylist << endl;
	cout << "Little check : is it sorted ? " << (mylist.isSorted() ? "Yes !" : "No.") << endl;
	return 0;
}