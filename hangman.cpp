#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Hangman {
private:
    vector<string> wordList = {
    "algorithm", "compiler", "recursion", "inheritance", "database",
    "pointer", "function", "variable", "loop", "object"
};

    string wordToGuess;
    string guessedWord;
    vector<char> wrongGuesses;
    int maxAttempts = 6;

    void chooseRandomWord() {
        srand(time(0));
        wordToGuess = wordList[rand() % wordList.size()];
        guessedWord = string(wordToGuess.length(), '_');
    }

    void displayWord() {
        for (char c : guessedWord) cout << c << ' ';
        cout << endl;
    }

    void drawHangman(int attemptsLeft) {
        string stages[] = {
            " +---+\n     |\n     |\n     |\n    ===",
            " +---+\n O   |\n     |\n     |\n    ===",
            " +---+\n O   |\n |   |\n     |\n    ===",
            " +---+\n O   |\n/|   |\n     |\n    ===",
            " +---+\n O   |\n/|\\  |\n     |\n    ===",
            " +---+\n O   |\n/|\\  |\n/    |\n    ===",
            " +---+\n O   |\n/|\\  |\n/ \\  |\n    ==="
        };
        cout << stages[maxAttempts - attemptsLeft] << endl;
    }

public:
    void play() {
        chooseRandomWord();
        int attemptsLeft = maxAttempts;

        while (attemptsLeft > 0 && guessedWord != wordToGuess) {
            cout << "\nWord: ";
            displayWord();
            drawHangman(attemptsLeft);
            cout << "Wrong guesses: ";
            for (char c : wrongGuesses) cout << c << ' ';
            cout << "\nGuess a letter: ";
            char guess;
            cin >> guess;
            guess = tolower(guess);

            if (!isalpha(guess)) {
                cout << " Invalid input. Please enter a letter.\n";
                continue;
            }

            if (guessedWord.find(guess) != string::npos || 
                find(wrongGuesses.begin(), wrongGuesses.end(), guess) != wrongGuesses.end()) {
                cout << " You've already guessed that letter!\n";
                continue;
            }

            bool correct = false;
            for (int i = 0; i < wordToGuess.length(); i++) {
                if (wordToGuess[i] == guess) {
                    guessedWord[i] = guess;
                    correct = true;
                }
            }

            if (!correct) {
                wrongGuesses.push_back(guess);
                attemptsLeft--;
            }
        }

        if (guessedWord == wordToGuess) {
            cout << "\n You won! The word was: " << wordToGuess << endl;
        } else {
            drawHangman(0);
            cout << "\n You lost. The word was: " << wordToGuess << endl;
        }
    }
};

int main() {
    Hangman game;
    game.play();
    return 0;
}
