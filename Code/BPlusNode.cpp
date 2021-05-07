#include "BPlusNode.h"

// remove the key and the pointer to corresponding children
void interNode::remove(int keyIndexFrom, int keyIndexTo){
	// update the total weight of the node
	int deleteWeight = 0;
	for (int i = keyIndexFrom; i <= keyIndexTo; ++i){
		deleteWeight += getKeyValue(i);
	}
	setTotalWeight(getTotalWeight() - deleteWeight);

	// copy the latter keys 
	int afterToNum = getCurNum() - keyIndexTo - 1;
	int limit = min(afterToNum + keyIndexFrom - 1, keyIndexTo);
	for(int i = keyIndexFrom; i <= limit; ++i){
		setKeyValue(i, getKeyValue(keyIndexTo + 1));
		setChild(i, getChild(keyIndexTo + 1));
	}
	// update the current size of keys 
	setCurKeyNum(getCurKeyNum() - (keyIndexTo - keyIndexFrom));
}

// insert a key into the node
void interNode::insert(int targetPosition, BPlusNode* childNode){
	int tempNum = getCurKeyNum();
	// if the new key should be the end of the keys
	if (targetPosition == tempNum){
		setKeyValue(targetPosition, childNode->getTotalWeight());
		setChild(targetPosition, childNode);
	}
	else{
		// the new key is in the middle or start of the keys
		for (int i = getCurKeyNum(); i > targetPosition; --i){
			setKeyValue(i, getKeyValue(i - 1));
			setChild(i, getChild(i - 1));
		}
		setKeyValue(targetPosition, childNode->getTotalWeight());
		setChild(targetPosition, childNode);
	}
	// update the total weight
	setTotalWeight(getTotalWeight() + childNode->getTotalWeight());
	// update the size of keys
	setCurKeyNum(getCurKeyNum() + 1);
	// set the childnode's index 
	childnode->setIndexParent(targetPosition); 
}

// 
void interNode::split(){
	interNode* newNode = new interNode();
	int leftNum = getCurKeyNum() / 2 + 1;
	int rightNum = getCurKeyNum() - leftNum;
	// update the new right node's size
	newNode->setCurKeyNum(rightNum);

	// copy the right part to the new node
	int newTotalWeight = 0;
	for (int i = 0; i < rightNum; ++i){
		newNode->keys[i] = getKeyValue(leftNum + i);
		newNode->childs[i] = getChild(leftNum + i);
		newTotalWeight += newNode->keys[i];
	}
	// remove the splited keys in the old left node
	remove(leftNum, getCurKeyNum() - 1);
	// update the total weight of new right node
	newNode->setTotalWeight(newTotalWeight);
	// set the parent pointer for new right node
	interNode* parentNode = getParent();
	parentNode->insert(getIndexParent() + 1, newNode);
	// update the preNode and the nextNode pointers
	newNode->setPreNode(this);
	newNode->setNextNode(getNextNode());
	setNextNode(newNode);
}
