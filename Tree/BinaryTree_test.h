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
	bool Insert(Type item);
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
	BinaryTreeNode<Type> *Parent(BinaryTreeNode<Type> *root, BinaryTreeNode<Type> *current);
	void Print(BinaryTreeNode<Type> *start, int i = 0);

};

//���뷽��
template<typename Type>
bool BinaryTree<Type>::Insert_test1(Type item) {
	BinaryTreeNode<Type> *pnode = new BinaryTreeNode<Type>(item);
	//û����ȷ�Ĵ����½��
	if (pnode == nullptr) {
		cout << "�������ݳ���" << endl;
		exit(1);
	}
	//��������Ϊ�գ������ò�����Ϊ���ڵ�
	if (proot == nullptr) {
		proot = pnode;
		this->pcurrent = proot;
		return 1;
	}
	//
	if (this->pcurrent == nullptr) {
		cout << "���ڲ�����" << endl;
		exit(1);
	}
	//first���Ϊ�գ���ֱ�Ӹ�ֵ��first���
	if (this->pcurrent->pfirst == nullptr) {
		this->pcurrent->pfirst = pnode;
		this->pcurrent = pnode;
		return true;
	}
	//first��㲻Ϊ�գ�first����first���
	BinaryTreeNode<Type> *pmove = this->pcurrent->pfirst;
	//����һ����б���next��һ���
	while (pmove->pnext) {
		pmove = pmove->pnext;
	}
	pmove->pnext = pnode;
	//pcurrent����������²���Ľ���ַ
	pcurrent = pnode;
	return true;

}

//��ӡ����
template<typename Type>
void BinaryTree<Type>::Print() {
	Print(proot);
}

template<typename Type>
void BinaryTree<Type>::LevelOrder(BinaryTreeNode<Type> *proot) {
	LinkedQueue<BinaryTreeNode<Type> *> queue;
	BinaryTreeNode<Type> *pmove, *ptemp;
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
void BinaryTree<Type>::LevelOrder() {
	LevelOrder(proot);
}

template<typename Type>
BinaryTreeNode<Type> * BinaryTree<Type>::Parent(BinaryTreeNode<Type> *current) {
	return Parent(this->proot, current);
}
//˽�з���
template<typename Type>
BinaryTreeNode<Type> * BinaryTree<Type>::Parent(BinaryTreeNode<Type> *root, BinaryTreeNode<Type> *current) {
	if (root == nullptr) {
		return nullptr;
	}
	BinaryTreeNode<Type> *pmove = current->pfirst;
	BinaryTreeNode<Type> *temp;
	if (pmove != nullptr) {
		while (pmove) {
			if (pmove == current) {
				return root;
			}
			pmove = pmove->pnext;
		}
	}
	pmove = root->pfirst;
	while (pmove) {
		temp = Parent(pmove, current);
		if (temp) {
			return temp;
		}
		pmove = pmove->pnext;
	}
	return nullptr;
}

//˽�д�ӡ����
template<typename Type>
void BinaryTree<Type>::Print(BinaryTreeNode<Type> *start, int i = 0) {
	//��ʼ���Ϊ��
	if (start == nullptr) {
		for (int j = 0; j < i; j++) {
			cout << "     ";
		}
		cout << "NULL" << endl;
		return;
	}
	//�ݹ飬ֱ��first���Ϊ��
	BinaryTreeNode<Type> *pmove = start->pfirst;
	Print(pmove, i + 1);
	//��i������i���յ�λ
	for (int j = 0; j < i; j++) {
		cout << "     ";
	}
	cout << start->data << "--->" << endl;
	//��start->pfirstΪ�գ�����
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
