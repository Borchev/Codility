// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int carstack = 0;
    int carsum = 0;
    
    for (unsigned int i = 0; i < A.size(); i++) {
        
        if (A[i] == 0) carstack++;
        if (A[i] == 1) carsum += carstack;
        if (carsum > 1000000000) return -1;
        
    }
    
    return carsum;
}