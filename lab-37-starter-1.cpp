#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;


long gen_hash_index(string str);

int main() {

    map<int, list<string>> hash_table;

    string hashString;
    int hashInt = 0;

    ifstream hash("lab-37-data-3.txt");


    if (!hash) {
        cout << "Error opening file." << endl;
    }
    else {
        while(getline(hash, hashString)) {
            hashInt = gen_hash_index(hashString);

            hash_table[hashInt].push_back(hashString);
        }
    }

    hash.close();

    int count = 0;
    
    for (auto item : hash_table) {
        cout << "Hash index: " << item.first << endl;

        for (string code : item.second) {
            cout << "\t" << code << endl;
        }

        cout << endl;

        ++count;

        if (count == 100) {
            break;
        }
    }

    return 0;
}

long gen_hash_index(string str) {
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
