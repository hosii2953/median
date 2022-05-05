#include "Solution.h"
#include <vector>
#include <Math.h>
using namespace std;

double Solution::Median(vector<int>& n1, vector<int>& n2)
{
	int length = n1.size() + n2.size();
	if (length % 2 == 1) {
		return getK(n1, n2, (length + 1) / 2);
	}
	else {
		return ((double)getK(n1, n2, length / 2) + (double)getK(n1, n2, length / 2 + 1))/2.0;
	}
}

int Solution::getK(vector<int>& n1, vector<int>& n2, int k)
{
	int length1 = n1.size();
	int length2 = n2.size();
	int i = 0, j = 0;

	while (true) {
		if (i == length1) {
			return n2[j + k - 1];
		}
		if (j == length2) {
			return n1[i + k - 1];
		}
		if (k == 1) {
			return min(n1[i], n2[j]);
		}

		int newi = min(length1 - 1, i + k / 2 - 1);
		int newj = min(length2 - 1, j + k / 2 - 1);
		int num1 = n1[newi];
		int num2 = n2[newj];
		if (num1 <= num2) {
			k = k - (newi - i + 1);
			i = newi + 1;
		}
		else {
			k = k - (newj - j + 1);
			j = newj + 1;
		}
	}
}
