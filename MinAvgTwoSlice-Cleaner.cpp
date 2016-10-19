// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    double min = (A[0] + A[1]) / 2.0;
    int index = 0;
    double bestoftwo, bestofthree;
    
    for (unsigned int i = 2; i < A.size(); i++) {
        
        bestoftwo = (A[i] + A[i-1]) / 2.0;
        bestofthree = (A[i] + A[i-1] + A[i-2]) / 3.0;
        
        if (bestoftwo < min) {
            min = bestoftwo;
            index = i - 1;
        }
 
        if (bestofthree < min) {
            min = bestofthree;
            index = i - 2;
        }

    }
    
    return index;
}