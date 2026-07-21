class Solution {
public:
    int lengtharea(vector<int>& heights){
        int n=heights.size();
        stack<int> st;
        vector<int>Left(n),Right(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            Left[i]=st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            Right[i]=st.empty() ? n : st.top();
            st.push(i);
        }
        long long  area=0;
        for(int i=0;i<n;i++){
            int weith=Right[i]-Left[i]-1;
            area=max(area,weith*(long long)heights[i]);
        }
        return (int)area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<int> heights(cols,0);
        int maxarea=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
               if(matrix[i][j]=='1'){
                  heights[j]++;
               }else{
                heights[j]=0;
               }
            }
            int area=lengtharea(heights);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};