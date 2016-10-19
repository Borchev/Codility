// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
 
    int max = 1;
    int xorexpected = 0;
    int xorencountered = 0;
    int result;

    for (unsigned int i = 0; i < A.size(); i++) {       
        if (A[i] > max) max = A[i];      
        xorencountered ^= A[i];      
    }
    
    if (max != A.size()) return 0;
    
    for (int i = 1; i <= max; i++) {
        xorexpected ^= i;
    }
    
    result = (xorexpected ^ xorencountered);
    
    if (result > 0) return 0;
    else return 1;
}