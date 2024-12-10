// C++ Program for appending multiple copies
// of the same character.
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str("Hello Geeks");

    // Appends 5 occurrences of '!'
    // to str
    str.append(5, '!');
    cout << str;
  
    return 0;
}
