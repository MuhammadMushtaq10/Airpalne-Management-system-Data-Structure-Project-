#include<iostream>
#include<windows.h>
#include <string>
#include <conio.h>
using namespace std;

int main()
{
		cout << "\n\n\t\t\t\t\t\t\t\t    ===================== LOGIN ===================== \n\n";
	string user, pass;
	bool login = false;

	//checking username and password:
	check:
	cout << "\n\n\t\t\t\t\t\t\t\tEnter authorized Username: ";
	getchar();
	getline(cin, user);
	cout << "\n\n\t\t\t\t\t\t\t\tEnter authorized Password: ";

		for (int i = 0; i > -1; i++)
		{
			char temp;
			temp = _getch();
			if (temp != 13 && temp != 8)
			{
				_putch('*');
			}
			if (temp == 13)
			{
				break;
			}
			if (temp == 8 || temp == 127 && !pass.empty())
			{
				cout << "\b \b";
				pass.erase(pass.size() - 1);
			}
			else
				pass += temp;

		}
		cout << "\n";



	
		for (int i = 0; i < count; i++) //and here
		{
			if (user == arr[i].username && pass == arr[i].password)
			{
				login = true;
				break;
			}
		}

		if (login == true)
		{
			cout << "\n\n\t\t\t\t\t\t\t\t\tLogged in! \n";
			cout << "\n\n\t\t\t\t\t\t\t\tSessional serial number is: " << c << "\n\n\t\t\t\t\t\t\t\t\t";
			cout << "\n\n\t\t\t\t\t\t\t\t\tLoading"; Sleep(200);
			cout << "."; Sleep(200);
			cout << "."; Sleep(400);
			cout << "."; Sleep(200);
			cout << "."; Sleep(200);
			cout << "."; Sleep(200);
			Sleep(2000);
			Display(c);
		}
		else {
			Beep(1000, 600);
			cout << "\n\n\t\t\t\t\t\t\t\tInvalid login credentials, please try again! \n";
			user = "";
			pass = "";
			goto check;
		}
	
}
}	
