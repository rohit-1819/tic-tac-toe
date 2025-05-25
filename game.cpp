#include<iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string player1;
string player2;
int row;
int col;
char token = 'x';
bool isTied;

void drawBoard() {

    cout << "     |       |   \n";
    cout << "  "<<space[0][0]<<"  |   " << space[0][1]<<"   | " << space[0][2] <<"    \n";
    cout << "_____|_______|___\n";
    cout << "     |       |   \n";
    cout << "  "<<space[1][0]<<"  |   " << space[1][1]<<"   | " << space[1][2] <<"    \n";
    cout << "_____|_______|___\n";
    cout << "     |       |   \n";
    cout << "  "<<space[2][0]<<"  |   " << space[2][1]<<"   | " << space[2][2] <<"    \n";
    cout << "     |       |   \n";
}

void game() {
    int digit;

    if(token == 'x') {
        cout << player1 << " its your turn" <<endl;
        cin >> digit;
    }

    if(token == 'o') {
        cout << player2 << " its your turn" <<endl;
        cin >> digit;
    }

    if(digit == 1) {
        row = 0;
        col = 0;
    }

    if(digit == 2) {
        row = 0;
        col = 1;
    }

    if(digit == 3) {
        row = 0;
        col = 2;
    }

    if(digit == 4) {
        row = 1;
        col = 0;
    }
    if(digit == 5) {
        row = 1;
        col = 1;
    }
    if(digit == 6) {
        row = 1;
        col = 2;
    }
    if(digit == 7) {
        row = 2;
        col = 0;
    }
    if(digit == 8) {
        row = 2;
        col = 1;
    }
    if(digit == 9) {
        row = 2;
        col = 2;
    }

    else if (digit < 1 || digit > 9){
        cout << "Invalid!!" << endl;
    }

    if (token == 'x' && space[row][col] != 'x' && space[row][col] != 'o') {
        space[row][col] = 'x';
        token = 'o';
    }
    else if(token == 'o' && space[row][col] != 'o' && space[row][col] != 'x') {
        space[row][col] = 'o';
        token = 'x';
    }
    else {
        cout << "There is no empty space" <<endl;
    }
}

bool checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]) {
            return true;
        }
    }
    if (space[0][0] == space[1][1] && space[0][0] == space[2][2] || space[0][2] == space[1][1] && space[0][2] == space[2][0]) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != 'o') {
                return false;
            }
        }
    }

    isTied = true;
    return true;
}

int main() {

    cout << "Enter name of player 1: \n";
    cin >> player1;
    cout << "Enter name of player 2: \n";
    cin >> player2;

    while (!checkWinner()) {
        drawBoard();
        game();
    }

    if (token == 'x' && isTied == false) {
        cout << player2 << " wins the game" << endl;
    }
    else if (token == 'o' && isTied == false) {
        cout << player1 << " wins the game" << endl;
    }
    else{
        cout << "Its a draw" << endl;
    }
}