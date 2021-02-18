// Trabalho 2
// Disciplina de Analise de Algoritmo - EACH 2/2020
// Aluna: Bruna Ferreira dos Santos

#include <bits/stdc++.h>
using namespace std;

#define MAX 5010
int main()
{

	char S[MAX];
    // A =
    // B =
	int A, B;
	scanf("%d %d\n", &A, &B);
	int N, meio; N = meio = 0;

	// Leitura da string contendo ordem das pedras
	// S = vetor de cores, sendo B = Black, preta
	// W = White , branca
	while (scanf("%c\n", &S[N]) != EOF)
		if (S[N++] == 'B') meio++;

    // número de moedas
	int custo = 0;

	// percorre lista de pedras
	for (int p = meio; p < N; ++p) {
		int j = p - 1;
		bool valor = false;
		if (S[p] == 'B') {
			while (j >= 0 && (p - j) * (A - B) <= A)
				if (j < meio && S[j] == 'W') {
					valor = true;
					custo += (p - j) * (A - B);
					S[j] = 'B';
					break;
				} else
					j--;

			if (!valor) custo += A;
			S[p] = 'W';
		}
	}
	printf("%d\n", custo);
}
