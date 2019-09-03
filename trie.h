#ifndef TRIE_H
#define TRIE_H


#include <QDebug>
#include <bits/stdc++.h>

using namespace std ;

struct Trie
{
    //stores the meaning of the word
    string meaning;

    // each node stores a map to its child nodes
    unordered_map<char, Trie*> map;
};


Trie* getNewTrieNode();

void insert(Trie*& head, string str ,string mean);


string search(Trie* head, string str);


void loadDataInTrie(Trie*& head) ;


#endif // TRIE_H
