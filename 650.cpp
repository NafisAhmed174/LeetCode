class Solution {
public:
    int minSteps(int n) {
        
        int f = 2;
        int ans = 0;
        int now = 1;

        while(n > 1){
            while(n % f == 0){
                ans += f / now;
                n++;
                n /= f;
            }
            f++;
        }
        return ans;        
    }
};