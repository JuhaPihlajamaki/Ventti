#include <iostream>
#include "Pelaaja.h"
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	Pelaaja Juha;
	Pelaaja Jakaja;
	Juha.Readme();
	while (Juha.Run == 0 && Juha.Rahaa > 0) {

		
		Juha.Alkutoimet();
		Jakaja.TeePakka();
		Jakaja.SekoitaPakka();

		if (Juha.Run == 1)
		{
			Juha.Haluatko();
			Juha.Run = 2;
		}



		if (Juha.Run == 2) { // Tarkistetaan pisteet voittaja ym.
			Juha.Run = 3;
		}



		while (Juha.Run == 3 && Juha.Pisteet < 21) { // Jakaja vetää kortteja.
			cout << "Jakaja vetaa kortteja" << endl;
			Jakaja.OtaKortti();
			system("cls");
			Jakaja.LaskePisteet();
			cout << " Jakajan kortit, pisteet yhteensa " << Jakaja.Pisteet << "." << endl;
			Jakaja.TulostaKortit();

			cout << "\n\n Sinun korttisi, pisteet yhteensa " << Juha.Pisteet << "." << endl;
			Juha.TulostaKortit();



			if (Jakaja.Pisteet < Juha.Pisteet && Jakaja.Pisteet < 21 && Juha.Pisteet < 21) {
				cout << "\n\n\n Sinun ";
				Juha.Odota();
				cout << "pisteesi ";
				Juha.Odota();
				cout << "on paremmat. ";
				Juha.Odota();
				cout << "taidampa ottaa ";
				Juha.Odota();
				cout << "viela yhden ";
				Juha.Odota();
				cout << "kortin.";
				Juha.Odota();

				if (Jakaja.Pisteet > 21) {

					Juha.Run = 4;
				}
			}

			if (Jakaja.Pisteet >= Juha.Pisteet || Jakaja.Pisteet > 21 ||Juha.Pisteet>21) {
				Juha.Run = 4;
			}







		}

	
	Juha.Run = 4;

	if (Juha.Run == 4) { // Tarkistaa pelin tulokse jakaa potin ja Run=0.
		system("cls");
		


		if (Jakaja.Pisteet == 21 || Jakaja.Pisteet == 20) {
			cout << "Jakaja sai ventin ja voitti taman kierroksen" << endl;
			cout << "Potti " << Juha.Potti << " euroa voittaa jakaja" << endl;
			
		}

		if (Juha.Pisteet == 21) {
			cout << "Sina sait ventin ja voitit taman kierroksen" << endl;
			cout << "Voitit potin " << Juha.Potti << " euroa." << endl;
			Juha.Rahaa += Juha.Potti;
			Juha.TulostaKortit();
		}


		if (Juha.Pisteet <= Jakaja.Pisteet && Jakaja.Pisteet<21) {
			cout << "Jakajalla paremmat, tai yhtasuuret pisteet, jakaja voittaa" << endl;
			cout << "Potin " << Juha.Potti << " euroa voittaa jakaja" << endl;
			
		}
		if (Juha.Pisteet > 21) {
			system("cls");
			Juha.TulostaKortit();
			cout << "\nSinun pisteesi on "<< Juha.Pisteet<<" se on yli 21 pistetta." << endl;
			cout << "Jakaja voitti taman kierroksen potin "<< Juha.Potti <<" euroa."<< endl;
			cout << "Sinun korttisi, pisteet yhteensa " << Juha.Pisteet << endl;
			cout << endl;
		}

		if (Jakaja.Pisteet > 21) {
			cout << "Jakajan pisteet meni yli 21, sina voitit potin "<< Juha.Potti<<" euroa." << endl;
			Juha.Rahaa += Juha.Potti;
		}


		if(Jakaja.KasiMaara>0){
			
		cout << "\nJakajan kortit, pisteet yhteensa " << Jakaja.Pisteet<< endl;
		Jakaja.TulostaKortit();

		cout << "\nPelaajan kortit, pisteet Yhteensa " << Juha.Pisteet<< endl;
		Juha.TulostaKortit();

		}




		//#################Nollataan lähtötilanteeseen###################

		cout << "\nIhan ";
		Juha.Odota();
		cout << "pian ";
		Juha.Odota();
		cout << "aloitetaan ";
		Juha.Odota();
		cout << "uusi ";
		Juha.Odota();
		cout << "kierros";
		Juha.Odota();
		cout << ".";
		Juha.Odota();
		Juha.Odota();
		Juha.Run = 0;
		Juha.Pisteet = 0;
		Jakaja.Pisteet = 0;
		Juha.KasiMaara = 0;
		Jakaja.KasiMaara = 0;
		Juha.Potti = 0;
		Juha.Halu = "k";
		Juha.Tarkistus = 0;

		//#################Nollataan lähtötilanteeseen###################

		

	}
	}
}
