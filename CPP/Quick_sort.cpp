#include <bits/stdc++.h>
//Quicksort taking last element as pivot that is T(n) = T(n-1)+@(n)
using namespace std;
void swap(int *a,int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int partition(int A[],int l,int h)
{
	int pivot = A[h];
	int k = l-1;
	for(int i=l;i<=h-1;i++){
		if(A[i]<=pivot){
			k++;
			swap(&A[k],&A[i]);
		}
	}
	swap(&A[k+1],&A[h]);
	return k+1;
}
void Quicksort(int A[],int l,int h)
{
	if(l<h){
		int p = partition(A,l,h);

		Quicksort(A,l,p-1);
		Quicksort(A,p+1,h);
	}
}
int main()
{
   int n;
   cin >> n;

   int A[n];
   for(int i=0;i<n;i++)
   	cin >> A[i];

   Quicksort(A,0,n-1);

   for(int i=0;i<n;i++)
   	cout << A[i] << " ";
   return 0;
}