class Solution {
public:
    bool isPalindrome(string s) {
        string clean="";
          for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                clean+=tolower(s[i]);
            }
          }
          int left=0,right=clean.size()-1;
        while(left<right){
            if(clean[left]!=clean[right]) return false;
                left++;
                right--;
                }
        return true;
    }
};