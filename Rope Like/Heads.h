#ifndef HEADS_H_
#define HEADS_H_
// Cpp Head file
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<list>
#include<functional>

//C head file
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdbool>
#include <ctime>


// Rope Node data field
struct Data{
    std::list<std::pair<int,char>> value; 
    int index;
    Data()=default;
    Data(Data& d){
        this->value = d.value;
        this->index = d.index;
    }
    Data& operator=(const Data& d){
        this->value=d.value;
        this->index = d.index;
        return *this;
    }
    ~Data()=default;
};


#endif
