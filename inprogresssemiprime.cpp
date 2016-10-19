// you can use includes, for example:
// #include <algorithm>
#include <cstring>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


bool * runEratosthenesSieve(int n);
bool issemiprime(bool * primes, int primesize, int n);

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
bool * primes = runEratosthenesSieve(N);


   for (int i=P[0]; i < Q[0]; i++) {
       
      issemiprime(primes, N, i);
   }
}

bool issemiprime(bool * primes, int primesize, int n) {

    int count = 0;

    for (int i = 2; i < primesize; i++) {
        
        if ((n % primes[i]) == 0) {
            cout << n << " " << count << endl;
            count++;
            if (count == 2) return true;
            n /= primes[i];
        }
        
    }

    return false;
}

bool * runEratosthenesSieve(int n) {
            
        bool * prime = new bool[n+1];
    memset(prime, true, sizeof(bool) * (n + 1));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
      
      
    
      
      
      
      return prime;
}