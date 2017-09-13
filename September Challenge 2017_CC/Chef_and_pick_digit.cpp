#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		vector<int> v;
		while(n>0){
			v.push_back(n%10);
			n=n/10;
		}

		//sort(v.begin(),v.end());

        int B[91];
        for(int i=0;i<91;i++)
         	B[i]=0;
        vector <int> c;

		for(int i=0;i<v.size()-1;i++){
			for(int j=i+1;j<v.size();j++){
				int t;
				t=v[i]*10 + v[j];
				if(t>64 && t < 91 && B[t]==0){
					c.push_back(t);
					B[t]++;
				}
				t=v[j]*10 +v[i];
                if(t>64 && t < 91 && B[t]==0){
					c.push_back(t);
                	B[t]++;
                }
			}
		}
		sort(c.begin(),c.end());

		for(int i=0;i<c.size();i++){
			cout << (char)c[i];
		}

		cout << endl;
	}
    return 0;   

}