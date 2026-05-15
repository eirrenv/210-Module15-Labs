#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;


long gen_hash_index(string str);

void menu(map<int, list<string>>& table);

int main() {

    map<int, list<string>> hash_table;

    string hashString;
    int hashInt = 0;

    ifstream hash("lab-37-data-3.txt");


    if (!hash) {
        cout << "Error opening file." << endl;
        return 1;
    }
    else {
        while(getline(hash, hashString)) {
            hashInt = gen_hash_index(hashString);

            hash_table[hashInt].push_back(hashString);
        }
    }

    menu(hash_table);

    hash.close();

    return 0;
}

long gen_hash_index(string str) {
    long asciiTotal = 0;
    for (int i = 0; i < str.size(); ++i) {
        asciiTotal += (int) str[i];
    }
    return asciiTotal;
}

void menu(map<int, list<string>>& table) {
    int choice = 1;
    cout << "Please choose an option:" << endl;
    cout << "[1] - Print first 100 table entries" << endl;
    cout << "[2] - Search for a key" << endl;
    cout << "[3] - Add key to table" << endl;
    cout << "[4] - Remove key from table" << endl;
    cout << "[5] - Modify key in table" << endl;
    cout << "[6] - Exit program" << endl;
    cout << "Choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
        {
            int count = 0;
            for (auto item : table) {
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
            break;
        }
        case 2:
        {
            string key;
            cout << "Please input the key to search for: ";
            cin.ignore();
            getline(cin, key);
            long hashIndex = gen_hash_index(key);
            auto location = table.find(hashIndex);
            bool found = false;

            if (location != table.end()) {
                for (string value : location->second) {
                    if (value == key) {
                        found = true;
                        break;
                    }
                }
            }
            if (found) {
                cout << "Key is in table." << endl;
            }
            else {
                cout << "Key is not in table." << endl;
            }
            break;
        }

        case 3:
        {
            string key;
            cout << "Please input the key to add: ";
            cin.ignore();
            getline(cin, key);

            long hashInt = gen_hash_index(key);

            table[hashInt].push_back(key);
            cout << "Key added to table." << endl;

            break;
        }

        case 4:
        {   
            string key;
            cout << "Please input the key to remove: ";
            cin.ignore();
            getline(cin, key);

            long hashIndex = gen_hash_index(key);

            auto location = table.find(hashIndex);
            bool removed = false;

            if (location != table.end()) {
                for (auto it = location->second.begin();
                    it != location->second.end();
                    ++it)
                {
                    if (*it == key) {
                        location->second.erase(it);
                        removed = true;
                        break;
                    }
                }

                if (location->second.empty()) {
                    table.erase(location);
                }
            }

            if (removed) {
                cout << "Key removed." << endl;
            }
            else {
                cout << "Key not in table." << endl;
            }

            break;
        }

        default:
        {
            cout << "Invalid input. Please input another option." << endl;
            break;
        }
    }
}
/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
