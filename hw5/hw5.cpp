#include <iostream>
#include <string.h>
#include <stdbool.h>

using namespace std;

#include "date.h"
#include "cake.h"
#include "musseCake.h"
#include "birthdayCake.h"

Cake* cakeArr;
int cakeLength = 0;

Date& dateInput() {
    int year, month, day;
    cout << "Enter a year: ";
    cin >> year;
    cout << "\nEnter a month: ";
    cin >> month;
    cout << "\nEnter a day: ";
    cin >> day;

    return Date(
        day,
        month,
        year
    );
}

Cake& cakeInput() {
    Date dt = dateInput();
    
    int diameter, storage;
    double height, price;
    
    bool glutenFree;

    cout << "Enter the diameter: ";
    cin >> diameter;
    cout << "\nEnter the height: ";
    cin >> height;
    cout << "\nEnter the price: ";
    cin >> price;
    cout << "\nPick storage type, 1. for Refrigeretor, 2. for nothing: ";
    cin >> storage;
    cout << "\nGluten Free? (true of false): ";
    cin >> glutenFree;

    return Cake(
        dt,
        diameter,
        height,
        price,
        storage,
        glutenFree
    );
}

void appendNewCake(Cake &cake) {
    Cake* tmp = new Cake[cakeLength+1];

    for(int i=0; i<cakeLength; i++) {
        tmp[i] = cakeArr[i];
    }

    delete[] cakeArr;

    cakeLength++;

    tmp[cakeLength] = cake;
    cakeArr = tmp;

    delete[] tmp;
}

void createCake() {
    appendNewCake(cakeInput());
}   

void createBirthdayCake() {
    BirthdayCake bc = cakeInput();

    const char* text = new char[bc.getDiameter()];

    cout << "Enter a text: ";
    cin.ignore();
    cin.getline(text, bc.getDiameter());

    bc.setText(text);

    delete[] text;

    appendNewCake(bc);
}

void createMusseCake() {
    MusseCake mc = cakeInput();

    const char* taste = new char[mc.getDiameter()];

    cout << "Enter the taste: ";
    cin.ignore();
    cin.getline(taste, mc.getDiameter());

    mc.setTaste(taste);

    delete[] taste;

    appendNewCake(mc);
}

void printAllCakes() {
    for(int i=0; i<cakeLength; i++) {
        cout << cakeArr[i] << endl;
    }
}

int main() {
    int op;
    do {
        cout << "1 for Cake\n2 for birthdayCake\n3 for musseCake\n4 to print all cakes\n5 to exit" << endl;
        cin >> op;

        switch (op) {
            case 1:
                createCake();
                break;
            case 2:
                createBirthdayCake();
                break;
            case 3:
                createMusseCake();
                break;
            case 4:
                printAllCakes();
                break;
            default:
                cout << op << " is not a valid option" << endl;
                continue
        }
    } while (op != 5);

    cout << "bye bye!" << endl;

    for(int i=0; i<cakeLength; i++) {
        delete cakeArr[i];
    }

    delete[] cakeArr;
    
    return 1;
}