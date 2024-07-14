class Solution {
public:
    string countOfAtoms(string s) {
        stack<unordered_map<string, int>> st;
        unordered_map<string, int> m;

        st.push(m);

        int i = 0, n = s.size();

        while (i < n) {
            string ch, cnt, mul;
            if (s[i] >= 'A' && s[i] <= 'Z') {
                ch.push_back(s[i]);
                i++;
                while (i < n && s[i] >= 'a' && s[i] < 'z') {
                    ch.push_back(s[i]);
                    i++;
                }
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    cnt.push_back(s[i]);
                    i++;
                }
                if (!cnt.size())
                    cnt = "1";
                st.top()[ch] += stoi(cnt);
            } else if (s[i] == '(') {
                st.push(m);
                i++;
            } else {
                i++;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    mul.push_back(s[i]);
                    i++;
                }

                auto it = st.top();
                st.pop();

                if (mul.empty()) mul = "1";
                
                int multiply = stoi(mul);
                for (auto& x : it) {
                    st.top()[x.first] += x.second * multiply;
                }
            }
        }

        map<string, int> mp;

        while (!st.empty()) {
            for (auto x : st.top()) {
                mp[x.first] += x.second;
            }
            st.pop();
        }
        string res;
        for (auto x : mp) {
            res += x.first;
            if (x.second > 1)
                res += to_string(x.second);
        }
        return res;
    }
};