import math

def binary(phbk,low,high,key):
    mid=0
    while(low<=high):
        s1=low+high
        m1=s1/2
        mid=math.ceil(m1)

        if(phbk[mid][0]==key):
            return mid 
 
        elif (phbk[mid][0]<key):
            low=mid+1
        elif(phbk[mid][0]>key):
            high=mid-1
 
    return -1

def insert(phbk,x1):
    c=[x1]
    mob=int(input("enter mobile number of your friend"))
    c.append(mob)
    print(c)
    phbk.append(c)
    print(phbk)
    print("but for binary and fibonacci search record must be in sorted order in phonebook")
 
    sort(phbk)
 
def sort(phbk):
    for j in range(len(phbk)):
        swapped=False
        i=0
        while i<len(phbk)-1:
            if phbk[i][0]>phbk[i+1][0]:
                phbk[i],phbk[i+1]=phbk[i+1],phbk[i]
                swapped=True 
            i=i+1
        if swapped==False:
            break
    print("after sorting a data in aphonebook: ")
    print(phbk)

phbk=[["Kiran Vare",9730581308],["atharva tambe",9422146699],["ruturaj",9890598740]]

n=len(phbk)

print("record present in the phone book is:")
for i in range(n):
    print(phbk[i])
    print()
 
x=input("enter the friend you want to search:")
x1=x.lower()
print(x1)

result=binary(phbk,0,len(phbk)-1,x1)
if result !=-1:
    print(x1,"is present at index",str(result))
 
else:
    print(x1,"is not present in a phonebook")
    print("friend",x1,"is now inserted in a phonebook...")
    insert(phbk,x1)
    print("friend",x1,"info added succesfully in phone book....")

