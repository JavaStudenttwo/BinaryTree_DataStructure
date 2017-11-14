#pragma once

#include "GeneralTreeNode.h"

template<typename Type>
class GeneralTree
{
public:
	GeneralTree() :proot(nullptr), pcurrent(nullptr) {}

	GeneralTreeNode<Type> *GetCurrent() {
		return pcurrent;
	}
	void SetCurrent(GeneralTreeNode<Type> *current) {
		pcurrent = current;
	}
	bool Insert(Type item);
	void Print();
	void LevelOrder(GeneralTreeNode<Type> *proot);
	void LevelOrder();

private:
	GeneralTreeNode<Type> *proot, *pcurrent;
	bool Find(GeneralTreeNode<Type> *root, Type item);
	bool Remove(GeneralTreeNode<Type> *root, Type item);

	GeneralTreeNode<Type> *Parent(GeneralTreeNode<Type> *root, GeneralTreeNode<Type> *current);
	void Print(GeneralTreeNode<Type> *start, int i = 0);

};

template<typename Type>
void GeneralTree<Type>::Print() {
	Print(proot);
}

template<typename Type>
void GeneralTree<Type>::LevelOrder(GeneralTreeNode<Type> *proot) {
	LinkedQueue<GeneralTreeNode<Type> *> queue;
	GeneralTreeNode<Type> *pmove, *ptemp;
	if (proot != nullptr) {
		queue.Enqueue(proot);
		while (!queue.IsEmpty()) {
			ptemp = queue.Dequeue();
			cout << ptemp->data;
			pmove = ptemp->pfirst;
			while (pmove) {
				queue.Enqueue(pmove);
				pmove = pmove->pnext;
			}
		}
	}
}

template<typename Type>
void GeneralTree<Type>::LevelOrder() {
	LevelOrder(proot);
}

template<typename Type>
void GeneralTree<Type>::Print(GeneralTreeNode<Type> *start, int i = 0) {
	if (start == nullptr) {
		for (int j = 0; j < i; j++) {
			cout << "     ";
		}
		cout << "NULL" << endl;
		return;
	}
	GeneralTreeNode<Type> *pmove = start->pfirst;
	Print(pmove, i + 1);

	for (int j = 0; j < i; j++) {
		cout << "     ";
	}
	cout << start->data << "--->" << endl;

	if (NULL == pmove) {
		return;
	}
	pmove = pmove->pnext;
	while (pmove)
	{
		Print(pmove, i + 1);
		pmove = pmove->pnext;
	}
}


