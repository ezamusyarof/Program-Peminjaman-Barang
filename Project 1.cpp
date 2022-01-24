#include <iostream> 
#include <conio.h>
#include <ctime>
using namespace std;

// PROGRAM PEMINJAMAN BARANG

// Variable
const int a=5; 	// Limit user
int id=0;		// id = nomor id real-time
string email, password_admin;
string username[a];
string password[a];
string nama[a];
string nim[a];
string kelas[a];
string alasan[a];
string status[a];
string barang[10];
int jumlah[a];

time_t waktu=time(0);
tm *sekarang=localtime(&waktu);
char* hari_ini=ctime(&waktu);

void login();
void menu();
void formulir();
void pilih_barang();
void pilih_durasi();
void status_peminjaman();
void admin();
void menu_admin();

int main(){
	system ("color 02"); //0 background, 2 text
	cout << hari_ini;
	if(id==0){
		for(int i=1; i<a; i++){
			status[i]="Belum di periksa";
			nama[i]="Tidak ada";
			nim[i]="Tidak ada";
			kelas[i]="Tidak ada";
			alasan[i]="Tidak ada";
			barang[i]="Tidak ada";
			jumlah[i]=0;
		}
	}
	
	cout << "...................................................." << endl;
	cout << ".        SELAMAT DATANG DI PEMINJAMAN BARANG       ." << endl;
	cout << ".            POLITEKNIK NEGERI JAKARTA             ." << endl;
	cout << "...................................................." << endl << endl << endl;
	cout << "           [1] MASUK          [2] DAFTAR" << endl << endl << endl;
	cout << "...................................................." << endl;
	cout << id << " ==> ";
	
	int pilihan;
	cin >> pilihan;
	if(pilihan==1){
		system("cls"); cout << hari_ini;
		login();
	}else if(pilihan==2){
		system("cls"); cout << hari_ini;
		while(id<=a){
			cout << "...................................................." << endl;
			cout << ".                   DAFTAR AKUN                    ." << endl;
			cout << "...................................................." << endl;
			id++;
			cout << endl;
			cout << "    username: ";
			cin >> username[id];
			cout << "    password: ";
			cin >> password[id];
			cout << endl;
			cout << "[1] Daftar  [2] Keluar" << endl;
			int pilihan;
			cout << "...................................................." << endl;
			cout << "==> ";
			cin >> pilihan;
			if(pilihan==1){
				system("cls");
				main(); break;
			}else{
				break;
			}
		}
   	}else{
		system("cls"); cout << hari_ini;
		cout << "(!) Intruksi salah, harap ulangi ..." << username[1];
		main();
	}
	system("cls");
	cout << hari_ini;
	cout << "...................................................." << endl;
	cout << ".                                                  ." << endl;
	cout << ".        TERIMA KASIH TELAH TELAH BERKUNJUNG       ." << endl;
	cout << ".                                                  ." << endl;
	cout << "...................................................." << endl << endl;
	
	return 0;
}

void login(){
	cout << "[1] Kembali  [2] Home     [3] Keluar" << endl;
	cout << "...................................................." << endl;
	cout << ".                    LOGIN PAGE                    ." << endl;
	cout << "...................................................." << endl;
	cout << "\n    Username: ";
	
	string user, pw;
	cin >> user;
	if(user=="admin"){
		system("cls");
		cout << hari_ini << endl;
		admin();
	}else{
 		for(int i=1; i<=a; i++){
			if(user==username[i]){
				cout << "    Password: ";
				cin >> pw;
				if(pw==password[i]){
					system("cls");\
					id=i;
					cout << hari_ini;
					cout << "User Terverifikasi ..." << endl;
					menu(); break;
				}else{
					system("cls");
					id=i;
					cout << "(!) Password salah, harap masukan karakter dengan benar ...\n" << endl;
					login(); break;
				}
			}else if((user=="1")||(user=="2")||(user=="3")){
				if(user=="1"){
					system("cls"); main(); break;
				}else if(user=="2"){
					system("cls"); main(); break;
				}else{
					system("cls"); break;
				}
			}else if((i==a)&&(user!=username[i])){
				system("cls");
				cout << hari_ini;
				cout << "(!) Username salah! daftar terlebih dahulu" << endl;
				login(); break;
			}
		}
	}
}

void menu(){;
	cout << "...................................................." << endl;
	cout << "                     MENU UTAMA" << endl;
	cout << "...................................................." << endl;
	cout << "[1] Ajukan peminjaman\n[2] Cek Status Peminjaman\n[3] Logout\n[4] Quit" << endl;
	cout << "----------------------------------------------------\n";
	
	int pilihan;
	cout << "==> ";
	cin >> pilihan;
	switch(pilihan){
		case 1:
			system("cls");
			cout << hari_ini << endl;
			formulir(); break;
		case 2:
			system("cls");
			cout << hari_ini << endl;
			status_peminjaman(); break;
		case 3:
			system("cls");
			cout << hari_ini << endl;
			login(); break;
		case 4:
			break;
		default:
			system("cls");
			cout << hari_ini << endl;
			cout << "Perintah salah, harap ulangi ...\n\n";
			menu(); break;
		}
}

