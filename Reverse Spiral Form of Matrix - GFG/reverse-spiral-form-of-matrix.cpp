//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  //https://www.youtube.com/watch?v=1ZGJzvkcLsA
    vector<int> reverseSpiral(int n, int m, vector<vector<int>>&a)  {
        // code here n rows m cols
        vector<int> spiral;
        int t=0,d=n-1,l=0,r=m-1;
        int dir=0;
        while(t<=d && l<=r){
            if(dir==0){ //L->R
                for(int i=l;i<=r;i++){
                    spiral.push_back(a[t][i]);
                }
                t++;
            }
            else if(dir==1){ //T->D
                for(int i=t;i<=d;i++){
                    spiral.push_back(a[i][r]);
                }
                r--;
            }
            else if(dir==2){ //R->L
                for(int i=r;i>=l;i--){
                    spiral.push_back(a[d][i]);
                }
                d--;
            }
            else if(dir==3){ //D->T
                for(int i=d;i>=t;i--){
                    spiral.push_back(a[i][l]);
                }
                l++;
            }
            dir=(dir+1)%4; //to move in other direction
        }
        reverse(spiral.begin(),spiral.end());
        return spiral;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
