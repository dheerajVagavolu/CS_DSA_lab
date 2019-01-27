#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		int data[n+1];
		int left[n+1];

		data[0] = 0;
		left[0] = -1;

		for(int i = 0;i<n/2;i++)
		{
			int x,y;
			cin >> x >> y;
			if(x<y){
				
			left[x]=1;
			left[y]=0;				
			}else{
				left[x]=0;
				left[y]=1;
			}

			data[x]=y;
			data[y]=x;
		}

		stack<int> s;
		int ans = 1;

		for(int i = 1;i<=n;i++)
		{
			if(left[i]==1)
			{
				s.push(i);
			}else if(left[i]==0)
			{
				int check = s.top();
				if(data[i]!=check){
					ans = 0;
				}else{
					s.pop();
				}
			}
		}

		if(ans == 1)
		{
			cout << "Yes" <<endl;
		}else{
			cout << "No" << endl;
		} // printing the answer.


	}
	return 0;
}