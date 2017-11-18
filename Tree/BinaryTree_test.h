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
	bool Insert(Type item);
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
	BinaryTreeNode<Type> *Parent(BinaryTreeNode<Type> *root, BinaryTreeNode<Type> *current);
	void Print(BinaryTreeNode<Type> *start, int i = 0);

};

//插入方法
template<typename Type>
bool BinaryTree<Type>::Insert_test1(Type item) {
	BinaryTreeNode<Type> *pnode = new BinaryTreeNode<Type>(item);
	//没有正确的创建新结点
	if (pnode == nullptr) {
		cout << "插入数据出错" << endl;
		exit(1);
	}
	//若二叉树为空，则设置插入结点为根节点
	if (proot == nullptr) {
		proot = pnode;
		this->pcurrent = proot;
		return 1;
	}
	//
	if (this->pcurrent == nullptr) {
		cout << "树内部出错" << endl;
		exit(1);
	}
	//first结点为空，则直接赋值给first结点
	if (this->pcurrent->pfirst == nullptr) {
		this->pcurrent->pfirst = pnode;
		this->pcurrent = pnode;
		return true;
	}
	//first结点不为空，first结点的first结点
	BinaryTreeNode<Type> *pmove = this->pcurrent->pfirst;
	//在这一结点中遍历next下一结点
	while (pmove->pnext) {
		pmove = pmove->pnext;
	}
	pmove->pnext = pnode;
	//pcurrent保存的是最新插入的结点地址
	pcurrent = pnode;
	return true;

}

//打印方法
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
//私有方法
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

//私有打印方法
template<typename Type>
void BinaryTree<Type>::Print(BinaryTreeNode<Type> *start, int i = 0) {
	//起始结点为空
	if (start == nullptr) {
		for (int j = 0; j < i; j++) {
			cout << "     ";
		}
		cout << "NULL" << endl;
		return;
	}
	//递归，直到first结点为空
	BinaryTreeNode<Type> *pmove = start->pfirst;
	Print(pmove, i + 1);
	//第i个结点空i个空单位
	for (int j = 0; j < i; j++) {
		cout << "     ";
	}
	cout << start->data << "--->" << endl;
	//若start->pfirst为空，返回
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
