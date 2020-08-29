#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;


int main() {
	vector<int> P;
	int M, N, index = 0;;
	cin >> M >> N;

	int n=2;
	while (true) {
		bool isPrime = true;
		for (int i = 2; i <= sqrt(n); ++i) {
			if (n % i == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			P.push_back(n);
			if (++index >= N) {
				break;
			}
		}
		++n;
	}
	int line = 1;
	for (int i=M;i<=N;i++)
	{
		cout << P[i - 1];
		if(line++==10){
			cout << endl;
			line = 1;
		}
		if (i != N && line!=1)cout << " ";
	}
	return 0;
}

