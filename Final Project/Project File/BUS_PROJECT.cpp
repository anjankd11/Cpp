#include "BUS_PROJECT.h"


void main_menu()  //the first window that will be displayed 
{
	int choice;
	New_Bus B;
	Passenger p1;
	admin a1;

	cout << "\n\n\n\n\n\n";

	cout << "                                       ______________WELCOME TO ANJAN TRANSPORT AND CO. _______________" << endl;
	cout << " Press 1 to Enter without Login" << endl;
	cout << " Press 2 to Enter with login info or create a new account" << endl;
	cout << " Pres 3 to EXIT" << endl;
	cout << " Enter Your Choice:  ";

	cout << endl << endl << endl << endl << endl << endl << endl << endl << "                                                  Press 5 for admin login" << endl;


	cin >> choice;


	switch (choice)
	{

	case 1:
		p1.passenger_menu(); // showing passenger menu
		break;

	case 2:
		p1.Login();       //passenger login
		break;
	case 3:
		exit(0);
	case 5:
		a1.Login();      //admin login

	default:
		cout << "\n Invalid choice";


	}
	_getch();

}

ostream& operator<<(ostream& os, New_Bus& B)  // output operator overloading for bus class
{
	os << "BUS ID:" << B.bus_id << endl << "Driver name:" << B.driver_name << endl << "Start Location:" << B.start_location << endl << "End Location:" << B.end_location
		<< endl << "Start Time:" << B.start_time << endl << "End Time:" << B.end_time << endl << "Total Seats:" << B.total_seats << endl << "Remaining Seats:" << B.remaining_seats << endl
		<< "Seat Price:" << B.seat_price << endl;
	return os;
}

New_Bus::New_Bus()  //default constructor for bus class
{

	bus_id = "0";
	driver_name = "UNKNOWN";
	start_location = "BUDAPEST";
	end_location = "BUDAPEST";
	start_time = "08:00 am";
	end_time = "08:00 am";
	total_seats = 50;
	remaining_seats = 50;
	seat_price = 5000;
}

void New_Bus::add_bus() {  ////adding information about a new bus

Start:

	system("cls");

	fstream bus_file;  // for file handling

	int count = 0;   //variable to check if a bus with same id exist already
	string tempbus_id; //setting temporary variables to check information from file
	string tempdriver_name;
	string tempstart_location;
	string tempend_location;
	string tempstart_time;
	string tempend_time;
	int temptotal_seats;
	int tempremaining_seats;
	int tempseat_price;

	cout << "\n\n\t___________Adding a new bus___________"; //taking input for for a bus
	cout << "\n\n Bus id: ";
	cin >> bus_id;
	cout << "\n\n Driver Name: ";
	cin >> driver_name;
	cout << "\n\n Start Location: ";
	cin >> start_location;
	cout << "\n\n End Location: ";
	cin >> end_location;
	cout << "\n\n Start Time: ";
	cin >> start_time;
	cout << "\n\n End Time: ";
	cin >> end_time;
	cout << "\n\n Total Seats: ";
	cin >> total_seats;
	cout << "\n\n Remaining Seats: ";
	cin >> remaining_seats;
	cout << "\n\n Seat Price: ";
	cin >> seat_price;

	bus_file.open("BUS.txt", ios::in); //first openning the file to check if same bus exists

	if (!bus_file) { //if no file found 

		bus_file.open("BUS.txt", ios::app | ios::out); //then creating a file
		bus_file << bus_id << " " << driver_name << " " << start_location << " " << end_location << " " // putting the information in file
			<< start_time << " " << end_time << " " << total_seats << " " << remaining_seats << " " << seat_price << endl;
		bus_file.close(); //closing the file
	}
	else // if file found
	{
		bus_file >> tempbus_id >> tempdriver_name >> tempstart_location >> tempend_location >> // checking the information in file if same bus exists
			tempstart_time >> tempend_time >> temptotal_seats >> tempremaining_seats >> tempseat_price;

		while (!bus_file.eof())//read until eof=end of file
		{
			if (bus_id == tempbus_id) // if exists 
			{

				count = count + 1;  // increase count
			}
			bus_file >> tempbus_id >> tempdriver_name >> tempstart_location >> tempend_location >>
				tempstart_time >> tempend_time >> temptotal_seats >> tempremaining_seats >> tempseat_price;
		}
		bus_file.close();
		if (count == 0) // if does not exist, then count did not increase 
		{
			bus_file.open("BUS.txt", ios::app | ios::out);  //so making a new file
			bus_file << bus_id << " " << driver_name << " " << start_location << " " << end_location << " "  // writing in the file
				<< start_time << " " << end_time << " " << total_seats << " " << remaining_seats << " " << seat_price << endl;
			bus_file.close();
		}
		else
		{
			cout << "Bus already exisits!!!" << endl;
			_getch();
			goto Start;
		}
	}
	cout << "New Bus information is added!!!" << endl;

	cout << "Press enter to continue!";
	_getch();
	system("cls");
	main_menu();




}

