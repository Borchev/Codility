// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    if (A.size() < 3) return 0;
    // write your code in C++11 (g++ 4.8.2)
    vector<int> result;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > 100000) A[i] = 100000; 
    }

    sort(A.begin(),A.end());
    
    for (int i = 0; i < A.size() - 2; i++) {
        if (A[i] < 0) continue;
        
        if ((A[i] + A[i+1]) > A[i+2]) {
            return 1;
        }
    
    }
            
    return 0;
}