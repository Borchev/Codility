// you can use includes, for example:
// #include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++11 (g++ 4.8.2)
    
    vector<int> bracket_stack;
    
    for (unsigned int i = 0; i < S.size(); i++) {
        
        switch(S[i]) {
            
            case '{':
            
            bracket_stack.push_back(0);
            
            break;
            case '[':
            
            bracket_stack.push_back(1);
            
            break;
            case '(':
            
            bracket_stack.push_back(2);
            
            break;
            case '}':
            
            if ((bracket_stack.size() > 0) && (bracket_stack.back() == 0)) bracket_stack.pop_back();
            else return 0;
            
            break;
            case ']':
            
            if ((bracket_stack.size() > 0) && (bracket_stack.back() == 1)) bracket_stack.pop_back();
            else return 0;
            
            break;
            case ')':
            
            if ((bracket_stack.size() > 0) && (bracket_stack.back() == 2)) bracket_stack.pop_back();
            else return 0;
            
            break;          
        }
        
    }
    return (bracket_stack.size() == 0);
}