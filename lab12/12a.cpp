#include <iostream>  
#include <algorithm>  
using namespace std;  
long long a[555][555],p[555],b[555];  
int main() {  
 int n;  
 cin>>n;  
 for (int i=1;i<=n;i++)  
  for (int j=1;j<=n;j++)  
   cin>>a[i][j];  
 for(int z=1;z<=n;z++)  
  cin>>b[z];  
 for(int z=1;z<=n;z++){  
  for(int i=1;i<=n;i++)  
   for (int j=1;j<=n;j++)  
    a[i][j]=min(a[i][j],a[i][b[z]]+a[b[z]][j]);  
    for (int i=1;i<=z;i++)  
     for (int j=1;j<=z;j++)  
      p[z]=max(a[b[i]][b[j]], p[z]);  
  }  
 for (int i=1;i<=n;i++)  
 cout<<p[i]<<' ';  
}