void New_Bus::show_businfo()  // displaying information of a existing bus
{
	system("cls");


	string temp_endlocation; // temporary variable to check the destination is same or not
	fstream bus_file;
	int count = 0;

	cout << "_______________BUS INFORMATION____________" << endl;
	bus_file.open("BUS.txt", ios::in | ios::binary);
	if (!bus_file)
	{
		cout<< "FILE ERROR";                         // if file not found thenn throw an error
	}
	else
	{
		cout << "Enter your destination: ";  // taling destination from the passenger
		cin >> temp_endlocation;

		bus_file >> bus_id >> driver_name >> start_location >> end_location >>  //reading the file 
			start_time >> end_time >> total_seats >> remaining_seats >> seat_price;

		while (!bus_file.eof())
		{



			if (end_location == temp_endlocation)  // if bus with same destination found then print
			{
				cout << "BUS ID:" << bus_id << endl << "Driver name:" << driver_name << endl << "Start Location:" << start_location << endl << "End Location:" << end_location
					<< endl << "Start Time:" << start_time << endl << "End Time:" << end_time << endl << "Total Seats:" << total_seats << endl << "Remaining Seats:" << remaining_seats << endl
					<< "Seat Price:" << seat_price << endl;
				count = count + 1;  
			}
			bus_file >> bus_id >> driver_name >> start_location >> end_location >>
				start_time >> end_time >> total_seats >> remaining_seats >> seat_price;
		}

		if (count == 0)
		{
			cout << "NO BUS AVAILABLE" << endl;
		}
		bus_file.close();
	}
	cout << "Press enter to continue!";
	_getch();
	system("CLS");
	main_menu();
}



void New_Bus::remove_businfo()   // removing a bus from the file
{
	system("cls");

	fstream bus_file;
	fstream temp_bus_file;  // this file will be used to copy all the other buses except the one to be deleted
	string temp_busid;
	int count = 0;


	cout << "_______________BUS INFORMATION UPDATE____________" << endl;

	bus_file.open("BUS.txt", ios::in); //openning the main file
	if (!bus_file)
	{
		cout<< "FILE ERROR";
	}
	else
	{
		cout << "Enter the bus id you want to delete: " << endl; // taking the bus id from admin to delete
		cin >> temp_busid;

		temp_bus_file.open("TEMP_BUS.txt", ios::app | ios::out); // creating a temporary file

		bus_file >> bus_id >> driver_name >> start_location >> end_location >> //reading from the main file
			start_time >> end_time >> total_seats >> remaining_seats >> seat_price;
		while (!bus_file.eof())
		{
			if (temp_busid == bus_id) // if bus id matches then not copying info for that bus
			{
				cout << "BUS REMOVED!" << endl;
				count++;
			}
			else // for other buses copying the info to another file
			{
				temp_bus_file << bus_id << driver_name << start_location << end_location <<
					start_time << end_time << total_seats << remaining_seats << seat_price;
			}
			bus_file >> bus_id >> driver_name >> start_location >> end_location >>
				start_time >> end_time >> total_seats >> remaining_seats >> seat_price;
		}
		bus_file.close();
		temp_bus_file.close();

		remove("BUS.txt"); // deleting the previous file
		rename("TEMP_BUS.txt", "BUS.txt"); // renaming the temporary file as the previous file

		if (count == 0)

		{
			cout << "BUS NOT FOUND" << endl;
		}
	}
	cout << "Press enter to continue!";
	_getch();
	system("CLS");
	main_menu();

}

