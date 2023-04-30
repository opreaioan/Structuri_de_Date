#include <iostream>
#include <vector>

typedef std::vector<int> vector;

void Max_Heapfy(vector& H, int i) {
	int st = 2 * i + 1;
	int dr = 2 * i + 2;
	int imax = i;
	if (st<H.size() && H[st]>H[imax])
		imax = st;
	if (dr<H.size() && H[dr]>H[imax])
		imax = dr;
	if (imax != i) {
		int aux = H[i];
		H[i] = H[imax];
		H[imax] = aux;
		Max_Heapfy(H, imax);
	}
}

void Build_Max_Heap(vector& H) {
	for (int i = H.size(); i >= 0; i--)
		Max_Heapfy(H, i);
}

int main() {
	vector v = { 3,11,2,0,1,7,8,4,6,9,5 };
	Build_Max_Heap(v);
	for (int i : v)
		std::cout << i << " ";
	return 0;
}
