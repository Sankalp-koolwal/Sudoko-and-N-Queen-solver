#include<iostream>
#include<cmath>
using namespace std;
const int D=9;
bool sudokoSolver(int board[][9],int n,int r,int c);
bool canPlace(int board[][9],int n,int r,int c,int no)
{
	if(board[r][c]!=0)
		return sudokoSolver(board,n,r,c+1);
	for(int x=0;x<n;x++)
	{
		if(board[r][x]==no)
			return false;
		if(board[x][c]==no)
			return false;
	}
	int rootn=sqrt(n);
	int boxRow=r/rootn;
	int boxCol=c/rootn;
	int boxStartCellRow=boxRow*rootn;
	int boxStartCellCol=boxCol*rootn;
	for(int i=boxStartCellRow;i<boxStartCellRow+rootn;i++)
	{
		for(int j=boxStartCellCol;j<boxStartCellCol+rootn;j++)
		{
			if(board[i][j]==no)
				return false;
		}
	}
	return true;
}
bool sudokoSolver(int board[D][D],int n,int r,int c)
{
	//base case
	if(r==n)
	{
		//print the board
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;

	}

	if(c==n)
		return sudokoSolver(board,n,r+1,0);
    if(board[r][c]!=0){
        return sudokoSolver(board,n,r,c+1);
    }
	for(int no=1;no<=9;no++)
	{
		if(canPlace(board,n,r,c,no))
		{
			board[r][c]=no;
			bool furtherSucccess=sudokoSolver(board,n,r,c+1);
			if(furtherSucccess)
				return true;
			board[r][c]=0;
		}
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	int board[D][D];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>board[i][j];
		}
	}
	sudokoSolver(board,n,0,0);

	return 0;

}