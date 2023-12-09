#include<iostream>
#include<fstream>
using namespace std;


//class generating rentals bill
class rentals
{
  public:
  int rent;
  float tax,fee;
  public:
  void take()
  {
    int n,ch;
    cout<<"Enter how many days costumer stayed : ";
    cin>>n;
    cout<<"Which type of room he booked"<<endl;
    cout<<"1-Normal room"<<endl<<"2-Special room"<<endl;
    cin>>ch;
    switch (ch)
    {
      case 1:
      rent=5000*n;
      fee=500*n;
      tax=(fee/100)*18;
      break;

      case 2:
      rent=10000*n;
      fee=700*n;
      tax=(fee/100)*21;
      break;

      default:
      cout<<"Enter valid choice"<<endl;
    }
   }
   
};

class restaurant: public rentals
{

  public:
  int dish[10]; 
  string itemname[10];
  double subtotal=0;
  int i=0,j;
  double Tax,total=0;
  double Total=0;
    
  //function for genreting restaurant bill
  public:
  void option()
  { 
    int ch,n;
    int t=1;
    cout<<"******************* MENU ******************"<<endl;
    cout<<"1-Chicken curry"<<endl<<"2-Egg curry"<<endl<<"3-Paneer masala"<<endl<<"4-Jeera rice"<<endl<<"5-Mix veg"<<endl<<"0-No dish"<<endl;
    while(t==1)
    {   
      cout<<"Enter number infront of dish to add dish in bill  ";
      cin>>ch;
            
      switch(ch)
      {  
        case 0:
        cout<<"No dish is entered"<<endl;
        break;
        case 1:
        cout<<"Enter how many dishes of chicken curry  ";
        cin>>n;
        itemname[i]="Chicken curry";
        dish[i]=150*n;
        i++;
        break;
        case 2:
        cout<<"Enter how many dishes of  Egg curry  ";
        cin>>n;
        itemname[i]="Egg curry";
        dish[i]=100*n;
        i++;
        break;
        case 3:
        cout<<"Enter how many dishes of  Paneer masala  ";
        cin>>n;
        itemname[i]="Paneer masala";
        dish[i]=50*n;
        i++;
        break;
        case 4:
        cout<<"Enter how many dishes of  Jeera rice  ";
        cin>>n;
        itemname[i]="Jeera rice";
        dish[i]=40*n;
        i++;
        break;
        case 5:
        cout<<"Enter how many dishes of  Mix veg  ";
        cin>>n;
        itemname[i]="Mix veg";
        dish[i]=50*n;
        i++;
        break;

        default:
        cout<<"Enter valid choice"<<endl;
      }
      cout<<"Enter 1 to add or enter any  other number to end"<<endl;
      cin>>t; 
    }
    Total=rent+fee+tax;
  }

    void print(string  Name,int ch)
    {
      
      ofstream file("my.txt");
      file<<"Name of customer is-:"<<Name<<endl;
      cout<<"Name of customer is-:"<<Name<<endl;
      cout<<"**************************************************"<<endl;
      file<<"**************************************************"<<endl;  
      for(j=0;j<i;j++)
      {
        file<<itemname[j]<<"-:"<<dish[j]<<endl;
        cout<<itemname[j]<<"-:"<<dish[j]<<endl;
        subtotal=subtotal+dish[j];
            
      }
      if(ch==1)
      {
        total=rent+fee+tax;
        cout<<"**************************************************"<<endl;
        file<<"**************************************************"<<endl;
        cout<<"@ Room Rentals @"<<endl<<"Rent for room is="<<rent<<endl<<"Service fee is="<<fee<<endl<<"Tax is="<<tax<<endl<<"Total is="<<total<<endl;
        cout<<"**************************************************"<<endl;
        
        file<<"Rent for room is="<<rent<<endl<<"Service fee is="<<fee<<endl<<"Tax is="<<tax<<endl<<"Total is="<<total<<endl;
        file<<"**************************************************"<<endl;
        
      }
      Tax=(subtotal/100)*5;
      Total=Tax+subtotal;
      cout<<"**************************************************"<<endl;
      file<<"**************************************************"<<endl;
      cout<<"@ restaurant bill @"<<endl<<"Subtotal is="<<subtotal<<endl<<"Tax is="<<Tax<<endl<<"Total is="<<Total<<" rs"<<endl;
      file<<"@ restaurant bill @"<<endl<<"Subtotal is="<<subtotal<<endl<<"Tax is="<<Tax<<endl<<"Total is="<<Total<<" rs"<<endl;
      cout<<"**************************************************"<<endl;
      file<<"**************************************************"<<endl;
      cout<<"Total amount payable is ="<<Total+total<<" rs"<<endl;
      file<<"Total amount payable is ="<<Total+total<<" rs"<<endl;

      file.close();
          
    }
};