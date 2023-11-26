#include <iostream>
#include <fstream>
#include <cstdlib>
#include <typeinfo>

#include "Sayi.cpp"
#include "SayilarListesi.cpp"

using namespace std;

int main(void)
{
    fstream sayilar("Sayilar.txt");

    if (sayilar.is_open())
    {
        string tp;
        SayilarListesi *sayilarListesi = new SayilarListesi();
        while (getline(sayilar, tp, ' '))
        {
            Sayi *sayi = new Sayi();
            for(int i=0; i<tp.size(); i++){
                sayi->add(tp.at(i));
            };
            sayilarListesi->add(sayi);

        }
        cout << *sayilarListesi <<"\n" ;

        sayilar.close();
    }
    return 0;
}