#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "../Practica 1/PRA_2324_P1/ListLinked.h"  // ¡¡¡¡MODIFICAR!!!!

using namespace std;

template <typename V>
class HashTable: public Dict<V> {

    private:
	int n;
	int max;
	ListLinked<TableEntry<V>>* table;

	int h(std::string key){
	   int sumAsc = 0;
	   for(int i=0; i<key.size(); i++){
	      char c = key.at(i);
	      sumAsc += int(c);
	   }	   
	   return sumAsc%max;
	}

    public:
    void insert(std::string key, V value) override{
	   int pos = h(key);
      	   //TableEntry<V> aux(key, value);
       TableEntry<V> *aux = new TableEntry<V>(key, value);

	   if(table[pos].search(*aux) == -1){

	       table[pos].prepend(*aux);  // prepend
		   n++;
	   }
	   else{
	      throw runtime_error("Ya existe esta clave");
	   }
	}

	V search(std::string key) override{
	   int pos = h(key);
           TableEntry<V> aux(key);
	   int posL = table[pos].search(aux);
	   if(posL == -1){
	      throw runtime_error("No existe esta clave");
	   }
	   else{
	      return table[pos].get(posL).value;
	   }

	}

	V remove(std::string key) override{
	   int pos = h(key);
           TableEntry<V> aux(key);
   	   int posL = table[pos].search(aux);
           if(posL == -1){
              throw runtime_error("No existe esta clave");
           }
           else{
	      n--;
              return table[pos].remove(posL).value;
           }
	}
	
	int entries() override{
	   return n;
	}

	HashTable(int size){
	   table  = new ListLinked<TableEntry<V>>[size];
	   n = 0;
	   max = size;
	}

	~HashTable(){
	   delete[] table;
	}

	int capacity(){
	   return max;
	}

	friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
	   out << "HashTable: [Entries: " << th.n << ", " << "Capacity: " << th.max << "]\n";
	   
	   for(int i=0; i<th.max; i++){
	      out << "Cubeta " << i << "==>" << th.table[i] << endl << endl;
	   }
	   out << endl << endl;
	   return out;
	}

	V operator[](std::string key){
	   return search(key);
	}
        
};

#endif
