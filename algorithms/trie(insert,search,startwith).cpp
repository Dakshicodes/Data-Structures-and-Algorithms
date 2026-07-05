#include<bits/stdc++.h>//trie I
using namespace std;
struct Node{
   Node* links[26]={nullptr};
   bool flag=false;
   bool containKey(char ch){
    return (links[ch-'a']!=nullptr);
   }
   void put(char ch,Node* node){
      links[ch-'a']=node;
   }

   Node* get(char ch){
    return links[ch-'a'];
   }
};
class trie{
    private:
      Node* root;
    public:
      trie(){
         root=new Node();
      }
      void insert(string word){
         Node* node=root;
         for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                Node* newnode=new Node();
                node->put(word[i],newnode);
            }
            node=node->get(word[i]);
         }
         node->flag=true;
      }
      bool search(string word){
         Node* node=root;
         for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i]))return false;
            node=node->get(word[i]);
         }
         if(node->flag)return true;
         return false;
      }
      bool startwith(string prefix){
         Node* node=root;
         for(int i=0;i<prefix.size();i++){
            if(!node->containKey(prefix[i]))return false;
            node=node->get(prefix[i]);
         }
         return true;   
      }
};