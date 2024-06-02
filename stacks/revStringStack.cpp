#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str = "krish";
    stack<char> st;
    for(int i=0;i<str.length();i++) {
        char ch = str[i];
        st.push(ch);
    }
    string result = "";
    while(!st.empty()) {
        char ch = st.top();
        result.push_back(ch);
        st.pop();
    }
    cout<<"The reversed string is : "<<result;
    return 0;
}