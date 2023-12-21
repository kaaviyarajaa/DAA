#include <bits/stdc++.h> 
#define ll long long 
using namespace std; 
int h1(string s, int arrSize) 
{ 
	ll int hash = 0; 
	for (int i = 0; i < s.size(); i++) 
	{ 
		hash = (hash + ((int)s[i])); 
		hash = hash % arrSize; 
	} 
	return hash; 
} 
int h2(string s, int arrSize) 
{ 
	ll int hash = 1; 
	for (int i = 0; i < s.size(); i++) 
	{ 
		hash = hash + pow(19, i) * s[i]; 
		hash = hash % arrSize; 
	} 
	return hash % arrSize; 
} 
 
bool lookup(bool* bitarray, int arrSize, string s) 
{ 
	int a = h1(s, arrSize); 
	int b = h2(s, arrSize); 


	if (bitarray[a] && bitarray[b] ){
	return true; 
}
	else{
		return false; 
	}
} 
void insert(bool* bitarray, int arrSize, string s) 
{ 

	if (lookup(bitarray, arrSize, s)) 
		cout << s << " is already present" << endl; 
	else
	{ 
		int a = h1(s, arrSize); 
		int b = h2(s, arrSize); 
	
		bitarray[a] = true; 
		bitarray[b] = true; 
    	cout << s << " is inserted sucessfully...! " << endl; 
	} 
} 

int main() 
{ 
	bool bitarray[100] = { false }; 
	int arrSize = 100; 
	string sarray[4] = { "Kaviya","Kaaviya","Kaviyaa","Kaviya" }; 
	for (int i = 0; i < 4; i++) { 
		insert(bitarray, arrSize, sarray[i]); 
	} 
	return 0; 
}
