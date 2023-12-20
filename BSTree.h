#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"
using namespace std;

template <typename T> 
class BSTree {
    private:
       int nelem;
       BSNode<T> *root;

       BSNode<T>* search(BSNode<T>* n, T e) const{
	  if(n == nullptr){
	     throw runtime_error("Elemento no encontrado");
	  }
	  else if(n.elem < e){
	     return search(n.right, e);
	  }
	  else if(n.elem > e){
	     return search(n.left, e);
	  }
	  else{
	     return n;
	  }
       }



    public:
       BSTree(){
	  nelem=0;
	  root = nullptr;	  
       }
       
       int size() const{
	  return nelem;
       }

       T search(T e) const{
          return search(root, e).elem;
       }

       T operator[](T e) const{

       }
};

#endif
