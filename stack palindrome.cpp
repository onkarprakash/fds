#include <iostream>
using namespace std; 
const int N=50;

class stack{
    private:
    char arr[N];
    int top;
    public:
    stack(){
        top=-1;
    }
    void push(char n);
    char pop();
    int peek();

};

void stack::push(char n){
    if (top==N-1){
        cout<<"stack overflow";
    }
    else{
        top++;
        arr[top]=n;
    }

}

char stack ::pop(){
    if(top==-1){
        cout<<"underflow";
        return -1;
    }
    else{
        char item=arr[top];
        top--;
        return item;
    }
}

int stack::peek(){
    return top;
}

void palindrome(string str1,string str2){
    int count=0;
    for(int i=0;i!=str1.size();i++){
        if(str1[i]==str2[i]){
            count++;
        }
    }
    if(count==str1.size()){
        cout<<"it is a palindrome";
    }
    else{
        cout<<"it is not a plindrome";
    }
}

int main(){
    stack s;
    string str;
    
    cout<<"Enter the string:";
    getline(cin,str);
    string str1="";
    for(int i=0;i!=str.size();i++){
        char ch=str[i];
        if(ch>='a' && ch<='z'){
            ch=(char)(ch-'a'+'A');
        }
        if(ch>='A' && ch<='Z'){
            s.push(ch);
            str1.push_back(ch);
        }
    }
    
    string str2="";
    for(int i=s.peek();i>=0;i--){
        char ch=s.pop();
        str2.push_back(ch);
    }

    cout<<"original string:"<<str<<endl;
    cout<<"converted string:"<<str1<<endl;
    cout<<"reverse string:"<<str2<<endl;
    palindrome(str1,str2);

}