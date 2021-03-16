import gmpy2

def sqr(x):
	return x * x;

I = 10 ** 200000

a = I
b = gmpy2.iroot(2 * I * I, 2)[0] // 2
t = I * I * I // 4
p = I

for i in range(25):
	(a, b, t, p)=((a + b) // 2, gmpy2.iroot(a * b, 2)[0],t - p * sqr((a - b) // 2),p * 2)

PI = sqr(a + b) * I * I // (4 * t)

f = []
while(PI):
	f.append(PI % 10)
	PI //= 10

f.reverse()

print("3.",end="")
for i in range(1,100001):
	print(f[i],end="")

print()


