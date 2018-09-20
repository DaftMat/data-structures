#ifndef GUARD_STACK_HPP
#define GUARD_STACK_HPP

#include <iostream>
#include "list.hpp"

template<class T>
class Stack{
	
	typedef struct s_node{
		T value;
		s_node *next;
		s_node *prev;
	}Node;
	
	List<T> stack;
	
public:
	/*constructors, destructors and overloaded operators*/
	inline Stack(){}
	
	/**
	* Create a stack from a list
	*	@param l : List to copy as a stack.
	*/
	Stack(const List<T> &l){
		stack = l;
	}
	
	/** Copy constructor
	*/
	Stack(const Stack<T> &s){
		stack = *(s.stack);
	}
	
	inline ~Stack(){}
	
	Stack & operator=(const Stack<T> &s){
		stack = s.stack;
	}
	
	/* Methods */
	bool operator==(const Stack<T> &s){
		return (stack == s.stack);
	}
	
	bool operator!=(const Stack<T> &s){
		return !(*this == s);
	}
	
	friend std::ostream & operator<<(std::ostream &os, const Stack<T> &s){
		os << s.stack;
		return os;
	}
	
	/**
	* Stack an element upon the stack
	*	@param e : element to stack
	*/
	void push(const T &obj){
		stack.pushFront(obj);
	}
	
	/**
	* Unstack the head of the stack
	*/
	void pop(){
		stack.popFront();
	}
	
	/** 
	* Get the head
	*	@return head of the stack
	*/
	const T & getHead(){
		return stack.getFront();
	}
	
	/** 
	* Set the head
	*	@param obj : value of new head
	*/
	void setHead(const T &obj){
		stack.setFront(obj);
	}
	
};

#endif
