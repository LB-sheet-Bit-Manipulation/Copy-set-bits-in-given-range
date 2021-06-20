/*
Question:

Ex:
i/p: x=10 and y=13 with range l=2 and r=3 

y me within the range of l and r included jaha bhi koi bit set(yaani 1) ho, usi position ki bit x me bhi set karo irrespective
vaha kya tha. 

position:4321   [2,3]
	  
	  13=1101
      10=1010
     
     pos 2-3 me pos 2 hi set hai y me, so make position 2 in x set irrespective of vo pehle ky tha
     
     x=1110 => 14

o/p: new x => 14 

TC --> O(n)
SC --> O(1)

*/

//Issue:
//GFG ki site par iska second approach bhi hai but wo nhi samza
//Try for more efficient solution if any

#include<iostream>
using namespace std;

int CopySetBitsInRange(int x,int y,int l,int r)
{
	int i;
	
	//traverse from l se r
	for(i=l;i<=r;i++)
	{
		//check if the bit is set using a mask variable. Mask is a number whose only set bit is i
		//1 is written as 0000..1. To bas (i-1) times left shift karne ki garaj hai to bring to ith position.
		int mask=1<<(i-1);
		
		//check if ith bit of y is set,if set then set the corresponding bit of x.Use OR bcoz agar x me already 1 hai to
		//bhi farak nhi padega.OR 1 hi dega us bit par
		if((y&mask)!=0)
		{
			//change karna hai to OR hi karo. Bits me arrays ki tarah sidha a[i]=b[i] likh ke copy nhi hota
			x=x|mask;
		}
	}
	
	return x;
}

int main() 
{ 	
	int x,y,l,r;
	
	cout<<"\nEnter the number x (positive number ONLY)";
	cin>>x;
	
	cout<<"\nEnter the number y (positive number ONLY)";
	cin>>y;
	
	cout<<"\nEnter the range (lowerlimit)";
	cin>>l;
	
	cout<<"\nEnter the range (upperlimit)";
	cin>>r;
	
	//checking for corner cases
	if(x>0 && y>0)
	{
		//I am assuming 32 bit integer store hoga. So, range can't be more than that. It MUST be [1---32] bits ONLY
		//also upper limit must be greater tha or equal to lower limit
		if((l<1 || r>32) || (l>r))
		{
			cout<<"\nInvalid range!! It MUST be [1---32] bits ONLY";
		}
		else
		{
			//calling our function
			cout<<"\nThe modified x is => "<<" "<<CopySetBitsInRange(x,y,l,r);	
		}
	}
	else
	{
		cout<<"\nEnter positive numbers ONLY!!";
	}
	return 0;
}
