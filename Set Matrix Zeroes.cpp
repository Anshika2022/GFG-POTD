class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        bool row_first=0;
        bool col_first=0;
        for(int i=0;i<n;i++){
            if(mat[i][0]==0){
                col_first=true;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]==0){
                row_first=true;
                break;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][0]==0 || mat[0][j]==0) mat[i][j]=0;
            }
        }
        if(row_first){
            for(int i=0;i<m;i++) mat[0][i]=0;
        }
        if(col_first){
            for(int i=0;i<n;i++) mat[i][0]=0;
        }
        
    }
};
