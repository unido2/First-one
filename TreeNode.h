#ifndef TREENODE_H
#define TREENODE_H

template<class NODETYPE> 
class TreeNode
{
	template<class NODETYPE>
	friend class Tree;
public:
	TreeNode(const NODETYPE&);
	NODETYPE getData() const;
private:
	TreeNode* leftPtr;
	NODETYPE data;
	TreeNode* rightPtr;
};

template<class NODETYPE>
TreeNode<NODETYPE>::TreeNode(const NODETYPE& d)
{
	data = d;
	leftPtr = rightPtr = nullptr;
}

template<class NODETYPE>
NODETYPE TreeNode<NODETYPE>::getData() const { return data; }

#endif // !TREENODE_H
