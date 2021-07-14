#include <vector>
#include "heapsort.h"
using namespace std;

class Heap {
public:
	vector<int> vec;
	Heap(vector<int> array) {
		buildHeap(array);
	}
	void buildHeap(vector<int> array) {
		this->vec = array;
		int N = this->vec.size();
		int firstParentIndex = (N - 2) / 2;
		for (; firstParentIndex >= 0; firstParentIndex--) {
			siftdown(firstParentIndex, N - 1);
		}
	}
	
	void swap(int i, int j) {
		int tmp = this->vec.at(i);
		this->vec.at(i) = this->vec.at(j);
		this->vec.at(j) = tmp;
	}
	
	int parentIndex(int index) {
		int parentIndex = (index - 1) / 2;
		return parentIndex >= 0 ? parentIndex : -1;
	}
	int childIndex(int index, int child) {
		// child = 1 or 2
		int childIndex = index * 2 + child;
		return childIndex < this->vec.size() ? childIndex : -1;
	}
	void siftdown(int index, int end) {
		while (index <= end && 0 <= index) {
			int childOneIndex = childIndex(index, 1);
			int childTwoIndex = childIndex(index, 2);
			int currentValue = this->vec.at(index);
			int toSwapIndex = -1;
			int childOneValue = 0;
			int childTwoValue = 0;
			if (-1 != childTwoIndex) {
				childOneValue = this->vec.at(childOneIndex);
				childTwoValue = this->vec.at(childTwoIndex);
				toSwapIndex = (childOneValue > childTwoValue) ? childOneIndex : childTwoIndex;
			}
			else {toSwapIndex = childOneIndex;}
			if (-1 != toSwapIndex) {
				if (this->vec.at(toSwapIndex) > currentValue) {
					swap(toSwapIndex, index);
				}
			}
			index = toSwapIndex;
		}
	}
	void siftup(int index) {
		while (index > 0) {
			int pIndex = parentIndex(index);
			if (-1 != pIndex) {
				int parentValue = this->vec.at(pIndex);
				int currentValue = this->vec.at(index);
				if (currentValue > parentValue) {
					swap(index, pIndex);
				}
				index = pIndex;
			}
			else {break;}
		}
	}
	int remove() {
		swap(0, this->vec.size() - 1);
		int ret = this->vec.back();
		this->vec.pop_back();
		siftdown(0, this->vec.size() - 1);
		return ret;
	}
	
	int length() {
		return this->vec.size();
	}
};

vector<int> heapSort(vector<int> array) {
  // Write your code here.
	int N = array.size();
	vector<int> ans;
	if (1 >= N) {return array;}
	Heap *pheap = new Heap(array);
	int ret = 0;
	while (0 < pheap->length()) {
		ret = pheap->remove();
		ans.insert(ans.begin(), ret);
	}
  return ans;
}
