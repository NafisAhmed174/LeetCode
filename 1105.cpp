class Solution {
public:
    int shelfWidth, n;
    vector<int> dp;

    int func(vector<std::vector<int>> &books, int i){
        if(i >= n) return 0; 

        int &ret = dp[i];
        if(ret != -1) return ret;

        int ans = 1e9, currWidth = 0, mxHeight = 0;

        for(int j = i; j < n; j++){
            currWidth += books[j][0];
            mxHeight = max(mxHeight, books[j][1]);
            if(currWidth > shelfWidth) break;

            ans = min(ans, mxHeight + func(books, j + 1));
        }
        return ret = ans;
    }

    int minHeightShelves(std::vector<std::vector<int>>& books, int shelfWidth) {
        this -> shelfWidth = shelfWidth;
        n = books.size();
        dp.resize(n);
        fill(dp.begin(), dp.end(), -1);
        return func(books, 0);
    }
};