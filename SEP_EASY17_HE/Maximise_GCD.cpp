#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
     if(a<b){
          int t=a;
          a=b;
          b=t;
        }
    if(b==0)
    return a;
    
    return gcd(b,a%b);
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    
    int result =A[n-1];
    int max=A[n-1],k=n-1;
    for(int i=n-2;i>=0;i--){
        result = gcd(result,A[i]);
        if(result >= max){
            k=i;
            max = result;
        }
    }
    cout << k <<endl;
    return 0;
}