#include <iostream>
#include <vector>

/*
 * moving_average_filter.cpp
 * Computes the moving average of given data with a fixed window size.
 *
 * Author: Luke Miller
 * Date: 2025-07-03
 *
 * Compile with:
 *     g++ moving_average_filter.cpp -o moving_average_filter -std=c++17
 */

const std::vector<double> data = {1,2,3,4,5,6}; //define data globally

double movingAverage(const std::vector<double> window){
	double sum = 0;

	for(int i=0;i<window.size();i++){
		sum = sum+window[i];
	}
	double mean = sum/window.size();
	return mean;
}

int main(){
	int window_size; //window size
	int j=0; //window loop counter
	bool is_filled false; //trigger if window is filled

	std::cout << "Input window size: ";
	std::cin>>  window_size;
	std::vector<double> window;

	if(window_size>data.size()){
		std::cout << "Window exceeds data size, truncating window size to " << data.size();
		window_size = data.size();
	}
	
	std::cout << "The moving average is: " << std::endl;
	//Loop through data
	for(int i=0;i<data.size();i++){

	//assemble the window
		if(is_filled==false){
			window.push_back(data[j]);
				if(window.size()>=window_size){
					is_filled=true;
				}
		} 
		if(is_filled==1){
			window[j] = data[i];
			j = j+1;
			if(j>=window_size){
				j = 0;
			}
		}
		double mean = movingAverage(window);
		std::cout<< mean <<std::endl;	
	}
	return 0;
}