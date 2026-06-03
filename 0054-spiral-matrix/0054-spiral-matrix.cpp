class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0,top=0;
        int right=m-1,bottom=n-1;
        vector<int> temp;
        while(left<=right && top<=bottom){
          for(int col=left;col<=right;col++)
            temp.push_back(matrix[top][col]);
            top++;
            for(int row=top;row<=bottom;row++)
                temp.push_back(matrix[row][right]);
            right--;
            if(top <= bottom) {
            for(int col = right; col >= left; col--)
                temp.push_back(matrix[bottom][col]);
            bottom--;
            }
         if(left <= right) {
            for(int row = bottom; row >= top; row--)
                temp.push_back(matrix[row][left]);
            left++;
             }
        }
  return temp;  }
};