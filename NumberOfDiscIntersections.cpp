// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    vector<pair<int,int>> events;
    int count = 0;
    int accum = 0;
    
    for (unsigned int i = 0; i < A.size(); i++) {
        if ((A[i] > 100000)) A[i] = 100000;
        events.push_back(pair<int,int> {i - A[i],1});  
        events.push_back(pair<int,int> {i + A[i],-1});
        
    }
    
    sort(events.begin(), events.end(),[](const pair<int,int> &A, const pair<int,int> &B){ 
        
        if (A.first == B.first ) return A.second > B.second;
        else return (A.first < B.first); 
   
        });
    
    
    for (unsigned int i = 0; i < events.size(); i++) {
        
    //cout << events[i].first << " " << events[i].second << endl;
       
        if (events[i].second == 1) count += accum;
        if (count > 10000000) return -1;
        accum += events[i].second;
       
    }
    
  return count;
}