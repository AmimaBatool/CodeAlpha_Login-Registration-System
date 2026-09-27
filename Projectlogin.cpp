// LOGIN and REGISTRATION SYSTEM

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    cout<<"==================================="<<endl;
    cout<<"              WELCOME              "<<endl;
    cout<<"   Login and Registration System   "<<endl;
    cout<<"==================================="<<endl;
    cout<<endl;

    int choice;
    cout<< "----MENU----"<<endl;
    cout<< "1. Login" << endl;
    cout<< "2. Register" << endl;
    cout<< "3. Forgot Password" << endl;
    cout<< "4. Exit" << endl;
    cout<<endl;
    cout<< "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"Thank you for using the Login and Registration System. Goodbye!"<<endl;
            break;
        default:
            cout << "Invalid choice! Enter the valid Option given above." << endl;
    }

    cout<<endl;
    return 0;
}

//Login function
void login()
{
    int count=0;
    string userId, password, id, pass;
    cout<<"-----Enter the Login Details-----"<<endl;
    cout<<"Enter the Username: ";
    cin>>userId;
    cout<<"Enter the Password: ";
    cin>>password;

    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if(id==userId && pass==password)
        {
            count=1;
        }
    }
    input.close();

    if(count==1)
    {
        cout<<userId<<"\nYour Login is Successful!"<<endl;
        main();
    }
    else
    {
        cout<<"Login Error! Please check your username and password."<<endl;
        cout<<endl;
        main();
    }
}

// Registration function
void registration()
{
    string r_userId, r_password, r_id, r_pass;

    cout<<"-----Enter the Registration Details-----"<<endl;
    cout<<"Enter the Username: ";
    cin>>r_userId;
    cout<<"Enter the Password: ";
    cin>>r_password;

    if(r_userId.empty() || r_password.empty())
    {
        cout<<"Username and Password cannot be empty!"<<endl;
        main();
        return;
    }

    ifstream checkFile("records.txt");
    string existingId, existingPass;
    while(checkFile >> existingId >> existingPass)
    {
        if(existingId == r_userId)
        {
            cout<<"Username already exists! Please choose another username."<<endl<<endl;
            checkFile.close();
            main();
            return;
        }
    }
    checkFile.close();

    ofstream f1("records.txt", ios::app);
    f1<<r_userId<<' '<<r_password<<endl;
    f1.close();
    cout<<"Registration is Successful!"<<endl<<endl;
    main();
}

// Forgot Function in case user forgets the password.
void forgot()
{
    int option;

    cout<<"-----Forgot Password-----"<<endl;
    cout<<"1. Search your account by Username"<<endl;
    cout<<"2. Go back to main menu"<<endl;
    cout<<endl;

    cout<<"Enter your choice: ";
    cin>>option;

    switch(option)
    {
        case 1:
        {
            int count=0;
            string s_userId, s_id, s_pass;
            cout<<"Enter the Username you remembered: ";
            cin>>s_userId;

            ifstream f2("records.txt");
            while(f2>>s_id>>s_pass)
            {
                if(s_id==s_userId)
                {
                    count=1;
                    break;
                }
            }
            f2.close();

            if(count==1)
            {
                cout<<"\nYour account is found!"<<endl;
                cout<<"\nYour password is: "<<s_pass<<endl;
                main();
            }
            else
            {
                cout<<"\nSorry! Your account is not found!"<<endl;
                main();
            }
        }
        break;

        case 2:
        {
            main();
        }
        break;

        default:
            cout<<"Invalid choice! Please try again."<<endl;
            forgot();
    }
}