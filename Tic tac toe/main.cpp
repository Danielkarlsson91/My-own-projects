#include <ctime>
#include <iostream>

// Function declarations
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkTheWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    char playAgain; // Variable to store user's decision to play again

    do
    {
        // Initialize the game board with empty spaces
        char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        char player = 'P';   // Character representing the player
        char computer = 'C'; // Character representing the computer
        bool running = true; // Game running state

        // Draw the initial empty board
        drawBoard(spaces);

        // Main game loop
        while (running)
        {
            // Player's turn
            playerMove(spaces, player);
            drawBoard(spaces);
            if (checkTheWinner(spaces, player, computer))
            {
                running = false; // End the game if there is a winner
                break;
            }
            else if (checkTie(spaces))
            {
                running = false; // End the game if there is a tie
                break;
            }

            // Computer's turn
            computerMove(spaces, computer);
            drawBoard(spaces);
            if (checkTheWinner(spaces, player, computer))
            {
                running = false; // End the game if there is a winner
                break;
            }
            else if (checkTie(spaces))
            {
                running = false; // End the game if there is a tie
                break;
            }
        }

        // Ask the user if they want to play again
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y'); // Continue if the user inputs 'y' or 'Y'

    std::cout << "Thank you for playing!\n";

    return 0;
}

// Function to draw the game board
void drawBoard(char *spaces)
{
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

// Function to handle the player's move
void playerMove(char *spaces, char player)
{
    int number;
    do
    {
        std::cout << "What spot would you like to enter? (1-9) ";
        std::cin >> number;
        number--;

        // Check if the selected spot is valid and empty
        if (number >= 0 && number < 9 && spaces[number] == ' ')
        {
            spaces[number] = player; // Place the player's marker
            break;
        }
        else
        {
            std::cout << "Invalid move. Try again.\n";
        }

    } while (true); // Repeat until a valid move is made
}

// Function to handle the computer's move
void computerMove(char *spaces, char computer)
{
    int number;
    srand(time(0)); // Seed the random number generator

    while (true)
    {
        number = rand() % 9; // Generate a random spot
        if (spaces[number] == ' ')
        {
            spaces[number] = computer; // Place the computer's marker
            break;
        }
    }
}

// Function to check if there is a winner
bool checkTheWinner(char *spaces, char player, char computer)
{
    for (int i = 0; i < 3; ++i)
    {
        // Check rows for a win
        if (spaces[i * 3] != ' ' && spaces[i * 3] == spaces[i * 3 + 1] && spaces[i * 3 + 1] == spaces[i * 3 + 2])
        {
            spaces[i * 3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            return true;
        }
        // Check columns for a win
        if (spaces[i] != ' ' && spaces[i] == spaces[i + 3] && spaces[i + 3] == spaces[i + 6])
        {
            spaces[i] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            return true;
        }
    }
    // Check diagonals for a win
    if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
        return true;
    }
    if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
        return true;
    }
    return false;
}

// Function to check if the game is a tie
bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false; // If any spot is empty, it's not a tie
        }
    }

    std::cout << "It's a draw!\n";
    return true; // All spots are filled and it's a tie
}
