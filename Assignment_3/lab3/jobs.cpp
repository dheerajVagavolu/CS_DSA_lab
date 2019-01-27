#include<iostream>
#include<cstdlib>

using namespace std;

class Queue{
	public:
	int ar[2000];
	int index;//number of elements
	int start;//start pointer.
	int end;//end pointer.

	Queue(int); // initializes the array of n elements.
	void insert(int); //adds element to the last.
	void remove(); //removes the first element.
	int number(); // returns number of elements left in the queue.
	int first(); // returns the first element of the queue.
	int returnend(); // returns the last element added.
	int first_index();
};



Queue::Queue(int n){
	start = 0;
	end = n-1;
	index = n;
	
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
	start++;
	index--;
}

int Queue::number(){
	return index;
}

int Queue::first(){
	return ar[start];
}

int Queue::first_index(){
	return start;
}


int evaluate(int n,int k)
{
	int job_index = k;
	int minutes = 0;
	
	Queue ppl(n);

	for(int i = 0;i<n;i++){
		int a;
		cin >> a;
		ppl.insert(a);
	}

	int value = ppl.ar[job_index];

	while(1){
		int top = ppl.first();
		int index = ppl.first_index();

		if(index != job_index){
			int test = 0;
			for(int i = 0;i<index;i++){
				if(top<ppl.ar[i]){
					test = 1;
					break;
				}
			}
			if(test == 0){
				ppl.insert(top);
				ppl.remove();
			}else{
				ppl.remove();
				minutes++;
			}

		}else{
			int test = 0;
			for(int i = 0;i<index;i++){
				if(top<ppl.ar[i]){
					test = 1;
					break;
				}
			}
			if(test == 0){
				ppl.insert(top);
				ppl.remove();
				job_index = job_index+(ppl.end-ppl.start+1);
			}else{
				ppl.remove();
				minutes++;
			}

		}
		

	}

	
	return minutes;
	
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,job;
		cin >> n >> job;
		int ans = evaluate(n,job);
		cout << ans << endl;
	}
}