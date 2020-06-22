#include <iostream>
#include <stdlib.h>

using namespace std;
int main();
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
           cout << "Input User:" ;
           cin >> n;
           user = new User[n];
           for(size_t i =0 ;i<n;i++)
           {
               cout << "User["<<i+1<<"] "<<"Name:";
               cin >> user[i].name;
           }
         //cout << "User Name:";
         //cin >> A.name[];
      }
      void showUser()
      {
            for(size_t i =0 ;i<n;i++)
            {
               cout << "User[" << i+1 << "] " << "Name:";
               cout << user[i].name << endl;
            }
               getchar();
      }
};

void menu()
{

 LOOP:   int x;

    Messeger user;
    system("clear");
    cout << "1.Register" << endl;
    cout << "2.Show all users" << endl;
    cout << "3.See the conversations" << endl;
    cout << ":";cin >> x;
    switch(x){
        case 1:user.Register();menu();
        case 2:user.showUser();goto LOOP;
        case 0:break;
        default:menu();
    }
}

int main()
{
    menu();
    return 0;
}
