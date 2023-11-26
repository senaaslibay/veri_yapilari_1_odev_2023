#ifndef DUGUM_HPP
#define DUGUM_HPP


#include "Sayi.cpp"

#include <iostream>
using namespace std;

struct Dugum{
    public:
        Sayi *item;
        Dugum *next;

        Dugum(Sayi *item, Dugum *next=NULL){
            this->item = item;
            this->next = next;
        }
};

#endif