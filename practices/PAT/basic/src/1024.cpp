#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string line;
	cin >> line;
	vector<char>v[2], & v0 = v[0], & v1 = v[1];

	int pos = 1;
	for (int i = 0; i < 2; i++) {
		while (pos < line.size()) {
			char ch = line[pos++];
			if (ch != 'E') {
				v[i].push_back(ch); continue;
			}
			break;
		}
	}

	
	int e = 0;//ָ��
	for (int i = 1; i < v1.size();i++) {
		e = e*10+v1[i]-'0';
	}
	e = v1[0] == '-' ? -e : e;

	pos = find(v[0].begin(), v[0].end(), '.') - v[0].begin();//"."����λ��
	int tow = e>0?1:-1;//�ƶ�����
	while (e != 0) {
		if (pos == v0.size() - 1) {
			v0.push_back('0');
		}
		else if (pos == 0) {
			v0.insert(v0.begin(), '0');
			pos++;
		}
		swap(v0[pos], v0[pos + tow]);
		e -= tow;
		pos += tow;
	}

	if(*(v0.end()-1)=='.')v0.erase(v0.end()-1);//ĩβ'.'ɾ��
	if (*(v0.begin()) == '.')v0.insert(v0.begin(), '0');//��ͷ'.'����ǰ��0
	
	if(line[0]=='-') cout << line[0];//����  err:�������������λ
	for (auto i : v0) {
		cout << i;
	}
	return 0;
}