#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class student
{
public:
    string fname, dept, lname, usn, sem;
} s[100];
class teacher
{
public:
    string tname, tlname, sub, exper;
} t[100];
int main()
{
    int login();
    login();
    int i=0,j;
    string fnd,srch;
    char choice;
    while(1)
    {
        cout<<"\n\t\t\t1. Students Information"<<endl;
        cout<<"\t\t\t2. Staffs Information"<<endl;
        cout<<"\t\t\t3. Exit "<<endl;
        cout<<"\n\t\t\tEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case '1':
        {
            while(1)
            {
                char c2;
                cout<<"\n\t\t\t---STUDENTS INFORMATION---\n\n\n";
                cout<<"\t\t\t1. Create new entry\n";
                cout<<"\t\t\t2. Find and display entry\n";
                cout<<"\t\t\t3. Back to main\n";
                cout<<"\n\n\t\t\tEnter your choice: ";
                cin>>c2;
                switch(c2)
                {
                case '1':
                {
                    ofstream f1("student.txt",ios::app);
                    for( i=0; c2!='n'&&c2!='N'; i++)
                    {
                        if((c2=='1')||(c2=='Y')||(c2=='y'))
                        {
                            cout<<"\n\t\t\tEnter First name: ";
                            cin>>s[i].fname;
                            cout<<"\t\t\tEnter Last name: ";
                            cin>>s[i].lname;
                            cout<<"\t\t\tEnter Usn: ";
                            cin>>s[i].usn;
                            cout<<"\t\t\tEnter the semester: ";
                            cin>>s[i].sem;
                            cout<<"\t\t\tEnter department name: ";
                            cin>>s[i].dept;
                            f1<<s[i].fname<<endl<<s[i].lname<<endl<<s[i].usn<<endl<<s[i].sem<<endl<<s[i].
                              dept<<endl;
                            cout<<"\n\n\t\t\tDo you want to enter more students details? (Y/N)";
                            cin>>c2;
                        }
                    }
                    f1.close();
                }
                continue;
                case '2':
                {
                    ifstream f2("student.txt");
                    cout<<"\n\t\t\tEnter student name to display student's record: ";
                    cin>>fnd;
                    int notFound = 0;
                    for( j=0; !f2.eof(); j++)
                    {
                        getline(f2,s[j].fname);
                        if(s[j].fname==fnd)
                        {
                            notFound = 1;
                            cout<<"\n\t\t\tFirst Name: "<<s[j].fname;
                            getline(f2,s[j].lname);
                            cout<<"\t\t\tLast Name: "<<s[j].lname;
                            getline(f2,s[j].usn);
                            cout<<"\t\t\tUSN: "<<s[j].usn;
                            getline(f2,s[j].sem);
                            cout<<"\t\t\tSemester: "<<s[j].sem;
                            getline(f2,s[j].dept);
                            cout<<"\t\t\tDepartment: "<<s[j].dept;
                            cout<<"\n";
                        }
                    }
                    if(notFound==0)
                    {
                        cout<<"\n\t\t\tNo data found"<<endl;
                    }
                    f2.close();
                }
                continue;
                case '3':
                {
                    break;
                }
                }
                break;
            }
            continue;
        }
        case '2':
        {
            while(1)
            {
                cout<<"\n\t\t\t---STAFF INFORMATION---\n\n\n";
                cout<<"\t\t\t1.Create new entry\n";
                cout<<"\t\t\t2.Find staff and display\n";
                cout<<"\t\t\t3.Back to main menu\n";
                cout<<"\n\n\t\t\tEnter your choice: ";
                cin>>choice;
                switch(choice)
                {
                case '1':
                {
                    ofstream t1("teacher.txt",ios::app);
                    for(i=0; choice!='n'&&choice!='N'; i++)
                    {
                        if((choice=='1')||(choice=='Y')||(choice=='y'))
                        {
                            cout<<"\n\t\t\tEnter first name: ";
                            cin>>t[i].tname;
                            cout<<"\t\t\tEnter last name: ";
                            cin>>t[i].tlname;
                            cout<<"\t\t\tEnter subject name: ";
                            cin>>t[i].sub;
                            cout<<"\t\t\tEnter years of experiance: ";
                            cin>>t[i].exper;
                            t1<<t[i].tname<<endl<<t[i].tlname<<endl<<t[i].sub<<endl<<t[i].exper<<endl;
                            cout<<"\n\n\t\t\tDo you enter more staffs details? (Y/N)";
                            cin>>choice;
                        }
                    }
                    t1.close();
                }
                continue;
                case '2':
                {
                    ifstream t2("teacher.txt");
                    cout<<"\n\t\t\tEnter staff name to be displayed";
                    cin>>fnd;
                    int notfound=0;
                    for( j=0; !t2.eof(); j++)
                    {
                        getline(t2,t[j].tname);
                        if(t[j].tname==fnd)
                        {
                            notfound=1;
                            cout<<"\n\t\t\tFirst name:"<<t[j].tname;
                            getline(t2,t[j].tlname);
                            cout<<"\t\t\tLast name:"<<t[j].tlname;
                            getline(t2,t[j].sub);
                            cout<<"\t\t\tSubject:"<<t[j].sub;
                            getline(t2,t[j].exper);
                            cout<<"\t\t\tYears of experience: "<<t[j].exper;
                            cout<<"\n";
                        }
                    }
                    t2.close();
                    if(notfound==0)
                    {
                        cout<<"\n\t\t\tNo data found";
                    }
                }
                continue;
                case '3':
                {
                    break;
                }
                break;
                }
                break;
            }
            continue;
        }
        default :
            exit(0);
        }
    }
}
int login()
{
    int id;
    cout<<"\n\n\n\n\n\n\n\t\t\t COLLEGE DATA MANAGEMENT SYSTEM \n\n";
    cout<<"\t\t\t------------------------------------\n\n";
    cout<<"\n\t\t\t\t LOGIN \n";
here:
    cout<<"\t\t\t\tEnter Password: ";
    cin>>id;
    cout<<"\n\t\t\t------------------------------------\n\n";
    if(id==12345)
    {
        cout<<"\n\t\t\t\tAccess Granted... \n";
    }
    else
    {
        cout<<"\n\n\t\t\tAccess Not Granted!!! Please Try Again...\n\n";
        goto here;
    }
}
