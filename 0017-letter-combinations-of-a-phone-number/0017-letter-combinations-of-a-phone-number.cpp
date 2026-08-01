class Solution {
public:
    void backtrack(int idx,string s,unordered_map<char,string> &mpp,string digits,vector<string>& ans){
        if(idx==digits.size()){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<mpp[digits[idx]].length();i++){
          s.push_back(mpp[digits[idx]][i]);
          backtrack(idx+1,s,mpp,digits,ans);
          s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
       unordered_map<char,string> mpp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
       string s;
       vector<string> ans;
       backtrack(0,s,mpp,digits,ans);
       return ans; 
    }
};