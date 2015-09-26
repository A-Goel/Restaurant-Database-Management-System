/*
  Name: Akash Goel
  Class: XII 
  School: Step by Step School, Noida
  Description: This is a program for a restaurant official to place orders, view orders and edit the menu.
*/
#include<ctime>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<math.h>
#include<string.h>
#include<fstream>
using namespace std;

class restaurant{
      private:
                    
              
                
                //Menu
                char appetizers[10][20],mainCourse[10][20],desserts[10][20],beverages[10][20];
                double costOfA[10],costOfMC[10],costOfD[10],costOfB[10];
                int countOfMenuItems[4],lenA[10],lenMC[10],lenD[10],lenB[10];
                
                //Customer Variables
                char customer_name[30],countName;
                int Day,Month,Year,Hour,Min,Sec,noOfOrders;
                int orderA[10],orderMC[10],orderD[10],orderB[10],qa[10],qmc[10],qd[10],qb[10];
                char mobile[14];
                double total,tax;
                int ca,cmc,cd,cb;
                
                //Loops
                int m,a;
                
      public:
               //Initial Details         
                char restaurant_name[30],username[30];
                char password[30];
                int countOfRName;
          
                //Checks
                int checkMain;
                
                //Selection
                int mainScreenSelect;
             
                //Header Function
                void header()
                {
                     system("cls");
                     cout<<setw((142-countOfRName)/2 + countOfRName)<<restaurant_name<<endl;
                     //cout<<setw(83)<<"{Developed by Akash Goel}"<<endl;
                     for(int line_count=0;line_count<142;line_count++)
                     cout<<"_";             
                }
                
                //Check for first Rrn
                int checkFirstRun()
                {
                    ofstream checkFR;
                    checkFR.open("CheckForFirstRun.txt");
                    checkFR<<1;
                    checkFR.close();
                    return 1;          
                }
                
                //Read initial values
                void readInitialValues()
                {
                     
                     header();
                     cout<<endl<<endl<<"Restaurant Details:-"<<endl<<endl;
                     cout<<"1)Name of Restaurant:";cin.ignore();cin.getline(restaurant_name,'#');
                     cout<<"2)Administrator details:-"<<endl;
                     cout<<"\t-Username:";cin.getline(username,'#');
                     cout<<"\t-Password:";cin.getline(password,'#');     
                }
                
                //Read initial values from file
                void readInitialValuesFromFile()
                {
                     ifstream initialValues;
                     initialValues.open("RestaurantDetails.txt");
                     initialValues.getline(restaurant_name,'#');
                     initialValues>>username;
                     initialValues>>password;
                     initialValues.close();                                     
                }      
                
                //Write initial values to file
                void enterInitialValuesToFile()
                  {
                       ofstream initialValues;
                       initialValues.open("RestaurantDetails.txt");
                       initialValues<<restaurant_name<<endl;
                       initialValues<<username<<endl;
                       initialValues<<password<<endl;
                       initialValues.close();                                                    
                  }
                  
                //Get length of Restaurant Name
                int getLengthOfRestaurantName()
                  {
                      int c=0;
                      for(int i=0;i<30;++i)
                      {
                          c++;
                          if(restaurant_name[i]=='\0')
                                                      break;
                      }
                      return c;
                                                 
                  }
                  
                //Main Screen
                int mainScreen()
                  {
                      
                      int mainScreenSelect;
                      header();
                      cout<<endl<<endl;
                      cout<<"1)New customer"<<endl;
                      cout<<"2)Old customer"<<endl;
                      cout<<"3)Edit Menu"<<endl;
                      cout<<"4)Edit restaurant details"<<endl;
                      cout<<"5)Restaurant statistics"<<endl;
                      cout<<"6)Close bakery"<<endl<<endl;
                      cout<<"Select option:";
                      cin>>mainScreenSelect;
                      return mainScreenSelect;                      
                  }
                
