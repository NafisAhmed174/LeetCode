class Solution {
public:
    int kadane(vector<int> &v){
        int n = v.size();
        int curSum = 0;
        int mxSum = 0;
        int start = 0;
        int mxStart = 0;
        
        for(int i = 0; i < n; i++){
            if(curSum + v[i] < 0){
                curSum = 0;
                start = i + 1;
                cout << start << endl;
            }
            else{
                curSum += v[i];
            }
            if(curSum > mxSum){
                mxSum = curSum;
                mxStart = start;
            }
        }
        return mxStart;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        vector<int> diff(2 * n, 0);
        
        int sum = 0;

        for(int i = 0; i < n; i++){
            diff[i] = diff[i + n] = gas[i] - cost[i];
            sum += diff[i];
        }

        if(sum < 0) return -1;

        int ans = kadane(diff);
        
        return ans;
    }
};