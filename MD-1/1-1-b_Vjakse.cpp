#include <iostream>
using namespace std;

// Funkcija, kas pārbauda vai skaitlis ir palindroms
bool isPalindrome(int n) {
    int originalNumber = n;
    int reversedNumber = 0;

    // Apgriež skaitli
    while (n > 0) {
        int digit = n % 10;
        reversedNumber = reversedNumber * 10 + digit;
        n = n / 10;
    }

    // Salīdzina apgriezto skaitli ar sākotnējo
    return originalNumber == reversedNumber;
}

int main() {
    cout << "Visi 6-ciparu palindromi ir:" << endl;

    // Cikls, kas pārbauda visus 6-ciparu skaitļus
    for (int i = 100000; i <= 999999; ++i) {
        if (isPalindrome(i)) {
            cout << i << endl;
        }
    }

    return 0;
}