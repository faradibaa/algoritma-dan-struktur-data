#include <iostream>
#define MAX_SIZE 3

using namespace std;

int arr[MAX_SIZE];
int i=0;

void tambah(int angka) {
	arr[i] = angka; //menyimpan data + menampilkan data yang telah disimpan
	cout << "Anda telah menambah angka " << angka << " ke dalam array index ke-" << i << endl;
	i++;
}

int main() {
	tambah(12);
	tambah(2);
	tambah(3);
	
	return 0;
}
