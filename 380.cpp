
class RandomizedSet {
    unordered_map<ll,ll> m;
    vector<int> v;
    public:

        RandomizedSet() {
            m.clear();
            v.clear();
        }
        
        bool insert(int val) {
            if(m.find(val) != m.end()){
                return false;
            }else{
                m[val] = v.size();
                v.push_back(val);
                return true;
            }
        }
        
        bool remove(int val) {
            if(m.find(val) != m.end()){
                v[m[val]] = v.back();
                m[v.back()] = m[val];
                v.pop_back();
                m.erase(val);
                return true;
            }else{
                return false;
            }
        }
        
        int getRandom() {
            return v[random() % v.size()];
        }
    };
    
    /**
     * Your RandomizedSet object will be instantiated and called as such:
     * RandomizedSet* obj = new RandomizedSet();
     * bool param_1 = obj->insert(val);
     * bool param_2 = obj->remove(val);
     * int param_3 = obj->getRandom();
     */
