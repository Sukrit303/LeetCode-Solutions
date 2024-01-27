class Solution {
   public:
    int bst(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left = bst(nums, target);
        int right = bst(nums, target + 1);
        if (left == right) {
            return {-1, -1};
        }
        return {left, right - 1};
    }
};

/*******************************************
* In this we have to find the left most and right most last occureance of an elemsnt
* so to do this 
* 1. we have to calculate first occurewance of an element
* 2. we have to calculate last occurewance of an element
* 3. Check if left == right then it has one occurence or zero
* 4. return left and right
* 
* As to find it optimally we can use binary search 
*/