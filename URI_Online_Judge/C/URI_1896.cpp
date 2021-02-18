// Trabalho 2
// Disciplina de Analise de Algoritmo - EACH 2/2020
// Aluna: Bruna Ferreira dos Santos

#include <iostream>

using namespace std;
#include <bits/stdc++.h>

typedef long long ll;

// Estrutura para armazenar as informações de cada carta
struct carta
{
	int a, d, h;

	carta(){a = d = h = 0;}
	carta(int i, int j, int k) : a(i), d(j), h(k){}

	bool operator == (const carta &other) const
	{
		return a == other.a && d == other.d && h == other.h;
	}
};

//Baralho - Deck
carta deck[25];

int main()
{
    // n = número de cartas na mesa
    // Atributos para que a carta Prassodia seja invocada
    // a = ataque
    // d = defesa
    // h = habilidade para invocar Prassódia
	int n, a, d, h;
	carta prassodia;

    //Leitura dos atributos das n cartas disponíveis
	while (cin >> n)
	{
		cin >> a >> d >> h;
		prassodia = carta(a, d, h);

		for (int i = 0 ; i < n ; ++i)
		{
			cin >> a >> d >> h;
			// Salva cada carta em um deck
			deck[i] = carta(a, d, h);
		}


		ll lim = (1L << n);
		// Variavel para identificar se pode ou não invocar prassodia
		int poder_prassodia = 0;

		//Realiza as combinações possiveis de todas as cartas
		for (ll i = 3; i < lim; ++i)
		{
			if (!(i & (i - 1))) continue;
			a = d = h = 0;
			for (int j = 0 ; j < n ; ++j)
			{
				if (i & (1L << j))
				{
				    // Soma todos os valores de ataque
					a += deck[j].a;
					// Soma todos os valores de defesa
					d += deck[j].d;
					// Soma todos os valores de habilidade
					h += deck[j].h;
				}
			}

            //Verifica se as configurações
			carta aux = carta(a, d, h);
			if (aux == prassodia)
			{
			    // É possivel invocar prassodia
				poder_prassodia = 1;
				break;
			}
		}
		if (poder_prassodia) cout << "Y\n";
		else cout << "N\n";
	}
}
