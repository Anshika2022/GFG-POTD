 class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int temp = mat[i][j];
                mat[i][j] = mat[i][n - j - 1];
                mat[i][n - j - 1] = temp;
            }
        }
    
    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
    }
};
