// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
vector<unsigned int> fibGen(int L);

vector<int> solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11 (g++ 4.8.2)
    vector<unsigned int> fibSeq = fibGen(A.size());
    vector<int> result;
    
    for (unsigned int i = 0; i < A.size(); i++) {
        result.push_back(fibSeq[A[i]+1] % (int)pow(2,B[i]));
    }
    return result;
}

vector<unsigned int> fibGen(int L) {
    
    vector<unsigned int> result = {0,1};
    
    for (int i = 2; i <= L + 1; i++) {
    
        result.push_back(result[i-1] + result[i-2]);
    }
    return result;
}