#include <iostream>
using namespace std;
#define m(x,y) x>y?x:y
int main(){int n,i,j,a[99][99];cin>>n;while(cin>>n){for(i=0;i<n;++i)for(j=0;j<i+1;++j)cin>>a[i][j];for(i=n-2;i>=0;--i)for(j=i;j>=0;--j)a[i][j]+=m(a[i+1][j],a[i+1][j+1]);cout<<a[0][0]<<endl;}}
