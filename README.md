# RopeLIke-text-buffer
Final project of 593A in SIT

### Source code reference citing
string in c++: http://www.cplusplus.com/reference/string/basic_string/  
bplustree: https://github.com/zcbenz/BPlusTree

### Introduction 
Rope is a tree-structure that holds text in order to insert into large strings faster than a string. It allows for operations like insertion, deletion, search and random access to be executed faster and much more efficiently in comparison to a traditional String. This Rope can be designed as a B+ tree, which can be very useful to store and modify the strings in file.
### Abstract
The rope is a tree-structure that holds text in order to insert into large strings faster than a string. It allows for operations like insertion, deletion, search and random access to be executed faster and much more efficiently in comparison to a traditional String.  
This Rope can be designed as a B+ tree, which can be very useful to store and modify the strings in the file. Create a tree with degree k. We will try k=2, k=4, k=16. For example, with degree 4, each node has 4 children. At the lowest level, the nodes contain 4 strings, each of which is a string for a line.  
The preliminary idea is to diverge the storage structure from the text file into a B+ tree to meet the inserting, reading, and replacement operations between the specified indexes. Each key-value stores the weight of the sub-node, and the weight means the number of the total characters in the sub-node. The node inside the B+ tree can be designed as two kinds: interNode and leafNode.