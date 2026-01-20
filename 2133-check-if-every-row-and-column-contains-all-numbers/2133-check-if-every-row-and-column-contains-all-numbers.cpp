class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // check rows
        for(int i = 0; i < n; i++){
            unordered_map<int, int> m1;
            for(int j = 0; j < n; j++){
                int x = matrix[i][j];
                
                
                if(x < 1 || x > n || m1[x] == 1){
                    return false;
                }
                m1[x] = 1;
            }
        }

        // check columns
        for(int j = 0; j < n; j++){
            unordered_map<int, int> m2;
            for(int i = 0; i < n; i++){
                int x = matrix[i][j];

                if(x < 1 || x > n || m2[x] == 1){
                    return false;
                }
                m2[x] = 1;
            }
        } 

        return true;
    }
};
