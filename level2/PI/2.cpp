#include<bits/stdc++.h>

using namespace std;

#define gc c=getchar()

template<typename T>
inline void read(T&x){
	x=0;T k=1;char gc;
	while(!isdigit(c)){if(c=='-')k=-1;gc;}
	while(isdigit(c)){x=x*10+c-'0';gc;}x*=k;
}

typedef vector<int> poly;

struct comp{
	double r,i;
	comp():r(0),i(0){}
	comp(const double &_r,const double &_i):r(_r),i(_i){}
};

inline comp operator + (const comp &a,const comp &b){
	return comp(a.r+b.r,a.i+b.i);
}

inline comp operator - (const comp &a,const comp &b){
	return comp(a.r-b.r,a.i-b.i);
}

inline comp operator * (const comp &a,const comp &b){
	return comp(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
}

inline comp operator / (const comp &a,const double &b){
	return comp(a.r/b,a.i/b);
}

inline comp conj(const comp &a){
	return comp(a.r,-a.i);
}

const double PI=acos(-1.0);
const int N=1e7+7;
const int Limit=1000;

int rev[N];
comp Wn[N];
int Now_Len;
inline void revinit(int n){
	for(int i=0;i<n;++i)rev[i]=(rev[i>>1]>>1)|((i&1)*(n>>1));
	Wn[0]=comp(1,0);
	Wn[1]=comp(cos(2*PI/n),sin(2*PI/n));
	for(int i=2;i<n;++i)Wn[i]=Wn[i-1]*Wn[1];
	Now_Len=n;
}

void DFT(comp *A,int n){
	if(Now_Len!=n)revinit(n);
	for(int i=0;i<n;++i)if(i<rev[i])swap(A[i],A[rev[i]]);
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;j+=i<<1){
			for(int k=0;k<i;++k){
				comp u=A[j+k],v=A[i+j+k]*Wn[n/(i<<1)*k];
				A[j+k]=u+v;
				A[i+j+k]=u-v;
			}
		}
	}
}

void IDFT(comp *A,int n){
	if(Now_Len!=n)revinit(n);
	for(int i=0;i<n;++i)if(i<rev[i])swap(A[i],A[rev[i]]);
	for(int i=1;i<n;i<<=1){
		for(int j=0;j<n;j+=i<<1){
			for(int k=0;k<i;++k){
				comp u=A[j+k],v=A[i+j+k]*conj(Wn[n/(i<<1)*k]);
				A[j+k]=u+v;
				A[i+j+k]=u-v;
			}
		}
	}
	for(int i=0;i<n;++i){
		A[i]=A[i]/n;
	}
}

inline void out(const poly &C){
	for(int i=C.size()-1;~i;--i)printf("%d",C[i]);puts("");
}

inline poly Poly(const string &x){
	poly ret;
	for(int i=x.length()-1;~i;--i){
		ret.push_back(x[i]-'0');
	}
	return ret;
}

void add(poly &A,poly &B,poly &C){
	int lenA=A.size();
	int lenB=B.size();
	int lenC=max(lenA,lenB);
	C.resize(lenC);
	if(lenA>lenB){
		for(int i=0;i<lenB;++i)C[i]=A[i]+B[i];
		for(int i=lenB;i<lenA;++i)C[i]=A[i];
	}
	else{
		for(int i=0;i<lenA;++i)C[i]=A[i]+B[i];
		for(int i=lenA;i<lenB;++i)C[i]=B[i];
	}
	for(int i=1;i<lenC;++i){
		if(C[i-1]>9){
			C[i]++;
			C[i-1]-=10;
		}
	}
	if(C[lenC-1]>9)C.push_back(1),C[lenC-1]-=10;
}

void sub(poly &A,poly &B,poly &C){
	int lenA=A.size();
	int lenB=B.size();
	int lenC=max(lenA,lenB);
	C.resize(lenC);
	if(lenA>lenB){
		for(int i=0;i<lenB;++i)C[i]=A[i]-B[i];
		for(int i=lenB;i<lenA;++i)C[i]=A[i];
	}
	else{
		for(int i=0;i<lenA;++i)C[i]=A[i]-B[i];
		for(int i=lenA;i<lenB;++i)C[i]=B[i];
	}
	for(int i=1;i<lenC;++i){
		if(C[i-1]<0){
			C[i]--;
			C[i-1]+=10;
		}
	}
	while(lenC&&!C[lenC-1])--lenC;
	assert(lenC>=0);
	C.resize(lenC);
}

