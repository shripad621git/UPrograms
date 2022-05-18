import os
rows, columns = os.popen('stty size', 'r').read().split()
r=int(rows)
c=int(columns)
n = int(input("Enter number of rows:"))
for i in range(int(r/2-n/2)):
print()
for i in range(n):
for k in range(int(c/2)-int(n/2)):
print(" ",end="")
for k in range(n-i-1):
print(" ",end="")
for k in range(2*i+1):
print("*",end="")
print("\n",end="")
for i in range(int(r/2-n/2)):
print()

