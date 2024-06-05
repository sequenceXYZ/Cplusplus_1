#include <iostream>
using namespace std;


// Funkcija, kas paarveido aatrumu no km/h uz m/sek pec formulas
double vms(double Vkmh) {
    return Vkmh * 1000.0 / 3600.0;
}

// Funkcija, kas apreekina tiksanaas laiku diviem pretii braucošiem objektiem
double timeWhenMeet(double kmh1, double kmh2, double km) {
    // Parveido aatrumus uz m/sek
    double v1 = vms(kmh1);
    double v2 = vms(kmh2);

    // Apreekina kopeejo aatrumu m/sek
    double total_speed = v1 + v2;

    // Apreekina tiksanaas laiku sekundees
    return (km * 1000) / total_speed;
}

int main() {
    double kmh1, kmh2, km;

    // Pieprasiit lietotaajam ievadiit aatrumus un attaalumu
    cout << "Ievadiet pirmaa objekta aatrumu (km/h): ";
    cin >> kmh1;
    cout << "Ievadiet otraa objekta aatrumu (km/h): ";
    cin >> kmh2;
    cout << "Ievadiet attaalumu starp objektiem (km): ";
    cin >> km;

    // Aprēķina un parāda tikšanās laiku sekundēs
    double timeSeconds = timeWhenMeet(kmh1, kmh2, km);
    cout << "Objektu tiksanas laiks: " << timeSeconds << " sekundes" << endl;

    return 0;
}
