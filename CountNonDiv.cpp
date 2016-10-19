// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    vector<int> instances((A.size() * 2 ) + 1, 0);
    vector<int> result;
    int count;
    
    for (unsigned int i = 0; i < A.size(); i++) instances[A[i]]++;
    
    for (unsigned int i = 0; i < A.size(); i++) {
        count = 0;
        for (int j = 1; j * j <= A[i]; j++) {
            if ((A[i] % j) == 0) {
                count += instances[j];
                if ((j * j) != A[i]) count += instances[A[i] / j];
            }
        }
        result.push_back(A.size() - count);
    }
    
    return result;
}