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

       BSNode<T>* insert(BSNode<T>* n, T e){
	  if(n == nullptr){
	     return new Node(e);
	  }
	  else if(n.elem == e){
	     throw runtime_error("Elemento ya existe");
	  }
	  else if(n.elem < e){
	     n.right = insert(n.right, e);
	  }
	  else{
	     n.left = insert(n.left, e);
	  }
          return n;
       }

       void print_inorden(std::ostream &out, BSNode<T>* n) const{
	  if(n != nullptr){
	     print_inorden(out, n.left());
		 out << n.elem;
		 print_inorden(out, n.right());
		}
	}


    public:
       BSTree(){
	  nelem = 0;
	  root = nullptr;	  
       }
       
       int size() const{
	  return nelem;
       }

       T search(T e) const{
          return search(root, e).elem;
       }

       T operator[](T e) const{
	  return search(e);
       }

       void insert(T e){
	  root = insert(root, e);
       }

       friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
	  out << 
       }


};

#endif