                //Edit Menu
                void editMenu()
                  {
                      
                                
                       header();
                   
                       cout<<endl<<endl<<"Menu:-"<<endl;
                       
                       //Get Appetizers
                       cout<<"\tNumber of appetizers:";cin>>countOfMenuItems[0];
                       for(int i=0;i<countOfMenuItems[0];++i)
                       {
                               cout<<"\t-Item "<<i+1<<":";cin.ignore();cin.getline(appetizers[i],'#');
                               cout<<"\t-Price(Rs) "<<":";cin>>costOfA[i];
                               cout<<endl;
                       }
                   
                       //Get Main Course
                       cout<<"\tNumber of items in Main Course:";cin>>countOfMenuItems[1];
                       for(int i=0;i<countOfMenuItems[1];++i)
                       {
                               cout<<"\t-Item "<<i+1<<":";cin.ignore();cin.getline(mainCourse[i],'#');
                               cout<<"\t-Price(Rs)"<<":";cin>>costOfMC[i];
                               cout<<endl;
                       }
                       
                       //Get Desserts
                       cout<<"\tNumber of desserts:";cin>>countOfMenuItems[2];
                       for(int i=0;i<countOfMenuItems[2];++i)
                       {
                               cout<<"\t-Item "<<i+1<<":";cin.ignore();cin.getline(desserts[i],'#');
                               cout<<"\t-Price(Rs) "<<":";cin>>costOfD[i];
                               cout<<endl;
                       }
                       
                       //Get Beverages
                       cout<<"\tNumber of beverages:";cin>>countOfMenuItems[3];
                       for(int i=0;i<countOfMenuItems[3];++i)
                       {
                               cout<<"\t-Item "<<i+1<<":";cin.ignore();cin.getline(beverages[i],'#');
                               cout<<"\t-Price(Rs) "<<":";cin>>costOfB[i];
                               cout<<endl;
                       }
                       
                  } 
                  
                //Write Menu to File
                void writeMenuToFile()
                  {
                         ofstream menuValues;
                         menuValues.open("MenuDetails.txt");
                                                       
                         //Write Appetizers
                         menuValues<<countOfMenuItems[0]<<endl;
                         for(int i=0;i<countOfMenuItems[0];++i)
                                 menuValues<<appetizers[i]<<endl<<costOfA[i]<<endl;
                         menuValues<<endl;
                         
                         //Write Main Course
                         menuValues<<countOfMenuItems[1]<<endl;
                         for(int i=0;i<countOfMenuItems[1];++i)
                                 menuValues<<mainCourse[i]<<endl<<costOfMC[i]<<endl;
                         menuValues<<endl;
                         
                         //Write Desserts
                         menuValues<<countOfMenuItems[2]<<endl;
                         for(int i=0;i<countOfMenuItems[2];++i)
                                 menuValues<<desserts[i]<<endl<<costOfD[i]<<endl;
                         menuValues<<endl;
                         
                         //Write Beverages
                         menuValues<<countOfMenuItems[3]<<endl;
                         for(int i=0;i<countOfMenuItems[3];++i)
                         menuValues<<beverages[i]<<endl<<costOfB[i]<<endl;
                         menuValues<<endl;
                         
                         menuValues.close();
                  }
                  
                //Read Menu From File
                void readMenuFromFile()
                  {
                      
                         ifstream menuRead;
                         menuRead.open("MenuDetails.txt");
                         
                         //Read Appetizers
                         menuRead>>countOfMenuItems[0];
                         for(int i=0;i<countOfMenuItems[0];++i)
                         {
                             menuRead.ignore();
                             menuRead.getline(appetizers[i],'#');
                             menuRead>>costOfA[i];                                   
                         }  
                         
                         //Read Main Course
                         menuRead>>countOfMenuItems[1];
                         for(int i=0;i<countOfMenuItems[1];++i)
                         {
                             menuRead.ignore();
                             menuRead.getline(mainCourse[i],'#');
                             menuRead>>costOfMC[i];
                         }
                          
                         //Read Desserts
                         menuRead>>countOfMenuItems[2];
                         for(int i=0;i<countOfMenuItems[2];++i)
                         {
                             menuRead.ignore();
                             menuRead.getline(desserts[i],'#');
                             menuRead>>costOfD[i];
                         }
                           
                         //Read Beverages
                         menuRead>>countOfMenuItems[3];
                         for(int i=0;i<countOfMenuItems[3];++i)
                         {
                             menuRead.ignore();
                             menuRead.getline(beverages[i],'#');
                             menuRead>>costOfB[i];
                         }
                         
                         menuRead.close();   
                         getLengthOfMenuItems();                                  
                  }
                  
