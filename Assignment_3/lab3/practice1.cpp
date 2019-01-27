#include<iostream>
#include<cstdlib>

using namespace std;

class Queue{
	public:
	int ar[2000];
	int index;//number of elements
	int start;//start pointer.
	int end;//end pointer.

	Queue(int,int); // initializes the array of n elements.
	void insert(int); //adds element to the last.
	void remove(); //removes the first element.
	int number(); // returns number of elements left in the queue.
	int first(); // returns the first element of the queue.
	int returnend(); // returns the last element added.
};



Queue::Queue(int n, int m){
	start = 0;
	end = n-1;
	index = n;
	//ar = (int*)malloc(n*sizeof(int));
	for(int i = 0;i<n;i++)
	{
		if((m+i)%n!=0){
			ar[i]=(m+i)%n;	
		}else{
			ar[i]=n;
		}
		
		
	}
}

void Queue::insert(int n){
	end = (end+1)%2000;
	ar[end] = n;
	index++;
}

int Queue::returnend(){
	int a = ar[end];
	return a;
}


void Queue::remove(){
	ar[start] = -1;
	start++;
	index--;
}

int Queue::number(){
	return index;
}

int Queue::first(){
	return ar[start];
}


int evaluate(int n,int m)
{
	Queue A(n,m);
	int a = A.number();

	

	while(a>1){
			
			int p = A.first();
			A.remove();
			int q = A.first();
			A.remove();
			A.insert(p);
			
			a = A.number();	
	}
	int j = A.returnend();
	return j;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		int ans = evaluate(n,m);
		cout << ans << endl;
	}
}