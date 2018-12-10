/**	Mathis MARGOT
 *	Project title : data-structures
 *	Package : data-structures
 *	File : dlist.hpp
 *
 *	Decription : enjoyed myself implementing this simply doubly linked list, having a merge sort.
 *	Compile : g++ [<anyCppFileUsingDList>.cpp ..] dlist.hpp -o <exeName>
 */
#ifndef _GUARD_DLIST_HPP_
#define _GUARD_DLIST_HPP_

#include <stdexcept>
#include <iostream>

template<class T>
class DList{
	class Node{
		public:
		T value;
		Node *next;
		Node *prev;
		void operator=(const Node& node){
			this->value = node.value;
			*(this->next) = *(node.next);
			*(this->prev) = *(node.prev);
		}
	};

	Node *head;
	Node *tail;
	int size;

	/**
	*	Split this list into 2 other lists
	*	@param left - 'left' resulting list
	*	@param right - 'right' resulting list
	*/
	void split(DList<T> &left, DList<T> &right){
		int splitPoint = size/2;
		for (int i = 0 ; i < splitPoint ; ++i){
			left.pushBack(getValue(i));
		}
		for (int i = splitPoint ; i < size ; ++i){
			right.pushBack(getValue(i));
		}
	}

	/**
	*	Merge two list into this, only useful in the mergeSort().
	*	@param left - 'left' list to merge
	*	@param right - 'right' list to merge
	*/
	void merge(DList<T> &left, DList<T> &right){
		int initialSize = size;
		for (int i = 0 ; i < initialSize ; ++i) {
			popFront();
		}
		while (!left.isEmpty() && !right.isEmpty()){
			if (left.getHeadValue() > right.getHeadValue()){
				pushBack(right.getHeadValue());
				right.popFront();
			}else{
				pushBack(left.getHeadValue());
				left.popFront();
			}
		}
		while (!left.isEmpty()){
			pushBack(left.getHeadValue());
			left.popFront();
		}
		while (!right.isEmpty()){
			pushBack(right.getHeadValue());
			right.popFront();
		}
	}	

	T getHeadValue(){
		return head->value;
	}

public:
	/* Constructor, destructor and operators */
	DList() : size(0){
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = nullptr;
		tail->next = nullptr;
	}

	DList(const DList<T> &toCopy){
		this = new DList<T>;
		for (int i ; i < toCopy.size ; ++i){
			this->pushBack(toCopy.getValue(i));
		}
	}

	//TODO: operator=

	~DList(){
		while (size > 1){
			popFront();
		}
		delete head;
		delete tail;
	}


	friend std::ostream& operator<< (std::ostream& stream, DList<T>& list){
		stream << "(" << list.size << ") -- ";
		for (int i = 0 ; i < list.size ; ++i){
			stream << list.getValue(i);
			if (i < list.size-1)
				stream << ", ";
			else
				stream << ".";
		}
		return stream;
	}

	/**
	*	Adds a new value to the end of the list
	*	@param value - value to add
	*/
	void pushBack(T value){
		switch(size){
			case 0:
				head->value = value;
				break;
			case 1:
				tail->value = value;
				break;
			default:
				Node *newTail = new Node;
				newTail->value = value;
				newTail->prev = tail;
				newTail->next = nullptr;
				tail->next = newTail;
				tail = newTail;
				break;
		}
		size++;
	}

	//TODO:pushFront

	//TODO:popBack

	/**
	*	Deletes the first elemt of the list;
	*/
	void popFront(){
		if (size > 2){
			Node *delHead = head;
			head = head->next;
			delete delHead;
		}
		if (size == 2){
			head->value = tail->value;
		}
		size--;
		if (size < 0) size = 0;
	}

	/**
	*	Returns the value of the specified index
	*	@param i - index
	*	@return value of index
	*/
	const T& getValue(int i){
		if (i > size){
			throw std::out_of_range("Can't reach that value\n");
		}
		Node *current = head;
		for (int j = 0 ; j < i ; ++j){
			current = current->next;
		}
		return current->value;
	}

	/**
	*	Assigns a new value to the specified index
	*	@param i - index
	*	@param value - new value
	*/
	void setValue(int i, const T& value){
		if (i > size){
			throw std::out_of_range("Can't reach that value\n");
		}
		Node *current = head;
		for (int j = 0 ; j < i ; ++j){
			current = current->next;
		}
		current->value = value;
	}

	int getSize(){
		return size;
	}

	bool isEmpty(){
		return !size;
	}

	bool isSorted(){
		if (!size) return true;
		if (size == 1) return true;
		for(int i = 1 ; i < size ; ++i){
			if (getValue(i-1)>getValue(i)){
				return false;
			}
		}
		return true;
	}

	/**
	*	Applies merge sort on the list, note that it sorts itself.
	*/
	void mergeSort(){
		if (!isSorted()){
			DList<T> left;
			DList<T> right;
			split(left, right);
			left.mergeSort();
			right.mergeSort();
			merge(left, right);
		}
	}
};

#endif