void formulir(){
	cout << "...................................................." << endl;
	cout << "                      FORMULIR" << endl;
	cout << "...................................................." << endl;
	cin.ignore(1, '\n');
	cout << "Nama\t\t: "; getline(cin,nama[id]); 
	cout << "NIM\t\t: "; getline(cin,nim[id]); 
	cout << "Kelas\t\t: "; getline(cin,kelas[id]);
	cout << "\n\n\n";
	cout << "...................................................." << endl;
	cout << "[1] Next\t[2] Back\t[3] Exit\n\n";
	
	int pilihan;
	cout << "==> ";
	cin >> pilihan;
	switch(pilihan){
		case 1:
			system("cls");
			cout << hari_ini << endl;
			pilih_barang(); break;
		case 2:
			system("cls");
			cout << hari_ini << endl;
			menu(); break;
		default:
			cout << "Perintah salah, harap ulangi ...\n\n";
			system("cls");
			cout << hari_ini << endl;
			menu(); break;
	}
}

void pilih_barang(){
	cout << "...................................................." << endl;
	cout << "                    PILIH BARANG" << endl;
	cout << "...................................................." << endl;
	string daftar_barang[10]={"Laptop","Proyektor","Router","Access Point","Kabel LAN","Bridge","Hub","Switch","Modem","Repeater"};
	cout << "PILIH BARANG	: \n" << endl;
	cout << "  [1] Laptop" << endl;
	cout << "  [2] Proyektor" << endl;
	cout << "  [3] Alat Jaringan Komputer\n" << endl;
	cout << "=> ";
	int pilihan_barang;
	cin >> pilihan_barang;
	switch(pilihan_barang){
		case 1:
			barang[id]=daftar_barang[pilihan_barang-1];
			break;
		case 2:
			barang[id]=daftar_barang[pilihan_barang-1];
			break;
		case 3:
			cout << "Alat Jaringan Komputer: \n" << endl;
			cout << "  [1] Router" << endl;
			cout << "  [2] Access Point" << endl;
			cout << "  [3] Kabel LAN" << endl;
			cout << "  [4] Bridge" << endl;
			cout << "  [5] Hub" << endl;
			cout << "  [6] Switch" << endl;
			cout << "  [7] Modem" << endl;
			cout << "  [8] Repeater\n" << endl;
			cout << "=> ";
			cin >> pilihan_barang;
			if((pilihan_barang>=0)&&(pilihan_barang<=8)){
				barang[id]=daftar_barang[pilihan_barang+1];	
			}else{
				system("cls");
			cout << hari_ini << endl;
				cout << "(!) Maaf, intruksi salah ...\n" << endl;
				pilih_barang();
			}
			break;
		default:
			system("cls");
			cout << hari_ini << endl;
			cout << "(!) Maaf, intruksi salah ...\n" << endl;
			pilih_barang();
			break;
	}
	
	cout << "\nJumlah\t\t: "; cin >> jumlah[id];
	cin.ignore(1, '\n');
	cout << "Alasan\nPeminjaman\t: "; getline(cin,alasan[id]); 
	cout << "\n\n";
	cout << "...................................................." << endl;
	cout << "[1] Next\t[2] Back\t[3] Exit\n\n";
	
	int pilihan;
	cout << "==> ";
	cin >> pilihan;
	switch(pilihan){
		case 1:
			system("cls");
			cout << hari_ini << endl;
			pilih_durasi();
			break;
		case 2:
			system("cls");
			cout << hari_ini << endl;
			formulir();
			break;
		default:
			system("cls");
			cout << hari_ini;
			cout << "Perintah salah, harap ulangi ..." << endl;
			menu();
			break;
	}
	
}

void pilih_durasi(){
	cout << "...................................................." << endl;
	cout << "                    PILIH DURASI" << endl;
	cout << "...................................................." << endl;
	
	cout << "\n\n\n";
	cout << "...................................................." << endl;
	cout << "[1] Next\t[2] Back\t[3] Exit\n\n";
	
	int pilihan;
	cout << "==> ";
	cin >> pilihan;
	switch(pilihan){
		case 1:
			system("cls");
			cout << hari_ini << endl;
			status_peminjaman();
			break;
		case 2:
			system("cls");
			cout << hari_ini << endl;
			pilih_barang();
			break;
		default:
			system("cls");
			cout << hari_ini << endl;
			cout << "Perintah salah, harap ulangi ...\n\n";
			menu();
			break;
	}
}

