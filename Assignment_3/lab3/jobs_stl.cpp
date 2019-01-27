#include<iostream>
#include<queue>

using namespace std;
int high(queue<int> q,int n){
	int high = 1;
	for(int i = 0;i<n;i++)
	{
		int a = q.front();
		if(a>high)
		{
			high = a;
		}
		q.pop();
	}
	return high;
}
int evaluate(queue<int> q, int n, int m)
{
	int minutes=0;
	int size = q.size();
	while(1)
	{
		int a = q.front();
		if(m==0){
			if(a<high(q,size)){
				q.push(a);
				q.pop();
				m = size-1;
			}else{
				minutes++;
				break;
			}
		}else{
			if(a<high(q,size)){
				q.push(a);
				q.pop();
				m--;
			}else{
				q.pop();
				minutes++; // printing
				size--;
				m--;
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
		int n,m;
		cin >> n >> m;
		queue<int> q;
		
		for(int i = 0;i<n;i++)
		{
			int input;
			cin >> input;			
			q.push(input);
		}

		int ans = evaluate(q,n,m);
		cout << ans << endl;

		
	}
}