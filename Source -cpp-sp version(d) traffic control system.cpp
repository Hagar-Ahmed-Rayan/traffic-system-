#include<iostream>

#include <string>

#include <stdio.h>

using namespace std;
struct Date 
{

	int day;
	int month;
	int year;

};

struct Fines { //fines for each driver
	float money;//value of fine
	string name_of_street;
	Date date;
	string status;
	
};

struct TRUCK {
	int num_of_cars;
	string plate_num;
	int  model;
	Fines fines[5] = {};
	int year_of_pro;

} ;

struct driver {
	long long licence_num;
	string name_of_driver;
	Date date;
	TRUCK t[3]; //max 3 cars
	int carrr;//number of cars user select
	int enter;//value of new entered violation saved in it
	string last;//plate number  saved in it
	float sum;//sum of all unpaid violations
	int fin; //num of fines that user select
	int num_o_drivers;//number of drivers user select
	int M;//index of name of driver saved in it 
	string num;
	
}user[10], use;


void entr_user_information (int st) {//function to enter all users information

	for (int i = st; i <=use.num_o_drivers; i++)
	{
		cout << "******************************************************************************************************************" << endl;
	
		cout << "enter user information of" << i << endl;
		cin.ignore();
		cout << "Enter user name" << endl; getline(cin,user[i].name_of_driver);
		
		cout << "enter licen num" << endl; cin >> user[i].licence_num;
		cout << "enter driver dob   d/m/y" << endl; cin >> user[i].date.day >> user[i].date.month >> user[i].date.year;
		 
		cout << "enter num of cars you own _max 3" << endl; cin >> user[i].carrr;
		if (user[i].carrr > 3) {
			cout << "invalid" << endl;
			break;
		}
		for (int j = 0; j < user[i].carrr; j++)
		{
			cout << "enter car platte num" << j + 1 << endl; cin >> user[i].t[j].plate_num;
			cout << "enter  car model" << j + 1 << endl; cin >> user[i].t[j].model;
		cout << "enter car year of production" << j + 1 << endl; cin >> user[i].t[j].year_of_pro;
		cout << "enter no of fines recorded" << j + 1 << endl; cin >> user[i].fin;
		
		for (int k = 1; k <= user[i].fin; k++) {
				cout << "enter fines on car " << j + 1 << endl; cin >> user[i].t[j].fines[k].money;
				cout << "name of street happend " << j + 1 << endl; cin >> user[i].t[j].fines[k].name_of_street;
				cout << "status of fines:(paid/unpaid) " << k << endl; cin >> user[i].t[j].fines[k].status;
				cout << "date of fines " << k<< endl; cin >> user[i].t[j].fines[k].date.day>> user[i].t[j].fines[k].date.month>> user[i].t[j].fines[k].date.year;

			}
		
		}

	}

}


void record_first_time (){//function to record for the first time
	
	use.num_o_drivers++;
	entr_user_information (use.num_o_drivers);
	
}

void intro ()//apperar only in the first time
{
	cout << "\n\n\n\t  TRAFFIC";
	cout << "\n\n\tCONTROL";
	cout << "\n\n\t  SYSTEM";
	cin.get();
}

void violation_calculation (string plate) {//calculate violation 
	int car_actual_speed;
  #define street_speed 15//in km/s
	int value;//value of  new entered violation
	string n_o_st;//name of street
	int d, m, y;//day&month&year  
	bool ex = false;//return true if plate number exsist

	for (int i = 1; i <= use.num_o_drivers; i++)//fi hena 7aga m4 mazbota
		for (int j = 0; j < user[i].carrr; j++)
		{
			{
				if (plate == user[i].t[j].plate_num) {

					cout << "valid" << endl;
					user[i].fin++;

					
					use.last = plate;
					

					ex = true;
					break;

				}


			}
		}


	if (ex == true) {

		cout << "Enter car speed in Km/h   >15 km/h " << endl; cin >> car_actual_speed;
		if (car_actual_speed > street_speed) {
			value = abs(street_speed - car_actual_speed) * 2;
			cout << "name of street happend" << endl; cin >> n_o_st;
			cout << "date of happen" << endl; cin >> d >> m >> y;
			
			for (int i = 1; i <= use.num_o_drivers; i++) {
				for (int j = 0; j < user[i].carrr; j++)
				{

					if (use.last == user[i].t[j].plate_num) {

							user[i].t[j].fines[user[i].fin].money = value;
							user[i].t[j].fines[user[i].fin].name_of_street = n_o_st;
							user[i].t[j].fines[user[i].fin].date.day = d;
							user[i].t[j].fines[user[i].fin].date.month = m;
							user[i].t[j].fines[user[i].fin].date.year = y;
							user[i].t[j].fines[user[i].fin].status = "unpaid";
						
					}

				}
			}

			cout << "violation recorded successfully" << endl;
			cout << " you have valuation =" << " " << value << endl;

			use.enter = 0;
			use.enter = use.enter + value;
			

		}
		else 
			cout << "you don't have violation" << endl;
		
	}

	else if (ex == false)          
		cout << "invalid" << endl;



}

