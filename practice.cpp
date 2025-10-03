#include <iostream>
using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch)
        {
            data = ch;
            for(int i=0; i<26; i++)
                children[i] = NULL;
            isTerminal = false;
        }
};

class Trie
{
    public:
        TrieNode* root;

        Trie()
        {
            root = new TrieNode('\0');
        }

        void insertWordUtil(TrieNode* root, string word)
        {
            // base condition
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            // * getting index of character from 1-26 characters
            // * assuming all characters are in CAPS.
            int index = word[0] - 'A';
            TrieNode* child;

            // * present case
            if (root->children[index] != NULL) {
                child = root->children[index];
            } else {
                // * absent case
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            
            insertWordUtil(child, word.substr(1));
        }

        void insertWord(string word)
        {
            insertWordUtil(root, word);
        }

        void deleteWord(string word)
        {
            bool search = searchWord(word);
            if (search)
            {
                deleteWordUtil(root, word);
                cout << "Word: " << word << " deleted from Trie Tree" << endl;
            }
            else 
            {
                cout << "Word: " << word << " not found in Trie Tree." << endl;
            }
        }

        void deleteWordUtil(TrieNode* root, string word)
        {
            if (word.length() == 0 && root->isTerminal == true) {
                root->isTerminal = false;
                return;
            }

            if (word.length() == 0) return;

            // * getting index of character from 1-26 characters
            // * assuming all characters are in CAPS.
            int index = word[0] - 'A';
            TrieNode* child;

            // * present case
            if (root->children[index] != NULL) {
                child = root->children[index];
                deleteWordUtil(child, word.substr(1));
            }
        }

        bool searchWordUtil(TrieNode* root, string word)
        {
            if (word.length() == 0)
                return root->isTerminal;
            
            int index = word[0] - 'A';
            TrieNode* child;

            // * present case
            if (root->children[index] != NULL)
                child = root->children[index];
            else return false;

            return searchWordUtil(child, word.substr(1));
        }

        bool searchWord(string word)
        {
            return searchWordUtil(root, word);
        }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("AKSHAT");
    t->deleteWord("AKSHAT");
    t->insertWord("TIME");
    cout << "AKSHAT present in Trie Tree: " << t->searchWord("AKSHAT") << endl;
    cout << "TIME present in Trie Tree  : " << t->searchWord("TIME") << endl;
    cout << "TIM present in Trie Tree : " << t->searchWord("TIM") << endl;
    return 0; 
}
