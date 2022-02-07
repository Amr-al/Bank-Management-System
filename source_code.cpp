#include <bits/stdc++.h>
#define ll long long
using namespace std;
void main_view() /// this function to show the pattern on screen
{
    cout << "\n\n\n\t\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t\t* Welcome to Our Bank in Our Bank you can do the following activties  *" << endl;
    cout << "\t\t\t\t***********************************************************************" << endl;
    for(int i=1; i<=10; i++)
    {
        if(i%2!=0){
            for(int j=1; j<=32; j++)
                cout << " ";
        }
        else{
            if(i==2)
                cout << "* 1-New Account\t\t\t\t\t      2-Transform     *\n\n";
            if(i==4)
                cout << "* 3-Edit Info\t\t\t\t\t      4-Erase Account *\n\n";
            if(i==6)
                cout << "* 5-money process\t\t\t\t      6-See details   *\n\n";
            if(i==8)
                cout << "* 7-veiw acc list process\t\t\t      8-exit          *\n\n";
            if(i==10)
                cout << "* 9- reset program\t\t\t\t      10-recover pass *\n";
        }
    }
    cout << "\t\t\t\t**********************************************************************" << endl;
    cout << "\t\t\t\t\t\t((((((Please Enter your Choose))))))" << endl;
    int choose;
    do{
        string c;
        cin >> c;
        choose = 0;
        for(int i = 0; i < c.size();++i)
            choose *= 10, choose +=abs(c[i]-'0');
    }while(choose > 8 || choose < 1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    main_view();
    return 0;
}
