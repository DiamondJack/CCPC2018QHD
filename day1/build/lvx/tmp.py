from os import system

for i in range(1, 21) : 
	system("./val <buildnet%d.in" % i)
	system("time ./cost <buildnet%d.in >ans" % i)
#	system("time ./std <buildnet%d.in >buildnet%d.ans" % (i, i))
	if system("diff ans buildnet%d.ans" % i) :
		print("WA on testcase #%d" % i)
		exit(0)
	print("Testcase #%d ok." % i)
