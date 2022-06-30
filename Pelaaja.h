#pragma once
#ifndef PELAAJA_H
#define PELAAJA_H
using namespace std;
#include<string>
class Pelaaja
{
public:

	Pelaaja();


	void AsetaPotti();



	void Odota();
	void TeePakka();
	void SekoitaPakka();
	void OtaKortti();
	void TulostaKortit();
	void LaskePisteet();
	void AsetaPanos();
	void Haluatko();
	void TarkistaPisteet();
	int HaeJakajanPisteet();
	void TulostaPisteet();

	void Alkutoimet();//Run=0
	void Tarkista();//Run=2
	void JakajaVetaa();//Run=3
	void Readme();
	
	
	

	int Rahaa=50;
	int Pisteet=0;
	int Run=0;
	int Potti = 0;
	int kierros = 0;
	int Tarkistus = 0;

	string H = "\x03";
	string R = "\x04";
	string P = "\x06";
	string C = "\x05";
	string Halu="k";
	


	int KorttiMaa[52]{};
	int KorttiArvo[52]{};

	

	int KasiMaa[12]{};
	int KasiArvo[12]{};
	int KasiMaara = 0;

};
#endif // PELAAJA_H

