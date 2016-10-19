// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    if (A.size() < 3) return 0;
    sort(A.begin(), A.end());   
    int max_1 = A[0] * A[1] * A[A.size()-1];
    int max_2 = A[A.size()-3] * A[A.size()-2] * A[A.size()-1];  
    return (max_1 > max_2) ? max_1 : max_2;
    
}