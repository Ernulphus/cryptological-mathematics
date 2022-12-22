using std::string;
#include <thread>
#include <future>
using std::thread;
string additiveEncipher(string message, int key);
string additiveDecipher(string ciphertext, int key);


string additiveEncipher(string message, int key)
{
  cleanMessage(message);
  string ciphertext = "";
  for (int i = 0; i < message.length(); i++)
  {
    ciphertext += shift(message[i], key);
    // if ((i+1) % 3 == 0)
    // ciphertext += " ";
  }
  return ciphertext;
}

void parallelAdditiveEncipher(string message, int key, std::promise<string>  & prms)
{
 
  cleanMessage(message);
  
  if (message.length() == 1)
  {
    string s = " ";
    s[0] = shift(message[0], key);
    prms.set_value(s);
    return;
  }

  std::promise<string> p1;
  std::promise<string> p2;
  thread t1(parallelAdditiveEncipher, message.substr(0, message.size()/2), key, std::ref(p1));
  thread t2(parallelAdditiveEncipher, message.substr(message.size()/2), key, std::ref(p2));
  
  std::future<string> f1 = p1.get_future();
  std::future<string> f2 = p2.get_future();
  
  string first = f1.get();
  string second = f2.get();
  prms.set_value(first + second);
  t1.join();
  t2.join();

}

string additiveDecipher(string ciphertext, int key)
{
  cleanMessage(ciphertext);
  string plaintext = "";
  for (int i = 0; i < ciphertext.length(); i++)
    plaintext += shift(ciphertext[i], -key);

  return plaintext;
}
