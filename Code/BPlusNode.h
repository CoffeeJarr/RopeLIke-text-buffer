#ifndef BPlusNode_H
#define BPlusNode_H

// base class of Node
class BPlusNode
{
public:
	BPlusNode();
	virtual ~BPlusNode();

	void setDegree(int _degree) {degree = _degree;}

	void setCurKeyNum(int newNum) {curKeyNum = newNum;}
	int getCurKeyNum() const {return curKeyNum;}

	void setKeyValue(int i, int keyValue) {keys[i] = keyValue;}
	int getKeyValue(int i) const {return keys[i];}

	void setTotalWeight(int newTotalWeight) {totalWeight = newTotalWeight;}
	int getTotalWeight() {return totalWeight;}

	BPlusNode* getParent() const {return parent;}
	int getIndexParent() const {return indexInParent;}

	void setParent(BPlusNode* newParent) {parent = newParent;}
	void setIndexParent()

	bool fullKeyCheck(){}

	// virtual function
	virtual void remove(int keyIndexFrom, int keyIndexTo) = 0;   // remove the specific key
	virtual void split() = 0;
	virtual void merge() = 0;
	virtual void clear() = 0;   // remove the whole node and the subtree
	virtual void borrow() = 0;


protected:
	int degree;
	int curKeyNum;  // current key numbers
	int *keys;
	int totalWeight;
	int indexInParent;
	BPlusNode *preNode;
	BPlusNode *nextNode;
	BPlusNode *parent;
	
};

// for inter node in the B+ tree
class interNode : public BPlusNode
{
private:

	BPlusNode **childs;

public:
	interNode();
	virtual ~interNode();

	void setChild(int i, BPlusNode* child) {childs[i] = child;}
	BPlusNode* getChild(int i) const {return childs[i];}
	

	virtual void remove(int keyIndex) = 0;   // remove the specific key
	virtual void split() = 0;
	virtual void merge() = 0;
	virtual void clear() = 0;   // remove the whole node
	virtual void borrow() = 0;
	
};

// for leaf node in the B+ tree
class leafNode : public BPlusNode
{
private:
	string data[degree]; // leaf node saves the real data: each one line of the text file

public:
	leafNode();
	virtual ~leafNode();
	virtual void remove(int keyIndex) = 0;   // remove the specific key
	virtual void split() = 0;
	virtual void merge() = 0;
	virtual void clear() = 0;   // remove the whole node
	virtual void borrow() = 0;
	bool fullLineCheck(){} 
	
};


#endif


