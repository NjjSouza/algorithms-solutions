#include <iostream>
#include "hashing.h"
using namespace std;

// h(k, m) = k % m 
// h(k, i, m) = h(h'(k,m) + i) % m 

int hash_aux(int k, int m){
	int h = k % m; 
	
	if (h < 0){
	    h += m;
	}
	
	return h;
}