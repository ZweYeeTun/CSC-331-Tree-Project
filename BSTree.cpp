#include "BSTree.h"

template <class T>
BSTree<T> :: BSTree ()
{
  root = NULL;
}

template <class T>
BSTree<T> :: ~BSTree ()
{
   destroy (root);
}

template <class T>
void BSTree<T> :: destroy ()
{   
   destroy (root);
}

template <class T>
void BSTree<T> :: destroy (node<T> *& p)
{   
   if ( p != NULL )
   {
      destroy (p->left);
      destroy (p->right);
      delete p;
      p = NULL;
   }
}

template <class T>
BSTree<T> :: BSTree (const BSTree<T> & other)
{
   copy (root, other );
}

template <class T>
const BSTree<T> &  BSTree<T> :: operator= (const BSTree<T> & other)
{
   if ( this != &other )  
   {
       if ( root != NULL )
          destroy (root);
       copy (root, other); 
   } 

}

template <class T>
void BSTree<T> :: copy (node<T> *& mroot, node<T> *croot )
{
   if ( croot == NULL )
      mroot = NULL;
   else
   {
      mroot = new node<T>;
      mroot->info = croot->info;
      copy (mroot->left, croot->left);
      copy (mroot->right, croot->right);
   }
}

template <class T>
bool BSTree<T> :: isEmpty ()
{
   return root == NULL;
} 

template <class T>
void BSTree<T> :: preOrder ()
{
   preOrder (root);
}

template <class T>
void BSTree<T> :: preOrder (node<T> *p )
{
   if ( p != NULL )
   {
      cout<<p->info<<" ";
      preOrder (p->left);
      preOrder (p->right);
   }
}

template <class T>
void BSTree<T> :: postOrder ()
{
   postOrder (root);
}

template <class T>
void BSTree<T> :: postOrder (node<T> *p )
{
   if ( p != NULL )
      {    
         postOrder (p->left);
         postOrder (p->right);
         cout<<p->info<<" ";
      }
}

template <class T>
void BSTree<T> :: inOrder ()
{
   inOrder (root);
}

template <class T>
void BSTree<T> :: inOrder (node<T> *p )
{ 
   if ( p != NULL )
      {    
         inOrder (p->left);
         cout<<p->info<<" ";
         inOrder (p->right);        
      }
}

template <class T>
void BSTree<T> :: insertItem (T item )
{
   node<T> *r = NULL;
   node<T> *p = root;

   while ( p != NULL )
      {
          r = p;
          if ( item < p->info )
             p = p->left;
          else if ( item > p->info )
             p = p->right;
          else
          {
             cout<<"NO DUPLICATES ALLOWED";
             return;        
          }        
      }

    p = new node<T>;
    p->info = item;
    p->left = NULL;
    p->right = NULL;

    if (root == NULL )
       root = p;
    else
    {
      if ( item > r->info )
         r->right = p;
      else r->left = p;
    }   
}

template <class T>
bool BSTree<T> :: searchItem (T item )
{
   node<T> *p = root;

   while ( p != NULL )
      {
         if ( p->info == item )
            return true;
         else if ( p->info > item )
            p = p->left;
         else
            p = p->right;
      }
   return false;
}

template <class T>
void BSTree<T> :: deleteItem (T item )
{
   deleteItem (root, item);
}

template <class T>
void BSTree<T> :: deleteItem (node<T> *&p, T item )
{
   if ( p == NULL )
   {
      cout<<"ITEM NOT IN TREE";
      return;
   }
   else if ( item < p->info )
      deleteItem (p->left, item);
   else if ( item > p->info )
      deleteItem (p->right, item);
   else 
      deleteNode (p);
}

template <class T>
void BSTree<T> :: deleteNode (node<T> *& p )
{
   node<T> *q;

   if ( p->left == NULL )
   {
      p = p->right;
      delete q;
   }
   else if ( p->right == NULL )
   {
      p = p->left;
      delete q;
   }
   else
   {
      node<T> *r = NULL;
      q = q->left;

      while (q->right != NULL)
         {
            r = q;
            q = q->right;
         }  

      p->info = q->info;

      if ( r == NULL )
         p = p->left;
      else
         r->right = q->left;

      delete q;
   }

}

template <class T>
int BSTree<T>::countUniqueWords() {
    return countNodes(root);
}

template <class T>
int BSTree<T>::countNodes(node<T> *p) {
    if (p == NULL) return 0;
    return 1 + countNodes(p->left) + countNodes(p->right);
}

template <class T>
void BSTree<T>::printOverusedWords(int threshold, ofstream &out) {
    printOverusedWordsHelper(root, threshold, out);
}

template <class T>
void BSTree<T>::printOverusedWordsHelper(node<T> *p, int threshold, ofstream &out) {
    if (p != NULL) {
        printOverusedWordsHelper(p->left, threshold, out);
        if (p->count > threshold) {
            out << p->info << " (" << p->count << " times)\n";
        }
        printOverusedWordsHelper(p->right, threshold, out);
    }
}

template <class T>
void BSTree<T>::printIndex(ofstream &out) {
    char currentLetter = '\0';
    printIndexHelper(root, out, currentLetter);
}

template <class T>
void BSTree<T>::printIndexHelper(node<T> *p, ofstream &out, char &currentLetter) {
    if (p != NULL) {
        printIndexHelper(p->left, out, currentLetter);

        // Check if the first letter of the word has changed
        if (p->info[0] != currentLetter) {
            currentLetter = p->info[0];
            out << "\n" << char(toupper(currentLetter)) << "\n";  // Print the new letter heading
        }

        out << p->info << "\n";  // Print the word
        printIndexHelper(p->right, out, currentLetter);
    }
}


