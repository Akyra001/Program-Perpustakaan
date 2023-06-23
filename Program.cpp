#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stack>
#include <iomanip>
#include <vector>

using namespace std;

struct user {
    string nama, id, alamat;
};

vector<user> e;
int total = 0;

typedef struct {
    int top;
    int data[20];
} stacktype;

stacktype A;

void push(int d) {
    if (A.top != 19) {
        A.top++;
        A.data[A.top] = d;
        cout << "Judul " << d << " Ditambahkan\n";
    } else {
        cout << "\nStack Penuh\n";
    }
}

void pop() {
    if (A.top != -1) {
        cout << "POP Data : " << A.data[A.top] << "\n";
        A.top--;
    } else {
        cout << "Stack Kosong\n";
    }
}

void print() {
    if (A.top != -1) {
        for (int i = A.top; i >= 0; i--)
            cout << A.data[i] << "\n";
    } else {
        cout << "Stack Kosong\n";
    }
}

int isEmpty() {
    if (A.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull() {
    if (A.top == 19) {
        return 1;
    } else {
        return 0;
    }
}

void adddata() {
    int choise;
    cout << "Jumlah Data yang Akan Anda Add : ";
    cin >> choise;
    for (int i = 0; i < choise; i++) {
        cout << "=================================\n";
        cout << "Data Ke-" << total + 1 << "\n";
        cout << "=================================\n";
        user newUser;
        cout << "Nama        : ";
        cin >> newUser.nama;
        cout << "ID          : ";
        cin >> newUser.id;
        cout << "Alamat      : ";
        cin >> newUser.alamat;
        e.push_back(newUser);
        total++;
    }
}

void update() {
    if (total != 0) {
        string id;
        cout << "Pilih Data yang akan di Update : ";
        cin >> id;
        for (int i = 0; i < total; i++) {
            if (id == e[i].id) {
                cout << "Data Ke-     : " << i + 1 << "\n";
                cout << "Nama         : " << e[i].nama << "\n";
                cout << "ID           : " << e[i].id << "\n";
                cin >> e[i].nama;
                cout << "ID : ";
                cin >> e[i].id;
                break;
            }
            if (i == total - 1) {
                cout << "Data Kosong\n";
            }
        }
    } else {
        cout << "Data Kosong !!\n";
    }
}

void remove() {
    if (total != 0) {
        char user;
        cout << "\n1. Remove Full\n";
        cout << "\n2. Remove Specific\n";
        cin >> user;
        if (user == '1') {
            total = 0;
            cout << "=================================\n";
            cout << "Data Sudah Terhapus!!\n";
        } else if (user == '2') {
            string id;
            cout << "Enter untuk remove\n";
            cin >> id;
            for (int i = 0; i < total; i++) {
                if (id == e[i].id) {
                    for (int j = i; j < total; j++) {
                        e[j].nama = e[j + 1].nama;
                        e[j].id = e[j + 1].id;
                        e[j].alamat = e[j + 1].alamat;
                    }
                    total--;
                    break;
                }
                if (i == total - 1) {
                    cout << "Tidak ada Data !!\n";
                }
            }
        }
    } else {
        cout << "Data Kosong\n";
    }
}

vector<string> names;
vector<int> prices;
vector<int> quantities;
int totalHarga = 0;

void AntrianMasuk(int no) {
    names.push_back(to_string(no));
    totalHarga += no;
}

void AntrianKeluar() {
    if (names.empty()) {
        cout << "Antrian Kosong!!";
        getch();
    } else {
        names.erase(names.begin());
        totalHarga -= 0;
    }
}

void clear() {
    names.clear();
    totalHarga = 0;
}

void view() {
    if (names.empty()) {
        cout << "Daftar Kosong!!";
    } else {
        system("cls");
        cout << "=================================\n";
        cout << "        ANTRIAN PERPUSTAKAAN \n";
        cout << "=================================\n";
        cout << "| NO | NAMA | HARGA | JUMLAH |\n";
        for (int i = 0; i < names.size(); i++) {
            cout << "|" << setw(2) << i + 1 << "|"
                 << setw(6) << names[i] << "|"
                 << setw(5) << prices[i] << "|"
                 << setw(6) << quantities[i] << "|\n";
        }
        cout << "=====================================\n";
        cout << "TOTAL HARGA : Rp." << totalHarga << "\n";
        cout << "=====================================\n";
    }
}

int main() {
    int menuutama, menustack, menuuser, judulbuku, jawab, no, add, choose;
    char jawabuser, jawabstack, jawabqueue;
    cout << "========== SILAHKAN LOGIN ==========\n";
    cout << "\nUsername : ";
    string username, password;
    cin >> username;
    cout << "\nPassword : ";
    cin >> password;
    cout << "\nMohon Menunggu";
    for (int i = 0; i < 20; i++) {
        cout << ".";
    }
    cout << "\nID yang dimasukkan Benar" << endl;
    system("cls");

    cout << "====================================";
    cout << "\n        MENU UTAMA        ";
    cout << "\n====================================";
    cout << "\n1. USER MANAGER";
    cout << "\n2. PROGRAM STACK";
    cout << "\n3. PROGRAM QUEUE";
    cout << "\n4. EXIT";
    cout << "\n====================================";
    cout << "\nPilih Menu : ";
    cin >> menuutama;

    if (menuutama == 1) {
        do {
            system("cls");
            cout << "        MENU USER MANAGER        ";
            cout << "\n====================================";
            cout << "\n1. Add Data";
            cout << "\n2. Update Data";
            cout << "\n3. Delete Data";
            cout << "\n4. Exit";
            cout << "\n====================================";
            cout << "\nPilih Menu : ";
            cin >> menuuser;
            if (menuuser == 1) {
                cout << "\nMasukkan Data : ";
                cin >> add;
                adddata();
            } else if (menuuser == 2) {
                update();
            } else if (menuuser == 3) {
                remove();
            } else {
                cout << "Masukkan Salah" << endl;
            }
            cout << "\nApakah Ingin Kembali Ke Menu User Manager? [Y/T] ";
            cin >> jawabuser;
        } while (jawabuser == 'y' || jawabuser == 'Y');
        cin >> jawabuser;
        getch();
    } else if (menuutama == 2) {
        do {
            system("cls");
            cout << "        MENU STACK        ";
            cout << "\n====================================";
            cout << "\n1. PUSH";
            cout << "\n2. POP";
            cout << "\n3. PRINT";
            cout << "\n====================================";
            cout << "\nPilih Menu : ";
            cin >> menustack;
            if (menustack == 1) {
                cout << "\nMasukkan Judul : ";
                cin >> judulbuku;
                push(judulbuku);
            } else if (menustack == 2) {
                pop();
            } else if (menustack == 3) {
                cout << "\nStack Adalah : ";
                print();
            } else {
                cout << "\nPilih Menu dari 1-3";
            }
            cout << "\nApakah Ingin Kembali Ke Menu Stack ? [Y/T] ";
            cin >> jawabstack;
        } while (jawabstack == 'Y' || jawabstack == 'y');
        getche();
    } else if (menuutama == 3) {
        do {
            system("cls");
            cout << "=================================\n";
            cout << "        ANTRIAN PERPUSTAKAAN \n";
            cout << "=================================\n";
            view();
            cout << "\n1. Tambah Buku \n";
            cout << "\n2. Keluarkan Buku \n";
            cout << "\n3. Daftar \n";
            cout << "\n4. Keluar \n";
            cout << "=================================\n";
            cout << "\nMasukkan Pilihan Anda         : ";
            cin >> choose;
            if (choose == 1) {
                string judul;
                int harga, jumlah;
                cout << "Judul buku yang akan di beli :";
                cin >> judul;
                cout << "Harga buku yang di beli : ";
                cin >> harga;
                cout << "Jumlah yang di beli :";
                cin >> jumlah;
                names.push_back(judul);
                prices.push_back(harga);
                quantities.push_back(jumlah);
                totalHarga += harga * jumlah;
            } else if (choose == 2) {
                if (names.empty()) {
                    cout << "tidak ada buku yang dapat di keluarkan !" << endl;
                    continue;
                }
                cout << "Buku " << names.front() << " Seharga Rp." << prices.front() << " berjumlah " << quantities.front() << " telah dikeluarkan" << endl;
                names.erase(names.begin());
                prices.erase(prices.begin());
                quantities.erase(quantities.begin());
            } else if (choose == 3) {
                view();
            } else if (choose == 4) {
                cout << "Exit";
                break;
            } else {
                cout << "Pilih Menu Dari 1-4";
            }
            cout << "\nKembali Ke Menu ? [Y/T] ";
            cin >> jawabqueue;
        } while (jawabqueue == 'y' || jawabqueue == 'Y');
    } else if (menuutama == 4) {
        exit(0);
    } else {
        cout << "Masukkan Salah";
    }
    return 0;
}
