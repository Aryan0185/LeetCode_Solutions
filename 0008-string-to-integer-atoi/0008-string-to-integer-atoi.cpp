class Solution {
public:
    void skipspace(string & s,int & i,int n){
        if(i<n && s[i]==' '){
            i++;
            skipspace(s,i,n);
        }
    }
    long readdigits(string & s,int & i,int n,long result){
        if(i>=n || !isdigit(s[i])) return result;
         result = result*10 + (s[i]-'0');
        if(result > INT_MAX) return result; 
        i++;
        return readdigits(s,i,n,result);
    }
    int myAtoi(string s) {
       int i=0;
       int n=s.size();
       skipspace(s,i,n); 
       int sign=1;
       if(i<n && (s[i]=='+'|| s[i]=='-')){
         if(s[i]=='-')sign=-1;
         i++;
       }
       long result=readdigits(s,i,n,0);
       if(result > INT_MAX) return (sign==1) ? INT_MAX : INT_MIN;
        return (int)(result*sign);
    }
};