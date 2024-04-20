#include <iostream>
#include <string>
using namespace std;

void replaceStandaloneNumbers(string& text) {
    for (size_t i = 0; i < text.length(); ) {
        // Check if the current character is a digit
        if (isdigit(text[i])) {
            size_t start = i;
            while (i < text.length() && isdigit(text[i])) {
                i++;
            }
            size_t end = i;

            // Check if the digit sequence is standalone
            bool isStandalone = (start == 0 || text[start - 1] == ' ') &&
                                (end == text.length() || text[end] == ' ');

            // Replace the standalone number with 'x's
            if (isStandalone) {
                for (size_t j = start; j < end; j++) {
                    text[j] = 'x';
                }
            }
        } else {
            i++;
        }
    }
}

bool isdigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int main() {
    string lineOfText;
    cout << "Please enter a line of text: " << endl;
    getline(cin, lineOfText);
    replaceStandaloneNumbers(lineOfText);
    cout << lineOfText;

    return 0;
}

//My userID is john17 and my 4 digit pin is 1234 which is secret