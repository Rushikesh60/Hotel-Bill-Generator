#include<iostream>
#include<fstream>
#include"hotel.h"

using namespace std;

int main()
{
    string Name;
    cout<<"Enter the name of costumer: ";
    getline(cin,Name);
    int ch,d;
    cout<<"************CHOICES**************"<<endl;
    cout<<"1-Hotel Bill"<<endl<<"2-Restourant Bill"<<endl;
    cout<<"Enter your choice : ";
    cin>>ch;
    //rentals room;
   restaurant r1;
    switch(ch)
    {
        case 1:
        //taking information from costunmer
        r1.take();
        cout<<"Enter 1 if you have visited restaurant else 0  :";
        cin>>d;
        if(d==1)
        {
            r1.option();
        }
        //calling function for restourant bill
        r1.print(Name,ch);
        break;
        case 2:
        //printing bill of restaurant
        r1.option();
        r1.print(Name,ch);
        break;
        default:
        cout<<"Enter valid choice"<<endl;
    }
    return 0;
}
