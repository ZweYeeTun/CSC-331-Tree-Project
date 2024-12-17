#include <iostream>
#include <fstream>
using namespace std;

#ifndef BSTREE_H
#define BSTREE_H

template <class T>
struct node
{
   T info;
   node *left;
   node *right;
int count;
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
          int countNodes(node<T> *p);

    void printOverusedWordsHelper(node<T> *p, int threshold, ofstream &out);
    void printIndexHelper(node<T> *p, ofstream &out, char &currentLetter);

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
       int countUniqueWords();
    void printOverusedWords(int threshold, ofstream &out);
    void printIndex(ofstream &out);
};

#endif