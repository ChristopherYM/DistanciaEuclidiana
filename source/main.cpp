#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;

void euclidiana(int n, int tamvec) {
	unsigned t0, t1;
	double time0;

	int result;
	int** t;
	t = new int*[tamvec];

	for (int j = 0; j < tamvec; j++)
		t[j] = new int[n];

	srand(time(NULL));
	for (int i = 0; i < tamvec; ++i) {
		for (int j = 0; j < n; ++j) {
			int r = rand() % 1000;
			t[i][j] = r;
		}
	}

	t0 = clock();
	for (int e = 0; e < tamvec; e++) {
		for (int i = 1; i < tamvec; ++i) {
			result = 0;
			for (int j = 0; j < n; ++j) {
				result += pow(t[i][j] - t[e][j], 2);
			}
			result = sqrt(result);
		}
	}
	t1 = clock();

	time0 = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "tamano: " << tamvec << " dimension: " << n << " tiempo: " << time0 << endl;
}

int main()
{
	for (int i = 10000; i <= 25000; i = i + 5000) {
		euclidiana(20, i);
	}
	return 0;
}