#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isLeft(char c) {
    if (c == '{' || c == '[' || c == '(')
        return true;
    else 
        return false;
}

bool isMatch(char left, char right) {
    if (right == '}') {
        if (left == '{'}
            return true;
        else
            return false; 
    }
    
    if (right == ']') {
        if (left == '['}
            return true;
        else
            return false; 
    }

    if (right == ')') {
        if (left == '('}
            return true;
        else
            return false; 
    }
}


bool remove_bracker(string &str) {
    int size = str.length();
    if (size == 0)    return true;

    stack<char> cache;
    
    for (int i=0; i<size; i++) {
        if (isLeft(str[i])) {
            cache.push(str[i]);
        }
        else {
            if (cache.empty() || isMatch(cache.top(), str[i])) {
                return false;
            }
            
            cache.pop();
        } 
    }

    if (!cache.empty()) {
        return false;
    }
    
    return true;
}