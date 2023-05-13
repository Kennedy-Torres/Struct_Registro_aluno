#include <stdio.h>
#define TAM 20
int main(){

    int i,j,nm_aluno=0;
    float soma=0,maior_media=0;
    

    do{
        printf("Informe o numero de cadastros que serao realizados:");
        scanf("%d",&nm_aluno);
    }while(nm_aluno<0 || nm_aluno>20); 

    struct Disciplina{
        
        char nome_disc[100];
        int carg_h;
        float notas[4];
    };

    struct Aluno{
        char nome[25]; 
        int matricula,idade;
        float media;
        struct Disciplina disciplina;
    }; 

    struct Aluno aluno[TAM];

    for(i=0;i<nm_aluno;i++){
        printf("+------------------------------+\n");
        printf("|   REGISTRO DO %do ALUNO(A):  |\n",i+1);
        printf("+------------------------------+\n");
        printf("Nome do aluno(a):\n");
        scanf(" %[^\n]s",&aluno[i].nome);
        printf("Matricula:\n");
        scanf("%d",&aluno[i].matricula);
        printf("A sua Idade:\n");
        scanf("%d",&aluno[i].idade);

        soma = 0; // a soma eh zerada para nao interferir na soma das notas dos outros alunos
        for(j=0;j<4;j++){ // cada aluno tem 4 notas
            printf("\nNome da %da disciplina cursada:\n",j+1);
            scanf(" %[^\n]s",&aluno[i].disciplina.nome_disc);
            printf("Carga horaria:\n");
            scanf("%d",&aluno[i].disciplina.carg_h);
            printf("Nota de %s:\n",aluno[i].disciplina.nome_disc);
            scanf("%f", &aluno[i].disciplina.notas[j]);
            soma += aluno[i].disciplina.notas[j]; 
            if(j==3){
                aluno[i].media = soma/4; // definindo a media de cada aluno
                if(aluno[i].media>maior_media){
                    maior_media = aluno[i].media; // definindo a maior media entre os alunos
                }
            }
        }  

    }

printf("\n+--------------------------------------------------+\n");
printf("|                  QUADRO DE ALUNOS                |\n");
printf("+--------------------------------------------------+\n");

    for(i=0;i<nm_aluno;i++){
        printf("NOME: ");
        printf("%s\t",aluno[i].nome);
        printf("IDADE: ");
        printf("%d\t",aluno[i].idade);
        printf("MEDIA: ");
        printf("%.2f\n",aluno[i].media);
    }



   
    printf("+--------------------------------------------------+\n");
    printf("|    Aluno(s) com a(s) maior(es) media(s)          |\n");
    printf("+--------------------------------------------------+\n");
    
    for(i=0;i<nm_aluno;i++){
        if(aluno[i].media == maior_media){
            printf("| NOME: ");
            printf("%s\t",aluno[i].nome);
            printf("MEDIA: ");
            printf("%.2f\n",maior_media);
        }
    }
    printf("+--------------------------------------------------+\n");

    return 0;
}

