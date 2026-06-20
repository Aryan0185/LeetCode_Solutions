class Solution {
public: 
  string expand(string s,int left,int right){
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left--;
        right++;
    }
   return s.substr(left+1,right-left-1);
  }
    string longestPalindrome(string s) {
        string result="";
       for(int i=0;i<s.size();i++){
           string odd=expand(s,i,i);
           if(odd.size()>result.size()) result=odd;
            string even=expand(s,i,i+1);
           if(even.size()>result.size()) result=even;
       }
       return result;
    }
};