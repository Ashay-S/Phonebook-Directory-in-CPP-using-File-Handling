#include <iostream>
#include <fstream>
#include <iomanip>

class PhoneDirectory {
protected:
    std::fstream file;

public:
    PhoneDirectory(const std::string& filename) {
        file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            exit(1);
        }
    }

    virtual void menu() = 0;

    static void showEmergencyContacts() {
        std::cout << "\n\nFOLLOWING ARE THE EMERGENCY NUMBERS:\n\n"
                  << "1. Police - 100\n"
                  << "2. Fire Brigade - 101\n"
                  << "3. Ambulance and Health Services - 102\n"
                  << "4. Women Helpline - 1091\n"
                  << "5. National Emergency Number - 112\n";
    }

    ~PhoneDirectory() {
        file.close();
    }
};

class PublicDirectory : public PhoneDirectory {
public:
    PublicDirectory(const std::string& filename) : PhoneDirectory(filename) {}

    void menu() override;
};

class PrivateDirectory : public PhoneDirectory {
    std::string password;

public:
    PrivateDirectory(const std::string& filename, const std::string& pw) : PhoneDirectory(filename), password(pw) {}

    void menu() override;
};
