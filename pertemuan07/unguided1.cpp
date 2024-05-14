#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node_149 {
    string data_149;
    Node_149* next_149;
};

// Class for the linked list-based queue
class Queue_149 {
private:
    Node_149* front_149;
    Node_149* back_149;

public:
    Queue_149() {
        front_149 = nullptr;
        back_149 = nullptr;
    }

    // Check if the queue is empty
    bool isEmpty_149() {
        return front_149 == nullptr;
    }

    // Add a new element to the queue
    void tambahData_149(string nama_149) {
        Node_149* newNode_149 = new Node_149();
        newNode_149->data_149 = nama_149;
        newNode_149->next_149 = nullptr;
        
        if (isEmpty_149()) {
            front_149 = back_149 = newNode_149;
        } else {
            back_149->next_149 = newNode_149;
            back_149 = newNode_149;
        }
    }

    // Remove an element from the queue
    void kurangAntrian_149() {
        if (isEmpty_149()) {
            cout << "Antrian kosong\n";
        } else {
            Node_149* temp_149 = front_149;
            front_149 = front_149->next_149;
            delete temp_149;
            if (front_149 == nullptr) {
                back_149 = nullptr;
            }
        }
    }

    // Count the number of elements in the queue
    int count_149() {
        int count_149 = 0;
        Node_149* temp_149 = front_149;
        while (temp_149 != nullptr) {
            count_149++;
            temp_149 = temp_149->next_149;
        }
        return count_149;
    }

    // Clear the entire queue
    void clearQueue_149() {
        while (!isEmpty_149()) {
            kurangAntrian_149();
        }
    }

    // View the elements in the queue
    void viewQueue_149() {
        cout << "Data antrian: \n";
        Node_149* temp_149 = front_149;
        int index_149 = 1;
        while (temp_149 != nullptr) {
            cout << index_149 << ". " << temp_149->data_149 << endl;
            temp_149 = temp_149->next_149;
            index_149++;
        }
        if (isEmpty_149()) {
            cout << "(kosong)\n";
        }
    }

    ~Queue_149() {
        clearQueue_149();
    }
};

int main() {
    Queue_149 queue_149;

    queue_149.tambahData_149("Alya");
    queue_149.tambahData_149("Kiki");
    queue_149.tambahData_149("Artika");

    queue_149.viewQueue_149();

    // Mengurangi antrian
    queue_149.kurangAntrian_149();
    queue_149.viewQueue_149();

    // Menghapus seluruh antrian
    queue_149.clearQueue_149();
    queue_149.viewQueue_149();

    return 0;
}
