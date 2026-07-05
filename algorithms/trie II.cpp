#include<bits/stdc++.h>
using namespace std;//trie II(functions->insert,countWordsEqualTo,countWordsStartingWith,erase)
struct Node{
    Node* links[26]={nullptr};
    int count_endwith=0;
    int count_prefix=0;
    bool containKey(char ch){
        return (links[ch-'a']!=nullptr);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
};
class trie{
    private:
        Node* root;
    public:
        trie(){
            root=new Node;
        }
        void insert(string word){
            Node* ptr=root;
            for(int i=0;i<word.size();i++){
                if(!ptr->containKey(word[i])){
                    Node* newnode=new Node;
                    ptr->put(word[i],newnode);
                }
                ptr=ptr->get(word[i]);
                ptr->count_prefix++;
            }
            ptr->count_endwith++;
       }
       int countWordsEqualTo(string word){
            Node* ptr=root;
            for(int i=0;i<word.size();i++){
                if(!ptr->containKey(word[i]))return 0;
                ptr=ptr->get(word[i]);
            }
            return ptr->count_endwith;
       }
       int countWordsStartingwith(string word){
            Node* ptr=root;
            for(int i=0;i<word.size();i++){
                if(!ptr->containKey(word[i]))return 0;
                 ptr=ptr->get(word[i]);
            }
            return ptr->count_prefix;
       }
        void erase(string word){
            Node* ptr=root;
           for(int i=0;i<word.size();i++){
                if(!ptr->containKey(word[i]))return;
                ptr=ptr->get(word[i]);
                ptr->count_prefix--;
           }
           ptr->count_endwith--;

       }
};
