#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    string reverseParentheses(string s) {
        deque<ll> d;
        for(ll i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                deque<ll> temp;
                while(d.back() != '('){
                    temp.push_back(d.back());
                    d.pop_back();
                }
                d.pop_back();
                while(!temp.empty()){
                    d.push_back(temp.front());
                    temp.pop_front();
                }
            }else{
                d.push_back(s[i]);
            }
        }
        string res = "";
        while(!d.empty()){
            res.push_back(d.front());
            d.pop_front();
        }
        return res;
    }
};


void solve(){
    string s;
    cin >> s;
    Solution sol;

    cout << sol.reverseParentheses(s);
    
}

int main(){
    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
    return 0;
}