using ll = long long;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            st.push(s[i]);
            bool done = false;
            while(st.size() >= 2 && !done){
                char c1 = st.top();
                st.pop();
                char c2 = st.top();
                st.pop();

                if(x > y){
                    if(c2 == 'a' && c1 == 'b'){
                        ans += x;
                    }else{
                        st.push(c2);
                        st.push(c1);
                        done = true;
                    }
                }
                else{
                    if(c2 == 'b' && c1 == 'a'){
                        ans += y;
                    }else{
                        st.push(c2);
                        st.push(c1);
                        done = true;
                    }
                }
            }
        }
        stack<char> st2;
        while(!st.empty()){
            char c1 = st.top();
            st.pop();
            if(st2.empty()){
                st2.push(c1);
            }
            else if(c1 == 'a' && st2.top() == 'b'){
                st2.pop();
                ans += x;
            }else if(c1 == 'b' && st2.top() == 'a'){
                ans += y;
                st2.pop();
            }else{
                st2.push(c1);
            }
        }

        return ans;
    }
};