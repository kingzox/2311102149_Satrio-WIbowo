  # <h1 align="center">Laporan Praktikum Modul 9 - GRAPH DAN TREE</h1>
<p align="center">Satrio Wibowo - 2311102149</p>


## Dasar Teori

### GRAPH
 #### A. Pengertian dan Fungsi Graph
Graf, dalam konteks struktur data, adalah representasi visual yang menunjukkan hubungan antara objek-objek tertentu. Secara formal, graf dinyatakan sebagai pasangan terurut \( G = (V, E) \), di mana \( G \) adalah graf, \( V \) adalah himpunan simpul (vertex), dan \( E \) adalah himpunan sisi (edge) yang menghubungkan simpul-simpul tersebut. Dalam graf, simpul-simpul merepresentasikan objek atau entitas, sedangkan sisi-sisi menggambarkan hubungan antara simpul-simpul tersebut. Graf digunakan untuk memodelkan berbagai situasi di berbagai bidang seperti jaringan komputer, rute transportasi, relasi sosial, dan lain-lain.

Dalam representasi graf, simpul-simpul sering digambarkan sebagai titik atau lingkaran, sementara sisi-sisi diwakili oleh garis atau panah yang menghubungkan simpul-simpul tersebut. Sisi-sisi ini bisa memiliki arah (disebut graf berarah) atau tidak (disebut graf tidak berarah), dan mungkin juga memiliki bobot atau atribut tambahan yang memberikan informasi lebih lanjut tentang hubungan antara simpul-simpul. Graf dapat bersifat acyclic (tanpa siklus) atau cyclic (dengan siklus). Graf acyclic tidak memiliki siklus atau jalur tertutup di mana simpul yang sama dilewati lebih dari sekali, sedangkan graf cyclic memiliki setidaknya satu siklus. Dalam praktiknya, graf digunakan untuk menganalisis dan memodelkan berbagai masalah. Berbagai algoritma telah dikembangkan untuk mengelola dan memanipulasi graf, seperti algoritma pencarian jalan terpendek, algoritma alur maksimal, dan banyak lagi.

![grpah](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/33abd700-e9d3-4ec7-9a5e-794c1e399481) </br>

#### Jenis jenis Graph
- Graf Berarah (Directed Graph) adalah jenis graf di mana setiap sisi memiliki arah tertentu, menunjukkan orientasi dari satu simpul ke simpul lainnya. Dalam graf ini, pergerakan atau perjalanan hanya bisa dilakukan dalam arah yang telah ditentukan.
- Graf Tidak Berarah (Undirected Graph) adalah graf di mana setiap sisi tidak memiliki arah spesifik, sehingga pergerakan dapat dilakukan bolak-balik antara dua simpul. Misalnya, jaringan jalan raya memungkinkan perjalanan dua arah antara dua kota.
- Graf Berbobot (Weighted Graph) adalah graf di mana setiap sisi memiliki nilai numerik yang disebut bobot atau weight, yang menunjukkan biaya, jarak, atau atribut lain dari hubungan antara dua simpul yang terhubung oleh sisi tersebut. Graf ini berguna untuk memodelkan situasi di mana hubungan antara simpul memiliki nilai yang berbeda-beda, seperti biaya perjalanan antara kota-kota dalam jaringan transportasi.

#### Representasi Graph
Representasi graf adalah cara untuk menggambarkan struktur dan hubungan antara simpul-simpul (vertex) dan sisi-sisi (edge) dalam sebuah graf. Ada beberapa metode umum untuk merepresentasikan graf dalam struktur data, di antaranya:

1. **Matriks Ketetanggaan (Adjacency Matrix):**
   Matriks ketetanggaan adalah matriks 2D yang digunakan untuk merepresentasikan graf. Jika terdapat \( n \) simpul, maka matriks ini berukuran \( n \times n \). Elemen matriks \( A[i][j] \) adalah 1 (atau bobotnya jika graf berbobot) jika terdapat sisi dari simpul \( i \) ke simpul \( j \), dan 0 jika tidak ada sisi.

   Contoh untuk graf tidak berarah:
   ```
     A B C
   A 0 1 0
   B 1 0 1
   C 0 1 0
   ```

