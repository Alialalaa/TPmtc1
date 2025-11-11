#include <stdio.h>
#include <math.h>
#include <gmp.h>




void ex1(int c, int d) {
	int q1 = 0;
	int temp = c;
	while (temp >= d) {
		temp = temp - d;
		q1 = q1 + 1;
	}
	printf("%d = %d * %d + %d", c, d, q1, temp);

}

void ex2(int a3, int b3) {
	int r3 = a3;
	int q3 = 0;
	int n3 = 0;
	int aux = b3;
	while (aux < a3) {
		aux = aux * 2;
		n3 = n3 + 1;
	}
	while (n3>0) {
		aux = aux / 2;
		n3 = n3 - 1;
		if (r3 < aux) {
			q3 = q3 * 2;
		}
		else {
			q3 = (q3 * 2) + 1;
			r3 = r3 - aux;
		}
	}
	printf("%d = %d * %d + %d", a3, b3, q3, r3);

}

void gmpEx1(mpz_t  Gc, mpz_t  Gd) {
	mpz_t Gq1 = 0;
	mpz_t Gtemp = Gc;
	while (Gtemp >= Gd) {
		mpz_sub(Gtemp, Gtemp, Gd);
		mpz_add(Gq1, Gq1, 1);
	}
	gmp_printf("%Zd = %Zd * %Zd + %Zd");

}




void gmpEx2(mpz_t Ga3, mpz_t Gb3) {
	mpz_t Gr3, Gq3, Gn3, Gaux;
	mpz_inits(Gr3, Gq3, Gn3, Gaux, NULL);

	mpz_set(Gr3, Ga3);
	mpz_set(Gaux, Gb3);
	mpz_set_ui(Gq3, 0);
	mpz_set_ui(Gn3, 0);

	while (mpz_cmp(Gaux, Ga3) < 0) {
		mpz_mul_ui(Gaux, Gaux, 2);
		mpz_add_ui(Gn3, Gn3, 1);
	}

	while (mpz_cmp_ui(Gn3, 0) > 0) {
		mpz_tdiv_q_2exp(Gaux, Gaux, 1); 
		mpz_sub_ui(Gn3, Gn3, 1);

		if (mpz_cmp(Gr3, Gaux) < 0) {
			mpz_mul_ui(Gq3, Gq3, 2);
		}
		else {
			mpz_mul_ui(Gq3, Gq3, 2);
			mpz_add_ui(Gq3, Gq3, 1);
			mpz_sub(Gr3, Gr3, Gaux);
		}
	}

	gmp_printf("%Zd = %Zd * %Zd + %Zd\n", Ga3, Gb3, Gq3, Gr3);

	mpz_clears(Gr3, Gq3, Gn3, Gaux, NULL);
}


void pgcd1(int a1, int b1) {
	int temp1;
	while (1) {
		temp1 = a1 % b1;
		if (temp1 == 0) { break; }
		a1 = b1;
		b1 = temp1;

	}

	printf("PGCD is:%d", b1);

}

void pgcd2(int a2, int b2) {
	int c2 = 0;
	int i = 0;
	while (1) {
		if (b2 == c2 && a2 == (2 * b2)) { break; }

		c2 = a2 - b2;
		if (b2 > c2) {
			a2 = b2;
			b2 = c2;

		}
		else if (b2 < c2) {
			a2 = c2;
			b2 = b2;
		}
	}
	printf("PGCD is:%d\n", c2);


}

void pgcd38(int a, int b) {
	int gcd = 1;
	int i;

	
	for (i = 2; i <= a && i <= b; i++) {
		
		while (a % i == 0 && b % i == 0) {
			gcd *= i;      
			a /= i;        
			b /= i;        
		}
	}

	printf("PGCD = %d\n", gcd);
}



int main() {
	pgcd38(490, 84);
}