                  //Get length of Menu items
                  void getLengthOfMenuItems()
                  {
                      //Appetizers
                      for(int i=0;i<countOfMenuItems[0];++i)
                      {
                          lenA[i]=0;
                          for(int u=0;appetizers[i][u]!='\0';++u)
                          lenA[i]++;
                      }
                     
                      //Main Course
                      for(int i=0;i<countOfMenuItems[1];++i)
                      {
                          lenMC[i]=0;
                          for(int u=0;mainCourse[i][u]!='\0';++u)
                          lenMC[i]++;
                      }
                      
                      //Desserts
                      for(int i=0;i<countOfMenuItems[2];++i)
                      {
                          lenD[i]=0;
                          for(int u=0;desserts[i][u]!='\0';++u)
                          lenD[i]++;
                      }
                      
                      //Beverages
                      for(int i=0;i<countOfMenuItems[3];++i)
                      {
                          lenB[i]=0;
                          for(int u=0;beverages[i][u]!='\0';++u)
                          lenB[i]++;
                      }
                      
                  }
                  
                //New Customer
                void newCustomer()
                  {
                      
                       char yn;
                       
                       header();
                       
                       cout<<endl<<endl<<"New Customer"<<endl<<endl;
                       cin.ignore();
                       
                       //Customer Details
                       cout<<"Name:"; cin.getline(customer_name,'#');
                   	
                       point5:;
                       cout<<"Mobile:";cin>>mobile;
                       for(m=0;mobile[m]!='\0';++m);
                       if(m!=10)
                       {
                                a=0;
                                cout<<"\nPlease enter a valid mobile number[10 digit].\n\n";
                                while(a<500000000)
                                {a++;}
                                goto point5;
                       }
                      mobile[10]='.';
                      mobile[11]='t';
                      mobile[12]='x';
                      mobile[13]='t';
                      restaurantStats();
                      readUserDetailsFromFile();
                      if(noOfOrders==0)
                          {writeUserDetailsToFile();}
                        
                        cout<<endl;
                        system("cls");
                        header();
                        
                        //Order Details
                        cout<<"\n\t\t\t\t\t\t\t\t<Menu>"<<endl;
                        
                       //Appetizers
                       if(countOfMenuItems[0]>0)
                       {
                             
                             cout<<"Appetizers:-"<<endl<<endl;
                             for(int i=0;i<countOfMenuItems[0];++i)
                             {
                                     cout<<i+1<<")"<<appetizers[i]<<" - Rs."<<costOfA[i]<<endl;
                             }
                             cout<<endl;
                              ca=0;
                             do{
                                 pointa:;
                                 cout<<"Item:";cin>>orderA[ca];
                                 cout<<"Quantity:";cin>>qa[ca];
                                 ca++;
                                 cout<<"Anything else(y/n)?:";cin>>yn;
                                 if(yn=='y')
                                 {
                                            cout<<endl;
                                            goto pointa;
                                 }           
                            }while(yn=='y');
                       }
                   
                       system("cls");
                       header();
                       
                       //Main Course
                       if(countOfMenuItems[1]>0)
                       {
                             cout<<"\n\t\t\t\t\t\t\t\t<Menu>"<<endl;
                             cout<<"Main Course:-"<<endl<<endl;
                             for(int i=0;i<countOfMenuItems[1];++i)
                             {
                                     cout<<i+1<<")"<<mainCourse[i]<<" - Rs."<<costOfMC[i]<<endl;
                             }
                             cout<<endl;
                              cmc=0;
                             do{
                                 pointmc:;
                                 cout<<"Item:";cin>>orderMC[cmc];
                                 cout<<"Quantity:";cin>>qmc[cmc];
                                 cmc++;
                                cout<<"Anything else(y/n)?:";cin>>yn;
                                if(yn=='y')
                                {
                                           cout<<endl;
                                           goto pointmc;
                                }                  
                            }while(yn=='y');
                      }
                      
                       system("cls");
                       header();
                       
                       //Desserts
                       if(countOfMenuItems[2]>0)
                       {
                             cout<<"\n\t\t\t\t\t\t\t\t<Menu>"<<endl;
                             cout<<"Desserts:-"<<endl<<endl;
                             for(int i=0;i<countOfMenuItems[2];++i)
                             {
                                     cout<<i+1<<")"<<desserts[i]<<" - Rs."<<costOfD[i]<<endl;
                             }
                             cout<<endl;
                              cd=0;
                             do{
                                 pointd:;
                                 cout<<"Item:";cin>>orderD[cd];
                                 cout<<"Quantity:";cin>>qd[cd];
                                 cd++;
                                 cout<<"Anything else(y/n)?:";cin>>yn;
                                 if(yn=='y')
                                 {
                                            cout<<endl;
                                            goto pointd;
                                 }                      
                            }while(yn=='y');
                      }
                      
                       system("cls");
                       header();
                       
                       //Beverages
                       if(countOfMenuItems[3]>0)
                       {
                             cout<<"\n\t\t\t\t\t\t\t\t<Menu>"<<endl;
                             cout<<"Beverages:-"<<endl<<endl;
                             for(int i=0;i<countOfMenuItems[3];++i)
                             {
                                     cout<<i+1<<")"<<beverages[i]<<" - Rs."<<costOfB[i]<<endl;
                             }
                             cout<<endl;
                              cb=0;
                             do{
                                 pointb:;
                                 cout<<"Item:";cin>>orderB[cb];
                                 cout<<"Quantity:";cin>>qb[cb];
                                 cb++;
                                 cout<<"Anything else(y/n)?:";cin>>yn;
                                 if(yn=='y')
                                 {
                                            cout<<endl;
                                            goto pointb;
                                 }                      
                            }while(yn=='y');
                      }
                      
                      system("cls");
                      header();
                      cout<<endl;
                      cout<<endl<<"Name:"<<customer_name<<endl<<"Mobile:";
                      for(int u=0;u<10;++u)
                          cout<<mobile[u];
                      cout<<endl<<endl;
                      for(int u=0;u<53;++u)
                          cout<<"-";
                          cout<<endl;
                      cout<<setw(10)<<"Item"<<setw(20)<<"Quantity"<<setw(10)<<"Cost"<<setw(10)<<"Price"<<endl;
                      
                      //Appetizers
                      for(int u=0;u<ca;++u)
                      {
                              
                              cout<<appetizers[orderA[u]-1]<<setw(27-(lenA[orderA[u]-1]))<<qa[(orderA[u])-1]<<setw(13)<<costOfA[orderA[u]-1]<<setw(10)<<costOfA[orderA[u]-1]*qa[(orderA[u])-1]<<endl;
                      }
                      
                      //Main Course
                       for(int u=0;u<cmc;++u)
                      {
                             
                              cout<<mainCourse[orderMC[u]-1]<<setw(27-(lenMC[orderMC[u]-1]))<<qmc[(orderMC[u])-1]<<setw(13)<<costOfMC[orderMC[u]-1]<<setw(10)<<costOfMC[orderMC[u]-1]*qmc[(orderMC[u])-1]<<endl;
                      }
                      
                      //Desserts
                       for(int u=0;u<cd;++u)
                      {
                              
                              cout<<desserts[orderD[u]-1]<<setw(27-(lenD[orderD[u]-1]))<<qd[(orderD[u])-1]<<setw(13)<<costOfD[orderD[u]-1]<<setw(10)<<costOfD[orderD[u]-1]*qd[(orderD[u])-1]<<endl;
                      }
                      
                      //Beverages
                       for(int u=0;u<cb;++u)
                      {
                              
                              cout<<beverages[orderB[u]-1]<<setw(27-(lenB[orderB[u]-1]))<<qb[(orderB[u])-1]<<setw(13)<<costOfB[orderB[u]-1]<<setw(10)<<costOfB[orderB[u]-1]*qb[(orderB[u])-1]<<endl;
                      }       
                      //Total
                      tax = 0.12 * total;
                      
                      //Time of Order
                      time_t rawtime;
                      struct tm *localTime;    
                      time(&rawtime);
                      localTime = localtime(&rawtime);
                      Day    = localTime->tm_mday;
                      Month  = localTime->tm_mon + 1;
                      Year   = localTime->tm_year + 1900;
                      Hour   = localTime->tm_hour;
                      Min    = localTime->tm_min;
                      Sec    = localTime->tm_sec;
                  
                      writeUserOrderToFile();      
                      for(int u=0;u<53;++u)
                          cout<<"-";
                          cout<<endl<<setw(40)<<"Total"<<setw(10)<<total<<endl;
                          cout<<setw(40)<<"Tax(12%)"<<setw(10)<<tax<<endl;
                          cout<<setw(40)<<"Subtotal"<<setw(10)<<tax+total<<endl;      
                          for(int u=0;u<53;++u)
                          cout<<"-";
                          cout<<endl;
                          cout<<"Date of Order:";
                         cout<<Day<<"\\"<<Month<<"\\"<<Year<<" | "<<"Time of Order:"<<Hour<<":"<<Min<<":"<<Sec<<endl;       
                  }
                  
