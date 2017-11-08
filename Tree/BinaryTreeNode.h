#pragma once
template<typename Type> class BinaryTree;

template<typename Type>
class BinaryTreeNode{
public:
	friend class BinaryTree<Type>;

private:
	BinaryTreeNode() :pfirst(nullptr), pnext(nullptr){}
	BinaryTreeNode(Type item, BinaryTreeNode<Type> *first = nullptr, BinaryTreeNode<Type> *next = nullptr)
		:data(item),pfirst(pfirst), pnext(next){}

	Type data;
	BinaryTreeNode<Type> *pfirst, *pnext;
};
