#pragma once

template<typename Type> class LinkedQueue;

template<typename Type>
class LinkedQueueNode
{
private:
	friend typename LinkedQueue<Type>;
	//构造函数和析构函数
	LinkedQueueNode() :pnext(nullptr) {}
	LinkedQueueNode(const Type item, LinkedQueueNode<Type> * next = nullptr)
		:data(item), pnext(next) {}
	~LinkedQueueNode() {
		pnext = nullptr;
	}
public:
	Type GetData();
private:
	Type data;
	LinkedQueueNode * pnext;
};

//获取链表节点中的数据
template<typename Type> Type LinkedQueueNode<Type>::GetData() {
	return this->data;
}
