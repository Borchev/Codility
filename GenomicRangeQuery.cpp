// you can use includes, for example:
// #include <algorithm>
#include <cstring>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
    int sequenceLength = S.size();
    vector<int> result;
    
    int A[sequenceLength + 1], C[sequenceLength + 1], G[sequenceLength + 1], T[sequenceLength + 1];
    
    //I should probably replace this cludgyness with a struct
    memset(A,0,sizeof(A));
    memset(C,0,sizeof(C));
    memset(G,0,sizeof(G));
    memset(T,0,sizeof(T));
    
    for (unsigned int i = 0; i < S.size(); i++) {
    
        A[i+1] += A[i];
        C[i+1] += C[i];
        G[i+1] += G[i];
        T[i+1] += T[i];
    
        switch (S[i]) {
        
            case 'A':
            A[i+1]++;
            break;
            case 'C':
            C[i+1]++;
            break;
            case 'G':
            G[i+1]++;
            break;
            case 'T':
            T[i+1]++;
            break;
        
        }
        
    }
    
    for (unsigned int i = 0; i < P.size(); i++) {
        if (A[Q[i]+1] - A[P[i]]) result.push_back(1);
        else if (C[Q[i]+1] - C[P[i]]) result.push_back(2);
        else if (G[Q[i]+1] - G[P[i]]) result.push_back(3);
        else if (T[Q[i]+1] - T[P[i]]) result.push_back(4);
             
    }
    
    
    return result;
}