void Passenger::passenger_menu()   //menu options only available for passenger
{
	system("cls");

	New_Bus B;
	Passenger p1;


	int choice;

	cout << "______________BUS BOOKING SYSTEM_______________" << endl;
	cout << " 1. View Bus Information" << endl;
	cout << " 2.Create a new booking" << endl;
	cout << " 3.View Existing booking" << endl;
	cout << " 4. EXIT";
	cout << " Enter Your Choice:  ";
	cin >> choice;
	{
		switch (choice)
		{

		case 1:
			B.show_businfo();
			break;
		case 2:
			p1.new_booking();
			break;
		case 3:
			p1.find_booking();
			break;

		case 4:
			exit(0);

		default:
			cout << "\n Invalid choice";


		}
		_getch();
		main_menu();
	}
}


void Passenger::new_booking()  // to make a new booking
{
	system("cls");

	string temp_endlocation;
	fstream bus_file;
	fstream bus_file2;
	fstream temp_bus_file;
	fstream passenger_file;
	string temp_busid;
	int count = 0;
	int count2 = 0;

	//three part of this method, which of one is previously done,another two created
	//Part one:find the bus according to the destination
	//Part two: booking seats
	//Part three:showing information about ticket

	//part one

	cout << "_______________BUS INFORMATION____________" << endl;
	bus_file.open("BUS.txt", ios::in | ios::binary);
	if (!bus_file)
	{
		cout<<"FILE ERROR";
	}
	else
	{
		cout << "Enter your destination: ";
		cin >> temp_endlocation;

		bus_file >> bus_id >> driver_name >> start_location >> end_location >>
			start_time >> end_time >> total_seats >> remaining_seats >> seat_price;

		while (!bus_file.eof())
		{



			if (end_location == temp_endlocation)
			{
				cout << "BUS ID:" << bus_id << endl << "Driver name:" << driver_name << endl << "Start Location:" << start_location << endl << "End Location:" << end_location
					<< endl << "Start Time:" << start_time << endl << "End Time:" << end_time << endl << "Total Seats:" << total_seats << endl << "Remaining Seats:" << remaining_seats << endl
					<< "Seat Price:" << seat_price << endl;
				count = count + 1;
			}
			bus_file >> bus_id >> driver_name >> start_location >> end_location >>
				start_time >> end_time >> total_seats >> remaining_seats >> seat_price;
		}

		if (count == 0)
		{
			cout << "NO BUS AVAILABLE" << endl;
		}
		bus_file.close();
	}

	//part one
	//part two
	cout << "_______________SEAT INFORMATION UPDATE____________" << endl;
	bus_file2.open("BUS.txt", ios::in);
	if (!bus_file2)
	{
		cout<< "FILE ERROR";
	}
	else
	{
		cout << "Enter the bus id you want to book: " << endl; //taking info about bus 
		cin >> temp_busid;

		cout << "How many seats you want to book?" << endl;  // taking info about seat
		cin >> booked_seats;

		temp_bus_file.open("TEMP_BUS.txt", ios::app | ios::out); // creating a temp file

		bus_file2 >> bus_id >> driver_name >> start_location >> end_location >> // reading from the main file
			start_time >> end_time >> total_seats >> remaining_seats >> seat_price;
		while (!bus_file2.eof())
		{
			if (temp_busid == bus_id && remaining_seats>=booked_seats)  // if the bus found
			{
				cout << "Your seats have been booked!" << endl;  // decrease the no. of seats in the bus
				remaining_seats = remaining_seats - booked_seats;
				mbusid_passenger = bus_id;
				mstartloc_passenger = start_location;
				mendloc_passenger = end_location;
				mstartime_passenger = start_time;
				mseatprice_passenger = seat_price;


				temp_bus_file << bus_id << " " << driver_name << " " << start_location << " " << end_location << " " //write the new info in the file
					<< start_time << " " << end_time << " " << total_seats << " " << remaining_seats << " " << seat_price << endl;
				count2++;
			}
			else // for other bus information write into the file without any change of information
			{
				temp_bus_file << bus_id << " " << driver_name << " " << start_location << " " << end_location << " "
					<< start_time << " " << end_time << " " << total_seats << " " << remaining_seats << " " << seat_price << endl;
			}
			bus_file2 >> bus_id >> driver_name >> start_location >> end_location >>
				start_time >> end_time >> total_seats >> remaining_seats >> seat_price;
		}
		bus_file2.close();
		temp_bus_file.close();

		remove("BUS.txt");
		rename("TEMP_BUS.txt", "BUS.txt"); // rename the temporary file as the main file

		if (count2 == 0)

		{
			cout << "BUS NOT FOUND" << endl;
		}
	}

	//part two
	//part three
	system("cls");
	cout << "                                      BOOKING INFORMATION" << endl;
	passenger_file.open("PASSENGER.txt", ios::app | ios::in); //open a new file for passneger information

	
	




	cout << "Enter your name:" << endl; //taking info of the passenger
	cin >> mpassenger_name;
	
	int digits;

	cout << "How many digits in your phone no.?";
	cin >> digits;
	mpassenger_phone = new string[digits]; //DMA for phone no. of the passneger

	cout << "Enter your phone no.:" << endl;
	cin >>*mpassenger_phone;

	phone = *mpassenger_phone;

	passenger_file << mpassenger_name << " " <<phone << " " << //writing the info into file
		mbusid_passenger << " " << mstartloc_passenger << " " << mendloc_passenger <<
		" " << mstartime_passenger << " " << booked_seats << " " << mseatprice_passenger << endl;
	passenger_file.close();

	system("cls");  //displaying the ticket info
	cout << "Here is your booked ticket information!!!" << endl;
	cout << "Name:" << mpassenger_name << endl;
	cout << "Phone no.: " << phone << endl;
	cout << "Bus ID:" << mbusid_passenger << endl;
	cout << "Starting Location: " << mstartloc_passenger << endl;
	cout << "Destination:" << mendloc_passenger << endl;
	cout << "NO. of Booked seats:" << booked_seats << endl;
	cout << "Total amount you have to pay:" << mseatprice_passenger * booked_seats << "HUF" << endl;
	cout << "Thank you for travelling with ANJAN TRANSPORTATION AND CO." << endl;
	cout << "Bus will leave from Budapest Bus Station at" << mstartime_passenger << ". Be present there at least 15 minutes before" << endl;
	cout << "Press enter to continue!";
	delete []mpassenger_phone;
	_getch();
	system("cls");
	main_menu();
}





