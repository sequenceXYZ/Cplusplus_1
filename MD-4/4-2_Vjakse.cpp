#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h> // for getch() function on Windows

using namespace std;

int main() {
    // Masīva definēšana ar 20 vārdiem
    string words[20] = {
        "terraform", "ansible", "mysql", "java", "python",
        "snowflake", "aws", "linux", "microsoft", "docker",
        "virtualization", "github", "project", "networking", "bash",
        "jenkins", "confluence", "kubernetes", "nagios", "jira"
    };

    // Inicializējam gadījuma skaitļu ģeneratoru
    srand(time(0));

    // Izveidojām masīvu, kas uzglabā vārdus, kuri jau ir minēti
    bool usedWords[20] = { false };

    // Spēles mainīgie
    int penaltyPoints = 0;
    int maxPenaltyPoints = 10;
    int guessedWordsCount = 0;
    int totalWords = 20;

    while (penaltyPoints < maxPenaltyPoints && guessedWordsCount < totalWords) {
        // Izvēlamies gadījuma vārdu no masīva, kas nav atkārtots
        int randomIndex;
        do {
            randomIndex = rand() % 20;
        } while (usedWords[randomIndex]);

        usedWords[randomIndex] = true;

        string chosenWord = words[randomIndex];
        int wordLength = chosenWord.length();
        string guessedWord(wordLength, '.'); // Sākumā visi burti ir aizvietoti ar punktiem

        // Galvenais spēles cikls vienam vārdam
        char guess;
        bool isGuessed = false;

        cout << "\nUzminiet vaardu: " << guessedWord << endl;

        while (!isGuessed) {
            cout << "Ievadiet burtu (vai '0', lai izietu): ";
            guess = _getch(); // Get character without waiting for Enter key (for Windows)
            cout << guess << endl; // Echo the character

            if (guess == '0') {
                cout << "Jus izvelejaties iziet no speles." << endl;
                return 0;
            }

            bool found = false;
            for (int i = 0; i < wordLength; ++i) {
                if (chosenWord[i] == guess) {
                    guessedWord[i] = guess;
                    found = true;
                }
            }

            if (found) {
                cout << "Pareizi! Vaards paslaik: " << guessedWord << endl;
            }
            else {
                cout << "Nepareizi! Meeginiet velreiz.\n";
                penaltyPoints++;
                cout << "Soda punkti: " << penaltyPoints << endl;
                if (penaltyPoints >= maxPenaltyPoints) {
                    break;
                }
            }

            if (guessedWord == chosenWord) {
                isGuessed = true;
                guessedWordsCount++;
                cout << "Apsveicam! Jus uzminejaat vardu: " << chosenWord << endl;
                // Samazina soda punktus par 5, bet nedrīkst būt negatīvs soda punktu skaits
                penaltyPoints = max(0, penaltyPoints - 5);
                cout << "Soda punkti pec samazinasanas: " << penaltyPoints << endl;
            }
        }

        if (penaltyPoints >= maxPenaltyPoints) {
            break;
        }
    }

    if (guessedWordsCount == totalWords) {
        cout << "Apsveicam! Jus uzminejaat visus vaardus!" << endl;
    }
    else {
        cout << "Spele beigusies. Jus uzminejaat " << guessedWordsCount << " vaardus." << endl;
    }

    return 0;
}

