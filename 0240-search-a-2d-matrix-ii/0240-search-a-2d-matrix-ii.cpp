class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
       int m=matrix[0].size();
       int rows=0,cols=m-1;
       while(rows<n && cols>=0){
        if(matrix[rows][cols]==target) return true;
        else if(target>matrix[rows][cols]) rows++;
        else cols--;
       }
       return false ;
    }
};