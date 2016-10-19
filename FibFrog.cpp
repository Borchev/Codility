// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> fibSequenceGen(int maximum);

int solution(vector<int> &A) {    
    // write your code in C++11 (g++ 4.8.2)
    vector<int> fib = fibSequenceGen(A.size()); 
    vector<int> B;
    A.push_back(1);
    B.assign(A.size(), A.size() + 1);
    for (int i = -1; i < (signed)A.size() - 1; i++) {
       
        if ((i > -1) && ((B[i] == (signed)A.size() + 1) || (A[i] == 0))) continue;
    
        for (int j = 2; fib[j] + i < (signed)A.size(); j++) {
            int temp = fib[j] + i;
            if (A[temp] == 0) continue;
            B[temp] = min(B[temp], B[i] + 1);
                      
        }       
    }
    
    return ((unsigned)B.back() == A.size() + 1) ? -1: B.back();
}

vector<int> fibSequenceGen(int maximum) {
       
    vector<int> result_temp = {0, 1};
       
    for (int i = 2; i < 26; i++) {
        result_temp.push_back(result_temp[i-1] + result_temp[i-2]);  
    }
    
    return result_temp;
}