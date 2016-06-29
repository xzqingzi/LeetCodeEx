class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> testmap(9,0);
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] == '.') continue;
                int temp = board[i][j] - '1'; // make characters to be 0-8 digits
                if(testmap[temp]) return 0; // if testmap at index temp is equal to 1, return false (number temp+1 existed)
                testmap[temp] = 1;
            }
            fill(testmap.begin(),testmap.end(),0);
        }
        
        for (int j=0; j<9; j++){  // index is opposite as above, make sure one is checking row, the other is checking column
            for (int i=0; i<9; i++){
                if (board[i][j] == '.') continue;
                int temp = board[i][j] - '1'; 
                if(testmap[temp]) return 0; 
                testmap[temp] = 1;
            }
            fill(testmap.begin(),testmap.end(),0);
        }
        
        for (int l=0; l<9; l+=3){
            for (int k=0; k<9; k+=3){
                for (int m=0; m<3; m++){
                    for (int n=0; n<3; n++){
                        int i = l+m;
                        int j = k+n;
                        if (board[i][j] == '.') continue;
                        int temp = board[i][j] - '1'; 
                        if(testmap[temp]) return 0; 
                        testmap[temp] = 1;
                    }
                }
                fill(testmap.begin(),testmap.end(),0);
            }
        }
        return 1;
    }
};





//Example from Bob
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {  //  == board(m,vector<int>(n)); Two dimension matix
        vector<int> simpleMap(9, 0);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j]=='.') continue; //continue: break one loop once; break: break the one whole loop 
                if(simpleMap[board[i][j] - '1']) return false;
                simpleMap[board[i][j] - '1'] = 1;
            }
            fill(simpleMap.begin(),simpleMap.end(),0); // assign the value 0 to the range between begin() and end() 
        }
        
        for(int j = 0; j < 9; j++) {
            for(int i = 0; i < 9; i++) {
                if(board[i][j]=='.') continue;
                if(simpleMap[board[i][j] - '1']) return false;
                simpleMap[board[i][j] - '1'] = 1;
            }
            fill(simpleMap.begin(),simpleMap.end(),0);  
        }
        
        for(int j = 0; j < 3; j++) {
            for(int i = 0; i < 3; i++) {
                for(int l = j*3; l < (j+1)*3; l++) {
                    for(int k = i*3; k < (i+1)*3; k++) {
                        if(board[l][k]=='.') continue;
                        if(simpleMap[board[l][k] - '1']) return false;
                        simpleMap[board[l][k] - '1'] = 1;
                    }
                }
                fill(simpleMap.begin(),simpleMap.end(),0);   
            }
        }
        return true;
    }
};