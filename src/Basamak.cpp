#ifndef BASAMAK_HPP
#define BASAMAK_HPP

#include <iostream>
using namespace std;

struct Basamak{
    public:
        char item;
        Basamak *next;

        Basamak(char& item, Basamak *next=NULL){
            this->item = item;
            this->next = next;
        }
};

#endif