  # <h1 align="center">Laporan Praktikum Modul 9 - GRAPH DAN TREE</h1>
<p align="center">Satrio Wibowo - 2311102149</p>


## Dasar Teori




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




   
## Kesimpulan

Dari praktikum yang telah dilakukan, dapat ditarik kesimpulan bahwa algoritma searching merupakan alat penting dalam ilmu komputer untuk menemukan data dalam kumpulan data. Sequential Search dan Binary Search adalah dua contoh populer dengan kelebihan dan kekurangannya masing-masing. Memahami karakteristik dan kegunaannya memungkinkan pengembang untuk memilih algoritma yang tepat untuk menyelesaikan masalah mereka secara efisien.

## Referensi
[1] Bart J. Van Zeghbroeck, et al., Josephson Sampler Response Using a Binary Search Algorithm, Colorado: IEEE, 2024. <br/>
[2] Asisten Praktikum. Modul 8 Algoritma Searching. Purwokerto: Institut Teknologi Purwokerto. 2024. <br/>
[3] Malik, D.S., C++ Programming. Boston: Course Technology, 2023.




