#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <math.h>
// #include <bits/stdc++.h> 
using namespace std;



void robin_karp(string P, string T, int d, int q)
{
	int n = T.length();
	int m = P.length();
	int h = 1;

	for(int i=0;i<m-1;i++)
	{
		h = h*d % q;
	}
	h%=q;

	int p = 0;
	int t = 0;
	int i=0;

	for(int i=0;i<m;i++)
	{
		p = (d*p + P[i]) % q;
		t = (d*t +T[i]) % q;
	}

	for(int s=0;s<(n-m);s++)
	{
		if(p==t)
		{
			bool valid = true;
			for ( i = 0; i < m; ++i)
			{
				if(T[i+s]!=P[i])
				{
					//cout<<"breaking"<<endl;
					break;
					//valid = false;
				}
			}
			if(i==m)
			{
				cout<<"Pattern found, occurs with shift: "<<s<<endl;
				//break;
			}
		}
		if(s<(n-m))
		{
			t = (d*(t-T[s]*h) + T[s+m])%q;
			if(t<0)
				t = t+q;
		}
	}
	return;
}


int main()
{

	int q = 101;
	int d = 256;
	string p = "a";
	string t = "What is the meaning of life during this time that we spend on earth as we ponder the reason behind our existence";

	robin_karp(p, t, d, q);

	return 0;
}