#include <iostream>
#include "queue.hpp"

using namespace std;

int main(){
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q << endl;
	cout << q.getHead() << endl;
	q.pop();
	cout << q << endl;
	cout << q.getHead() << endl;
	
	
	return 0;
}
