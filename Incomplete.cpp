//Basic header files required for different inbuilt function
#include<iostream>
#include<vector>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;
static int count=0;



//Here class vehicle is defined that makes easier to implement different functions
class vehicle
{
    string pltno;
    int type;
    

public:
    void addVehicle();
    void calculatecharges();
    void deleteVehicle();
    void printvehicle(vehicle v);
    void show();


};

//created a vector of type vehicle of size 100
//Vector represent tha dyanmic arry
vector<vehicle> veh(100);
int totalvehicle=0,totalcar=0,totalbike=0,totalamt=0,i=0,charges=0;
time_t entryTime, exitTime;
//Here i represent index value of vector

fstream file;

//This function works whenever any vehicles arrive
void vehicle::addVehicle()
{

      vehicle *v = new vehicle;
      cout<<"Enter vehicle type(1 for Car/2 for Bike) : ";
      cin>>v->type;
      cout<<"Enter vehicle number : ";
      cin>>v->pltno;
      entryTime = time(0);
      count++;
      string t = ctime(&entryTime); 
      cout<<"Entry Time: "<<ctime(&entryTime);

      veh.at(i).pltno=v->pltno;
      veh.at(i).type=v->type;
      

      i++;
      totalvehicle++;

      if(v->type == 1)
      {
          totalcar++;
      }
      else
        {
        totalbike++;
        }

        cout<<"\nVehicle added successfully"<<endl;
};
//Compute the parked time of a vehicle
 void vehicle::calculatecharges()
  {

    long long duration = exitTime-entryTime;
            int mins = duration/60;
            int hours = mins/60;
            int extra_min = mins%60;
            
}
//This function works whenever any vehicles depart from parking
  void vehicle:: deleteVehicle()
  {
      string pno;
      int typ;
      
      int time_diff;
      int charge=0;

      cout<<"Enter vehicle type(1 for Car/2 for Bike) : ";
      cin>>typ;
      cout<<"Enter vehicle number : ";
      cin>>pno;
      exitTime = time(0);
      cout<<"exitime: "<<ctime(&exitTime);



      for(int j=0;j<=i;j++)
      {
          if((veh.at(j).pltno==pno)&&(veh.at(j).type==typ))
          {
             

              time_diff=exitTime-entryTime;

              if(veh.at(j).type== 1)
              {
                  totalcar--;
                  if(time_diff<2)
                  {
                      charge=20;
                  }
                  else
                  {
                      if((time_diff>2) && ((time_diff<5)))                          {
                              charge=40;
                          }
                          else
                            {
                               charge=50;
                            }
                  }

              }
              else
              {
                  totalbike--;

                      if( time_diff<2)
                      {
                          charge=5;
                      }
                      else
                      {
                          if((time_diff>2) && ((time_diff<5)))
                              {
                                  charge=10;
                              }
                              else
                                {
                                   charge=20;
                                }
                      }

              }
               //Createdd a file
              cout<<"\nVehicle having vehicle number  : "<<veh.at(j).pltno<<" has left the parking after paying Rs. "<<charge<<endl;
              file.open("parkingDatabase.txt",ios::app);
              if(!file)
                {
                    cerr << "Error: file could not be opened" << endl;
                    exit(1);
                }

               file<<veh.at(j).type<<"\t\t\t"<<veh.at(j).pltno<<"\t\t\t"<< ctime(&entryTime)<<":"<<"\t\t\t"<<ctime(&exitTime)<<endl;
               file.close();
              veh.erase(veh.begin()+j);
              i--;
              totalvehicle--;
              totalamt = totalamt+charge;
              break;

          }

          if(j==i)
          {
              cout<<"\nWrong Entry , Try Again "<<endl;
              cout<<"Departure : "<<endl;
              deleteVehicle();
          }

      }



  }

//These function shows the details of the vehicle
  void vehicle::printvehicle(vehicle v)
  {
    cout<<v.type<<"\t\t\t"<<v.pltno<<"\t\t\t"<< ctime(&entryTime)<<endl;
  }

  void vehicle::show()
  {
      cout<<"Vehicle Type\t\t\tVehicle Number\t\t\tArrival Time"<<endl;
      for(int j=0;j<i;j++)
      {
          printvehicle(veh[j]);
      }
  }
//This functions count the type and total no.of vehicle parked
  void totalveh()
  {
      cout<<"Total number of vehicle parked : "<< totalvehicle<<endl;
      cout<<"Total number of car parked : "<< totalcar<<endl;
      cout<<"Total number of bike parked : "<<  totalbike<<endl;

  }
//This function shows the Total amount collected
  void totalamount()
  {
      cout<<"Total Collection till now : "<<totalamt<<endl;
  }


//THis is the main function from the program starts
  int main()
  {
    int choice;
    char ans;
    system ( "cls" ) ;

  do
  {
     system ( "cls" ) ;
     cout<<"                 VEHICLE PARKING RESERVATION SYSTEM                 "<<endl;
     cout<<"1. Arrival of a vehicle"<<endl
         <<"2. Total number of vehicles parked"<<endl
         <<"3. Departure of vehicle"<<endl
         <<"4. Total Amount collected "<<endl
         <<"5. Display "<<endl
         <<"6. Exit"<<endl
         <<"********************************************************************"<<endl
         <<"Enter your Choice : ";
         cin>>choice;

         switch(choice)
         {
             case 1: system ( "cls" ) ;
                     cout<<"Add : "<<endl;
                     veh.at(i).addVehicle();
                     break;

             case 2: system ( "cls" ) ;
                     totalveh();
                     break;

             case 3: system ( "cls" ) ;
                     cout<<"Departure : "<<endl;
                     veh.at(i).deleteVehicle();
                     break;

             case 4: system ( "cls" ) ;
                     totalamount();
                     break;

             case 5: system ( "cls" ) ;
                     veh.at(i).show();
                     break;
             case 6: exit(0);
         }

         cout<<"\nDo you want to continue, press y/n : "<<endl;
         cin>>ans;
         if(ans=='n')
         {
             break;
         }
         else
         {
             continue;
         }

  }while(1);

  return 0;
  }
