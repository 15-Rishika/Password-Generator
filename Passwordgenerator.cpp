#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int length;
    char useUpper, useLower, useNumbers, useSpecial;

    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string numbers = "0123456789";
    string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    string allChars = "";

    cout << "===== Password Generator =====\n";

    cout << "Enter password length: ";
    cin >> length;

    cout << "Include Uppercase letters? (y/n): ";
    cin >> useUpper;

    cout << "Include Lowercase letters? (y/n): ";
    cin >> useLower;

    cout << "Include Numbers? (y/n): ";
    cin >> useNumbers;

    cout << "Include Special characters? (y/n): ";
    cin >> useSpecial;

    // Build character set
    if (useUpper == 'y' || useUpper == 'Y')
        allChars += upper;

    if (useLower == 'y' || useLower == 'Y')
        allChars += lower;

    if (useNumbers == 'y' || useNumbers == 'Y')
        allChars += numbers;

    if (useSpecial == 'y' || useSpecial == 'Y')
        allChars += special;

    // Check if at least one option selected
    if (allChars.empty()) {
        cout << "Error: No character set selected!\n";
        return 0;
    }

    // Initialize random seed
    srand(time(0));

    string password = "";

    // Generate password
    for (int i = 0; i < length; i++) {
        int index = rand() % allChars.length();
        password += allChars[index];
    }

    cout << "\nGenerated Password: " << password << endl;

    return 0;
}