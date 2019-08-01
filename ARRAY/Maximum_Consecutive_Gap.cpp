/*
PROBLEM
Maximum Consecutive Gap
Given an unsorted array, find the maximum difference between the successive elements in its sorted form. Try to solve it in linear time/space. Example :
Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.
You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.
*/

/*
Started with the bucketing concept , so the concept is fine , but initially i was getting MLE (memory limit execeded) as i was using a 2d vector , then bring down the code to a 1d vector<pair<int,int>> and got a AC 
*/

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if (n<2)
    return 0;
    int mn =INT_MAX, mx=-INT_MAX;
    for(int i=0;i<n;i++){
        mn = min(mn,A[i]);
        mx = max(mx,A[i]);
    }
    //cout<<mx<<" "<<mn<<" "<<mx-mn<<endl;
    if(mx-mn == 0)
    return 0;
    int gap,row;
    if(mx-mn<n){
     gap=mx-mn;
     row=2;
    }else{
     gap = (int)(mx-mn)/(n-1);
     row = (int)(mx/gap) +1;
    }//cout<<gap<<" "<<row<<endl;
    vector<pair<int,int>> vect(row);
    for(int i=0;i<row;i++){
        vect[i].first=INT_MAX;
        vect[i].second=-INT_MAX;
    }
    for(int i=0;i<n;i++){
        int r = A[i]/(gap+1);
        vect[r].first=min(vect[r].first,A[i]);
        vect[r].second=max(vect[r].second,A[i]);
    }
    pair<int,int> mnmx1,mnmx2;
    int rowmnmx=0,c=0;
    int ans = -INT_MAX;
    for(int i=0;i<row;i++){
        int col = vect[i].first;
        if(col!=INT_MAX){
        mn=vect[i].first;
        mx=vect[i].second;
        if (c==0)
        mnmx1 = make_pair(mn,mx);
        else{
        mnmx2 = make_pair(mn,mx);    
            ans=max(ans,mnmx2.first-mnmx1.second);
        mnmx1=mnmx2;    
        }
        ++c;
        }
        
    }
    
    // for(int i=0;i<row;i++){
    //     int col = vect[i].size();
    //     mn =INT_MAX, mx=-INT_MAX;
    //     for(int j=0;j<col;j++){
    //         cout<<vect[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // ele;
    // for(int i=0;i<rowmnmx-1;i++){
    //     ele=mnmx[i+1].first-mnmx[i].second;
    //     ans=max(ans,ele);
    // }

    return ans;
}
