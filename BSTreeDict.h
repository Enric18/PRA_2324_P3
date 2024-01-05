#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
	BSTree<TableEntry<V>>* tree;

    public:
	
	void insert(std::string key, V value) override{
	   TableEntry<V> aux = TableEntry<V>(key, value);
           tree->insert(aux);
	}

	V search(std::string key) override{
	   TableEntry<V> aux = TableEntry<V>(key);	   
	   return (tree->search(aux)).value; 
	}

	V remove(std::string key) override{
	   V temp = search(key);

  	   TableEntry<V> aux = TableEntry<V>(key, temp);
	   tree->remove(aux);
	   
	   return temp;
	}

	int entries() override{
	   return tree->size();
	}

	BSTreeDict(){
	   tree = new BSTree<TableEntry<V>>;
	}

	~BSTreeDict(){
	   delete tree;
	}

	friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
	   return out << *(bs.tree);	   
	}

	V operator[](std::string key){
	   return search(key);
	}
};

#endif
