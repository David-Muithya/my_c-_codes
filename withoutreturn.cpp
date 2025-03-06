#include <iostream>
#include <cmath>
using namespace std;
void area();
int main()
{
	  area();
	return 0;
	}
	void area(){
		float height,length,hypotenuse,area;
		cout<<"Enter the height \n";
		cin>>height;
		cout<<"Enter the length \n";
		cin>>length;
 		hypotenuse =sqrt(pow(height,2)+(pow(length,2)));
		area=(length*height)/2;
		cout<<"the area is "<<area;
		cout<<"the hypotenuse is "<<hypotenuse;
		
	}












































