class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> ans;
        int l=0,r=m-1,t=0,d=n-1;
        int dir=0;
        while(l<=r && t<=d){
            if(dir==0){ //L->R
                for(int i=l;i<=r;i++){
                    ans.push_back(mat[t][i]);
                }
                t++;
            }
            else if(dir==1){  //T->D
                for(int i=t;i<=d;i++){
                    ans.push_back(mat[i][r]);
                }
                r--;
            }
            else if(dir==2){  //R->L
                for(int i=r;i>=l;i--){
                    ans.push_back(mat[d][i]);
                }
                d--;
            }
            else if(dir==3){  //D->U
                for(int i=d;i>=t;i--){
                    ans.push_back(mat[i][l]);
                }
                l++;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};