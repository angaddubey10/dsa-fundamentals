#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    int count; 
    bool isEnd;
    TrieNode* child[26];
    TrieNode(){
        count = 0;
        isEnd = false;
        for(int i=0; i<26; i++){
            child[i] = nullptr;
        }
    }
};

class Trie{
    TrieNode * root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        int idx;
        TrieNode *current = root;
        for(char ch : word){
            idx = ch-'a';
            if(current->child[idx]==nullptr){
                current->child[idx] = new TrieNode();
            }
            current = current->child[idx];
            current->count++;
        }
        current->isEnd = true;
    }

    int countPrefix(string word){
        int idx;
        int ct = 0;
        TrieNode *current = root;
        for(char ch : word){
            idx = ch-'a';
            current = current->child[idx];
            ct += current->count;
        }
        return ct;
    }
};

class Solution {
public:
    vector<int> sumPrefixScoresHashMap(vector<string>& words) {
        unordered_map<string, int>prefix;
        string pref;
        for(string word : words){
            for(int i=0; i<word.size(); i++){
                pref = word.substr(0, i+1);

                prefix[pref]++;
            }
        }
        vector<int>ans;
        int count;
        for(string word : words){
            count=0;
            for(int i=0; i<word.size(); i++){
                pref = word.substr(0, i+1);
                count+=prefix[pref];
                
            }
            ans.push_back(count);
        }
        return ans;
    }


     vector<int> sumPrefixScoresTrie(vector<string>& words) {
        Trie myTrie;
        for(string word : words){
            myTrie.insert(word);
        }
        vector<int>ans;
        int count;
        for(string word : words){
            count = myTrie.countPrefix(word);
            ans.push_back(count);
        }
        return ans;
    }



    vector<int> sumPrefixScores(vector<string>& words) {

        return sumPrefixScoresTrie(words);

        return sumPrefixScoresHashMap(words);

    }
};

int main(){
    vector<string> words = {"abc","ab","bc","b"};
    Solution obj;
    vector<int> ans = obj.sumPrefixScores(words);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<", ";
    }
    

    return 0;
}