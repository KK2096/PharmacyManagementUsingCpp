#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<cstring>

using namespace std;

string name,id,quan;
string reciept_number;
double cost,quantity,amount,temp;
string customerName;
int x,y;
string payment;
string date;
class Phar
{
	public:
		void AddRecord();
		void ListRecord();
		void SearchRecord();
		void UpdateRecord();
		void DeleteRecord();
		void place_order();
		void ViewReceipt();
		void OrderSummary();
};
int main()
{
	int choice;
	char x;
	Phar b;

    do{

       // system("cls");
        cout<<"\n\n\t***PHARMACY MANAGEMENT SYSTEM***";
		cout<<"\n\n \t1. Add New medicine";
		cout<<"\n \t2. Display medicines";
		cout<<"\n \t3. Check Specific medicine";
		cout<<"\n \t4. Update medicine";
		cout<<"\n \t5. Delete medicine";
		cout<<"\n \t6. Generate Bill";
		cout<<"\n \t7. View Bill Reciept";
		cout<<"\n \t8. View  Summary of customer";
		cout<<"\n \t9. Exit";
	cout<<"\n\n Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:

			b.AddRecord();
			break;

		case 2:
			b.ListRecord();
			break;
		case 3:
			b.SearchRecord();
			break;
		case 4:
			b.UpdateRecord();
			break;
		case 5:
			b.DeleteRecord();
			break;
		case 6:
		   b.place_order();
		    break;

        case 7:
            b.ViewReceipt();
            break;

        case 8:
            b.OrderSummary();
            break;
		case 9:
			exit(0);
		default:
			cout<<"\n\n Invalid choice...Please Try Again...";
	}
	}while(choice!=9);
	getch();

}
void Phar::AddRecord()
{
		system("cls");
		fstream file;

		cout<<"\n\n\t\t\t\t Add New Medicine Records";
		cout<<"\n\n Medicine ID : ";
		cin>>id;
        cout<<"\n Medicine Name : ";
		cin>>name;

		int namelen=name.length();
        int k=0;
        char name1[namelen];

		strcpy(name1,name.c_str());
		for(int i=0; i< strlen(name1); i++)
        {
            if(!isalnum(name1[i])  )
            {
                cout<<"Enter valid name...\n"<<endl;
                k++;
            }
        }

        if(k==1)
        {
            cout<<"\n Medicine Name : ";
            cin>>name;
        }

		cout<<"\n Cost : ";
		cin>>cost;
		cout<<"\n Quantity : ";
		cin>>quan;

        file.open("medicine.txt",ios::out|ios::app);
		file<<" "<<id<<" "<<name<<" "<<cost<<" "<<quan<<"\n";
		file.close();
}

void Phar::ListRecord()
{
		int flag=0;
		system("cls");
		fstream file;
		cout<<"\n\n\t\t\t\tAll Medicines Records\n\n";
		file.open("medicine.txt",ios::in);

		if(!file)
            cout<<"\n\n File Openning Error...";

		else
		{

            cout<<"Medicine Records "<<endl;
            cout<<"================================================================="<<endl;

            cout<<"  ID   |      Name        |           Cost     |        Quantity  "<<endl<<"================================================================\n";

			file>>id>>name>>cost>>quan;
			while(!file.eof())
			{
				cout<<setw(5)<<id<<setw(20)<<name<<setw(18)<<cost<<setw(17)<<quan<<"\n";
				file>>id>>name>>cost>>quan;
			}
			file.close();

		}
}

void Phar::SearchRecord()
{
		system("cls");
		fstream file;
		int count=0;
		string idd,namme;
		cout<<"\n\n\t\t\t\tSearch Records"<<endl;
		file.open("medicine.txt",ios::in);

		if(!file)
		cout<<"\n\n File Openning Error...";

		else
		{
			int choice;
			//do{
			cout<<"\n1.Search Medicine By ID "<<endl;
			cout<<"2. Search Medicine By Name "<<endl;
			cout<<"\nEnter Your Choice >>";
			cin>>choice;
			cout<<endl;

			switch(choice)
			{

            case 1:
			cout<<"\n\n Enter Medicine ID to be Search : ";
			cin>>idd;
			file>>id>>name>>cost>>quan;

			while(!file.eof())
			{
				if(idd == id)
				{
					system("cls");
					 cout<<"Medicine Records "<<endl;
                    cout<<"======================================================"<<endl;

                    cout<<"  ID   |      Name        |    Cost     |    Quantity  "<<endl<<"=====================================================\n";
				    cout<<setw(5)<<id<<setw(10)<<name<<setw(18)<<cost<<setw(17)<<quan<<"\n";


					count++;
					break;
				}
				file>>id>>name>>cost>>quan;

			}
            break;


			case 2:

            cout<<"\n\n Enter Medicine Name to be Search : ";
			cin>>namme;
			file>>id>>name>>cost>>quan;

			while(!file.eof())
			{
				if(namme == name)
				{
					system("cls");
                    cout<<"Medicine Records "<<endl;
                    cout<<"======================================================"<<endl;

                    cout<<"  ID   |      Name        |    Cost     |    Quantity  "<<endl<<"=====================================================\n";
				    cout<<setw(5)<<id<<setw(10)<<name<<setw(18)<<cost<<setw(17)<<quan<<"\n";


					count++;
					break;
				}
				file>>id>>name>>cost>>quan;
			}
			break;

			}


			file.close();
			if(count == 0)
			cout<<"\n\n Medicine ID Not Found...";
		}

}

