#include<iostream>
#include<queue>

using namespace std;

int evaluate(int n,int k)
{
	queue<int> ppl;
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