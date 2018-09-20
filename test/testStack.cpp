#include <iostream>
#include "stack.hpp"

using namespace std;

int main(){
	Stack<int> s;
	s.push(8);
	s.push(9);
	s.push(7);
	cout << s << endl;
	s.pop();
	cout << s << endl;
	cout << s.getHead() << endl;
	return 0;
}
