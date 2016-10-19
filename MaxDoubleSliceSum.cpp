// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2) 
    
    pair<int,int> slices[A.size()];
    int listSize =  A.size();
    int result = 0;
    
    
    for (int i = 1; i < listSize - 1; i++) {
        
        slices[i].first = max(slices[i-1].first + A[i], 0);       
        slices[listSize - i - 1].second = max(slices[listSize - i].second + A[listSize - i - 1], 0);
        
    }
    
    for (unsigned int i = 0; i < A.size()-2; i++) {
        
        result = max(result, slices[i].first + slices[i+2].second);
    }
    
    return result;
}