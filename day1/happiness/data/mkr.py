from random import *

mod = 3#998244353

C = [(5, 4)] #[(randint(500, 1000), randint(500, 1000)) for i in xrange(97)] + [(100000, 50000)] * 3
shuffle(C)
print len(C)
for (N, Q) in C:
	print N, Q
	for i in xrange(N):
		k = min(5, randint(0, 10))
		print k, " ".join([str(randint(0 if j < k else 1, mod - 1)) for j in xrange(k + 1)])
	# Fa = []
	M = randint(N/4, 3*N/4)
	for i in xrange(2, M + 1):
		Fa = randint(max(1, i - 5), i - 1)
		assert 1 <= Fa < i
		print Fa, i
	for i in xrange(M + 1, N + 1):
		Fa = randint(max(1, M - 3), M)
		assert 1 <= Fa < i
		print Fa, i
	for i in xrange(Q):
		print randint(1, N), randint(1, N), randint(0, mod - 1)


