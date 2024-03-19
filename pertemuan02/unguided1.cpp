//Satrio Wibowo
//2311102149

#include<iostream>
using namespace std;

int main(){

    int arr_149[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Deklarasi isi array
    int length = sizeof(arr_149) / sizeof(arr_149[0]); //Menghitiung ukuran array

    cout << "Data Array: ";
    //Perulangan for untuk mencetak data array
    for (int i = 0; i < length; ++i){
        cout << arr_149[i] << " ";
    }
    cout << endl;
    //Mencetak angka genap
    cout<<"Nomor Genap: ";
    //Perulangan for untuk mencetak  nomor genap dari array
    for(int j=0;j<length;j++){
        //Percabangan if untuk menentukan kondisi jika angka yang ada pada data array merupakan angka genap
        if(arr_149[j]%2==0){
            cout<<arr_149[j]<<", ";
        }
    }
    cout<<endl;
    //Mencetak angka ganjil
    cout<<"Nomor Ganjil: ";
    //Perulangan for untuk mencetak  nomor genap dari array
    for(int i=0;i<length;i++){
         //Percabangan if untuk menentukan kondisi jika angka yang ada pada data array merupakan angka ganjil
        if(arr_149[i]%2 !=0){
            cout<<arr_149[i]<<", ";
        }
    }
    return 0;
}