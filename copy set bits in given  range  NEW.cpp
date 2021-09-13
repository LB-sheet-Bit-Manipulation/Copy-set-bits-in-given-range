#include <bits/stdc++.h>
using namespace std;
 
// Copy set bits in range [l, r] from y to x.
// Note that x is passed by reference and modified
// by this function.
int copySetBits(int x, int y, int l, int r)
{
   // l and r must be between 1 to 32
   // (assuming ints are stored using
   //  32 bits)
   if (l < 1 || r > 32)
      return -1;
 
   // Traverse in given range
   for (int i=l; i<=r; i++)
   {
       // Find a mask (A number whose
       // only set bit is at i'th position)
       int mask = 1 << (i-1);
       
       
 
       // If i'th bit is set in y, set i'th
       // bit in x also.
       if (y & mask)
          x = x | mask;
   }
   
   return x;
}
 
// Driver code
int main()
{
   int x = 44, y = 3, l = 1, r = 5;
   
   cout << "\n\nModified x is " << copySetBits(x, y, l, r);
   
   return 0;
}
