#pragma once
#include"LinkedQueueNode.h"

template<typename Type>
class LinkedQueue {
public:
	LinkedQueue() :prear(nullptr), pfront(nullptr) {}
	~LinkedQueue() {
		MakeEmpty();
	}
	//返回队列的信息的方法
	bool IsEmpty();
	//对队列内元素的操作
	void MakeEmpty();
	bool Enqueue(const Type item);
	Type Dequeue();
	//基本方法
	void Print();

private:
	LinkedQueueNode<Type> * pfront;
	LinkedQueueNode<Type> * prear;
};

template<typename Type>
void LinkedQueue<Type>::MakeEmpty() {
	LinkedQueueNode<Type> *pdel;
	while (pfront) {
		pdel = pfront;
		pfront = pfront->pnext;
		delete pdel;
	}
}

template<typename Type>
bool LinkedQueue<Type>::IsEmpty() {
	return pfront == nullptr;
}

template<typename Type>
bool LinkedQueue<Type>::Enqueue(const Type item) {
	if (pfront == nullptr) {
		pfront = prear = new LinkedQueueNode<Type>(item);
	}
	else {
		prear = prear->pnext = new LinkedQueueNode<Type>(item);
	}
	return true;
}

template<typename Type>
Type LinkedQueue<Type>::Dequeue() {
	if (IsEmpty()) {
		cout << "没有可删除的元素" << endl;
		exit(1);
	}
	LinkedQueueNode<Type> *pdel = pfront;
	Type temp = pfront->data;
	pfront = pfront->pnext;
	delete pdel;
	return temp;
}

template<typename Type>
void LinkedQueue<Type>::Print() {
	LinkedQueueNode<Type> *pmove = pfront;
	cout << endl << "front";
	while (pmove) {
		cout << "->" << pmove->data;
		pmove = pmove->pnext;
	}
	cout << "-rear" << endl;
}