2. **Daftar Ketetanggaan (Adjacency List):**
   Daftar ketetanggaan adalah array dari daftar yang digunakan untuk merepresentasikan graf. Setiap simpul memiliki daftar terhubung yang berisi semua simpul tetangga yang terhubung dengannya. Ini lebih efisien dalam penggunaan memori untuk graf yang jarang (sparse graph).

   Contoh:
   ```
   A: B
   B: A, C
   C: B
   ```

3. **Matriks Insiden (Incidence Matrix):**
   Matriks insiden adalah matriks 2D yang digunakan untuk merepresentasikan graf. Jika terdapat \( n \) simpul dan \( m \) sisi, maka matriks ini berukuran \( n \times m \). Elemen matriks \( I[i][j] \) adalah 1 jika simpul \( i \) terhubung dengan sisi \( j \), dan 0 jika tidak.

   Contoh untuk graf tidak berarah dengan sisi \{e1, e2, e3\}:
   ```
     e1 e2 e3
   A  1  0  1
   B  1  1  0
   C  0  1  1
   ```

4. **Representasi Tepi (Edge List):**
   Representasi tepi adalah daftar yang digunakan untuk menyimpan semua sisi dari sebuah graf. Setiap elemen dalam daftar adalah pasangan (atau tripel untuk graf berbobot) yang menunjukkan simpul yang terhubung oleh sisi tersebut.

   Contoh:
   ```
   (A, B)
   (B, C)
   (A, C)
   ```

### TREE
Pohon adalah struktur data hierarkis yang terdiri dari simpul-simpul yang terhubung dalam pola terbatas dan tidak membentuk siklus. Pohon terdiri dari simpul-simpul yang memiliki dua bagian utama: simpul akar (root node) dan simpul-simpul anak (child nodes). Simpul akar adalah simpul paling atas yang tidak memiliki simpul induk (parent node), sementara simpul-simpul anak adalah simpul-simpul di bawah simpul akar yang terhubung langsung dengannya. Karakteristik lain dari pohon adalah setiap simpul anak hanya memiliki satu simpul induk, berbeda dengan graf biasa di mana simpul dapat memiliki beberapa simpul induk. Oleh karena itu, setiap simpul dalam pohon memiliki hubungan induk-anak yang jelas.

Pohon sering digunakan untuk merepresentasikan data hierarkis, seperti struktur file dalam sistem operasi, struktur direktori di komputer, struktur organisasi dalam bisnis, dan struktur hierarki dalam bahasa pemrograman seperti pohon ekspresi dalam pemrosesan bahasa aljabar. Selain itu, pohon juga banyak digunakan dalam algoritma dan struktur data, seperti pohon pencarian biner (binary search tree), pohon merah-hitam (red-black tree), dan pohon B (B-tree), yang digunakan dalam berbagai aplikasi seperti pengurutan dan pencarian data, manajemen basis data, dan lainnya. Pemahaman tentang konsep pohon sangat penting dalam pemrograman dan pengembangan perangkat lunak karena memungkinkan pengorganisasian data secara hierarkis dan efisien serta menyediakan dasar untuk berbagai algoritma dan struktur data yang kompleks.



## Guided

### 1. Guided I Program Graph

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekai", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur [7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph(){
    for( int baris=0; baris<7; baris++){
        cout<<" "<<setiosflags(ios::left)<<setw(15)<<simpul[baris]<<" : ";
        for (int kolom=0; kolom<7; kolom++){
            if (busur[baris][kolom] !=0){
                cout<<" "<<simpul[kolom]<<" ("<<busur[baris][kolom]<<" )";
            }

        }cout<<endl;
    }  
}

int main(){
    tampilGraph();
    return 0;
}

