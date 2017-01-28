#include<iostream>
#define N 8
using namespace std;
void print(int a[8][8])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl<<endl<<endl;
}
bool s=true;
bool KnightTour(int current,int i,int j,int a [N][N] )
{



	if(current==N*N)
	{
		return true;
	}
	if(a[i][j]==-1)
	{
		a[i][j]=current;
		if(i+2<=7&&j+1<=7)
		{
			if(KnightTour(current+1,i+2,j+1,a))
				return true;
		}
		if(i+1<=7&&j+2<=7)
		{
			if(KnightTour(current+1,i+1,j+2,a))
				return true;
		}
		if(i-1>=0&&j+2<=7)
		{
			if(KnightTour(current+1,i-1,j+2,a))
				return true;
		}
		if(i-2>=0&&j+1<=7)
		{
			if(KnightTour(current+1,i-2,j+1,a))
				return true;
		}
		if(i-2>=0&&j-1>=0)
		{
			if(KnightTour(current+1,i-2,j-1,a))
				return true;
		}
		if(i-1>=0&&j-2>=0)
		{
			if(KnightTour(current+1,i-1,j-2,a))
				return true;
		}
		if(i+1<=7&&j-2>=0)
		{
			if(KnightTour(current+1,i+1,j-2,a))
				return true;
		}

		if(i+2<=7&&j-1>=0)
		{
			if(KnightTour(current+1,i+2,j-1,a))
				return true;
		}
		if(current==63)
			return true;
		a[i][j]=-1;
		return false;
	}
	return false;

}
int main()
{
	int a[N][N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			a[i][j]=-1;
	KnightTour(0,0,0,a);
	print (a);
	return 0;
}
