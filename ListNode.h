#ifndef LISTND_H
#define LISTND_H


template<class NODETYPE>
class ListNode{
	template<class NODETYPE>
	friend class List;

public:
	ListNode(const NODETYPE&);
	NODETYPE getData() const;
private:
	NODETYPE data;
	ListNode* nextPtr;
};


template<class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE& info) {
	data = info;
	nextPtr = nullptr;
}

template<class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const { return data; }

#endif // !LISTND_H
