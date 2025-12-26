#include <iostream>
using namespace std;
#include <cstdlib>

void clearScreen()
{
    system("cls");
}

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
};

void printBoard()
{
    cout << "|\t \t" << "|\t \t" << "|\t \t|" << endl;
    cout << "|\t" << board[0][0] << "\t" << "|\t" << board[0][1] << "\t" << "|\t" << board[0][2] << "\t|" << endl;
    cout << "|\t \t" << "|\t \t" << "|\t \t|" << "\n\n";

    cout << "|\t \t" << "|\t \t" << "|\t \t|" << endl;
    cout << "|\t" << board[1][0] << "\t" << "|\t" << board[1][1] << "\t" << "|\t" << board[1][2] << "\t|" << endl;
    cout << "|\t \t" << "|\t \t" << "|\t \t|" << "\n\n";

    cout << "|\t \t" << "|\t \t" << "|\t \t|" << endl;
    cout << "|\t" << board[2][0] << "\t" << "|\t" << board[2][1] << "\t" << "|\t" << board[2][2] << "\t|" << endl;
    cout << "|\t \t" << "|\t \t" << "|\t \t|" << "\n\n";
}

const int winConditions[8][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {1, 4, 7},
    {2, 5, 8},
    {3, 6, 9},
    {1, 5, 9},
    {3, 5, 7}};

class Player
{
public:
    char name;
    int account[9];
    int cai = 0;
    Player(char name) : name(name) {}
    void addCell(int cellNo)
    {
        account[cai++] = cellNo;
    }
    int checkWin()
    {
        for (int i = 0; i < 8; i++)
        {
            int counter = 0;

            for (int j = 0; j < 3; j++)
            {
                bool found = false;

                for (int k = 0; k < cai; k++)
                {
                    if (account[k] == winConditions[i][j])
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                    counter++;
            }

            if (counter == 3)
                return 1; 
        }

        return 0; 
    }

};


int main()
{
    Player X('X');
    Player O('O');
    char currentPlayer = 'X';
    int cellNo;
    int moves=0;
    while (1)
    {
        while (1)
        {
            cout << currentPlayer << "'s turn: ";

            if (!(cin >> cellNo))
            {
                cout << "Invalid choice. Enter a number.\n";

                cin.clear();
                char ch;
                while (cin.get(ch) && ch != '\n')
                    ;

                continue;
            }

            if (cellNo >= 1 && cellNo <= 9)
            {
                if (*((*board) + (cellNo - 1)) != ' ')
                {
                    cout << "Cell is already filled up!" << endl;
                    continue;
                }
                *((*board) + (cellNo - 1)) = currentPlayer;
                cout << "\n";
                
                clearScreen();
                printBoard();

                if(currentPlayer=='X'){
                    X.addCell(cellNo);
                    if(X.checkWin()){
                        cout<<"X won the game!"<<endl;
                        return 0;
                    }
                }else if(currentPlayer=='O'){
                    O.addCell(cellNo);
                    if(O.checkWin()){
                        cout<<"O won the game!"<<endl;
                        return 0;
                    }
                }

                currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
                moves++;
                if(moves==9){
                    cout<<"Match Draw!"<<endl;
                    return 0;
                }
                break;
            }
            else
            {
                cout << "Invalid choice. Choose 1–9.\n";
            }
        }
    }

    return 0;
}