// Created by sjyan @2017-07-27

#include <iostream>
#include <stack>
#include <string>
using namespace std;

void remove_bracket(string &str) {
    int length = str.length();
    stack<int> left;
    
    if (length == 0)    return;
    
    for (int i=0; i<length; i++) {
        if (str[i] == '(') {
            left.push(i);
        }
        else {
            if (str[i] == ')') {
                if (!left.empty()) {
                    str.erase(i, 1);
                    i--;
                    int left_pos = left.top();
                    left.pop();
                    str.erase(left_pos, 1);
                    i--;
                    length-=2;
                }
            }
        }
    }
}

int main() {
    string str = "ab(c()(";
    remove_bracket(str);
    cout<<str<<endl;
    return 0;
}