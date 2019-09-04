#ifndef TRIE_H
#define TRIE_H

/**
*@file trie.h
*@brief this header file contains definations(declarations) for the functions to be used in the main programm
*
*@author MOhit KUmar
*
*@date 03/09/19
*/

#include <QDebug>
#include <bits/stdc++.h>

using namespace std ;



/**
*structure of the trie node
*@author MOHIT KUMAR
*@date 03/09/19
*/
struct Trie
{
    //stores the meaning of the word
    string meaning;

    // each node stores a map to its child nodes
    unordered_map<char, Trie*> map;
};


/**
*This method will be used to create a new node
*@author MOHIT KUMAR
*@date 03/09/19
*/
Trie* getNewTrieNode();



/**
*This method will be used to insrt a node in the trie data structure
*@param Trie*& head             the root of the trie data structure
*@param string str              the string to be inserted
*@param string mean             the meaning of the word
*@author MOHIT KUMAR
*@date 03/09/19
*/
void insert(Trie*& head, string str ,string mean);

/**
*This method will be used to search a node in the trie data structure and return its corresponding meaning
*@param Trie*& head             the root of the trie data structure
*@param string str              the string to be searched in the trie data structure
*@author MOHIT KUMAR
*@date 03/09/19
*/
string search(Trie* head, string str);

/**
*This method will be used to load the dictionary in the trie data structure
*@param Trie*& head             the root of the trie data structure
*@author MOHIT KUMAR
*@date 03/09/19
*/
void loadDataInTrie(Trie*& head) ;


#endif // TRIE_H
