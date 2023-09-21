#include <iostream>
#include <vector>
#include <fstream>
#include <string> 
#include "Actors.h"
#include "Movies.h"
#include "letmeinpls.h"
using namespace std;





int pagingint = 0;
fstream myfile;


void Program::inputerUI() {
	cout << "\n                                          Choose a number";
	cout << "\n                                          ---------------";
	cout << "\n                                                  ";
}

void Program::UI(bool checker) {
	if (pagingint == 0) {

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n-----------------------------------------------------------------------------------------------------------" << endl;
		cout << "                                    Welcome random human being" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------\n" << endl;

	}
	else if (pagingint == 1) {

		cout << "------------------------------------------------------------------------------------------------------" << endl;
		cout << "                    [1]Movies               [2]Actors               [0]Next Page" << endl;
		cout << "------------------------------------------------------------------------------------------------------\n\n" << endl;

		if (checker == true) {
			cout << "                                         Successfully added!" << endl;
		}
	}
	else if (pagingint == 2) {

		cout << "------------------------------------------------------------------------------------------------------" << endl;
		cout << "                    [1]Back                 [2]Delete               [0]Exit" << endl;
		cout << "------------------------------------------------------------------------------------------------------\n\n" << endl;
	}
	else if (pagingint == 3) {
		cout << "------------------------------------------------------------------------------------------------------" << endl;
		cout << "                                     Which one do you want to delete?" << endl;
		cout << "------------------------------------------------------------------------------------------------------\n\n" << endl;
	}
}


void Program::Code() {

	vector <Movie> Movies;
	vector <Actor> Actors;
	vector <string> array = { {1}, };
	bool check = false;

	/* Reading the file */
	myfile.open("saver.txt", ios::in);


	/* Greeting */
	UI(check);
	string con;
	getline(cin, con);
	pagingint = 1;


	/* Starting Question */
	do
	{
		system("CLS");
		UI(check);

		inputerUI();

		string ant;
		getline(cin, ant);
		check = false;

		try
		{
			/* Movie Choice */
			if (stoi(ant) == 1) {

				system("CLS");
				UI(check);
				Movie ans;
				cout << "					Movie: ";
				getline(cin, ans.name);
				cout << "					Published: ";
				getline(cin, ans.publishyear);
				cout << "					Genre: ";
				getline(cin, ans.genre);
				Movies.push_back(ans);

				int k;
				for (int i = 0; i < Movies.size(); i++) {
					k = i;
				}
				int i = 0;
				i++;
				array.push_back("Movie: " 
					+ Movies[k].name + "\nPublished: " 
					+ Movies[k].publishyear + "\nGenre: " 
					+ Movies[k].genre + "\n");


				if (i == 1)
				{
					check = true;
					i = 0;
				}
			}

			/* Actor Choice */
			else if (stoi(ant) == 2) {
				system("CLS");
				UI(check);
				Actor ans;
				cout << "					Actor: ";
				getline(cin, ans.name);
				cout << "					Age: ";
				getline(cin, ans.age);
				cout << "					Nationality: ";
				getline(cin, ans.nationality);
				Actors.push_back(ans);

				int k;
				for (int i = 0; i < Actors.size(); i++) {
					k = i;
				}

				int i = 0;
				i++;
				array.push_back("Actor: " + Actors[k].name 
					+ "\nAge: " + Actors[k].age 
					+ "\nNationality: " 
					+ Actors[k].nationality + "\n");


				if (i == 1)
				{
					check = true;
					i = 0;
				}
			}

			/* Next Page */
			else if (stoi(ant) == 0) {
				system("CLS");
				pagingint = 2;
				UI(check);
				pagingint = 1;
				
				for (int i = 1; i < array.size(); i++) {

					cout << "\n" << i << ". \n" << array[i]  << endl;

				}


				/* Option checker*/
				inputerUI();
				string anse;
				getline(cin, anse);


				/* Going back to first page */
				if (stoi(anse) == 1) {

				}


				/* Deleter */
				else if (stoi(anse) == 2) {

					system("CLS");
					pagingint = 3;
					UI(check);
					int k;
					for (int i = 1; i < array.size(); i++) {

						cout << "\n" << i << ". \n" << array[i] << endl << endl;

						k = i;
					}
					int ans;
					inputerUI();
					cin >> ans;

					array.erase(array.begin() + ans);
				}


				/* Exit */
				else if (stoi(anse) == 0) {
					myfile.open("saver.txt", ios_base::out);


					if (myfile.is_open()) {

						for (int i = 1; i < array.size(); i++) {

							myfile << array[i] << endl << "----------------------------" << endl;
						}
						myfile.close();
						break;
					}
					else {
						cout << "ERROR: file corrupted";
					}

				}
				pagingint = 1;
			}
		}
		catch (const std::exception&)
		{
			system("CLS");
			cout << "ERROR: Input must be a number!" << endl;
		}

	} while (true);

}