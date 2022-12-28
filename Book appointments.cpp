
#include<iostream>
using namespace std;

int size;	

struct SLL_Node	
{
    int start;
    int end;
    int min;
    int max;
    int flag;
    struct SLL_Node *next;
}*head;


class App_Shedule
{
  public:
	void create_Shed();
         	 
	void display_Shed();

	void book_App();

	void cancel_App();

	void sort_App();
	
}A1;


int main()
{
   int ch;
   char ans;
   
   do
   {    
      cout<<"\n Menu";
      cout<<"\n 1. Create Appointment Schedule";
      cout<<"\n 2. Display Free Slots";
      cout<<"\n 3. Book an Appointment";
      cout<<"\n 4. Cancel an Appointment";
      cout<<"\n 5. Sort slots based on Time";

      
      cout<<"\n\n Enter your choice: ";                        
      cin>>ch;
      
      switch(ch)
      {
         case 1: A1.create_Shed();
         	 break;
         	 
         case 2: A1.display_Shed();
         	 break;         	 
         	 
         case 3: A1.book_App();
         	 break;
         	 
         case 4: A1.cancel_App();
         	 break;

         case 5: A1.sort_App();
         	 break;
         	 
         default: cout<<"\n Wrong choice";
	          	 
      }
      
      cout<<"\n\n Do you wanna continue? (y/n) : ";
      cin>>ans;
   }while(ans == 'y');
   
}


void App_Shedule :: create_Shed()           
{ 
    int i;
    struct SLL_Node *temp, *last;
    
    head = NULL;
    
    cout<<"\n\n How many Appointment Slots: ";
    cin>>size;
    
    for(i=0; i<size; i++)
    {
       temp = new(struct SLL_Node);         
       cout<<"\n\n Enter Start Time: ";   
       cin>>temp->start; 
       cout<<"\n\n Enter End Time: ";
       cin>>temp->end;
       cout<<"\n\n Enter Minimum Duration: ";
       cin>>temp->min;
       cout<<"\n\n Enter Maximum Duration: ";
       cin>>temp->max;
         temp->flag = 0;
       temp->next = NULL;
       
       if(head == NULL)
       {
          head = temp;
          last = head;
       }
       else
       {
          last->next = temp;
          last = last->next;
       }
       
    }
}

	 
void App_Shedule :: display_Shed()                   
{
   int cnt = 1;
   struct SLL_Node *temp;
   
   cout<<"\n\n Appointment Schdule";
   cout<<"\n\n Srno.\tStart\tEnd\tMin_Dur\tMax_Dur\tStatus";        
   
   temp = head;
   while(temp != NULL)
   {
      cout<<"\n\n "<<cnt;
      cout<<"\t "<<temp->start;
      cout<<"\t "<<temp->end;
      cout<<"\t  "<<temp->min;
      cout<<"\t  "<<temp->max;
      
      if(temp->flag)
         cout<<"\tBooked";                        
      else
         cout<<"\tFree";         
         
      temp = temp->next; 
      cnt++;  
   }
}


void App_Shedule :: book_App()              
{
    int start;
    struct SLL_Node *temp;

    cout<<"Please enter Appointment time: "<<endl;
    cin>>start;
 
   temp = head;

   while(temp != NULL)
   {
      if(start == temp->start)
      {
         if(temp->flag == 0)
         {
            cout<<"Appointment Slot is Booked"<<endl;
            temp->flag = 1;
         }
         else
            cout<<" Appointment Slot is not Available"<<endl;
      }

      temp = temp->next; 
   }

}
      
         

void App_Shedule :: cancel_App()          
{
    int start;
    struct SLL_Node *temp;

    cout<<" Please enter Appointment time to Cancel: "<<endl;
    cin>>start;
 
   temp = head;

   while(temp != NULL)
   {
      if(start == temp->start)
      {
         if(temp->flag == 1)
         {
            cout<<"Your Appointment Slot is Canceled"<<endl;
            temp->flag = 0;
         }
         else
            cout<<"appointment was not book"<<endl;
      }

      temp = temp->next; 
   }
}


void App_Shedule :: sort_App()              
{
   int i,j,val;
   struct SLL_Node *temp;


   for(i=0; i < size-1; i++) 	
   {
       temp = head;
       while(temp->next != NULL)
       { 
          if(temp->start > temp->next->start)
          {
              val = temp->start;
	      temp->start = temp->next->start;
	      temp->next->start = val;

              val = temp->end;
	      temp->end = temp->next->end;
	      temp->next->end = val;

              val = temp->min;
	      temp->min = temp->next->min;
	      temp->next->min = val;

              val = temp->max;
	      temp->max = temp->next->max;
	      temp->next->max = val;
	
          }
          temp = temp->next;
       }   
   }

   cout<<"\n\n\t The Appointments got Sorted";

}


