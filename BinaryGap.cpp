int solution(int N) {
    // write your code in C++11 (g++ 4.8.2)
    bool seenone = false;
    int localcount = 0, result = 0;
  
    for (unsigned int i = 0; i < sizeof(int) * 8; i++) {  
             
        if ((1 & (N >> i))) {    
            if ((localcount > result)) {
                result = localcount;

            } 
            
            localcount = 0;
            seenone = true;
        
        } else if (seenone) localcount++;      
    }
    
    return result;
}