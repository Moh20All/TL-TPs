#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_LISTS 5

typedef struct node {
    char word[20];
    struct node *next;
} Node;

void append(Node *list, char *word) {
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->word,word);
    new_node->next = NULL;

    Node *curr = list;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

void display(Node *list) {
    Node *curr = list->next;
    while (curr != NULL) {
        printf("%s->", curr->word);
        curr = curr->next;
    }
    printf("|\n|\n|");
}

void empt(char *tag){
            for (int j=0;j<=256;j++){
            tag[j]='\0';
        }
        return tag;
}
Node *lists[NUM_LISTS];

void read_file(char filename[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[256],word[20];
    int len = 256;
    int read,length;
    int i=0;
    while ((line[i] = fgetc(fp))!=EOF ) {
if(line[i]==' '){

            if (length > 5 ) {
                append(lists[4], line);
            } else if(length>1){
            append(lists[length-2],line);
            }
     empt(line);
     i=0;
     length=0;
}else{
length++;
i++;
}

        }



}

int main() {

    char nom[10]="File.txt";
    for (int i = 0; i < NUM_LISTS; i++) {
        lists[i] = malloc(sizeof(Node));
        lists[i]->next = NULL;
    }

    read_file(nom);





for (int i=0;i<5;i++){
    printf("\n|-----------------------------Words of length %d:-----------------------------|\n",i+2);
    display(lists[i]);
}


    return 0;
}
