#include<iostream>

using namespace std;

class Queue{
	int start;
	int end;
	int number;
	int ar[2000];
	int nn = 2000;
public:
	Queue(int n);
	int size();
	void push(int n);
	int front();
	void pop();
};

Queue::Queue(int n){
	start = 0;
	end = 0;
	number = 0;
}

int Queue::size(){
	return number;
}

void Queue::push(int n){
	ar[end] = n;
	end=(end+1)%nn;
	number++;
}

int Queue::front(){
	if(number!=0){
		int a = ar[start];
		return a;	
	}
}

void Queue::pop(){
	
		ar[start] = -1;
		start=(start+1)%nn;
		number--;
	
}

int evaluate(int n,int k)
{
	Queue ppl(n);
	for(int i = 0;i<n;i++){
		ppl.push(i+1);
	}
	
	while(ppl.size()>1){
		for(int i = 0; i<k;i++){	
			int a = ppl.front();
			ppl.pop();
			ppl.push(a);	
		}
		ppl.pop();
	}
	int ans = ppl.front();
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