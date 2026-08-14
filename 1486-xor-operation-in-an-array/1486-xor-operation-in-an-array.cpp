class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        vector<int> arr;
        for(int i=0;i<n;i++){
           arr.push_back(start+2*i);
           ans^=arr[i];
        }
        return ans;
    }
};