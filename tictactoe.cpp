#include <iostream>
#include <vector>
using namespace std;

vector<char> moves;
char turn = 'x';

char b[3][3] = {{'1', '2', '3'},
                {'4', '5', '6'},
                {'7', '8', '9'}};
bool draw = false;

void viewBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void switchTurns()
{
    if (turn == 'x')
        turn = 'o';
    else if (turn = 'o')
        turn = 'x';
}

void playerTurn()
{
    int choice;
    int r, c;

    if (turn == 'x')
        cout << "Enter Player 1 choice [x]: ";
    else if (turn == 'o')
        cout << "Enter Player 2 choice [o]: ";

    cin >> choice;
    if (choice > 0 && choice < 10)
        switch (choice)
        {
        case 1:
            r = 0;
            c = 0;
            break;
        case 2:
            r = 0;
            c = 1;
            break;
        case 3:
            r = 0;
            c = 2;
            break;
        case 4:
            r = 1;
            c = 0;
            break;
        case 5:
            r = 1;
            c = 1;
            break;
        case 6:
            r = 1;
            c = 2;
            break;
        case 7:
            r = 2;
            c = 0;
            break;
        case 8:
            r = 2;
            c = 1;
            break;
        case 9:
            r = 2;
            c = 2;
            break;
        }
    else
    {
        switchTurns();
        cout << "Invalid move" << endl;
        return;
    }

    if (b[r][c] != 'x' && b[r][c] != 'o')
    {
        moves.push_back(b[r][c]);
        b[r][c] = turn;
    }
    else
    {
        cout << "Invalid move" << endl;
        playerTurn();
    }
}

bool finish()
{
    for (int i = 0; i < 3; i++)
        if (b[i][0] == b[i][1] && b[i][0] == b[i][2] || b[0][i] == b[1][i] && b[0][i] == b[2][i])
            return false;

    if (b[0][0] == b[1][1] && b[0][0] == b[2][2] || b[0][2] == b[1][1] && b[0][2] == b[2][0])
        return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[i][j] != 'x' && b[i][j] != 'o')
                return true;

    draw = true;
    return false;
}

int main()
{
    while (finish())
    {
        viewBoard();
        playerTurn();
        finish();
        switchTurns();
    }
    viewBoard();
    switchTurns();
    if (turn == 'x' && draw == false)
        cout << "Player 1 won" << endl;
    else if (turn == 'o' && draw == false)
        cout << "Player 2 won" << endl;
    else
        cout << "Draw" << endl;

    turn = 'x';
    int p1count = 0;
    int p2count = 0;

    cout << "Sequence of moves: ";
    for (auto i : moves)
    {
        cout << " " << turn << ":" << i << "->";
        if (turn == 'x')
            p1count++;
        else if (turn = 'o')
            p2count++;
        switchTurns();
    }

    cout << endl;
    cout << "Total turns of p1: " << p1count << endl;
    cout << "Total turns of p2: " << p2count << endl;
}