#include<iostream>
#include<string>
using namespace std;
bool check(int row,int col,int arr[8][8])
{

	for(int i=0;i<8;i++)
		if(arr[i][col]==1)
		{
			//cout<<"same col"<<endl;
			return false;
		}
	for(int i=0;i<8;i++)
		if(arr[row][i]==1)
		{
			//cout<<"same row"<<endl;
			return false;
		}
	//cout<<"hiii"<<endl;

	int row1=row;
	int col1=col;
	while(true)
	{
		//cout<<"checking "<<row1<<" "<<col1<<endl;
		if(row1==7&&col1==7)
		{
			if(arr[row1][col1]==1)
			{
				//cout<<"same ptive diagnol"<<endl;
				return false;
			}
			break;
		}
		if(arr[row1][col1]==1)
		{
			//cout<<"same ptive diagnol"<<endl;
			return false;
		}
		if(row1<7)
			row1++;
		if(col1<7)
			col1++;
	}
	//cout<<"passed the stage"<<endl;
	row1=row;
	col1=col;
	while(true)
	{
		//cout<<"checking "<<row1<<" "<<col1<<endl;
		if(row1==0&&col1==0)
		{
			if(arr[row1][col1]==1)
			{
				//cout<<"same -ve diagnol"<<endl;
				return false;
			}			break;

		}
		if(arr[row1][col1]==1)
		{
			//cout<<"same -ne diagnol"<<endl;
			return false;
		}
		if(row1>0)
			row1--;
		if(col1>0)
			col1--;
	}
	return true;
}
bool nqueen(int row ,int col,int queens,int arr[8][8],string space )
{
	if(row>7)
		return true;
	cout<<space<<row<<" "<<col<<endl;

	for(int i=0;i<8;i++)
	{

		if(check(row,i,arr))
		{
			arr[row][i]=1;
			if(nqueen(row+1,0,queens-1,arr,space+"  "))
				return true;
			arr[row][i]=0;
		}
	}
	return false;
}
int main()
{
	int a[8][8];
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			a[i][j]= 0;
	cout<<"sfsadf"<<endl;
	nqueen(0,0,8,a,"");
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	//a[4][5]=1;
	//cout<<check(0,0,a);
}
