#pragma once
template<typename Type> class BinaryTree;

template<typename Type>
class BinaryTreeNode{
public:
	friend class BinaryTree<Type>;

	Type GetData() {
		return this->data;
	}

	BinaryTreeNode() :pleft(nullptr), pright(nullptr) {}
	BinaryTreeNode(Type item, BinaryTreeNode<Type> *left = nullptr, BinaryTreeNode<Type> *right = nullptr)
		:data(item), pleft(left), pright(right) {}


private:
	Type data;
	BinaryTreeNode<Type> *pleft;
	BinaryTreeNode<Type> *pright;
	BinaryTreeNode<Type> *pparent;
};
