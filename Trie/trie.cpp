#include<iostream>
#include<string>
using namespace std;


struct Node
{
    Node* letters[26] = {NULL};
    bool end = false;
    bool ifPresent(const char ch)
    {
        return letters[ch - 'a'] != NULL;
    }
    void assignNewNode(const char ch)
    {
        letters[ch - 'a'] = new Node();
    }
    Node* getToNextNode(const char ch)
    {
        return letters[ch - 'a'];
    }
    void setEnd()
    {
        end = true;
    }
    bool ifEndIsTrue()
    {
        return end;
    }
};


class Trie
{
private:
    Node* root = NULL;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(const string word)
    {
        Node* temp = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(temp->ifPresent(word[i]) == false)
            {
                temp->assignNewNode(word[i]);
            }
            temp = temp->getToNextNode(word[i]);
        }
        temp->setEnd();
    }
    bool search(const string word)
    {
        Node* temp = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(temp->ifPresent(word[i]) == false)
            {
                return false;
            }
            temp = temp->getToNextNode(word[i]);
        }
        return temp->ifEndIsTrue();
    }
    bool startsWithPrefix(const string prefix)
    {
        Node* temp = root;
        for(int i = 0; i < prefix.size(); ++i)
        {
            if(temp->ifPresent(prefix[i]) == false)
            {
                return false;
            }
            temp = temp->getToNextNode(prefix[i]);
        }
        return true;
    }
};


int main()
{
    Trie trie;
    trie.insert("hello");
    trie.insert("health");
    trie.insert("hell");
    trie.insert("heyy");
    if(trie.search("he"))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    if(trie.search("hell"))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    if(trie.startsWithPrefix("app"))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    if(trie.startsWithPrefix("hea"))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;
}