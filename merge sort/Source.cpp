#include <iostream>
#include <vector>

using namespace std;

void slit(vector<int>& a, vector<int>& left, vector<int>& right) {
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j] < right[k]) {
			a[i] = left[j];
			j++;
		}
		else {
			a[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		a[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		a[i] = right[k];
		k++; i++;
	}
}


void sort(vector<int>& a) {
	if (a.size() <= 1) return;

	vector<int> left;
	vector<int> right;
	int i = 0;

	while (i < a.size() / 2) {
		left.push_back(a[i]);
		i++;
	}
	while (i < a.size() ) {
		right.push_back(a[i]);
		i++;
	}

	sort(left);
	sort(right);
	slit(a, left, right);

}


int main() {
	vector<int> arr;
	int a, size, i;
	i = 0;
	cout << "paste size: " << endl;
	cin >> size;
	cout << "paste numbers: " << endl;
	while (size > 0) {
		cin >> a;
		arr.push_back(a);
		size--;
	}
	
	sort(arr);

	for (i; i < arr.size(); i++)
		cout << arr[i] << ' ';
	cout << endl;
	i = 0;

	return 0;
	
}



	