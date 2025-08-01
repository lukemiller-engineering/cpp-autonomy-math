#include <iostream>
#include <vector>

/* Moving Average Filter 
   Written by Luke Miller
   August 1st 2025

   This moving average filter improves upon the existing moving average filter by solving the problem in O(1) vs O(k)

*/

double takeSum(const std::vector<double> &window,const double sum_last, const bool filled, const int j){
	double sum = 0;
	int k = window.size();
	if(filled==false){
		sum = sum_last + window[j]; 
	} else if(filled==true){
		int idx = (j+1)%k;
		sum = sum_last + window[j] - window[idx];
	}
	return sum;
}
double movingAverage(const bool filled,const int j, const int k, const double sum){
	double Avg = 0;

	if(filled==false){
		Avg = sum/(j+1);
	} else {
		Avg = sum/k;
	}
	return Avg;
}

int main(){
	constexpr int N = 10; // data size
	std::vector<double> data = {1,2,3,4,5,6,7,8,9,10};

	int i = 0; //counter for data
	int j = 0; //counter for window
	double sum_last = 0;

	constexpr int k = 5; //window size
	std::vector<double> window(k,0.0); 

	bool filled=false;
	while(true){
		window[j] = data[i];
		
		double sum = takeSum(window,sum_last,filled,j);
		sum_last = sum;

		double Avg = movingAverage(filled,j,k,sum);
		
		std::cout << Avg << std::endl;

		j = j+1;
		if(j>=k){ //if window is filled
			j=0;
			if(filled==false) filled=true;
		}

		i = i+1;
		if(i>=N){ //if data is overfilled
			i=0;
		}
	}
	
	return 0;
}