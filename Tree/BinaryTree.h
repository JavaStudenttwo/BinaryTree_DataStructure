#pragma once
#include "BinaryTreeNode.h"
#include"LinkedQueue.h"

template<typename Type>
class BinaryTree
{
public:
	BinaryTree() :proot(nullptr), pcurrent(nullptr) {}
	//���úͻ�ȡ��ǰ���
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
	//˽������
	BinaryTreeNode<Type> *proot, *pcurrent;
	bool Find(BinaryTreeNode<Type> *root, Type item);
	bool Remove(BinaryTreeNode<Type> *root, Type item);
	//˽�з���
	void Insert(Type item, BinaryTreeNode<Type> *node);
	BinaryTreeNode<Type> *Parent(BinaryTreeNode<Type> *root, BinaryTreeNode<Type> *current);
	void Print(BinaryTreeNode<Type> *start);

};

//���ⲿ���õĲ��뷽��
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

//���뷽���ڲ�ʵ��
template<typename Type>
void BinaryTree<Type>::Insert(Type item, BinaryTreeNode<Type> *node) {
	//�������������С�ڵ�ǰ������ݣ�����뵽����
	if (item < node->data)
		//�ݹ���ò��뷽��
		Insert(item, node->pfirst);
	//�������������С�ڵ�ǰ������ݣ�����뵽�ҽ��
	else if (node->data < item)
		Insert(item, node->pnext);
	else
		;
}

//��ӡ���������ⲿ����
template<typename Type>
void BinaryTree<Type>::Print() {
	Print(proot);
}

//�ڲ���ӡ����ʵ��
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
//˽�з���
template<typename Type>
BinaryTreeNode<Type> * BinaryTree<Type>::Parent(BinaryTreeNode<Type> *root, BinaryTreeNode<Type> *current) {
	return nullptr;
}

