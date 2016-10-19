// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    vector<int> result;
    vector<int> result_sorted;
    result_sorted.resize(A.size());
    vector<pair<int,int>> indexed_A;
    int temp ;
      
    for (unsigned int i = 0; i < A.size(); i++) {
        indexed_A.push_back(pair<int,int> {A[i],i});      
    }
    
    sort(indexed_A.begin(), indexed_A.end(), [](const pair<int,int> a, const pair<int,int> b){ return a < b;});
     
    for (unsigned int i = 0; i < indexed_A.size(); i++) {
        
        temp = 0;
        
        if ((i > 0) && (indexed_A[i].first == indexed_A[i-1].first)) {
            result.push_back(result.back());
            continue;
        }
              
        for (unsigned int j = 0; j < indexed_A.size(); j++) {
            
            if (indexed_A[i].first == indexed_A[j].first) continue;
            if ((indexed_A[i].first % indexed_A[j].first) != 0) temp++;          
        }
        
        result.push_back(temp);
        
    }
    
    for (unsigned int i = 0; i < result.size(); i++) {
        result_sorted[indexed_A[i].second] = result[i];
    }
  
    return result_sorted;
}