class Solution {
public:
    int maxOperations(string s) {
        int n = s.length(), ans = 0;
        int i = 0;
        int oneCount = 0;
        while (i < n) {
            if (s[i] == '1') {
                oneCount++;
                i++;
            } else {
                ans += oneCount; // Each zero sequence causes all previous ones to move
                while (i < n && s[i] != '1') i++; // Skip zeros
            }
        }
        return ans;
    }
};