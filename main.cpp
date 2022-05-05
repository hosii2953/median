#include<iostream>
#include<vector>
#include<fstream>
#include"Solution.h"
using namespace std;

int main() {
	int n;
	vector<int> n1;
	vector<int> n2;

	Solution s;

	fstream f1;
	f1.open("try.txt", ios::in);
	if (!f1.is_open()) {
		cerr << "can not open file" << endl;
		exit(-1);
	}
	f1 >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		f1 >> temp;
		n1.push_back(temp);
		
	}
	for (int j = 0; j < n; j++) {
		f1 >> temp;
		n2.push_back(temp);
	}
	f1.close();

	double median = s.Median(n1, n2);

	fstream f2;
	f2.open("result.txt", ios::out | ios::app);
	if (!f2.is_open()) {
		cerr << "can not open file" << endl;
		exit(-1);
	}
	f2 << median;
	f2.close();

	cout << median << endl;

	return 0;
}