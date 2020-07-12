//*error undefined reference to vtable when use virtual
//fixed reason because you declare constructor without definition
//and don't declare function member without definition
#include <iostream>
using namespace std;

class Employee{
    protected:
        int id[50]={0},n;
        string name[50] ,sex[50];
        static int GenID;
    public:
        Employee();//run id autonumber
        int getdata();
        void display();//pure function member
        void input();
        void output();
};
class Salaried_Employee : public Employee {
    private:
        int salary[50];
    public:
        void input();
        virtual void display();
        virtual void getdata();

};
class Waged_Employee : public Employee {
    private:
        int amount[50],rate[50];
    public:
        virtual void display();
        virtual void getdata();
};
class Salaried_Waged_Employee : public Employee {
    private:
        int Total[50];
    public:
        virtual void display();
        virtual void getdata();

};
//global
Salaried_Employee a;
Salaried_Waged_Employee b;
Waged_Employee c;
//definition
Employee::Employee(){
}
void Employee::input(){
    cout << "Input Employee N:" ; cin >> n;
    for(size_t i = 0;i<n;i++){
        cout << "===Employee" << i+1<<"===" << endl;
        cout << "Name:" ;cin.ignore();getline(cin,name[i]);
        cout << "Sex:"; cin >> sex[i];
        id[i]=i+1;
    }
}
void Employee::output(){
    cout << "=====OUTPUT======" << endl;
    cout << "ID\tName\t\tSex\t" << endl;
    for(size_t i=0;i<n;i++){
        cout <<id[i]<<"\t"<<Employee::name[i]<<"\t\t"<<sex[i]<<endl;
    }
}
void Salaried_Waged_Employee::display(){
    //sort process
    int tmp;
    string t;
    for(size_t i=0;i<n;i++){
        for(size_t j=i+1;j<n;j++){
            if(b.Total[i] < b.Total[j]){
                tmp = Total[j];
                b.Total[j] = b.Total[i];
                b.Total[i] = tmp;

                tmp = b.id[j];
                b.id[j] = b.id[i];
                b.id[i] = tmp;

                t = b.name[j];
                b.name[j] = b.name[i];
                b.name[i] = t;

                t = b.sex[j];
                b.sex[j] = b.sex[i];
                b.sex[i] =t;

            }
        }
    }
    //end sort process
    cout << "=====OUTPUT======" << endl;
    cout << "ID\tName\t\tSex\tTotal" << endl;
    for(size_t i=0;i<n;i++){
        cout <<id[i]<<"\t"<<Employee::name[i]<<"\t\t"<<sex[i]<<"\t"<<Total[i]<<endl;
    }
}
void Salaried_Waged_Employee::getdata(){
    cout << "Input Employee N:" ; cin >> n;
    for(size_t i = 0;i<n;i++){
        cout << "===Employee" << i+1<<"===" << endl;
        cout << "Name:" ;cin.ignore();getline(cin,name[i]);
        cout << "Sex:"; cin >> sex[i];
        cout << "Total:"; cin >> Total[i];
        id[i]=i+1;
    }

}
void Salaried_Employee::display(){
    //sort process
    int tmp;
    string t;
    for(size_t i=0;i<n;i++){
        for(size_t j=i+1;j<n;j++){
            if(a.salary[i] < a.salary[j]){
                tmp = salary[j];
                a.salary[j] = a.salary[i];
                a.salary[i] = tmp;

                tmp = a.id[j];
                a.id[j] = a.id[i];
                a.id[i] = tmp;

                t = a.name[j];
                a.name[j] = a.name[i];
                a.name[i] = t;

                t = a.sex[j];
                a.sex[j] = a.sex[i];
                a.sex[i] =t;

            }
        }
    }
    //end sort process
    cout << "=====OUTPUT======" << endl;
    cout << "ID\tName\t\tSex\tSalary" << endl;
    for(size_t i=0;i<n;i++){
        cout <<id[i]<<"\t"<<Employee::name[i]<<"\t\t"<<sex[i]<<"\t"<<salary[i]<<endl;
    }
}
void Salaried_Employee::getdata(){
    cout << "Input Employee N:" ; cin >> n;
    for(size_t i = 0;i<n;i++){
        cout << "===Employee" << i+1<<"===" << endl;
        cout << "Name:" ;cin.ignore();getline(cin,name[i]);
        cout << "Sex:"; cin >> sex[i];
        cout << "Salary: " ; cin >> salary[i];
        id[i]=i+1;
    }
}
void Waged_Employee::getdata(){
    cout << "Input Employee N:" ; cin >> n;
    for(size_t i = 0;i<n;i++){
        cout << "===Employee" << i+1<<"===" << endl;
        cout << "Name:" ;cin.ignore();getline(cin,name[i]);
        cout << "Sex:"; cin >> sex[i];
        cout << "Amount:"; cin >> amount[i];
        cout << "Rate:";cin >> rate[i];
        id[i]=i+1;
    }

}
void Waged_Employee::display(){
    //sort process
    int tmp;
    string t;
    for(size_t i=0;i<n;i++){
        for(size_t j=i+1;j<n;j++){
            if(c.amount[i] < c.amount[j]){
                tmp = amount[j];
                c.amount[j] = c.amount[i];
                c.amount[i] = tmp;

                tmp = rate[j];
                c.rate[j] = c.rate[i];
                c.rate[i] = tmp;

                tmp = c.id[j];
                c.id[j] = c.id[i];
                c.id[i] = tmp;

                t = c.name[j];
                c.name[j] = c.name[i];
                c.name[i] = t;

                t = c.sex[j];
                c.sex[j] = c.sex[i];
                c.sex[i] =t;

            }
        }
    }
    //end sort process
    cout << "=====OUTPUT======" << endl;
    cout << "ID\tName\t\tSex\tRate\tAmount" << endl;
    for(size_t i=0;i<n;i++){
        cout <<id[i]<<"\t"<<Employee::name[i]<<"\t\t"<<sex[i]<<"\t"<<rate[i]<<amount[i]<<endl;
    }

}
void SE(){
    int n;
    cout << "Welcome to Salaried_Employee app" << endl;
    cout << "1.input" << endl;
    cout << "2.display" << endl;
    cout << "0.Back" << endl;
    cout << "choose:";cin >> n;
    switch(n){
        case 1:a.getdata();SE();break;
        case 2:a.display();SE();break;
        case 0:break;
    }
}
void WE(){
    int n;
    cout << "Welcome to Waged_Employee app" << endl;
    cout << "1.input" << endl;
    cout << "2.display" << endl;
    cout << "0.Back" << endl;
    cout << "choose:";cin >> n;
    switch(n){
        case 1:b.getdata();WE();break;
        case 2:b.display();WE();break;
        case 0:break;
    }

}
void SWE(){
    int n;
    cout << "Welcome to Salaried_Waged_Employee app" << endl;
    cout << "1.input" << endl;
    cout << "2.display" << endl;
    cout << "0.Back" << endl;
    cout << "choose:";cin >> n;
    switch(n){
        case 1:c.getdata();SWE();break;
        case 2:c.display();SWE();break;
        case 0:break;
    }

}
void DisplayAll(){
    cout << "Salaried_Employee";a.display();
    cout << "Waged_Employee";c.display();
    cout << "Salaried_Waged_Employee";b.display();
}
void menu(){
    int n;
    cout << "1.Salaried_Employee" << endl;
    cout << "2.Waged_Employee" << endl;
    cout << "3.Salaried_Waged_Employee" << endl;
    cout << "4.Display all data" << endl;
    cout << "0.Exit" << endl;
    cout << "choose:" ; cin >> n;
    //switch here
    switch(n){
        case 1 : SE();menu();break;
        case 2 : WE();menu();break;
        case 3 : SWE();menu();break;
        case 4 : DisplayAll();menu();break;
        case 0:break;
    }
}
int main(){
    menu();
    return 0;
}
