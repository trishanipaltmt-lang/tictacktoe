#include <iostream>
using namespace std;

char board[9] = {'1','2','3','4','5','6','7','8','9'};

// Display the board
void displayBoard()
{
    cout << "\n";
    cout << "     |     |     " << endl;
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    cout << "     |     |     " << endl;
}

// Check whether the player has won
bool checkWin(char player)
{
    // Rows
    if (board[0] == player && board[1] == player && board[2] == player)
        return true;

    if (board[3] == player && board[4] == player && board[5] == player)
        return true;

    if (board[6] == player && board[7] == player && board[8] == player)
        return true;

    // Columns
    if (board[0] == player && board[3] == player && board[6] == player)
        return true;

    if (board[1] == player && board[4] == player && board[7] == player)
        return true;

    if (board[2] == player && board[5] == player && board[8] == player)
        return true;

    // Diagonals
    if (board[0] == player && board[4] == player && board[8] == player)
        return true;

    if (board[2] == player && board[4] == player && board[6] == player)
        return true;

    return false;
}

// Check whether the board is full
bool checkDraw()
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] != 'X' && board[i] != 'O')
            return false;
    }

    return true;
}

// Reset the board
void resetBoard()
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = '1' + i;
    }
}

int main()
{
    int position;
    char player;
    char choice;

    cout << "=================================" << endl;
    cout << "        TIC TAC TOE GAME" << endl;
    cout << "=================================" << endl;

    do
    {
        resetBoard();
        player = 'X';

        while (true)
        {
            displayBoard();

            cout << "\nPlayer " << player;
            cout << ", enter position (1-9): ";
            cin >> position;

            // Check position range
            if (position < 1 || position > 9)
            {
                cout << "Invalid position!";
                cout << " Please enter a number from 1 to 9.\n";
                continue;
            }

            // Check whether position is already occupied
            if (board[position - 1] == 'X' ||
                board[position - 1] == 'O')
            {
                cout << "Position already occupied!";
                cout << " Choose another position.\n";
                continue;
            }

            // Place player's symbol
            board[position - 1] = player;

            // Check winner
            if (checkWin(player))
            {
                displayBoard();

                cout << "\n*********************************" << endl;
                cout << "     Player " << player << " WINS!" << endl;
                cout << "*********************************" << endl;

                break;
            }

            // Check draw
            if (checkDraw())
            {
                displayBoard();

                cout << "\n*********************************" << endl;
                cout << "          GAME DRAW!" << endl;
                cout << "*********************************" << endl;

                break;
            }

            // Change player
            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\nThank you for playing Tic Tac Toe!" << endl;

    return 0;
}