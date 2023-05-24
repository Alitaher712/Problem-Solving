#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> OS;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> OMS;
 
#define ll long long int
 
#define Faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
 
vector<string> S;
map<string,bool> present;
int n,m;
 
void Call(int currIndx,int gapsRemain,string sample){
    if(gapsRemain<0){
        return;
    }
    if(currIndx==S.size()){
        if(sample.size()>=3 and sample.size()<=16 and !present[sample]){
            cout<<sample<<endl;
            exit(0);
        }
        return;
    }
    if(sample.size()>0 and sample.back()!='_'){
        Call(currIndx,gapsRemain,sample+"_");
    }
    else{
        Call(currIndx+1,gapsRemain,sample+S[currIndx]);
        if(sample.size()>0){
            Call(currIndx,gapsRemain-1,sample+"_");
        }
    }
}
 
int main(){
    Faster;
    cin>>n>>m;
    present.clear();
    S.resize(n);
 
    int ExtraGapsRemain=16;
 
    for(int i=0;i<n;i++){
        cin>>S[i];
        ExtraGapsRemain-=S[i].size();
    }
 
    ExtraGapsRemain-=(n-1);
 
    sort(S.begin(),S.end());
 
    for(int i=0;i<m;i++){
        string T;
        cin>>T;
        present[T]=true;
    }
 
 
 
    do{
        Call(0,ExtraGapsRemain,"");
    }while(next_permutation(S.begin(),S.end()));
 
 
    cout<<-1<<endl;
 
    return 0;
}