#pragma once
template<typename Type> class BinaryTree;

template<typename Type>
class BinaryTreeNode{
public:
	friend class BinaryTree<Type>;

private:
	BinaryTreeNode() :pleft(nullptr), pright(nullptr){}
	BinaryTreeNode(Type item, BinaryTreeNode<Type> *left = nullptr, BinaryTreeNode<Type> *right = nullptr)
		:data(item),pleft(left), pright(right){}

	Type data;
	BinaryTreeNode<Type> *pleft;
	BinaryTreeNode<Type> *pright;
	BinaryTreeNode<Type> *pparent;
};
