int n1;
//vector<vector<int>> mat1(n1,vector<int>(n1,1e5+1));
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int n = mat.size();vector<int> v;
        int m = mat[0].size();
        n1 = max(n,m);
        int p=-1,q=0;
// for printing first half
        for(int i =1;i<=n1;i++){
            if(i%2==0){q++;}else{p++;}
            for(int j =1;j<=i;j++){
                if(p<n && q<m){
                v.push_back(mat[p][q]);
                }
                if(j<=i-1){
                if(i%2==0){p++;q--;}
                else{q++;p--;}
                }
                
            }
        }
// for printing second half
        for(int i = n1-1;i>=1;i--){
            if(i%2!=0){q++;}else{p++;}
            for(int j =1;j<=i;j++){
                if(p<n && q<m){
                v.push_back(mat[p][q]);
                }
                if(j<=i-1){
                if(i%2==0){p++;q--;}
                else{q++;p--;}
                }
            }
        }
       return v;
    }
};