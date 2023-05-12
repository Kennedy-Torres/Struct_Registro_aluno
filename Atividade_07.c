#include <stdio.h>

int main(){

    int i,j,x,nm_aluno=0;
    float soma_nota_aluno[20]={},media_aluno[20],maior_media;
    int aluno_destaque;
    

    do{
        printf("Informe o numero de cadastros que serao realizados:");
        scanf("%d",&nm_aluno);
    }while(nm_aluno<0 || nm_aluno>20); //cadastro de até 20 estudantes

    struct Disciplina{
        char nome_disc[100];
        int carg_h;
        float notas[4];
    };

    struct Aluno{
        char nome[25]; 
        int matricula,idade;
        struct Disciplina disciplina;
    }; 

    struct Aluno aluno[nm_aluno];

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

        for(j=0;j<4;j++){ // cada aluno tem 4 notas
            printf("\nNome da %da disciplina cursada:\n",j+1);
            scanf(" %[^\n]s",&aluno[i].disciplina.nome_disc);
            printf("Carga horaria:\n");
            scanf("%d",&aluno[i].disciplina.carg_h);
            printf("Nota de %s:\n",aluno[i].disciplina.nome_disc);
            scanf("%f",&aluno[i].disciplina.notas[j]);
            soma_nota_aluno[i] = (soma_nota_aluno[i] + aluno[i].disciplina.notas[j]); 
        }  

        media_aluno[i] = (soma_nota_aluno[i]/4);
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
        printf("%.2f\n",media_aluno[i]);
    }


    maior_media = -11111; // qualquer valor da variavel media_aluno serah maior
    for(i=0;i<nm_aluno;i++){ 
        if(media_aluno[i]>maior_media){
            maior_media = media_aluno[i]; 
            aluno_destaque = i; // informa qual foi o aluno
        }
    }
   
    printf("+--------------------------------------------------+\n");
    printf("| Aluno com a maior media\n");
    printf("| NOME: ");
    printf("%s\t",aluno[aluno_destaque].nome);
    printf("MEDIA: ");
    printf("%.f\n",maior_media);
    printf("+--------------------------------------------------+\n");

    return 0;
}