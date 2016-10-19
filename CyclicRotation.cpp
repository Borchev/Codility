// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    if (A.size() == 0) return {};
    vector<int> result;
    K = K % A.size();
    
    for (unsigned int i = 0; i < A.size(); i++) {     
        result.push_back(A.at((i + (A.size() - K)) % A.size() ));       
    }
    
    return result;
}