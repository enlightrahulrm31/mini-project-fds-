#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

//                      project student management system
//                      Data structure used - Linked list ,arrays
//                      concept used - if-else ,for loop,while loop
//                      Made By:
//                      - Rahul Ramesh Mahant (7240)
//                      - Parshant Rajput (7234)
//
bool check = true;
int freq_rollno[100005];
int dis_arr[100005];
int len_arr=0;
int chec_repition(int x){
    if(freq_rollno[x])return true;
    else return false;
}
struct node    //structure of node//
{
 char name[100005];
 char clg_name[100005];
 int rollNo;
 char section;
 node *next;
}*head,*lastptr;

void add()    //Adds record of student//
{
 node *p;
 p=new node;
 cout<<"Enter name of student:"<<endl;
 gets(p->name);
 fflush(stdin);
 cout<<"Enter clg_name of student:"<<endl;
 gets(p->clg_name);
 fflush(stdin);
 cout<<"Enter Roll Number of student:"<<endl;
 cin>>p->rollNo;
 int k=p->rollNo;
 dis_arr[len_arr]=k;
 freq_rollno[k]++;
 len_arr++;
 fflush(stdin);
 cout<<"Enter section of student:"<<endl;
 cin>>p->section;
 fflush(stdin);
 p->next=NULL;

 if(check)
 {
  head = p;
  lastptr = p;
  check = false;
 }
 else
 {
  lastptr->next=p;
  lastptr=p;
 }
 cout<<endl<<"Recored Entered";
 getch();
}
void search(int x)   //searches record of student//
{
 node *prev=NULL;
 node *current=NULL;
 int roll_no;
 roll_no=x;;
 prev=head;
 current=head;
 while(current->rollNo!=roll_no)
 {
  prev=current;
  current=current->next;
 }
 cout<<"\nname: ";
 puts(current->name);
 cout<<"\nRoll No:";
 cout<<current->rollNo;
 cout<<"\nclg_name:";
 puts(current->clg_name);
 cout<<"\nSection:";
 cout<<current->section;
  //getch();
}
void findd(int x)   //searches record of student//
{
 node *prev=NULL;
 node *current=NULL;
 int roll_no;
 roll_no=x;;
 prev=head;
 current=head;
 while(current->rollNo!=roll_no)
 {
  prev=current;
  current=current->next;
 }
 cout<<"\nname: ";
 puts(current->name);
 cout<<"\nRoll No:";
 cout<<current->rollNo;
 cout<<"\nclg_name:";
 puts(current->clg_name);
 cout<<"\nSection:";
 cout<<current->section;
  getch();
}
void del()    //deletes record of a student//
{
 node *ptr=NULL;
 node *prev=NULL;
 node *current=NULL;
 int roll_no;
 cout<<"Enter Roll Number to Delete:"<<endl;
 cin>>roll_no;
 freq_rollno[roll_no]--;
 prev=head;
 current=head;
 while(current->rollNo!=roll_no)
 {
  prev=current;
  current=current->next;
 }
 prev->next = current->next;
 current->next=NULL;
 delete current;
 cout<<endl<<"Recored Deleted";
 getch();
}
void modify()   //modifies record of student//
{
 node *ptr;
 node *prev=NULL;
 node *current=NULL;
 int roll_no;
 del();
 add();
 cout<<endl<<"Recored Modified";
 getch();
}
void display(){
    for(int i=0;i<len_arr;i++){
        if(freq_rollno[dis_arr[i]]==1){
                search(dis_arr[i]);
                cout<<"\n-------------------------\n";
        }
    }
    getch();

}
int main()
{
 char x;
 cout<<"\t\t ********************************* \t\t\t"<<endl;
 cout<<"\t\t ****STUDENT MANAGEMENT SYSTEM**** \t\t\t"<<endl;
 cout<<"\t\t ********************************* \t\t\t"<<endl;
 cout<<"\n\nPress Any Key To Continue . . . ."<<endl;
 getch();
 do
 {
  system("cls");
  cout<<"1--->Press '1' to add New record:"<<endl;
  cout<<"2--->Press '2' to search a record:"<<endl;
  cout<<"3--->Press '3' to modify a record:"<<endl;
  cout<<"4--->Press '4' to delete a record:"<<endl;
  cout<<"5--->Press '5' to display a record:"<<endl;
  cout<<"6--->Press '6' to exit:"<<endl;
  x=getch();
  if(x=='1')
  {
   system("cls");
   add();
  }
  else if(x=='2')
  {
   system("cls");
   cout<<"Enter Roll Number to search:"<<endl;
   int p;
   cin>>p;
   findd(p);
  }
  else if(x=='3')
  {
   system("cls");
   modify();
  }
  else if(x=='4')
  {
   system("cls");
   del();
  }
  else if(x=='5'){
    system("cls");
    display();
  }
  else if(x=='6')
  {
   exit(0);
  }
  else
  {
  }
 }while(x != 27);
 getch();
}
