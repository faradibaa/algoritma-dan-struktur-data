#include <iostream>
#define MAX_SIZE 5

using namespace std;

int index = 0, outProgram = 0;
string data[MAX_SIZE];
string inputan;

void tambahData() {
	int i = 0;
	while(data[i] != "") {
		i++;
	}
	cout << "Silakan masukkan ID: ";
	cin >> inputan;
	cout << endl;
	data[i] = inputan;
	index++;
}

void hapusData() {
	int hapus;
	cout << "Pilih index data yang akan dihapus: ";
	cin >> hapus;
	data[hapus] = "";
	cout << "Data index ke-" << hapus << " berhasil dihapus." << endl << endl;
}

void printData() {
	char cariData;
	cout << "Masukkan index data yang ingin dicari (ketik 'a' apabila ingin menampilkan semua): ";
	cin >> cariData;
	switch(cariData) {
		case 'a':
			for(int i=0; i<MAX_SIZE; i++) {
				cout << "Data index ke-" << i << " : " << data[i] << endl;
			}
			break;
		case '0' ... char(MAX_SIZE-1+48):
			cout << "Data index ke-" << cariData << " : " << data[int(cariData-48)] << endl;
			break;
		default:
			cout << "ERROR!" << endl;
			break;
	}
	cout << endl;
}

void menu() {
	char pilih;
	cout << "[MENU] 1. Input data | 2. Hapus data | 3. Menampilkan data | 4. Keluar dari program \n";
	cout << "Pilih salah satu: ";
	cin >> pilih;
	cout << endl;
	switch(pilih) {
		case '1':
			tambahData();
			break;
		case '2':
			hapusData();
			break;
		case '3':
			printData();
			break;
		case '4':
			cout << "Program selesai." << endl;
			outProgram = 1;
			break;
		default:
			cout << "Input tidak valid." << endl;
			break;
	}
}

int main() {
	do {
		menu();
	} while(outProgram == 0);
	
	return 0;
}
