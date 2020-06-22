#include <iostream>
#include <stdlib.h>

using namespace std;
int main();
void menu();
struct User{
    string name;
    string sent[50];
    string inbox[50];
};
class Messeger
{
    private:
        User *user;
        int n;
    public:

      void Register()
      {
           cout << "Input User" ;
           cin >> n;
           user = new User[n];
           for(size_t i =0 ;i<n;i++)
           {
               cout << "User["<<i+1<<"] "<<"Name:";
               cin >> user[i].name;
           }
      }
      void showUser()
      {
          cout << n <<endl;
            for(int i =0 ;i<n;i++)
            {
               cout << "User[" << i+1 << "] " << "Name:";
               cout << user[i].name << endl;
            }
            cout << "Press any to continue!" << endl;
            int tmp;
            cin >> tmp;
            menu();
      }
};
//should not declare object in loop function or recursive
Messeger user;

void menu()
{

     int x;

    system("clear");
    cout << "1.Register" << endl;
    cout << "2.Show all users" << endl;
    cout << "3.See the conversations" << endl;
    cout << ":";cin >> x;
    switch(x)
    {
        //use break to prevent recursive
        case 1:user.Register();menu();break;
        case 2:user.showUser();break;
        case 0:break;
        default:menu();
    }
}

int main()
{
    menu();
    return 0;
}
