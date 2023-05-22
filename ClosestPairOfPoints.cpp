/*
*
@author : Asutosh Karanam
*
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>

using namespace std;

//Class to define a point and it's co-ordinates
class CoOrdinates
{
	protected:
		int x, y;
	public:
		
		CoOrdinates() : x{0}, y{0} 
		{}
		//Getters and Setters
		bool getCoOrdinates(int* x1, int* y1) {
			*x1 = x;
			*y1 = y;
			return true;
		}
		
		void setCoOrdinates(int x1, int y1) {
			x=x1;
			y=y1;
		}
};

//Initialize the Main vector of the Co-ordinates
void init_point_list(vector<CoOrdinates>& mainArray)
{
	CoOrdinates c[16];

	c[0].setCoOrdinates(2,3);
	c[1].setCoOrdinates(12,30);
	c[2].setCoOrdinates(40,50);
	c[3].setCoOrdinates(5,1);
	c[4].setCoOrdinates(12,10);
	c[5].setCoOrdinates(3,4);
	c[6].setCoOrdinates(41,51);
	c[7].setCoOrdinates(42,52);
	c[8].setCoOrdinates(43,53);
	c[9].setCoOrdinates(44,54);
	c[10].setCoOrdinates(45,55);
	c[11].setCoOrdinates(46,56);
	c[12].setCoOrdinates(47,57);
	c[13].setCoOrdinates(48,58);
	c[14].setCoOrdinates(49,59);
	c[15].setCoOrdinates(50,60);

	for(int i=0; i<16; i++)
		mainArray.push_back(c[i]);

}
//Comparator for Sorting
bool comparatorXCoOrdinate(CoOrdinates i1, CoOrdinates i2)
{
	int x11,x22,y11,y22;
	i1.getCoOrdinates(&x11,&y11);
	i2.getCoOrdinates(&x22,&y22);
    return (x11 < x22);
}
//Comparator for Sorting
bool comparatorYCoOrdinate(CoOrdinates i1, CoOrdinates i2)
{
	int x11,x22,y11,y22;
	i1.getCoOrdinates(&x11,&y11);
	i2.getCoOrdinates(&x22,&y22);
    return (y11 < y22);
}
//Utility to find Distance
float findDistance(CoOrdinates i1, CoOrdinates i2)
{	
	int x11,x22,y11,y22;
	i1.getCoOrdinates(&x11,&y11);
	i2.getCoOrdinates(&x22,&y22);
	return sqrt(((x22-x11)*(x22-x11)) +	((y22-y11)*(y22-y11)));
}
//Main recursive call
float closestPair(vector<CoOrdinates> dots, int sz)
{
	//return infinity if the available points are less than 2
	if (sz <= 1) {
		return FLT_MAX;
	}
	// If # of points <= 3, directly find the min.distance
	if (sz <= 3)
	{
		float min = FLT_MAX;
		for (int i = 0; i < sz; i++) {
			for (int j = i+1; j < sz; j++) {
				if (findDistance(dots[i], dots[j]) < min)  min = findDistance(dots[i], dots[j]);
			}
		}
		return min;
	}
	
	//Start Recursion from start to Mid and Mid to end
	CoOrdinates midPoint = dots[sz/2];
	float leftSide = closestPair(dots, (sz/2));
	vector<CoOrdinates> subvector = {dots.begin() + (sz/2), dots.end()};
	float rightSide = closestPair(subvector, sz - (sz/2));
	
	//Construct the Delta-region
	vector<CoOrdinates> deltaRegion;
	for (int i = 0; i < sz; i++) {
		int x1,y1,x2,y2;
		dots[i].getCoOrdinates(&x1,&y1);
		midPoint.getCoOrdinates(&x2,&y2);
		if (abs(x1 - x2) < std::min(leftSide, rightSide))
			deltaRegion.push_back(dots[i]);
	}
	
	//find the Closest Pair in the Delta Region
	//Sort by Y CoOrdinate
	sort(deltaRegion.begin(), deltaRegion.end(), comparatorYCoOrdinate);
	float minimum = std::min(leftSide, rightSide);
	for (int i = 0; i < deltaRegion.size(); i++) {
		int x,y;
		deltaRegion[i].getCoOrdinates(&x,&y);
		for (int j = i+1, x1, y1; (j < deltaRegion.size()) && (deltaRegion[j].getCoOrdinates(&x1,&y1)) && ((y1 - y) < minimum); j++) {
			if (findDistance(deltaRegion[i],deltaRegion[j]) < minimum) {
				minimum = findDistance(deltaRegion[i], deltaRegion[j]);
			}
		}
	}
	//update the minimum if any of these distances is less than previous Minimum
	return std::min(minimum, std::min(leftSide,rightSide));
}

int main(int argc, char* argv[])
{	
	vector<CoOrdinates> points; //Array of all points

	init_point_list(points); // Call to initialize the list
	
	sort(points.begin(), points.end(), comparatorXCoOrdinate); //Sort by X Co-ordinate
	
	cout<<"The closest pair of Points are distance is "<<closestPair(points, points.size())<<endl;
	
	return 0;
}