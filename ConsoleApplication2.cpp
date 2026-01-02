/******************************
**
**  İSTANBUL 29 MAYIS ÜNİVERSİTESİ
**  BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**  BÜYÜK VERİ ANALİSTLİĞİ PR.
**  PROGRAMLAMAYA GİRİŞ DERSİ PROJESİ
**  2025-2026 GÜZ DÖNEMİ
**
**  ÖĞRENCİ ADI      : Yigit Ergünöz
**  ÖĞRENCİ NUMARASI : 300125014
**
******************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* ================= STRUCT TANIMLARI ================= */

struct Oda {
    int OdaNo;
    double Ucret;
};

struct Musteri {
    int MusteriNo;
    string Ad;
    string Soyad;
    string Tc;
};

struct Kayit {
    int OdaNo;
    int MusteriNo;
};

/* ================= FONKSİYONLAR ================= */

void OdaEkle() {
    ofstream dosya("odalar.txt", ios::app);
    Oda oda;

    cout << "Oda No: ";
    cin >> oda.OdaNo;
    cout << "Oda Ucreti: ";
    cin >> oda.Ucret;

    dosya << oda.OdaNo << " " << oda.Ucret << endl;
    dosya.close();

    cout << "Oda eklendi.\n";
}

void OdalariListele() {
    ifstream dosya("odalar.txt");
    Oda oda;

    cout << "\n--- ODA LISTESI ---\n";
    while (dosya >> oda.OdaNo >> oda.Ucret) {
        cout << "Oda No: " << oda.OdaNo << " | Ucret: " << oda.Ucret << endl;
    }
    dosya.close();
}

void MusteriEkle() {
    ofstream dosya("musteriler.txt", ios::app);
    Musteri m;

    cout << "Musteri No: ";
    cin >> m.MusteriNo;
    cout << "Ad: ";
    cin >> m.Ad;
    cout << "Soyad: ";
    cin >> m.Soyad;
    cout << "TC Kimlik No: ";
    cin >> m.Tc;

    dosya << m.MusteriNo << " " << m.Ad << " " << m.Soyad << " " << m.Tc << endl;
    dosya.close();

    cout << "Musteri eklendi.\n";
}

void MusterileriListele() {
    ifstream dosya("musteriler.txt");
    Musteri m;

    cout << "\n--- MUSTERI LISTESI ---\n";
    while (dosya >> m.MusteriNo >> m.Ad >> m.Soyad >> m.Tc) {
        cout << "No: " << m.MusteriNo
            << " | Ad: " << m.Ad
            << " | Soyad: " << m.Soyad
            << " | TC: " << m.Tc << endl;
    }
    dosya.close();
}

void OdaKayit() {
    ofstream dosya("kayitlar.txt", ios::app);
    Kayit k;

    cout << "Oda No: ";
    cin >> k.OdaNo;
    cout << "Musteri No: ";
    cin >> k.MusteriNo;

    dosya << k.OdaNo << " " << k.MusteriNo << endl;
    dosya.close();

    cout << "Oda kaydi yapildi.\n";
}

/* ================= MENÜLER ================= */

void OdaMenu() {
    int secim;
    do {
        cout << "\nOda Islemleri\n";
        cout << "1- Oda Ekle\n";
        cout << "2- Odalari Listele\n";
        cout << "99- Ust Menu\n";
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {
        case 1: OdaEkle(); break;
        case 2: OdalariListele(); break;
        case 99: break;
        default:
            cout << "Hatali Secim\n";
        }
    } while (secim != 99);
}

void MusteriMenu() {
    int secim;
    do {
        cout << "\nMusteri Islemleri\n";
        cout << "1- Musteri Ekle\n";
        cout << "2- Musterileri Listele\n";
        cout << "99- Ust Menu\n";
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {
        case 1: MusteriEkle(); break;
        case 2: MusterileriListele(); break;
        case 99: break;
        default:
            cout << "Hatali Secim\n";
        }
    } while (secim != 99);
}

/* ================= MAIN ================= */

int main() {
    int secim;

    do {
        cout << "\nOTEL ISLEMLERI\n";
        cout << "1- Oda Islemleri\n";
        cout << "2- Musteri Islemleri\n";
        cout << "3- Oda Kayit Islemleri\n";
        cout << "99- Cikis\n";
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {
        case 1: OdaMenu(); break;
        case 2: MusteriMenu(); break;
        case 3: OdaKayit(); break;
        case 99: cout << "Programdan cikiliyor...\n"; break;
        default:
            cout << "Hatali Secim\n";
        }
    } while (secim != 99);

    return 0;
}