class Solution {
public:

    bool canPlace(int row , int column , vector<string>& temp , int& n){

        bool rows = true, updiagonal = true , downdiagonal = true;

        for(int i=0;i<column;i++){
            if(temp[row][i] == 'Q') rows = false;
        }

        int  i = row;
        int j = column;

        while(i >=0 && j >=0){
            if(temp[i][j] == 'Q') updiagonal = false;
            i--;
            j--;
        }

        i = row;
        j = column;

        while(i < n && j >=0){
            if(temp[i][j] == 'Q') downdiagonal = false;
            i++;
            j--;
        }

        if(rows && updiagonal && downdiagonal) return true;
        return false;
    }

    void NQueen(int column , vector<vector<string>>& result , vector<string>& temp , int& n){

        if(column == n){
            result.push_back(temp);
            return;
        }



        for(int row=0;row<n;row++){

            if(canPlace(row,column , temp , n)){
                temp[row][column] = 'Q';

                NQueen(column + 1 , result , temp , n);

                temp[row][column] = '.';
            }
        }

    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string s(n , '.');
        vector<string> temp(n ,s);

        int column = 0;

        NQueen(column , result , temp , n);

        return result;
    }
};