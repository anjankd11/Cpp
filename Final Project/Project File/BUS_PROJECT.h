#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>

using namespace std;


void main_menu(); // this main menu is created so that it can be called after end of use of every method to start again


class New_Bus   // class which hold information about bus
{

protected:
	                           // attributes of the class
	string bus_id;
	string driver_name;
	string start_location;
	string end_location;
	string start_time;
	string end_time;
	int  total_seats;
	int remaining_seats;
	int seat_price;
	friend ostream& operator << (ostream& os, New_Bus& B);

public:

	New_Bus(); // default constructor
	void add_bus();  //adding information about a new bus
	void show_businfo(); // displaying information of a bus
	void remove_businfo(); // removing a bus from the file

	virtual void Login() {}; // virtual function to handle polymorphism 



};
ostream& operator<<(ostream& os, New_Bus& B); // output operator overloading for bus class



class Passenger :public New_Bus   // class for passenger information, which is a child class of bus class
{
	string mpassenger_name;      //attributes for a passenger
	string *mpassenger_phone;
	string phone;
	string temp_phn;
	string mbusid_passenger, mstartloc_passenger, mendloc_passenger, mstartime_passenger;
	string passenger_user_name, passenger_password, passenger_id;
	int mseatprice_passenger, booked_seats;

public:

	void new_booking();      // to make a new booking
	void find_booking();     // to find a previously made booking
	void Login();            //to login as a passenger
	void passenger_menu();   //menu options only available for passenger



};

class admin :public New_Bus, public Passenger     // class for admin which has access to all methods of bus class and passenger class using multiple inheritence
{
	string  user_id;                             //attributes
	string  password;
	int login_error = 404;

public:
	void Login(); //login for admin
	void admin_menu();  // options available only for admin
};



















