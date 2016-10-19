// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    if (A.size() == 0) return 0;
    int currentmin = A[0];
    int currentmax = 0;
    int temp;
    
    for (unsigned int i = 1; i < A.size(); i++) {
        if (A[i] < currentmin) {
            currentmin = A[i];
            continue;
        }
        
        temp = A[i] - currentmin;
        if (temp > currentmax) currentmax = temp;
        
    }
    
    return currentmax;
}