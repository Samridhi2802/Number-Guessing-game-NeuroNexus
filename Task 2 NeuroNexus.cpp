#include <iostream>
#include <cstdlib>
#include <ctime>

// Function prototypes
int generateSecretNumber();
int getUserGuess();
void evaluateGuess(int secretNumber, int guess, int& attempts, bool& hintUsed);

int main() {
    srand(time(nullptr));

    int secretNumber = generateSecretNumber();
    int guess;
    int attempts = 0;
    bool hintUsed = false;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    do {
        guess = getUserGuess();
        evaluateGuess(secretNumber, guess, attempts, hintUsed);
    } while (guess != secretNumber);

    return 0;
}

// Function to generate a random secret number
int generateSecretNumber() {
    return rand() % 51 + 50; // Generate a number between 50 and 100 (inclusive)
}

// Function to get user guess with input validation
int getUserGuess() {
    int guess;
    do {
        std::cout << "Enter your guess (between 1 and 100): ";
        std::cin >> guess;

        if (std::cin.fail() || guess < 1 || guess > 100) {
            std::cout << "Invalid input. Please enter a valid number between 1 and 100." << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        } else {
            break;
        }
    } while (true);

    return guess;
}

// Function to evaluate user's guess
void evaluateGuess(int secretNumber, int guess, int& attempts, bool& hintUsed) {
    ++attempts;

    std::cout << "Your guess is " << (guess < secretNumber ? "below" : (guess > secretNumber ? "above" : "correct"))
              << " the target.";

    if (!hintUsed && attempts > 1) {
        std::cout << " Hint: The secret number is even.";
        hintUsed = true;
    }

    std::cout << std::endl;

    if (guess == secretNumber) {
        std::cout << "Congratulations! You correctly identified the secret number " << secretNumber
                  << " in " << attempts << " attempts." << std::endl;
    }
}
