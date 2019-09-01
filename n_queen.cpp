#include<iostream>
using namespace std;
bool is_it_safe(int board[][10],int i,int j,int n){
  //For Coloumn
	for(int k=0;k<n;k++){
		if(board[i][k]==1 || board[k][j]==1){
			return false;
		}
	}
	int r=i,c=j;
	while(r>=0 && c>=0){
		if(board[r][c]==1){
			return false;
		}
		r--;
		c--;
	}

	r=i;c=j;
	while(r>=0 && c<n ){
		if(board[r][c]==1){
			return false;
		}
		r--;
		c++;
	}

	return true;
}
bool solve_N_queen(int board[][10],int i,int n){
    //cout<<"hi";
  //Base Case->when you have successfully placed the queen at their right position.
  if(i==n){
    //Print the board.
    for(int row=0;row<n;row++){
      for(int col = 0;col<n;col++){
        if(board[row][col] == 1){
          cout<<"Q ";
        }
        else{
          cout<<"_ ";
        }
      }
      cout<<endl;
    }
    return true;
  }
 // cout<<i<<" ";
  int j;
  //Recursive Case
  //Try to place the queen in the current row and recursion will solve the problem for remaining rows
  for(j = 0;j<n;j++){
    if(is_it_safe(board,i,j,n)){
      board[i][j] = 1;
      bool next = solve_N_queen(board,i+1,n);
      if(next == true){
        return true;
      }
      board[i][j]=0;
    }
  }
  
  return false;
}
int main(){
int n;
  cin>>n;
  int board[10][10] = {0};
  solve_N_queen(board,0,n);
}
