#ifndef HASH_H_
#define HASH_H_
#include"Heads.hpp"
#include<cmath>
#define SLOTS 4096 //number of SLOTS

//hash function
int hash(int val){
    return (int)std::ceil(SLOTS*(((int)(val*0.618033))%1));
}
#endif
