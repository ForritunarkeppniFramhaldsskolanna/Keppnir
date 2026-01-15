#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to print the board
void print_board(const vector<string>& board) {
    for (const string& row : board) {
        cout << row << endl;
    }
}

// Function to check if a player has won
bool check_win(const vector<string>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player || board[i][0] == toupper(player)) &&
            (board[i][1] == player || board[i][1] == toupper(player)) &&
            (board[i][2] == player || board[i][2] == toupper(player))) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if ((board[0][j] == player || board[0][j] == toupper(player)) &&
            (board[1][j] == player || board[1][j] == toupper(player)) &&
            (board[2][j] == player || board[2][j] == toupper(player))) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player || board[0][0] == toupper(player)) &&
        (board[1][1] == player || board[1][1] == toupper(player)) &&
        (board[2][2] == player || board[2][2] == toupper(player))) {
        return true;
    }
    if ((board[0][2] == player || board[0][2] == toupper(player)) &&
        (board[1][1] == player || board[1][1] == toupper(player)) &&
        (board[2][0] == player || board[2][0] == toupper(player))) {
        return true;
    }

    return false;
}

// Function to check if a player has any legal moves
bool has_legal_moves(const vector<string>& board, int x_count, int X_count, int o_count, int O_count, char player) {
    int lower_count = (player == 'x') ? x_count : o_count;
    int upper_count = (player == 'x') ? X_count : O_count;
    char opponent = (player == 'x') ? 'o' : 'x';

    if (lower_count > 0) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == '.') {
                    return true;
                }
            }
        }
    }

    if (upper_count > 0) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == '.') {
                    return true;
                }
                if (board[i][j] == tolower(opponent)) {
                    return true;
                }
            }
        }
    }
    
    if (upper_count > 0){
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(board[i][j] == toupper(player)){
                    for(int ni = 0; ni < 3; ++ni){
                        for(int nj = 0; nj < 3; ++nj){
                            if(board[ni][nj] == tolower(opponent)){
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    vector<string> board(3, "...");
    int x_count = 4;
    int X_count = 2;
    int o_count = 4;
    int O_count = 2;

    // First move
    board[1][1] = 'x';
    x_count--;
    print_board(board);
    
    while (true) {
        // Read opponent's move
        vector<string> opponent_board(3);
        for (int i = 0; i < 3; ++i) {
            cin >> opponent_board[i];
            if(opponent_board[i] == "Tap!" || opponent_board[i] == "Sigur!"){
                return 0;
            }
            for (int j = 0; j < 3; ++j) {
                if (opponent_board[i][j] != board[i][j]) {
                    if (board[i][j] == '.') {
                        if(opponent_board[i][j] == 'o') o_count--;
                        else if(opponent_board[i][j] == 'O') O_count--;
                    } else if (board[i][j] == 'x') x_count++;
                      else if (board[i][j] == 'X') X_count++;
                }
            }
        }

        board = opponent_board;


        if (check_win(board, 'o')) {
            cout << "Tap!" << endl;
            return 0;
        }
        if (!has_legal_moves(board, x_count, X_count, o_count, O_count, 'x')) {
          cout << "Tap!" << endl;
          return 0;
        }

        // My move
        bool moved = false;
        
        // Try to win
        for (int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == '.'){
                    if(x_count > 0){
                        board[i][j] = 'x';
                        if(check_win(board, 'x')){
                            x_count--;
                            print_board(board);
                            moved = true;
                            break;
                        }
                        board[i][j] = '.';
                    }
                    if(X_count > 0){
                        board[i][j] = 'X';
                        if(check_win(board, 'x')){
                            X_count--;
                            print_board(board);
                            moved = true;
                            break;
                        }
                        board[i][j] = '.';
                    }
                }
            }
            if(moved) break;
        }

        if(!moved){
          if(x_count > 0){
              for(int i = 0; i < 3; ++i){
                  for(int j = 0; j < 3; j++){
                      if(board[i][j] == '.'){
                          board[i][j] = 'x';
                          x_count--;
                          print_board(board);
                          moved = true;
                          break;
                      }
                  }
                  if(moved) break;
              }
          }
        }

        if(!moved){
          if(X_count > 0){
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    if(board[i][j] == '.'){
                        board[i][j] = 'X';
                        X_count--;
                        print_board(board);
                        moved = true;
                        break;
                    }
                }
                if(moved) break;
            }
          }
        }
        
        if(!moved && X_count > 0){
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[i][j] == 'o') {
                        board[i][j] = 'X';
                        X_count--;
                        o_count++;
                        print_board(board);
                        moved = true;
                        break;
                    }
                }
                if(moved) break;
            }
        }
        if(!moved && X_count > 0){
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    if(board[i][j] == 'X'){
                        for(int ni = 0; ni < 3; ++ni){
                            for(int nj = 0; nj < 3; ++nj){
                                if(board[ni][nj] == 'o'){
                                    board[ni][nj] = 'X';
                                    board[i][j] = '.';
                                    o_count++;
                                    print_board(board);
                                    moved = true;
                                    break;
                                }
                            }
                            if(moved) break;
                        }
                    }
                    if(moved) break;
                }
                if(moved) break;
            }
        }


        if (check_win(board, 'x')) {
            cout << "Sigur!" << endl;
            return 0;
        }
    }

    return 0;
}
