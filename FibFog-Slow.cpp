// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> fibSequenceGen(int maximum);

int solution(vector<int> &A) {    
    // write your code in C++11 (g++ 4.8.2)
    vector<int> fib = fibSequenceGen(A.size()); 
    A.push_back(1);
    vector<int> B;
    B.assign(A.size(), A.size() + 1);
    for (int i = -1; i < (signed)A.size() - 1; i++) {
        if ((i >= 0) && ((A[i] == 0) || (B[i] >= B.back()))) continue;       
        for (unsigned int j = i + 1; j < A.size(); j++) {
            if ((fib[j - i] == 1) && (A[j] == 1)) {             
                B[j] = min(B[i] + 1, B[j]);
            }  
        }       
    }
    
    return ((unsigned)B.back() == A.size() + 1) ? -1: B.back();
}

vector<int> fibSequenceGen(int maximum) {
       
    vector<int> result_temp = {0, 1};
    vector<int> result = {0, 1, 1};
    result.resize(maximum+2);
       
    for (int i = 2; i < 26; i++) {
        result_temp.push_back(result_temp[i-1] + result_temp[i-2]);  
        result[result_temp.back()] = 1;
        if (result_temp.back() > maximum) break;
        
    }
    
    return result;
}