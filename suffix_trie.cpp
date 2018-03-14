#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int cou=0; 
#define MAX_CHAR 256
 
// A Suffix Trie (A Trie of all suffixes) Node
class SuffixTrieNode
{
private:
    SuffixTrieNode *children[MAX_CHAR];
    list<int> *indexes;
public:
    SuffixTrieNode() // Constructor
    {
        // Create an empty linked list for indexes of
        // suffixes starting from this node
        indexes = new list<int>;
 
        // Initialize all child pointers as NULL
        for (int i = 0; i < MAX_CHAR; i++)
          children[i] = NULL;
    }
 
    // A recursive function to insert a suffix of the txt
    // in subtree rooted with this node
    void insertSuffix(string suffix, int index);
 
    // A function to search a pattern in subtree rooted
    // with this node.The function returns pointer to a linked
    // list containing all indexes where pattern is present.
    // The returned indexes are indexes of last characters
    // of matched text.
    list<int>* search(string pat);
};
 
// A Trie of all suffixes
class SuffixTrie
{
private:
    SuffixTrieNode root;
public:
    // Constructor (Builds a trie of suffies of the given text)
    SuffixTrie(string txt)
    {
        // Consider all suffixes of given string and insert
        // them into the Suffix Trie using recursive function
        // insertSuffix() in SuffixTrieNode class
        for (int i = 0; i < txt.length(); i++)
            root.insertSuffix(txt.substr(i), i);
    }
 
    // Function to searches a pattern in this suffix trie.
    void search(string pat);
};
 
// A recursive function to insert a suffix of the txt in
// subtree rooted with this node
void SuffixTrieNode::insertSuffix(string s, int index)
{
    // Store index in linked list
    indexes->push_back(index);
 
    // If string has more characters
    if (s.length() > 0)
    {
        // Find the first character
        char cIndex = s.at(0);
 
        // If there is no edge for this character, add a new edge
        if (children[cIndex] == NULL)
            children[cIndex] = new SuffixTrieNode();
 
        // Recur for next suffix
        children[cIndex]->insertSuffix(s.substr(1), index+1);
    }
}
 
// A recursive function to search a pattern in subtree rooted with
// this node
list<int>* SuffixTrieNode::search(string s)
{
    // If all characters of pattern have been processed,
    if (s.length() == 0)
        return indexes;
 
    // if there is an edge from the current node of suffix trie,
    // follow the edge.
    if (children[s.at(0)] != NULL)
        return (children[s.at(0)])->search(s.substr(1));
 
    // If there is no edge, pattern doesn’t exist in text
    else return NULL;
}
 
/* Prints all occurrences of pat in the Suffix Trie S (built for text)*/
void SuffixTrie::search(string pat)
{
    // Let us call recursive search function for root of Trie.
    // We get a list of all indexes (where pat is present in text) in
    // variable 'result'
    list<int> *result = root.search(pat);
 
    // Check if the list of indexes is empty or not
    if (result == NULL)
        cout << "Pattern not found" << endl;
    else
    {
       list<int>::iterator i;
       int patLen = pat.length();
       for (i = result->begin(); i != result->end(); ++i)
         //cout << "Pattern found at position " << *i - patLen<< endl;
       	cou++;
    }
}
 
 
// Driver program to test above function
int main()
{
    char txt[20000];
    //scanf("%s",&txt);
    std::ifstream file;
    file.open("inputtext.txt");
    //file>>txt;
    file.getline(txt,19999);
    file.close();

    SuffixTrie S(txt);
    //printf("100%s100\n",txt );
    //char *pat = "ABABAAABAB";
    //char *pat ="learning";
    char pat[30];

    file.open("pat.txt");
    while(file.getline(pat,29))
    {
    clock_t begin = clock();
    S.search(pat);
    clock_t end = clock();
    double elapsed_secs = double(end - begin)*1000 / CLOCKS_PER_SEC;
    //cout<<txt<<endl;
    cout<<"Number of matches of \""<<pat<<"\" is "<<cou<<endl<<"Time taken:"<<elapsed_secs<<endl;
    cou=0;
    }
   file.close();
    
    return 0;
}