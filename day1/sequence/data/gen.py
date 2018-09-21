import sys
import os
import random

if len(sys.argv)<4:
	print("Too Few Arguments.")
	exit()

n=int(sys.argv[1])
Q=int(sys.argv[2])
p=int(sys.argv[3])

mod=998244353

def num():
	if random.random()*100<p:
		return 0
	else:
		return random.randint(0,mod-1)

print(n)
a=[]
for i in range(n):
	a.append(str(num()))
print(' '.join(a))
print(Q)
for i in range(Q):
	pos=random.randint(1,n)
	value=num()
	print("{0} {1}".format(pos,value))


