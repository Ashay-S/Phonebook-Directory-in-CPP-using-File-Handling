#include "phonebook.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

// Function to validate phone number
bool isValidPhoneNumber(const char* number) {
    int len = strlen(number);
    if (len != 10)
        return false;

    for (int i = 0; i < len; ++i) {
        if (number[i] < '0' || number[i] > '9')
            return false;
    }

    return true;
}

// Function to validate email
bool isValidEmail(const char* email) {
    return strchr(email, '@') != nullptr;
}

void PublicDirectory::menu() {
    while (true) {
        int choice;
        char name[20], phone[12], email[30];

        std::cout << "\n\n*****Public Town Phone Directory *****\n\n";
        std::cout << "Choose the operation you want to perform:\n";
        std::cout << "1. Add New Record\n";
        std::cout << "2. Display All Records\n";
        std::cout << "3. Search Telephone No.\n";
        std::cout << "4. Search Person by Name\n";
        std::cout << "5. Update Details\n";
        std::cout << "6. Delete a record \n";
        std::cout << "7. Exit\n\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Adding New Record:\n";
                std::cout << "Enter Name: ";
                std::cin >> name;
                std::cout << "Enter Phone No.: ";
                std::cin >> phone;
                while (!isValidPhoneNumber(phone)) {
                    std::cout << "Invalid Phone Number! Please enter again: ";
                    std::cin >> phone;
                }
                std::cout << "Enter Email: ";
                std::cin >> email;
                while (!isValidEmail(email)) {
                    std::cout << "Invalid Email! Please enter again: ";
                    std::cin >> email;
                }
                newRecord(name, phone, email);
                break;

            case 2:
                display();
                break;

            case 3:
                std::cout << "Enter Phone No. to search: ";
                std::cin >> phone;
                searchPhoneNumber(phone);
                break;

            case 4:
                std::cout << "Enter Name to search: ";
                std::cin >> name;
                searchName(name);
                break;

            case 5:
                std::cout << "Enter Name to update: ";
                std::cin >> name;
                updateRecord(name);
                break;

            case 6:
                std::cout << "Enter Name to delete: ";
                std::cin >> name;
                deleteRecord(name);
                break;

            case 7:
                std::cout << "Exiting Public Directory...\n";
                return;

            default:
                std::cout << "Invalid Option!\n";
        }
    }
}

void PrivateDirectory::menu() {
    std::string inputPassword;
    std::cout << "Enter the password: ";
    std::cin >> inputPassword;

    if (inputPassword == password) {
        while (true) {
            int choice;
            char name[20], phone[12], email[30];

            std::cout << "\n\n*****Private Town Phone Directory *****\n";
            std::cout << "Choose the operation you want to perform:\n";
            std::cout << "1. Add New Record\n";
            std::cout << "2. Display All Records\n";
            std::cout << "3. Search Telephone No.\n";
            std::cout << "4. Search Person by Name\n";
            std::cout << "5. Update Details\n";
            std::cout << "6. Delete a record \n";
            std::cout << "7. Exit\n\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Adding New Record:\n";
                    std::cout << "Enter Name: ";
                    std::cin >> name;
                    std::cout << "Enter Phone No.: ";
                    std::cin >> phone;
                    while (!isValidPhoneNumber(phone)) {
                        std::cout << "Invalid Phone Number! Please enter again: ";
                        std::cin >> phone;
                    }
                    std::cout << "Enter Email: ";
                    std::cin >> email;
                    while (!isValidEmail(email)) {
                        std::cout << "Invalid Email! Please enter again: ";
                        std::cin >> email;
                    }
                    newRecord(name, phone, email);
                    break;

                case 2:
                    display();
                    break;

                case 3:
                    std::cout << "Enter Phone No. to search: ";
                    std::cin >> phone;
                    searchPhoneNumber(phone);
                    break;

                case 4:
                    std::cout << "Enter Name to search: ";
                    std::cin >> name;
                    searchName(name);
                    break;

                case 5:
                    std::cout << "Enter Name to update: ";
                    std::cin >> name;
                    updateRecord(name);
                    break;

                case 6:
                    std::cout << "Enter Name to delete: ";
                    std::cin >> name;
                    deleteRecord(name);
                    break;

                case 7:
                    std::cout << "Exiting Private Directory...\n";
                    return;

                default:
                    std::cout << "Invalid Option!\n";
            }
        }
    } else {
        std::cout << "Wrong Password!!! Locking out...\n";
        return;
    }
}
