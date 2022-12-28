R=int(input("Enter the no of rows:"))
C=int(input("enter no of columns:"))
matrix=[]
print("Enter the entries row wise:")
for i in range(R):
    a=[]
    for j in range(C):
        a.append(int(input()))
    matrix.append(a)
for i in range(R):
    for j in range(C):
        print(matrix[i][j],end=" ")
    print()                                        
R=int(input("Enter the no of rows:"))
C=int(input("enter no of columns:"))
matrix1=[]
print("Enter the entries row wise:")
for i in range(R):
    b=[]
    for j in range(C):
        b.append(int(input()))
    matrix1.append(b)
for i in range(R):
    for j in range(C):
        print(matrix1[i][j],end=" ")
    print()                                     
print("addition:")
for i in range(R):
    for j in range(C):
        print((matrix1[i][j]+matrix[i][j]), end = " ")
    print()
print("subtraction:")
for i in range(R):
    for j in range(C):
        print((matrix1[i][j]-matrix[i][j]), end = " ")
    print()
        
Trans=[[0 for i in range(C)]for i in range(R)]        
for i in range(R):
    for j in range(C):
        Trans[i][j]=matrix[j][i]
print("Transpose is:")
for t in Trans:
    print(t)
    
result=[[0 for i in range(C)] for i in range(R)]
for i in range(len(matrix)):
    for j in range(len(matrix1[0])):
        for k in range(len(matrix1)):
            result [i][j]+=matrix[i][k]*matrix1[k][j]
print("\nProduct is: ")
for r in result:
    print(r)