                //Write User Details to File
                void writeUserDetailsToFile()
                  {
                       ofstream user;
                       user.open(mobile,ios::app);
                       user<<customer_name<<endl;
                       for(m=0;m<10;++m)
                       {
                              user<<mobile[m];
                      }
                      noOfOrders++;
                      user<<endl<<noOfOrders;
                      user<<endl<<endl;
                       user.close();                            
                  }
                  
                //Read User Details From File
                void readUserDetailsFromFile()
                  {
                      ifstream user;
                      user.open(mobile);
                      user>>customer_name;
                      user>>mobile;
                      mobile[10]='.';
                      mobile[11]='t';
                      mobile[12]='x';
                      mobile[13]='t';
                      user>>noOfOrders;
                      user.close();
                  }
                  
                //Write user order to file
                void writeUserOrderToFile()
                  {
                      ofstream order;
                      order.open(mobile,ios::app);
                      order<<"\nDate of Order:";
                      order<<Day<<"\\"<<Month<<"\\"<<Year<<" | "<<"Time of Order:"<<Hour<<":"<<Min<<":"<<Sec<<endl;
                      order<<setw(10)<<"Item"<<setw(20)<<"Quantity"<<setw(10)<<"Cost"<<setw(10)<<"Price"<<endl;
                      
                      //Appetizers
                      for(int u=0;u<ca;++u)
                      {
                              total+=costOfA[orderA[u]-1]*qa[(orderA[u])-1];
                              order<<appetizers[orderA[u]-1]<<setw(27-(lenA[orderA[u]-1]))<<qa[(orderA[u])-1]<<setw(13)<<costOfA[orderA[u]-1]<<setw(10)<<costOfA[orderA[u]-1]*qa[(orderA[u])-1]<<endl;
                      }
                      
                      //Main Course
                       for(int u=0;u<cmc;++u)
                      {
                              total+=costOfMC[orderMC[u]-1]*qmc[(orderMC[u])-1];
                              order<<mainCourse[orderMC[u]-1]<<setw(27-(lenMC[orderMC[u]-1]))<<qmc[(orderMC[u])-1]<<setw(13)<<costOfMC[orderMC[u]-1]<<setw(10)<<costOfMC[orderMC[u]-1]*qmc[(orderMC[u])-1]<<endl;
                      }
                      
                      //Desserts
                       for(int u=0;u<cd;++u)
                      {
                              total+=costOfD[orderD[u]-1]*qd[(orderD[u])-1];
                              order<<desserts[orderD[u]-1]<<setw(27-(lenD[orderD[u]-1]))<<qd[(orderD[u])-1]<<setw(13)<<costOfD[orderD[u]-1]<<setw(10)<<costOfD[orderD[u]-1]*qd[(orderD[u])-1]<<endl;
                      }
                      
                      //Beverages
                       for(int u=0;u<cb;++u)
                      {
                              total+=costOfB[orderB[u]-1]*qb[(orderB[u])-1];
                              order<<beverages[orderB[u]-1]<<setw(27-(lenB[orderB[u]-1]))<<qb[(orderB[u])-1]<<setw(13)<<costOfB[orderB[u]-1]<<setw(10)<<costOfB[orderB[u]-1]*qb[(orderB[u])-1]<<endl;
                      }       
                      //Total
                      tax = 0.12 * total;
                      for(int u=0;u<53;++u)
                          order<<"-";
                          order<<endl<<setw(40)<<"Total"<<setw(10)<<total<<endl;
                          order<<setw(40)<<"Tax(12%)"<<setw(10)<<tax<<endl;
                          order<<setw(40)<<"Subtotal"<<setw(10)<<tax+total<<endl;
                      order.close();
                  }
                  
