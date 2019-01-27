#include<iostream>
#include<cstdlib>

using namespace std;

class Queue{
	public:
	int ar[1000];
	int index;//number of elements
	int start;//start pointer.
	int end;//end pointer.

	Queue(int); // initializes the array of n elements.
	void insert(int); //adds element to the last.
	void remove(); //removes the first element.
	int number(); // returns number of elements left in the queue.
	int first(); // returns the first element of the queue.
	int returnend(); // returns the last element added.
};



Queue::Queue(int n){
	start = 0;
	end = n-1;
	index = n;
	
	for(int i = 0;i<n;i++)
	{
			ar[i]=i+1;
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


int evaluate(int n,int k)
{
	Queue ppl(n);
	int a = ppl.number();
	while(a>1){
		for(int i = 0;i<k;i++){
			int removed = ppl.first();
			//cout << removed << endl;
			ppl.remove();
			ppl.insert(removed);
		}
		ppl.remove();
		a = ppl.number();
		//cout << "a " << a << endl;
	}
	int ans = ppl.returnend();
	return ans;
	
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		int ans = evaluate(n,k);
		cout << ans << endl;
	}
}