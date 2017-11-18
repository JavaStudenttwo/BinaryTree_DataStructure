#pragma once
#include "BinaryTreeNode.h"
#include"LinkedQueue.h"

template<typename Type>
class BinaryTree
{
public:
	//������������
	BinaryTree() :proot(nullptr), pcurrent(nullptr) {}
	//��ȡ˽�����ԣ����úͻ�ȡ��ǰ���
	BinaryTreeNode<Type> *GetCurrent() {
		return this->pcurrent;
	}
	void SetCurrent(BinaryTreeNode<Type> *current) {
		this->pcurrent = current;
	}
	//һ�㷽�����ⲿ����
	void Insert(Type item);
	void InsertAndSort(Type item);
	void Print();
	void LevelOrder(BinaryTreeNode<Type> *proot);
	void LevelOrder();

	

private:
	//˽������
	BinaryTreeNode<Type> *proot;
	BinaryTreeNode<Type> *pcurrent;
	//˽�з���
	bool Find(BinaryTreeNode<Type> *root, Type item);
	bool Remove(BinaryTreeNode<Type> *root, Type item);
	//˽�и������ܷ���
	void Insert(BinaryTreeNode<Type> *newnode, BinaryTreeNode<Type> *node);
	void InsertAndSort(Type item, BinaryTreeNode<Type> *node);
	void Print(BinaryTreeNode<Type> *start);
	void Print_1(BinaryTreeNode<Type> *start, int n = 0);
	
};

//���ⲿ���õĲ��뷽��
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

//���뷽���ڲ�ʵ��
template<typename Type>
void BinaryTree<Type>::InsertAndSort(Type item, BinaryTreeNode<Type> *node) {
	//�������������С�ڵ�ǰ������ݣ�����뵽����
	if (item < node->data)
		//�ݹ���ò��뷽��
		InsertAndSort(item, node->pleft);
	//�������������С�ڵ�ǰ������ݣ�����뵽�ҽ��
	else if (node->data < item)
		InsertAndSort(item, node->pright);
	else
		;
}

//���ⲿ���õĲ��뷽��
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

//���뷽���ڲ�ʵ��
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

//��ӡ���������ⲿ����
template<typename Type>
void BinaryTree<Type>::Print() {
	if (proot == nullptr) {
		cout << "������Ϊ��" << endl;
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

//�ڲ���ӡ����ʵ��
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


