class Solution {
public:
    bool dfs(vector<vector<char>>& board , string word , int i , int j , int c){

        if(board[i][j] != word[c]) return false;

        if(c == word.size() -1 ){
            return true;
        }

        int dx[] = {0 , 1 , 0 , -1};
        int dy[] = {1 , 0 , -1 , 0};

        // or use a vis matrix
        char temp = board[i][j];
        board[i][j] = '@';

        for(int k = 0 ; k < 4 ; k++){
            int nr = i + dx[k];
            int nc = j + dy[k];

            if(nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size() && board[nr][nc] != '@'){
                if(dfs(board , word , nr , nc , c+1)) return true;
            }
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board , word , i , j , 0)) return true;
                }
            }
        }
        return false;
    }
};
