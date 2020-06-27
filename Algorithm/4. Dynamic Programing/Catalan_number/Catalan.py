T = int(input())
a_size = 105
C = []
for j in range (105):
	C.append(0)
C[0] = 1
for n in range (1, 102):
	for i in range (n):
		C[n] = C[n] + C[i] * C[n-i-1]
while T > 0:
	N = int(input())
	print (C[N])
	T = T - 1

	
