class Solution {
public:
    string countAndSay(int n) {
        string st="1";
        for(int i=1;i<n;i++){
            int left=0;
            int len=st.size();
            string next="";
            while(left<len){
                int right=left;
                int count=1;
                while(right+1<len && st[right]==st[right+1]){
                    count++;
                    right++;
                }
                next+=to_string(count)+st[right];
                left=right+1;
            }
             st=next;
        }
        return st;
    }
};