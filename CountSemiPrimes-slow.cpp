// you can use includes, for example:
// #include <algorithm>
#include <cstring>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


bool * runEratosthenesSieve(int n);
bool issemiprime(bool * primes, int n, int * semiprimes);

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++11 (g++ 4.8.2)
bool * primes = runEratosthenesSieve(N);
int * semiprimes = (int*)calloc(N+1,sizeof(int));
int count;
vector<int> result;

    for (unsigned int o = 0; o < P.size(); o++) {
        count = 0;
   for (int i=P[o]; i <= Q[o]; i++) {
       
       if (!(primes[i]) && issemiprime(primes,min(i,N), semiprimes)) count++;
       
   }
        result.push_back(count);
    }
   
   
   return result;
   
}

bool issemiprime(bool * primes, int n, int * semiprimes) {
    
    if (semiprimes[n] == 1) return true;
    else if (semiprimes[n] == -1) return false; 
    
    int count = 0;
    int accum = n;
    for (int i = 2; i <= (n / 2); i++) {
       // cout << accum << " " << i << endl;
        if (((accum % i) == 0) && (primes[i])) {
            count++;
            accum /= i;
            i--;
            if (count == 2) {              
                if (accum == 1) {
                    semiprimes[n] = 1;
                    return true;
                }
                else {
                    semiprimes[n] = -1;
                    return false;
                }
            }
        }
        
    }
    semiprimes[n] = -1;
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