```
Program ini menampilkan graf berarah yang terdiri dari 7 simpul dan 12 busur, menggunakan array 2 dimensi sebagai representasi graf. Terdapat fungsi tampilGraph() yang bertugas menampilkan graf ini. Array simpul menyimpan nama-nama simpul, sementara array busur menyimpan bobot antara simpul-simpul tersebut. Dengan menggunakan fungsi tampilGraph(), graf berarah yang terdiri dari 7 simpul dan 12 busur akan ditampilkan. Fungsi tampilGraph() menggunakan perulangan for untuk melakukan hal ini. Pada fungsi main(), kita memanggil tampilGraph() untuk menampilkan graf.


### 2. Program Tree
```C++
#include <iostream>

using namespace std;

// Program Binary Tree

// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;

// Inisialisasi
void init()
{
    root = NULL;
}

// Cek Node
int isEmpty()
{
    if (root == NULL)
        return 1; // true
    else
        return 0; // false
}

void buatNode(char data)
{
    if (isEmpty() == 1)
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\n Pohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kiri ada atau tidak
        if (node->left != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}
// Tambah Kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (root == NULL)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kanan ada atau tidak
        if (node->right != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}
// Ubah Data Tree
void update(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
// Lihat Isi Data Tree
void retrieve(Pohon *node)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
// Cari Data Tree
void find(Pohon *node)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// Hapus Tree
void clear()
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node = root)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void charateristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}
int main()
{
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);

    retrieve(nodeC);

    find(nodeC);

    cout << "\n"
         << endl;
    charateristic();

    cout << "\n PreOrder :" << endl;
    preOrder(root);

    cout << "\n"
         << endl;
    cout << " InOrder :" << endl;
    inOrder(root);

    cout << "\n"
         << endl;
    cout << " PostOrder :" << endl;
    postOrder(root);
}

