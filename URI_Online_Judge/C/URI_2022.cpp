// Trabalho 2
// Disciplina de Analise de Algoritmo - EACH 2/2020
// Aluna: Bruna Ferreira dos Santos

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;


int main() {
	string str,s;
	//Q = Quantidade de Presentes
	int Q;
	while(cin>>str)
	{
	    // ***** Entradas - Leitura *****
	    // Le nome da criança e quantidade de presentes
		scanf("%d",&Q);
		getline(cin,s);
		// E = escala de preferencia do objeto
		int E;
		// P = preco do objeto desejado
		double P;
		// O = nome do  objeto desejado
		string O;
		vector< pair<string,double> > crianca[11];

		// Inicializa contador da escala de preferencia como 0
		int max_pref=0;

		//Le as informações dos presentes de cada criança
		for(int i=0;i<Q;i++)
		{
		    // Le o nome do objeto
			getline(cin,O);

			// Le o preco do objeto e a escala de preferencia
			cin>>P>>E;

			// Cria lista de objetos para cada escala de prioridade
			crianca[E].push_back(make_pair(O,P));

            // Armazenada o valor da prioridade mais alta lida até o momento
			if(E>max_pref)max_pref=E;
			getline(cin,s);
		}

		// ***** Ordenação da lista *****
		printf("Lista de %s\n",str.c_str());


		// Percorre escala de preferência, da maior até a menor prioridade
		for(int i=max_pref;i>0;i--)
		{
		    // Verifica se a lista de presentes não está vazia
			if(!crianca[i].empty())
			{
			    // Percorre a lista de presentes
				for(int j=0;j<crianca[i].size()-1;j++)
				{
				    // Percorre a lista de presentes comparando com o proximo
					for(int k=0;k<crianca[i].size()-1;k++)
					{
					    // Se o preco do primeiro presente é maior que o do segundo
						if(crianca[i][k].second>crianca[i][k+1].second)
						{
						    // Faz uma troca
							swap(crianca[i][k+1],crianca[i][k]);
						}
						// Caso contrario se o  preco do primeiro presente é igual ao do segundo
						// E o nome da primeira criança antecede o da segunda
						else if(crianca[i][k+1].second==crianca[i][k].second&&crianca[i][k].first>crianca[i][k+1].first)
						{
						    // Faz troca
							swap(crianca[i][k+1],crianca[i][k]);
						}
					}
				}
        // ***** Mostra a lista de presentes ordenada *****
				for(int j=0;j<crianca[i].size();j++)
				{
				    // Mostra cada item da lista
					cout<<crianca[i][j].first<<" - R$";
					printf("%.2lf\n",crianca[i][j].second);
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
