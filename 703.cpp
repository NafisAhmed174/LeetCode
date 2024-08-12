class KthLargest {
public:
    
    int k;
    vector<int> nums;
    multiset<int> st;

    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        this -> nums = nums;
        for(auto x: nums){
            st.insert(x);
            if(st.size() > k) st.erase(st.begin());
        }
    }
    
    int add(int val) {
        st.insert(val);
        if(st.size() > k){
            st.erase(st.begin());
        }
        return *st.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */