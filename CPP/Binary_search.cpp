#include <bits/stdc++.h>

using namespace std;

#define k for(int i=0;i<n;i++)

int Bsearch(int A[],int l,int h,int x)
{
    if(l<=h){
    	int mid = (h+l)/2;

    	if(A[mid] > x){
    		Bsearch(A,l,mid-1,x);
    	}else if(A[mid]<x){
    		Bsearch(A,mid+1,h,x);
    	}else{
    		return x;
    	}
    }

   return 0;
}

int main()
{
	int n;
	cin >> n;
	int A[n];
	k{
		cin >> A[i];
	}

	int x;
	cin >> x;

	sort(A,A+n);

	int t = Bsearch(A,0,n-1,x);

	if (t==0)
		cout << "No" << endl;
	else
		cout << t << endl;
}