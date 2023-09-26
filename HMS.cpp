#include<iostream>
#include<fstream>
#include<iomanip>
#include"Header.h"
#include<string>
#include<string.h>
using namespace std;

Administrator::Administrator() {
	fee_status = "UnPaid";
	appointment_status = "Unchecked";
	username = "Deafult";
	password = "Deafult";
}
Patient::Patient() {

}
Doctor::Doctor() {

}

bool Administrator::check(bool& ch) {
	return ch;
}
void Administrator::sign_in(bool& ch) {
	cout << "\n\t\t|       Sign In       |" << endl;
	cin.ignore();
	cout << "\n\t\tUserName : ";
	getline(cin, username);
	cout << "\t\tPassword : ";
	getline(cin, password);
	if (username == "admin" && password == "admin") {
		ch = true;
		check(ch);
	}
	else {
		check(ch);
	}
}

void Administrator::write_Doctor_File(Administrator* Arr1, int size) {

	int i = 0;
	ofstream out;
	out.open("Doctor.txt", ios::app);
	while (i < size - 1)
	{
		out << Arr1[i].first_name << endl;
		out << Arr1[i].last_name << endl;
		out << Arr1[i].department_id << endl;
		out << Arr1[i].D_std_number << endl;
		out << Arr1[i].department_name << endl;
		out << Arr1[i].username << endl;
		out << Arr1[i].password << endl;
		out << Arr1[i].reg_date.day << endl;
		out << Arr1[i].reg_date.month << endl;
		out << Arr1[i].reg_date.year << endl;
		out << Arr1[i].gender << endl;
		out << Arr1[i].contact_no << endl;
		out << Arr1[i].blood_group << endl;
		out << Arr1[i].address << endl;
		out << Arr1[i].qualification << endl;
		out << Arr1[i].salary << endl;
		i++;
	}
}
void Administrator::Read_Doctor_File(Administrator* Arr1, int& i)
{
	ifstream input;
	input.open("Doctor.txt");

	// Checking if the file is opened or not 
	if (input.is_open())
	{
		while (!input.eof())
		{
			input >> Arr1[i].first_name;
			input >> Arr1[i].last_name;
			input >> Arr1[i].department_id;
			input >> Arr1[i].D_std_number;
			input >> Arr1[i].department_name;
			input >> Arr1[i].username;
			input >> Arr1[i].password;
			input >> Arr1[i].reg_date.day;
			input >> Arr1[i].reg_date.month;
			input >> Arr1[i].reg_date.year;
			input >> Arr1[i].gender;
			input >> Arr1[i].contact_no;
			input >> Arr1[i].blood_group;
			input >> Arr1[i].address;
			input >> Arr1[i].qualification;
			input >> Arr1[i].salary;
			i++;
		}
	}
	else {
		cout << "File is not opened " << endl;
	}
}
void Administrator::Read_Patient_File(Administrator* Arr2, int& i)
{
	ifstream input;
	input.open("Patient.txt");

	// Checking if the file is opened or not 
	if (input.is_open())
	{
		while (!input.eof())
		{
			input >> Arr2[i].first_name;
			input >> Arr2[i].last_name;
			input >> Arr2[i].department_id;
			input >> Arr2[i].P_std_number;
			input >> Arr2[i].department_name;
			input >> Arr2[i].reg_date.day;
			input >> Arr2[i].reg_date.month;
			input >> Arr2[i].reg_date.year;
			input >> Arr2[i].gender;
			input >> Arr2[i].contact_no;
			input >> Arr2[i].blood_group;
			input >> Arr2[i].address;
			input >> Arr2[i].fee_status;
			input >> Arr2[i].qualification;
			input >> Arr2[i].salary;
			i++;
		}
	}
	else {
		cout << "File is not opened " << endl;
	}
}
void Administrator::write_Patient_File(Administrator* Arr2, int size) {

	int i = 0;
	ofstream out;
	out.open("Patient.txt", ios::app);
	while (i < size - 1)
	{
		out << Arr2[i].first_name << endl;
		out << Arr2[i].last_name << endl;
		out << Arr2[i].department_id << endl;
		out << Arr2[i].D_std_number << endl;
		out << Arr2[i].department_name << endl;
		out << Arr2[i].reg_date.day << endl;
		out << Arr2[i].reg_date.month << endl;
		out << Arr2[i].reg_date.year << endl;
		out << Arr2[i].gender << endl;
		out << Arr2[i].contact_no << endl;
		out << Arr2[i].blood_group << endl;
		out << Arr2[i].address << endl;
		out << Arr2[i].fee_status << endl;
		out << Arr2[i].qualification << endl;
		out << Arr2[i].salary << endl;
		i++;
	}
}
void Administrator::Read_Appointement_File(Administrator* Arr3, int& i)
{
	ifstream input;
	input.open("Appointment.txt");

	// Checking if the file is opened or not 
	if (input.is_open())
	{
		while (!input.eof())
		{
			input >> Arr3[i].child_department;
			input >> Arr3[i].department_id;
			input >> Arr3[i].C_std_number;
			input >> Arr3[i].department_name;
			input >> Arr3[i].patient_id;
			input >> Arr3[i].set_time;
			input >> Arr3[i].appointment_status;
			input.ignore();
			i++;
		}
	}
	else {
		cout << "File is not opened " << endl;
	}
}
void Administrator::write_Appointement_File(Administrator* Arr3, int size)
{
	ofstream out;
	int i = 0;
	out.open("Appointment.txt", ios::app);
	while (i < size - 1)
	{
		out << Arr3[i].child_department << endl;
		out << Arr3[i].department_id << endl;
		out << Arr3[i].C_std_number << endl;
		out << Arr3[i].department_name << endl;
		out << Arr3[i].patient_id << endl;
		out << Arr3[i].set_time << endl;
		out << Arr3[i].appointment_status << endl;
		i++;
	}
}

