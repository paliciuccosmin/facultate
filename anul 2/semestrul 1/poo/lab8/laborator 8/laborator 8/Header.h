﻿#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;

int gcd(int a, int b)
{
	// Find Minimum of a and b 
	int result = min(a, b);
	while (result > 0) {
		if (a % result == 0 && b % result == 0) {
			break;
		}
		result--;
	}

	// Return gcd of a and b 
	return result;
}
set<int>
prime; // a set will be the collection of prime numbers,
// where we can select random primes p and q
int public_key;
int private_key;
int n;
// we will run the function only once to fill the set of
// prime numbers
void primefiller()
{
	// method used to fill the primes set is seive of
	// eratosthenes(a method to collect prime numbers)
	vector<bool> seive(250, true);
	seive[0] = false;
	seive[1] = false;
	for (int i = 2; i < 250; i++) {
		for (int j = i * 2; j < 250; j += i) {
			seive[j] = false;
		}
	} // filling the prime numbers
	for (int i = 0; i < seive.size(); i++) {
		if (seive[i])
			prime.insert(i);
	}
}
// picking a random prime number and erasing that prime
// number from list because p!=q
void setkeys()
{
	int prime1 = 181; // first prime number
	int prime2 = 19; // second prime number
	// to check the prime numbers selected
	n = prime1 * prime2;
	int fi = (prime1 - 1) * (prime2 - 1);
	int e = 2;
	while (1) {
		if (gcd(e, fi) == 1)
			break;
		e++;
	} // d = (k*Φ(n) + 1) / e for some integer k
	public_key = e;
	int d = 2;
	while (1) {
		if ((d * e) % fi == 1)
			break;
		d++;
	}
	private_key = d;
}
// to encrypt the given number
long long int encrypt(double message)
{
	int e = public_key;
	long long int encrpyted_text = 1;
	while (e--) {
		encrpyted_text *= message;
		encrpyted_text %= n;
	}
	return encrpyted_text;
}
// to decrypt the given number
long long int decrypt(int encrpyted_text)
{
	int d = private_key;
	long long int decrypted = 1;
	while (d--) {
		decrypted *= encrpyted_text;
		decrypted %= n;
	}
	return decrypted;
}
// first converting each character to its ASCII value and
// then encoding it then decoding the number to get the
// ASCII and converting it to character
vector<int> encoder(string message)
{
	vector<int> form;
	// calling the encrypting function in encoding function
	for (auto& letter : message)
		form.push_back(encrypt((int)letter));
	return form;
}
string decoder(vector<int> encoded)
{
	string s;
	// calling the decrypting function decoding function
	for (auto& num : encoded)
		s += decrypt(num);
	return s;
}
std::string vectorToString(const std::vector<int>& vec) {
	std::ostringstream oss;

	// Iterate through the vector and append each integer to the stream
	for (const int& value : vec) {
		oss << value;
	}

	// Convert the stringstream to a string
	return oss.str();
}


