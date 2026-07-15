class Solution {
public:
    string removeKdigits(string num, int k) {
       int n=num.size();
       stack<char>st;
       for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && st.top()>num[i]){
            st.pop();
            k--;
        }
        st.push(num[i]);
       } 
       while(k>0 && !st.empty()){
        st.pop();
        k--;
       }
       string result="";
       while(!st.empty()){
        result.push_back(st.top());
        st.pop();
       }
       reverse(result.begin(),result.end());
       int idx = 0;
        while (idx < (int)result.size() - 1 && result[idx] == '0') idx++;
        result = result.substr(idx);
        
        return result.empty() ? "0" : result;
    }
};