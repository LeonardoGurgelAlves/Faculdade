#include <stdio.h>
#include <math.h>

int main() {
    // Declara��o de variaveis
    float n1, n2, nt = 0;
    float notas[3] = {0, 0, 0}; // �ndices para: 0 = AP1, 1 = AP2 e 2 = recupera��o
    int tentativas = 1; // Contador das tentativas
    float somanotas = 0, media, desviopadrao = 0, somadesvios = 0;
    float historico[100]; // Para guardar todas as notas
    int notast = 0;

    // Input da AP1 e AP2
    printf("Informe a primeira nota do aluno (AP1): ");
    scanf("%f", &n1);
    printf("Informe a segunda nota do aluno (AP2): ");
    scanf("%f", &n2);

    // Armazenando os dados nas vari�veis e no hist�rico
    notas[0] = n1;
    notas[1] = n2;
    historico[notast++] = n1;
    historico[notast++] = n2;

    // Calculo da m�dia inicial (AP1 e AP2)
    media = (notas[0] + notas[1]) / 2;

    // Loop para as infinitas tentativas at� alcan�ar a m�dia
    while (media < 6){
        printf("\nVoce nao atingiu a media, tente novamente!.");
        printf("\nEssa � sua %d� tentativa: ", tentativas);
        scanf("%f", &nt);

        // Substitui��o da menor nota
        if (notas[0] >= notas[1]){
            if (nt > notas[1]){
                notas[1] = nt; // Substitui a menor nota
            }else{
                printf("\nNota inserida %.2f nao e maior que sua menor nota %.2f", nt, notas[1]);
            }
        }else{
            if (nt > notas[0]){
                notas[0] = nt; // Substitui a menor nota
            }else{
                printf("\nNota inserida %.2f nao e maior que sua menor nota %.2f", nt, notas[0]);
            }
        }

        // Atualiza��o do hist�rico de notas
        historico[notast++] = nt;

        // Contabilizando as tentativas e recalculando a media
        tentativas++;
        printf("\nNotas: %.2f, %.2f", notas[0], notas[1]);
        media = (notas[0] + notas[1]) / 2;
        printf("\nSua media atual e de: %.2f", media);
    }

    // Calcuo da media de todas as notas
    for (int i = 0; i < notast; i++){
        somanotas += historico[i];
    }
    float mediat = somanotas / notast;

    // Fazendo a ordem do hist�rico de notas para poder calcular a mediana
    for (int i = 0; i < notast - 1; i++){
        for (int j = i + 1; j < notast; j++){
            if (historico[i] > historico[j]){
                float temp = historico[i];
                historico[i] = historico[j];
                historico[j] = temp;
            }
        }
}

    // Calculo da mediana
    float mediana;
    if (notast % 2 == 0){
        mediana = (historico[notast / 2 - 1] + historico[notast / 2]) / 2;
    }else{
        mediana = historico[notast / 2];
    }

    // Calculo do desvio padr�o
    for (int i = 0; i < notast; i++){
        somadesvios += pow(historico[i] - mediat, 2);
    }
    desviopadrao = sqrt(somadesvios / notast);

    // Mostrando o resultado final do c�digo
    printf("\tResultado Final:\n");
    printf("Nota AP1: %.2f\n", notas[0]);
    printf("Nota AP2: %.2f\n", notas[1]);
    printf("Media Final: %.2f\n", media);
    printf("Voce fez %d tentativas.\n", tentativas);

    // mostrando o resultado da media total das notas, mediana e o desvio padr�o.
    printf("\nEstatisticas complementares:\n");
    printf("Media de todas as notas: %.2f\n", mediat);
    printf("Mediana de todas as notas: %.2f\n", mediana);
    printf("Desvio padrao das notas: %.2f\n", desviopadrao);

    return 0;
}
