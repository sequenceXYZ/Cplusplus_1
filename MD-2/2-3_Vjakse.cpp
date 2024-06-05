#include <iostream>
using namespace std;


// Rekursiivaa funkcija, kas apreekina Lielaako Kopeejo Dalitaju diviem skaitļiem x un y
int LKD(int x, int y) {
    // ja y ir 0, tad LKD ir x
    if (y == 0) {
        return x;
    }
    /* LKD diviem skaitļiem x un y (kur x >= y) ir tas pats, kas LKD no y un atlikuma, 
    kad x tiek dalīts ar y (apzīmēts kā x % y)*/
    return LKD(y, x % y);
}

int main() {
    int x, y;

    // Pieprasīt lietotājam ievadīt divus skaitļus
    cout << "Ievadiet pirmo skaitli: ";
    cin >> x;
    cout << "Ievadiet otro skaitli: ";
    cin >> y;

    // Aprēķina un parāda LKD
    int result = LKD(x, y);
    cout << "Lielakais kopiigais daliitaajs: " << result << endl;

    return 0;
}
