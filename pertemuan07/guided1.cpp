//guided

#include <iostream>
using namespace std;

const int maksimalAntrian = 5;
int front = 0;
int back = 0;
string queueTeller[5];

//mengecek antrian apakah sudah penuh
bool isFull(){
    if(back == maksimalAntrian){
        return true;
    } else {
        return false;
    }
}

//mengecek antrian apakah masih kosong
bool isEmpty(){
    if (back == 0){
        return true;
    } else {
        return false;
    }
}

//menambah antrian
void tambahDAta(string nama){
    if (isFull()){
        cout<<"Antrian sudah penuh\n";
     } else {
        if (isEmpty()){
            queueTeller[0] = nama;
            front++;
            back++;
        } else {
            queueTeller[back] = nama;
            back++;
        }
     }
}

//mengurangi antrian
void kurangAntrian(){
    if (isEmpty()){
        cout<<"Antrian kosong\n";
    } else {
        for ( int i = 0; i < back; i++){
            queueTeller[i] = queueTeller[i+1];
        }
        back --;
    }
}

//memnghitung banyak data antrian
int count(){
    return back;
}

//menghapus seluruh antrian
void clearQueue(){
    if (isEmpty()){
        cout<<"Antrian kosong\n";
    } else {
        for (int i = 0; i < back; i++){
            queueTeller[i] = " ";
        }
        back = 0;
        front = 0;
    }
}

//melihat antrian
void viewQueue(){
    cout<<"Data antrian : \n";
    
    for (int i = 0; i < maksimalAntrian; i++){

        if (queueTeller[i]!= ""){
            cout << i+1 << ". "<<queueTeller[i]<<endl;
        } else {
            cout << i+1 <<". "<<"(kosong)"<<endl;
        }
        
    }
    }

    int main(){
        tambahDAta("Alya");
        tambahDAta("Kiki");
        tambahDAta("Artika");

        viewQueue();

        //memngurangi antrian
        kurangAntrian();
        viewQueue();

        //menghapus seluruh antrian
        clearQueue();
        viewQueue();

        return 0;
    }
