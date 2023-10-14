#include "Trip.h"
#include <iostream>
using namespace std;
bool IsEmpty(int size) {
    return size == 0;
}

void Print(Trip* arr, int size) {
    if (IsEmpty(size)) {
        cout << "No trips available." <<   endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        arr[i].printTrip();
        cout << "--------------------------" <<   endl;
    }
}

void EditTrip(Trip* arr, int size) {
    if (IsEmpty(size)) {
        std::cout << "No trips available." << std::endl;
        return;
    }

    int tripNum;
    std::cout << "Enter trip number for editing: ";
    std::cin >> tripNum;

    for (int i = 0; i < size; i++) {
        if (arr[i].getTripNum() == tripNum) {
            char dest[100];
            int day, month, year;

            std::cout << "Enter new destination: ";
            std::cin >> dest;
            arr[i].setDest(dest);

            std::cout << "Enter new day: ";
            std::cin >> day;
            std::cout << "Enter new month: ";
            std::cin >> month;
            std::cout << "Enter new year: ";
            std::cin >> year;
            arr[i].setDate(Date(day, month, year));

            return;
        }
    }
    std::cout << "Trip not found!" << std::endl;
}


Trip* AddTrip(Trip* arr, int &size) {
    char dest[100];
    int tripNum, day, month, year;

    std::cout << "Enter trip number: ";
    std::cin >> tripNum;

    std::cout << "Enter destination: ";
    std::cin >> dest;

    std::cout << "Enter day: ";
    std::cin >> day;
    std::cout << "Enter month: ";
    std::cin >> month;
    std::cout << "Enter year: ";
    std::cin >> year;

    Trip* newArr = new Trip[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = Trip(tripNum, dest, Date(day, month, year));
    delete[] arr;
    size++;
    return newArr;
}


int main() {
    int option;
    Trip* arr = new Trip[0];
    int size = 0;

    do {
          cout << "Please Select an option: \n1. Print Trips\n2. Edit Trip\n3. Add Trip\n4. Exit" <<   endl;
          cin >> option;

        switch (option) {
            case 1:
                Print(arr, size);
                break;
            case 2:
                EditTrip(arr, size);
                break;
            case 3:
                arr = AddTrip(arr, size);
                break;
            case 4:
                cout << "Bye bye!" <<   endl;
                delete[] arr;
                return 0;
            default:
                cout << "Invalid option" <<   endl;
                break;
        }
    } while (option != 4);
}
