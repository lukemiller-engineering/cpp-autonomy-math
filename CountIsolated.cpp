/* 
Given a 2D binary grid (0 = empty, 1 = point), count how many isolated 1s there are.

Written by Luke Miller
July 5th 2025

*/

#include<iostream>
#include<vector>

int main(){
	std::vector<std::vector<int>> grid = {
  	{1, 0, 0, 0},
  	{0, 1, 1, 0},
  	{0, 1, 0, 0},
  	{0, 0, 0, 1}};

	int numIso = 0; //number of isolated points
	std::vector<std::pair<int,int>> coords;

	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[i].size();j++){
			if(grid[i][j]==0) continue;
			
			bool no_right = false;
			bool no_left = false;
			bool no_up = false;
			bool no_down = false;

			//search right
			if(j+1>=grid[i].size() || grid[i][j+1] == 0) no_right = true;

			//search left
			if(j-1<0 || grid[i][j-1] == 0) no_left = true;

			//search up
			if(i-1<0 || grid[i-1][j] == 0) no_up = true;

			//search down
			if(i+1>=grid.size() || grid[i+1][j] == 0) no_down = true;

			if(no_down==true && no_up == true && no_right == true && no_left == true){
				coords.push_back({i,j}); //new isolated number
				numIso++;
			}
		}
	}
	std::cout<<"The coordinates of the isolated numbers are: " << std::endl;
	for(int i=0;i<coords.size();i++){
		std::cout<< i+1 << ": (" << coords[i].first << "," << coords[i].second << ")" << std::endl;
	}
	return 0;
}