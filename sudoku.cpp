#include<iostream>
#include<string>
#include <ctime>
#define N 9
using namespace std;
bool checkValid1(int value,int i,int j,int sudoku[N][N])
{
	int x,y;
	x=i-i%3;
	y=j-j%3;
	//cout<<x<<" "<<y<<endl;
	for(int m=x;m<x+3;m++)
	{
		for(int n=y;n<y+3;n++)
		{
			//cout<<m<<" "<<n<<endl;
			if(sudoku[m][n]==value)
				return false;
		}
	}

	for(int m=0;m<N;m++)
		if(sudoku[m][j]==value)
			return false;
	for(int m=0;m<N;m++)
		if(sudoku[i][m]==value)
			return false;

	return true;
}
bool checkValid(int value,int i,int j,int sudoku[N][N])
{
	int x,y;
	if( i<=2&&j<=2)
	{

		x=0;
		y=0;
		for(int m=x;m<x+3;m++)
			for(int n=y;n<y+3;n++)
				if(sudoku[m][n]==value)
					return false;
	}
	else if(i<=2&&j<=5)
	{
		x=0;
		y=3;
		for(int m=x;m<x+3;m++)
			for(int n=y;n<y+3;n++)
				if(sudoku[m][n]==value)
					return false;
	}
	else if(i<=2&&j<=8)
	{
		x=0;
		y=6;
		for(int m=x;m<x+3;m++)
			for(int n=y;n<y+3;n++)
				if(sudoku[m][n]==value)
					return false;
	}
	else if(i<=5&&j<=2)
	{
		x=3;
		y=0;
		for(int m=x;m<x+3;m++)
			for(int n=y;n<y+3;n++)
				if(sudoku[m][n]==value)
					return false;
	}
	else if(i<=8&&j<=2)
	{
		x=6;
		y=0;
		for(int m=x;m<x+3;m++)
			for(int n=y;n<y+3;n++)
				if(sudoku[m][n]==value)
					return false;
	}
	else if(i<=5&&j<=5)
	{
		x=3;
		y=3;
		for(int m=x;m<x+3;m++)
			for(int n=y;n<y+3;n++)
				if(sudoku[m][n]==value)
					return false;
	}
	else if(i<=5&&j<=8)
	{
		x=3;
		y=6;
		for(int m=x;m<x+3;m++)
			for(int n=y;n<y+3;n++)
				if(sudoku[m][n]==value)
					return false;
	}
	else if(i<=8&&j<=5)
	{
		x=6;
		y=3;
		for(int m=x;m<x+3;m++)
			for(int n=y;n<y+3;n++)
				if(sudoku[m][n]==value)
					return false;
	}
	else
	{
		x=6;
		y=6;
		for(int m=x;m<x+3;m++)
			for(int n=y;n<y+3;n++)
				if(sudoku[m][n]==value)
					return false;
	}
	for(int m=0;m<N;m++)
		if(sudoku[m][j]==value)
			return false;
	for(int m=0;m<N;m++)
		if(sudoku[i][m]==value)
			return false;

	return true;
}
bool fillSudoku(int i,int j,int sudoku[N][N])
{
	if(sudoku[i][j]==0)
	{
		for(int value=1;value<10;value++)
		{
			if(checkValid1(value,i,j,sudoku))
			{
				sudoku[i][j]=value;
				if(j<N-1)
				{
					if(fillSudoku(i,j+1,sudoku))
						return true;
				}
				else
				{
					if(i<N-1)
					{
						if(fillSudoku(i+1,0,sudoku))
							return true;
					}
					else
						return true;
				}
				sudoku[i][j]=0;
			}
		}
		return false;
	}

	if(j<N-1)
	{
		if(fillSudoku(i,j+1,sudoku))
			return true;
	}
	else
	{
		if(i<N-1)
		{
			if(fillSudoku(i+1,0,sudoku))
				return true;
		}
		else
			return true;
	}
	return false;
}

int main()
{
	clock_t begin = clock();

	int sudoku[9][9]=
	{{3, 0, 6, 5, 0, 8, 4, 0, 0},
			{5, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 8, 7, 0, 0, 0, 0, 3, 1},
			{0, 0, 3, 0, 1, 0, 0, 8, 0},
			{9, 0, 0, 8, 6, 3, 0, 0, 5},
			{0, 5, 0, 0, 9, 0, 6, 0, 0},
			{1, 3, 0, 0, 0, 0, 2, 5, 0},
			{0, 0, 0, 0, 0, 0, 0, 7, 4},
			{0, 0, 5, 2, 0, 6, 3, 0, 0}};

	fillSudoku(0,0,sudoku);
	//cout<<checkValid(6,0,0,sudoku);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<sudoku[i][j]<<"  ";
		cout<<endl;
	}
	clock_t end = clock();
	cout<<double(end - begin) / CLOCKS_PER_SEC;
}

