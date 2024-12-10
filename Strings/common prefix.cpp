#include <iostream>
#include <string>
#include <vector> // Include only necessary header for strings
using namespace std;

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    char secondLetter = strs[0][4]; // Access the second character (index 1)
    cout << secondLetter << endl;   // Print with newline
    return 0;
}
