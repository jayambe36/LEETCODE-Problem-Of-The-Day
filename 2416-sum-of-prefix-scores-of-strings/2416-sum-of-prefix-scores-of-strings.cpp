class Solution {
public:
    unordered_map<long long,int> mp;
    long long base = 31 , pw = 1 , mod = 1011001110001111;
    vector<int> sumPrefixScores(vector<string>& words) {
         vector<int> ans;
         for(string s : words) {
             long long hash = 0 , pw = 1;
             for(int j=0; j<s.size(); j++) {
                   mp[hash = (hash + (pw * (s[j] -'a' + 1)) % mod)%mod]++;
                   pw = (pw * base) % mod;
             }
         }
          for(string s : words) {
             long long hash = 0 , pw = 1;
             int cnt = 0;
             for(int j=0; j<s.size(); j++) {
                   cnt+=mp[hash = (hash + (pw * (s[j] -'a' + 1)) % mod)%mod];
                   pw = (pw * base) % mod;
             }
             ans.push_back(cnt); 
         }
        return ans;
    } 
};
