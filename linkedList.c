#include<stdlib.h>
#include<stdio.h>

typedef struct linkedL{
    int value;
    struct linkedL *next;

}nodetype;

nodetype* add(nodetype* head){ //add to last
    nodetype* temp = (nodetype*)malloc(sizeof(struct linkedL));
    printf("Enter an integer: ");
    scanf("%d", &temp -> value);
    temp -> next = NULL;
    if(head == NULL){
        head = temp;
    }else{
        nodetype* aux = head;

        while(aux -> next != NULL){
            aux = aux -> next;
        }
        aux -> next = temp;
    }
    return head;
}

nodetype* push(nodetype* head){ //add to first
    nodetype * temp = (nodetype*)malloc(sizeof(struct linkedL));
    printf("Enter an integer: ");
    scanf("%d", &temp -> value);
    temp -> next = NULL;
    if(head == NULL){
        head = temp;
    }else{
        temp -> next = head;
        head = temp;
    }

    return head;
}

nodetype* pop(nodetype* head){ //remove from last
    nodetype * temp = (nodetype*)malloc(sizeof(struct linkedL));
    temp -> next = NULL;
    if(head == NULL){
        printf("STRUCTURE IS EMPTY");
        getch();
    }else{
        temp = head;
        while(temp -> next->next != NULL){
            temp = temp -> next;
        }

        nodetype * aux = temp->next;
        free(aux);
        temp->next = NULL;
    }
    return head;
}

nodetype* removeF(nodetype* head){ //remove from first
    nodetype * temp = (nodetype*)malloc(sizeof(struct linkedL));
    if(head == NULL){
        printf("STRUCTURE IS EMPTY");
        getch();
    }else{
        temp = head->next;
        head -> next = NULL;
        free(head);
        head = temp;
    }
    return head;
}


void displayAll(nodetype * head){

    nodetype * aux;
    if(head == NULL){
        printf("STRUCTURE IS EMPTY");
    }else{
        aux = head;
        while(aux != NULL){
            printf("%d --> ", aux -> value);
            aux = aux -> next;
        }
    }

}


int main(){

    int op = 0;
    int num;
    nodetype* stack = (nodetype*)malloc(sizeof(struct linkedL));
    stack = NULL;
    nodetype* queue = (nodetype*)malloc(sizeof(struct linkedL));
    queue = NULL;
    nodetype* dequeue = (nodetype*)malloc(sizeof(struct linkedL));
    dequeue = NULL;

    //MENU

    while(op == 0){
        system("cls");
        printf("MENU\n"
               "====\n"
               "[1] STACK\n"
               "[2] QUEUE\n"
               "[3] DEQUEUE\n"
               "[0] EXIT\n"
               "PLEASE, CHOOSE A DATA STRUCTURE\n");
               scanf("%d", &op);
        switch(op){
            case 1:
                while(op > 0){
                    system("cls");
                    printf("STACK\n"
                           "=====\n"
                           "[1] ADD ELEMENT\n"
                           "[2] REMOVE ELEMENT\n"
                           "[3] DISPLAY STACK\n"
                           "[0] RETURN\n"
                           "PLEASE, CHOOSE AN OPTION:\n");
                           scanf("%d", &op);
                    switch(op){
                        case 1:
                            stack = push(stack);
                            break;
                        case 2:
                            stack = removeF(stack);
                            break;
                        case 3:
                            displayAll(stack);
                            getch();
                            break;
                        case 0:
                            break;
                        default:
                            op = 4;
                    }
                }
                break;
            case 2:
                while(op > 0){
                    system("cls");
                    printf("QUEUE\n"
                           "=====\n"
                           "[1] ADD ELEMENT\n"
                           "[2] REMOVE ELEMENT\n"
                           "[3] DISPLAY QUEUE\n"
                           "[0] RETURN\n"
                           "PLEASE, CHOOSE AN OPTION:\n");
                           scanf("%d, &op");
                    switch(op){
                            case 1:
                                queue = push(queue);
                                break;
                            case 2:
                                queue = pop(queue);
                                break;
                            case 3:
                                displayAll(queue);
                                getch();
                                break;
                            case 0:
                                break;
                            default:
                                op = 4;
                    }
                }
                break;
            case 3:
                while(op > 0){
                    system("cls");
                    printf("DEQUEUE\n"
                           "=======\n"
                           "[1] ADD FIRST ELEMENT\n"
                           "[2] ADD LAST ELEMENT\n"
                           "[3] REMOVE FIRST ELEMENT\n"
                           "[4] REMOVE LAST ELEMENT\n"
                           "[5] DISPLAY STACK\n"
                           "[0] RETURN\n"
                           "PLEASE, CHOOSE AN OPTION:\n");
                           scanf("%d", &op);
                    switch(op){
                            case 1:
                                dequeue = push(dequeue);
                                break;
                            case 2:
                                dequeue = add(dequeue);
                                break;
                            case 3:
                                dequeue = removeF(dequeue);
                                break;
                            case 4:
                                dequeue = pop(dequeue);
                                break;
                            case 5:
                                displayAll(dequeue);
                                getch();
                                break;
                            case 0:
                                break;
                            default:
                                op = 6;
                    }
                }
                break;
            case 0:
                exit(0);
                break;
            default:
                op = 4;

        }
    }
}
