
// PROGRAMING-FUNDAMENTAL SEMESTER-PROJECT
// KHIZAR AMEER -



#include <iostream>
#include <fstream>
#include <string>
using namespace std;

 //                  FUNTIONS DECLERATION.


void Store_in_MyFile (string [],string [],float [],int);

void  cgpa(string [],float [],int);

void FeeDefault (string [],string [],string [],bool [],float []);

void SelectNumber (string [],string [],string [],bool [],float []);

void loginSystem (string [],string [],string [],bool [],float []);

void PreRequisite ();

void MainMenu ();
 
void FILESAVE (string [],string [],string [],bool [],float [],string [],string []);

void Registeration (string [],string [],string [],bool [],float [],int);

int main()
{
	
   //                            	                 DATA OF ALL STUDENTS.

	
	string Student_Name[5]     = {"KHIZAR-AMEER", "WAJID-ABID", "BILAL-AHMED", "HAIDER-CH", "SAFRA"};
	
	string Student_ID[5]       = {"21016065019","21016065027","21016065011","21016065069","21016065004"};
	
	string Student_Pass[5]     = {"khizar123", "wajid123", "bilal123", "haider123", "safra123"};
	
	bool Student_Fees[5]       = {1, 0, 1, 1, 0};
	
	float Student_CGPA[5]      = {3.5, 3.4, 2.9, 1.8, 3.1};
	
	string Student_Address[5]  = {"BERLIN"," SIALKOT"," SIALKOT"," SIALKOT" , " SIALKOT"};
	
	string Student_Number[5]   = {"6139976", "6139975", "7530005", "7145512", "6320479"};
	

	FILESAVE (Student_Name, Student_ID,Student_Pass,Student_Fees,Student_CGPA,Student_Address,Student_Number);

	MainMenu ();

	SelectNumber (Student_Name, Student_ID, Student_Pass, Student_Fees, Student_CGPA); 
	
	return 0;
	
}

//                                            VARIATION OF FUNCTIONS

	
void FILESAVE (string Student_Name[],string Student_ID[],string Student_Pass[],bool Student_Fees[],float Student_CGPA[],string Student_Address[],string Student_Number[])
{
	
	fstream MyFile;
	MyFile.open("StoreData.txt", ios::out);
	if(MyFile.is_open())
	{
		MyFile << "-------------------------DATA  STORED------------------------------"<<endl;
		for(int x = 0; x < 5; x++)
		{
			MyFile<<"   Data of Student No "<< x+1  << endl;
			MyFile<<"   Name: " << Student_Name[x]  << endl;
			MyFile<<"   ID: " << Student_ID[x]  << endl;
			MyFile<<"   Password: " << Student_Pass[x]  << endl;
			MyFile<<"   Fees: " << Student_Fees[x]  << endl;
			MyFile<<"   CGPA: " << Student_CGPA[x]  << endl;
			MyFile<<"   Address: "  << Student_Address[x]    << endl;
			MyFile<<"   Number: " << Student_Number[x]  << endl;
			MyFile<<"-------------------------------------------------------------------"<<endl;
		}
		
		MyFile.close();
	}
}
	
void MainMenu()
{
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	cout<<"********************** UMT---------    REGISTRATION   --------SYSTEM ********************"<<endl;
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
	
	cout<<"--*****<<    PRESS 1 TO ENTER LOGIN SYSTEM." <<endl;	
	cout<<"--*****<<    PRESS 6 TO EXIT THE SYSTEM." <<endl;	
	cout<<endl<<endl;
}	

void SelectNumber(string Student_Name[],string Student_ID[], string Student_Pass[], bool Student_Fees[], float Student_CGPA[])
{
	int select;
	cout << "----------";
	cin >> select;
	cout << "----------";
	
	switch(select)
	{
		case 1:
		    loginSystem(Student_Name, Student_ID, Student_Pass, Student_Fees, Student_CGPA);
			break;
		case 6:
			cout<<" EXITED----:( "<<endl;
			break;
			
		default:
			cout<<" INVALID OPTION "<<endl;
	}
}

void loginSystem (string Student_Name[], string Student_ID[], string Student_Pass[], bool Student_Fees[], float Student_CGPA[])
{
	cout<<endl<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"------------------------ LOGIN  INFORMATION--------------------------"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
	
	string ID, pass;
	bool a=1;
	while(a==1)
	{
		cout<<"<--------- Enter ID and Password"<<endl;
		cout<<"<--------- ID : ";
		cin>>ID;
		cout<<"<--------- PASSWORD : ";
		cin>>pass;
		
		int b=0;
		
		for(int i = 0; i < 5; i++)
		{
			if(ID==Student_ID[i] and pass==Student_Pass[i])
			{
				a=0;
				b=i;
				
				cout<<"---------------------------------------------------------------------"<<endl;
	            cout<<"---------------------------------------------------------------------"<<endl;
                cout<<"------------------- LOGIN  SUCCESSFULLY YOU ARE IN  -----------------"<<endl;
                cout<<"---------------------------------------------------------------------"<<endl;
	            cout<<"---------------------------------------------------------------------"<<endl;
	            cout<<endl<<endl;
			 
				
				cout<<"-------- PRESS 2 TO REGISTER.---------" <<endl;	
				cout<<"-------- PRESS 3 TO SEE LIST OF FEE DEFAULTERS.--------" <<endl;	
				cout<<"-------- PRESS 4 TO SEE CGPA OF A STUDENT.----------" <<endl;	
				cout<<"-------- PRESS 5 TO SEE PRE-REQUISITE OF COURSE.---------" <<endl;
				cout<<endl<<endl;
				
				int q;
				cin>>q;
				
				switch(q)
				{
					case 2:
					Registeration(Student_Name, Student_ID, Student_Pass, Student_Fees, Student_CGPA,b);
					break;
					case 3:
					FeeDefault (Student_Name, Student_ID, Student_Pass, Student_Fees, Student_CGPA);
					break;
					case 4:
					cgpa(Student_Name, Student_CGPA,b);
					break;
					case 5:
					PreRequisite();
					break;
				}
				break;	
			}		
		}
		
		if(a==1)
		{
			cout<<"Invalid, Try again"<<endl;
		}
	}
}


