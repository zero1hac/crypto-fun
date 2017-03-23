#include<iostream>
using namespace std;

int phi(const int n)
{
  if ( n < 2 )
    return 0;
  if ( isprime(n) )
    return n-1;

  if ( (n & 1) == 0 ) {
    int m = n >> 1;
    return !(m & 1) ? phi(m)<<1 : phi(m);
  }

  for ( std::vector<int>::iterator p = primes.begin();
        p != primes.end() && *p <= n;
        ++p )
  {
    int m = *p;
    if ( n % m  ) continue;
    int o = n/m;
    int d = binary_gcd(m, o);
    return d==1? phi(m)*phi(o) : phi(m)*phi(o)*d/phi(d);
  }
}

int main(){
  cout<<"phi(67)"<<phi(67);
  return 0;
}
