#include <bits/stdc++.h>

using namespace std;


#define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)


int n, m;
int arr[10][10];
bool valid(int i, int j)
{
   return i>= 0 && i < n && j >= 0 && j < m;
}

int sum = 0, ans = INT_MIN;
void path(int i, int j)
{
   
   
   if(i == n-1&&j == m-1)
   {  

      ans = max(ans, sum+arr[i][j]);
      return;
   }
   
   sum += arr[i][j];
   if(valid(i+1, j))
      path(i+1, j);
   if(valid(i, j+1))
      path(i, j+1);
   sum -=arr[i][j];

}


int main()
{
   FAST;
   cin >> n >> m;
   for (int i = 0; i < n; ++i)
   {
      for (int j = 0; j < m; ++j)
      {
         cin >> arr[i][j];
      }
   }
   path(0, 0);
   cout << ans << endl;




   return 0;

}



