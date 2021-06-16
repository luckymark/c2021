import gmpy2
import time

start = time.time()

def sqr(x):
	return x * x;

N = 1000000

I = 10 ** (2 * N)

a = I
b = gmpy2.iroot(2 * I * I, 2)[0] // 2
t = I * I * I // 4
p = I

for i in range(20):
	(a, b, t, p)=((a + b) // 2, gmpy2.iroot(a * b, 2)[0],t - p * sqr((a - b) // 2),p * 2)

PI = str(sqr(a + b) * I * I // (4 * t))

end = time.time()
print("Time=",end-start)

print(PI[: 1] + '.' + PI[1: N])
