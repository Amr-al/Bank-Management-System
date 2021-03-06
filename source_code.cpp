#include <bits/stdc++.h>
#include <stdlib.h>
#define ll long long
using namespace std;
void main_view();
ll string_to_int(string s)
{
    ll res = 0;
    for(auto it:s)
    {
        res *= 10;
        res +=(it-'0');
    }
    return res;
}
string int_to_string(ll n)
{
    string res;
    while(n)
    {
        res.push_back(n%10 + '0');
        n/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
void new_account() /// function to create a new account
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
        for_each(type.begin(), type.end(), [](char & c)
        {
            c = ::toupper(c);
        });
        while(type != "CURRENT" && type != "SAVING")
        {
            cout << "\t\tEnter Type of the Account (CURRENT/SAVING) : ";
            cin >> type;
            for_each(type.begin(), type.end(), [](char & c)
            {
                c = ::toupper(c);
            });
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
void show_account() /// function to show the account details
{
    system("CLS");

    string ac_num,tmp,tmp2,name,type;
    cout << "\n\n\n\t\tEnter the Account No. : ";
    cin >> ac_num;
    ifstream myfile;
    int check = 0;
    myfile.open("clients_data.txt");

    while(getline(myfile, tmp) && !check)
    {
        tmp2 = tmp;
        auto it = tmp.find(' ');
        tmp.erase(it,tmp.size());
        if(tmp == ac_num)
        {
            check = 1;
            system("CLS");
            cout<<"\t\t\t====================================================\n";
            cout<<"\t\t\t| A/c no.        NAME        Type        Balance   |\n ";
            cout<<"\t\t\t====================================================\n";
            cout << "\t\t\t  " << ac_num << "\t\t ";
            tmp2.erase(0,ac_num.size()+1);
            auto it = tmp2.find(' ');
            name = tmp2.substr(0,it);
            cout << name << "\t     ";
            tmp2.erase(0,name.size()+1);
            it = tmp2.find(' ');
            type = tmp2.substr(0,it);
            tmp2.erase(0,it);
            cout << type << "\t";
            cout << tmp2;
            _sleep(4000);
            myfile.close();
            main_view();
            return;
        }
    }
    myfile.close();
    if(!check)
    {
        system("CLS");
        cout << "\n\n\t\t\t\t\t THERE IS NO SUCH ACCOUNT";
        _sleep(2000);
        system("CLS");
        main_view();
    }
}
void deposit()
{
    system("CLS");
    string ac_num,tmp,tmp2,amount;
    ll balance = 0;
    cout << "\n\n\n\t\tEnter the Account No. : ";
    cin >> ac_num;
    cout << "\n\n";
    ifstream myfile;
    int check = 0;
    myfile.open("clients_data.txt");

    while(getline(myfile, tmp))
    {
        tmp2 = tmp;
        auto it = tmp2.find(' ');
        if(tmp.substr(0,it) == ac_num)
        {
            check = 1;
            cout << "\t\tAccount No. : " << ac_num << "\n";
            tmp2.erase(0,it+1);
            it = tmp2.find(' ');
            cout << "\t\tAccount Holder Name : " << tmp2.substr(0,it) <<'\n';
            tmp2.erase(0,it+1);
            it = tmp2.find(' ');
            cout << "\t\tType of Account : " << tmp2.substr(0,it) << '\n';
            tmp2.erase(0,it+1);
            amount = tmp2;
            cout << "\t\tBalance amount : " << amount << "\n\n";
            cout <<"\t\tTO DEPOSITSS AMOUNT\n\n\t\tEnter The amount to be deposited : ";
            cin >> balance;
            balance += string_to_int(amount);
            break;
        }
    }
    myfile.close();
    if(!check)
    {
        system("CLS");
        cout << "\n\n\t\t\t\t\t THERE IS NO SUCH ACCOUNT";
        _sleep(2000);
        system("CLS");
        main_view();
    }
    else
    {
        myfile.open("clients_data.txt");
        ofstream out("tmp.txt"),file;
        while(getline(myfile,tmp2))
        {
            if(tmp != tmp2)
                out << tmp2 <<"\n";
        }
        myfile.close();
        out.close();
        // delete the original file
        remove("clients_data.txt");
        // rename old to new
        rename("tmp.txt","clients_data.txt");
        auto it = tmp.find(amount);
        tmp.erase(it,tmp.size());
        tmp2 = int_to_string(balance);
        for(auto it:tmp2)
            tmp.push_back(it);
        file.open("clients_data.txt",ios::app);
        file << tmp << "\n";
        file.close();
    }
    cout << "\t\tPROCESS DONE SUCESSFULLY";
    _sleep(2000);
    system("CLS");
    main_view();
}
void show_all()
{
    ifstream myfile;
    myfile.open("clients_data.txt");
    string tmp,tmp2;
    system("CLS");
    cout<<"\t\t\t====================================================\n";
    cout<<"\t\t\t| A/c no.        NAME        Type        Balance   |\n ";
    cout<<"\t\t\t====================================================\n";
    while(getline(myfile,tmp))
    {
        auto it = tmp.find(' ');
        cout << "\t\t\t  " << tmp.substr(0,it) << "\t\t ";
        tmp.erase(0,it+1);
        it = tmp.find(' ');
        cout << tmp.substr(0,it) << "\t     ";
        tmp.erase(0,it+1);
        it = tmp.find(' ');
        cout << tmp.substr(0,it) << "\t ";
        tmp.erase(0,it+1);
        cout << tmp << endl;
    }
    _sleep(4000);
    myfile.close();
    main_view();
}
void with_draw()
{
    system("CLS");
    string ac_num,tmp,tmp2,amount;
    ll balance = 0;
    cout << "\n\n\n\t\tEnter the Account No. : ";
    cin >> ac_num;
    cout << "\n\n";
    ifstream myfile;
    int check = 0;
    myfile.open("clients_data.txt");

    while(getline(myfile, tmp))
    {
        tmp2 = tmp;
        auto it = tmp2.find(' ');
        if(tmp.substr(0,it) == ac_num)
        {
            check = 1;
            cout << "\t\tAccount No. : " << ac_num << "\n";
            tmp2.erase(0,it+1);
            it = tmp2.find(' ');
            cout << "\t\tAccount Holder Name : " << tmp2.substr(0,it) <<'\n';
            tmp2.erase(0,it+1);
            it = tmp2.find(' ');
            cout << "\t\tType of Account : " << tmp2.substr(0,it) << '\n';
            tmp2.erase(0,it+1);
            amount = tmp2;
            cout << "\t\tBalance amount : " << amount << "\n\n";
            cout <<"\t\tTO DEPOSITSS AMOUNT\n\n\t\tEnter The amount to be deposited : ";
            cin >> balance;
            ll cur_amount = string_to_int(amount);
            if(cur_amount < balance)
            {
                cout << "\t\tInsufficience balance";
                _sleep(2000);
                myfile.close();
                main_view();
                return;
            }
            balance = cur_amount - balance;
            break;
        }
    }
    myfile.close();
    if(!check)
    {
        system("CLS");
        cout << "\n\n\t\t\t\t\t THERE IS NO SUCH ACCOUNT";
        _sleep(2000);
        system("CLS");
        main_view();
    }
    else
    {
        myfile.open("clients_data.txt");
        ofstream out("tmp.txt"),file;
        while(getline(myfile,tmp2))
        {
            if(tmp != tmp2)
                out << tmp2 <<"\n";
        }
        myfile.close();
        out.close();
        // delete the original file
        remove("clients_data.txt");
        // rename old to new
        rename("tmp.txt","clients_data.txt");
        auto it = tmp.find(amount);
        tmp.erase(it,tmp.size());
        tmp2 = int_to_string(balance);
        for(auto it:tmp2)
            tmp.push_back(it);
        file.open("clients_data.txt",ios::app);
        file << tmp << "\n";
        file.close();
    }
    cout << "\t\tPROCESS DONE SUCESSFULLY";
    _sleep(2000);
    system("CLS");
    main_view();
}
void close_account()
{
    system("CLS");
    ifstream myfile;
    myfile.open("clients_data.txt");
    string tmp,ac_num,tmp2;
    int check = 0;
    cout << "\n\n\n\t\tEnter the Account No. : ";
    cin >> ac_num;
    while(getline(myfile,tmp))
    {
        auto it = tmp.find(' ');
        if(tmp.substr(0,it) == ac_num)
        {
            check = 1;
            tmp2 = tmp;
            break;
        }
    }
    myfile.close();
    if(!check)
    {
        cout << "\t\tTHERE IS NO SUCH ACCOUNT";
        _sleep(2000);
        system("CLS");
        main_view();
        return;
    }
    ofstream tmpfile;
    tmpfile.open("TMP.txt");
    myfile.open("clients_data.txt");
    while(getline(myfile,tmp))
    {
        if(tmp == tmp2)
            continue;
        tmpfile << tmp << "\n";
    }
    tmpfile.close();
    myfile.close();
    remove("clients_data.txt");
    rename("TMP.txt","clients_data.txt");
    cout << "\t\tPROCESS DONE SUCESSFULLY";
    _sleep(2000);
    system("CLS");
    main_view();
}
void modify()
{
    system("CLS");
    string tmp,name,ac_num,type,amount,tmp2,newac="";
    cout << "\n\n\n\t\tEnter the Account No. : ";
    cin >> ac_num;
    cout << "\n\n";
    ifstream myfile("clients_data.txt");
    while(getline(myfile,tmp))
    {
        auto it = tmp.find(' ');
        tmp2 = tmp;
        if(tmp.substr(0,it) == ac_num)
        {
            cout << "\t\tAccount No. : " << ac_num << "\n";
            tmp.erase(0,it+1);
            it = tmp.find(' ');
            cout << "\t\tAccount Holder Name : " << tmp.substr(0,it) <<'\n';
            tmp.erase(0,it+1);
            it = tmp.find(' ');
            cout << "\t\tType of Account : " << tmp.substr(0,it) << '\n';
            tmp.erase(0,it+1);
            amount = tmp;
            cout << "\t\tBalance amount : " << amount << "\n\n";
            cout << "\t\tEnter The New Details of account\n\n";
            cout << "\t\tModify Account Holder Name : ";
            cin >> name;
            cout << "\n\t\tModify Type of Account : ";
            cin >> type;
            for_each(type.begin(), type.end(), [](char & c)
            {
                c = toupper(c);
            });
            while(type != "CURRENT" && type != "SAVING"){
                cout << "\n\t\Type of the Account should be (CURRENT/SAVING) : ";
                cin >> type;
                for_each(type.begin(), type.end(), [](char & c)
                {
                    c = toupper(c);
                });
            }
            cout << "\n\t\tModify Balance amount : ";
            cin >> amount;
            newac = ac_num + ' ' + name + ' ' + type + ' ' + amount;
        }
    }
    myfile.close();
    if(newac.empty()){
        cout << "\t\tTHERE IS NO SUCH ACCOUNT";
        _sleep(2000);
        system("CLS");
        main_view();
        return;
    }
    myfile.open("clients_data.txt");
    ofstream tmpfile("tmp.txt");
    while(getline(myfile,tmp))
    {
        if(tmp == tmp2)
        {
            tmpfile << tmp2 << "\n";
            continue;
        }
        tmpfile << tmp << "\n";
    }
    tmpfile.close();
    myfile.close();
    remove("clients_data");
    rename("tmp.txt","clients_data.txt");
    cout << "\t\tPROCESS DONE SUCESSFULLY";
    _sleep(2000);
    system("CLS");
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
        if(choose == "2")
        {
            with_draw();
        }
        if(choose == "3")
        {
            deposit();
        }
        if(choose == "4")
        {
            show_account();
        }
        if(choose == "5")
        {
            show_all();
        }
        if(choose == "6")
        {
            close_account();
        }
        if(choose == "7")
        {
            modify();
        }
    }
    while(choose != "8");
}
int main(void)
{
    main_view();
    return 0;
}
