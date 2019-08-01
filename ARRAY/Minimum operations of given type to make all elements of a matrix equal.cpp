/*
Given a matrix of integers A of size N x M and an integer B. In a single operation, B can be added to or subtracted from any element of the matrix. Find and return the minimum number of operations required to make all the elements of the matrix equal and if it impossible return -1 instead.

Input 1:
    A = [   [0, 2, 8]
            [8, 2, 0]
            [0, 2, 8]   ]
    B = 2
Output 1:
    12

Input 2:
    A = [   [5, 17, 100, 11]
            [0, 0,  2,   8]    ]
    B = 3
Output 2:
    -1

*/

/*
obviously the number B must be able to produce equal result after % with i.e A[x][y]%B = mod , this mod value should be constant for all the elements , if not , simply return -1 , 
else 
find the minmum number and the min operation will be , when we try to bring every number close to the median . 

REMBER THE MODING LOGIC FOR -VE NUMBER  mod = ((A[0][0])%B + B)%B;
*/

int Solution::solve(vector<vector<int> > &A, int B) {
    vector<int> arr;
    int n = A.size();
    int mod = ((A[0][0])%B + B)%B;
    for(int i=0;i<n;i++){
        int k = A[i].size();
        for(int j=0;j<k;j++){
            if(((A[i][j])%B + B)%B!=mod)
            return -1;
            
            arr.push_back(A[i][j]);
        }
    }
    n=arr.size();
    sort(arr.begin(),arr.end());
    
    int median = arr[n/2],median2,min_operation=0,min_operation2=0;
    for(int i=0;i<n;i++){
        min_operation += abs(arr[i]-median)/B;
    }
    if(n%2==0){
    median2 = arr[(n/2) -1];    
    for(int i=0;i<n;i++){
        min_operation2 += abs(arr[i]-median2)/B;
    }    
    min_operation = min(min_operation,min_operation2);
    }
    return min_operation;
}