                //Update Restaurant Statistics
                void restaurantStats()
                  {
                      double customers=1;
                      double earnings;
                      
                      if(ifstream("Restaurant Statistics.txt"))
                      {
                          ifstream stats;
                          stats.open("Restaurant Statistics.txt");
                          stats>>customers;
                          stats>>earnings;
                          stats.close();
                          earnings+=(total+tax);
                          if(!ifstream(mobile))
                              customers+=1;
                      }
                      ofstream stats2;
                      stats2.open("Restaurant Statistics.txt");
                      stats2<<customers<<endl;
                      stats2<<earnings;
                  }
                  
                //Get Restaurant Statistics
                void getRStats()
                  {
                      
                      double c,b;
                      ifstream rstats;
                      rstats.open("Restaurant Statistics.txt");
                      rstats>>c;
                      rstats>>b;
                      system("cls");
                      header();
                      cout<<endl<<"Restaurant Statistics:-";
                      cout<<endl<<endl<<"Total customers:"<<c<<endl;
                      cout<<"Total billings:"<<b;
                      rstats.close();
                      //getch();
                      
                  }
                  
                //Old Customer
                void oldCustomer()
                  {
                      char yn;
                      header();int j=1,oldCustSelect,pOrderSelect;
                      char orders[120],date[15]="Date of Order";
                      cout<<endl<<endl<<"Old Customer"<<endl<<endl<<"Mobile:";cin>>mobile;
                      mobile[10]='.';
                      mobile[11]='t';
                      mobile[12]='x';
                      mobile[13]='t';
                      system("cls");
                      header();
                      ifstream oldCust;
                      oldCust.open(mobile);
                      oldCust>>customer_name;
                      cout<<endl<<endl<<"Name:"<<customer_name<<endl;
                      oldCust>>mobile;
                      
                      cout<<"Mobile:"<<mobile<<endl<<endl;
                       mobile[10]='.';
                      mobile[11]='t';
                      mobile[12]='x';
                      mobile[13]='t';
                      
                      cout<<"1)Place order\n2)View previous orders\n\nSelect option:";cin>>oldCustSelect;
                      if(oldCustSelect==2)
                      {
                          system("cls");
                          header();
                          cout<<"\n\nPrevious orders of "<<customer_name<<":-\n\n";
                                  while(oldCust)
                              {
                                  oldCust.getline(orders,'?');
                                  if(strncmp(orders,date,13)==0)
                                  {
                                      cout<<j<<")"<<orders<<endl;
                                      j++;
                                  }
                              }            
                              oldCust.close();
                              ifstream oldCust2;
                              oldCust2.open(mobile);
                          cout<<"\nSelect order:";cin>>pOrderSelect;cout<<endl<<endl;
                          j=0;           
                          while(oldCust2)
                              {
                                  oldCust2.getline(orders,'?');
                                  
                                  if(strncmp(orders,date,13)==0)
                                  {
                                      //cout<<orders<<" " <<j<<endl;
                                      ++j;
                                      if(j==pOrderSelect)
                                      {
                                          oPrint:;
                                          oldCust2.getline(orders,'?');
                                          if(strncmp(orders,date,13)!=0)
                                          {
                                              if(oldCust2.eof())
                                                  goto exit;
                                                  
                                              cout<<orders<<endl;
                                              goto oPrint;
                                          }
                                          
                                      }
                                  }
                                  
                              }   
                              exit:;  
                              oldCust2.close();
                              //getch();           
                      }
                      if(oldCustSelect==1)
                      {
                            total=0;
                            tax=0;
                            system("cls");
                        header();
                        
                        //Order Details
                        cout<<"\n\t\t\t\t\t\t\t\t<Menu>"<<endl;
                        
                       //Appetizers
                       if(countOfMenuItems[0]>0)
                       {
                             
                             cout<<"Appetizers:-"<<endl<<endl;
                             for(int i=0;i<countOfMenuItems[0];++i)
                             {
                                     cout<<i+1<<")"<<appetizers[i]<<" - Rs."<<costOfA[i]<<endl;
                             }
                             cout<<endl;
                              ca=0;
                             do{
                                 pointa:;
                                 cout<<"Item:";cin>>orderA[ca];
                                 cout<<"Quantity:";cin>>qa[ca];
                                 ca++;
                                 cout<<"Anything else(y/n)?:";cin>>yn;
                                 if(yn=='y')
                                 {
                                            cout<<endl;
                                            goto pointa;
                                 }           
                            }while(yn=='y');
                       }
                   
                       system("cls");
                       header();
                       
                       //Main Course
                       if(countOfMenuItems[1]>0)
                       {
                             cout<<"\n\t\t\t\t\t\t\t\t<Menu>"<<endl;
                             cout<<"Main Course:-"<<endl<<endl;
                             for(int i=0;i<countOfMenuItems[1];++i)
                             {
                                     cout<<i+1<<")"<<mainCourse[i]<<" - Rs."<<costOfMC[i]<<endl;
                             }
                             cout<<endl;
                              cmc=0;
                             do{
                                 pointmc:;
                                 cout<<"Item:";cin>>orderMC[cmc];
                                 cout<<"Quantity:";cin>>qmc[cmc];
                                 cmc++;
                                cout<<"Anything else(y/n)?:";cin>>yn;
                                if(yn=='y')
                                {
                                           cout<<endl;
                                           goto pointmc;
                                }                  
                            }while(yn=='y');
                      }
                      
                       system("cls");
                       header();
                       
                       //Desserts
                       if(countOfMenuItems[2]>0)
                       {
                             cout<<"\n\t\t\t\t\t\t\t\t<Menu>"<<endl;
                             cout<<"Desserts:-"<<endl<<endl;
                             for(int i=0;i<countOfMenuItems[2];++i)
                             {
                                     cout<<i+1<<")"<<desserts[i]<<" - Rs."<<costOfD[i]<<endl;
                             }
                             cout<<endl;
                              cd=0;
                             do{
                                 pointd:;
                                 cout<<"Item:";cin>>orderD[cd];
                                 cout<<"Quantity:";cin>>qd[cd];
                                 cd++;
                                 cout<<"Anything else(y/n)?:";cin>>yn;
                                 if(yn=='y')
                                 {
                                            cout<<endl;
                                            goto pointd;
                                 }                      
                            }while(yn=='y');
                      }
                      
                       system("cls");
                       header();
                       
                       //Beverages
                       if(countOfMenuItems[3]>0)
                       {
                             cout<<"\n\t\t\t\t\t\t\t\t<Menu>"<<endl;
                             cout<<"Beverages:-"<<endl<<endl;
                             for(int i=0;i<countOfMenuItems[3];++i)
                             {
                                     cout<<i+1<<")"<<beverages[i]<<" - Rs."<<costOfB[i]<<endl;
                             }
                             cout<<endl;
                              cb=0;
                             do{
                                 pointb:;
                                 cout<<"Item:";cin>>orderB[cb];
                                 cout<<"Quantity:";cin>>qb[cb];
                                 cb++;
                                 cout<<"Anything else(y/n)?:";cin>>yn;
                                 if(yn=='y')
                                 {
                                            cout<<endl;
                                            goto pointb;
                                 }                      
                            }while(yn=='y');
                      }
                      
                      system("cls");
                      header();
                      cout<<endl;
                      cout<<endl<<"Name:"<<customer_name<<endl<<"Mobile:";
                      for(int u=0;u<10;++u)
                          cout<<mobile[u];
                      cout<<endl<<endl;
                      for(int u=0;u<53;++u)
                          cout<<"-";
                          cout<<endl;
                      cout<<setw(10)<<"Item"<<setw(20)<<"Quantity"<<setw(10)<<"Cost"<<setw(10)<<"Price"<<endl;
                      
                      //Appetizers
                      for(int u=0;u<ca;++u)
                      {
                              
                              cout<<appetizers[orderA[u]-1]<<setw(27-(lenA[orderA[u]-1]))<<qa[(orderA[u])-1]<<setw(13)<<costOfA[orderA[u]-1]<<setw(10)<<costOfA[orderA[u]-1]*qa[(orderA[u])-1]<<endl;
                      }
                      
                      //Main Course
                       for(int u=0;u<cmc;++u)
                      {
                             
                              cout<<mainCourse[orderMC[u]-1]<<setw(27-(lenMC[orderMC[u]-1]))<<qmc[(orderMC[u])-1]<<setw(13)<<costOfMC[orderMC[u]-1]<<setw(10)<<costOfMC[orderMC[u]-1]*qmc[(orderMC[u])-1]<<endl;
                      }
                      
                      //Desserts
                       for(int u=0;u<cd;++u)
                      {
                              
                              cout<<desserts[orderD[u]-1]<<setw(27-(lenD[orderD[u]-1]))<<qd[(orderD[u])-1]<<setw(13)<<costOfD[orderD[u]-1]<<setw(10)<<costOfD[orderD[u]-1]*qd[(orderD[u])-1]<<endl;
                      }
                      
                      //Beverages
                       for(int u=0;u<cb;++u)
                      {
                              
                              cout<<beverages[orderB[u]-1]<<setw(27-(lenB[orderB[u]-1]))<<qb[(orderB[u])-1]<<setw(13)<<costOfB[orderB[u]-1]<<setw(10)<<costOfB[orderB[u]-1]*qb[(orderB[u])-1]<<endl;
                      }       
                      //Total
                      tax = 0.12 * total;
                      
                      //Time of Order
                      time_t rawtime;
                      struct tm *localTime;    
                      time(&rawtime);
                      localTime = localtime(&rawtime);
                      Day    = localTime->tm_mday;
                      Month  = localTime->tm_mon + 1;
                      Year   = localTime->tm_year + 1900;
                      Hour   = localTime->tm_hour;
                      Min    = localTime->tm_min;
                      Sec    = localTime->tm_sec;
                  
                      writeUserOrderToFile();      
                      for(int u=0;u<53;++u)
                          cout<<"-";
                          cout<<endl<<setw(40)<<"Total"<<setw(10)<<total<<endl;
                          cout<<setw(40)<<"Tax(12%)"<<setw(10)<<tax<<endl;
                          cout<<setw(40)<<"Subtotal"<<setw(10)<<tax+total<<endl;      
                          for(int u=0;u<53;++u)
                          cout<<"-";
                          cout<<endl;
                          cout<<"Date of Order:";
                         cout<<Day<<"\\"<<Month<<"\\"<<Year<<" | "<<"Time of Order:"<<Hour<<":"<<Min<<":"<<Sec<<endl;       
                  
                        }
                      
                  }
                  
