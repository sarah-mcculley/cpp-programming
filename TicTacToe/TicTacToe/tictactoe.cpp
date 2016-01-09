//
//  main.cpp
//  TicTacToe
//
//  Created by Sarah McCulley on 10/25/15.
//  Copyright (c) 2015 Sarah McCulley. All rights reserved.
//

#include <iostream>
using namespace std;


void showBoard(char board[3][3])
{
    cout << endl;
    cout << "-------------" << endl;
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
    cout << "-------------" << endl;
    
}


void instructions()
{
    cout << "You already know the rules." << endl << endl;
}

bool isGameOver(char board[3][3])
{
    bool isGameOver;
    if(((board[0][0] == 'x' and board[0][1] == 'x' and board[0][2] == 'x') or
       (board[1][0] == 'x' and board[1][1] == 'x' and board[1][2] == 'x') or
       (board[2][0] == 'x' and board[2][1] == 'x' and board[2][2] == 'x') or
       (board[0][0] == 'x' and board[1][1] == 'x' and board[2][2] == 'x') or
       (board[0][2] == 'x' and board[1][1] == 'x' and board[2][0] == 'x') or
       (board[0][0] == 'x' and board[1][0] == 'x' and board[2][0] == 'x') or
       (board[0][1] == 'x' and board[1][1] == 'x' and board[2][1] =='x') or
       (board[0][2] == 'x' and board[1][2] == 'x' and board[2][2] == 'x')) or
        ( (board[0][0] == 'o'  and board[0][1] == 'o' and board[0][2] == 'o') or
         (board[1][0] == 'o' and board[1][1] == 'o' and board[1][2] == 'o') or
         (board[2][0] == 'o' and board[2][1] == 'o' and board[2][2] == 'o') or
         (board[0][0] == 'o' and board[1][1] == 'o' and board[2][2] == 'o') or
         (board[0][2] == 'o' and board[1][1] == 'o' and board[2][0] == 'o') or
         (board[0][0] == 'o' and board[1][0] == 'o' and board[2][0] == 'o') or
         (board[0][1] == 'o' and board[1][1] == 'o' and board[2][1] == 'o') or
         (board[0][2] == 'o' and board[1][2] == 'o' and board[2][2] == 'o')))
        isGameOver = true;
    else
        isGameOver = false;
        
    return isGameOver;
}

void chooseSquare(char board[3][3], int player, int choice)
{
    int board1 = 0;
    int board2 = 0;
    cout << "choice: " << choice;
    switch (choice) {
        case 1:
            board1 = 0;
            board2 = 0;
            break;
        case 2:
            board1 = 0;
            board2 = 1;
            break;
        case 3:
            board1 = 0;
            board2 = 2;
            break;
        case 4:
            board1 = 1;
            board2 = 0;
            break;
        case 5:
            board1 = 1;
            board2 = 1;
            break;
        case 6:
            board1 = 1;
            board2 = 2;
            break;
        case 7:
            board1 = 2;
            board2 = 0;
            break;
        case 8:
            board1 = 2;
            board2 = 1;
            break;
        case 9:
            board1 = 2;
            board2 = 2;
            break;
    }
    
    char marker = player == 1 ? 'x' : 'o';
    board[board1][board2] = marker;
            
            
    
}



int main() {
    
    int player = 1;
    int choice;
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'} };
    instructions();
    showBoard(board);
    
    while (!isGameOver(board))
    {
        cout << "Player " << player << " choose a square: ";
        cin >> choice;
        while(choice < 1 or choice > 9)
            {
                cout << "That square is already taken." << endl;
                cin >> choice;
            }
        chooseSquare(board, player, choice);
                showBoard(board);
        if (isGameOver(board)) {
            cout << "Player " << player << " wins!" << endl;
        };
        if (player == 1) {
            player = 2;
        }
        else if (player == 2) {
            player = 1;
        }

    }
   
    return 0;
}
