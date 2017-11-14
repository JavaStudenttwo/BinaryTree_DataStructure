#pragma once
#include "BinaryTreeNode.h"
#include"LinkedQueue.h"

template<typename Type>
class BinaryTree
{
public:
	BinaryTree() :proot(nullptr), pcurrent(nullptr) {}
	//设置和获取当前结点
	BinaryTreeNode<Type> *GetCurrent() {
		return this->pcurrent;
	}
	void SetCurrent(BinaryTreeNode<Type> *current) {
		this->pcurrent = current;
	}
	void Insert(Type item);
	void Print();
	void LevelOrder(BinaryTreeNode<Type> *proot);
	void LevelOrder();

	BinaryTreeNode<Type> *Parent(BinaryTreeNode<Type> *current);

private:
	//私有属性
	BinaryTreeNode<Type> *proot, *pcurrent;
	bool Find(BinaryTreeNode<Type> *root, Type item);
	bool Remove(BinaryTreeNode<Type> *root, Type item);
	//私有方法
	void Insert(Type item, BinaryTreeNode<Type> *node);
	BinaryTreeNode<Type> *Parent(BinaryTreeNode<Type> *root, BinaryTreeNode<Type> *current);
	void Print(BinaryTreeNode<Type> *start);

};

//供外部调用的插入方法
template<typename Type>
void BinaryTree<Type>::Insert(Type item) {
	if (pcurrent == nullptr) {
		BinaryTreeNode<Type> *newnode = new BinaryTreeNode<Type>(item, nullptr, nullptr);
		proot = newnode;
		Insert(item, newnode);
	}
	else {
		Insert(item, pcurrent);
	}
}

//插入方法内部实现
template<typename Type>
void BinaryTree<Type>::Insert(Type item, BinaryTreeNode<Type> *node) {
	//如果待插入数据小于当前结点数据，则插入到左结点
	if (item < node->data)
		//递归调用插入方法
		Insert(item, node->pfirst);
	//如果待插入数据小于当前结点数据，则插入到右结点
	else if (node->data < item)
		Insert(item, node->pnext);
	else
		;
}

//打印方法，供外部调用
template<typename Type>
void BinaryTree<Type>::Print() {
	Print(proot);
}

//内部打印方法实现
template<typename Type>
void BinaryTree<Type>::Print(BinaryTreeNode<Type> *start) {
	if (start != nullptr) {
		Print(start->pfirst);
		cout << start->data << endl;
		Print(start->pnext);
	}
}

template<typename Type>
void BinaryTree<Type>::LevelOrder(BinaryTreeNode<Type> *proot) {

}

template<typename Type>
void BinaryTree<Type>::LevelOrder() {

}

template<typename Type>
BinaryTreeNode<Type> * BinaryTree<Type>::Parent(BinaryTreeNode<Type> *current) {
	return nullptr;
}
//私有方法
template<typename Type>
BinaryTreeNode<Type> * BinaryTree<Type>::Parent(BinaryTreeNode<Type> *root, BinaryTreeNode<Type> *current) {
	return nullptr;
}

