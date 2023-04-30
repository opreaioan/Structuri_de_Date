#include <iostream>
#include <vector>

typedef std::vector<int> vector;

void Min_Heapfy(vector& H, int i) {
	int st = 2 * i + 1;
	int dr = 2 * i + 2;
	int imin = i;
	if (st<H.size() && H[st]<H[imin])
		imin = st;
	if (dr<H.size() && H[dr]<H[imin])
		imin = dr;
	if (imin != i) {
		int aux = H[i];
		H[i] = H[imin];
		H[imin] = aux;
		Min_Heapfy(H, imin);
	}
}

void Build_Min_Heap(vector& H) {
	for (int i = H.size(); i >= 0; i--)
		Min_Heapfy(H, i);
}

int main() {
	vector v = { 3,11,2,0,1,7,8,4,6,9,5 };
	Build_Min_Heap(v);
	for (int i : v)
		std::cout << i << " ";
	return 0;
}
