#include <iostream>

using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char data)
        {
            this->data = data;
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

        void insertUtil(TrieNode* root, string word)
        {
            // * base case
            if (word.length() == 0)
            {
                root->isTerminal = true;
                return;
            }

            // ^ assumption: Words will be in CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            // ^ present case
            if(root -> children[index] != NULL)
            {
                child = root -> children[index];
            }
            // ^ absent case
            else
            {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            insertUtil(child, word.substr(1));

        }

        bool searchWordUtil(TrieNode* root, string word)
        {
            // * base condition
            if (word.length() == 0)
                return root->isTerminal;
            
            // ^ assumption: Words will be in CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            // ^ present case
            if(root->children[index] != NULL)
                child = root->children[index];
            else
                // ^ absent case
                return false;

            // ^ recursion
            return searchWordUtil(child, word.substr(1));
        }

        bool searchWord(string word)
        {
            return searchWordUtil(root, word);
        }

        bool deleteWordUtil(TrieNode* root, string word)
        {
            // * base condition
            if (word.length() == 0)
            {
                root->isTerminal = false;
                return true;
            }

            // ^ assumption: Words will be in CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            // ^ present case
            if (root->children[index] != NULL)
                child = root->children[index];
            else
                // ^ absent case
                return false;
            
            // * recursion
            return deleteWordUtil(child, word.substr(1));
        }

        bool deleteWord(string word)
        {
            return deleteWordUtil(root, word);
        }

        void insertWord(string word)
        {
            insertUtil(root, word);
        }

        
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DUCK");
    t->insertWord("TIME");
    t->insertWord("DICE");

    cout << "Present or Not: " << t->searchWord("TIME") << endl;
    cout << "After deleteing Delete TIME word from Trie Tree";
    t->deleteWord("TIME"); cout << endl;
    cout << "Present or Not: " << t->searchWord("TIME") << endl;
    return 0;
}