void Phar::UpdateRecord()
{
		system("cls");
		fstream file,file1;
		int count=0;
		string name1,cost1,idd,quan1;
		cout<<"\n\n\t\t\t\tUpdate Medicine Record";
		file1.open("F://medic1.txt",ios::app|ios::out);
		file.open("medicine.txt",ios::in);

		if(!file)
		cout<<"\n\n File Openning Error...";

		else
		{
			cout<<"\n\n Medicine ID to be update : ";
			cin>>id;
			file>>idd>>name>>cost>>quan;
			while(!file.eof())
			{
				if(id == idd)
				{
					system("cls");
					int ch;
					cout<<"\n\nId Found..\nEnter New Records"<<endl;
					int x,y,z;
					cout<<"Press 1. To Update Medicine Name : "<<endl;
					cout<<"Press 2. To Update Medicine Cost : "<<endl;
					cout<<"Press 3. To Update Medicine Quantity : "<<endl;
					cin>>x;
					if(x==1)
                    {
                        cout<<"\n\nEnter New medicine Name for Medicine "<<name<<" : ";
                        cin>>name1;
                        file1<<" "<<id<<" "<<name1<<" "<<cost<<" "<<quan<<"\n";
                       // file>>id>>name1>>nam>>quan;
					}
					if(x==2)
                    {
                        cout<<"\nEnter New cost for Medicine "<<name<<" : ";
                        cin>>cost1;
                        file1<<" "<<id<<" "<<name<<" "<<cost1<<" "<<quan<<"\n";
					}
					if(x==3)
					{
                        cout<<"\nEnter New Quantity for Medicine "<<name<<" : ";
                        cin>>quan1;
                        file1<<" "<<id<<" "<<name<<" "<<cost<<" "<<quan1<<"\n";
					}
					count++;
				}
				else
				file1<<" "<<idd<<" "<<name<<" "<<cost<<" "<<quan<<"\n";
				file>>idd>>name>>cost>>quan;
			}
            cout<<"\n\n Medicine ID Updated successfully!...";

			if(count == 0)
			cout<<"\n\n Medicine ID Not Found...";
		}
		file.close();
		file1.close();
		remove("medicine.txt");
		rename("F://medic1.txt","medicine.txt");
}

void Phar::DeleteRecord()
{

	    system("cls");
		fstream file,file1;
		int count=0;
		string idd;
		cout<<"\n\n\t\t\t\tDelete medicine Record";
		file1.open("F://medic1.txt",ios::app|ios::out);
		file.open("medicine.txt",ios::in);

		if(!file)
		cout<<"\n\n File Openning Error...";

		else
		{
			cout<<"\n\n Medicine ID : ";
			cin>>id;
			file>>idd>>name>>cost>>quan;
			while(!file.eof())
			{
				if(id == idd)
				{
					system("cls");
					cout<<"\n\n Medicine Record Deleted Successfully...";
					count++;
				}
				else
				file1<<" "<<idd<<" "<<name<<" "<<cost<<" "<<quan<<"\n";
				file>>idd>>name>>cost>>quan;
			}
			if(count == 0)
			cout<<"\n\n Medicine ID Not Found...";
		}
		file.close();
		file1.close();
		remove("medicine.txt");
		rename("F://medic1.txt","medicine.txt");
}


void Phar::place_order()
{

		fstream file,file1;
		fstream myfile;
		int totalitems,count1=0;
		string idd;
		int ch;
		file.open("medicine.txt",ios::in);
        cout << "Type Order no: ";
        cin >> reciept_number;

         cout<< "Enter Customer Name: ";
        cin>> customerName;

        int namelen=customerName.length();
        int k=0;
        char cust_name[namelen];

		strcpy(cust_name,customerName.c_str());
		for(int i=0; i< strlen(cust_name); i++)
        {
            if(!isalpha(cust_name[i]))
            {
                cout<<"Enter Characters only...\n"<<endl;
                cout<<"\nName : ";
                cin>>customerName;
            }
        }

        ListRecord();
        do{

            cout<<"\n1) Select Medicine.."<<endl;
            cout<<"2) Go back and View total "<<endl;
            cout<<"\nEnter your choice"<<endl;
            cin>>ch;
            switch(ch)
            {

            case 1:


                cout<<"\n\nEnter Medicine ID to Buy medicine : ";
                cin>>idd;
                file.seekg (0, ios::beg);
                file>>id>>name>>cost>>quan;
                while(!file.eof())
                {

                    amount=0;
                    if(idd == id)
                    {

                        cout<<"Enter quantity: ";
                        cin>>quantity;
                        int x1=cost;

                        int y1=quantity;
                        amount=x1*y1;
                        //	temp=amount;
                        temp=temp+amount;
                        cout << "The amount: " << amount<<endl;
                        cout<<endl;
                        count1++;


                        file1.open("bill.txt",ios::out|ios::app);
                        file1<<" "<<reciept_number<<" "<<customerName<<" "<<name<<" "<<quantity<<" "<<amount<<" "<<temp<<"\n";

                        file1.close();


                        break;
                    }

                    file>>id>>name>>cost>>quan;

                }
                break;

            case 2:
                goto s;
                break;
}
            if(count1 == 0)
                cout<<"\n\n Medicine ID Not Found...\n\n";

        }while(ch!=2);

        s:
        cout << "\nTotal amount Need to pay is : " << temp<<endl;
        cout<<endl;
        string var;
        cout << "Is Payment done by Customer ..?? : " <<endl;
        cout << "yes  or  no : " <<endl;
        cin>>var;


        if(var=="yes")
        {
            cout<<"\nPayment Successful"<<endl;
            payment="Paid";
        }
        if(var=="no")
        {
            cout<<"\nPayment Not done"<<endl;
            payment="Unpaid";
        }

        myfile.open("summary.txt",ios::out|ios::app);
        myfile<<" "<<reciept_number<<" "<<customerName<<" "<<temp<<" "<<payment<<"\n";
        myfile.close();

        file.close();

}

