#include "BPlusNode.h"

// remove the key and the Corresponding pointer
void interNode::remove(int keyIndexFrom, int keyIndexTo){
	int afterToNum = getCurNum() - keyIndexTo - 1;
	int limit = min(afterToNum + keyIndexFrom - 1, keyIndexTo);
	for(int i = keyIndexFrom; i <= limit; ++i){
		setKeyValue(i, getKeyValue(keyIndexTo + 1));
		setChild(i, getChild(keyIndexTo + 1));
	}
}

// insert a key into the node
void interNode::insert(int targetPosition, BPlusNode* childNode){
	int tempNum = getCurKeyNum();
	if (targetPosition == tempNum){
		setKeyValue(targetPosition, childNode.getTotalWeight());
		setChild(targetPosition, childNode);
	}
	else{
		for (int i = getCurKeyNum(); i > targetPosition; --i){
			setKeyValue(i, getKeyValue(i - 1));
			setChild(i, getChild(i - 1));
		}
		setKeyValue(targetPosition, childNode.getTotalWeight());
		setChild(targetPosition, childNode);
	}
	setTotalWeight(getTotalWeight() + childNode.getTotalWeight());
	setCurKeyNum(getCurKeyNum() + 1); // add the curren number of keys 

}

// 
void interNode::split(){
	
}
