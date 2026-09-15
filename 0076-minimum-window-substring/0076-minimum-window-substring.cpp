class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return "";
        vector<int> hash(256, 0);
        for (int i = 0; i < n; i++) hash[t[i]]++;   

        int l = 0, r = 0, cnt = 0, minle = INT_MAX, sindex = -1;
        while (r < m) {
            if (hash[s[r]] > 0) cnt++;   
            hash[s[r]]--;

            while (cnt == n) {
                if (r - l + 1 < minle) {
                    minle = r - l + 1;
                    sindex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return (sindex == -1) ? "" : s.substr(sindex, minle);
    }
};