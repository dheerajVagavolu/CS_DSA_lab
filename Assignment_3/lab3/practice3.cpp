#include<bits/stdc++.h>

using namespace std;

class Bag{
	int ar[3000];
	int size;
	int min;
public:
	Bag();
	void insert(int);
	void deleteit(int);
	int minimum();
};

Bag::Bag(){
	size = 0;
	min = -1;
}

void Bag::insert(int n){
	ar[size] = n;
	size ++ ;
	if(n < min){
		min = n;
	}
}

void Bag::deleteit(int n){
	int i = 0;
	while(ar[i]!=n){
		i++;
	}
	for(int j = i;j<size-1;j++){
		ar[j] = ar[j+1];
	}
}

int Bag::minimum(){
	int mn = ar[0];
	for(int i = 0;i<size;i++){
		if(ar[i]<mn){
			mn = ar[i];
		}
	}
	return mn;
}

int main()
{
	Bag b;
	while(true){
		int n,m;
		cin >> n;
		if(n==0){
			break;
		}else if(n==1){
			cin >> m;
			b.insert(m);
		}else if(n==2){
			cin >> m;
			b.deleteit(m);
		}else if(n==3){
			int a = b.minimum();
			cout << a << endl;
		}


	}
}