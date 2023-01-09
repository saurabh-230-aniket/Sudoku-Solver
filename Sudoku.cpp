//SUDOKU SOLVER
#include<bits/stdc++.h>
using namespace std;
void printBoard(vector<vector<int> > arr){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(j==8){
			    if(arr[i][j]!=0)
			    cout<<" | "<<arr[i][j]<<" |";
			    else
			    cout<<" | "<<" "<<" |";
			}
			else{
			    if(arr[i][j]!=0)
			    cout<<" | "<<arr[i][j];
			    else
			    cout<<" | "<<" ";
			}
		}
		cout<<endl<<"--------------------------------------"<<endl;
	}
}
void mainLogic(vector<vector<int> > arr,int i,int j,map<pair<int,int>,map<int,int> > submat,vector<map<int,int> > rmap,	vector<map<int,int> > cmap){
	if(i==9){
		//end of Sudoku so print it
		cout<<"             COMPLETE BOARD"<<endl;
		printBoard(arr);
		return;
	}
	if(j==9){
		mainLogic(arr,i+1,0,submat,rmap,cmap);
		return;
	}
	
	if(arr[i][j]!=0){
		mainLogic(arr,i,j+1,submat,rmap,cmap);
		return;
	}
	
	//now check for the possibility of every number from 0 to 9
	for(int n=1;n<=9;n++){
		
		int subi=i/3;
		int subj=j/3;
		
		if(!submat[{subi,subj}][n] and !rmap[i][n] and !cmap[j][n]){
			
			//Do
			submat[{subi,subj}][n]=1;
			rmap[i][n]=1;
			cmap[j][n]=1;
			arr[i][j]=n;
			
			mainLogic(arr,i,j+1,submat,rmap,cmap);//recursion
			
			//Undo
			submat[{subi,subj}][n]=0;
			rmap[i][n]=0;
			cmap[j][n]=0;
			arr[i][j]=0;
		}
	}
}
void solve(vector<vector<int> >arr){
	map<pair<int,int>,map<int,int> > submat;
	vector<map<int,int> > rmap(9);
	vector<map<int,int> > cmap(9);
	
	//filling all the maps
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(arr[i][j]!=0){
				submat[{i/3,j/3}][arr[i][j]]=1;
				rmap[i][arr[i][j]]=1;
				cmap[j][arr[i][j]]=1;
			}
		}
	}
	mainLogic(arr,0,0,submat,rmap,cmap);
}
int main(){
	cout<<"*****  Welcome To The Sudoku Solver  *********"<<endl<<endl;
	cout<<"Please enter the 9x9 sudoku problem"<<endl<<"**Enter the numbers and put one '0' for incomplete cells**"<<endl;
// 	vector<vector<int>> arr(9,vector<int>(9));
vector<vector<int> > arr={ {5,3,0,0,7,0,0,0,0},{6,0,0,1,9,5,0,0,0},{0,9,8,0,0,0,0,6,0},{8,0,0,0,6,0,0,0,3},{4,0,0,8,0,3,0,0,1},{7,0,0,0,2,0,0,0,6},{0,6,0,0,0,0,2,8,0},{0,0,0,4,1,9,0,0,5},{0,0,0,0,8,0,0,7,9} };
//	for(int i=0;i<9;i++){
//		for(int j=0;j<9;j++){
//			cin>>arr[i][j];
//		}
//	}
	cout<<endl;
//	vector<vector<int> > arr={ {5,3,0,0,7,0,0,0,0},{6,0,0,1,9,5,0,0,0},{0,9,8,0,0,0,0,6,0},{8,0,0,0,6,0,0,0,3},{4,0,0,8,0,3,0,0,1},{7,0,0,0,2,0,0,0,6},{0,6,0,0,0,0,2,8,0},{0,0,0,4,1,9,0,0,5},{0,0,0,0,8,0,0,7,9} };
	cout<<"              INCOMPLETE BOARD"<<endl<<endl;
	printBoard(arr);
	cout<<endl;
	solve(arr);	
}