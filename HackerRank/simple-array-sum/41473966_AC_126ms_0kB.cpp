
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>

using namespace std;

int main()
{
   int n;
   cin>>n;
   long long sum=0;
   for(int i=0;i<n;i++){
       long long x;
       cin>>x;
       sum+=x;
   }
   cout<<sum<<endl;
    return 0;
}
