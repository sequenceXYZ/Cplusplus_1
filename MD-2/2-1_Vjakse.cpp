#include <iostream>
#include <iomanip>

using namespace std;

double parkingFee(double hours) {
    // Minimalaa stavvietas maksa
    double minFee = 2.0;
    // Papildu maksa par stundu pec 3 stundaam
    double extraFeePerHour = 0.5;
    // Maksimlaa diennakts maksa
    double maxDailyFee = 10.0;

    // Nodroshina minimaalo stavvietas maksu
    if (hours <= 3) {
        return minFee;
    }

    // Aprekina papildu maksu, ja staaveshana ir ilgaaka par 3 stundaam
    double totalFee = minFee + (hours - 3) * extraFeePerHour;

    // Nodroshina, ka maksa nepaarsniedz maksimaalo diennakts maksu
    if (totalFee > maxDailyFee) {
        return maxDailyFee;
    }

    return totalFee;
}

int main() {
    double hours;

    cout << "Ievadiet stundu skaitu: ";
    cin >> hours;

    if (hours < 0) {
        cout << "Stundu skaitam jābūt pozitīvam skaitlim." << endl;
    }
    else {
        cout << "Stundas: " << hours << " -> Maksa: " << parkingFee(hours) << " Eur" << endl;
    }

    return 0;
}
