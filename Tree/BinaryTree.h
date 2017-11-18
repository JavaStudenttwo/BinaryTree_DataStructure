#pragma once
#include "BinaryTreeNode.h"
#include"LinkedQueue.h"

template<typename Type>
class BinaryTree
{
public:
	//构造析构方法
	BinaryTree() :proot(nullptr), pcurrent(nullptr) {}
	//获取私有属性，设置和获取当前结点
	BinaryTreeNode<Type> *GetCurrent() {
		return this->pcurrent;
	}
	void SetCurrent(BinaryTreeNode<Type> *current) {
		this->pcurrent = current;
	}
	//一般方法，外部调用
	void Insert(Type item);
	void InsertAndSort(Type item);
	void Print();
	void LevelOrder(BinaryTreeNode<Type> *proot);
	void LevelOrder();

	

private:
	//私有属性
	BinaryTreeNode<Type> *proot;
	BinaryTreeNode<Type> *pcurrent;
	//私有方法
	bool Find(BinaryTreeNode<Type> *root, Type item);
	bool Remove(BinaryTreeNode<Type> *root, Type item);
	//私有辅助功能方法
	void Insert(BinaryTreeNode<Type> *newnode, BinaryTreeNode<Type> *node);
	void InsertAndSort(Type item, BinaryTreeNode<Type> *node);
	void Print(BinaryTreeNode<Type> *start);
	void Print_1(BinaryTreeNode<Type> *start, int n = 0);
	
};

//供外部调用的插入方法
template<typename Type>
void BinaryTree<Type>::InsertAndSort(Type item) {
	if (pcurrent == nullptr) {
		BinaryTreeNode<Type> *newnode = new BinaryTreeNode<Type>(item, nullptr, nullptr);
		proot = newnode;
		InsertAndSort(item, newnode);
	}
	else {
		InsertAndSort(item, pcurrent);
	}
}

//插入方法内部实现
template<typename Type>
void BinaryTree<Type>::InsertAndSort(Type item, BinaryTreeNode<Type> *node) {
	//如果待插入数据小于当前结点数据，则插入到左结点
	if (item < node->data)
		//递归调用插入方法
		InsertAndSort(item, node->pleft);
	//如果待插入数据小于当前结点数据，则插入到右结点
	else if (node->data < item)
		InsertAndSort(item, node->pright);
	else
		;
}

//供外部调用的插入方法
template<typename Type>
void BinaryTree<Type>::Insert(Type item) {
	BinaryTreeNode<Type> *newnode = new BinaryTreeNode<Type>(item, nullptr, nullptr);
	if (pcurrent == nullptr) {
		proot = newnode;
		pcurrent = newnode;
	}
	else {
		Insert(newnode, pcurrent);
	}
}

//插入方法内部实现
template<typename Type>
void BinaryTree<Type>::Insert(BinaryTreeNode<Type> *newnode, BinaryTreeNode<Type> *node) {
	if (node->pleft == nullptr) {
		node->pleft = newnode;
		newnode->pparent = node;
		pcurrent = node;
	}	
	else if(node->pright == nullptr) {
		node->pright = newnode;
		newnode->pparent = node;
		pcurrent = node;
	}
	else {
		Insert(newnode,pcurrent->pleft);
	}
}

//打印方法，供外部调用
template<typename Type>
void BinaryTree<Type>::Print() {
	if (proot == nullptr) {
		cout << "二叉树为空" << endl;
	}
	else {
		Print(proot);
	}
}

/*
template<typename Type>
void BinaryTree<Type>::Print(BinaryTreeNode<Type> *start) {
if (start != nullptr){
Print(start->pleft);
cout << start->data << endl;
Print(start->pright);
}
}
*/

template<typename Type>
void BinaryTree<Type>::Print(BinaryTreeNode<Type> *start) {
	if (start != nullptr) {
		cout << "->" << start->data;
		Print(start->pleft);
		Print(start->pright);
	}
}

//内部打印方法实现
template<typename Type>
void BinaryTree<Type>::Print_1(BinaryTreeNode<Type> *start, int n = 0) {
	if (NULL == start)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "     ";
		}
		cout << "NULL" << endl;
		return;
	}
	BinaryTreeNode<Type> *pmove = start->pleft;
	Print(pmove, n + 1);

	for (int i = 0; i < n; i++) {
		cout << "     ";
	}
	cout << start->data << "--->" << endl;

	if (NULL == pmove) {
		return;
	}
	pmove = pmove->pright;
	while (pmove)
	{
		Print(pmove, n + 1);
		pmove = pmove->pright;
	}
	
	
}

template<typename Type>
void BinaryTree<Type>::LevelOrder(BinaryTreeNode<Type> *proot) {

}

template<typename Type>
void BinaryTree<Type>::LevelOrder() {

}


