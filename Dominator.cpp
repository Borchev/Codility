// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    pair<int,int> leader;
    int count = 0;
    
    for (unsigned int i = 0; i < A.size(); i++) {
        
        if (leader.second == 0) {
            leader.first = A[i];
            leader.second++;
        } else if (leader.first == A[i]) leader.second++;
        else leader.second--;    
    }
    
    for (unsigned int i = 0; i < A.size(); i++) {
        
        if (A[i] == leader.first) count++;
        if (count > ceil((A.size() - 1) / 2.0)) return i;       
    }
    
    
    return -1;
}