#include <iostream>
#include <fstream>

using namespace std;

class Shopping
{
private:
// p stands for product
	int pcode;
	float price;
	float dis;
	string pname;
	
public:
	void menu();
	void administrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();
};

void Shopping :: menu()
{
	m:
	int choice; 
	string email;
	string password;
	
	cout << "\t\t\t\t_____________________________\n";
	cout << "\t\t\t\t                             \n";
	cout << "\t\t\t\t    Supermarket Main Menu    \n";
	cout << "\t\t\t\t                             \n";
	cout << "\t\t\t\t_____________________________\n";
	cout << "\t\t\t\t                             \n";
	cout << "\t\t\t\t    1)Administrator          \n";
	cout << "\t\t\t\t                             \n";
	cout << "\t\t\t\t    2) Buyer                 \n";
	cout << "\t\t\t\t                             \n";
	cout << "\t\t\t\t    3) Exit                  \n";
	cout << "\t\t\t\t                             \n";
	cout << "\n\t\t\t Please Select: ";
	cin >> choice;
	
	
	switch(choice)
	{
		case 1:
			cout << "\t\t\t\t  Please Login  \n";
			cout << "\t\t\t\t  Enter Email: ";
			cin >> email;
			cout << "\t\t\t\t  Enter Password: ";
			cin >> password;
			
			if(email == "admin" && password == "admin")
			{
				administrator();
			}	
			else
			{
				cout << "\nInvalid Email/Password";		
			}
			break;	
			
		case 2:
		{
			buyer();
		}
		
		case 3:
		{
			exit(0);
		}
		
		default:
		{
			cout << "Please select from the given options "; 
		}
   }
   
   goto m;
}


void Shopping :: administrator()
{
	m:
	int choice;
	cout << "\n\n\n\t\t\t  Administrator Menu";
	cout << "\n\t\t\t|____1). Add the Product _____|";
	cout << "                                      |";
	cout << "\n\t\t\t|____2). Modify the Product __|";
	cout << "                                      |";
	cout << "\n\t\t\t|____3). Delete the Product __|";
	cout << "                                      |";
	cout << "\n\t\t\t|____4). Back to Main Menu ___|";
	
	cout << "\n\t\t Please enter your choice: ";
	cin >> choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
			
		case 2:
 			edit();
			break;
			
		case 3:
			rem();
			break;
			
		case 4:
			menu();
			break;
		
		default:
			cout << "Invalid Choice";
	}
	goto m;
}

void Shopping :: buyer()
{
	
	int choice;
	cout << "\t\t\t Buyer \n";
	cout << "\t\t\t________________\n";
	cout << "                      \n";
	cout << "\t\t\t 1) Buy Product \n";
	cout << "                      \n";
	cout << "\t\t\t 2) Go back     \n";
	cout << "                      \n";
	cout << " Enter your choice: ";
	cin >> choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		
		case 2:
			menu();
			break;
			
		default:
			cout << "Invalid Choice";
	}
}

void Shopping :: add()
{
	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;
	cout << "\n\n\t\t\t  Add new product";
	cout << "\n\n\t Product code of the product: ";
	cin >> pcode;
	cout << "\n\n\t Name of the product: ";
	cin >> pname;
	cout << "\n\n\t Price of the product: ";
	cin >> price;
	cout << "\n\n\t Discount the product: ";
	cin >> dis;
	
	data.open("database.txt", ios::in);

	if(!data)
	{
		data.open("database.txt", ios::app|ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	}
	else
	{
		data >> c >> n >> p >> d;
		while(!data.eof())
		{
			if(c == pcode)
			{
				token ++;
			}
			data >> c >> n >> p >> d;
		}
		
		data.close();
	}
	if(token == 1)
	{
		goto m;
	}
	else
	{
		data.open("database.txt", ios::app|ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
		data.close();
	} 
	cout << "\n\n\t\tRecord Inserted ! ";
} 

void Shopping :: edit()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	int c;
	int p;
	int d;
	string n;
	
	cout << "\n\t\t\t Modify the record";
	cout << "\n\t\t\t Product code : ";
	cin >> pkey;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout << "\n\nFile does not exist! ";
	}
	else
	{
		data1.open("database1.txt", ios::app|ios::out);
		
		data >> pcode >> pname >> price >> dis;
		while(!data.eof())
		{
			if(pkey == pcode)
			{
				cout << "\n\t\t Product new code: ";
				cin >> c;
				cout << "\n\t\t Name of the product: ";
				cin >> n;
				cout << "\n\t\t Price: ";
				cin >> p;
				cout << "\n\t\t Discount: ";
				cin >> d;
				
				data1 << " " << c << " " << n << " " << p << " " << d << "\n";
				cout << "\n\n\t\t Record Edited";
				
				token ++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token == 0)
		{
			cout << "\n\n Record not found sorry!";
		}
	}
}

void Shopping :: rem()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	
	cout << "\n\t\t\t Delete Product";
	cout << "\n\t\t\t Product code : ";
	cin >> pkey;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout << "\n\nFile does not exist! ";
	}
	else
	{
		data1.open("database1.txt", ios::app|ios::out);
		
		data >> pcode >> pname >> price >> dis;
		while(!data.eof())
		{
			if(pkey == pcode)
			{
				cout << "\n\t\t Product deleted sucessfully";
			
				token ++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token == 0)
		{
			cout << "\n\n Record not found sorry!";
		}
	}
}

void Shopping :: list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n|________________________________________\n";
	cout << "No\t\tName\t\t\tPrice";
	cout << "\n\n|________________________________________\n";
	data >> pcode >> pname >> price >> dis;
	
	while(!data.eof())
	{
		cout << pcode << "\t\t"<< pname << "\t\t" << price << "\n";
		data >> pcode >> pname >> price >> dis;
	}
	
	data.close();
}


void Shopping :: receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;
	
	cout << "\n\n\t\t\t\t RECEIPT ";
	data.open("database.txt", ios::in);
	
	if(!data)
	{
		cout << "\n\n Empty database";
	}
	else
	{
		data.close();
		
		list();
		cout << "\n________________________________________\n";
		cout << "\n                                        \n";
		cout << "\n         Please place the order         \n";
		cout << "\n                                        \n";
		cout << "\n________________________________________\n";
		
		do 
		{
			m:
			cout << "\n\nEnter Product code: ";
			cin >> arrc[c];
			cout << "\n\nEnter Product quantity: ";
			cin >> arrq[c];
			
			for (int i = 0; i < c; i++)
			{
				if(arrc[c] == arrc[i])
				{
					cout << "\n\n Duplicate product code. Please try again!";
					goto m;
				}
			}
			c++;
			cout << "\n\n Do you want to buy another product? If yes then press y else n: ";
			cin >> choice;
		}
		while(choice == 'y');

		cout << "\n\n\t\t\t_____________RECEIPT______________\n";
		cout << "\nProduct No\t Product Name\t Product Quantity\t Price\t Amount\t Amount with discount\n";
			
		for (int i = 0; i < c; i++)
		{
			data.open("database.txt", ios::in);
			data >> pcode >> pname >> price >> dis;
			while (!data.eof())
			{
				if(pcode == arrc[i])
				{
					amount = price * arrq[i];
					dis = amount - (amount * dis / 100);
					total = total + dis;
					cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
				}
				data >> pcode >> pname >> price >> dis;
			}
			data.close();
		}
		data.close();
	}
	cout << "\n\n______________________________________";
	cout << "\nTotal amount : " << total ;
}

int main(int argc, char **argv)
{
	Shopping s;
	s.menu();
}