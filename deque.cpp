#include<iostream>
using namespace std;

class Deque{
int *arr;
int front;
int rear;
int size;

public:
Deque(int n){
size = n;
arr= new int[n];
front = -1;
rear = -1;
}
bool isEmpty(){
if(front==-1){
return true;
}
else{
return false;
}
}

bool isFull(){
if((front==0 && rear == size-1 )|| ( rear==(front-1)%(size-1))){
return true;
}
else{
return false;
}
}

bool pushfront(int x){
if( isFull()){
return false;
}
else if(isEmpty()){
front = rear = 0;
}
else if(front==0 && rear != size-1 ){
front = size -1;
}
else{
front --;
}
arr[front]=x;
return true;
}

bool pushrear(int x){
if(isFull()){
return false;
}
else if(isEmpty()){
front = rear =0;
}
else if(rear==size-1 && front != 0 ){
front=0;
}
else{
rear++;
}
arr[rear]= x;
return true;
}

int popfront(){
if(isEmpty()){
return -1;
}
int ans = arr[front];
arr[front]=-1;
if(front==rear){
front = rear = -1;
}
else if(front==size-1)
{
front=0;
}
else{
front++;
}
return ans;
}

int poprear(){
if(isEmpty()){
return -1;
}
int ans = arr[rear];
arr[rear]=-1;
if(front==rear){
front = rear=-1;
}
else if(rear==0){
rear=size-1;
}
else{
rear--;
}
return  ans;
}

void display(){
for(int i = front; i<=rear ;i++){
cout<<arr[i]<<" ";
}
}
};
int main()
{
int c;
int item;
Deque d1(16);

do
{
cout<<"DEQUE OPERATION"<<endl;
cout<<"Press NUM to access following Operation"<<endl;
cout<<"1- Insert at beginning"<<endl;
cout<<"2- insert at end"<<endl;
cout<<"3- Display"<<endl;
cout<<"4- Delete from front"<<endl;
cout<<"5- Delete from rear"<<endl;
cout<<"6- exit"<<endl;
cout<<"enter the valid choice<1-4>:";
cin>>c;

switch(c)
{
case 1:
cout<<"Enter the element to be inserted:  ";
cin>>item;
d1.pushfront(item);
break;

case 2:
cout<<" Enter the element to be inserted:";
cin>>item;
d1.pushrear(item);
break;

case 3:
d1.display();
break;

case 4:
d1.popfront();
break;

case 5:
d1.poprear();
break;

case 6:
exit(1);
break;

default:
cout<<" Invalid choice";
break;
}
}
while(c != 7);
return 0;
}

