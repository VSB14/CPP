#include <bits/stdc++.h>

using namespace std;

int getCost(int A, int B, int X) {
    int redAr, blueAr;
    if (X == 1 || A == 1 || B == 1) {
        return 0;
        
    }
    redAr = A * B;
    blueAr = X * X;
    if (redAr <= blueAr) {
        return 0;
    }

    while (A > 0) {
        if (blueAr < redAr || blueAr != redAr) {

            return 1;
        }
        A--;
        redAr = A * B;

      
    }
   cout<<"A now: "<< A<<endl;
    while (B > 0) {
        if (blueAr < redAr || blueAr != redAr) {

            return 2;
        }
        B--;
        redAr = A * B;

    }
    return 0;
}

int main() {
    int n;
    cout<<"Enter test cases: ";
    cin >> n;
    while (n > 0) {
        int A, B, X, redAr, blueAr, res;
        cout<<"Enter Value for Test case "<<n<<": ";
        cin >> A >> B >> X;
        res = getCost(A, B, X);
        cout << res << endl;
        n--;
    }
    return 0;
}