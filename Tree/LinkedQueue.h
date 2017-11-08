#pragma once
#include"LinkedQueueNode.h"

template<typename Type>
class LinkedQueue {
public:
	LinkedQueue() :prear(nullptr), pfront(nullptr) {}
	~LinkedQueue() {
		MakeEmpty();
	}
	//���ض��е���Ϣ�ķ���
	bool IsEmpty();
	//�Զ�����Ԫ�صĲ���
	void MakeEmpty();
	bool Enqueue(const Type item);
	Type Dequeue();
	//��������
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
		cout << "û�п�ɾ����Ԫ��" << endl;
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