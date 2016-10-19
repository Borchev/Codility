// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    sort(A.begin(),A.end());
    
    unsigned int pp, qp, rp;
    int result = 0;

    for (pp = 0; pp < max((signed)A.size() - 2, 0); ++pp) {
    
        qp = pp + 1;
        
        for (rp = pp + 2; rp < A.size(); ++rp) {
            
            if (A[rp] < A[qp] + A[pp]) result += rp - qp;
            else {
                qp++;
                if (rp != qp) rp--;
            }               
        } 
    }
    return result;
}