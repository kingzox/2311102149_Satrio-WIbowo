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
Pohon* insertLeft(char data, Pohon *node);
Pohon* insertRight(char data, Pohon *node);
void update(char data, Pohon *node);
void retrieve(Pohon *node);
void find(Pohon *node);
void preOrder(Pohon *node = root);
void inOrder(Pohon *node = root);
void postOrder(Pohon *node = root);
void deleteTree(Pohon *node);
void deleteSub(Pohon *node);
void clear();
int size(Pohon *node = root);
int height(Pohon *node = root);
void characteristic();
void showChildren(Pohon *node);
void showDescendants(Pohon *node);
Pohon* findNode(Pohon *node, char data);

int main() {
    int pilihan;
    char data;
    Pohon *node = NULL;

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
                node = findNode(root, parentData);
                if (node) insertLeft(data, node);
                break;
            }
            case 3: {
                cout << "\nMasukkan data node: ";
                cin >> data;
                cout << "\nMasukkan data parent: ";
                char parentData;
                cin >> parentData;
                node = findNode(root, parentData);
                if (node) insertRight(data, node);
                break;
            }
            case 4: {
                cout << "\nMasukkan data baru: ";
                cin >> data;
                cout << "\nMasukkan data node yang ingin diubah: ";
                char parentData;
                cin >> parentData;
                node = findNode(root, parentData);
                if (node) update(data, node);
                break;
            }
            case 5: {
                cout << "\nMasukkan data node yang ingin dilihat: ";
                char parentData;
                cin >> parentData;
                node = findNode(root, parentData);
                if (node) retrieve(node);
                break;
            }
            case 6: {
                cout << "\nMasukkan data node yang ingin dicari: ";
                char parentData;
                cin >> parentData;
                node = findNode(root, parentData);
                if (node) find(node);
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
                node = findNode(root, parentData);
                if (node) showChildren(node);
                break;
            }
            case 10: {
                cout << "\nMasukkan data node: ";
                char parentData;
                cin >> parentData;
                node = findNode(root, parentData);
                if (node) showDescendants(node);
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

Pohon* insertLeft(char data, Pohon *node) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

Pohon* insertRight(char data, Pohon *node) {
    if (root == NULL) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node: " << node->data << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;
            if (!node->parent)
                cout << "Parent: (tidak punya parent)" << endl;
            else
                cout << "Parent: " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling: " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling: " << node->parent->right->data << endl;
            else
                cout << "Sibling: (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri: (tidak punya child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan: (tidak punya child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->right->data << endl;
        }
    }
}

void preOrder(Pohon *node) {
    if (isEmpty() == 1)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

void inOrder(Pohon *node) {
    if (isEmpty() == 1)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

void postOrder(Pohon *node) {
    if (isEmpty() == 1)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

void deleteTree(Pohon *node) {
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

void deleteSub(Pohon *node) {
    if (!root)
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
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

int size(Pohon *node) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

int height(Pohon *node) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            return (heightKiri >= heightKanan) ? heightKiri + 1 : heightKanan + 1;
        }
    }
}

void characteristic() {
    cout << "\nSize Tree: " << size() << endl;
    cout << "Height Tree: " << height() << endl;
    cout << "Average Node of Tree: " << size() / height() << endl;
}

void showChildren(Pohon *node) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nNode: " << node->data << endl;
    if (node->left)
        cout << "Child Kiri: " << node->left->data << endl;
    else
        cout << "Child Kiri: (tidak punya child kiri)" << endl;

    if (node->right)
        cout << "Child Kanan: " << node->right->data << endl;
    else
        cout << "Child Kanan: (tidak punya child kanan)" << endl;
}

void showDescendants(Pohon *node) {
    if (isEmpty() == 1) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nDescendants of node " << node->data << ": ";
    preOrder(node);
    cout << endl;
}

Pohon* findNode(Pohon *node, char data) {
    if (!node)
        return NULL;
    if (node->data == data)
        return node;
    Pohon *foundNode = findNode(node->left, data);
    if (!foundNode)
        foundNode = findNode(node->right, data);
    return foundNode;
}
