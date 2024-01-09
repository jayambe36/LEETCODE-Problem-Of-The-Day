class Solution {
public:
    void dfs( TreeNode* root , int type , vector<int>&marker , bool &possible)
    {
         if( root == NULL)
         {
             return;
         }
         
         if( root->left == NULL && root->right == NULL)
         {
              if( type == 1)
              {
                  marker.push_back(root->val);
              }
              else
              {
                  if(marker.size() != 0 && marker.back() == root->val)
                  {
                      marker.pop_back();
                  }
                  else
                  {
                      possible = false;
                  }
              }
         }

         dfs( root->left , type , marker,possible);
         dfs( root->right , type , marker , possible);

    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        bool possible = true;

        vector<int>marker;

        dfs( root1 , 1 , marker , possible);

        reverse(marker.begin() , marker.end());
        

        dfs( root2 , 2 , marker , possible);
       
        if(marker.size() > 0) possible = false;

        return possible;
    }
};