void Passenger::find_booking()  // to find a previously made booking
{
	system("cls");
	fstream passenger_file;
	string temp_phn;



	cout << "                  FINDING BOOKING" << endl;

	passenger_file.open("PASSENGER.txt", ios::in);

	if (!passenger_file)
	{
		cout<< "FILE ERROR";
	}
	else
	{
	

		cout << "Enter your phone number: " << endl;
		cin >> temp_phn;

		passenger_file >> mpassenger_name >> phone >> mbusid_passenger >> mstartloc_passenger >> mendloc_passenger >> mstartime_passenger >> booked_seats >> mseatprice_passenger;

		while (!passenger_file.eof())
		{
			if (temp_phn == phone) //if phone number matches fetch information
			{
				cout << "Here is your booked ticket information!!!" << endl;
				cout << "Name:" << mpassenger_name << endl;
				cout << "Phone no.: " << phone << endl;
				cout << "Bus ID:" << mbusid_passenger << endl;
				cout << "Starting Location: " << mstartloc_passenger << endl;
				cout << "Destination:" << mendloc_passenger << endl;
				cout << "NO. of Booked seats:" << booked_seats << endl;
				cout << "Total amount you have to pay:" << mseatprice_passenger * booked_seats << "HUF" << endl;
				cout << "Thank you for travelling with ANJAN TRANSPORTATION AND CO." << endl;
				cout << "Bus will leave from Budapest Bus Station at " << mstartime_passenger << ". Be present there at least 15 minutes before" << endl;
			}
			passenger_file >> mpassenger_name >> phone >> mbusid_passenger >> mstartloc_passenger >> mendloc_passenger >> mstartime_passenger >> booked_seats >> mseatprice_passenger;
		}
		passenger_file.close();
		
	}
	

	cout << "Press enter to continue!";
	_getch();
	system("cls");
	main_menu();
}