void Registeration(string Student_Name[],string Student_ID[],string Student_Pass[],bool Student_Fees[], float Student_CGPA[],int b)
{
    cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"---------------------- R E G I S T R A T I O N S --------------------"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
	
	if(Student_Fees[b]==0)
	{
		cout<<" PLEASE CLEAR YOUR ALL FEE DEUS "<<endl;
		
	}
	else
	{
		if(Student_CGPA[b] > 3.0)
		{
			cout<<"Object Oriented Programming"<<endl;
			cout<<"Discrete Structures"<<endl;
			cout<<"Applied Physics"<<endl;
			cout<<"Object Oriented Programming Lab"<<endl;
			cout<<"Composition & Communication"<<endl;
			cout<<"Applied Physics Lab"<<endl;
			cout<<"Pakistan Studies"<<endl;
			
		}
		else if(Student_CGPA[b] > 2.0)
		{
			
			cout<<"Object Oriented Programming"<<endl;
			cout<<"Discrete Structures"<<endl;
			cout<<"Applied Physics"<<endl;
		}
		else if(Student_CGPA[b] <= 2.0)
		{
			cout<<"YOUR CGPA IS LESSER. ONLY TWO COURSES. BEWARE! "<<endl;
			
			   cout<<"2nd Semester Courses"<<endl;
			cout<<" Object Oriented Programming"<<endl;
			cout<<" Discrete Structures"<<endl;
		}
		
		Store_in_MyFile (Student_Name,Student_ID,Student_CGPA,b);
		
		}
}

void Store_in_MyFile(string Student_Name[],string Student_ID[],float Student_CGPA[],int b)
{
	string subj[7]={"OOP","Discrete Structures","Applied Physics","OOP LAB","Composition & Communication","Applied Physics Lab","Pakistan Studies"};
	
	fstream jFile;
	
	jFile.open("StoreData.txt", ios::app);
	
		jFile<<Student_Name[b]<<endl;
		
		jFile<<"ID: "<<Student_ID[b]<<endl;
		
		jFile<<"CGPA: "<<Student_CGPA[b]<<endl;
		
		
		if(Student_CGPA[b] > (3.0))
		{
			for(int i = 0; i < 7; i++)
			{
				jFile<<subj[i]<<endl;
			}
		}
		else if(Student_CGPA[b] > (2.0))
		{
			for(int i = 0; i < 3; i++)
			{
				jFile<<subj[i]<<endl;
			}
		}
		else if(Student_CGPA[b] <= (2.0))
 		{
			for(int i = 0; i < 2; i++)
			{
				jFile<<subj[i]<<endl;
			}
		}
		
		jFile.close();	
}

 void FeeDefault(string Student_Name[],string Student_ID[],string Student_Pass[],bool Student_Fees[],float Student_CGPA[])
{
 
	cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"----------------------       FEE - DEFAULTERS    --------------------"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
	 
	cout<<endl<<endl;
	 
	cout<<"FEE DEFAULTER STUDENTS : "<<endl;
	
	for(int i = 0; i < 5; i++)
	{
		if(Student_Fees[i]==0)
		{
			cout<<"------->> Name:  "<<Student_Name[i]<<endl;
			cout<<"------->> ID:  "<<Student_ID[i]<<endl;
			cout<<"------->> Password: "<<Student_Pass[i]<<endl;
			cout<<"------->> CGPA: "<<Student_CGPA[i]<<endl;
		}
	}
	
}

void cgpa(string Student_Name[], float Student_CGPA[], int b)
{
    
	cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"----------------------      CGPA OF STUDENTS     --------------------"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
	
	cout<<endl<<endl;
	cout<<Student_Name[b]<<endl;
	cout<<"YOUR CGPA IS HERE :  "<<Student_CGPA[b]<<endl;
}

void PreRequisite()
{
	  
	cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"----------------------        PRE - REQUISITE    --------------------"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
 
	cout<<endl<<endl;
	cout<<" Object Oriented Programming          PF"<<endl;
	
	cout<<" Object Oriented Programming Lab      PF Lab"<<endl;
	
	cout<<" Applied Physics                      No Pre requisite"<<endl;
	
	cout<<" Composition & Communication          English Grammer & Composition"<<endl;
	
	cout<<" Discrete Structures                  No Pre requisite"<<endl;
	
	cout<<" Applied Physics Lab                  No Pre requisite"<<endl;
	
	cout<<" Pakistan Studes                      No Pre requisite"<<endl;
}