void which (string p) {//if user choose to search with plate number
	int  a;//fine that driver select to pay
	bool true_plate = false;
	for (int i = 1; i <= use.num_o_drivers; i++) {

		for (int j = 0; j < user[i].carrr; j++)
		{
			use.sum = 0;
			if (p == user[i].t[j].plate_num)
			{
				use.num = p;
			
				

				cout << "___________________________________________" << endl;

				cout << "driver name:" << i << ": " << user[i].name_of_driver << endl;
				cout << "licence_num:" << user[i].licence_num << endl;
				cout << "driver_date:" << user[i].date.day << "/" << user[i].date.month << "/" << user[i].date.year << endl;//here
				cout << " number of cars" << ":" << user[i].carrr << endl;
				cout << "___________________________________________" << endl;
				cout << " car model" << j + 1 << ":" << user[i].t[j].model << endl;
				cout << "plate number" << j + 1 << ":" << user[i].t[j].plate_num << endl;
				cout << " car yofp" << j + 1 << ":" << user[i].t[j].year_of_pro << endl;

				cout << "___________________________________________" << endl;
			    	for (int k = 1; k <= user[i].fin; k++)
				    {
					cout << " fines on car " << j + 1 << ":" << user[i].t[j].fines[k].money << " " << "|";
					cout << "name of st happend :" << j + 1 << user[i].t[j].fines[k].name_of_street << " " << "|";
					cout << "status of fines " << j + 1 << user[i].t[j].fines[k].status << " " << "|";
					cout << "date of fines " << j + 1 << user[i].t[j].fines[k].date.day << "/" << user[i].t[j].fines[k].date.month << "/" << user[i].t[j].fines[k].date.year << endl;

				     }
				
				     for (int k = 1; k <= user[i].fin; k++)
				      {
					     if (user[i].t[j].fines[k].status == "unpaid")
					       {

						  use.sum = use.sum + user[i].t[j].fines[k].money;

					     }
				     }

				cout << "total unpaid=" << " " << use.sum << endl;
				cout << "whih violation do you want to pay" << endl;

				cin >> a;
				for (int k = 1; k <= user[i].fin; k++) {
					if (a == user[i].t[j].fines[k].money) {
						user[i].t[j].fines[k].status = "paid";
						use.sum = use.sum - user[i].t[j].fines[k].money;
						cout << "total unpaid=" << use.sum << endl;
						cout << " fines on car " << j+1 << ":" << user[i].t[j].fines[k].money;
						cout << "status of fines " << k + 1 << ":" << user[i].t[j].fines[k].status << endl;
						
					}
				}

			}
			
			     
		}


	}
	if (p != use.num)
		cout << "invalid";

}