```

Program ini mengimplementasikan struktur data tree menggunakan bahasa C++. Program ini mencakup berbagai fungsi, seperti fungsi buatNode untuk membuat node baru, fungsi insertLeft dan insertRight untuk menambahkan node baru pada child kiri dan kanan, serta fungsi update untuk mengubah data pada node. Ada juga fungsi retrieve untuk mengambil data dari node, fungsi find untuk mencari data node, dan fungsi preOrder, inOrder, serta postOrder untuk melakukan penelusuran pada tree. Selain itu, ada fungsi deleteTree untuk menghapus seluruh tree, fungsi deleteSub untuk menghapus subtree, fungsi clear untuk menghapus tree, fungsi size untuk memeriksa ukuran tree, fungsi height untuk memeriksa tinggi tree, dan fungsi characteristic untuk memeriksa karakteristik tree. Pada fungsi main, semua fungsi ini dipanggil sesuai dengan kebutuhan program.
    
## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya. Output Program : </br>

![soal unguided1](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/5d9ac0b0-0a67-4a69-9b0b-b43033ac142f)




```C++

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int jumlahSimpul_2311102149;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul_2311102149;

    vector<string> namaSimpul(jumlahSimpul_2311102149);
    vector<vector<int>> matriksBobot(jumlahSimpul_2311102149, vector<int>(jumlahSimpul_2311102149));

    // Input nama-nama simpul
    for (int i = 0; i < jumlahSimpul_2311102149; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> namaSimpul[i];
    }

    // Input bobot antar simpul, termasuk bobot dari kota ke kota itu sendiri
    for (int i = 0; i < jumlahSimpul_2311102149; ++i) {
        for (int j = 0; j < jumlahSimpul_2311102149; ++j) {
            cout << namaSimpul[i] << "--> " << namaSimpul[j] << " = ";
            cin >> matriksBobot[i][j];
        }
    }

    // Cetak header matriks
    cout << "\n\t";
    for (int i = 0; i < jumlahSimpul_2311102149; ++i) {
        cout << namaSimpul[i] << "\t";
    }
    cout << endl;

    // Cetak baris dan kolom matriks
    for (int i = 0; i < jumlahSimpul_2311102149; ++i) {
        cout << namaSimpul[i] << "\t";
        for (int j = 0; j < jumlahSimpul_2311102149; ++j) {
            cout << matriksBobot[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

```
#### Output :

![unguided1 modul9 - satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/5589a9c9-a9ca-46ca-b0d3-1f3da319b366)

Program di atas adalah program dalam bahasa C++ yang digunakan untuk menginput dan menampilkan matriks bobot dari sebuah graf yang tidak berarah. Program ini dimulai dengan meminta user untuk memasukkan jumlah simpul (nodes) yang ingin dimasukkan ke dalam graf, saya memasukkan 2 jumlah simpul untuk masing masing dari run code- nya. Setelah itu, user diminta untuk memasukkan nama-nama setiap simpul, saya memberi nama BALI - PALU dan PURWOKERTO - SEMARANG. Selanjutnya, program meminta user untuk menginput bobot antara setiap pasangan simpul, termasuk bobot dari simpul ke dirinya sendiri. Untuk BALI - PALU memiliki bobot 3 dan PALU - BALI 4, untuk SEMARANG - PURWOKERTO memiliki bobot 5 dan PURWOKERTO - SEMARANG 4. Untuk bobot dari simpul ke simpul itu sendiri yaitu 0. Matriks bobot yang dihasilkan kemudian ditampilkan dalam bentuk tabel, dengan baris dan kolom yang diberi label menggunakan nama-nama simpul yang telah diinput. Program menggunakan beberapa fitur dasar dari bahasa C++, seperti iostream untuk input dan output, serta vector dari STL untuk menyimpan nama-nama simpul dan matriks bobotnya. 


### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++

 
#include <iostream>

using namespace std;

// Struct Declaration for Binary Tree
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

// Global Variables
Pohon *root, *baru;

// Function Declarations
void init();
int isEmpty();
void buatNode(char data);
Pohon* insertLeft(char data, Pohon *node_2311102149);
Pohon* insertRight(char data, Pohon *node_2311102149);
void update(char data, Pohon *node_2311102149);
void retrieve(Pohon *node_2311102149);
void find(Pohon *node_2311102149);
void preOrder(Pohon *node_2311102149 = root);
void inOrder(Pohon *node_2311102149 = root);
void postOrder(Pohon *node_2311102149 = root);
void deleteTree(Pohon *node_2311102149);
void deleteSub(Pohon *node_2311102149);
void clear();
int size(Pohon *node_2311102149 = root);
int height(Pohon *node_2311102149 = root);
void characteristic();
void showChildren(Pohon *node_2311102149);
void showDescendants(Pohon *node_2311102149);
Pohon* findNode(Pohon *node_2311102149, char data);

int main() {
    int pilihan;
    char data;
    Pohon *node_2311102149 = NULL;

    do {
        cout << "\nMenu:";
        cout << "\n1. Buat Root";
        cout << "\n2. Tambah Node Kiri";
        cout << "\n3. Tambah Node Kanan";
        cout << "\n4. Ubah Data Node";
        cout << "\n5. Lihat Data Node";
        cout << "\n6. Cari Data Node";
        cout << "\n7. Hapus Tree";
        cout << "\n8. Lihat Karakteristik Tree";
        cout << "\n9. Tampilkan Child dari Node";
        cout << "\n10. Tampilkan Descendant dari Node";
        cout << "\n11. PreOrder Traversal";
        cout << "\n12. InOrder Traversal";
        cout << "\n13. PostOrder Traversal";
        cout << "\n14. Keluar";
        cout << "\nPilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan data root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2: {
                cout << "\nMasukkan data node: ";
                cin >> data;
                cout << "\nMasukkan data parent: ";
                char parentData;
                cin >> parentData;
                node_2311102149 = findNode(root, parentData);
                if (node_2311102149) insertLeft(data, node_2311102149);
                break;
            }
            case 3: {
                cout << "\nMasukkan data node: ";
                cin >> data;
                cout << "\nMasukkan data parent: ";
                char parentData;
                cin >> parentData;
                node_2311102149 = findNode(root, parentData);
                if (node_2311102149) insertRight(data, node_2311102149);
                break;
            }
            case 4: {
                cout << "\nMasukkan data baru: ";
                cin >> data;
                cout << "\nMasukkan data node yang ingin diubah: ";
                char parentData;
                cin >> parentData;
                node_2311102149 = findNode(root, parentData);
                if (node_2311102149) update(data, node_2311102149);
                break;
            }
            case 5: {
                cout << "\nMasukkan data node yang ingin dilihat: ";
                char parentData;
                cin >> parentData;
                node_2311102149 = findNode(root, parentData);
                if (node_2311102149) retrieve(node_2311102149);
                break;
            }
            case 6: {
                cout << "\nMasukkan data node yang ingin dicari: ";
                char parentData;
                cin >> parentData;
                node_2311102149 = findNode(root, parentData);
                if (node_2311102149) find(node_2311102149);
                break;
            }
            case 7:
                clear();
                break;
            case 8:
                characteristic();
                break;
            case 9: {
                cout << "\nMasukkan data node: ";
                char parentData;
                cin >> parentData;
                node_2311102149 = findNode(root, parentData);
                if (node_2311102149) showChildren(node_2311102149);
                break;
            }
            case 10: {
                cout << "\nMasukkan data node: ";
                char parentData;
                cin >> parentData;
                node_2311102149 = findNode(root, parentData);
                if (node_2311102149) showDescendants(node_2311102149);
                break;
            }
            case 11:
                cout << "\nPreOrder Traversal: " << endl;
                preOrder(root);
                cout << "\n";
                break;
            case 12:
                cout << "\nInOrder Traversal: " << endl;
                inOrder(root);
                cout << "\n";
                break;
            case 13:
                cout << "\nPostOrder Traversal: " << endl;
                postOrder(root);
                cout << "\n";
                break;
            case 14:
                cout << "\nKeluar dari program." << endl;
                break;
            default:
                cout << "\nPilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 14);

    return 0;
}

void init() {
    root = NULL;
}

int isEmpty() {
    return root == NULL ? 1 : 0;
}

void buatNode(char data) {
    if (isEmpty() == 1) {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon* insertLeft(char data, Pohon *node_2311102149) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node_2311102149->left != NULL) {
            cout << "\nNode " << node_2311102149->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node_2311102149;
            node_2311102149->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon* insertRight(char data, Pohon *node_2311102149) {
    if (root == NULL) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node_2311102149->right != NULL) {
            cout << "\nNode " << node_2311102149->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node_2311102149;
            node_2311102149->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node_2311102149) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node_2311102149)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node_2311102149->data;
            node_2311102149->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node_2311102149) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node_2311102149)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node: " << node_2311102149->data << endl;
        }
    }
}

void find(Pohon *node_2311102149) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node_2311102149)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nNode: " << node_2311102149->data << endl;
            if (!node_2311102149->left)
                cout << "Child Kiri: (tidak punya child kiri)" << endl;
            else
                cout << "Child Kiri: " << node_2311102149->left->data << endl;
            if (!node_2311102149->right)
                cout << "Child Kanan: (tidak punya child kanan)" << endl;
            else
                cout << "Child Kanan: " << node_2311102149->right->data << endl;
        }
    }
}

void preOrder(Pohon *node_2311102149) {
    if (isEmpty() == 1)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node_2311102149 != NULL) {
            cout << " " << node_2311102149->data << ", ";
            preOrder(node_2311102149->left);
            preOrder(node_2311102149->right);
        }
    }
}

void inOrder(Pohon *node_2311102149) {
    if (isEmpty() == 1)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node_2311102149 != NULL) {
            inOrder(node_2311102149->left);
            cout << " " << node_2311102149->data << ", ";
            inOrder(node_2311102149->right);
        }
    }
}

void postOrder(Pohon *node_2311102149) {
    if (isEmpty() == 1)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node_2311102149 != NULL) {
            postOrder(node_2311102149->left);
            postOrder(node_2311102149->right);
            cout << " " << node_2311102149->data << ", ";
        }
    }
}

void deleteTree(Pohon *node_2311102149) {
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node_2311102149 != NULL) {
            if (node_2311102149 != root) {
                if (node_2311102149->parent->left == node_2311102149)
                    node_2311102149->parent->left = NULL;
                else
                    node_2311102149->parent->right = NULL;
            }
            deleteTree(node_2311102149->left);
            deleteTree(node_2311102149->right);
            if (node_2311102149 == root) {
                delete root;
                root = NULL;
            } else {
                delete node_2311102149;
            }
        }
    }
}

void deleteSub(Pohon *node_2311102149) {
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node_2311102149->left);
        deleteTree(node_2311102149->right);
        cout << "\nNode subtree " << node_2311102149->data << " berhasil dihapus." << endl;
    }
}

void clear() {
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

int size(Pohon *node_2311102149) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node_2311102149) {
            return 0;
        } else {
            return 1 + size(node_2311102149->left) + size(node_2311102149->right);
        }
    }
}

int height(Pohon *node_2311102149) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node_2311102149) {
            return 0;
        } else {
            int heightKiri = height(node_2311102149->left);
            int heightKanan = height(node_2311102149->right);
            return (heightKiri >= heightKanan) ? heightKiri + 1 : heightKanan + 1;
        }
    }
}

void characteristic() {
    cout << "\nSize Tree: " << size() << endl;
    cout << "Height Tree: " << height() << endl;
    cout << "Average Node of Tree: " << size() / height() << endl;
}

void showChildren(Pohon *node_2311102149) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node_2311102149) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nNode: " << node_2311102149->data << endl;
    if (node_2311102149->left)
        cout << "Child Kiri: " << node_2311102149->left->data << endl;
    else
        cout << "Child Kiri: (tidak punya child kiri)" << endl;

    if (node_2311102149->right)
        cout << "Child Kanan: " << node_2311102149->right->data << endl;
    else
        cout << "Child Kanan: (tidak punya child kanan)" << endl;
}

void showDescendants(Pohon *node_2311102149) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node_2311102149) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nDescendants of node " << node_2311102149->data << ": ";
    preOrder(node_2311102149);
    cout << endl;
}

Pohon* findNode(Pohon *node_2311102149, char data) {
    if (!node_2311102149)
        return NULL;
    if (node_2311102149->data == data)
        return node_2311102149;
    Pohon *foundNode = findNode(node_2311102149->left, data);
    if (!foundNode)
        foundNode = findNode(node_2311102149->right, data);
    return foundNode;
}


```

### Output


![unguided2 1 modul 9 -Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/a1d4325f-bd1f-40d6-acd1-6088d5a6c1d6) </br>

![unguided2 2 modul 9 -Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/a3a48629-7cd0-4950-aa55-46579cf3e9ad) </br>

![unguided2 3 modul9 -Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/46e94d8b-526d-4d47-ab1f-134cb36b3da3) </br>

![unguided2 4 modul 9 -Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/ebb323a5-8c0b-4936-8aa1-6dcf0004b97f) </br>

![unguided2 5 modul 9 -Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/672042ee-7b3d-4124-bc7e-e2c0c414f400) </br>

![unguided2 6 modul 9 -Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/7594584a-79aa-40bc-b76c-9f336dbb1b50) <br>

![unguided2 7 modul 9 -Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/e1804129-2b21-4fe5-a030-c0ed206acc05) </br>

![unguided2 8 modul 9 -Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/480b3eff-3849-4d29-9236-0441a2a0ded1) </br>

![unguided2 9 modul 9 -Satrio](https://github.com/kingzox/2311102149_Satrio-WIbowo/assets/151898942/83d132f5-0bf0-430e-8c60-05a4dc23071e) </br>



Program di atas adalah implementasi sederhana dari sebuah pohon biner (binary tree) menggunakan bahasa C++. Pohon biner tersebut diimplementasikan menggunakan struct bernama Pohon yang memiliki atribut untuk menyimpan data, serta pointer ke anak kiri, anak kanan, dan orang tua (parent). Program ini juga memiliki beberapa fungsi untuk menginisialisasi pohon, memeriksa apakah pohon kosong, membuat node, menambah node di kiri atau kanan, mengubah data node, menampilkan data node, mencari node, menghapus pohon, menghitung ukuran dan tinggi pohon, serta menampilkan karakteristik pohon seperti ukuran dan tinggi.

Dalam main(), program menampilkan menu untuk pengguna dengan berbagai opsi seperti membuat root, menambah node kiri atau kanan, mengubah data node, melihat data node, mencari node, menghapus pohon, melihat karakteristik pohon, menampilkan anak-anak node, menampilkan keturunan node, dan melakukan traversal pohon (preorder, inorder, dan postorder). Pengguna dapat memilih opsi dengan memasukkan pilihan yang sesuai dan mengikuti instruksi yang diberikan.

Fungsi-fungsi utama meliputi:

- init(): Menginisialisasi pohon dengan mengatur root menjadi NULL.
- isEmpty(): Memeriksa apakah pohon kosong.
- buatNode(char data): Membuat node root jika pohon belum dibuat.
- insertLeft(char data, Pohon *node): Menambah node di anak kiri dari node yang ditentukan.
- insertRight(char data, Pohon *node): Menambah node di anak kanan dari node yang ditentukan.
- update(char data, Pohon *node): Mengubah data dari node yang ditentukan.
- retrieve(Pohon *node): Menampilkan data dari node yang ditentukan.
- find(Pohon *node): Mencari node berdasarkan data dan menampilkan informasi tentang node tersebut.
- preOrder(Pohon *node), inOrder(Pohon *node), postOrder(Pohon *node): Melakukan traversal preorder, inorder, dan postorder.
- deleteTree(Pohon *node): Menghapus seluruh pohon atau sub-pohon dari node yang ditentukan.
- clear(): Menghapus seluruh pohon.
- size(Pohon *node): Menghitung jumlah node dalam pohon.
- height(Pohon *node): Menghitung tinggi pohon.
- characteristic(): Menampilkan karakteristik pohon.
- showChildren(Pohon *node): Menampilkan anak-anak dari node yang ditentukan.
- showDescendants(Pohon *node): Menampilkan keturunan dari node yang ditentukan.
- findNode(Pohon *node, char data): Mencari node berdasarkan data dan mengembalikan pointer ke node tersebut.






## Kesimpulan

Dari praktikum yang telah dilakukan, dapat ditarik kesimpulan bahwa Tree dan graph merupakan struktur data penting yang mendalam dalam pengembangan perangkat lunak dan pemrosesan informasi. Tree menyediakan kerangka kerja hierarkis untuk mengorganisir data secara efisien, memungkinkan representasi hubungan induk-anak yang jelas antara elemen-elemen data. Graph, di sisi lain, menawarkan representasi umum dari hubungan antar objek melalui node dan edge, menggambarkan berbagai situasi seperti jaringan komputer, rute transportasi, dan relasi sosial.

Pemahaman tentang operasi dasar seperti penyisipan, penghapusan, dan penelusuran, serta jenis penelusuran seperti inorder, postorder, dan preorder, memungkinkan pengembang untuk mengimplementasikan dan memanipulasi tree dan graph dengan efektif. Dalam pengembangan perangkat lunak, pengetahuan ini kunci untuk merancang algoritma efisien dan mengatasi tantangan pemrosesan data. Representasi graf dengan matriks dan linked list, serta operasi dasar pada tree, membantu pengembang menyelesaikan masalah kompleks dan membangun solusi efisien.

Dengan pemahaman mendalam tentang tree dan graph, pengembang dapat menciptakan solusi inovatif dan terukur untuk berbagai aplikasi, mulai dari analisis jaringan hingga algoritma pencarian dan pengurutan data. Konsep-konsep ini memberikan fondasi yang kuat untuk menjelajahi berbagai aplikasi dalam pemrosesan informasi modern.

## Referensi
[1] Anita Sindar RMS, ST., M.TI., STRUKTUR DATA DAN ALGORITMA DENGAN C++. Serang: CV. AA. RIZKY, 2020. <br/>
[2] Asisten Praktikum. Modul 9 Grpah dan Tree. Purwokerto: Institut Teknologi Purwokerto. 2024. <br/>
[3] Malik, D.S., C++ Programming. Boston: Course Technology, 2023.




