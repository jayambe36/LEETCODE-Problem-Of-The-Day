class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        // if the leading bit is 0 --> toggle it
        for(int i = 0; i < m; ++i) {
            if(A[i][0] == 0) {
                for(int j = 0; j < n; ++j) {
                    A[i][j] ^= 1;
                }
            }
        }
        // process each col (except leading col)
				// if the numbers of 1 is larger than m/2 (where m is the row nums), toggle it.
        for(int i = 1; i < n; ++i) {
            int cnt = 0;
            for(int j = 0; j < m; ++j) {
                cnt += A[j][i];
            }            
            if(cnt <= (m>>1)) {
                for(int j = 0; j < m; ++j) {
                    A[j][i] ^= 1;
                }
            }
        }
        
        // calculate the result
        int res = 0;
        int bin = 1;
        for(int j = n-1; j >= 0; --j) {
            for(int i = 0; i < m; ++i) {
                res += A[i][j]*bin;
            }
            bin = (bin << 1);
        }
        /*
        for(auto i:A) {
            for(auto j:i)
                cout << j << " ";
            cout << endl;
        }
        */
        
        return res;
    }
};
