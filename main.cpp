#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

void Fermat(int a, vector<int> &fac)
{
	while (a % 2 == 0)
	{
		a = a / 2;
		fac.push_back(2);
	}

	int y, yy, a1, a2;
	int x = (int)ceil(sqrt(a));
	while (x < (a + 1) / 2)
	{
		yy = x * x - a;
		y = floor(sqrt(yy));
		if (yy == y * y)
		{
			a1 = x - y;
			a2 = x + y;
			if (a1 == 1 || a2 == 1)
			{
				break;
			}
			Fermat(a1, fac);
			Fermat(a2, fac);
			return;
		}
		x++;
	}
	fac.push_back(a);
}



int Mod(int a, long long int b, int c) {

	auto r = a;
	for (long long int i = 1; i < b; i++)
	{
		r = (r*a) % c;
	}
	return r;
}
int ModOdwr(int a, int b){

	int c, d, e, f, g;
	c = 1; d = a;
	e = 0; f = b;

	while (d){

		if (d < f){

			g = c; c = e; e = g;
			g = d; d = f; f = g;
		}

		g = d/f;
		c -= g*e;
		d -= g*f;
	}

	if (f == 1){

		if (e < 0) {
			e += b;
		}
		return e;
	}
}

bool isMod(int g, int q, int p)

{
	for (int i = q-1; i > 1; i--)
	{
		if (Mod(g, i, p) == 1) {
			return false;
		}
	}

	if (Mod(g, q, p) == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool isPrime(int number) {
	if (number < 2) return false;
	if (number == 2) return true;
	if (number % 2 == 0) return false;
	for (int i = 3; (i*i) <= number; i += 2) {
		if (number % i == 0) return false;
	}
	return true;

}

int n1(vector <char> &text) {
	int licznik_n1 = 0;
	for (int i = 0; i < text.size(); i++) {
		switch (text[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			licznik_n1++;
		}
	}
	return licznik_n1;
}

int n2(vector <char> &text) {
	int licznik_n2 = 0;
	for (int i = 0; i < text.size(); i++) {
		switch (text[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case ' ':
			break;
		default:
			licznik_n2++;
		}
	}
	return licznik_n2;
}
int SP(vector <char> &text) {
	int licznik_sp = 0;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ' ') {
			licznik_sp++;
		}
	}
	return licznik_sp;

}
int JHA(vector <char> &text, int p, int q) {
	int wynik = Mod(q, 7 * n1(text) - 3 * n2(text) + pow(SP(text), 2), p);
		return wynik;
}
void PRK(int g, int k, int p, int q) {

	cout << "\nPRK: (" << Mod(g, k, p) << ", " << g << ", " << p << ", " << q << ")";
}

void DSS(int g, int p, int q, int k, int r, int jha) {
	int x, y = 0;
	x = Mod(g, k, p) % q;
	y = (ModOdwr(r, q)*Mod( jha + (k * x), 1, q))%q ;
	cout << "\nDSS: (" << x << ", " << y << ")\n";

}

int main() {
	
	int p, g;
	/*
//TEKST D£UGI
	cout << "Podaj p: ";

	do {
		cin >> p;
		if (p >= 32000) cout << "Poddaj p<32000\nWpisz ponownie\n";
		if (!isPrime(p)) cout << "p nie jest liczba pierwsza\nWpisz ponownie\n" << endl;
	} while (p >= 32000 || !isPrime(p));

	vector <char> text;
	char c;
	fstream fin("text.txt", fstream::in);
	while (fin >> noskipws >> c) {
		text.push_back(c);
	}
	for (int i = 0; i < text.size(); i++) { cout << text[i] << ""; }
	cout << "\nn1: " << n1(text) << "\nn2: " << n2(text) << "\nsp: " << SP(text) << endl;

	int q = 0;
	vector<int> wynik;
	Fermat(p - 1, wynik);
	int s = wynik.size();
	sort(wynik.begin(), wynik.end());
	q = wynik[s - 1];
	cout << "\nq: " << q << endl;

	cout << "\nPodaj g: ";
	do {
		cin >> g;
		if (g < 0) cout << "\ng musi byæ liczb¹ dodatni¹\nWpisz ponownie\n";
		if (!isMod(g, q, p)) cout << "\ng nie jest q-tym pierwiastkiem modulo p\nWpisz ponownie\n";
	} while (g < 0 || !isMod(g, q, p));

	int jha = 0;
	jha = JHA(text, p, q);
	cout << "\nJHA: " << jha;

	int k, r;
	cout << "\nPodaj k: ";
	do {
		cin >> k;
		if (k > q) cout << "\nk musi byæ mniejsze od q\nWpisz ponownie\n";
	} while (k > q);

	cout << "\nPodaj r: ";
	do {
		cin >> r;
		if (r > q) cout << "\nr musi byæ mniejsze od q\nWpisz ponownie\n";
	} while (r > q);

	PRK(g, k, p, q);
	DSS(g, p, q, k, r, jha);
	*/
//TEST DLA K2
//K2

	cout << "Podaj p: ";
	
	do {
		cin >> p;
		if (p >= 32000) cout << "Poddaj p<32000\nWpisz ponownie\n";
		if (!isPrime(p)) cout << "p nie jest liczba pierwsza\nWpisz ponownie\n" << endl;
	} while (p >= 32000 || !isPrime(p));

	vector <char> text_k2;
	char c_k2;
	fstream fin_k2("text_k2.txt", fstream::in);
	while (fin_k2 >> noskipws >> c_k2) {
		text_k2.push_back(c_k2);
	}
	for (int i = 0; i < text_k2.size(); i++) { cout << text_k2[i] << ""; }
	cout << "\nn1: " << n1(text_k2) << "\nn2: " << n2(text_k2) << "\nsp: " << SP(text_k2) << endl;
	
	int q = 0;
	vector<int> wynik;
	Fermat(p - 1, wynik);
	int s = wynik.size();
	sort(wynik.begin(), wynik.end());
	q = wynik[s - 1];
	cout << "\nq: " << q << endl;

	cout << "\nPodaj g: ";
	do {
		cin >> g;
		if (g < 0) cout << "\ng musi byæ liczb¹ dodatni¹\nWpisz ponownie\n";
		if (!isMod(g, q, p)) cout << "\ng nie jest q-tym pierwiastkiem modulo p\nWpisz ponownie\n";
	} while (g < 0 || !isMod(g, q, p));

	int jha = 0;
	jha = JHA(text_k2, p, q);
	cout << "\nJHA: " << jha;

	int k, r;
	cout << "\nPodaj k: ";
	do {
		cin >> k;
		if (k > q) cout << "\nk musi byæ mniejsze od q\nWpisz ponownie\n";
	} while (k > q);

	cout << "\nPodaj r: ";
	do {
		cin >> r;
		if (r > q) cout << "\nr musi byæ mniejsze od q\nWpisz ponownie\n";
	} while (r > q);

	PRK(g, k, p, q);
	DSS(g, p, q, k, r, jha);

	
	system("pause");
	return 0;
}