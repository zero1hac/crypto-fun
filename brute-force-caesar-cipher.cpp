#include<iostream>
#include<string>
#include "caesar.cpp"
#include <vector>

using namespace std;

bool check_equal(string cipher_text, string message)
{
  return cipher_text.compare(message) == 0;
}


vector< int >  generate_keys()
{
  vector< int > keys;
  for(int b=0; b < 26; b++){
    keys.push_back(b);
  }
  return keys;
}


string decrypt_brute(string cipher_text, int a)
{
  string m=cipher_text;
  for (int i = 0; i < m.length(); i++)
  {
    if(isupper(m[i]))
   {
     if((m[i] >= 'D' ) && ( m[i] <= 'Z' ))
       m[i] = tolower(m[i] - (char)a);
     else if(m[i] == 'A')
       m[i] = 'x';
     else if(m[i] == 'B')
       m[i] = 'y';
     else
       m[i] = 'z';
   }
   else
   {
     m[i] = m[i];
   }
  }


  return m;
}


int main(){
  vector< int > keys;
  int flag=0;
  keys = generate_keys();
  string message = "zeroonehacker";
  string cipher_text = encrypt(message);

    for( int j = 0; j < keys.size(); j++){
      cout<<"Checking a="<<keys[j]<<" decrypted text="<<decrypt_brute(cipher_text, keys[j])<<endl;
      if( check_equal(message, decrypt_brute(cipher_text, keys[j]))){
        cout<<"Keys found a="<<keys[j];
        flag=1;
        break;
      }
    }

  return 0;
}