void status_peminjaman(){
	cout << "...................................................." << endl;
	cout << "                  STATUS PEMINJAMAN" << endl;
	cout << "...................................................." << endl;
	cout << "Nama Peminjam\t: " << nama[id] << endl; 
	cout << "NIM\t\t: " << nim[id] << endl; 
	cout << "Kelas\t\t: " << kelas[id] << endl;
	cout << "Nama Barang\t: " << barang[id] << endl;
	cout << "Alasan\nPeminjaman\t: " << alasan[id] << endl << endl;
	cout << "STATUS\t: " << status[id];
	
	cout << "\n\n";
	cout << "...................................................." << endl;
	cout << "[1] Menu\n\n";
	
	int pilihan;
	cout << "==> ";
	cin >> pilihan;
	switch(pilihan){
		default:
			system("cls");
			cout << hari_ini << endl;
			menu();
			break;
	}
	
}

void admin(){
	cout << "...................................................." << endl;
	cout << "                    LOGIN ADMIN" << endl;
	cout << "----------------------------------------------------" << endl << endl;
	cout << "  Anda login sebagai admin..." << endl << endl;
	cout << "  Password: ";
	cin >> password_admin;
	if(password_admin=="123"){
		system("cls");
		cout << hari_ini << endl;
		menu_admin();
	}
	else{
		cout << "\n\n(!) Password Salah... " << endl << endl;
		cout << "[1] Kembali\t[2] Ulangi\n\n==> ";
		int pilihan;
		cin >> pilihan;
		switch(pilihan){
			case 1:
				system("cls");
				cout << hari_ini << endl;
				login();
			case 2:
				system("cls");
				cout << hari_ini << endl;
				admin();
			default:                 
				cout << "Perintah salah, harap ulangi ...\n\n";
				system("cls");
				cout << hari_ini << endl;
				admin();
		}
	}
}

void menu_admin(){
	cout << "...................................................." << endl;
	cout << "                     MENU ADMIN" << endl;
	cout << "...................................................." << endl;
	cout << "[1] Daftar Username" << endl;
	cout << "[2] Edit Status" << endl;
	cout << "\n\n\n";
	cout << "...................................................." << endl;
	
	int pilihan, i=0;
	cout << "==> ";
	cin >> pilihan;
	switch(pilihan){
		case 1:
			daftar_user:
			system("cls");
			cout << "...................................................." << endl;
			cout << "                    DAFTAR USER" << endl;
			cout << "...................................................." << endl;
			cout << "ID\tUsername\t\tPassword" << endl;
			while(i<=id){
				cout << i << "\t" << username[i] << "\t\t" << password[i] << endl;
				i++;
			}
			cout << endl;
			int pilihan;
			cout << "Pilih User ==> ";
			cin >> pilihan;
			if(pilihan==0){
				system("cls");
				cout << hari_ini << endl;
				menu_admin();
			}else{
				for(int i=1; i<=id; i++){
					if(pilihan==i){
						cout << endl;
						cout << "Nama Peminjam\t: " << nama[i] << endl; 
						cout << "NIM\t\t: " << nim[i] << endl; 
						cout << "Kelas\t\t: " << kelas[i] << endl;
						cout << "Alasan\nPeminjaman\t: " << alasan[i] << endl << endl;
						cout << "STATUS\t: " << status[i] << endl;
						system("pause");
						system("cls"); cout << hari_ini;
						cout << hari_ini << endl;
						menu_admin();
						break;
					}else if(pilihan>a){
						system("cls");
						cout << hari_ini << endl;
						cout << "(!) Instruksi salah... " << endl;
						goto daftar_user;
					}
				}
			}
			break;
		case 2:
			system("cls");
			int pilihan2;
			cout << "Pilih ID User ==> ";
			cin >> pilihan2;
			if(pilihan2==0){
				system("cls");
				cout << hari_ini << endl;
				menu_admin();
			}else{
				for(int i=1; i<=a; i++){
					if(pilihan2==i){
						cout << endl;
						cout << "Nomor ID\t: " << i << endl;
						cout << "Nama Peminjam\t: " << nama[i] << endl;
						cout << "Status\t: " << status[i] << endl << endl; 
						cout << "STATUS\t: ";
						cin.ignore(1, '\n');
						getline(cin,status[i]);
						system("pause");
						system("cls");
						cout << hari_ini << endl;
						menu_admin();
						break;
					}else if(pilihan2>a){
						cout << "(!) Instruksi salah / User tidak ada ... " << endl;
						system("cls");
						cout << hari_ini << endl;
						goto daftar_user;
					}
				}
			}
			break;
		case 3:
			system("cls");
			cout << hari_ini << endl;
			main();
	}
}

// Ngirim pesan ke user lain/admin
// 

