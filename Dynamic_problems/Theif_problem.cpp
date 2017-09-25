#include <iostream>
using namespace std;

int max(int a,int b)
{
	if(a>=b)
		return a;

	return b;
}
int main()
{
    int n;
    cin >> n ;
    int A[n];
    for(int i=0;i<n;i++)
    	cin >> A[i];

    int include =A[0],exclude_temp=0;
    int exclude =0,include_temp=0;

    for(int i=1;i<n;i++){
    	include_temp = A[i] + exclude;
    	exclude_temp = max(include,exclude);

    	exclude = exclude_temp;
    	include = include_temp;
    }

    cout << max(include,exclude) << endl;
	return 0;
}