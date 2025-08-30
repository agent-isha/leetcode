class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++){
            unordered_map<char,int>freq;
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]>'0'&& board[i][j]<='9') {
                    freq[board[i][j]]++;

                }
               

            }
            for(auto & a:freq){
                if(a.second>1){
                    return false;
                }
            }
        }
        for(int i=0;i<board[0].size();i++){
            unordered_map<char,int>freq1;
            for(int j=0;j<board.size();j++){
                if((board[j][i]>'0' && board[j][i]<='9')){
                    freq1[board[j][i]]++;

                }
               

            }
            for(auto & a:freq1){
                if(a.second>1){
                   return false;
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                unordered_map<char,int>freq3;
                for(int k=i*3;k<i*3+3;k++){
                    
                    for(int l=j*3;l<j*3+3;l++){
                        if(board[k][l]>'0' && board[k][l]<='9'){
                            freq3[board[k][l]]++;
                        }

                    }
                    for(auto a:freq3){
                        if(a.second>1){
                            return false;
                        }
                    }
                }

            }
        }
        return true;
        
    }
};