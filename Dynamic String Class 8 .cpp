#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class String {
private:
    char *str;

public:
    // Default Constructor
    String() {
        str = new char[1];
        str[0] = '\0';
    }

    // Parameterized Constructor
    String(const char *s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy Constructor
    String(const String &s) {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Assignment Operator
    String& operator=(const String &s) {
        if (this != &s) {
            delete[] str;
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        return *this;
    }

    // Concatenation
    String operator+(const String &s) {
        String temp;
        delete[] temp.str;

        temp.str = new char[strlen(str) + strlen(s.str) + 1];
        strcpy(temp.str, str);
        strcat(temp.str, s.str);

        return temp;
    }

    // Comparison
    bool operator==(const String &s) {
        return strcmp(str, s.str) == 0;
    }

    // Reverse
    void reverse() {
        int n = strlen(str);
        for (int i = 0; i < n / 2; i++) {
            char t = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = t;
        }
    }

    // Count Vowels
    int countVowels() {
        int count = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            char ch = tolower(str[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u')
                count++;
        }
        return count;
    }

    // Convert to Uppercase
    void toUpper() {
        for (int i = 0; str[i] != '\0'; i++)
            str[i] = toupper(str[i]);
    }

    void display() {
        cout << str << endl;
    }
};

int main() {
    char s1[100], s2[100];

    cout << "Enter First String: ";
    cin.getline(s1, 100);

    cout << "Enter Second String: ";
    cin.getline(s2, 100);

    String A(s1);
    String B(s2);

    cout << "\nFirst String: ";
    A.display();

    cout << "Second String: ";
    B.display();

    // Concatenation
    String C = A + B;
    cout << "\nConcatenated String: ";
    C.display();

    // Comparison
    if (A == B)
        cout << "Strings are Equal\n";
    else
        cout << "Strings are Not Equal\n";

    // Reverse
    A.reverse();
    cout << "\nReverse of First String: ";
    A.display();

    // Vowel Count
    cout << "Number of Vowels: " << A.countVowels() << endl;

    // Uppercase
    A.toUpper();
    cout << "Uppercase String: ";
    A.display();

    return 0;
}
