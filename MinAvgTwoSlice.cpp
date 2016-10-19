// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    double min = (1 << sizeof(int) * 8 - 1) - 1;
    int index = 0;
    double bestoftwo, bestofthree;
    
    for (unsigned int i = 0; i < A.size() - 1; i++) {
        
        bestoftwo = (A[i] + A[i+1]) / 2.0;
        bestofthree = (A[i] + A[i+1] + A[i+2]) / 3.0;
        
        if (bestoftwo < min) {
            min = bestoftwo;
            index = i;
        }
 
        if ((bestofthree < min) && (i < A.size() - 2)) {
            min = bestofthree;
            index = i;
        }

    }
    
    return index;
}