#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
        
        int A[n+1];
        for(int i=0;i<=n;i++){
        	A[i]=0;
        }    
        vector <int> v;
        for(int i=1;i<n+1;i++){
        	for(int j=1;j<=n;j++){
        		if(A[j]==0 && j!=i){
        			v.push_back(j);
        			A[j]++;
        			break;
        		}
        	}
        }
        
        for(int i=1;i<=n;i++){
        	if(A[i]==0)
        		v.push_back(i);
        }
        for(int i=n-1;i>0;i--){
        	if(v[i]==i+1){
        		int t=v[i];
        		v[i]=v[i-1];
        		v[i-1] = t;
        	}else{
        		break;
        	}
        }
        for(int i=0;i<n;i++){
        	cout << v[i] <<" ";
        }
        cout << endl;
	}
    return 0;   

}