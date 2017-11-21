#include<iostream>

using namespace std;

#include"BinaryTree.h"
#include"LinkedQueue.h"

int main() {
	BinaryTree<int> tree;
	
	for (int i = 1; i <= 10; i++) {
		tree.Insert(i);
	}
	/*
	int init[10] = { 3,0,2,1,7,5,9 };
	for (int i = 0; i < 7; i++) {
	tree.InsertAndSort(init[i]);
	}
	*/
	tree.Print(); 

	LinkedQueue<BinaryTreeNode<int> *> *levelqueue = tree.LevelOrder();
	while (levelqueue->IsEmpty() == false){
		BinaryTreeNode<int> *node = new BinaryTreeNode<int>();
		node = levelqueue->Dequeue();
		cout << node->GetData();
	}
	cout << endl;
	LinkedQueue<BinaryTreeNode<int> *> *prequeue = tree.PreOrder();
	while (prequeue->IsEmpty() == false) {
		BinaryTreeNode<int> *node = new BinaryTreeNode<int>();
		node = prequeue->Dequeue();
		cout << node->GetData();
	}
	cout << endl;
	LinkedQueue<BinaryTreeNode<int> *> *postqueue = tree.PostOrder();
	while (postqueue->IsEmpty() == false) {
		BinaryTreeNode<int> *node = new BinaryTreeNode<int>();
		node = postqueue->Dequeue();
		cout << node->GetData();
	}
	cout << endl;
	

	cin.get();
	return 0;
}