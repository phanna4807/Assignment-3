#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to clean the string (removes spaces, punctuation, and converts to lowercase)
string cleanString(const string& str) {
    string cleaned;
    for (char c : str) {
        if (isalnum(c)) { // Keep only alphanumeric characters
            cleaned += tolower(c); // Convert to lowercase
        }
    }
    return cleaned;
}

// Recursive function to check if a string is a palindrome
bool isPalindrome(const string& str, int start, int end) {
    // Base case: If start >= end, it's a palindrome
    if (start >= end) {
        return true;
    }
    // Check if the first and last characters match
    if (str[start] != str[end]) {
        return false;
    }
    // Recursive call for the substring without the first and last characters
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string input;

    // Get the string input from the user
    cout << "Enter a word, phrase, or sentence: ";
    getline(cin, input);

    // Clean the input string
    string cleanedInput = cleanString(input);

    // Check if the cleaned string is a palindrome
    if (isPalindrome(cleanedInput, 0, cleanedInput.length() - 1)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    }
    else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}
