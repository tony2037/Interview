#include <vector>
#include <stdio.h>
using namespace std;


void swap(vector<int> &array, int i, int j) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void helper(vector<int> &array, int start, int end) {
	int N = array.size();
	if (0 > start) return;
	if (N <= end) return;
	if (start >= end) return;
	int pivot = array[start];
	int i = start + 1;
	int j = end;
	while (i < j) {
		while (N > i && pivot > array[i]) i++;
		while (0 <= j && pivot < array[j]) j--;
        if (i < j)
		    swap(array, i, j);
	}
	swap(array, start, j);
	helper(array, start , j);
	helper(array, j, end);
}

vector<int> quickSort(vector<int> array) {
  // Write your code here.
	int N = array.size();
	helper(array, 0, N - 1);
  return array;
}


int main() {
	vector<int> array = {8, 5, 2, 9, 5, 6, 3};
	vector<int> ret = quickSort(array);
	for (int i : ret) {
		printf("%d ", i);
	}
}
