#include<iostream>
using namespace std;

class Point{
public:
	int x,y;
	
	void Setpoint(int _x, int _y){
		x = _x;
		y = _y;
	}

	void pointGet(){
		cout << x << "," << y << endl; 
	}

	bool start(){
		return x == 0 && y == 0;
	}
};

int main()
{
	Point n1;
	Point n2;
	Point* n3;
	Point* n4;

	Point array [10];
	Point* pArray;
	pArray = new Point[10];
	
	for(int i = 0; i < 10 ; i++){
		array[i].Setpoint(i , i + 2);
		(pArray  + sizeof(Point)*i) -> Setpoint(i + 5, i + 10);
	} 
	for(int i = 0 ; i < 10 ; i++){
		array[i].pointGet();
		(pArray + sizeof(Point)*i) -> pointGet();
		cout << endl;
	}
	n4 = new Point;

	n3 = &n2;

	n1.Setpoint(2,8);
	n1.pointGet();
	
	n2.Setpoint(0,0);
	n2.pointGet();

	if(n1.start())
		cout << "n1 in star" << endl;
	if(n2.start())
		cout << "n2 in start" << endl;
	
	n3 -> pointGet();
	cout << "n3 pointer" << endl;
	
	n4 -> Setpoint(100,200);
	n4 -> pointGet();


	return 0;
}
