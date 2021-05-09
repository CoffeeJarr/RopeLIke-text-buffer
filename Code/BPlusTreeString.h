#ifndef BPLUSTREESTRING_H
#define BPLUSTREESTRING_H

#include <cstring>
#include "BPlusNnode.h"
using namespace std;

class BPlusTreeString{
public:
	BPlusTreeString();
	// load 100Mb file of text
	BPlusTreeString(const string& filename);
	~BPlusTreeString();
	// get the kth byte
	char getByte(const int& position) const;
	// get a string from byte m to n
	string getString(const int& m, const int& n) const;
	// replace a string from byte m to n
	void replaceString(const int& m, const int & n);
	// inserting 1 byte in the middle of the file (offset=50 million for example)
	void insertOneByte(const char& c, const int& position);
	// inserting 10 bytes, 100 bytes, 1k bytes 10k bytes (normal string)
	void insertString(const string& str, const int& position);
	// inserting 10 bytes, 100 bytes, 1k bytes 10k bytes (ropelike)
	void insertString(const BPlusTreeString& filename, const int& position);
	// appending to end of file 1, 10, 100, 1k, 10k bytes.(normal string)
	void endAdd(const string& str);
	// appending to end of file 1, 10, 100, 1k, 10k bytes.(ropelike)
	void endAdd(const BPlusTreeString& filename);
	// deleting 1, 10, 100, 1k, 10k bytes and the entire file.(normal string)
	void remove(const int& position, const int& k); 
	// saving the entire text to a file
	void output() const;

private:
	int totalBytes; // total number of bytes
	interNode* rootNode;
	leafNode* start;
	leafNode* finish;
};

#endif
