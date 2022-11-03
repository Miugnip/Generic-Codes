#include <iostream>
#include <vector>
using namespace std;
int Maior;
vector<int>Vet;
// generates all subsets
void generate(int k, vector<bool> & my_set, int N)
{
	bool Ver=true;
	if(k == N)
	{
		// shows the subset
		cout << "{ ";
		for(int i = 0; i < Maior+1 ; i++)
		{
			if(my_set[i] == true)
				cout << i  << " ";
		}
		cout << "}\n";
	}
	else
	{
		my_set[Vet[k]] = true;
		generate(k + 1, my_set, N);
		my_set[Vet[k]] = false; // backtracking
		generate(k + 1, my_set, N);
	}
}

int main()
{
	int N,X;
	Maior=0;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>X;
		Vet.push_back(X);
		Maior=max(Maior,X);
	}
	vector<bool> my_set(Maior+1);

	generate(0, my_set, N);

	return 0;
}
