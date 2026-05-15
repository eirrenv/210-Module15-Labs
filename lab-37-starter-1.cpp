#include <iostream>
#include <string>
using namespace std;


long sum_ascii(string str);

int main() {
    string testString = "TESTING"; // test value, ASCII value should be 542

    cout << "ASCII Total: " << sum_ascii(testString);
    
    return 0;
}

long sum_ascii(string str) {
    long asciiTotal = 0;
    for (int i = 0; i < str.size(); ++i) {
        asciiTotal += (int) str[i];
    }
    return asciiTotal;
}
/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
