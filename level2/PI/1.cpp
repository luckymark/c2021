#include<bits/stdc++.h>
#include<ctime>
#include<gmp.h>

using namespace std;

const int N=10000;

char PI[N*2];

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	clock_t start=clock();

	mpz_t I;
	mpz_init(I);
	mpz_ui_pow_ui(I,10,N*2);

	mpz_t a;
	mpz_init(a);
	mpz_set(a,I);

	mpz_t b;
	mpz_init(b);
	mpz_mul(b,I,I);
	mpz_mul_ui(b,b,2);
	mpz_sqrt(b,b);
	mpz_div_ui(b,b,2);

	mpz_t t;
	mpz_init(t);
	mpz_mul(t,I,I);
	mpz_mul(t,t,I);
	mpz_div_ui(t,t,4);

	mpz_t p;
	mpz_init(p);
	mpz_set(p,I);

	for(int i=0;(1<<i)<(N<<1);++i){
		mpz_sub(I,a,b);
		mpz_div_ui(I,I,2);
		mpz_mul(I,I,I);
		mpz_mul(I,p,I);
		mpz_sub(t,t,I);

		mpz_mul_ui(p,p,2);

		mpz_set(I,a);
		mpz_add(a,a,b);
		mpz_div_ui(a,a,2);

		mpz_mul(b,I,b);
		mpz_sqrt(b,b);

	}

	mpz_add(a,a,b);
	mpz_mul(a,a,a);
	mpz_ui_pow_ui(I,10,N*4);
	mpz_mul(a,a,I);
	mpz_mul_ui(t,t,4);
	mpz_div(a,a,t);

	clock_t end=clock();

	printf("Time = %lfs\n",(double)(end-start)/CLOCKS_PER_SEC);

	mpz_get_str(PI,10,a);
	printf("3.");
	for(int i=1;i<N;++i)putchar(PI[i]);
	puts("");

	mpz_clear(I);
	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(t);
	mpz_clear(p);
	return 0;
}