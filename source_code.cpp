#include <bits/stdc++.h>
#include <stdlib.h>
#define ll long long
using namespace std;
void main_view();
void new_account()
{
    system("CLS");
    cout << "\n\n\n\t\tEnter the Account No. : ";
    string ac_num,tmp,name,type,amount;
    int check = 1;
    cin >> ac_num;

    // Read from the text file
    ifstream MyReadFile;
    MyReadFile.open("clients_data.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, tmp) && check)
    {
        auto it = tmp.find(' ');
        tmp.erase(it,tmp.size());
        if(tmp == ac_num)
            check = 0;
    }
    if(check)
    {
        MyReadFile.close();
        cout << "\t\tEnter the Name of the Account holder : ";
        cin >> name;
        cout << "\t\tEnter Type of the Account (CURRENT/SAVING) : ";
        cin >> type;
        while(type != "CURRENT" && type != "SAVING")
        {
            cout << "\t\tEnter Type of the Account (CURRENT/SAVING) : ";
            cin >> type;
        }
        cout << "\t\tEnter The Initial amount : ";
        cin >> amount;
        ofstream MyFile;
        MyFile.open("clients_data.txt",ios::app);
        // Write to the file
        MyFile << ac_num << ' ' << name << ' ' << type << ' ' << amount << "\n";
        // Close the file
        MyFile.close();
    }
    else
    {
        system("CLS");
        cout << "\t\tTHIS ACCOUNT NUMBER WAS TAKEN BY ANOTHER PERSON PLEASE TRY AGAIN";
        _sleep(1000);
        MyReadFile.close();
        new_account();
        return;
    }
    cout<<"\n\n\t\tAccount Created..";
    _sleep(2000);
    main_view();
}
void main_view() /// this function to show the pattern on screen
{
    system("CLS");
    cout << "\n\n\n\t\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t\t* Welcome to Our Bank in Our Bank you can do the following activties  *" << endl;
    cout << "\t\t\t\t***********************************************************************\n" << endl;
    for(int i=1; i<=8; i++)
    {
        if(i%2!=0)
        {
            for(int j=1; j<=32; j++)
                cout << " ";
        }
        else
        {
            if(i==2)
                cout << "* 1-NEW ACCOUNT\t\t\t\t\t   2-WITHDRAW AMOUNT  *\n\n";
            if(i==4)
                cout << "* 3-DEPOSIT AMOUNT\t\t\t\t   4-BALANCE ENQUIRY  *\n\n";
            if(i==6)
                cout << "* 5-ALL ACCOUNT HOLDER LIST\t\t\t   6-CLOSE AN ACCOUNT *\n\n";
            if(i==8)
                cout << "* 7-MODIFY AN ACCOUNT\t\t\t\t   8-EXIT             *\n\n";
        }
    }
    cout << "\t\t\t\t**********************************************************************" << endl;
    cout << "\t\t\t\t\t\t((((((Please Enter your Choose))))))" << endl;
    string choose;
    do
    {
        cin >> choose;
        if(choose == "1")
        {
            new_account();
        }
    }
    while(choose != "8");
}
int main(void)
{
    main_view();
    return 0;
}
