#pragma once
template<typename Type> class BinaryTree;

template<typename Type>
class BinaryTreeNode {
public:
	friend class BinaryTree<Type>;

private:
	BinaryTreeNode() :p_firstChild(nullptr), p_nextSibling(nullptr) {}
	BinaryTreeNode(Type item, BinaryTreeNode<Type> *firstChild = nullptr, BinaryTreeNode<Type> *nextSibling = nullptr)
		:data(item), p_firstChild(firstChild), pnp_nextSiblingext(nextSibling) {}

	Type [] elements;
	BinaryTreeNode<Type> *p_firstChild, *p_nextSibling;
};
