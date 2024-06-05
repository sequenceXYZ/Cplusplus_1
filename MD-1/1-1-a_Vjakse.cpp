#include <iostream>
using namespace std;

// Funkcija, kas paarbauda vai skaitlis ir palindroms
bool isPalindrome(int n) {
    int originalNumber = n;
    int reversedNumber = 0;

    // Apgriez skaitli
    while (n > 0) {
        int digit = n % 10;
        reversedNumber = reversedNumber * 10 + digit;
        n = n / 10;
    }

    // Saliidzina apgriezto skaitli ar saakotneejo
    return originalNumber == reversedNumber;
}

int main() {
    int n;

    // Prasa lietotaajam ievadiit skaitli
    cout << "Ievadiet skaitli: ";
    cin >> n;

    // Paarbauda vai skaitlis ir palindroms un izvada rezultaatu
    if (isPalindrome(n)) {
        cout << "Skaitlis " << n << " ir palindroms." << endl;
    }
    else {
        cout << "Skaitlis " << n << " nav palindroms." << endl;
    }
}