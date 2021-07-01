//
// PrimeChecker.cpp
// ds_hw1_warm_up
//
#include "PrimeChecker.h"
#include "math.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef unsigned long ul;

ul mul(ul a, ul b, ul mod)
{
    	a %= mod;
    	b %= mod;
    	ul c = (long double) a * b / mod;
    	ul ans = a * b - c * mod;
    	return (ans % mod + mod) % mod;
}

ul pow_mod(ul x, ul n, ul mod)
{
    	ul res = 1;
    	while (n) {
        	if (n & 1) {
        		res = mul(res, x, mod);
		}
        x = mul(x, x, mod);
        n >>= 1;
    	}
    	return (res + mod) % mod;
}

bool Miller_Rabbin(ul a, ul n)
{

    	ul s = n - 1, r = 0;
    	while ((s & 1) == 0) {
        	s >>= 1;
		r++;
    	}

    	ul k = pow_mod(a, s, n);

    	if (k == 1) {
		return true;
	}
    	for (int i = 0; i < r; i++, k = k * k % n) {
      	  	if (k == n - 1) {
			return true;
		}
    	}
    	return false;
}

bool check(ul n) 
{
	ul times_32 = 1;
	ul prime_32[3] = {126401071349994536};
	for (ul j = 0; j < times_32; j++) {
               	if (Miller_Rabbin(prime_32[j], n) == false) {
                       	return false;
               	}		
	} 
	return true;
}

ul PRIMECHECKER::PrimeChecker(ul a, ul b){
	ul prime[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	ul count = 0, flag = 0;
    	for (ul i = a; i <= b; i++) {
		flag = 0;
		for (ul j = 0; j < 25; j++) {
			if (i == prime[j]) {
				count++;
				flag = 1;
				break;
			}
			if (i % prime[j] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			continue;
		}	
		if (check(i)) {
			count++;
		}
		
	}
	return count;
}
