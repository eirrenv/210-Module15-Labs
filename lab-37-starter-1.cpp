#include <iostream>
#include <string>
#include <fstream>
using namespace std;


long sum_ascii(string str);

int main() {
    string hashString;
    long long hashTotal = 0;

    ifstream hash("lab-37-data-3.txt");


    if (!hash) {
        cout << "Error opening file." << endl;
    }
    else {
        while(getline(hash, hashString)) {
            hashTotal += sum_ascii(hashString);
        }
    }

    cout << "ASCII Total: " << hashTotal;

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
