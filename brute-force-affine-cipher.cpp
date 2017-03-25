#include<iostream>
#include<string>
#include "affine.cpp"
#include <vector>

using namespace std;

bool check_equal(string cipher_text, string message)
{
  return cipher_text.compare(message) == 0;
}


int gcd(int a, int b)
{
  int c = a % b;
  while(c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}


vector< vector<int> >  generate_keys()
{
  vector< vector<int> > keys;
  for(int b=0; b < 26; b++){
    vector<int> a_key;
    for(int a=0; a < 26; a++){
      if (gcd(a, 26) == 1){
        a_key.push_back(a);
      }
    }
    keys.push_back(a_key);
  }
  return keys;
}


string decrypt_brute(string cipher_text, int a, int b)
{
    string m = "";
    int a_inv = 0;
    int flag = 0;
    // calculating a^-1 for decryption
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        if (flag == 1)
        {
            a_inv = i;
        }
    }

    for (int i = 0; i < cipher_text.length(); i++)
    {
        m = m + (char) (((a_inv * ((cipher_text[i] - b)) % 26)) + 65);
    }

    return m;
}


int main(){
  vector< vector<int> > keys;
  int flag=0;
  keys = generate_keys();
  string message = "ZEROONEHACKER";
  string cipher_text = encrypt(message);
  for(int i = 0; i < keys.size(); i++){
    for( int j = 0; j < keys[0].size(); j++){
      cout<<"Checking a="<<keys[0][j]<<" b="<<i<<"decrypted text="<<decrypt_brute(cipher_text, keys[0][j], i)<<endl;
      if( check_equal(message, decrypt_brute(cipher_text, keys[0][j], i))){
        cout<<"Keys found a="<<keys[i][j]<<" and b="<<i;
        flag=1;
        break;
      }
    }
    if(flag==1)break;
  }
  return 0;
}
