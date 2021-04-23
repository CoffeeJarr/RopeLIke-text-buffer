#ifndef BPLUSTREESTRING_H
#define BPLUSTREESTRING_H

#include "BPlusNnode.h"
using namespace std;

class BPlusTreeString{
public:
	BPlusTreeString();
	BPlusTreeString(const string& filename); // load 100Mb file of text
	~BPlusTreeString();
	char getByte(const int& position) const; // get the kth byte
	string getString(const int& m, const int& n) const; // get a string from byte m to n
	void replaceString(const int& m, const int & n); // replace a string from byte m to n
	void insertOneByte(const char& c, const int& position); // inserting 1 byte in the middle of the file (offset=50 million for example)
	void insertString(const string& str, const int& position); // inserting 10 bytes, 100 bytes, 1k bytes 10k bytes (normal string)
	void insertString(const BPlusTreeString& filename, const int& position); // inserting 10 bytes, 100 bytes, 1k bytes 10k bytes (ropelike)
	void endAdd(const string& str); // appending to end of file 1, 10, 100, 1k, 10k bytes.(normal string)
	void endAdd(const BPlusTreeString& filename); // appending to end of file 1, 10, 100, 1k, 10k bytes.(ropelike)
	void remove(const int& position, const int& k); // deleting 1, 10, 100, 1k, 10k bytes and the entire file.(normal string)
	void output() const; // saving the entire text to a file

private:
	int numBytes; // total number of bytes
	interNode* baseNode;
	leafNode* start;
	leafNode* finish;
};

BPlusTreeString::BPlusTreeString(const string& filename) {}


#endif
