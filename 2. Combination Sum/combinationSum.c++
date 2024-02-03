class Solution {
    public:
        void recur(vector<int>&arr, int target,int ind , vector<vector<int>>&ans,vector<int>&ds ){
            
            if(ind == arr.size()){
                if(target == 0){
                    ans.push_back(ds);
                }
                return;
            }
    
            // Pick the element 
            if(arr[ind]<= target){
                ds.push_back(arr[ind]);
                recur(arr,target-arr[ind],ind, ans, ds);
                // remove element from data structure
                ds.pop_back();
            }
    
            recur(arr, target, ind+1, ans , ds);
    
    
    
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int>ds;
            recur(candidates,target, 0,ans,ds);
            return ans;
        }
    };