#include <iostream>
#include <vector>
using namespace std;



int main() {
	unsigned int A, B,D,sum;
	cin >> A >> B >> D;
	sum = A + B;

	vector<int> output;

	do{
		output.push_back(sum%D);
		sum /= D;
	} while (sum != 0);//err: while��ѭ����A+B=0ʱ��������ʸ�do-while

	for (auto i = output.rbegin(); i != output.rend(); i++) {
		cout << *i;
	}
	
}