void Passenger::Login()//to login as a passenger
{

	int enter;
	string  temp_passenger_user_name, temp_passenger_password;
	fstream passenger_login_file;
	

	system("cls");

	cout << "                                      USER LOGIN" << endl;

	cout << "To login press 1" << endl;
	cout << "For creating a new account press 2" << endl;
	cin >> enter;

	if (enter == 1) // if account already exists
	{
		system("cls");
		cout << "                  USER LOGIN" << endl;
		cout << "Enter your user name:";
		cin >> temp_passenger_user_name;
		cout << "Enter passowrd:";
		cin >> temp_passenger_password;


		passenger_login_file.open("PASSENGER_LOGIN.txt", ios::in);  //read from file 

		if (!passenger_login_file)
		{
			cout<< "FILE ERROR";
		}
		else
		{

			passenger_login_file >> mpassenger_name >>phone >> passenger_id
				>> passenger_user_name >> passenger_password;

			while (!passenger_login_file.eof())
			{
				if (temp_passenger_user_name == passenger_user_name && temp_passenger_password == passenger_password) // if matches then go to menu
				{

					cout << endl << endl << endl << endl << "                                LOADING";
					for (int i = 0; i < 15; i++)
					{
						Sleep(100);
						cout << "->";
					}
					cout << "LOGIN SUCCESSFUL!";
					_getch();
					passenger_menu();
				}
				else
				{
					cout<<"Invalid user name or password";
				}
				passenger_login_file >> mpassenger_name >>phone >> passenger_id
					>> passenger_user_name >> passenger_password;
			}
			passenger_login_file.close();
		}




	}

	if (enter == 2)// creating a new account
	{
		system("cls");
		cout << "                                      Creating New Account" << endl;
		passenger_login_file.open("PASSENGER_LOGIN.txt", ios::app | ios::in); //creating new file for passenger login information


		
		cout << "Enter your name:" << mpassenger_name; // taking info of the passneger
		cin >> mpassenger_name;
		cout << "Enter your phone no.:" << endl;
		cin >> phone;
		cout << "Enter your ID no.";
		cin >> passenger_id;
		cout << "Enter your new username:";
		cin >> passenger_user_name;
		cout << "Enter your new password:";
		cin >> passenger_password;

		passenger_login_file << mpassenger_name << " " << phone << " " << passenger_id
			<< " " << passenger_user_name << " " << passenger_password << endl;
		passenger_login_file.close();
	}


	cout << endl << endl << endl << endl << "                                LOADING";
	for (int i = 0; i < 15; i++)
	{
		Sleep(100);
		cout << "->";
	}

	cout << "New Account Created!";

	
	_getch();
	passenger_menu();
}

void admin::admin_menu() // options available only for admin
{
	New_Bus B;

	int choice;

	system("cls");
	cout << "                                              ______________BUS MANAGEMENT SYSTEM_______________" << endl;
	cout << " 1. Add a New Bus" << endl;
	cout << " 2. View a Existing Bus Information" << endl;
	cout << " 3. Remove a bus" << endl;
	cout << " 4. EXIT";
	cout << " Enter Your Choice:  ";
	cin >> choice;
	{
		switch (choice)
		{

		case 1:
			B.add_bus();
			break;
		case 2:
			B.show_businfo();
			break;
		case 3:
			B.remove_businfo();
			break;

		case 4:
			exit(0);

		default:
			cout << "\n Invalid choice";


		}
		_getch();
		main_menu();
	}
}

void admin::Login()  //login for admin
{
	admin a;

	system("cls");
	try {                                         //exception handling
		cout << "                                                            Admin Login" << endl;
		cout << "Enter user name:";
		cin >> user_id;
		cout << "Enter password:";
		cin >> password;

		if (user_id == "anjan" && password == "anjan") // admin login only possible for this userid and password
		{
			cout << endl << endl << endl << endl << "                                LOADING";
			for (int i = 0; i < 15; i++) 
			{
				Sleep(100);
				cout << "->";
			}
			admin_menu();
		}
		else {
			throw login_error;
		}
	}
	catch(int login_error)

	{
		cout<< "Invalid user name or password"<<endl;
		cout << "Error"<<login_error;
		_getch();
		a.Login();
	}
}











