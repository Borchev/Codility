// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11 (g++ 4.8.2)
    
    int previousSegment = -1;
    int result = 0;
    
    for (unsigned int i = 0; i < A.size(); i++) {
        
        if (A[i] > previousSegment) {
        
            previousSegment = B[i];
            result++;
        
        }      
    }
    return result;
}