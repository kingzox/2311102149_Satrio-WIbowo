//-- Satrio Wibowo--
//-- 2311102149

//Contoh program menggunakan map

#include<iostream>
#include<map> //std library yang digunakan agar bisa menggunakan fungsi map
using namespace std;

void cars_list(){ //Fungsi carlist berisi deklarasi map dengan key int dan value string
    map<int,string> garage_2149;
    garage_2149[1] = "Nissan Skyline R34 GT-R       => $100.000";
    garage_2149[2] = "Mazda RX-7 Veilside           => $85.000";
    garage_2149[3] = "Dodge Charger 22'             => $18.500";
    garage_2149[4] = "Honda Civic Type R 00'        => $11.100";
    garage_2149[5] = "Toyota Supra Mk4              => $100.000";


    //Looping untuk menampilkan data dari garage_2149
    for(int i=1; i<=garage_2149.size(); i++){
        cout<<i<<". "<<garage_2149[i]<<endl;
    }

};


int main(){

int choice_2149; //Data primitif int untuk mengisi pilihan menu
do{ //Looping untuk menjalankan program daftar SATRIO GARAGE
cout<<endl;
cout<<"-----------------------------------\n";
cout<<"          SATRIO GARAGE            \n";
cout<<"-----------------------------------\n";
cout<<endl;

cars_list(); //Pemanggilan fungsi cars_list
cout<<"6. Exit";
cout<<endl;
cout<<"Please choose one car to buy: "; cin>>choice_2149;
cout<<endl;
switch(choice_2149){

case 1:
    cout<<"You choose Nissan Skyline R34 GT-R with price $100.000"; //Menampilkan case 1 jika user memilih 1
    break;
case 2:
    cout<<"You choose Mazda RX-7 Veilside with price $85.000"; //Menampilkan case 2 jika user memilih 2
    break;
case 3:
    cout<<"You choose Dodge Charger 22' with price $18.500"; //Menampilkan case 3 jika user memilih 3
    break;
case 4:
    cout<<"You choose Honda Civic Type R 00' with price $11.100"; //Menampilkan case 4 jika user memilih 4
    break;
case 5:
     cout<<"You choose Toyota Supra Mk4 with price $100.000"; //Menampilkan case 5 jika user memilih 5
    break;
case 6:
    cout<<"Thank You for coming to SATRIO GARAGE!";
    break;
default:
 cout<<"You Choose wrong choice, input again!"<<endl; //Menampilkan default jika user memilih bukan di antara case 1 - case 5
 break;
}}while(choice_2149<5); //Program akan berhenti ketika user menginputkan nila <5

return 0;
}