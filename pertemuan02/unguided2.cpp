//Satrio Wibowo
//2311102149

#include <iostream>
using namespace std;

int main() {
    //Variable untuk menyimpan ukuran elemen array tiga dimensi
    int xsize_149, ysize_149, zsize_149;

    // user menginputkan ukuran elemen array tiga dimensi
    cout << "Masukkan ukuran elemen array tiga dimensi x: "; cin>>xsize_149;
    cout << "Masukkan ukuran elemen array tiga dimensi y: "; cin>>ysize_149;
    cout << "Masukkan ukuran elemen array tiga dimensi z: "; cin>>zsize_149;
   
    //Deklarasi array untuk ukuran yang akan dimasukkan user
    int arr[xsize_149][ysize_149][zsize_149];

    // loop untuk mengisi elemen array dengan data yang diinputkan user
    for (int x = 0; x < xsize_149; x++) {
        for (int y = 0; y < ysize_149; y++) {
            for (int z = 0; z < zsize_149; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Perulangan For untuk menampilkan elemen array berserta indeksnya
    for (int x = 0; x < xsize_149; x++) {
        for (int y = 0; y < ysize_149; y++) {
            for (int z = 0; z < zsize_149; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    //Perulangan For untuk menampilkan elemen array dalam format tiga dimensi
    for (int x = 0; x < xsize_149; x++) {
        for (int y = 0; y < ysize_149; y++) {
            for (int z = 0; z < zsize_149; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}