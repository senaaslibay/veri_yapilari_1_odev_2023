#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP

#include <typeinfo>
#include "Sayi.cpp"
#include "Dugum.cpp"

class SayilarListesi{
    private:
        Dugum *head;
        int size;

        Dugum* FindPrevByPosition(int position){
            if(position<0 || position> size) throw "Index out of range";
            int index=1;
            for(Dugum *itr=head;itr!=NULL; itr=itr->next,index++){
                if(position == index) return itr; 
            }
            return NULL;
            
        }
    public:
        SayilarListesi(){
            head = NULL;
            size = 0;
        }

        bool isEmpty() const{
            return size == 0;
        }

        int count()const{
            return size;
        }
        const Sayi* first(){
            if(isEmpty()) throw "Empty List";
            return head->item;
        }
        const Sayi* last(){
            if(isEmpty()) throw "Empty List";
            return FindPrevByPosition(size)->item;

        }


        void add(Sayi* item){
            insert(size,item);
        }

        void insert(int index, Sayi* item){
            if(index == 0) head = new Dugum(item,head); //listenin başına ekledik
            else{
                Dugum *prev = FindPrevByPosition(index);
                prev->next = new Dugum(item,prev->next);
            }
            size++;
        }

        void remove(Sayi* item){
            int index = indexOf(item);
            removeAt(index);
        }

        void removeAt(int index){
            if(size == 0) throw "Empty List";
            Dugum *del;
            if(index == 0){
                del = head;
                head = head->next;
            }
            else{
                Dugum *prev = FindPrevByPosition(index);
                del = prev->next;
                prev->next = prev->next->next;

            };
            delete del;
            size--;
        }

        int indexOf(Sayi* item){
            int index = 0;
            for(Dugum *itr=head; itr!=NULL; itr=itr->next, index++){
                cout<< typeid(itr->item).name() ;
                if(itr->item == item) return index;
            }
            throw "Index out of range";
        }

        bool find(Sayi* item){
            for(Dugum *itr=head; itr!=NULL;itr=itr->next){
                if(itr->item == item) return true;
            }
            return false;
        }

		friend ostream& operator<<(ostream& screen, SayilarListesi &right){
			if(right.isEmpty()) screen<<"Empty list";
			else{
				for(Dugum *itr=right.head;itr!=NULL;itr=itr->next){
					screen<<*itr->item;
					
				}
                screen<<"1.Tek basamaklari Basa Al\n";
                screen<<"2.Basamaklari Tersle\n";
                screen<<"3.En Buyuk Cikar\n";
                screen<<"4.Cikis";
			}
			return screen;
		}
		void clear(){
			while(!isEmpty())
				removeAt(0);			
		}

		~SayilarListesi(){
			clear();
		}
};




#endif