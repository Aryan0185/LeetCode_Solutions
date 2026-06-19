class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int counter=0;
        for(char c : s){
            if(c=='('){
                if(counter>0){
                    result+=c;
                }
                counter++;
            }else{
               counter--;
               if(counter>0){
                    result+=c;
                }
            }
        }
        return result;
    }
};