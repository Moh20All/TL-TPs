#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ALLALI MOHAMED BAHA EDDINE
//----------------------------------------- Global var -----------------------------//
    char temp[5];
    int col,row;
    int transition[100][26];
//----------------------------------------- clear an array -----------------------------//
void vide(){
    int i=0;
    while(i<5){
    temp[i]='\0';
    i++;
    }
}
// --------------------------------------- videz la matrice -----------------------
void clear_matrice(int arr[row][col]){
   for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 26; j++) {
         arr[i][j] = -1;
      }
   }
   }
// ---------------------------------------- creation of the transition table ---------
void creation(int nb_tr,int nb_st,int nb_vt,char vts[]){

    int i=0,j=0;
    char temp[10];
    fgets(temp,10,stdin);
    while(i<nb_tr){
    fgets(temp,10,stdin);
    if(temp[0] >= '0' && temp[0] <= '9'){
        transition[(temp[0] - '0')][(temp[2]-'a')]=(temp[4]-'0');
        }
        i++;
    }
}
// ---------------------------------- Check the word automata ---------------------
int check_automata(char mot[]){
    if(mot[0]=='\0')
        return 911;
    else{
        int i=0,last_st=0;
        printf("0--");
        while(mot[i]!='\n'){
            printf("%c->",mot[i]);
            if(last_st == -1){
                return 911;
            }else{
                printf("%d--",transition[last_st][(mot[i]-'a')]);
                last_st=transition[last_st][(mot[i]-'a')];
                i++;
            }
        }
    return last_st;
    }
}
// ---------------------------------------- Display -----------------------------------
void display(char vts[],int sw){
    for(int i=0;i<100;i++){
        for(int j=0;j<26;j++){
            if(transition[i][j]==-1)
                printf("x\t");
            else
                printf("%d\t",transition[i][j]);
        }
        printf("\n");
    }
}
//-----------------------------------------main function --------------------------
int main()
{

    int nb_st=0,nb_vt=0,nb_ter=0,nb_tran=0;
    char a[3];
 //     number_states , number_vt ,number_terminal , number_transition;
    printf("Number of states :\n");//
    fgets(temp,5,stdin);
    nb_st=atoi(temp);
    printf("Number of Vt symbols :\n");//
    fgets(temp,5,stdin);
    nb_vt=atoi(temp);
    char vt_sy[nb_vt];
    int i=0;
    while(i<nb_vt){
        fgets(a,3,stdin);
        if(a[0]>='a'&&a[0]<='z'){
        vt_sy[i]=a[0];
        i++;
        }
    }
    printf("Number of terminal states :\n");//
    fgets(temp,5,stdin);
    nb_ter=atoi(temp);
    int vt_st[nb_ter];
    // read states
    printf("Terminal states (space between):\n");
    fgets(temp,5,stdin);
    i=0;
    int j=0;
    while(temp[i]!='\0' && j<nb_ter){
    if (temp[i] >= '0' && temp[i] <= '9') {
            vt_st[j] =(temp[i] - '0');
            j++;

        }
    i++;
    }
    // Read transition
    printf("Number of transition :\n");//
    temp[0]=getchar();
    nb_tran=atoi(temp);
    row=nb_st;
    col=nb_vt;
    clear_matrice(transition);

    creation(nb_tran,nb_st,nb_vt,vt_st);
do{
    printf("\n\n----------------- Enter word -----------------\n");
    fgets(temp,5,stdin);
    display(vt_st,nb_vt);
    printf("\nChecking ................\n");
    int result = check_automata(temp);
    int flag= 999;
    for(int i=0;i<nb_ter;i++){
        if(result==vt_st[i])
            flag=1;
        i++;
    }
    if(flag==999)
        printf("\nNO");
    else
        printf("\nYES");
}while(temp[0]!= 'x');
    return 0;
}




/*

int automata(char word[],char q)
{
    int i=0;
    printf("%c",q);
    if(word[i]=='\0')//no word
    {
        printf("--\nno");return 0;
    }
    while(word[i]!='\0')//end mot
    {
        printf("--%c-->",word[i]);
        q=am[q-'0'][word[i]-'a'];
        if(q=='N')
        {
            printf("\nNO");return 0;
        }
        printf("%c",q);
        i++;
    }
    char c='N';
    i=0;
    while(stop[i]!='\0')
    {
        if(q==stop[i])
        {
            c='Y';
            break;
        }
        i++;
    }
    printf(c=='Y' ? "\nYES":"\nNO");return 0;
}
/*
int main()
{
    char t[20];
    create_automata();
    display();
    printf("donne le mot de verife par automate : \n");
    gets(t);
    automata(t,'0');
    return 0;


}
*/
