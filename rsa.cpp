#include<iostream>
using namespace std;

int phi,M,n,e,d,C,FLAG;

int encrypt(int message, int e, int n){
  int cipher=1;
  for(int i=0; i<e; i++){
    cipher = cipher*message %n;
  }
  return cipher%n;

}


int decrypt(int cipher, int d, int n){
  int message=1;
  for(int i=0; i<d; i++){
    message = message*cipher%n;
  }
  return message%n;
}


int gcd(int a, int b){
	int m=a,n=b;
	while (n > 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
	return m;

}


int valid(int e, int phi){
  if(gcd(e, phi)==1) return 1;
  else return 0;
}


int gcd_inv(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd1 = gcd_inv(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd1;
}

int inv(int a, int m){
	int x, y;
	int gcd1 = gcd_inv(a, m, &x, &y);
	if(gcd1!=1) return -1;
	else {
		int result = (x%m+m)%m;
		return result;
	}
}


int main(){
  int p, q, n, phi, e, d, message;
  cout<<"Enter first prime number: ";
  cin>>p;
  cout<<"Enter second prime number: ";
  cin>>q;
  n = p*q;
  phi = (p-1)*(q-1);
  cout<<"Enter the value of encryption key e: ";
  cin>>e;
  if(!valid(e, phi)){
    cout<<"Not Valid e!! Exiting..";
    return 0;
  }

  d = inv(e, phi);
  if(d==-1){
    cout<<"Some error has been occured!! Exiting...";
    return 0;
  }

  cout<<"Enter the message : ";
  cin>>message;
  cout<<"Encrypted messsage : "<<encrypt(message, e, n)<<endl;
  cout<<"Decrypted message of above encryption : "<<decrypt(encrypt(message, e, n), d, n)<<endl;
  return 0;
}
