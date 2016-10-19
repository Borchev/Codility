// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    int runningCount = 0;
    int result = 0;
    
    for (unsigned int i = 0; i < A.size(); i++) {
        
        runningCount += A[i];
        if (runningCount >= K) {
            result++;
            runningCount = 0;
        }    
    }
    return result;
}