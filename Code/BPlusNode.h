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
	void setIndexParent(int i) {setIndexParent = i;}

	void setPreNode(BPlusNode* newPre) {preNode = newPre;}
	void setNextNode(BPlusNode* newNext) {nextNode = newNext;}

	BPlusNode* getPreNode() const {return preNode;}
	BPlusNode* getNextNode() const {return nextNode;}

	bool fullKeyCheck(){return curKeyNum == degree;}

	int search(int k) const;
	// virtual function
	virtual void remove(int keyIndexFrom, int keyIndexTo) = 0;   // remove the specific key
	virtual void insert(int targetPosition, BPlusNode* childNode) = 0;
	virtual void split() = 0;
	virtual void merge(BPlusNode* mergeNode) = 0;
	virtual void clear() = 0;   // remove the whole node and the subtree
	virtual void borrow(BPlusNode* brotherNode, int left, int num) = 0; 


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
	
	virtual void remove(int keyIndexFrom, int keyIndexTo);   // remove the specific key
	virtual void insert(int targetPosition, BPlusNode* childNode);
	virtual void split();
	virtual void merge(interNode* mergeNode);
	virtual void clear();   // remove the whole node and the subtree
	virtual void borrow(interNode* brotherNode, int left, int num); 

	
};

// for leaf node in the B+ tree
class leafNode : public BPlusNode
{
private:
	string datas[degree]; // leaf node saves the real data: each one line of the text file

public:
	leafNode();
	virtual ~leafNode();

	void setData(int i, string& data) {datas[i] = data;}
	string getData(int i) const {return datas[i];}

	virtual void remove(int keyIndexFrom, int keyIndexTo);
	virtual void insert(int targetPosition, string& childString);
	virtual void split();
	virtual void merge(leafNode* mergeNode);
	virtual void clear();
	virtual void borrow(leafNode* brotherNode, int left, int num);
	// find the kth string is full or not
	bool fullStringCheck(int k){
		return getKeyValue(k) == 1024;
	}
	
};


#endif
