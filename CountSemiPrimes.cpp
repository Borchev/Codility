// you can use includes, for example:
// #include <algorithm>
#include <cmath>
#include <cstring>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> numberofsemiprime(int max, int* semiprimes);
vector<int> runEratosthenesSieve(int upperBound);


vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
 
    vector<int> primes, result, noofsemiprimes;
    
    int semiprimes[N];
    
    memset(semiprimes, 0, (N)*sizeof(int));
   
    primes = runEratosthenesSieve(N);
    int temp_value, counta, countb;
    
    for (unsigned int i = 0; i < primes.size(); i++) {
        

        if ((i * i) > (unsigned int)N) break;
        
        for (unsigned int j = i; j < primes.size(); j++) { 
            
             temp_value = primes[i] * primes[j];
             if (temp_value <= N) semiprimes[temp_value] = 1;
             //cout << "tempval: " << temp_value << endl;
             
             
            //cout << temp_value << endl;
        
        }
        
        
    }
    
    noofsemiprimes = numberofsemiprime(N, semiprimes);
   
    
    for (unsigned int i = 0; i < P.size(); i++) {
        counta = P[i] - 1;
        countb = Q[i];
        
         //cout << "counta: " << counta << "countb: " << countb << endl;
        
        if (counta < 4) counta = 0;
        else counta = noofsemiprimes[counta - 4];
        
        if (countb < 4) countb = 0;
        else countb = noofsemiprimes[countb - 4];
        
        result.push_back(countb - counta);
        
  
              
    }
    
    
    return result;
}

vector<int> numberofsemiprime(int max, int* semiprimes) {
    vector<int> result;
    int count = 0;
    
    for (int i = 4; i <= max; i++) {
        
        if (semiprimes[i] == 1) count++;
        
        
        result.push_back(count);
        
        //cout << i << " count: " << count << endl;
    }
    
    
    
    return result;
}

vector<int> runEratosthenesSieve(int upperBound) {
    vector<int> result;
      int upperBoundSquareRoot = (int)sqrt((double)upperBound);
      bool *isComposite = new bool[upperBound + 1];
      memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
      for (int m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
                  result.push_back(m);
                  for (int k = m * m; k <= upperBound; k += m)
                        isComposite[k] = true;
            }
      }
      for (int m = upperBoundSquareRoot; m <= upperBound; m++)
            if (!isComposite[m])
                  result.push_back(m);
      delete [] isComposite;
      return result;
}