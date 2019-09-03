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


Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->meaning = "";

    return node;
}

void insert(Trie*& head, string str ,string mean)
{
    if (head == nullptr)
        head = getNewTrieNode();

    // start from root node
    Trie* curr = head;
    string::iterator it = str.begin();
    while (it != str.end())
    {
        // create a new node if path doesn't exists
        if (curr->map.find(*it) == curr->map.end())
            curr->map[*it] = getNewTrieNode();

        // go to next node
        curr = curr->map[*it];

        // move to next character
        it++;
    }

    // store the meaning in the current node
    curr->meaning = mean;

}


string search(Trie* head, string str)
{
    // return false if Trie is empty
    if (head == nullptr)
        return "";

    Trie* curr = head;

    string::iterator it =str.begin();
    while (it != str.end())
    {
        // go to next node
        curr = curr->map[*it];

        // if string is invalid (reached end of path in Trie)
        if (curr == nullptr)
            return "";

        // move to next character
        it++;
    }

    // if current node is the final node where we wanted to retirve the data
    return curr->meaning;
}



void loadDataInTrie(Trie*& head) {

    qCritical()<< "C++ Style Info Message";

    ifstream file ( "/home/maharaja40/QtProjects/Dictionary/input_file.csv" );

    qCritical()<< "C++ Style Info Message";

    string value;

    qCritical()<<file.good();

    while ( file.good() )
    {
         qCritical()<< "C++ Style Info Message";

         getline ( file, value, '\n' );

         size_t pos = value.find(",");
         transform(value.begin(), value.end(), value.begin(), ::tolower);
         qDebug()<<pos;

         string str = value.substr(0,pos);
         string meaning  = value.substr(pos+1);

         insert(head , str , meaning);

    }
}



#endif // TRIE_H
