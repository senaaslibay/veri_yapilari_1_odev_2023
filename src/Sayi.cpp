#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.cpp"

class Sayi
{
private:
    Basamak *head;
    int size;

    Basamak *FindPrevByPosition(int position)
    {
        if (position < 0 || position > size)
            throw "Index out of range";
        int index = 1;
        for (Basamak *itr = head; itr != NULL; itr = itr->next, index++)
        {
            if (position == index)
                return itr;
        }
        return NULL;
    }

public:
    Sayi()
    {
        head = NULL;
        size = 0;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    int count() const
    {
        return size;
    }
    const char &first()
    {
        if (isEmpty())
            throw "Empty List";
        return head->item;
    }
    const char &last()
    {
        if (isEmpty())
            throw "Empty List";
        return FindPrevByPosition(size)->item;
    }

    string getSayi(){
        int index = 0;
        string sayi = "";
        for (Basamak *itr = head; itr != NULL; itr = itr->next, index++)
        {
            if (size == index) return sayi;
            sayi = sayi + itr->item;
            
        }
    }

    void add(char &item)
    {
        insert(size, item);
    }

    void insert(int index, char &item)
    {
        if (index == 0)
            head = new Basamak(item, head); // listenin başına ekledik
        else
        {
            Basamak *prev = FindPrevByPosition(index);
            prev->next = new Basamak(item, prev->next);
        }
        size++;
    }

    void remove(char &item)
    {
        int index = indexOf(item);
        removeAt(index);
    }

    void removeAt(int index)
    {
        if (size == 0)
            throw "Empty List";
        Basamak *del;
        if (index == 0)
        {
            del = head;
            head = head->next;
        }
        else
        {
            Basamak *prev = FindPrevByPosition(index);
            del = prev->next;
            prev->next = prev->next->next;
        };
        delete del;
        size--;
    }

    int indexOf(char &item)
    {
        int index = 0;
        for (Basamak *itr = head; itr != NULL; itr = itr->next, index++)
        {
            if (itr->item == item)
                return index;
        }
        throw "Index out of range";
    }

    bool find(char &item)
    {
        for (Basamak *itr = head; itr != NULL; itr = itr->next)
        {
            if (itr->item == item)
                return true;
        }
        return false;
    }

    friend ostream &operator<<(ostream &screen, Sayi &right)
    {
        if (right.isEmpty())
            screen << "Empty list";
        else
        {

            screen << "########## ";
            for (Basamak *itr = right.head; itr != NULL; itr = itr->next)
            {
                screen << "******** ";

            }
            screen<<"\n";

            screen<<"#"<<&right<<"# ";

            for (Basamak *itr = right.head; itr != NULL; itr = itr->next)
            {
                screen << "*    " << itr << " *";

            }
            screen<<"\n";
            screen<<"#--------# ";

            for (Basamak *itr = right.head; itr != NULL; itr = itr->next)
            {
                screen << "******** ";

            }
            screen<<"\n";
            screen<<"#   "<<right.getSayi()<<"# ";

            for (Basamak *itr = right.head; itr != NULL; itr = itr->next)
            {
                screen << "*    " << itr->item << " * ";

            }
            screen<<"\n";
            screen << "########## ";

            for (Basamak *itr = right.head; itr != NULL; itr = itr->next)
            {
                screen << "******** ";

            }
            screen<<"\n";








                
                
                
                
        }
        return screen;
    }
    void clear()
    {
        while (!isEmpty())
            removeAt(0);
    }

    ~Sayi()
    {
        clear();
    }
};

#endif