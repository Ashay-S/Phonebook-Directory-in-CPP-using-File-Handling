#include <iostream>
#include "phonebook.h"

using namespace std;

int main() {
    PhoneDirectory publicDirectory("public.txt");
    PrivateDirectory privateDirectory("private.txt", "1234");

    int choice;

    while (true) {
        cout << "\n\n*****Digital Town Phone Directory *****\n\n";
        cout << "Choose the operation you want to perform:\n";
        cout << "1. Public File\n";
        cout << "2. Private File\n";
        cout << "3. Emergency Contact No\n";
        cout << "Any other key to exit.\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                publicDirectory.menu();
                break;

            case 2:
                privateDirectory.menu();
                break;

            case 3:
                PhoneDirectory::showEmergencyContacts();
                break;

            default:
                cout << "Exiting...\n";
                return 0;
        }
    }

    return 0;
}
