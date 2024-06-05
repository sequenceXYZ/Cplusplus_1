#ifndef CLIENTDATA_H
#define CLIENTDATA_H

struct clientData {
    int accNum;       // konta numurs
    char Sur[15];     // uzvārds
    char Name[10];    // vārds
    float balance;    // balanss (kontā esošā summa vai parāds)
};

void addRecord(clientData[]);
void deleteRecord(clientData[]);
void displayRecords(const clientData[]);
void findRecord(const clientData[]);
void updateBalance(clientData[]);
void displayDebtors(const clientData[]);
void countRecords(const clientData[]);
void displayMenu();

#endif

