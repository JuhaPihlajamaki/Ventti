#include "Pelaaja.h"
#include <iostream>
#include <clocale>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;
Pelaaja::Pelaaja() {
	int KortinArvo();
	int KortinMaa();
}
void Pelaaja::Odota() {
	Sleep(1000);
	
}

void Pelaaja::Readme() {
	cout << "Tervetuloa pelaamaan venttia!" << endl;
	cout << "Haluatko lukea pelin ohjeet (K/E) ?"<<endl;
	string ohjeet;
	cin >> ohjeet;
	if(ohjeet=="k"|| ohjeet == "K"){
	string line;
	ifstream myfile("ohjeet.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			Sleep(400);
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "ReadMe tiedoston luku ei onnistunut!";

		Odota(); Odota(); Odota(); Odota();Odota();Odota();
		
	}

}



void Pelaaja::AsetaPotti() {
	cout << "Sinulla on rahaa " << Rahaa << " euroa" << endl;
	cout << "Aseta panos 1 - " << Rahaa << " euroa" << endl;
	cin >> Potti;
	Rahaa -= Potti;
	Potti += Potti;
}
void Pelaaja::TeePakka() {
	
	int laskuri = 0;
	for (int i = 0; i <= 3; i++) {
	
		for (int m = 2; m <= 14; m++) {
			KorttiArvo[laskuri] = m;
			KorttiMaa[laskuri] = i;
			laskuri++;
		}

	}
	
}
void Pelaaja::SekoitaPakka() {
	
	srand(time(0));

	for (int i=0; i < 1000; i++)
	{
		
		int luku1 = rand() % 52 + 0;
		int luku2 = rand() % 52 + 0;

		int hetkellinen = KorttiArvo[luku1];
		KorttiArvo[luku1] = KorttiArvo[luku2];
		KorttiArvo[luku2] = hetkellinen;

		hetkellinen = KorttiMaa[luku1];
		KorttiMaa[luku1] = KorttiMaa[luku2];
		KorttiMaa[luku2] = hetkellinen;
		
	}

}
void Pelaaja::OtaKortti() {
	
	KasiArvo[KasiMaara] = KorttiArvo[KasiMaara];
	KasiMaa[KasiMaara] = KorttiMaa[KasiMaara];
	KasiMaara++;
}
/*
void Pelaaja::TulostaKortit() {
	system("cls");
	for (int i = 0; i < KasiMaara; i++) {
		string maa;
		if (KasiMaa[i] == 0) maa = Hertta;
		if (KasiMaa[i] == 1) maa = Ruutu;
		if (KasiMaa[i] == 2) maa = Pata;
		if (KasiMaa[i] == 3) maa = Risti;

		cout << "arvo = " << KasiArvo[i] << " Maa on =  " << KasiMaa[i]  <<maa<< endl;

	}

}
*/


void Pelaaja::TulostaKortit() {
	

	///// Tulostetaan ensimmäinen rivi.
	for (int i = 1; i <= KasiMaara; i++) {
		cout << " *********** ";
	}

	///// Tulostetaan toinen rivi.
	cout << endl;
	for (int i = 1; i <= KasiMaara; i++) {
		cout << " *         * ";
	}


	///// Tulostetaan kolmas rivi.
	cout << endl;
	for (int i = 1; i <= KasiMaara; i++) {
		cout << " *         * ";
	}


	///// Tulostetaan neljäs rivi eli maa;
	cout << endl;
	for (int i = 1; i <= KasiMaara; i++) {
		string maa;
		if (KasiMaa[i - 1] == 0) maa = " * Hertta  * ";
		if (KasiMaa[i - 1] == 1) maa = " *  Ruutu  * ";
		if (KasiMaa[i - 1] == 2) maa = " *   Pata  * ";
		if (KasiMaa[i - 1] == 3) maa = " *  Risti  * ";
		cout << maa;
	}





	///// Tulostetaan viides rivi eli arvo;
	cout << endl;
	for (int i = 1; i <= KasiMaara; i++) {


		cout << " *    " << KasiArvo[i - 1];
		if (KasiArvo[i - 1] < 10) { cout << " "; }
		cout << "   * ";
	}

	///// Tulostetaan kuudes rivi.
	cout << endl;
	for (int i = 1; i <= KasiMaara; i++) {
		if(KasiArvo[i-1] == 14) { cout << " *   tai   * "; }
		else{ cout << " *         * "; }
		
	}

	///// Tulostetaan seitsemäs rivi.
	cout << endl;
	for (int i = 1; i <= KasiMaara; i++) {
		if (KasiArvo[i - 1] == 14) { cout << " *    1    * "; }
		else { cout << " *         * "; }

	}

	///// Tulostetaan viimeinen rivi.
	cout << endl;
	for (int i = 1; i <= KasiMaara; i++) {
		cout << " *********** ";
	}
	
}

void Pelaaja::LaskePisteet() {
	
	
	
	Pisteet = 0;

	for (int i =0;i!=KasiMaara; i++)
	{
		Pisteet += KasiArvo[i];
	}
	for (int i = 0; i <= KasiMaara; i++) {
		if (KorttiArvo[i-1] == 14 && Pisteet > 21) { Pisteet -= 13; }
	}
	
	if(Pisteet>=21)Run = 4;
	
	
}
void Pelaaja::TulostaPisteet() {
	cout << "\n Korttiesi arvo on nyt " << Pisteet << " pistetta." << endl;
}
void Pelaaja::Haluatko() {
	
		LaskePisteet();
		
		if (Pisteet >= 21) {
			Run = 4;
		}


		while (Pisteet < 21&&  Halu=="k"|| Halu == "K"&&Run==1) {
			system("cls");
			TulostaKortit();
			LaskePisteet();
			if (Pisteet < 21) {
				
					cout << "\n Haluatko ottaa uuden kortin, korttien arvo on nyt "<< Pisteet<<" (K/E)";
					cin >> Halu;
					if (Halu == "k" || Halu == "K" || Halu == "e" || Halu == "E") { Tarkistus = 1; }

					while (Halu != "k" && Halu != "K" && Halu != "e" && Halu != "E")
					{
						cout << "\n Virheellinen syote, anna (K/E)";
						cout << "\n Haluatko ottaa uuden kortin, korttien arvo on nyt " << Pisteet << " (K/E)";
						cin >> Halu;
					}
				}


			if (Pisteet>=21) {
				Run = 4;
			}


			if (Halu == "k" || Halu == "K"&&Pisteet<21&&Run==1) {
				if(Pisteet<21) OtaKortti();
			}
			if(Halu == "e" || Halu == "E"||Pisteet>=21) {
				Run = 4;
				//Pisteet = 21;//Tekee ventin joka kerta
			}
		}
		
			
		
}
void Pelaaja::AsetaPanos() {
	
	
	TulostaPisteet();
		cout << " Sinulla on rahaa " << Rahaa << " euroa." << endl;
		cout << " Aseta panos talle kierrokselle. 1 - " << Rahaa << "euroa." << endl;
		cin >> Potti;
	
	

	Rahaa -= Potti;
	Potti += Potti;
	
}

// Peli etenee tässä järjestyksessä

void Pelaaja::Alkutoimet() {
	
	system("cls");
	TeePakka();
	SekoitaPakka();
	OtaKortti();
	TulostaKortit();
	LaskePisteet();
	AsetaPanos();
	Run=1;
}