void name_of_driver (string chose) {//if user choose to search with driver name
	int A;//fines intered
	string pl;//plate number do you want to pay
	bool d = false;//return true if driver name is exsist
	for (int i = 1; i <= use.num_o_drivers; i++)
	{
		if (chose == user[i].name_of_driver) {
			use.M = i;
			d = true;
			break;
		}
	}
	if (d == true)
	{
		
		  int i = use.M;
				
				cout << "_______________" << endl;
				
				cout << "driver name:" << " " << i << " " << user[i].name_of_driver << endl;
				cout << "licence_num:" << user[i].licence_num << endl;
				cout << "driver_date:" << user[i].date.day << "/" << user[i].date.month << "/" << user[i].date.year << endl;//here
				for (int j = 0; j < user[i].carrr; j++) {
					cout << "_______________" << endl;
					cout << " car model" << " " << j + 1 << ":" << user[i].t[j].model << endl;
					cout << "plate number" << " " << j + 1 << ":" << user[i].t[j].plate_num << endl;
					cout << " car yofp" << " " << j + 1 << ":" << user[i].t[j].year_of_pro << endl;

					for (int k = 1; k <= user[i].fin; k++)
					{
						cout << " fines on car " << " " << j + 1 << ":" << user[i].t[j].fines[k].money << " " << "|";
						cout << "name of st happend " << k << ":" << user[i].t[j].fines[k].name_of_street << " " << "|";
						cout << "status of fines " << k << ":" << user[i].t[j].fines[k].status << " " << "|";
						cout << "date of fines " << k << ":" << user[i].t[j].fines[k].date.day << "/" << user[i].t[j].fines[k].date.month << "/" << user[i].t[j].fines[k].date.year << endl;

					}


				}

				if (user[i].carrr > 1)
				{
					
					cout << "which plate num do you want to pay" << endl;
					cin >> pl;
					cout << "_______________" << endl;
					which(pl);

				}
				else if (user[i].carrr == 1)
				{
					
					for (int j = 0; j < user[i].carrr; j++){
					
				 
					   for (int k = 1; k <= user[i].fin; k++)
				    { 
						       if (user[i].t[j].fines[k].status == "unpaid")
						        {

							      use.sum = use.sum + user[i].t[j].fines[k].money;

						       }
					}

				    	cout << "total unpaid=" << " " << use.sum << endl;
					   cout << "whih violation do you want to pay" << endl;
					  cin >> A;
					  for (int k = 1; k <= user[i].fin ; k++) {
						if (A == user[i].t[j].fines[k].money) {
							user[i].t[j].fines[k].status = "paid";
							use.sum = use.sum - user[i].t[j].fines[k].money;
							cout << "total unpaid=" << use.sum << endl;
							cout << " fines on car " << j+1 << ":" << user[i].t[j].fines[k].money;
							cout << "status of fines " << k  << ":" << user[i].t[j].fines[k].status << endl;
							
						}

					}
					

			    }
			
		}
	}

	else if (d == false) 
	cout << "invalid name this user is not exist " << endl;
	
		

		}

	int main () {
		string p;
		use.sum = 0;//sum of all unpaid fines
		string chose;//name chosen to know its violations
		char c;//chose from menue
		int start = 1;//start index in i
		intro();
		cout << "enter num of drivers do you want to record " << endl; cin >> use.num_o_drivers;
		entr_user_information(start);
		string plate;
		do
		{
			cout << "\n\n\n\tMAIN MENU";
			cout << "\n\n\t01. RECORD VIOLATION";//POLICE
			cout << "\n\n\t02. PAY VIOLATION";//USER
			cout << "\n\n\t03. FIRST RECORDED";//USER
			cout << "\n\n\t04. EXIT";
			cout << "\n\n\tSelect Your Option (1-3) ";
			cin >> c;
		
		string ch;
		switch (c)
		{
			
		case '1' :	
			 cout << "enter plate num" << endl; cin >> plate;
			violation_calculation(plate); //record violation

			break;
		case '2' :
			int che;//plate num or username
			cout << "enter driver name or truck plate num to know your violations" << endl;
			cout << "chosse 1 for plate num &2 for name of driver" << endl;
			cin >> che;
			if (che == 1) {
				cout << "enter plate num" << endl;
				cin >> p;
				which (p);
			}
			else if (che ==2) {
				cout << "enter yourname" << endl;
				cin.ignore();
				getline (cin, chose);		//cin >> chose;
				name_of_driver (chose);
			
			}
			
			break;

		case'3' :
			record_first_time();
				break;

		case '4' :
			break;
			break;
		
		default:cout << "\a";
			
     	}
		cin.ignore();
		cin.get();


	    }while (c!= '4');

		return 0;
	}
