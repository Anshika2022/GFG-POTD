class Solution {
public:
    vector<int> search(string& pat, string& txt) {
        int k = pat.size();
        vector<int> lps(k, 0), res;
        
        // Preprocess the pattern to create the LPS array
        for (int i = 1, len = 0; i < k; ) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        
        // Search for the pattern in the text
        for (int i = 0, j = 0; i < txt.size(); ) {
            if (txt[i] == pat[j]) {
                i++, j++;
                if (j == k) {
                    res.push_back(i - j); // Found a match, add start index
                    j = lps[j - 1];
                }
            } else if (j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        
        return res;
    }
};
