#include <iostream>
#include <cstring>
#include "clientData.h"

const int SIZE = 100;

void addRecord(clientData records[]) {
    int accNum;
    std::cout << "Ievadiet konta numuru (0-99): ";
    std::cin >> accNum;

    if (accNum < 0 || accNum >= SIZE) {
        std::cout << "Nepareizs konta numurs !" << std::endl;
        return;
    }

    if (records[accNum].accNum != -1) {
        std::cout << "Konts jau eksiste!" << std::endl;
        return;
    }

    records[accNum].accNum = accNum;
    std::cout << "Ievadiet uzvardu: ";
    std::cin >> records[accNum].Sur;
    std::cout << "Ievadiet vardu: ";
    std::cin >> records[accNum].Name;
    std::cout << "Ievadiet summu: ";
    std::cin >> records[accNum].balance;

    std::cout << "Ieraksts pievienots!" << std::endl;
}

void deleteRecord(clientData records[]) {
    int accNum;
    std::cout << "Ievadiet konta numuru (0-99) ko velaties izdzest: ";
    std::cin >> accNum;

    if (accNum < 0 || accNum >= SIZE || records[accNum].accNum == -1) {
        std::cout << "Konts nav atrasts!" << std::endl;
        return;
    }

    records[accNum].accNum = -1;
    std::cout << "Ieraksts ir izdzests!" << std::endl;
}

void displayRecords(const clientData records[]) {
    for (int i = 0; i < SIZE; ++i) {
        if (records[i].accNum != -1) {
            std::cout << "Konta numurs: " << records[i].accNum << std::endl;
            std::cout << "Uzvards: " << records[i].Sur << std::endl;
            std::cout << "Vards: " << records[i].Name << std::endl;
            std::cout << "Summa: " << records[i].balance << std::endl;
            std::cout << "--------------------------" << std::endl;
        }
    }
}

void findRecord(const clientData records[]) {
    int accNum;
    std::cout << "Ievadiet konta numuru (0-99) ko velaties atrast: ";
    std::cin >> accNum;

    if (accNum < 0 || accNum >= SIZE || records[accNum].accNum == -1) {
        std::cout << "Konts nav atrasts!" << std::endl;
        return;
    }

    std::cout << "Konta numurs: " << records[accNum].accNum << std::endl;
    std::cout << "uzvards: " << records[accNum].Sur << std::endl;
    std::cout << "Vards: " << records[accNum].Name << std::endl;
    std::cout << "Summa: " << records[accNum].balance << std::endl;
}

void updateBalance(clientData records[]) {
    int accNum;
    float amount;
    std::cout << "Ievadiet konta numuru (0-99): ";
    std::cin >> accNum;

    if (accNum < 0 || accNum >= SIZE || records[accNum].accNum == -1) {
        std::cout << "Konts nav atrasts!" << std::endl;
        return;
    }

    std::cout << "Ievadiet summmu, ko velaties pievienot/iznemt: ";
    std::cin >> amount;

    records[accNum].balance += amount;
    std::cout << "Konta atlikums ir atjaunots!" << std::endl;
}

void displayDebtors(const clientData records[]) {
    for (int i = 0; i < SIZE; ++i) {
        if (records[i].accNum != -1 && records[i].balance < 0) {
            std::cout << "Konta numurs: " << records[i].accNum << std::endl;
            std::cout << "Uzvards: " << records[i].Sur << std::endl;
            std::cout << "Vards: " << records[i].Name << std::endl;
            std::cout << "Summa: " << records[i].balance << std::endl;
            std::cout << "--------------------------" << std::endl;
        }
    }
}

void countRecords(const clientData records[]) {
    int count = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (records[i].accNum != -1) {
            ++count;
        }
    }
    std::cout << "Visi ieraksto: " << count << std::endl;
}

void displayMenu() {
    std::cout << "Galvena izvelne" << std::endl;
    std::cout << "1. Pievienot ierakstu" << std::endl;
    std::cout << "2. Dzest ierakstu" << std::endl;
    std::cout << "3. Izvadit visus ierakstus" << std::endl;
    std::cout << "4. Atrast ierakstu" << std::endl;
    std::cout << "5. Izmainit konta balansu" << std::endl;
    std::cout << "6. Izvadit paradniekus" << std::endl;
    std::cout << "7. Saskaitit ierakstus" << std::endl;
    std::cout << "8. Iziet" << std::endl;
}

int main() {
    clientData records[SIZE];

    // Initialize all records to -1 (indicating they are empty)
    for (int i = 0; i < SIZE; ++i) {
        records[i].accNum = -1;
    }

    int choice;
    do {
        displayMenu();
        std::cout << "Ievadiet savu izveli: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addRecord(records);
            break;
        case 2:
            deleteRecord(records);
            break;
        case 3:
            displayRecords(records);
            break;
        case 4:
            findRecord(records);
            break;
        case 5:
            updateBalance(records);
            break;
        case 6:
            displayDebtors(records);
            break;
        case 7:
            countRecords(records);
            break;
        case 8:
            std::cout << "Iziet no programmas..." << std::endl;
            break;
        default:
            std::cout << "Izvele nav deriga!" << std::endl;
        }
    } while (choice != 8);

    return 0;
}
