using std::string;

string affineEncipher(string message, int r, int s);
string affineDecipher(string ciphertext, int r, int s);

string affineEncipher(string message, int r, int s)
{
  return multiplicativeEncipher(additiveEncipher(message,r),s);
}

string affineDecipher(string ciphertext, int r, int s)
{
  return additiveDecipher(multiplicativeDecipher(ciphertext,s),r);
}