                //Login
                void login()
                  {
                       
                       login:;
                       header();
                      char us[30],passw[30];
                      int u=0,p=0,u1=0,p1=0;
                      for(int k=0;username[k]!='\0';k++)
                          u+=(int)username[k];
                       for(int k=0;password[k]!='\0';k++)
                          p+=(int)password[k];
                      
                     
                      cout<<endl<<endl<<"Log In"<<endl<<endl;
                      cout<<"Username:";cin>>us;
                      cout<<"Password:";cin>>passw;
                      for(int k=0;us[k]!='\0';k++)
                          u1+=(int)us[k];
                       for(int k=0;passw[k]!='\0';k++)
                          p1+=(int)passw[k];
                      if(u1!=u || p1!=p)
                      {
                          cout<<endl<<"Failed to Log In. Incorrect combination of username and password.";
                          for(unsigned long int q=0;q<800000000;++q);
                          system("cls");
                          goto login;
                      }
                  }
                  
                  //Close Bakery
                  void closeBakery()
                  {
                      system("cls");
                      header();
                      cout<<"\n\nTata!";
                      for(unsigned long int q=0;q<800000000;++q);
                  }
             
                                                                         
}Object;//Class end

//Main Start
int main()
{
          system("color 8f");
          //Function Prototypes
      
          
          //Function Calls
          Object.readInitialValuesFromFile();
          Object.countOfRName = Object.getLengthOfRestaurantName();
          Object.checkMain = Object.checkFirstRun();
          Object.login();
          initial:;
          Object.mainScreenSelect = Object.mainScreen();
          
          
          switch(Object.mainScreenSelect){
          case 1://New Customer
                 Object.readMenuFromFile();
                 Object.newCustomer();
                 Object.restaurantStats();
                
                 break;
          case 2://Old Customer
                Object.readMenuFromFile();
                Object.oldCustomer();
                Object.restaurantStats();
                 break;
                 
          case 3://Edit Menu
                 Object.editMenu();  
                 Object.writeMenuToFile();
                       
                 break;
          case 4://Edit Restaurant Details
                 Object.readInitialValues();
                 Object.enterInitialValuesToFile();  
                 break;
                 
          case 5://Stats
                Object.getRStats();
                 break;
                 
          case 6://Exit
                Object.closeBakery();
                 break;
                 
          default:
                cout<<"\n\nPlease select a valid option.";
                for(int time=0;time<100000000;++time);
                system("cls");
                goto initial;
                
                  break;
          }
          
                          
          getch();
          
                system("cls");
                goto initial;
   
}
