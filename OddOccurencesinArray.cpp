// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int returnval = 0;
    // write your code in C++11 (g++ 4.8.2)
    for (unsigned int i = 0; i < A.size(); i++) {
        returnval ^= A[i];
    }
    
    return returnval;
}