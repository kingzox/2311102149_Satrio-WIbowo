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
