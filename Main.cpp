#include<iostream>
#include"Header.h"
#include<string>
#include<fstream>
using namespace std;
int main()
{
	Administrator A1;    // Obj for Administrator
	Patient obj2;        // Obj For Patient
	Doctor obj3;         // Obj For Doctor
	Doctor* Arr5 = new Doctor[50];   // Obj Array For Doctor Module
	int count = 0, count_patient = 0, count_apoint = 0, opt, count5 = 0;
	static int count_Assign = 0;
	int p_id = 0;

	Administrator* Arr1 = new Administrator[50];  // Array Of Doctors
	Administrator* Arr2 = new Administrator[50];  // Array Of Patient
	Administrator* Arr3 = new Administrator[50];  // Array Of Appointment
	Administrator* Arr4 = new Administrator[50];  // Array Of Assign Appointments

	A1.Read_Doctor_File(Arr1, count);    // Function calling  of read data fromm Doctor file
	A1.Read_Patient_File(Arr2, count_patient);    // Function caliing of read data from Patient File
	A1.Read_Appointement_File(Arr3, count_apoint); // Function calling of read data from appointment file

	while (1) {
		system("cls");
		cout << "\n\t\t\t |     HOSPITAL MANAGEMENT SYSTEM     |" << endl << endl;
		cout << "\t\tPress 1 For Administrator Module" << endl;
		cout << "\t\tPress 2 For Patient Module" << endl;
		cout << "\t\tPress 3 For Doctor Module" << endl;
		cout << "\t\tPress 0 For Exit The Programm" << endl;
		cout << "\t\tChoose The Option=>";
		cin >> opt;
		if (opt == 1) {
			system("cls");
			bool che = false;
			A1.sign_in(che);
			if (A1.check(che) == 1) {
				system("cls");
				while (1) {
					system("cls");
					cout << "\n\t\t|          Select The Option          |" << endl;
					cout << "\n\t\tPress 1 For Add new Doctor" << endl;
					cout << "\t\tPress 2 For Add new Patient" << endl;
					cout << "\t\tPress 3 For Add new appointment" << endl;
					cout << "\t\tPress 4 For Assign Appointment" << endl;
					cout << "\t\tPress 5 For Edit patient details" << endl;
					cout << "\t\tPress 6 For Edit doctor details" << endl;
					cout << "\t\tPress 7 For View all Patients" << endl;
					cout << "\t\tPress 8 For View all Doctors" << endl;
					cout << "\t\tPress 9 For View all Appointments" << endl;
					cout << "\t\tPress 10 For Update Appointment" << endl;
					cout << "\t\tPress 11 For View fee status" << endl;
					cout << "\t\tPress 0 For Exit The Program" << endl;
					int option;
					cout << "\t\tChoose The Option : ";
					cin >> option;
					if (option == 0)
					{
						exit(0);
					}
					switch (option)
					{
					case 1:
						system("cls");
						A1.Add_new_Doctor(Arr1, count);
						delete[]Arr1;
						Arr1 = new Administrator[50];
						count = 0;
						A1.Read_Doctor_File(Arr1, count);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0");
						system("cls");
						break;
					case 2:
						system("cls");
						A1.Add_new_Patient(Arr2, count_patient);
						delete[]Arr2;
						Arr2 = new Administrator[50];
						count_patient = 0;
						A1.Read_Patient_File(Arr2, count_patient);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0)");
						system("cls");
						break;
					case  3:
						system("cls");
						A1.Add_new_appointment(Arr1, Arr2,Arr3, Arr4,A1,
							count, count_patient,count_apoint,count_Assign);
						delete[]Arr3;
						Arr3 = new Administrator[50];
						count_apoint = 0;
						A1.Read_Appointement_File(Arr3,count_apoint);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0)");
						system("cls");
						break;
					case 4:
						system("cls");
						A1.Assign_Appointment(Arr1,Arr2,Arr4, count,count_patient,count_Assign,p_id, Arr3, count_apoint);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0)");
						system("cls");
						break;
					case 5:
						system("cls");
						A1.Edit_patient_details(Arr2, count_patient);
						A1.write_Patient_File(Arr2, count_patient);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0)");
						system("cls");
						break;
					case 6:
						system("cls");
						A1.Edit_doctor_details(Arr1, count);
						A1.write_Doctor_File(Arr1, count);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0)");
						system("cls");
						break;
					case 7:
						system("cls");
						A1.View_All_Patients(Arr2, count_patient);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0)");
						system("cls");
						break;
					case 8:
						system("cls");
						A1.View_All_Doctors(Arr1, count);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0");
						system("cls");
						break;
					case 9:
						system("cls");
						A1.View_All_Appointments(Arr4,count_Assign);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0");
						system("cls");
						break;
					case 10:
						system("cls");
						A1.Update_Appointments(Arr4,count_Assign,Arr3,count_apoint);
						A1.write_Appointement_File(Arr3, count_apoint);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0");
						system("cls");
						break;
					case 11:
						system("cls");
						A1.Fee_Status(Arr2, count_patient);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0");
						system("cls");
						break;
					}
				}
			}
			else if (A1.check(che) == 0) {
				cout << "\n\t\tYour Username And Password Is InCorrect.";
				cout << "Please Correct It." << endl;
			}
			system("pause>1");
		}
		else if (opt == 2) {
			system("cls");
			bool che = false;
			obj2.Sign_in(che);
			if (obj2.check1(che) == 1) {
				system("cls");
				while (1) {
					int opt1;
					cout << "\n\t\t|          Select The Option          |" << endl;
					cout << "\n\t\tPress 1 For View All Appointments" << endl;
					cout << "\t\tPress 2 For View Fee Status" << endl;
					cout << "\t\tPress 0 For Exit" << endl;
					cout << "\t\tChoose The Option=>";
					cin >> opt1;
					if (opt1 == 1)
					{
						system("cls");
						A1.View_All_Appointments(Arr4,count_Assign);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0");
						system("cls");
					}
					else if (opt1 == 2)
					{
						system("cls");
						obj2.Fee_Status(Arr2, count_patient);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0)");
						system("cls");
					}
					else if (opt1 == 0) {
						exit(0);
					}
				}
			}
			else if (obj2.check1(che) == 0) {
				cout << "\n\t\tYour Username And Password Is InCorrect.";
				cout << "Please Correct It." << endl;
			}
		}
		else if (opt == 3) {
			system("cls");
			bool che = false;
			obj3.Sign_in1(che);
			if (obj3.check2(che) == 1) {
				system("cls");
				while (1) {
					int opt2;
					cout << "\n\t\t|          Select The Option          |" << endl;
					cout << "\n\t\tPress 1 For Doctor Appointments" << endl;
					cout << "\t\tPress 2 For Update Appointments" << endl;
					cout << "\t\tPress 0 For Exit" << endl;
					cout << "\t\tChoose The Option=>";
					cin >> opt2;
					if (opt2 == 1)
					{
						system("cls");
						obj3.read(Arr5, count5);
						obj3.Doctor_Appointments(Arr5, count5);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0)");
						system("cls");
					}
					else if (opt2 == 2)
					{
						system("cls");
						obj3.Update(Arr5, count_patient);
						cout << "\n\t\tPress 0 For Back" << endl;
						system("pause>0)");
						system("cls");
					}
					else if (opt2 == 0) {
						system("cls");
					}
				}
			}
			else if (obj3.check2(che) == 0) {
				cout << "\n\t\tYour Username And Password Is InCorrect.";
				cout << "Please Correct It." << endl;
			}
		}
		else if (opt == 0) {
			exit(0);
		}
	}
	delete[] Arr1;
	delete[] Arr2;
	delete[] Arr3;
	Arr1 = NULL;
	Arr2 = NULL;
	Arr2 = NULL;
	system("pause");
	return 0;
}