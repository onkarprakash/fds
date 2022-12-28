# function for selection sort
def selection_sort(arr,n):
    for i in range(n-1):
        mina=i
        for j in range(i+1,n):
            if arr[j]<arr[mina]:
                mina=j
        (arr[i],arr[mina])=(arr[mina],arr[i])
    print("Marks after sorting",arr)

# function for bubble sort
def bubble_sort(arr,n):
    for i in range(n):
        for j in range(0,n-i-1):
            if arr[j]>arr[j+1]:
                (arr[j],arr[j+1])=(arr[j+1],arr[j])
    print("Marks after sorting",arr)

# function to print top 5 scores
def printarr(arr,n):
    print("top 5 scores are:")
    for i in range(0, 5):
        print(arr[n - i - 1], end=" ")

print("1.Selection Sort")
print("2.Bubble Sort")
c=int(input("Select your choice:"))

if c==1 or c==2:
    n=int (input("enter the no. of students: "))
    arr=[]
    for i in range (n):
        a=float(input("enter the percentage:"))
        arr.append(a)
if c==1:
    print("Marks before sorting",arr)
    selection_sort(arr,n)
    printarr(arr,n)
elif c==2:
    print("Marks before sorting", arr)
    bubble_sort(arr,n)
    printarr(arr, n)
else:
    print("Invalid Choice")

