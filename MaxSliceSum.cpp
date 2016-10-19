// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2) 
    int maximum = A[0];
    int slices = maximum;

    for (unsigned int i = 1; i < A.size(); i++) {
                
        slices = max(A[i] + slices, A[i]);
        maximum = max(maximum,slices);
    }
    
    return maximum;
}