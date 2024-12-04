class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size(), i = 0, j = 0;
        while(i < n && j < m){
            int operation = 0;
            if(str1[i] <= str2[j]){
                operation = str2[j] - str1[i];
            }
            else{
                operation = 26 - (str1[i] - str2[j]);
            }
            if(operation <= 1){
                j++;
            }
            i++;
        }
        return j == m;
    }
};
