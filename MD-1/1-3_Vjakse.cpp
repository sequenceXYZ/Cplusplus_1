#include <iostream>
using namespace std;

int main() {
    int low = 1;
    int high = 100;
    int guess;
    int attempts = 0;
    const int maxAttempts = 10;
    char response;

    cout << "Izdomaajiet skaitli no 1 liidz 100, un es meeginasu to uzmineet." << endl;

    while (low <= high && attempts < maxAttempts) {
        guess = low + (high - low) / 2;
        attempts++;

        cout << "Vai skaitlis ir " << guess << "? (lielaaks/mazaaks/pareizs) (L/M/P): ";
        cin >> response;

        if (response == 'P' || response == 'p') {
            cout << "Es uzmineeju skaitli ar " << attempts << " meginaajumu!" << endl;
            return 0;
        }
        else if (response == 'L' || response == 'l') {
            low = guess + 1;
        }
        else if (response == 'M' || response == 'm') {
            high = guess - 1;
        }
        else {
            cout << "Nederiiga ievade. Luudzu, ievadiet 'L' (lielaaks), 'M' (mazaaks) vai 'P' (pareizi)." << endl;
            attempts--; // Neskaita nederīgu ievadi kā mēģinājumu
        }
    }

    cout << "Es nespeeju uzmineet skaitli ar 10 meeginaajumiem." << endl;
    return 0;
}