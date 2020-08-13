#include<bits/stdc++.h>

using namespace std;
char board[3][3] = {
  {
    '1',
    '2',
    '3'
  },
  {
    '4',
    '5',
    '6'
  },
  {
    '7',
    '8',
    '9'
  }
};
int row, column;
bool draw = false;
char turn = 'x';
void display_board() {
  system("cls");
  cout << "\t\tT  I  C   T  A  C   T  O  E\n\n";

  cout << "\n\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  ";
  cout << "\n\t\t_____|_____|______";
  cout << "\n\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  ";
  cout << "\n\t\t_____|_____|______";
  cout << "\n\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  ";

}
void player_turn() {
  int choice;

  if (turn == 'x')
    cout << "\n\t\tVISHAL [x]:";
  if (turn == 'o')
    cout << "\n\t\tNEERAJ [o]:";
  cin >> choice;
  switch (choice) {

  case 1:
    row = 0;
    column = 0;
    break;
  case 2:
    row = 0;
    column = 1;
    break;
  case 3:
    row = 0;
    column = 2;
    break;
  case 4:
    row = 1;
    column = 0;
    break;
  case 5:
    row = 1;
    column = 1;
    break;
  case 6:
    row = 1;
    column = 2;
    break;
  case 7:
    row = 2;
    column = 0;
    break;
  case 8:
    row = 2;
    column = 1;
    break;
  case 9:
    row = 2;
    column = 2;
    break;
  default:
    cout << "Invalid Choice!!\n";
  }
  if (turn == 'x' && board[row][column] != 'x' && board[row][column] != 'o') {
    board[row][column] = 'x';
    turn = 'o';
  } else if (turn == 'o' && board[row][column] != 'x' && board[row][column] != 'o') {
    board[row][column] = 'o';
    turn = 'x';
  } else {
    cout << "Box Already Filled!\nPlease Try Again";
  }

}

bool gameover() {
  for (int i = 0; i < 3; i++)
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
      return false;
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][0] == board[2][0])
    return false;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (board[i][j] != 'x' && board[i][j] != 'o')
        return true;
  draw = true;
  return false;
}

int main() {
  while (gameover()) {

    display_board();
    player_turn();

  }
  display_board();
  if (turn == 'x' && draw == false) {
    cout << "NEERAJ [O] WINS CONGRATULATIONS!!\n";
  } else if (turn == 'o' && draw == false) {
    cout << "VISHAL [X] WINS CONGRATULATIONS!!\n";
  } else {
    cout <<"GAME DRAW!!\n";
  }

}
