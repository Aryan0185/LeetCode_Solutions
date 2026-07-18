class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int targetindex=n-k;
        nth_element(
            nums.begin(),
            nums.begin()+targetindex,
            nums.end()
        );
        return nums[targetindex];
    }
};