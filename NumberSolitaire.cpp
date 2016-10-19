// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> B(A.size(), (1 << 31));
    
    B[0] = A[0];
    
    for (unsigned int i = 0; i < A.size(); i++) {
        for (int roll = 1; roll <= 6; roll++) {
            
            if ((i + roll) >= A.size()) continue;
            B[i + roll] = max(A[i + roll] + B[i], B[i + roll]);
               
        }
    }
    
    return B.back();
}