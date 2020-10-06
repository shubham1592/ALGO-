#include <iostream>
#include <numeric>
#include <bits/stdc++.h> 
using namespace std; 


bool isvalid(int arr[], int n, int m, int mid){
    
    int sum = 0;
    int stu = 1;
    
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum > mid){
            stu++;
			sum = arr[i];
        }
        if(stu>m){
            return false;
        }
    }
    return true;
}


int arraysum(int arr[], int n){ 
    int initial_sum  = 0;  
    return accumulate(arr, arr+n, initial_sum); 
} 


int  allocate_pages(int arr[], int n, int m){
    
    int ans = INT_MAX;
    int start = *max_element(arr, arr+n);
    int end = arraysum(arr,n);
    if(n<m){
		return -1;
	}

    while(start <= end){
        int mid = (start + end)/2;
        
        if(isvalid(arr, n, m, mid) == true){
            ans = min(ans,mid);
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

	return ans;
    
}


int main() {

    int t;
    int n;
    int arr[1000] = {0};
    int m;
    
    cin>>t;
    for(int z=0; z<t; z++){
        
        cin>>n>>m;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        
        cout<<allocate_pages(arr, n, m)<<endl;
        
    }

	return 0;
}
