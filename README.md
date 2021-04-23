# RopeLIke-text-buffer
Final project of 593A in SIT

### Source code reference citing
string in c++: http://www.cplusplus.com/reference/string/basic_string/  
bplustree: https://github.com/zcbenz/BPlusTree
# Abstract
The rope is a tree-structure that holds text in order to insert into large strings faster than a string. It allows for operations like insertion, deletion, search and random access to be executed faster and much more efficiently in comparison to a traditional String. This Rope can be designed as a B+ tree, which can be very useful to store and modify the strings in the file. Create a tree with degree k. We will try k=2, k=4, k=16. For example, with degree 4, each node has 4 children. At the lowest level, the nodes contain 4 strings, each of which is a string for a line. The preliminary idea is to diverge the storage structure from the rope into a B+ tree to meet the inserting, reading, and replacement operations between the specified indexes. The index position of the first character of each string in the text is regarded as the key value of the node where the string is located. The internal nodes of the B+ tree do not store data but are only used for indexing, and all strings are stored in the leaf nodes. Each leaf node stores pointers to adjacent leaf nodes and the leaf nodes themselves are linked in order of the size of the key from small to large. When a string is inserted, the index position of the string in the following text will be changed, which causes an offset, and the index position of the following node needs to be modified.

Ropes: an Alternative to Strings hans-j. boehm, russ atkinson and michael plass Xerox PARC, 3333 Coyote Hill Rd., Palo Alto, CA 94304, U.S.A
https://citeseer.ist.psu.edu/viewdoc/download?doi=10.1.1.14.9450&rep=rep1&type=pdf

Rope Data Structure
https://medium.com/underrated-data-structures-and-algorithms/rope-data-structure-e623d7862137

Introduction of B+ Tree
https://www.geeksforgeeks.org/introduction-of-b-tree/

Data Structures for Text Sequences Charles Crowley University of New Mexico 
https://www.cs.unm.edu/~crowley/papers/sds.pdf
