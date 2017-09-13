#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
        
        int A[n];
		for(int i=0;i<n;i++){
			cin >> A[i];
			//cout << A[i] << " ";
		}
         //cout << endl;
		int B[n+1],c[n+1];
		int s=0,cnt=0;
		for(int i=1;i<=n;i++){
            B[i] = A[i-1] + s;
            s = B[i];
            //cout << B[i] << " ";
		}
		//cout << endl;
		for(int i=1;i<=n;i++){
            c[i]=A[n-i]+cnt;
            cnt = c[i];

            //cout << c[i] << " ";
		}
        //cout << endl;
		int max=0,index=0;
		for(int i=1;i<=n;i++){
			if(B[i]+c[n-i-1]>max){
				max=B[i]+c[i];
				index = i;
			}
		}
		cout << index-1 << endl;
	}
	
    return 0;   

}