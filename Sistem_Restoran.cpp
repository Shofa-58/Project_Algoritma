#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>

using namespace std;

int pilihmenu, cari_kode, i = 0;
char menu_kembali = 'y' || 'Y';
string cari_nama;

bool found;

struct Menu_Restoran
{
    int ID;
    char nama[30];
    char kategori[20];
    int harga;
};

struct Node 
{
        Menu_Restoran data;
        Node* kanan;
        Node* kiri;
};


struct Node* buatNode (int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->kanan = NULL;
    newNode->kiri = NULL;
    return newNode;
}

void Input_Data() //input data
{
    // temp sebagai vaiabel sementara untuk penginputan
    Menu_Restoran temp;
    FILE *filedata;
    filedata = fopen("datarestoran.dat", "ab");
    if (!filedata)
    {
        cout <<"File tidak ditemukan!\n"<< endl;
        return;
    }
    cout << "\n====== INPUT DATA ======\n" << endl;
    cout << left << setfill(' ') << setw(30) << "Masukkan Nomer Kependudukan " << ":";
    cin >> temp.ID;
    cout << left << setfill(' ') << setw(30) << "Masukkan nama " << ":";
    cin.ignore();
    cin.getline(temp.nama, 30);
    cout << left << setfill(' ') << setw(30) << "Masukkan alamat " << ":";
    cin.getline(temp.kategori, 20);
    cout << left << setfill(' ') << setw(30) << "Masukkan jenis kelamin " << ":";
    cin >> temp.harga;

    fwrite(&temp, sizeof(Menu_Restoran), 2, filedata);
    fclose(filedata);

    cout << "Data kependudukan berhasil ditambahkan!" << endl;
}

void Bubble_Sort()//search bubble sorting
{
    FILE *filedata;
    filedata = fopen("datarestoran.dat", "rb");

    Menu_Restoran data[100];
    int index = 0;

    //untuk mencari jumlah index array
    while (fread(&data[index], sizeof(Menu_Restoran), 1, filedata))
    {
        index++;
    }

    for (int i = 0; i < index - 1; ++i)
    {
        for (int j = 0; j < index - 1 - i; ++j)
        {
            if (data[j].ID > data[j + 1].ID)
            {
                swap(data[j], data[j + 1]);
            }
        }
    }

    filedata = fopen("datarestoran.dat", "wb");
    for (int i = 0; i < index; ++i)
    {
        fwrite(&data[i], sizeof(Menu_Restoran), 1, filedata);
    }
    fclose(filedata);
}

void Output_Data()
{
    Menu_Restoran temp;
    FILE *filedata;
    filedata = fopen("datarestoran.dat", "ab");
    if (!filedata)
    {
        cout <<"File tidak ditemukan!\n"<< endl;
        return;
    }
        Bubble_Sort(); // Selalu urutkan data sebelum ditampilkan

    // temp sebagai vaiabel sementara untuk penginputan
    cout << "\n====== Daftar Menu Item ======\n"<<endl;
    cout << left <<setfill(' ') << setw(5) << "ID." <<"|"
         <<setfill(' ') << setw(20) << "Nama" <<"|"<<setfill(' ')<< setw(30)
         <<setfill(' ') << "Kategori" <<"|"<< "Harga"<<"|"<< endl;
    while (fread(&temp, sizeof(Menu_Restoran), 1, filedata))
    {
        cout << left <<setfill(' ')<<setw(5) << temp.ID <<"|"
             <<setfill(' ')<< setw(20) << temp.nama <<"|"
             <<setfill(' ')<<setw(30) << temp.kategori <<"|"
             << setfill(' ')<<setw(13)<<temp.harga <<"|"<< endl;
    }
    fclose(filedata);

}

int main()
{
    do
    {
        cout << "\n";
        cout << "MENU PILIHAN:" << endl;
        cout << "1. Input Data Item" << endl;
        cout << "2. Tampilan Data Item" << endl;
        cout << "3. Mencari Data" << endl;
        cout << "4. Mengurutkan Data Item" << endl;
        cout << "5. Menutup Program" << endl;
        cout << "memilih : ";
        cin >> pilihmenu;

        switch (pilihmenu)
        {
        case 1:
        {
            Input_Data();
            break;
        }

        case 2:
        {
            Output_Data();
            break;
        }
    
        case 3:
        {

        }

        case 4:
        {

        }
        case 5:
        {
            cout << "Terima Kasih Telah Menggunakan Program Kami" << endl;
            exit(0);
            break;
        }
        }
        cout << "Kembali Ke menu ? (y/n) : ";
        cin >> menu_kembali;
    } while (menu_kembali == 'y' || menu_kembali == 'Y');
    
    return;
}