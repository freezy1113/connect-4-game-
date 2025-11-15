#include <iostream>
#include <vector> 
#include <map>
using namespace std;

vector<vector<char>> vec(6, vector<char>(7, ' ')) ;
bool xo = true ;
int turn ;
int player = 1 ; 
int winner = 0 ;
map < int , int > mp = { {1, 0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0} };
void printgame(){
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            cout << '|' << vec[i][j] << '|' ;
        }
        cout << "\n" ;
    }
    return ;
}

void checker(){
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 7 ; j++){
            if( (i <= 2 && vec[i][j] != ' ' && vec[i][j] == vec[i+1][j] && vec[i][j] == vec[i+2][j] && vec[i][j] == vec[i+3][j]) || (j <=3 && vec[i][j] != ' ' && vec[i][j] == vec[i][j+1] && vec[i][j] == vec[i][j+2] && vec[i][j] == vec[i][j+3]) || (i <= 2 && j <= 3 && vec[i][j] != ' ' && vec[i][j] == vec[i+1][j+1] && vec[i][j] == vec[i+2][j+2] && vec[i][j] == vec[i+3][j+3]) || (i <= 2 && j >= 3 && vec[i][j] != ' ' && vec[i][j] == vec[i+1][j-1] && vec[i][j] == vec[i+2][j-2] && vec[i][j] == vec[i+3][j-3])){
                cout << "player " << vec[i][j] << " won\n" ;
                winner++ ;
                return ;
            }
        }
    }
}

void playerturn(int turn){
    if (xo == true){
        player = 1 ;
        if(mp[turn] >= 6){
            cout << "invalid move! \n" ;
            return ;
        }
        vec[5 - mp[turn]][turn-1] = 'X';
        mp[turn]++ ;
        xo = false ;
        player = 2 ; 
    }
    else{
        if(mp[turn] >= 6){
            cout << "invalid move! \n" ;
            return ;
        }
        vec[5 - mp[turn]][turn-1] = 'O';
        mp[turn]++ ;
        xo = true ;
        player = 1 ;
    }
}

int main(){ 
    int theLoop = 42 ;
    cout << "Welcome to connect 4 game <3\n" ; 
    while(theLoop--){
        printgame() ; 
        cout << "player " << player << " turn : " ;
        while(true){
            cin >> turn ;
            if(turn < 1 || turn > 7 ){
                cout << "invalid move!\ntry again pls : " ;
            }
            else{
                break;
            }
        }
        playerturn(turn);
        checker() ;
        if(winner > 0){
            return 0 ;
        }
    }
    cout  << "tie <3 \n" ;
}



