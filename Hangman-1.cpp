#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<string> words = {"computer", "science", "hangman", "programming", "wizard", "galaxy"};

void displayWord(const string& word, const vector<bool>& guessed) {
    for (int i = 0; i < word.length(); ++i) {
        if (guessed[i])
            cout << word[i] << " ";
        else
            cout << "_ ";
    }
    cout << endl;
}

bool isWordGuessed(const vector<bool>& guessed) {
    for (bool letter : guessed) {
        if (!letter) return false;
    }
    return true;
}

int main() {
    srand(time(0));
    string word = words[rand() % words.size()];
    vector<bool> guessed(word.length(), false);
    int lives = 6;
    char guess;

    cout << "===== Welcome to Hangman! =====\n";
    
    while (lives > 0) {
        cout << "\nLives remaining: " << lives << endl;
        displayWord(word, guessed);

        cout << "Enter a letter: ";
        cin >> guess;
        guess = tolower(guess);

        bool found = false;
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] == guess) {
                guessed[i] = true;
                found = true;
            }
        }

        if (!found) {
            cout << "Wrong guess!\n";
            lives--;
        }

        if (isWordGuessed(guessed)) {
            cout << "\nCongratulations! You guessed the word: " << word << endl;
            break;
        }
    }

    if (lives == 0) {
        cout << "\nYou lost! The word was: " << word << endl;
    }

    return 0;
}

