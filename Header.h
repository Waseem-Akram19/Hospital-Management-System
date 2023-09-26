#include<iostream>
using namespace std;
struct date {
	int day;
	int month;
	int year;
};
class Administrator {
protected:
	string username, password;
	string first_name, last_name, department_name,child_department, gender, blood_group, address, qualification, 
		   fee_status, appointment_status, set_time,p_first,p_last;
	int D_std_number = 1000, P_std_number = 1000, C_std_number = 1000, salary, option,patient_id,D_id,
		department_id;
	string first, last, first1, last1;
	unsigned long contact_no;
	date reg_date;
public:
	Administrator();
	bool check(bool&);
	void sign_in(bool&);
	void Add_new_Doctor(Administrator*, int);
	void Read_Doctor_File(Administrator*, int&);
	void write_Doctor_File(Administrator*, int);
	void Add_new_Patient(Administrator*, int);
	void Read_Patient_File(Administrator*, int&);
	void write_Patient_File(Administrator*, int);
	void Add_new_appointment(Administrator* ,Administrator*, Administrator*, Administrator*,
		                     Administrator,int, int,int, int);
	void Read_Appointement_File(Administrator*, int&);
	void write_Appointement_File(Administrator*, int);

	void Assign_Appointment(Administrator*, Administrator*, Administrator*,int,int,int&,int, Administrator*, int);

	void Edit_patient_details(Administrator*, int);
	void Edit_doctor_details(Administrator*, int);
	void View_All_Patients(Administrator*, int);
	void View_All_Doctors(Administrator*, int);
	void View_All_Appointments(Administrator*,int);
	void Update_Appointments( Administrator*, int, Administrator*, int);
	void Fee_Status(Administrator*,int);
	~Administrator(){}
};
class Patient :public Administrator {
public:
	Patient();
	bool check1(bool&);
	void Sign_in(bool&);
};
class Doctor :public Administrator {
public:
	Doctor();
	bool check2(bool&);
	void Sign_in1(bool&);
	void read(Doctor*, int&);
	void Doctor_Appointments(Doctor*, int);
	void Update(Doctor*, int);
};