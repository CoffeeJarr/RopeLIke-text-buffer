#ifndef BPlusNode_H
#define BPlusNode_H

// base class of Node
class BPlusNode
{
public:
	BPlusNode();
	virtual ~BPlusNode();
private:
	int size;
	
};

// for inter node in the B+ tree
class interNode : public BPlusNode
{
public:
	interNode();
	virtual ~interNode();
	
};

// for leaf node in the B+ tree
class leafNode : public BPlusNode
{
public:
	leafNode();
	virtual ~leafNode();
	
};


#endif
