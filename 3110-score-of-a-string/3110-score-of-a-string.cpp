class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size(), res = 0;
        for(int i=0;i<n-1;i++)res+=abs(s[i]-s[i+1]);
        return res;
    }
};
