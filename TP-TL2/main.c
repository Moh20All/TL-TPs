#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
// Structure de noeud
typedef struct graph{
    int node;
    struct GP* next;
}GP;

//Structure de vecteur
typedef struct vector{
    int tete;
    struct GP*link;
    struct VC* next;
}VC;

// Structure de connexite
typedef struct {
    int T;
    bool cond;
}test;

//Global variables
    VC* Tete=NULL;// Vecteur
    GP* Node=NULL;// Noeud
    GP* append(int n);

void creation(int n){
    int i = 0, j = 0, nd = 0;
    int ch;
    VC *HEAD = NULL;
    VC *TEMP = NULL;
    VC *P = NULL;
    for (i=0;i<n;i++ ){

        TEMP=(VC*)malloc(sizeof(VC));
        printf("\nEnter The name of node : ");
        scanf("%d",&(TEMP->tete));
        // Node info
        TEMP->next=NULL;
        TEMP->link=NULL;
        printf("\nEnter number neighbors: ",i);
        scanf("%d",&nd);
        if (HEAD==NULL)
        {
            HEAD = TEMP;
        }else
        {
            P = HEAD;
            while (P->next != NULL)
            {
                P = P->next;
            } // Loop
            P->next = TEMP;
        }

        TEMP->link=append(nd);
    }

Tete=HEAD;
}

GP* append(int n){
    int i = 0, j = 0, nd = 0;
    char ch;
    GP *HEAD = NULL;
    GP *TEMP = NULL;
    GP *P = NULL;
    j = 0;
    while (j < n)
    {
        TEMP = (GP *)malloc(sizeof(GP));
        printf("\nEnter neighbor  %d : ", j + 1);
        scanf("%d",&nd);
        TEMP->node=nd;

        TEMP->next = NULL;

        if (HEAD == NULL)
        {
            HEAD = TEMP;
        }//if
        else
        {

            P = HEAD;
            while (P->next != NULL)
            {
                P = P->next;
            } // Loop
            P->next = TEMP;

        } // else
        j++;
    }
    return HEAD;
}
VC* append1(VC* tete){
    int s;
    VC* TEMP=NULL;
    VC* P=NULL;

        TEMP=(VC*)malloc(sizeof(VC));
        printf("\nEnter The name of node : ");
        scanf("%d",&(TEMP->tete));
        // Node info
        TEMP->next=NULL;
        TEMP->link=NULL;
    while(P!=NULL){
        P=P->link;
    }
    printf("Enter number of neighbors:");
    scanf("%d",&s);
    P->link=append(s);
}
// Display
void display(VC *HEAD)
{
    int cot=0;
    VC *P = HEAD;
    GP *T = NULL;

    while (P != NULL)
    {
        T=P->link;
        printf("%d->", P->tete);
        cot=0;
        while(T!=NULL){
            cot++;
            printf("%d , ", T->node);
            T=T->next;
        }
        printf("\n");
        P = P->next;
    }
}
// Connexity de graph
void connex(test Tab[],int nd){
    VC *P = Tete;
    GP *T = NULL;
    int j=0;
    for (int i=0;i<nd;i++){
        Tab[i].T=P->tete;
        P=P->next;
        Tab[i].cond=false;
    }
    Tab[0].cond=true;
    P=Tete;
    for (int i=0;i<nd;i++){
            T=P->link;
        while(T!=NULL){
                j=0;
            while(j<nd){
                  if (T->node==Tab[j].T)
                    Tab[j].cond=true;
                j++;
            }
            T=T->next;
        }
        P=P->next;
    }
j=0;
while(j<nd){
    if(Tab[j].cond==false){
            printf("\n---------- Ne pas connexe.----------\n");
        break;
    }
    j++;
}
if (j==nd)
    printf("\n---------- Le graph est connexe .----------\n");
}
// calcul le degree
void degree(test Tab[],int nd){
    VC *P = Tete;
    GP *T = NULL;
    int i=0,j=0,cot=0;
    while(i<nd){
        cot=0;
        P = Tete;
while(P!=NULL){
            T=P->link;
            while((T!=NULL)&&(Tab[i].T!=P->tete)){
                if (Tab[i].T==T->node){
                    cot++;
                }
            T=T->next;
            }
    if(Tab[i].T==P->tete)
        cot=cot+show(P->link);

    P=P->next;
}
printf("\n----- Le degree de 1 est : %d\n",cot);
    i++;
    }
}
int show(GP* HEAD){
    GP* P=HEAD;
    int cc=0;
    while(P!=NULL){
        cc++;
        P=P->next;
    }
    return cc;
}
// Le plus court chemin

int main()
{

    int n=0,sw=0;
    printf("Enter The number of Nodes : ");
    scanf("%d",&n);
    creation(n);
    display(Tete);
    test tab[n];
    connex(tab,n);
    degree(tab,n);
    while(sw!=5){
    printf("\n\n------1.Add a node.\n");
    printf("------2.Tester la connexity.\n");
    printf("------3.Calculer la degree.\n");
    printf("------4.Display nodes.\n");
    printf("------5.Exit.\n");
    scanf("%d",&sw);
    switch (sw)
    {
            case 1:
        Tete=append1(Tete);
        break;
            case 2:
        connex(tab,n);
        break;
            case 3:
        degree(tab,n);
        break;
            case 4:
        display(Tete);
        break;
            case 5:
        return 0;
        break;

    default:
        break;
    }
    }


    return 0;
}
