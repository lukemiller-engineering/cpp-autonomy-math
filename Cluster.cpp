/* 
Cluster points within a distance, d

Distance threshold d = 2.0

Points:
(0, 0)
(1, 1)
(5, 5)
(6, 6)
(10, 10)

Written by Luke Miller 
July 5th 2025
*/

#include <iostream>
#include <vector>
#include <cmath>

double distance(const std::vector<double> PointI, const std::vector<double> PointJ){
	double dist = 0;

	for(int i = 0; i<PointI.size(); i++){
		dist = dist + (PointI[i]-PointJ[i])*(PointI[i]-PointJ[i]);
	}
	dist = std::sqrt(dist);
	return dist;
}

int main() {
	std::vector<std::vector<double>> points = {{0, 0}, {1, 1}, {5, 5},{6, 6},{10, 10}};
	double d = 2.0;
	std::vector<std::vector<int>> clusters;

	for(int i=0;i<(points.size()-1);i++){
		for(int j=i+1;j<points.size();j++){
			double dist = distance(points[i],points[j]); //find distance
			
			bool i_in = false;
			bool j_in = false;
			int i_cluster = -1;
			int j_cluster = -1;

			if(dist<=d){
				for(int k=0; k<clusters.size();k++){
					/*check which clusters contain i and j
					-if neither create i and j
					- if one add to cluster
					- if multiple then merge clusters */

					for(int m = 0; m < clusters[k].size();m++){
						if(clusters[k][m] == i){
							i_in = true;
							i_cluster = k;
						}
						if(clusters[k][m] == j){
							j_in = true;
							j_cluster = k;
						}
					}	
				}
				if(i_in==false && j_in ==false){
					//Case 1 create cluster
					clusters.push_back(std::vector<int> {i,j});
				}
				if(i_in==true && j_in==false){
					//Case 2 add to cluster
					clusters[i_cluster].push_back(j);
				}
				if(j_in==true && i_in==false){
					//Case 2 add to cluster
					clusters[j_cluster].push_back(i);
				}
				if(i_in==true && j_in==true){
					int first = std::min(i_cluster, j_cluster);
					int second = std::max(i_cluster, j_cluster);

					clusters[first].insert(clusters[first].end(), clusters[second].begin(), clusters[second].end());
					clusters.erase(clusters.begin() + second);
				}
			}
		}
	}

	//find points which are assigned to the clusters
	std::vector<bool> in_cluster(points.size(), false);
	
	// Mark assigned points
	for (const auto& cluster : clusters) {
    		for (int idx : cluster) {
        	in_cluster[idx] = true;
    		}
	}

	// Add singleton clusters for points that were never clustered
	for (int i = 0; i < points.size(); ++i) {
    		if (!in_cluster[i]) {
        	clusters.push_back({i});
    		}
	}

	std::cout << "The clusters are:" << std::endl;
	for(int i = 0; i<clusters.size();i++){
		std::cout << "Cluster " << i << ":";
		for(int j = 0; j<clusters[i].size(); j++){
			int idx = clusters[i][j];
			std::cout << "(" << points[idx][0] << ", " << points[idx][1] << ")";
        		if (j < clusters[i].size() - 1) std::cout << ", ";
    		}
    		std::cout << std::endl;
	}
	return 0;
}