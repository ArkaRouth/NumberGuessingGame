#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include <string>
using namespace std;
void game();

// Random number from 1-100
int random() {
	mt19937_64 rand{ static_cast<mt19937_64::result_type>(chrono::steady_clock::now().time_since_epoch().count()) };
	uniform_int_distribution <int> n{ 1,100 };
	return n(rand);
}

// The Game
void game()
{
	double y;
	int x = random();

	cout << "Guess the number between 1-100: ";
	do {
		cin >> y;
		if (y > 100 or y < 1 or y!=static_cast<int>(y)) {
			system("CLS");
			cout << "Choose an integer between 1 to 100" << endl;
		}
		else if (x - y >= 30 or y - x >= 30) {
			system("CLS");
			cout << "Too Far" << endl;
		}
		else if (x - y >= 10 or y - x >= 10) {
			system("CLS");
			cout << "A bit Far" << endl;
		}
		else if (x - y >= 5 or y - x >= 5) {
			system("CLS");
			cout << "You are close,try again" << endl;
		}
		else if (x - y <= 2 or y - x <= 2) {
			system("CLS");
			cout << "You are really really close" << endl;
		}
	} while (x != y);  {
		system("CLS");
		cout << "Thats correct the number is " << y << endl;
		}

}


int main()
{
	g1:
	string re;
	game();
	cout << "Do you want to play again ? (y/n)" << endl;
	cin >> re;
	if (re == "y" or re == "Y") {
		system("CLS");
		goto g1;
	}
	else if (re == "n" or re == "N") {
		system("CLS");
		cout << "Thanks for Playing" << endl;
	}
	else{
		system("CLS");
		cout << "I guess thats a NO" << endl;
		return 0;
	}
}

