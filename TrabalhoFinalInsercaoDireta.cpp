#include <iostream>
#include <ctime>
using namespace std;

void ordenacaoInsercaoDireta(int *vetorOrdenadoDireta, int tamanhoVetor){

    int aux2, numeroAtual;
    int comparacoesInsercaoDireta = 0, movimentacoesInsercaoDireta = 0;

    for(int aux1 = 2; aux1 <= tamanhoVetor; aux1 ++){
        numeroAtual = vetorOrdenadoDireta[aux1];
        vetorOrdenadoDireta[0] = numeroAtual;
        aux2 = aux1;
        movimentacoesInsercaoDireta += 2;

        while(numeroAtual < vetorOrdenadoDireta[aux2 - 1]){
            vetorOrdenadoDireta[aux2] = vetorOrdenadoDireta[aux2-1];
            aux2 = aux2 - 1;
            comparacoesInsercaoDireta++;
            movimentacoesInsercaoDireta++;
        }
        comparacoesInsercaoDireta++;
        vetorOrdenadoDireta[aux2] = numeroAtual;
        movimentacoesInsercaoDireta++;
    }

}


int main(){

    int tamanhoVetor;
    clock_t tempo1, tempo2;
    double tempo_total;

    cout << "Qual sera o tamanho n do vetor? ";
    cin >> tamanhoVetor;
    cin.ignore();
    int vetorOrdenadoDireta[tamanhoVetor + 1];

    /*
    //Atribuicao de valores aleatorio - pares e impares tem padroes distintos
    for(int i = 1; i <= tamanhoVetor; i++){
        if(i%2){
            vetorOrdenadoDireta[i] = 3*i;
        }
        else{
            vetorOrdenadoDireta[i] = ((5*i)/2 + 3);
        }
    }

    cout << endl << "\nDefina cada posicao do vetor, partindo de 1 ate n: \n";
    for(int aux = 1; aux <= tamanhoVetor; aux++){
        cout << "\tVetor " << aux << ": ";
            cin >> vetorOrdenadoDireta[aux];
            cin.ignore();
        cout << endl;
    }

    //Atribuicao de valores decrescentes
    int j = tamanhoVetor;
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorOrdenadoDireta[i] = j;
        j--;
    }

    /*
    //Atribuicao de valores crescentes
    for(int i = 1; i <= tamanhoVetor; i++){
        vetorOrdenadoDireta[i] = i;
    }*/

    //Estrutura que fara o calculo de tempo
    cout << endl << endl;
    tempo1 = clock();
    ordenacaoInsercaoDireta(vetorOrdenadoDireta, tamanhoVetor);
    tempo2=clock();
    tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
    cout << "\nTempo total: " << tempo_total;

    cout << "Ordenacao por insercao direta: ";
    //Estrutura que printa vetor ordenado - usado para conferir a organizacaoo dos vetores dados
    /*for(int aux3 = 1; aux3 <= tamanhoVetor; aux3++){
        cout << vetorOrdenadoDireta[aux3] << " ";
    }*/

    //Estrutura que printa o numero de movimentacoes e comparacoes
    cout << endl << "Movimentacoes: "<< movimentacoesInsercaoDireta << " e comparacoes: " << comparacoesInsercaoDireta;



}

