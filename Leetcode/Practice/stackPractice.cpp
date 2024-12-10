#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> st;
    string num = "123";
    st.push(num[1]);
    cout << "Stack Top when empty: " << st.top() << endl;
    cout << "Next" << endl;
    // push into stack
    st.push(num[2]);
    cout << "Stack Top when pushed: " << st.top() << endl;

    return 0;
}