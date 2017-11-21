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
	LinkedQueue<BinaryTreeNode<Type> *> *GetLevelQueue() {
		return this->levelQueue;
	}
	LinkedQueue<BinaryTreeNode<Type> *> *GetPreQueue() {
		return this->preQueue;
	}
	LinkedQueue<BinaryTreeNode<Type> *> *GetPostQueue() {
		return this->postQueue;
	}
	//һ�㷽�����ⲿ����
	void Insert(Type item);
	void InsertAndSort(Type item);
	void Print();
	LinkedQueue<BinaryTreeNode<Type> *> *LevelOrder();
	LinkedQueue<BinaryTreeNode<Type> *> *PreOrder();
	LinkedQueue<BinaryTreeNode<Type> *> *PostOrder();

private:
	//˽������
	BinaryTreeNode<Type> *proot;
	BinaryTreeNode<Type> *pcurrent;
	LinkedQueue<BinaryTreeNode<Type> *> *levelQueue;
	LinkedQueue<BinaryTreeNode<Type> *> *preQueue;
	LinkedQueue<BinaryTreeNode<Type> *> *postQueue;
	//˽�з���
	bool Find(BinaryTreeNode<Type> *root, Type item);
	bool Remove(BinaryTreeNode<Type> *root, Type item);
	//˽�и������ܷ���
	void Insert(BinaryTreeNode<Type> *newnode, BinaryTreeNode<Type> *node);
	void InsertAndSort(BinaryTreeNode<Type> *newnode, BinaryTreeNode<Type> *node);
	void Print(BinaryTreeNode<Type> *start);
	void Print(BinaryTreeNode<Type> *start, int n);
	void LevelOrder(BinaryTreeNode<Type> *root);
	void PreOrder(BinaryTreeNode<Type> *root);
	void PostOrder(BinaryTreeNode<Type> *root);
	
};

//���ⲿ���õĲ��뷽��
template<typename Type>
void BinaryTree<Type>::InsertAndSort(Type item) {
	BinaryTreeNode<Type> *newnode = new BinaryTreeNode<Type>(item, nullptr, nullptr);
	if (proot == nullptr) {
		proot = newnode;
	}
	else {
		InsertAndSort(newnode, proot);
	}
}

//���뷽���ڲ�ʵ��
template<typename Type>
void BinaryTree<Type>::InsertAndSort(BinaryTreeNode<Type> *newnode, BinaryTreeNode<Type> *node) {
	
	if(node->data > newnode->data) {
		if (node->pleft == nullptr) {
			node->pleft = newnode;
			newnode->pparent = node;
			pcurrent = node;
			return;
		}
		InsertAndSort(newnode, node->pleft);
	}
	else if(node->data < newnode->data) {
		if (node->pright == nullptr) {
			node->pright = newnode;
			newnode->pparent = node;
			pcurrent = node;
			return;
		}
		InsertAndSort(newnode, node->pright);
	}
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
		Print(proot,0);
	}
}

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
void BinaryTree<Type>::Print(BinaryTreeNode<Type> *start, int n) {
	//��ӡ��ֵnullptr
	if (nullptr == start){
		for (int i = 0; i < n; i++)
		{
			cout << "		";
		}
		cout << "--->" << "nullptr" << endl;
		return;
	}
	//�ݹ��ӡ����
	BinaryTreeNode<Type> *pmove = start->pleft;
	Print(pmove, n + 1);
	//��ӡ������ݣ���㲻Ϊ�գ�
	for (int i = 0; i < n; i++) {
		cout << "		";
	}
	
	cout << "--->" << start->data;
	if (start->pparent != nullptr) {
		cout << "(" << start->pparent->data << "���ӽ��)" << endl;
	}
	//�ݹ��ӡ�ҽ��
	pmove = start->pright;
	//���ҽ��Ϊ��
	if (nullptr == pmove) {
		for (int i = 0; i <= n; i++)
		{
			cout << "		";
		}
		cout << "--->" << "nullptr" << endl;
		return;
	}
	while (pmove){
		Print(pmove, n + 1);
		pmove = pmove->pright;
	}
}

//�������
template<typename Type>
LinkedQueue<BinaryTreeNode<Type> *> *BinaryTree<Type>::LevelOrder() {
	levelQueue = new LinkedQueue<BinaryTreeNode<Type> *>();
	LevelOrder(proot);
	return levelQueue;
}

template<typename Type>
void BinaryTree<Type>::LevelOrder(BinaryTreeNode<Type> *root) {
	if (root != nullptr) {
		levelQueue->Enqueue(root);
		if (root->pleft != nullptr) {
			LevelOrder(root->pleft);
		}
		if (root->pright != nullptr) {
			LevelOrder(root->pright);
		}
	}
}

//�������
template<typename Type>
LinkedQueue<BinaryTreeNode<Type> *> *BinaryTree<Type>::PreOrder() {
	preQueue = new LinkedQueue<BinaryTreeNode<Type> *>();
	PreOrder(proot);
	return preQueue;
}

template<typename Type>
void BinaryTree<Type>::PreOrder(BinaryTreeNode<Type> *root) {
	if (root != nullptr) {
		if (root->pleft != nullptr) {
			PreOrder(root->pleft);
		}
		preQueue->Enqueue(root);
		if (root->pright != nullptr) {
			PreOrder(root->pright);
		}
	}
}

//�������
template<typename Type>
LinkedQueue<BinaryTreeNode<Type> *> *BinaryTree<Type>::PostOrder() {
	postQueue = new LinkedQueue<BinaryTreeNode<Type> *>();
	PostOrder(proot);
	return postQueue;
}

template<typename Type>
void BinaryTree<Type>::PostOrder(BinaryTreeNode<Type> *root) {
	if (root != nullptr) {
		if (root->pright != nullptr) {
			PostOrder(root->pright);
		}
		postQueue->Enqueue(root);
		if (root->pleft != nullptr) {
			PostOrder(root->pleft);
		}
		
	}
}



