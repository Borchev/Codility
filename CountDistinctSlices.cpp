// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;



int solution(int M, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> visitedMap;
    visitedMap.assign(M + 1, -1);
    int start = -1;
    int end = 0;
    unsigned int result = 0;
    
    while ((unsigned)end < A.size()) {
        
        if (visitedMap[A[end]] > start) {   
            start = visitedMap[A[end]];     
        }
        
        result += end - start;
        if (result >= 1000000000) return 1000000000;
        
        visitedMap[A[end]] = end; 
        end++;
    }
    
    return result;
    
}