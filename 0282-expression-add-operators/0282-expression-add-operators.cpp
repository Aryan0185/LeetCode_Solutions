class Solution {
public: 
    void sol(string num,int t,int i,string op,vector<string>& res,long long c,long long p){
        if(i==num.size()){
            if(c==t){
                res.push_back(op);
            }
            return ;
        }
        string cur;
        long long a=0;
        for(int j=i;j<num.size();j++){
            if(j>i && num[i]=='0') break;
            cur+=num[j];
            a=a*10+num[j]-'0';
            if(i==0){
                sol(num,t,j+1,op+cur,res,a,a);
            }else{
                sol(num,t,j+1,op+'+'+cur,res,c+a,a);
                sol(num,t,j+1,op+'-'+cur,res,c-a,-a);
                sol(num,t,j+1,op+'*'+cur,res,c-p+p*a,p*a);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        sol(num,target,0,"",res,0,0);
        return res;
    }
};