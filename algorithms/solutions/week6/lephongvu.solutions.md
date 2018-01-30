#Rotate image

class Solution {
public:
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                std::swap(matrix[a][a+i], matrix[a+i][b]);
                std::swap(matrix[a][a+i], matrix[b][b-i]);
                std::swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
    }
};
