#include <iostream>
#include <vector> 
#include <map>
using namespace std;

vector<vector<char>> grid(6, vector<char>(7, ' ')) ;
bool playerSelector = true ;
int playerMove ;
char player = 'x' ; 
bool winner = false ;
map < int , int > storedMoves = { {1, 0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0} };
void printgame(){
    for(int j = 0 ; j < 7 ; j++){
        cout << " " << (j+1) <<  " " ;
    }
    cout << "\n" ;
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            cout << '|' << grid[i][j] << '|' ;
        }
        cout << "\n" ;
    }
    return ;
}

void checker(){
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            if( (i <= 2 && grid[i][j] != ' ' && grid[i][j] == grid[i+1][j] && grid[i][j] == grid[i+2][j] && grid[i][j] == grid[i+3][j]) || (j <=3 && grid[i][j] != ' ' && grid[i][j] == grid[i][j+1] && grid[i][j] == grid[i][j+2] && grid[i][j] == grid[i][j+3]) || (i <= 2 && j <= 3 && grid[i][j] != ' ' && grid[i][j] == grid[i+1][j+1] && grid[i][j] == grid[i+2][j+2] && grid[i][j] == grid[i+3][j+3]) || (i <= 2 && j >= 3 && grid[i][j] != ' ' && grid[i][j] == grid[i+1][j-1] && grid[i][j] == grid[i+2][j-2] && grid[i][j] == grid[i+3][j-3])){
                cout << "player " << grid[i][j] << " won\n" ;
                winner = true ;
                return ;
            }
        }
    }
}

void playerturn(int turn){
    if (playerSelector == true){
        player = 'x' ;
        if(storedMoves[turn] >= 6){
            cout << "invalid move! \n" ;
            return ;
        }
        grid[5 - storedMoves[turn]][turn-1] = 'X';
        storedMoves[turn]++ ;
        playerSelector = false ;
        player = 'o' ; 
    }
    else{
        if(storedMoves[turn] >= 6){
            cout << "invalid move! \n" ;
            return ;
        }
        grid[5 - storedMoves[turn]][turn-1] = 'O';
        storedMoves[turn]++ ;
        playerSelector = true ;
        player = 'x' ;
    }
}

int main(){ 
    int theLoop = 42 ;
    cout << "Welcome to connect 4 game <3\n" ; 
    while(theLoop--){
        printgame() ; 
        cout << "player " << player << " turn , pick a column (1-7) : " ;
        while(true){
            cin >> playerMove ;
            if(playerMove < 1 || playerMove > 7 ){
                cout << "invalid move!\ntry again pls : " ;
            }
            else{
                break;
            }
        }
        playerturn(playerMove);
        checker() ;
        if(winner){
            return 0 ;
        }
    }
    cout  << "tie <3 \n" ;
}



