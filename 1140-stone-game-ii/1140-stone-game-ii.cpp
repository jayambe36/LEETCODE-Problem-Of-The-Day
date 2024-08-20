class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int size = piles.size();
        vector<int> sufPileSum(size);
        for(int indx = size - 1; indx >= 0; indx--) {
            sufPileSum[indx] = (indx == size - 1) ? piles[indx] : (piles[indx] + sufPileSum[indx+1]);
        }
        
        vector<vector<int>> stateMat(size + 1, vector<int>(size + 1, 0));
        for(int indx = 0; indx < size; indx++){
            int mVal = size;
            stateMat[indx][mVal] = sufPileSum[indx];  
        }

        for(int indx = size - 1; indx >= 0; indx--){
            for(int mVal = 1; mVal <= size; mVal++){
                for(int xVal = 1; xVal <= 2 * mVal && indx + xVal <= size; xVal++){  
                    int futureAliceCollection = sufPileSum[indx] - stateMat[indx + xVal][max(mVal, xVal)];
                    stateMat[indx][mVal] = max(stateMat[indx][mVal], futureAliceCollection);  
                }
            }
        }
        return stateMat[0][1];
    }
};
