#include <iostream>
using namespace std;

void park(char a[][100], int m, int n, int k, int s) {
    bool ans = true;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            char ch = a[i][j];

            if(s<k){
                ans=false;
                break;
            }

            if(ch == '*'){
                s += 5;
            }

            else if(ch == '.'){
                s -= 2;
            }
            else{
                break;
            }

            if(j != n-1){
                s--;
            }
        }
    }
    if(ans){
        cout<<"Yes"<<endl;
        cout<<s<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}

int main(){
	int m, n, k, s;
	cin >> m >> n >> k >> s;
	char arr[100][100];

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	park(arr, m, n, k, s);
	return 0;
}
