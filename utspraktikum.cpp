#include <iostream>
#include <string>

using namespace std;

// Deklarasi class Node
class Node {
public:
    string name;
    string phoneNumber;
    Node* prev;
    Node* next;

    // Constructor
    Node(string name, string phoneNumber) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        prev = nullptr;
        next = nullptr;
    }
};

// Deklarasi class DoubleLinkedList
class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
public:
    // Constructor
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Menambah kontak baru ke akhir daftar
    void addContact(string name, string phoneNumber) {
        Node* newNode = new Node(name, phoneNumber);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Kontak berhasil ditambahkan!" << endl;
    }

    // Menampilkan semua kontak
    void displayContacts() {
        if (head == nullptr) {
            cout << "Daftar kontak kosong." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->name << ", Phone: " << current->phoneNumber << endl;
            current = current->next;
        }
    }

    // Menghapus kontak berdasarkan nama
    void deleteContact(string name) {
        Node* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                if (current == head && current == tail) {
                    head = tail = nullptr;
                } else if (current == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Kontak berhasil dihapus!" << endl;
                return;
            }
            current = current->next;
        }
        cout << "Kontak dengan nama " << name << " tidak ditemukan." << endl;
    }
};

int main() {
    DoubleLinkedList contactList;
    int choice;
    string name, phoneNumber;

    do {
        cout << "\nMenu Daftar Kontak:\n";
        cout << "1. Tambahkan Kontak\n";
        cout << "2. Tampilkan Kontak\n";
        cout << "3. Hapus Kontak\n";
        cout << "4. Keluar\n";
        cout << "Masukkan Pillihan Menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, name);
                cout << "Masukkan Nomor HP: ";
                getline(cin, phoneNumber);
                contactList.addContact(name, phoneNumber);
                break;
            case 2:
                cout << "\nKontak yang tersedia:" << endl;
                contactList.displayContacts();
                break;
            case 3:
                cout << "Masukkan nama kontak yang ingin dihapus: ";
                cin.ignore();
                getline(cin, name);
                contactList.deleteContact(name);
                break;
            case 4:
                cout << "Program selesai, terima kasih!" << endl;
                break;
            default:
                cout << "pilihan tidak valid, silahkan coba lagi." << endl;
        }
    } while (choice != 4);

    return 0;
}