void Administrator::Add_new_Doctor(Administrator* Arr1, int size) {
	int a = 0;
	ofstream write_in_file;
	write_in_file.open("Doctor.txt", ios::app);
	cout << "\n\t\t----------Enter Doctor Details----------" << endl;
	cin.ignore();
	cout << "\t\tFirst Name : ";
	getline(cin, first_name);
	write_in_file << first_name << endl;
	cout << "\t\tLast Name : ";
	getline(cin, last_name);
	write_in_file << last_name << endl;
	cout << "\n\t\t\t| Select The Department |" << endl;
	cout << "\t\t1. Dental" << endl;
	cout << "\t\t2. Accident & Emergency" << endl;
	cout << "\t\t3. Orthopedics" << endl;
	cout << "\t\t4. Psychiatry" << endl;
	cout << "\t\t5. Physiotherapy" << endl;
	int option;
	cout << "\n\t\tSelect The Option : ";
	cin >> option;
	department_id = option;
	switch (option) {
	case 1: {
		department_name = "Dental";
		while (a < size)
		{
			if (department_id == Arr1[a].department_id)
			{
				if (D_std_number == Arr1[a].D_std_number)
				{
					Arr1[a].D_std_number = D_std_number++;
				}
			}
			a++;
		}
		cout << "\t\tDoctor Id : 0" << department_id << D_std_number << endl;
		write_in_file << department_id << endl;
		write_in_file << D_std_number << endl;
		cout << "\t\tDepartment Name : " << department_name << endl;
		write_in_file << department_name << endl;
		break;
	}
	case 2: {
		D_std_number = 1000;
		department_name = "Accident&Emergency";
		while (a < size)
		{
			if (department_id == Arr1[a].department_id)
			{
				if (D_std_number == Arr1[a].D_std_number)
				{
					Arr1[a].D_std_number = D_std_number++;
				}
			}
			a++;
		}
		cout << "\t\tDoctor Id : 0" << department_id << D_std_number << endl;
		write_in_file << department_id << endl;
		write_in_file << D_std_number << endl;
		cout << "\t\tDepartment Name : " << department_name << endl;
		write_in_file << department_name << endl;
		break;
	}
	case 3: {
		D_std_number = 1000;
		department_name = "Orthopedics";
		while (a < size)
		{
			if (department_id == Arr1[a].department_id)
			{
				if (D_std_number == Arr1[a].D_std_number)
				{
					Arr1[a].D_std_number = D_std_number++;
				}
			}
			a++;
		}
		cout << "\t\tDoctor Id : 0" << department_id << D_std_number << endl;
		write_in_file << department_id << endl;
		write_in_file << D_std_number << endl;
		cout << "\t\tDepartment Name : " << department_name << endl;
		write_in_file << department_name << endl;
		break;
	}
	case 4: {
		D_std_number = 1000;
		department_name = "Psychiatry";
		while (a < size)
		{
			if (department_id == Arr1[a].department_id)
			{
				if (D_std_number == Arr1[a].D_std_number)
				{
					Arr1[a].D_std_number = D_std_number++;
				}
			}
			a++;
		}
		cout << "\t\tDoctor Id : 0" << department_id << D_std_number << endl;
		write_in_file << department_id << endl;
		write_in_file << D_std_number << endl;
		cout << "\t\tDepartment Name : " << department_name << endl;
		write_in_file << department_name << endl;
		break;
	}
	case 5: {
		D_std_number = 1000;
		department_name = "Physiotherapy";
		while (a < size)
		{
			if (department_id == Arr1[a].department_id)
			{
				if (D_std_number == Arr1[a].D_std_number)
				{
					Arr1[a].D_std_number = D_std_number++;
				}
			}
			a++;
		}
		cout << "\t\tDoctor Id : 0" << department_id << D_std_number << endl;
		write_in_file << department_id << endl;
		write_in_file << D_std_number << endl;
		cout << "\t\tDepartment Name : " << department_name << endl;
		write_in_file << department_name << endl;
		break;
	}
	default:
		exit(0);
	}
	cout << "\n\t\tDoctor UserName : ";
	cin.ignore();
	getline(cin, username);
	write_in_file << username << endl;
	cout << "\t\tDoctor Password : ";
	getline(cin, password);
	write_in_file << password << endl;
	cout << "\n\t\t\t-----Registration Date-----" << endl;
	cout << "\n\t\tDay : ";
	cin >> reg_date.day;
	write_in_file << reg_date.day << endl;
	cout << "\t\tMonth : ";
	cin >> reg_date.month;
	write_in_file << reg_date.month << endl;
	cout << "\t\tYear : ";
	cin >> reg_date.year;
	write_in_file << reg_date.year << endl;
	cout << "\t\tGender : ";
	cin.ignore();
	getline(cin, gender);
	write_in_file << gender << endl;
	cout << "\t\tContact Number : ";
	cin >> contact_no;
	write_in_file << contact_no << endl;
	cin.ignore();
	cout << "\t\tBlood Group : ";
	getline(cin, blood_group);
	write_in_file << blood_group << endl;
	cout << "\t\tAddress : ";
	getline(cin, address);
	write_in_file << address << endl;
	cout << "\t\tQualification : ";
	getline(cin, qualification);
	write_in_file << qualification << endl;
	cout << "\t\tEnter The Doctor Salary : ";
	cin >> salary;
	write_in_file << salary << "\n";
	write_in_file.close();
}
void Administrator::Add_new_Patient(Administrator* Arr2, int size) {
	ofstream write_file;
	int a = 0;
	write_file.open("Patient.txt", ios::app);
	cout << "\n\t\t----------Enter Patient Deatails----------" << endl;
	cin.ignore();
	cout << "\t\tFirst Name : ";
	getline(cin, first_name);
	write_file << first_name << endl;
	cout << "\t\tLast Name : ";
	getline(cin, last_name);
	write_file << last_name << endl;
	cout << "\n\t\t\t| Select The Department |" << endl;
	cout << "\t\t1. Dental" << endl;
	cout << "\t\t2. Accident & Emergency" << endl;
	cout << "\t\t3. Orthopedics" << endl;
	cout << "\t\t4. Psychiatry" << endl;
	cout << "\t\t5. Physiotherapy" << endl;
	int option;
	cout << "\n\t\tSelect The Option : ";
	cin >> option;
	switch (option) {
	case 1: {
		department_name = "Dental";
		while (a < size)
		{
			if (option == Arr2[a].department_id)
			{
				if (P_std_number == Arr2[a].P_std_number)
				{
					Arr2[a].P_std_number = P_std_number++;
				}
			}
			a++;
		}
		cout << "\t\tPatient Id : 0" << option << P_std_number << endl;
		write_file << option << endl;
		write_file << P_std_number << endl;
		cout << "\t\tDepartment Name : " << department_name << endl;
		write_file << department_name << endl;
		break;
	}
	case 2: {
		P_std_number = 1000;
		department_name = "Accident&Emergency";
		while (a < size)
		{
			if (option == Arr2[a].department_id)
			{
				if (P_std_number == Arr2[a].P_std_number)
				{
					Arr2[a].P_std_number = P_std_number++;
				}
			}
			a++;
		}
		cout << "\t\tPatient Id : 0" << option << P_std_number << endl;
		write_file << option << endl;
		write_file << P_std_number << endl;
		cout << "\t\tDepartment Name : " << department_name << endl;
		write_file << department_name << endl;
		break;
	}
	case 3: {
		P_std_number = 1000;
		department_name = "Orthopedics";
		while (a < size)
		{
			if (option == Arr2[a].department_id)
			{
				if (P_std_number == Arr2[a].P_std_number)
				{
					Arr2[a].P_std_number = P_std_number++;
				}
			}
			a++;
		}
		cout << "\t\tPatient Id : 0" << option << P_std_number << endl;
		write_file << option << endl;
		write_file << P_std_number << endl;
		cout << "\t\tDepartment Name : " << department_name << endl;
		write_file << department_name << endl;
		break;
	}
	case 4: {
		P_std_number = 1000;
		department_name = "Psychiatry";
		while (a < size)
		{
			if (option == Arr2[a].department_id)
			{
				if (P_std_number == Arr2[a].P_std_number)
				{
					Arr2[a].P_std_number = P_std_number++;
				}
			}
			a++;
		}
		cout << "\t\tPatient Id : 0" << option << P_std_number << endl;
		write_file << option << endl;
		write_file << P_std_number << endl;
		cout << "\t\tDepartment Name : " << department_name << endl;
		write_file << department_name << endl;
		break;
	}
	case 5: {
		P_std_number = 1000;
		department_name = "Physiotherapy";
		while (a < size)
		{
			if (option == Arr2[a].department_id)
			{
				if (P_std_number == Arr2[a].P_std_number)
				{
					Arr2[a].P_std_number = P_std_number++;
				}
			}
			a++;
		}
		cout << "\t\tPatient Id : 0" << option << P_std_number << endl;
		write_file << option << endl;
		write_file << P_std_number << endl;
		cout << "\t\tDepartment Name : " << department_name << endl;
		write_file << department_name << endl;
		break;
	}
	default:
		exit(0);
	}
	cout << "\n\t\t\t-----Registration Date-----" << endl;
	cout << "\n\t\tDay : ";
	cin >> reg_date.day;
	write_file << reg_date.day << endl;
	cout << "\t\tMonth : ";
	cin >> reg_date.month;
	write_file << reg_date.month << endl;
	cout << "\t\tYear : ";
	cin >> reg_date.year;
	write_file << reg_date.year << endl;
	cout << "\t\tGender : ";
	cin.ignore();
	getline(cin, gender);
	write_file << gender << endl;
	cout << "\t\tContact Number : ";
	cin >> contact_no;
	write_file << "0" << contact_no << endl;
	cin.ignore();
	cout << "\t\tBlood Group : ";
	getline(cin, blood_group);
	write_file << blood_group << endl;
	cout << "\t\tAddress : ";
	getline(cin, address);
	write_file << address << endl;
	cout << "\t\tFee Status : " << fee_status << endl;
	write_file << fee_status << endl;
	cout << "\t\tQualification : ";
	getline(cin, qualification);
	write_file << qualification << endl;
	cout << "\t\tSalary : ";
	cin >> salary;
	write_file << salary << "\n";
	write_file.close();
}
void Administrator::Add_new_appointment(Administrator* Arr1, Administrator* Arr2, Administrator* Arr3,
	Administrator* Arr4, Administrator A1, int size, int size2, int size3, int i) {
	int a = 0;
	ofstream write_file;
	write_file.open("Appointment.txt", ios::app);
	cout << "\n\t\t----------Add New Appointment----------" << endl;
	cout << "\n\t\t\t| Select Parent Department |" << endl;
	cout << "\t\t1. Dental" << endl;
	cout << "\t\t2. Accident&Emergency" << endl;
	cout << "\t\t3. Orthopedics" << endl;
	cout << "\t\t4. Psychiatry" << endl;
	cout << "\t\t5. Physiotherapy" << endl;
	int option;
	cout << "\n\t\tSelect The Option : ";
	cin >> option;
	switch (option) {
	case 1: {
		cout << "\n\t\t\t| Department Name |" << endl;
		department_name = "Dental";
		while (a < size3)
		{
			if (option == Arr3[a].department_id)
			{
				if (C_std_number == Arr3[a].C_std_number)
				{
					Arr3[a].C_std_number = C_std_number++;
				}
			}
			a++;
		}
		cout << "\n\t\tThere Are Subcategories Of Dental." << endl;
		cout << "\t\t1) Endodontist." << endl;
		cout << "\t\t2) Orthodontics." << endl;
		cout << "\t\t3) periodontists." << endl;
		cin.ignore();
		cout << "\n\t\tPlease Enter The Department Name From Above : ";
		getline(cin, child_department);
		write_file << child_department << endl;
		cout << "\t\tAppointment Id : 0" << option << C_std_number << endl;
		write_file << option << endl;
		write_file << C_std_number << endl;
		write_file << department_name << endl;
		break;
	}
	case 2: {
		cout << "\n\t\t\t| Department Name |" << endl;
		department_name = "Accident&Emergency";
		C_std_number = 1000;
		while (a < size3)
		{
			if (option == Arr3[a].department_id)
			{
				if (C_std_number == Arr3[a].C_std_number)
				{
					Arr3[a].C_std_number = C_std_number++;
				}
			}
			a++;
		}
		cout << "\n\t\tThere Are Subcategories Of Accident and Emergency." << endl;
		cout << "\t\t1) Heart Attack." << endl;
		cout << "\t\t2) Car Accident." << endl;
		cout << "\t\t3) Other types." << endl;
		cout << "\n\t\tPlease Enter The Department Name From Above : ";
		cin.ignore();
		getline(cin, child_department);
		write_file << child_department << endl;
		cout << "\t\tAppointment Id : 0" << option << C_std_number << endl;
		write_file << option << endl;
		write_file << C_std_number << endl;
		write_file << department_name << endl;
		break;
	}
	case 3: {
		cout << "\n\t\t\t| Department Name |" << endl;
		department_name = "Orthopedics";
		C_std_number = 1000;
		while (a < size3)
		{
			if (option == Arr3[a].department_id)
			{
				if (C_std_number == Arr3[a].C_std_number)
				{
					Arr3[a].C_std_number = C_std_number++;
				}
			}
			a++;
		}
		cout << "\n\t\tThere are subcategories of Orthopedics." << endl;
		cout << "\t\t1) Back pain." << endl;
		cout << "\t\t2) Work injuries." << endl;
		cout << "\t\t3) Fractures and broken bones." << endl;
		cin.ignore();
		cout << "\n\t\tPlease Enter The Department Name From Above : ";
		getline(cin, child_department);
		write_file << child_department << endl;
		cout << "\t\tAppointment Id : 0" << option << C_std_number << endl;
		write_file << option << endl;
		write_file << C_std_number << endl;
		write_file << department_name << endl;
		break;
	}
	case 4: {
		cout << "\n\t\t\t| Department Name |" << endl;
		department_name = "Psychiatry";
		C_std_number = 1000;
		while (a < size3)
		{
			if (option == Arr3[a].department_id)
			{
				if (C_std_number == Arr3[a].C_std_number)
				{
					Arr3[a].C_std_number = C_std_number++;
				}
			}
			a++;
		}
		cout << "\n\t\tThere are subcategories of Psychiatry." << endl;
		cout << "\t\t1) Depression." << endl;
		cout << "\t\t2) Anxiety Disorders." << endl;
		cout << "\t\t3) Addictive Behaviours." << endl;
		cin.ignore();
		cout << "\n\t\tPlease Enter The Department Name From Above : ";
		getline(cin, child_department);
		write_file << child_department << endl;
		cout << "\t\tAppointment Id : 0" << option << C_std_number << endl;
		write_file << option << endl;
		write_file << C_std_number << endl;
		write_file << department_name << endl;
		break;
	}
	case 5: {
		C_std_number = 1000;
		while (a < size3)
		{
			if (option == Arr3[a].department_id)
			{
				if (C_std_number == Arr3[a].C_std_number)
				{
					Arr3[a].C_std_number = C_std_number++;
				}
			}
			a++;
		}
		cout << "\n\t\t\t| Department Name |" << endl;
		department_name = "Physiotherapy";
		cout << "\n\t\tThere are subcategories of Physiotherapy." << endl;
		cout << "\t\t1) Musculo-skeletal conditions." << endl;
		cout << "\t\t2) Neurology disorders." << endl;
		cout << "\t\t3) Paediatric respiratory conditions." << endl;
		cin.ignore();
		cout << "\n\t\tPlease Enter The Department Name From Above : ";
		getline(cin, child_department);
		write_file << child_department << endl;
		cout << "\t\tAppointment Id : 0" << option << C_std_number << endl;
		write_file << option << endl;
		write_file << C_std_number << endl;
		write_file << department_name << endl;
		break;
	}
	default:
		exit(0);
	}
	cout << "\t\tPlease Enter The Patient Id : ";
	cin >> patient_id;
	write_file << patient_id << endl;
	if (option == 1)
		cout << "\n\t\tYou have choose the option for Dental .\n";
	else if (option == 2)
		cout << "\n\t\tYou have choose the option for Accident & Emergency .\n";
	else if (option == 3)
		cout << "\n\t\tYou have choose the option for Orthopedics .\n";
	else if (option == 4)
		cout << "\n\t\tYou have choose the option for Psychiatry .\n";
	else if (option == 5)
		cout << "\n\t\tYou have choose the option for Physiotherapy .\n";
	else
		cout << "\n\t\tYour choice is wrong.\n";
	cout << "\n\t\t\t----Appointment time----" << endl;
	cout << "\t\tEnter The Timing e.g(Morning,Evening) : ";
	cin >> ws;
	getline(cin, set_time);
	write_file << set_time << endl;
	cout << "\t\tAppointment Status : " << appointment_status << endl;
	write_file << appointment_status << "\n";
	write_file.close();
}
void Administrator::Assign_Appointment(Administrator* Arr1, Administrator* Arr2,
	Administrator* Arr4, int size, int size2, int& a,int p_id, Administrator* Arr3, int size3) {
	int id1, temp = 0, temp2 = 0, id2 = 0;
	string first, last,first1,last1;
	cout << "\n\t\t----------Assign Appointment----------" << endl;
	cout << "\nAppointId" << setw(15) << "PatientId" << endl;
	for (int i = 0; i < size3 - 1; i++)
	{
		cout << "0" << Arr3[i].department_id << Arr3[i].C_std_number <<setw(10);
		cout <<"0"<< Arr3[i].patient_id << endl;
	}
	cout << "\n\t\t\t| Select Doctor |" << endl;
	cout << "\nDoctorId " << setw(10) << " Doctor Name" << setw(15) << " Department" << setw(10)
		<< "Gender" << setw(10) << "Address" << setw(20) << "Qualification" << endl;
	for (int i = 0; i < size - 1; i++)
	{
		cout << "0" << Arr1[i].department_id;
		cout << Arr1[i].D_std_number << setw(10);
		cout << Arr1[i].first_name << " ";
		cout << Arr1[i].last_name << setw(10);
		cout << Arr1[i].department_name << setw(12);
		cout << Arr1[i].gender << setw(11);
		cout << Arr1[i].address << setw(12);
		cout << Arr1[i].qualification << endl;
	}

		cout << "\n\t\t\t\t| Select Patient |" << endl << endl;
		cout << "\n\t\t\t| Select Appointment To Assign |" << endl;
		cout<< "\nPatientId " << setw(10) << " Patient Name" << setw(15) << " Department" << setw(10)
			<< "Gender" << setw(10) << "Address" << setw(20) << "Qualification" << endl;
		for (int i = 0; i < size2 - 1; i++)
		{
			cout << "0" << Arr2[i].department_id;
			cout << Arr2[i].P_std_number << setw(10);
			cout << Arr2[i].first_name << " ";
			cout << Arr2[i].last_name << setw(10);
			cout << Arr2[i].department_name << setw(12);
			cout << Arr2[i].gender << setw(11);
			cout << Arr2[i].address << setw(12);
			cout << Arr2[i].qualification << endl;
		}
		cout << "\n\tPlease Enter The Patient Id For Assign Appointment: ";
		cin >> id2;
		p_id = id2;
		temp2 = id2 / 10000;
		id2 = id2 % 10000;
		for (int i = 0; i < size2 - 1; i++)
		{
			if (temp2 == Arr2[i].department_id && Arr2[i].P_std_number == id2)
			{
				cout << "You Are Selected Pa. " << Arr2[i].first_name << " " << Arr2[i].last_name << endl;
				first1 = Arr2[i].first_name;
				last1 = Arr2[i].last_name;
			}
		}

		cout << "\n\tPlease Enter The Doctor Id For Assign Appointment: ";
		cin >> id1;
		temp = id1 / 10000;
		id1 = id1 % 10000;
		for (int i = 0; i < size - 1; i++)
		{
			if (temp == Arr1[i].department_id && Arr1[i].D_std_number == id1)
			{
				cout << "You Are Selected Dr. " << Arr1[i].first_name << " " << Arr1[i].last_name << endl;
				first = Arr1[i].first_name;
				last = Arr1[i].last_name;
			}
		}
		for (int i = 0; i < size2 - 1; i++)
		{
			if (Arr3[i].patient_id == p_id)
			{
				Arr4[a].department_id = Arr3[i].department_id;
				Arr4[a].C_std_number = Arr3[i].C_std_number;
				Arr4[a].set_time = Arr3[i].set_time;
			}
		}
		Arr4[a].patient_id = p_id;
		Arr4[a].p_first = first1;
		Arr4[a].p_last = last1;
		Arr4[a].D_id = temp;
		Arr4[a].D_std_number = id1;
		Arr4[a].first_name = first;
		Arr4[a].last_name = last;
		a++;
}
void Administrator::Edit_doctor_details(Administrator* Arr1, int size) {
	int id, temp, a = 1;
	cout << "\n\t\t\t| Select Doctor |" << endl;
	cout << "\nDoctorId " << setw(10) << " Doctor Name" << setw(15) << " Department" << setw(10)
		<< "Salary" << setw(15) << "ContactNo" << setw(15) << "Address" << setw(20) << "Qualification" << endl;
	for (int i = 0; i < size - 1; i++)
	{
		cout << "0" << Arr1[i].department_id;
		cout << Arr1[i].D_std_number << setw(10);
		cout << Arr1[i].first_name << " ";
		cout << Arr1[i].last_name << setw(10);
		cout << Arr1[i].department_name << setw(14);
		cout << Arr1[i].salary << setw(7);
		cout << "0" << Arr1[i].contact_no << setw(15);
		cout << Arr1[i].address << setw(10);
		cout << Arr1[i].qualification << endl;
	}
	cout << "\n\t\t----------Edit Doctor Details----------" << endl;
	cout << "\n\t\tEnter The Doctor Id For Editing : ";
	cin >> id;
	temp = id / 10000;
	id = id % 10000;
	for (int i = 0; i < size - 1; i++)
	{
		if (Arr1[i].department_id == temp && Arr1[i].D_std_number == id)
		{
			cout << "You Are Selected Dr. " << Arr1[i].first_name << " " << Arr1[i].last_name << endl << endl;
			cin.ignore();
			cout << "\t\tUpdate The Address : ";
			getline(cin, address);
			Arr1[i].address = address;
			cout << "\t\tUpdate The Contact No : ";
			cin >> contact_no;
			Arr1[i].contact_no = contact_no;
			cin.ignore();
			cout << "\t\tUpdate The Qualification : ";
			getline(cin, qualification);
			Arr1[i].qualification = qualification;
			cout << "\t\tUpdate The Salary : ";
			cin >> salary;
			Arr1[i].salary = salary;
		}
	}

}
void Administrator::Edit_patient_details(Administrator* Arr2, int size) {
	int id, temp;
	cout << "\n\t\t\t| Select Patient |" << endl;
	cout << "\nPatientId " << setw(10) << " Patient Name" << setw(15) << " Department" << setw(13)
		<< "FeeStatus" << setw(15) << "ContactNo" << setw(15) << "Address" << endl;
	for (int i = 0; i < size - 1; i++)
	{
		cout << "0" << Arr2[i].department_id;
		cout << Arr2[i].P_std_number << setw(11);
		cout << Arr2[i].first_name << " ";
		cout << Arr2[i].last_name << setw(11);
		cout << Arr2[i].department_name << setw(14);
		cout << Arr2[i].fee_status << setw(10);
		cout << "0" << Arr2[i].contact_no << setw(14);
		cout << Arr2[i].address << endl;
	}
	cout << "\n\t\t----------Edit Patient Details----------" << endl;
	cout << "\n\t\tEnter The Patient Id For Editing : ";
	cin >> id;
	temp = id / 10000;
	id = id % 10000;
	for (int i = 0; i < size - 1; i++)
	{
		if (Arr2[i].department_id == temp && Arr2[i].P_std_number == id)
		{
			cout << "You Are Selected Pa. " << Arr2[i].first_name << " " << Arr2[i].last_name << endl << endl;
			cin.ignore();
			cout << "\t\tUpdate The First Name : ";
			getline(cin, first_name);
			Arr2[i].first_name = first_name;
			cout << "\t\tUpdate The Last Name : ";
			getline(cin, last_name);
			Arr2[i].last_name = last_name;
			cout << "\t\tUpdate The FeeStatus : ";
			getline(cin, fee_status);
			Arr2[i].fee_status = fee_status;
			cout << "\t\tUpdate The Address : ";
			getline(cin, address);
			Arr2[i].address = address;
			cout << "\t\tUpdate The Contact No : ";
			cin >> contact_no;
			Arr2[i].contact_no = contact_no;
		}
	}
}
void Administrator::View_All_Patients(Administrator* Arr2, int size)
{
	cout << "\n\t\t----------All Patient Deatails----------" << endl;
	cout << "\nPatientId " << setw(10) << " Patient Name" << setw(15) << " Department" << endl;
	for (int i = 0; i < size - 1; i++)
	{
		cout << "0" << Arr2[i].department_id;
		cout << Arr2[i].P_std_number << setw(11);
		cout << Arr2[i].first_name;
		cout << Arr2[i].last_name << setw(11);
		cout << Arr2[i].department_name << endl;
	}
}
void Administrator::View_All_Doctors(Administrator* Arr1, int size)
{
	cout << "\n\t\t----------All Doctor Deatails----------" << endl;
	cout << "\nDoctor Name" << setw(10) << "Gender" << setw(15) << "Qualification"
		<< setw(15) << "ContactNo" << setw(13) << "UserName" << endl;
	for (int i = 0; i < size - 1; i++)
	{
		cout << Arr1[i].first_name;
		cout << Arr1[i].last_name << setw(9);
		cout << Arr1[i].gender << setw(7);
		cout << Arr1[i].qualification << setw(16);
		cout << "0" << Arr1[i].contact_no << setw(8);
		cout << Arr1[i].username << endl;
	}
}
void Administrator::View_All_Appointments(Administrator* Arr4,int size)
{
	ofstream write;
	cout << "\n\t\t----------All Appointments Deatails----------" << endl;
	cout << "\nAppointmentId" << setw(20) << "AppointmentStatus"<<setw(10)<<"Time" << setw(15) << "PatientId"
		<< setw(20) << "Patient Name" << setw(20) << "DoctorId" << setw(20) << "Doctor Name" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "0" << Arr4[i].department_id << Arr4[i].C_std_number << setw(21);
		cout << Arr4[i].appointment_status << setw(15);
		cout << Arr4[i].set_time << setw(10);
		cout << "0" << Arr4[i].patient_id << setw(17);
		cout << Arr4[i].p_first << Arr4[i].p_last << setw(11);
		cout << "0" << Arr4[i].D_id << Arr4[i].D_std_number << setw(16);
		cout << Arr4[i].first_name<< Arr4[i].last_name << endl;
	}
}
void Administrator::Update_Appointments(Administrator* Arr4, int size,Administrator*Arr3,int size3)
{
	int temp = 0,app_id1;
	cout << "\n\t\t |       All Appointments      |" << endl << endl;
	cout << "\nAppointmentId" << setw(15) << "AppointmentStatus" << setw(20) << "PatientId"
		<< setw(20) << "Patient Name" << setw(20) << "DoctorId" << setw(20) << "Doctor Name" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "0" << Arr4[i].department_id << Arr4[i].C_std_number << setw(21);
		cout << Arr4[i].appointment_status << setw(18);
		cout << "0" << Arr4[i].patient_id << setw(17);
		cout << Arr4[i].p_first << Arr4[i].p_last << setw(11);
		cout << "0" << Arr4[i].D_id << Arr4[i].D_std_number << setw(16);
		cout << Arr4[i].first_name << Arr4[i].last_name << endl;
	}
	cout << "\n\t\t------------Update Appointment------------" << endl << endl;
	cout << "Please Enter The AppointMent Id : ";
	cin >> app_id1;
	temp = app_id1 / 10000;
	app_id1 = app_id1 % 10000;

	for (int i = 0; i < size3 - 1; i++)
	{
		if (Arr3[i].department_id == temp && Arr3[i].C_std_number == app_id1)
		{
			cout << "\n\t\t\t| Update Appointment Status |" << endl;
			cout << "\t\tPress Y For Checked" << endl;
			cout << "\t\tPress N For UnChecked" << endl;
			cout << "\t\tChoose Option =>";
			char opt;
			cin >> opt;
			if (opt == 'Y' || opt == 'y')
			{
				Arr3[i].appointment_status = "Checked";
				Arr4[i].appointment_status = "Checked";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			else if (opt == 'N' || opt == 'n') {
				Arr3[i].appointment_status = "UnChecked";
				Arr4[i].appointment_status = "UnChecked";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			cout << "\n\t\t\t | Update Appointment Time |" << endl;
			cout << "\t\tPress M For Morning" << endl;
			cout << "\t\tPress N For Noon" << endl;
			cout << "\t\tPress A For AfterNoon" << endl;
			cout << "\t\tPress E For Evening" << endl;
			cout << "\t\tPress Y For Night" << endl;
			cout << "\t\tChoose Option =>";
			char opt1;
			cin >> opt1;
			if (opt1 == 'M' || opt1 == 'm')
			{
				Arr3[i].set_time = "Morning";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			else if (opt1 == 'N' || opt1 == 'n') {
				Arr3[i].set_time = "Noon";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			else if (opt1 == 'A' || opt1 == 'a')
			{
				Arr3[i].set_time = "AfterNoon";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			else if (opt1 == 'E' || opt1 == 'e') {
				Arr3[i].set_time = "Evening";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			else if (opt1 == 'Y' || opt1 == 'y')
			{
				Arr3[i].set_time = "Night";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
		}
	}
}
void Administrator::Fee_Status(Administrator* Arr2, int size)
{
	cout << "\t\t\t|     Fee Status Of Of Patients    |" << endl << endl;
	cout << "PatientId" << setw(17) << "Patient Name" << setw(17) << "Fee Status" << endl;
	for (int i = 0; i < size - 1; i++)
	{
		cout << "0" << Arr2[i].department_id << Arr2[i].P_std_number << setw(14);
		cout << Arr2[i].first_name << Arr2[i].last_name << setw(12);
		cout << Arr2[i].fee_status << endl;
	}
}

bool Patient::check1(bool& ch) {
	return ch;
}
void Patient::Sign_in(bool& ch) {
	cout << "\n\t\t|       Sign In       |" << endl;
	cin.ignore();
	cout << "\n\t\tUserName : ";
	getline(cin, username);
	cout << "\t\tPassword : ";
	getline(cin, password);
	if (username == "admin" && password == "admin") {
		ch = true;
		check(ch);
	}
	else {
		check(ch);
	}
}

bool Doctor::check2(bool& ch) {
	return ch;
}
void Doctor::Sign_in1(bool& ch) {
	cout << "\n\t\t|       Sign In       |" << endl;
	cin.ignore();
	cout << "\n\t\tUserName : ";
	getline(cin, username);
	cout << "\t\tPassword : ";
	getline(cin, password);
	if (username == "admin" && password == "admin") {
		ch = true;
		check(ch);
	}
	else {
		check(ch);
	}
}
void Doctor::read(Doctor* Arr4, int& i)
{
	ifstream input;
	input.open("Appointment.txt", ios::app);

	// Checking if the file is opened or not 
	if (input)
	{
		while (input)
		{
			input >> Arr4[i].child_department;
			input >> Arr4[i].department_id;
			input >> Arr4[i].C_std_number;
			input >> Arr4[i].department_name;
			input >> Arr4[i].patient_id;
			input >> Arr4[i].set_time;
			input >> Arr4[i].appointment_status;
			input >> ws;
			i++;
		}
	}
	else {
		cout << "File is not opened " << endl;
	}
}
void Doctor::Doctor_Appointments(Doctor* Arr4, int size)
{
	cout << "\t\t\t----------------apointment-------------" << endl;
	cout << "AppointId" << setw(15) << "AppointTime" << setw(15) << "ApointStaus" << endl;
	for (int i = 0; i < size - 1; i++)
	{
		cout << "0" << Arr4[i].department_id << Arr4[i].D_std_number << setw(15);
		cout << Arr4[i].set_time << setw(15);
		cout << Arr4[i].appointment_status << endl;
	}
}
void Doctor::Update(Doctor* Arr4, int size)
{
	int id, temp;
	cout << "Enter The Id  For Update : ";
	cin >> id;
	temp = id / 10000;
	id = id % 10000;
	for (int i = 0; i < size - 1; i++)
	{
		if (Arr4[i].department_id == temp && Arr4[i].P_std_number == id)
		{
			cout << "\n\t\t\t| Update Appointment Status |" << endl;
			cout << "\t\tPress Y For Checked" << endl;
			cout << "\t\tPress N For UnChecked" << endl;
			cout << "\t\tChoose Option =>";
			char opt;
			cin >> opt;
			if (opt == 'Y' || opt == 'y')
			{
				Arr4[i].appointment_status = "Checked";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			else if (opt == 'N' || opt == 'n') {
				Arr4[i].appointment_status = "UnChecked";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			cout << "\n\t\t\t | Update Appointment Time |" << endl;
			cout << "\t\tPress M For Morning" << endl;
			cout << "\t\tPress N For Noon" << endl;
			cout << "\t\tPress A For AfterNoon" << endl;
			cout << "\t\tPress E For Evening" << endl;
			cout << "\t\tPress Y For Night" << endl;
			cout << "\t\tChoose Option =>";
			char opt1;
			cin >> opt1;
			if (opt1 == 'M' || opt1 == 'm')
			{
				Arr4[i].set_time = "Morning";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			else if (opt1 == 'N' || opt1 == 'n') {
				Arr4[i].set_time = "Noon";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			else if (opt1 == 'A' || opt1 == 'a')
			{
				Arr4[i].set_time = "AfterNoon";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			else if (opt1 == 'E' || opt1 == 'e') {
				Arr4[i].set_time = "Evening";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
			else if (opt1 == 'Y' || opt1 == 'y')
			{
				Arr4[i].set_time = "Night";
				cout << "\n\t\tUpdated Successfully" << endl;
			}
		}
	}
}