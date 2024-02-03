class Solution {
public:
    void recur(int index , int target , vector<int>&arr, vector<int>&ds, vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        // Pick the element
        for(int i=index; i<arr.size();i++){
            // Check if same number repeted just adjcentt
            if(index < i and arr[i]==arr[i-1]){
                continue;
            }

            if(arr[i]>target){
                break;
            }

            ds.push_back(arr[i]);

            recur(i+1, target - arr[i], arr ,ds, ans);
            

            ds.pop_back();
        }

       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        recur(0,target, candidates, ds, ans);
        return ans;
    }
};