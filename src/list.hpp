#ifndef GUARD_LIST_HPP
#define GUARD_LIST_HPP

#include <iostream>

template<class T>
class List{

	typedef struct s_node{
		T value;
		s_node *next;
		s_node *prev;
	}Node;

	Node *sentinel;
	int size;
	
public:
	/*Constructors, destructors and overloaded operators*/
	/**
	* Basic constructor, creates an empty list
	*/
	List(void){
		size = 0;
		sentinel = new Node;
		sentinel->next = sentinel;
		sentinel->prev = sentinel;
	}
	
	List(const List<T> &l){
		size = 0;
		sentinel = new Node;
		sentinel->next = sentinel;
		sentinel->prev = sentinel;
		Node *cur = l.sentinel->next;
		while (cur != l.sentinel){
			pushBack(cur->value);
			cur = cur->next;
		}
	}
	
	~List(void){
		clean();
		delete sentinel;
	}
	
	List<T> & operator=(const List<T> &l){
		clean();
		Node *cur = l.sentinel->next;
		while (cur != l.sentinel){
			this->pushBack(cur->value);
			cur = cur->next;
		}
		return *this;
	}
	
	bool operator!=(const List<T> &l){
		if (this->size != l.size){
			return true;
		}
		Node *curL = l.sentinel->next;
		Node *curT = this->sentinel->next;
		while (curT != this->sentinel){
			if (curL->value != curT->value){
				return true;
			}
			curL = curL->next;
			curT = curT->next;
		}
		return false;
	}
	
	bool operator==(const List<T> &l){
		return !(*this != l);
	}
	
	friend std::ostream& operator<<(std::ostream &os, const List<T> &l){
		Node *cur = l.sentinel->next;
		os << "{ ";
		while (cur != l.sentinel){
			os << (cur->value);
			cur = cur->next;
			if (cur != l.sentinel){
				os << " ; ";
			}
		}
		os << " }";
	return os;
	}
	
	/*operators*/
	/**
	* Adds an element at the beginning of the list
	*	@param elem : elem to push
	*/
	void pushFront(const T &elem){
		Node *nElem = new Node;
		nElem->value = elem;
		nElem->next = sentinel->next;
		nElem->next->prev = nElem;
		nElem->prev = sentinel;
		sentinel->next = nElem;
		size++;
	}
	
	/**
	* Adds an element at the end of the list
	*	@param elem : elem to push
	*/
	void pushBack(const T &elem){
		Node *nElem = new Node;
		nElem->value = elem;
		nElem->prev = sentinel->prev;
		nElem->prev->next = nElem;
		nElem->next = sentinel;
		sentinel->prev = nElem;
		size++;
	}
	
	/**
	* Deletes the first element of the list
	*/
	void popFront(void){
		Node *dElem = sentinel->next;
		sentinel->next = dElem->next;
		sentinel->next->prev = sentinel;
		delete dElem;
		size--;
	}
	
	/**
	* Deletes the last element of the list
	*/
	void popBack(void){
		Node *dElem = sentinel->prev;
		sentinel->prev = dElem->prev;
		sentinel->prev->next = sentinel;
		delete dElem;
		size--;
	}
	
	inline const T& getFront(void){return sentinel->next->value;}
	inline const T& getBack(void){return sentinel->prev->value;}
	
	inline void setFront(const T &obj){sentinel->next->value = obj;}
	inline void setBack(const T &obj){sentinel->prev->value = obj;}
	
	/**
	* Return the element at the specified index
	*	@param ind : index of the element
	*	@return element of index ind
	*/
	const T& getAt(int ind){
		if (ind >= size || ind <= 0){
			return sentinel->value;
		}
		Node *cur = sentinel->next;
		for (int i = 0 ; i < ind ; ++i){
			cur = cur->next;
		}
		return cur->value;
	}
	
	/**
	* Modify the element at the specified index
	*	@param ind : index of the element to set
	*/
	void setAt(int ind, const T &obj){
		if (ind >= size || ind <= 0){
			return;
		}
		Node *cur = sentinel->next;
		for (int i = 0 ; i < ind ; ++i){
			cur = cur->next;
		}
		cur->value = obj;
	}
	
	/**
	* Delete all elements of the list and set size to 0
	*/
	void clean(){
		while (size){
			popFront();
		}
	}
};
#endif
