#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Hello World!"<<endl;
    return 0;
}

void generateParenthesis(int n, int open, int close, string s, vector<string> &res){
    if(s.size() == 2*n){
        res.push_back(s);
        return;
    }
    if(open < n){
        generateParenthesis(n, open+1, close, s+'(', res);
    }
    if(close < open){
        generateParenthesis(n, open, close+1, s+')', res);
    }
}