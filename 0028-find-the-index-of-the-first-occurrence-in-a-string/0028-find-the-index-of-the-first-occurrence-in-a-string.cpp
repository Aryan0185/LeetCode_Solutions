class Solution {
public:
    int strStr(string haystack, string needle) {
         int n = needle.size();
        for(int i = 0; i <= (int)haystack.size() - n; i++){
            string st = "";
            for(int j = i; j < i + n; j++){   
                st += haystack[j];
            }
            if(st == needle) return i;   
        }
        return -1;
    }
};