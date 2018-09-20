#ifndef GUARD_QUEUE_HPP
#define GUARD_QUEUE_HPP

#include <iostream>
#include "list.hpp"

template<class T>
class Queue{
	List<T> queue;
	
public:
	/*Constructors, destructor and overloaded operators*/
	
	inline Queue(){}
	
	/**
	* Creates Queue from a list
	*	@param l : list to copy as a Queue
	*/
	inline Queue(const List<T> &l){
		queue = l;
	}
	
	/**
	* copy constructor
	*	@param q : queue to copy
	*/
	inline Queue(const Queue<T> &q){
		queue = q.queue;
	}
	
	inline ~Queue(){}
	
	Queue<T> & operator=(const Queue<T> &q){
		queue = q.queue;
		return *this;
	}
	
	bool operator==(const Queue<T> &q){
		return *this == q;
	}
	
	bool operator!=(const Queue<T> &q){
		return !(*this == q);
	}
	
	friend std::ostream & operator<<(std::ostream &os, const Queue<T> &q){
		os << q.queue;
		return os;
	}
	
	/* Methods */
	
	/**
	* Adds an element to the queue
	*	@param obj : element to add
	*/
	void push(const T &obj){
		queue.pushFront(obj);
	}
	
	/** 
	* Deletes the head of the queue
	*/
	void pop(){
		queue.popBack();
	}
	
	/**
	* head getter
	*	@return : head of the queue
	*/
	const T & getHead(){
		return queue.getBack();
	}
	
	/**
	* head setter
	*	@param : value of the new head
	*/
	void setHead(const T &obj){
		queue.setBack(obj);
	}
	
};

#endif
