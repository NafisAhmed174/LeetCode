#define MAXLEN 100010
constexpr uint64_t mod = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

uint64_t base_pow[MAXLEN];

int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}

void init(){
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct PolyHash{
    /// Remove suff vector and usage if reverse hash is not required for more speed
    vector<int64_t> pref, suff;

    PolyHash() {}

    template <typename T>
    PolyHash(const vector<T>& ar){
        if (!base_pow[0]) init();

        int n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0);
        // suff.resize(n + 3, 0);

        for (int i = 1; i <= n; i++){
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod) pref[i] -= mod;
        }

        // for (int i = n; i >= 1; i--){
        //     suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
        //     if (suff[i] >= mod) suff[i] -= mod;
        // }
    }

    PolyHash(const char* str)
        : PolyHash(vector<char> (str, str + strlen(str))) {}
    PolyHash(string str)
        : PolyHash(vector<char> (str.begin(), str.end())) {}
    uint64_t get_hash(int l, int r){
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }

    // uint64_t rev_hash(int l, int r){
    //     int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
    //     return h < 0 ? h + mod : h;
    // }
};

class Solution {
public:
    vector<unsigned long long> hashes;    
    PolyHash h;
    int n;
    int s_len;
    set<int> lengths;
    vector<int> len;

    vector<unordered_map<unsigned long long, int>> hashmap;
    
    
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        n = words.size();
        h = PolyHash(target);
        hashes.resize(n);
        s_len = target.size();
        hashmap.resize(s_len + 1);
        
        for(int i = 0; i < n; i++){
            hashes[i] = PolyHash(words[i]).get_hash(0, words[i].size() - 1);
            lengths.insert(words[i].size());



            if(hashmap[words[i].size()].find(hashes[i]) != hashmap[words[i].size()].end()){
                hashmap[words[i].size()][hashes[i]] = min(hashmap[words[i].size()][hashes[i]], costs[i]);
            }else{
                hashmap[words[i].size()][hashes[i]] = costs[i];
            }
        }
        
        for(auto x: lengths) len.push_back(x);
        
        vector<long long> dp(s_len + 1, 1e15);
        dp[0] = 0;
        for(int i = 0; i < s_len; i++){
            if(dp[i] >= INT_MAX) continue;
            for(auto l : len){
                if(i + l > s_len) break;
                auto hsh = h.get_hash(i, i + l - 1);
                if(hashmap[l].find(hsh) != hashmap[l].end()){
                    dp[i + l] = min(dp[i + l], dp[i] +  hashmap[l][hsh] );
                }
            }
        }


        
        if(dp[s_len] >= INT_MAX) return -1;
        return dp[s_len];
    }
};