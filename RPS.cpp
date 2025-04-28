#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    string options[3] = {"Rock", "Paper", "Scissors"};
    int userChoice, cpuChoice;

    cout << "Rock(0), Paper(1), or Scissors(2)? ";
    cin >> userChoice;

    cpuChoice = rand() % 3;
    cout << "Computer chose: " << options[cpuChoice] << endl;

    if (userChoice == cpuChoice)
        cout << "It's a draw!" << endl;
    else if ((userChoice == 0 && cpuChoice == 2) ||
             (userChoice == 1 && cpuChoice == 0) ||
             (userChoice == 2 && cpuChoice == 1))
        cout << "You win!" << endl;
    else
        cout << "You lose!" << endl;

    return 0;
}
