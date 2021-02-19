#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

class Student
{
	 int admno;
	 char name[20];
	 char gender;
	 int std;
	 float marks;
	 float percentage;
	 
	 public:
	  void getData();
	  void showData();
	  int getAdmno(){return admno;}
}s;

void Student::getData()
{
	 cout<<"Enter Student Details"<<endl;
	 cout<<"Enter Admission No.     : "; 
	 cin>>admno;
	 cout<<"Enter Full Name         : ";
	 cin.ignore(); cin.getline(name,20);
	 cout<<"Enter Gender (M/F)      : "; 
	 cin>>gender;
	 cout<<"Enter Standard          : ";
	 cin>>std;
	 cout<<"Enter Marks (out of 500): "; 
	 cin>>marks;
	 cout<<endl;
	 percentage=marks*100.00/500.00;
}

void Student::showData()
{
	 cout<<"Admission No.     : "<<admno<<endl;
	 cout<<"Full Name         : "<<name<<endl;
	 cout<<"Gender            : "<<gender<<endl;
	 cout<<"Standard          : "<<std<<endl;
	 cout<<"Marks (out of 500): "<<marks<<endl;
	 cout<<"Percentage        : "<<percentage<<endl;
	 cout<<endl;
}

void addData()
{
	 ofstream fout;
	 fout.open("Students.dat",ios::binary|ios::out|ios::app);
	 s.getData();
	 fout.write((char*)&s,sizeof(s));
	 fout.close();
	 cout<<"Data Successfully Saved to File...."<<endl;
}

void displayData()
{
	 ifstream fin;
	 fin.open("Students.dat",ios::in|ios::binary);
	 while(fin.read((char*)&s,sizeof(s)))
	 {
	  s.showData();
	 }
	 fin.close();
	 cout<<"Data Reading from File Successfully Done...."<<endl;
}

void extractData()
{
	 int n, flag=0;
	 ifstream fin;
	 fin.open("Students.dat",ios::in|ios::binary);
	 cout<<"Enter Admission Number you want to search : ";
	 cin>>n;
	 
	 while(fin.read((char*)&s,sizeof(s)))
	 {
	  if(n==s.getAdmno())
	  {
	   cout<<"The Details of Admission No. "<<n<<" shown herewith:"<<endl;
	   s.showData();
	   flag++;
	  }
	 }
	 fin.close();
	 if(flag==0)
	  cout<<"The Admission No. "<<n<<" not found...."<<endl;
	 cout<<"Data Reading from File Successfully Done...."<<endl;
}

void deleteData()
{
	 int n, flag=0;
	 ifstream fin;
	 ofstream fout,tout;
	
	 fin.open("Students.dat",ios::in|ios::binary);
	 fout.open("TempStud.dat",ios::out|ios::app|ios::binary);
	
	 cout<<"Enter Admission Number you want to delete: ";
	 cin>>n;
	 
	 while(fin.read((char*)&s,sizeof(s)))
	 {
	  if(n==s.getAdmno())
	  {
	   cout<<"The Following Admission No. "<<n<<" has been deleted:"<<endl;
	   s.showData();
	   flag++;
	  }
	  else
	  {
	   fout.write((char*)&s,sizeof(s));
	  }
	 }
	 fout.close();
	 fin.close();
	 if(flag==0)
	  cout<<"The Admission No. "<<n<<" not found...."<<endl;
	 remove("Students.dat");
	 rename("tempStud.dat","Students.dat");
}

void project()
{
	 int ch;
	 do
	 {
	  system("cls");
	  cout<<"...............STUDENT MANAGEMENT SYSTEM.............."<<endl;
	  cout<<"0. Exit from Program"<<endl;
	  cout<<"1. Write Data to File"<<endl;
	  cout<<"2. Read Data From File"<<endl;
	  cout<<"3. Extract Data From File"<<endl;
	  cout<<"4. Delete Data From File"<<endl;
	  cout<<"Enter your choice  : ";
	  cin>>ch;
	  system("cls");
	  switch(ch)
	  {
	   case 1: addData(); break;
	   case 2: displayData(); break;
	   case 3: extractData(); break;
	   case 4: deleteData(); break;
	  }
	  system("pause");
	 }while(ch);
}

int main()
{
	 project();
}
