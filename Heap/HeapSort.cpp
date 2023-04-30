#include <iostream>
#include <vector>

typedef std::vector<int> vector;

void Max_Heapfy(vector& H, int size, int i) {
	int st = 2 * i + 1;
	int dr = 2 * i + 2;
	int imax = i;
	if (st<size && H[st]>H[imax])
		imax = st;
	if (dr<size && H[dr]>H[imax])
		imax = dr;
	if (imax != i) {
		std::swap(H[i], H[imax]);
		Max_Heapfy(H, size, imax);
	}
}

void Build_Max_Heap(vector& H) {
	int size = H.size();
	for (int i = size / 2 - 1; i >= 0; i--)
		Max_Heapfy(H, size, i);
}

void HeapSort(vector& H) {

	Build_Max_Heap(H);
	int n = H.size();
	for (int i = n - 1; i >= 1; i--) {
		std::swap(H[i], H[0]);
		n--;
		Max_Heapfy(H, n, 0);
	}
}

int main() {
	vector v = { 3,11,2,0,1,7,8,4,6,9,5 };
	HeapSort(v);
	for (int i : v)
		std::cout << i << " ";
	return 0;
}
