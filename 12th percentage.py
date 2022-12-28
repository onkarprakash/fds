
def bucket_s(marks_b,n):
    bucket=[]
    for i in range(10):
        bucket.append([])
        
    for j in marks_b:
        index_b=int(10*j)
        bucket[index_b].append(j)
    
    for i in range(10):
        bucket[i]=sorted(bucket[i])
    k=0    
    for i in range(10):
        for j in range(len(bucket[i])):
                  marks_b[k]=bucket[i][j]
                  k+=1
   
    return marks_b

marks=[]
n = int(input("Enter number of students whose percentage are to be displayed : "))
print("Enter percentage for",n,"students (Press ENTER after every students marks): ")
for i in range(0, n):
    ele = int(input())
    marks.append(ele)  

print("The marks of",n,"students are : ")
print(marks)

marks_b=[]
for i in range(n):
    a= marks[i]/100
    marks_b.append(a)
 
c=bucket_s(marks_b,n)

per=[]
for i in range(n):
    b=c[i]*100
    per.append(b)
print(per)
    