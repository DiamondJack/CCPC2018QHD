import os;
import time;

NAME = 'connected'

def getIn(id):
	return str(id) + '.in'

def getOut(id):
	return str(id) + '.ans'

def genInput(id, **dictArgs):
	n = dictArgs['n'];
	k = dictArgs['k'];

	nameinput = getIn(id);
	cmd = 'gen %d %d %d >%s'%(n,k,id,nameinput);

	os.system(cmd);

nId = 1

#5 small test
for i in range(0,5):
	genInput(nId,n=100,k=50)
	nId += 1

#5 big tests
for i in range(0,5):
	genInput(nId,n=50000,k=500)
	nId += 1

for i in range(1,nId):
	nameinput = getIn(i);
	nameoutput = getOut(i);
	cur = time.time()
	os.system('std.exe <%s >%s'%(nameinput,nameoutput));
	print "Test %d completed, Std Time Usage: %0.5fs"%(i,time.time() - cur)
