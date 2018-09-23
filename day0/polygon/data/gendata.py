import os;
import time;

NAME = 'polygon'

def getIn(id):
	return str(id) + '.in'

def getOut(id):
	return str(id) + '.ans'

def genInput(id, **dictArgs):
	n = dictArgs['n'];
	m = dictArgs['m'];
	k = dictArgs['k'];
	R = dictArgs['R'];
	L = dictArgs['L'];

	nameinput = getIn(id);
	cmd = 'gen %d %d %d %d %d >%s'%(n,m,k,R,L,nameinput);

	os.system(cmd);

#5 small tests

nId = 1

genInput(nId,n=6,m=5,k=3,R=100,L=20);nId += 1
genInput(nId,n=6,m=7,k=3,R=100,L=50);nId += 1
genInput(nId,n=6,m=10,k=3,R=300,L=70);nId += 1
genInput(nId,n=6,m=10,k=4,R=300,L=70);nId += 1
genInput(nId,n=6,m=10,k=5,R=300,L=70);nId += 1

#5 middle tests

genInput(nId,n=30,m=30,k=3,R=600,L=100);nId += 1
genInput(nId,n=30,m=30,k=3,R=600,L=100);nId += 1
genInput(nId,n=30,m=30,k=10,R=1800,L=200);nId += 1
genInput(nId,n=30,m=30,k=12,R=1800,L=200);nId += 1
genInput(nId,n=30,m=30,k=15,R=1800,L=200);nId += 1

#5 big tests

genInput(nId,n=100,m=100,k=10,R=600,L=100);nId += 1
genInput(nId,n=100,m=100,k=13,R=600,L=100);nId += 1
genInput(nId,n=100,m=100,k=15,R=1800,L=200);nId += 1
genInput(nId,n=100,m=100,k=20,R=1800,L=200);nId += 1
genInput(nId,n=100,m=100,k=23,R=1800,L=200);nId += 1

for i in range(1,nId):
	nameinput = getIn(i);
	nameoutput = getOut(i);
	cur = time.time()
	os.system('std.exe <%s >%s'%(nameinput,nameoutput));
	print "Test %d completed, Std Time Usage: %0.5fs"%(i,time.time() - cur)