void Phar::ViewReceipt()
{
        int count=0,choice;
        string num2,nm;
        fstream file;
		cout<<"\n\n\t\t\t\tAll Medicines Records\n\n";
		file.open("bill.txt",ios::in);
		//file1.open("summary.txt",ios::in);

		if(!file)
		cout<<"\n\n File Openning Error...";

		else
        {
            cout<<"\n1. View Receipt By Receipt Number"<<endl;
            cout<<"2. View Receipt By Customer Name"<<endl;
            cout<<"Enter Your Choice >> ";
            cin>>choice;
            cout<<endl;

            switch(choice)
            {


            case 1:
            cout<<" Enter the Reciept Number To Print The Reciept\n";
            cin>>num2;
            cout<<"\n";
            cout<<"============================================================"<<endl;
            cout <<"\t\tHere is the Order list\n";
            cout<<"============================================================"<<endl;
			file>>reciept_number>>customerName>>name>>quantity>>amount>>temp;

			while(!file.eof())
			{
				if(num2 == reciept_number)
				{

					 if(count>=1)
                     {
                         goto a;
                     }
					 cout<<"Medicine Records "<<endl;

					 cout <<"Reciept Number : "<<reciept_number;
                     cout <<"\n";
                     cout<<"Customer Name: "<<customerName<<endl;


                    cout<<"=========================================================="<<endl;

                    cout<<"  Medicine Name      |   Quantity    |     Cost    "<<endl<<"=========================================================\n";

				   a: cout<<setw(10)<<name<<setw(18)<<quantity<<setw(17)<<amount<<"\n";


					count++;

				}

				file>>reciept_number>>customerName>>name>>quantity>>amount>>temp;
			}
			break;

			case 2:

            cout<<" Enter the Customer Name To Print The Reciept\n";
            cin>>nm;
            cout<<"\n";
            cout<<"==========================================================================="<<endl;
            cout <<"\t\tHere is the Order list\n";
            cout<<"==========================================================================="<<endl;
			file>>reciept_number>>customerName>>name>>quantity>>amount>>temp;
			while(!file.eof())
			{
				if(nm == customerName)
				{
					//system("cls");
					 if(count>=1)
                     {
                         goto a1;
                     }
					 cout<<"Medicine Records "<<endl;

					 cout <<"Reciept Number : "<<reciept_number;
                     cout <<"\n";
                     cout<<"Customer Name: "<<customerName<<endl;


                    cout<<"=========================================================="<<endl;

                    cout<<" Medicine Name      |   Quantity    |     Cost    "<<endl<<"=========================================================\n";

				   a1: cout<<setw(10)<<name<<setw(18)<<quantity<<setw(17)<<amount<<"\n";

					count++;
					//break;
				}

				file>>reciept_number>>customerName>>name>>quantity>>amount>>temp;
			}
			break;


        }
            cout<<"\nTotal Cost:"<<temp;
			file.close();
			if(count == 0)
			cout<<"\n\n Medicine ID Not Found...";
		}

}
void Phar::OrderSummary()
{

        fstream file;
		cout<<"\n\n\t\t\t\tSummary of Medicines Order\n\n";
		file.open("summary.txt",ios::in);
		if(!file)
		cout<<"\n\n File Openning Error...";
		else{

			file>>reciept_number>>customerName>>temp>>payment;
			cout<<"==========================================================================="<<endl;

            cout<<" Receipt no  |     Customer       |     Total  Cost    |   Payment Status"<<endl<<"==========================================================================\n";

			while(!file.eof())
            {

                cout<<setw(6)<<reciept_number<<setw(18)<<customerName<<setw(22)<<temp<<setw(20)<<payment<<"\n";
               // count++;
                file>>reciept_number>>customerName>>temp>>payment;


            }

            file.close();
		}

}

