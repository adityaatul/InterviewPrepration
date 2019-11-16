/*
2
6
5 5 10 100 10 5
3
1 2 3
Output:
110
4

Explanation:
Testcase1:
5+100+5=110
Testcase2:
1+3=4


*/


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n,0);
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    /*
		ansE is xculding the ith ele , ansI is including it
		ans maintains the maximum till ith point 
	    */
	    int ansE=0,ansI=arr[0],ans=0;
	    for(int i=1;i<n;i++){
	    	//max till i is stored in ans.
	        ans = max(ansE,ansI);
	        //ansI includes the curr , note that ansE is used as it signifies that we have not included i-1th element
	        ansI = ansE + arr[i];
	        //ansE is the max ans till here without including the ith element . 
	        ansE = ans;
	    }
	    ans = max(ansE,ansI);
	    cout<<ans<<endl;    
	}
	return 0;
}
