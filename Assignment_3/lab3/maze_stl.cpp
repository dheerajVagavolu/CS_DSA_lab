#include<iostream>
#include<queue>

using namespace std;

class Ordinate{
	public:
	int x;
	int y;

	Ordinate(int, int);
	Ordinate right();
	Ordinate down();
	void print();
};

void Ordinate::print()
{
	cout << x << " " << y << endl;
}

Ordinate::Ordinate(int a, int b)
{
	x = a;
	y = b;
}

Ordinate Ordinate::right(){
	Ordinate newc(x+1,y);
	return newc;
}

Ordinate Ordinate::down(){
	Ordinate newc(x,y+1);
	return newc;
}

int A[100][100];

int verify(Ordinate point, Ordinate dest){
	if(point.x > dest.x || point.y > dest.y)
	{
		return 0;
	}
	if(A[point.x][point.y]==0)
	{
		return 0;
	}
	if(point.x == dest.x && point.y == dest.y)
	{
		return 1;	
	}
	return 2;
	
}

int main(){

	int t;
	cin >> t;
	while(t--)
	{
		int m;
		int n;
		cin >> m >> n;
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				int n;
				cin >> n;
				A[i][j] = n;
			}

		}	// Input stored in Array.
		int sx,sy;
		cin >> sx >> sy;
		Ordinate source(sx,sy);
		
		cin >> sx >> sy;
		Ordinate dest(sx,sy); // Source and Destination points recorded.
		
		queue<Ordinate> qp;
		qp.push(source);
		int ans = 0; // queue to store points created.

		while(qp.size()!=0)
		{
			Ordinate top = qp.front();
			
			Ordinate tr = top.right();
			
			Ordinate td = top.down();
			
			qp.pop();
			int a = verify(tr,dest);
			int b = verify(td,dest);
			if(a==2){
				qp.push(tr);
			}
			if(b==2){
				qp.push(td);
			}

			if(a==1||b==1){
				ans = 1;
				break;
			}



		} /// to check if path exists.

		if(ans == 1)
		{
			cout << "yes" <<endl;
		}else{
			cout << "no" << endl;
		} // printing the answer.

	}

	return 0;
}