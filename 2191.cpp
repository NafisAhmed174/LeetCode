class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        unordered_map<int,int> m;

        for(auto x: nums){
            if(m.find(x) != m.end()) continue;
            string s = to_string(x);
            for(int i = 0; i < s.length(); i++){
                s[i] = '0' + mapping[s[i] - '0'];
            }
            m[x] = stoll(s);
        }
        
        auto cmp = [&] (int x, int y){
            return m[x] < m[y];
        };

        stable_sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};