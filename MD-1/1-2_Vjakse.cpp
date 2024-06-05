#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Inicialize nejausu skaitlu generatoru
    int secretNumber = rand() % 101; // Genere nejausu skaitli no 0 lidz 100
    int guess;
    int attempts = 0;
    const int maxAttempts = 10;

    cout << "Uzmini skaitli no 0 lidz 100!" << endl;

    while (attempts < maxAttempts) {
        cout << "Ievadiet savu minejumu: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Skaitlis ir lielaks par ievadito." << endl;
        }
        else if (guess > secretNumber) {
            cout << "Skaitlis ir mazaks par ievadito." << endl;
        }
        else {
            cout << "Skaitlis uzminets no " << attempts << " meginajuma!" << endl;
            return 0;
        }
    }

    cout << "Jus zaudajat! Pareiza atbilde ir " << secretNumber << endl;
    return 0;
}
