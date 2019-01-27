#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Queue{
	public:
	string ar[2000];
	int index;//number of elements
	int start;//start pointer.
	int end;//end pointer.

	Queue(); // initializes the array of n elements.
	void insert(string); //adds element to the last.
	void remove(); //removes the first element.
	int number(); // returns number of elements left in the queue.
	string first(); // returns the first element of the queue.
	string returnend(); // returns the last element added.
};



Queue::Queue(){
	start = 0;
	end = 1;
	index = 2;
	ar[0] = '0';
	ar[1] = '1';
}

void Queue::insert(string n){
	end = (end+1)%2000;
	ar[end] = n;
	index++;
}

string Queue::returnend(){
	string a = ar[end];
	return a;
}


void Queue::remove(){
	ar[start] = "-1";
	start = (start+1)%2000;
	index--;
}

int Queue::number(){
	return index;
}

string Queue::first(){
	return ar[start];
}

void evaluate(int n){
	Queue A;
	//cout << A.ar[0] << endl << A.ar[1] << endl;
	//while(A.end < n){
	for(int i = 0 ;i<n;i++){
		string first = A.first();
		cout << first << endl;
		string insert1 = first + "0";
		string insert2 = first + "1";
		A.insert(insert1);
		A.insert(insert2);
		A.remove();
	}

}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		evaluate(n);
			cout << endl;
	}
}