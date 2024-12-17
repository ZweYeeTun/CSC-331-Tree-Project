#include <iostream>
#include <fstream>
using namespace std;

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <class T>
struct node
{
   T info;
   node *left;
   node *right;
};

template <class T>
class BSTree
{
   private:
      node<T> *root;
      
      void destroy (node<T> *&);
      void preOrder (node<T> *);
      void inOrder (node<T> *);
      void postOrder (node<T> *);
      void copy ( node<T> *&, node<T> * );

   public:
      BSTree();
      ~BSTree();
      BSTree (const BSTree<T> &);
      const BSTree<T> & operator= (const BSTree<T> &);
      void destroy();   
      bool isEmpty();
      bool searchItem (T);
      void preOrder ();
      void inOrder();
      void postOrder();
      void insertItem (T);  
      void deleteItem (T item );
      void deleteItem (node<T> *&, T );
      void deleteNode (node<T> *&  );      
};

#endif