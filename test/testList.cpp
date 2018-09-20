#include "../src/list.hpp"
#include <iostream>

using namespace std;

void testCopy(List<List<int>> l);

int main(){
	/*tests push and pop*/
	List<int> l;
	List<int> k;
	List<List<int>> lk;
	l.pushFront(8);
	k.pushFront(7);
	l.pushBack(9);
	k.pushBack(0);
	cout << l << " et " << k << endl;
	l.popFront();
	cout << l << endl;
	l.pushFront(6);
	k.pushFront(8);
	l.pushBack(8);
	k.pushBack(4);
	l.pushBack(9);
	k.pushBack(1);
	/*test on a 2 dims list*/
	lk.pushBack(k);
	lk.pushFront(l);
	cout << lk << endl;
	cout << ((l==k) ? ("true") : ("false")) << endl;
	/*test operators*/
	List<List<int>> lkCp = lk;
	testCopy(lkCp);
	cout << lkCp << endl;
	cout << ((lk == lkCp) ? ("true") : ("false")) << endl;
	cout << lkCp.getAt(3) << endl;
	cout << lkCp.getAt(1) << endl;
	lkCp.setAt(1, l);
	cout << lkCp.getAt(1) << endl;
	return 0;
}

void testCopy(List<List<int>> l){
	List<int> lk;
	lk.pushBack(68);
	lk.pushFront(99);
	l.pushFront(lk);
	cout << l << endl;
}