comp F[N],G[N],H[N];
void mul(poly &A,poly &B,poly &C){
	int lenA=A.size();
	int lenB=B.size();
	if(!lenA||!lenB){
		C.resize(0);
		return ;
	}
	int lenC=lenA+lenB-1,n;
	if(lenA<1e7/lenB){
		poly tmp;
		tmp.resize(lenC);
		for(int i=0;i<lenA;++i){
			for(int j=0;j<lenB;++j){
				tmp[i+j]+=A[i]*B[j];
			}
		}
		C=tmp;
	}
	else {	
		for(n=1;n<lenC;n<<=1);n>>=1;
		for(int i=0;i<n;++i){
			F[i]=comp(((i<<1)<lenA)?A[i<<1]:0,((i<<1|1)<lenA)?A[i<<1|1]:0);
			G[i]=comp(((i<<1)<lenB)?B[i<<1]:0,((i<<1|1)<lenB)?B[i<<1|1]:0);
		}
		DFT(F,n);DFT(G,n);
		for(int i=0,j;i<n;++i){
			j=(n-i)&(n-1);
			H[i]=F[i]*G[i]-(comp(1,0)+Wn[i])*(F[i]-conj(F[j]))*(G[i]-conj(G[j]))*comp(0.25,0);
		}
		IDFT(H,n);
		C.resize(lenC);
		for(int i=0;(i<<1)<lenC;++i){
			C[i<<1]=int(H[i].r+0.5);
			C[i<<1|1]=int(H[i].i+0.5);
		}
	}
	for(int i=1;i<lenC;++i){
		if(C[i-1]>9){
			int t=C[i-1]/10;
			C[i]+=t;
			C[i-1]-=10*t;
		}
	}
	while(C[lenC-1]>9){
		C.push_back(C[lenC-1]/10);
		C[lenC-1]%=10;
		++lenC;
	}
}

inline void shift(poly &A,int n){
	int lenA=A.size();
	if(n>=0){
		A.resize(lenA+n);
		for(int i=lenA+n-1;i>=n;--i)A[i]=A[i-n];
		for(int i=0;i<n;++i)A[i]=0;
	}
	else {
		for(int i=0;i<lenA+n;++i){
			A[i]=A[i-n];
		}
		A.resize(max(0,lenA+n));
	}
}

inline void shift(const poly &A,poly &C,int n){
	C=A;
	shift(C,n);
}

int inv(poly &A,poly &C){
	int lenA=A.size();
	C.resize(1);
	C[0]=10/A[lenA-1];
	int exp=lenA/Limit+1;
	shift(C,Limit*exp-lenA);
	poly t1,t2;
	shift(Poly("2"),t2,exp*Limit);
	for(int x=0;x<10;++x){
		mul(A,C,t1);
		sub(t2,t1,t1);
		mul(C,t1,C);
		shift(C,-exp*Limit);
	}
	return exp;
}

void div(poly &A,poly &B,poly &C){
	// puts("DIV");
	// out(A);
	// out(B);
	int exp=inv(B,C);
	mul(A,C,C);
	shift(C,-exp*Limit);
}

void div2(poly &A){
	int lenA=A.size();
	for(int i=lenA-1;i;--i){
		if(A[i]&1)A[i-1]+=10;
		A[i]>>=1;
	}
	A[0]>>=1;
	if(!A[lenA-1])A.pop_back();
}

void sqrt(poly &A,poly &C){
	int lenA=A.size();
	if(!lenA){
		C=A;
		return ;
	}
	C.resize((lenA+1)>>1);
	C[C.size()-1]=sqrt((lenA&1)?A[lenA-1]:(A[lenA-1]*10+A[lenA-2]));
	poly t;
	for(int x=0;x<10;++x){
		// out(C);
		div(A,C,t);
		add(C,t,C);
		div2(C);
	}
}

inline void test(){
	poly A=Poly("17");
	poly B=Poly("3");
	poly C;
	// inv(B,C);
	shift(A,Limit);
	// div(A,B,C);
	sqrt(A,C);
	// printf("%d\n",C.size());
	out(C);
	exit(0);
}

int main(){
	// test();
	poly a=Poly("1");
	shift(a,Limit);

	poly tmp=Poly("2");
	poly b;
	shift(tmp,2*Limit);
	sqrt(tmp,b);
	div2(b);

	poly t=Poly("1");
	shift(t,3*Limit);
	div2(t);
	div2(t);

	poly p=a;
	poly aa,bb,tt,pp;

	for(int i=0;i<10;++i){
		add(a,b,aa);
		div2(aa);

		mul(a,b,tt);
		sqrt(tt,bb);

		sub(a,b,tt);
		div2(tt);
		mul(tt,tt,tt);
		mul(p,tt,tt);
		sub(t,tt,tt);
		add(p,p,pp);

		a=aa;
		b=bb;
		t=tt;
		p=pp;
	}

	add(a,b,a);
	mul(a,a,a);
	shift(a,2*Limit);
	div2(a);
	div2(a);
	div(a,t,b);
	out(b);
}
