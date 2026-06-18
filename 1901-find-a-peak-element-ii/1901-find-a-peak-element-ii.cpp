class Solution {
public:
    int findindex(vector<vector<int>>& mat,int n,int m,int col){
        int index=-1;
        int maxle=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxle){
                maxle=mat[i][col];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxindex=findindex(mat,n,m,mid);
            int left=mid-1>=0 ? mat[maxindex][mid-1] : -1;
            int right=mid+1<m ? mat[maxindex][mid+1] : -1;
            if(mat[maxindex][mid]>left && mat[maxindex][mid]>right){
                return {maxindex,mid};
            }else if (mat[maxindex][mid]<left)high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};