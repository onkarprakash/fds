#include <iostream>
#include<string.h>
using namespace std; 
const int N=10;

template<class T>
class stack{
    private:
    T arr[N];
    int top;
    public:
    stack(){
        top=-1;
    }
    bool empty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void push(T n){
        if (top==N-1){
        cout<<"stack overflow";
    }
    else{
        top++;
        arr[top]=n;
    }
    }
    void pop(){
        if(top!=-1){
        top--;
    }
    }
    T top1(){
        return arr[top];
    }


};

int precedence(char& c){
    if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}


string conversion(string infix){
    stack<char> s;
    string p;
    for(int i=0;infix[i]!='\0';i++){
        if(isdigit(infix[i]))
        {
            p+=infix[i];
        }
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(s.top1()!='(' && !s.empty())
            {
                char temp=s.top1();
                p+=temp;
                s.pop();
            }
            s.pop();
        }
        else
        {
            if(s.empty())
            {
                s.push(infix[i]);
            }
            else{
                char a=s.top1();
                if(precedence(infix[i])>precedence(a))
                {
                    s.push(infix[i]);
                }
                else{
                    while(!s.empty() && (precedence(infix[i])<=precedence(a)))
                    {
                        char temp=s.top1();
                        p+=temp;
                        s.pop();
                    }
                    s.push(infix[i]);

                }
            }

        }
    }
    while(!s.empty())
    {
        p+=s.top1();
        s.pop();
    }
    return p;
}
bool checkdigit(char temp){
   int dummy=temp-48;
   bool ans=0;
   if(dummy>=0 && dummy<=9){
    ans=1;
   }
   return ans;
}
void evaluation(string postfix){
    stack<int> s1;
    int len=postfix.length();
    for(int i=0;i<len;i++)
    {    
        if(checkdigit(postfix[i])){
            int x=postfix[i]-48;
            s1.push(x);
        }else{
            int op2 = s1.top1();
            s1.pop();
            int  op1 =s1.top1();
            s1.pop();
            if(postfix[i]=='*')
            {
                s1.push(op1*op2);
            }
            else if(postfix[i]=='/')
            {s1.push(op1/op2);
            }
            else if(postfix[i]=='+')
            {s1.push(op1+op2);
            }
            else if(postfix[i]=='-')
            {s1.push(op1-op2);
            }
        }
    }
}

int main()
{
    string postfix,infix;
    cout<<"Enter the Infix expression:"<<endl;
    cin>> infix;
    postfix=conversion(infix);
    cout<<"postfix:"<<postfix<<endl;
    evaluation(postfix);

    return 0;
}
