#include <iostream>
using namespace std;

char cpuSym = 'X';          // the character that will be used by the cpu
char humanSym = 'O';        // the character that will be used by the human player

void printState(string state)       // This function prints the tic-tac-toe board
{
    cout << " " << state[1] << " | " << state[2] << " | " << state[3] << endl;
    cout << "-----------" << endl;
    cout << " " << state[4] << " | " << state[5] << " | " << state[6] << endl;
    cout << "-----------" << endl;
    cout << " " << state[7] << " | " << state[8] << " | " << state[9] << endl;
    cout << endl;
}

bool isValidMove(int move, string state)    // checks if the move entered by human player is valid
{
    if (move > 9 || move < 1 || state[move] != ' ')
    {
        return 0;
    }
    return 1;
}

bool playerWon(string state, char pl)   // given the game state, and the player symbol, returns if that player won
{
    for (int i = 0; i < 3; i++)
    {
        bool boo1 = 1, boo2 = 1;
        for (int j = 0; j < 3; j++)
        {
            if (state[i * 3 + j + 1] != pl)     // checking if pl covered an entire row
            {
                boo1 = 0;
            }
            if (state[i + 1 + j * 3] != pl)     // checking if pl covered an entire column
            {
                boo2 = 0;
            }
        }
        if (boo1 || boo2)
        {
            return 1;
        }
    }
    if (state[1] == pl && state[5] == pl && state[9] == pl)     // top-left to bottom-right diagonal
    {
        return 1;
    }
    if (state[3] == pl && state[5] == pl && state[7] == pl)     // top-right to bottom-left diagonal
    {
        return 1;
    }
    return 0;
}

int lastMove(string state, char pl)     // checks if there is a winning position for the player pl that would end the game
{
    for (int i = 1; i <= 9; i++)
    {
        if (state[i] == ' ')
        {
            state[i] = pl;
            if (playerWon(state, pl))
            {
                return i;
            }
            state[i] = ' ';
        }
    }
    return 0;
}

int calcWinMoves(string state, char pl)     // counts the number of positions which will lead to win of player if played at that position
{
    int cnt = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (state[i] == ' ')
        {
            state[i] = pl;
            if (playerWon(state, pl))
            {
                cnt++;  // increment count if playing at ith position leads to win of player pl
            }
            state[i] = ' ';
        }
    }
    return cnt;
}

int nextMove(string state)      // this function is called by the cpu to decide the next move it isn't obvious
{
    if (state[5] == ' ' && cpuSym == 'O')    // if the center is unoccupied when the human played first, 
    {                                        // take the center (there are exceptions in the main function)
        return 5;
    }
    int newMove = -1;       // this variable keeps track of the potential next move
    for (int i = 1; i <= 9; i++)
    {
        if (state[i] == ' ')        // if cell i unoccupied
        {
            state[i] = cpuSym;      // try taking ith state
            int wins = calcWinMoves(state, cpuSym); // check how many ways to win after taking ith cell
            if (wins > 1)   // if more than one way to win after choosing ith cell
            {
                return i;   // then go for it (sure win)
            }
            if (wins == 1)  // if only one way possible
            {
                int Omove = lastMove(state, cpuSym);    
                state[Omove] = humanSym;
                if (calcWinMoves(state, humanSym) > 1)  // checking if human can have a definite win after blocking this move
                {
                    state[Omove] = ' ';     
                    continue;   // if so, then don't make this move and continue
                }
                for (int j = 1; j <= 9; j++)    // after ith move is made and blocked by the human,
                {                               // check for definite win condition in next to next move
                    if (state[j] == ' ')
                    {
                        state[j] = cpuSym;
                        if (!lastMove(state, humanSym) && calcWinMoves(state, cpuSym) > 1)
                        {
                            return i;       // if win guaranteed in next to next move then go for this move
                        }
                        state[j] = ' ';
                    }
                }
                state[Omove] = ' ';
                newMove = i;    
            }
            state[i] = ' ';
        }
    }
    if (newMove != -1)  // if potential move found then return it
    {
        return newMove;
    }
    else
    {
        return state.find(' ');     // else return any empty cell (usually happens at the end of the game)
    }
}

int main()
{
    string state = ".         ";    // state is a 10 character long string with first character unused

    int playerChoice = 0;   // used to input order from the user
    bool contPlay = 1;
    while (contPlay)
    {
        state = ".         ";
        cout << "Select first player: 0-Human, 1-CPU: ";
        cin >> playerChoice;    // input order
        if (playerChoice != 0 && playerChoice != 1)
        {
            cout << "Invalid choice. Please try again\n\n";
            continue;
        }
        cout << endl;
        if(playerChoice == 0)   // setting varaibles for the players acc to game order
        {
            humanSym = 'X';
            cpuSym = 'O';
        }
        else
        {
            cpuSym = 'X';
            humanSym = 'O';
        }
        int noOfMoves = 0;  // keeps track of number of moves that already happened
        int move = 0, cpuMove = 0;
        while (noOfMoves < 9)
        {
            if (noOfMoves % 2 == playerChoice)  // if human player's turn
            {
                cout << "Enter your move(1-9): ";
                cin >> move;
                if (!isValidMove(move, state))
                {
                    cout << "Illegal move\n\n";
                    continue;
                }

                state[move] = humanSym;
                cout << "Your move:\n";
                printState(state);
                if (playerWon(state, humanSym))
                {
                    break;
                }
                noOfMoves++;
            }
            else    // cpu's turn
            {
                cout << "CPU move:\n";
                if (noOfMoves == 0) // if first move, then go for the top left-corner
                {
                    cpuMove = 1;
                    state[cpuMove] = cpuSym;
                    printState(state);
                    noOfMoves++;
                    continue;
                }   
                if (noOfMoves == 1 && move % 2 == 0)    // if second move and human played at any edge centre then play it's adjacent block
                {
                    if (move == 2 || move == 8)
                    {
                        cpuMove = move - 1;
                    }
                    else
                    {
                        cpuMove = move - 3;
                    }

                    state[cpuMove] = cpuSym;
                    printState(state);
                    noOfMoves++;
                    continue;
                }
                cpuMove = lastMove(state, cpuSym);  // if can win, then win
                if (cpuMove)
                {
                    state[cpuMove] = cpuSym;
                    printState(state);
                    break;
                }

                cpuMove = lastMove(state, humanSym);    // if human is winning, then block
                if (cpuMove)
                {
                    state[cpuMove] = cpuSym;
                    printState(state);
                    noOfMoves++;
                    continue;
                }

                cpuMove = nextMove(state);  // no obvious move possible then call nextMove function
                state[cpuMove] = cpuSym;
                printState(state);
                noOfMoves++;
            }
        }

        if (playerWon(state, cpuSym))       // after the game ends, check the result of the match
        {
            cout << "CPU won! :)\n";
        }
        else if (playerWon(state, humanSym))
        {
            cout << "Human won :(\n";
        }
        else
        {
            cout << "It'a a tie\n";
        }

        cout << "\nDo you want to play again? Yes-1, No-0: ";
        cin >> playerChoice;
        if (playerChoice == 0)
        {
            contPlay = 0;
            cout<<"Sayonara!";
        }
        cout << endl;
    }
}