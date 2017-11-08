#pragma once
#include "BinaryTreeNode.h"
#include"LinkedQueue.h"

template<typename Type>
class BinaryTree
{
public:
	BinaryTree() :proot(nullptr),pcurrent(nullptr){}

	BinaryTreeNode<Type> *GetCurrent() {
		return pcurrent;
	}
	void SetCurrent(BinaryTreeNode<Type> *current) {
		pcurrent = current;
	}
	bool Insert(Type item);
	void Print();
	void LevelOrder(BinaryTreeNode<Type> *proot);
	void LevelOrder();

private:
	BinaryTreeNode<Type> *proot, *pcurrent;
	bool Find(BinaryTreeNode<Type> *root, Type item);
	bool Remove(BinaryTreeNode<Type> *root, Type item);

	BinaryTreeNode<Type> *Parent(BinaryTreeNode<Type> *root, BinaryTreeNode<Type> *current);
	void Print(BinaryTreeNode<Type> *start, int i = 0);
	
};

template<typename Type> 
bool BinaryTree<Type>::Insert(Type item) {
	BinaryTreeNode<Type> *pnode = new BinaryTreeNode<Type>(item);
	//没有正确的创建新结点
	if (pnode == nullptr){
		cout << "插入数据出错" << endl;
		exit(1);
	}
	//若二叉树为空，则设置插入结点为根节点
	if (proot == nullptr){
		proot = pnode;
		pcurrent = proot;
		return 1;
	}
	//
	if (pcurrent == nullptr) {
		cout << "树内部出错" << endl;
		exit(1);
	}
	//
	if (pcurrent->pfirst == nullptr){
		pcurrent->pfirst = pnode;
		pcurrent = pnode;
		return true;
	}
	BinaryTreeNode<Type> *pmove = pcurrent->pfirst;
	while (pmove->pnext){
		pmove = pmove->pnext;
	}
	pmove->pnext = pnode;
	pcurrent = pnode;
	return true;

}

template<typename Type>
void BinaryTree<Type>::Print() {
	Print(proot);
}

template<typename Type>
void BinaryTree<Type>::LevelOrder(BinaryTreeNode<Type> *proot) {
	LinkedQueue<BinaryTreeNode<Type> *> queue;
	BinaryTreeNode<Type> *pmove, *ptemp;
	if (proot != nullptr){
		queue.Enqueue(proot);
		while (!queue.IsEmpty()){
			ptemp = queue.Dequeue();
			cout << ptemp->data;
			pmove = ptemp->pfirst;
			while (pmove){
				queue.Enqueue(pmove);
				pmove = pmove->pnext;
			}
		}
	}
}

template<typename Type>
void BinaryTree<Type>::LevelOrder() {
	LevelOrder(proot);
}

template<typename Type>
void BinaryTree<Type>::Print(BinaryTreeNode<Type> *start, int i = 0) {
	if (start == nullptr){
		for (int j = 0; j < i; j++) {
			cout << "     ";
		}
		cout << "NULL" << endl;
		return;
	}
	BinaryTreeNode<Type> *pmove = start->pfirst;
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


