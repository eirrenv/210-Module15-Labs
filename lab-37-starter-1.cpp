#include <iostream>
#include <string>
using namespace std;


int main() {
    string testString = "TESTING"; // test value, ASCII value should be 542

    int asciiTotal = 0;
    for (int i = 0; i < testString.size(); ++i) {
        asciiTotal += (int) testString[i];
    }
    cout << "ASCII Total: " << asciiTotal << endl;
    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
