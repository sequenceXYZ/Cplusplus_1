#include <iostream>
#include <regex>
using namespace std;

bool checkIfValidTime(const string& input) {
    regex validTime("^([0-1][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$");
    return regex_match(input, validTime);
}

void checkTime(const string& time) {
    if (!checkIfValidTime(time)) {
        cout << time << " - nepareizs formaats vai nepareizs laiks" << endl;
    }
    else {
        cout << time << " - pareizs laika formaats" << endl;
    }
}

int main() {
    string time;
    cout << "Ievadiet laiku formaataa hh:mm:ss: ";
    cin >> time;

    checkTime(time);

    return 0;
}
