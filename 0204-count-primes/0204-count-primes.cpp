

class Solution {
public:
    int countPrimes(int n) {
        const int max = 5000001;
        bool is_prime[max]; // if is_prime[i] = true t.m. i = prime
        is_prime[0] = 0;
        is_prime[1] = 0;
        for(int i=2;i<max;i++){
            is_prime[i] = true;
        }        
        for(int i=2;i*i<max;i++){
            if(is_prime[i]){
                for(int j=i*i;j<max;j+=i){
                    is_prime[j] = false;
                }
            }
        }
        int count_primes_till_n = 0;
        for(int i=0;i<n;i++){
            if(is_prime[i]) count_primes_till_n++;
        }
        return count_primes_till_n;
    }
};