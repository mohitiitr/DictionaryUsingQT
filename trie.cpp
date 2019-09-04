
/**
*@file trie.cpp
*@brief this cpp file contains implementations to the functions defined(declared) in the trie.h
*
*@author MOhit KUmar
*
*@date 03/09/19
*/
#include "trie.h"



/**
*This method will be used to create a new node
*@author MOHIT KUMAR
*@date 03/09/19
*/
Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->meaning = "";

    return node;
}

/**
*This method will be used to insrt a node in the trie data structure
*@param Trie*& head             the root of the trie data structure
*@param string str              the string to be inserted
*@param string mean             the meaning of the word
*@author MOHIT KUMAR
*@date 03/09/19
*/
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

/**
*This method will be used to search a node in the trie data structure and return its corresponding meaning
*@param Trie*& head             the root of the trie data structure
*@param string str              the string to be searched in the trie data structure
*@author MOHIT KUMAR
*@date 03/09/19
*/
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



/**
*This method will be used to load the dictionary in the trie data structure
*@param Trie*& head             the root of the trie data structure
*@author MOHIT KUMAR
*@date 03/09/19
*/
void loadDataInTrie(Trie*& head) {

    qCritical()<< "C++ Style Info Message";

//    ifstream file ( "/home/maharaja40/QtProjects/Dictionary/input_file.csv" );
    ifstream file ( "input_file.csv" );

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
