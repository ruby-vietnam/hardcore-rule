Problem 1:

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> result (rowIndex +1, 0);
        
        result[0]  = 1;
        for(int i = 0; i <= rowIndex; i++)
        {
            for(int j = i ; j >0 ;  j--)
            {
                result[j] = result[j] + result[j-1];
            }
        }
        
        return result;
        
    }
};

Problem 2: 
