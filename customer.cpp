#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class node
{
	public:
		string name,phone_no,pp,email,cnic,address,acc_no;
		node* next;
		node()
		{
			
		}
		
		void insert(string name , string phone_no , string pp , string email , string cnic , string address , string acc_no)
		{
			this->name=name;
			this->phone_no=phone_no;
			this->pp=pp;
			this->email=email;
			this->cnic=cnic;
			this->address=address;
			this->acc_no=acc_no;
			next = NULL;
		}
		
		node(string name , string phone_no , string pp , string email , string cnic , string address , string acc_no)
		{
			this->name=name;
			this->phone_no=phone_no;
			this->pp=pp;
			this->email=email;
			this->cnic=cnic;
			this->address=address;
			this->acc_no=acc_no;
			next = NULL;
		}
		
		void print()
		{
				cout<<"Name : "<<'\t'<< name <<endl; 
				cout<<"Pass Port No. : "<<'\t'<< pp <<endl;
				cout<<"Email - ID : "<<'\t'<< email <<endl;
				cout<<"Phone Number : "<< phone_no <<endl;
				cout<<"CNIC : "<< cnic <<endl;
				cout<<"Address : "<< address <<endl;
				cout<<"Account Number : "<< acc_no <<endl;
				cout<<endl;
		}
};
class customer
{
	public:
		node* head;
		customer()
		{
			head = NULL;
		}
		customer(node* n)
		{
			head = n;
		}
		void insert(string name , string phone_no , string pp , string email , string cnic , string address , string acc_no)
		{
			node* newnode = new node(name , phone_no , pp , email , cnic , address , acc_no);
			if(head == NULL)
			{
				head = newnode;
			}
			else
			{
				node* temp;
				temp = head;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newnode;
			}

		}
		
		void print()
		{
			node *temp;
			temp = head;
	
			while( temp != NULL)
			{
				cout<<"Name : "<<'\t'<< temp->name <<endl; 
				cout<<"Pass Port No. : "<<'\t'<< temp->pp <<endl;
				cout<<"Email - ID : "<<'\t'<< temp->email <<endl;
				cout<<"Phone Number : "<< temp->phone_no <<endl;
				cout<<"CNIC : "<< temp->cnic <<endl;
				cout<<"Address : "<< temp->address <<endl;
				cout<<"Account Number : "<< temp->acc_no <<endl;
				temp = temp ->next;
				cout<<endl;
			}
		}
	
};
int main()
{
	fstream f1;
	node obj1;

//	string name,phone_no,pp,email,cnic,address,acc_no;
//	
//        cout<<"Enter Customer Name : "<<endl;
//		getline(cin,name);
//		
//		x:
//	cout<<"Enter Customer passport NO. : "<<endl;
//	getline(cin,pp);
//	if(pp.length()!= 12)
//	{
//		cout<<"Error! passport No. should not be greater or lower than 12 digits "<<endl;
//		goto x;
//	}
//	cout<<"Enter Customer Email - ID : "<<endl;
//	getline(cin,email);
//	y:
//	cout<<"Enter Customer Phone No. : "<<endl;
//	getline(cin,phone_no);
//	if(phone_no.length()!= 11)
//	{
//		cout<<"Error! Phone No. should not be greater or lower than 11 digits "<<endl;
//		goto y;
//	}
//	z:
//	cout<<"Enter Customer CNIC  : "<<endl;
//	getline(cin,cnic);
//	if(cnic.length()!= 15)
//	{
//		cout<<"Error! CNIC should not be greater or lower than 15 digits "<<endl;
//		goto z;
//	}
//	cout<<"Enter Customer Home/Office Address  : "<<endl;
//	getline(cin,address);
//	xx:
//	cout<<"Enter Customer Account No. : "<<endl;
//	getline(cin,acc_no);
//	if(acc_no.length()!= 9)
//	{
//		cout<<"Error! Account no. should not be greater or lower than 9 digits "<<endl;
//		goto xx;
//	}
//
//	obj1.insert(name,phone_no,pp,email,cnic,address,acc_no);
//	f1.open("Customerdata.dat", ios::app | ios::binary);
//	f1.write((char*)&obj1 , sizeof(obj1));
//	f1.close();
//	system("cls");
//	cout<<endl;

ifstream f("Customerdata.dat", ios::in | ios::binary);	
	while(f.read((char*)&obj1 , sizeof(node)))
	{
		obj1.print();
	}
	
	f.close();
 	return 0;
 }