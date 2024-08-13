class Solution {
public:
    vector<vector<int>> res;
    vector<int> f;
    int target;

    void print(vector<int>&v){
        for(auto x: v) cout << x << " ";
        cout << "\n" ;
    }

    void func(int i, int sum, vector<int> &sub){
        // print(sub);
        if(sum == 0){
            res.push_back(sub);
            return;
        }
        if(i > target) return;
        int cnt = 0;

        func(i + 1, sum, sub);

        for(int j = 1; j <= f[i]; j++){
            if(sum - j * i >= 0){
                cnt++;
                sub.push_back(i);
                func(i + 1, sum - j * i, sub);
            }else{
                break;
            }
        }
        while(cnt){
            sub.pop_back();
            cnt--;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        f.resize(target + 1);
        for(auto x: candidates){
            if(x > target) continue;
            f[x]++;
        }
        vector<int> dummy;
        func(0, target, dummy);
        return res;
    }
};