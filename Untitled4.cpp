#include<iostream>
#include<string>
#include<fstream>
#include <Graphs>
using namespace std;
bool security(char*,char*);
void update(char*&, char*);
int main() {
	fstream fin;
	char filename[50] = "shortestpath_timevertex.txt";
	fin.open(filename);
	if (!fin) {
		cout << "Can't Open the file right now ! " << endl;
		return 0;
	}
	int maxSize = 0;
	fin >> maxSize;
	fin.close();
	char orignalusername[50] = "usamanawaz786";
	char orignalpassword[50] = "freedomfighters";
	char* ptr = orignalpassword;
	char* username=new char[50];
	char* password=new char[50];
	int choice = -1;
	bool check = true;
	Graphs g1(maxSize);
	g1.creategraph();
	do {
		system("cls");
		int index = -1;
		cout << "nnnn";
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << " ttt  -> Press 1 to Enter the Username and Password: " << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << " ttt  -> Press 2 to Updata the Username/Password: " << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << " ttt  -> Press 0 to exit the Program: " << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "ttt  >> "; cin >> index;
		switch (index) {
		case 1: {
			system("cls");
			cout << endl << endl;
			cout << "nnnn ttt  -> Please Enter the Admin username: " << endl;
			cin.ignore();
			cout << "ttt  -> "; cin.get(username, 50);
			if (security(username, orignalusername)) {}
			else {
				cout << "nn ttt  Username INCORRECT ! ";
				cin.ignore();
				cout << endl << "nnnnnnnnnnnnnnnnnnnn ttt ";
				system("PAUSE");
				continue;
			}
			system("cls");
			cout << "nnnn ttt  -> Please Enter the Admin Password: " << endl;
			cin.ignore();
			cout << "ttt  -> "; cin.get(password, 50);
			if (security(password, orignalpassword)) { check = false; break; }
			else {
				cout << "nn ttt  Password Incorret ! ";
				cout << endl << "nnnnnnnnnnnnnnnnnnnn ttt ";
				system("PAUSE");
				continue;
			}
		}
		case 2: {
			system("cls");
			cout << endl << endl;
			cout << "nnnn ttt  -> Please Enter the current Admin username: " << endl;
			cin.ignore();
			cout << "ttt  -> "; cin.get(username, 50);
			if (security(username, orignalusername)) {}
			else {
				cout << "nn ttt  Username INCORRECT ! ";
				cin.ignore();
				cout << endl << "nnnnnnnnnnnnnnnnnnnn ttt ";
				system("PAUSE");
				continue;
			}
			system("cls");
			cout << "nnnn ttt  -> Please Enter the current Admin Password: " << endl;
			cin.ignore();
			cout << "ttt  -> "; cin.get(password, 50);
			if (security(password, orignalpassword)) {
				char updatepassword[50];
				system("cls");
				cout << "nnnn ttt  -> Please Enter the new Admin Password: " << endl;
				cin.ignore();
				cout << "ttt  -> "; cin.get(updatepassword, 50);
				update(ptr, updatepassword);
				continue;
			}
			else {
				cout << "nn ttt  Password Incorret ! ";
				cout << endl << "nnnnnnnnnnnnnnnnnnnn ttt ";
				system("PAUSE");
				continue;
			}

		}
		case 0:system("cls"); cout << "nnnn ttt SEE U S00N :) "; exit(1);
		default: {
			cout << "Invalide Input!! ";
			cout << endl << "nnnnnnnnnnnnnnnnnnnn ttt ";
			system("PAUSE");
			continue;
		}
		}
	} while (check);
	do {
		system("cls");
		cout << endl << endl;
		cout << "=======================================================================================" << endl;
		cout << "|                                   OSPREY AIRWAYS                                    |" << endl;
		cout << "=======================================================================================" << endl << endl;
		//cout << "nn ttt Welcome To Flight Reservation System" << endl << endl;
		cout << "tt     <><><><><><><><><><><><><><><><><><><><><><><>n";
		cout << "tt           Welcome To Flight Reservation System             n"; 
		cout << "tt     <><><><><><><><><><><><><><><><><><><><><><><>n";
		cout << ".....................................MENU OPTIONS......................................nn";
		//cout << ".......................................................................................n";
		cout << "tt     ...............................................         " << endl;
		cout << "tt                FLIGHT SCHEDULE DATABASE ....... '1'" << endl;
		cout << "tt     ...............................................         " << endl;
		cout << "tt              PASSENGER SCHEDULE DATABASE ....... '2'" << endl;
		cout << "tt     ...............................................         " << endl;
		cout << "tt              EXIT THE PROGRAM .................. '0'" << endl;
		int a = -1;
		cout << "ttt  -> "; cin >> a;
		switch (a) {
		case 1: {
			system("cls");
			int b = -1;
			do {
				system("cls");
				cout << "nn.......................................................................................";
				cout << "tt                   LIST OF ALL CITIES SERVICED BY AIRLINE .......... '1'n";
				cout << ".......................................................................................";
				cout << "tt              LIST OF FLIGHTS DEPARTURE FOR A PARTICULAR CITY ...... '2'n";
				cout << ".......................................................................................";
				cout << "tt               LIST OF FLIGHTS ARRIVAL FOR A PARTICULAR CITY ....... '3'n";
				cout << ".......................................................................................";
				cout << "tt             LIST OF ALL CITIES REACHED FROM A PARTICULAR CITY ..... '4'n";
				cout << ".......................................................................................";
				cout << "tt          LIST OF CITIES IN THE SHORTEST PATH B/W ANY TOW CITIES...  '5'n";
				cout << ".......................................................................................";
				cout << "tt                    SHORTEST ROUTE B/2 ANY TWO CITIES..............  '6'n";
				cout << ".......................................................................................";
				cout << "tt                            EXIT THIS MODULE ......................  '0'n";
				cout << "ttt  -> "; cin >> b;
				switch (b) {
				case 1: {
					system("cls");
					cout << "nn tList of all Cities that are serviced by 'OSPREY AIRWAYS' are as follows:" << endl;
					g1.Displayservedcities();
					cout << endl << "nnnnnn ttt ";
					system("PAUSE");
					continue;
				}
				case 2: {
					system("cls");
					string cityname;
					cout << "nn t Enter the name of the city from which you want to check Departure Flights : " << endl;
					cin.ignore();
					cout << "ttt "; getline(cin, cityname);
					cout << " t List of Flight departures for "<<cityname<< endl;
					g1.Display_Departure(cityname);
					cout << endl << "nnnnnn ttt ";
					system("PAUSE");
					continue;
				}
				case 3: {
					system("cls");
					string cityname;
					cout << "nn t Enter the name of the city for which you want to chek Arrival Flights: " << endl;
					cin.ignore();
					cout << "ttt "; getline(cin, cityname);
					cout << " t List of Flight departures for " << cityname << endl;
					g1.Display_Arrival(cityname);
					cout << endl << "nnnnnn ttt ";
					system("PAUSE");
					continue;
				}
				case 4: {
					system("cls");
					string cityname;
					cout << "nn t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "ttt "; getline(cin, cityname);
					cout << " t List of all cities that can be reached from " << cityname << " are :" << endl;
					g1.toallcities(cityname);
					cout << endl << "nnnnnn ttt ";
					system("PAUSE");
					continue;
				}
				case 5: {
					system("cls");
					string sourcecity,citydestination;
					cout << "nn t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "ttt "; getline(cin, sourcecity);
					cout << "t Enter the name of the destination city: " << endl;
					cout << "ttt "; getline(cin, citydestination);
					cout << " t List of cities b/w shortest route from " << sourcecity << " to " << citydestination << " are: " << endl;
					g1.shortestpath_Destination(sourcecity, citydestination);
					cout << endl << "nnnnnn ttt ";
					system("PAUSE");
					continue;
				}
				case 6: {
					system("cls");
					string sourcecity, citydestination;
					cout << "nn t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "ttt "; getline(cin, sourcecity);
					cout << "t Enter the name of the destination city: " << endl;
					cout << "ttt "; getline(cin, citydestination);
					g1.Display_shortestpath(sourcecity, citydestination);
					cout << endl << "nnnnnn ttt ";
					system("PAUSE");
					continue; 
				}
				case 0:
					system("pause"); break;
				default: {
					cout << "Invalide Input!! ";
					cout << endl << "nnnnnnnnnnnnnnnnnnnn ttt ";
					system("PAUSE");
					continue;
				}
				}
			} while (b != 0);
			continue;
		}
		case 2: {
			system("cls");
			int b = -1;
			do {
				system("cls");
				cout << "nn.......................................................................................";
				cout << "tt                          MAKE RESERVATION ............... '1'n";
				cout << ".......................................................................................";
				cout << "tt                      PRINT RESERVATION SCHEDULE ......... '2'n";
				cout << ".......................................................................................";
				cout << "tt                         DELETE RESERVATION  ............. '3'n";
				cout << ".......................................................................................";
				cout << "tt               LIST OF PASSENGERS FOR A PARTICULAR FLIGHT  '4'n";
				cout << ".......................................................................................";
				cout << "tt                          EXIT THIS MODULE  .............. '0'n";
				cout << "ttt  -> "; cin >> b;
				switch (b) {
				case 1: {
					system("cls");
					string sourcecity, citydestination;
					cout << "nn t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "ttt "; getline(cin, sourcecity);
					cout << "t Enter the name of the destination city: " << endl;
					cout << "ttt "; getline(cin, citydestination);
					g1.getreservation(sourcecity, citydestination);
					cout << endl << "nnnnnn ttt ";
					system("PAUSE");
					continue;
				}
				case 2: {
					system("cls");
					string sourcecity, citydestination,firstname,lastname;
					cout << "nn t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "ttt "; getline(cin, sourcecity);
					cout << "t Enter the name of the destination city: " << endl;
					cout << "ttt "; getline(cin, citydestination);
					cout << "t Enter the first name of the Passenger: " << endl;
					cout << "ttt "; getline(cin, firstname);
					cout << "t Enter the last name of the Passenger : " << endl;
					cout << "ttt "; getline(cin, lastname);
					g1.DisplayPassengerDetail(sourcecity, citydestination, firstname, lastname);
					cout << endl << "nnnnnn ttt ";
					system("PAUSE");
					continue;
				}
				case 3: {
					system("cls");
					string sourcecity, citydestination, firstname, lastname;
					cout << "nn t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "ttt "; getline(cin, sourcecity);
					cout << "t Enter the name of the destination city: " << endl;
					cout << "ttt "; getline(cin, citydestination);
					cout << "t Enter the first name of the Passenger: " << endl;
					cout << "ttt "; getline(cin, firstname);
					cout << "t Enter the last name of the Passenger : " << endl;
					cout << "ttt "; getline(cin, lastname);
					g1.DeletePassenger(sourcecity, citydestination, firstname, lastname);
					cout << endl << "nnnnnn ttt ";
					system("PAUSE");
					continue;
				}
				case 4: {
					system("cls");
					string sourcecity, citydestination;
					cout << "nn t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "ttt "; getline(cin, sourcecity);
					cout << "t Enter the name of the destination city: " << endl;
					cout << "ttt "; getline(cin, citydestination);
					g1.Displaylistofpassenger(sourcecity, citydestination);
					cout << endl << "nnnnnn ttt ";
					system("PAUSE");
					continue;
				}
				case 0:
					break;
				default: {
					cout << "Invalide Input!! ";
					cout << endl << "nnnnnnnnnnnnnnnnnnnn ttt ";
					system("PAUSE");
					continue;
				}
				}
			} while (b != 0);
			continue;
		}
		case 0:system("cls"); cout << "tt SEE U S00N :)" << endl; exit(1);
			system("pause"); break;
		default: {
			cout << "Invalide Input!! ";
			cout << endl << "nnnnnnnnnnnnnnnnnnnn ttt ";
			system("PAUSE");
			continue;
		}
		}
		system("PAUSE");
	} while (choice != 0);
}
bool security(char* username,char* orignal) {
	int i = 0, flag = 0;
	while (username[i] != '' && orignal[i] != '')
	{

		if (username[i] != orignal[i])
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0 && username[i] == '' && orignal[i] == '')
		return true;
	else
		return false;
}
void update(char*& password1, char* update) {
	strcpy_s(password1, 50, update);
}