#include<stdio.h>
typedef struct Node{
    char id[11];
    int price;
    struct Node *leftChild;
    struct Node *rightChild;
    struct Node *sub;
}Node;

Node *root[100000];

Node *makeNode(char *id, int price){
    Node * p = (Node*)malloc(sizeof(Node));
    strcpy(p->id, id);
    p->price = price;
    p->leftChild = NULL;
    p->rightChild = NULL;
    p->sub = NULL;
    return p;
}

Node *searchBST(char *id, Node *r){
    if(r == NULL) return NULL;
    int c = strcmp(r->id, id);
    if(c == 0) return r;
    else if (c < 0) return searchBST(id, r->rightChild);
    else return searchBST(id,r->leftChild);
}

Node *insertBST(char *id, int price, Node *r){
    if(r == NULL) return makeNode(id, price);
    int c = strcmp(r->id, id);
    if(c == 0){
        r->price += price;
        return r;
    }
    else if(c < 0){
        r->rightChild = insertBST(id, price, r->rightChild);
        return r;
    }
    else{
        r->leftChild = insertBST(id, price, r->leftChild);
        return r;
    }
}

int hashFunction(char *id){
    int code = 0;
    for(int i = 0; i < strlen(id); i++){
        code = (code * 256 + id[i]) % 100000;
    }
    return code;
}

void insertNode(char *id, int price){
    int index = hashFunction(id);
    root[index] = insertBST(id, price, root[index]);
}

Node *searchNode(char *id){
    int index = hashFunction(id);
    return searchBST(id, root[index]);
}

int timeFunction(char *time){
    int hour = (time[0]-'0')*10+(time[1]-'0');
    int min = (time[3]-'0')*10 + (time[4]-'0');
    int second = (time[6]-'0')*10 + (time[7]-'0');
    return hour * 3600 + min * 60 +second;
}

int main(){
    int n = 0; int total = 0;
    char customerID[11];
    char productID[11];
    char shopID[11];
    int price;
    char timepoint[9];
    char cmd[50];
    int a[86401], t[86401];
    for(int  i = 0; i < 86401; i++){
        a[i] = 0;
        t[i] = 0;
    }
    while(1){
        scanf("%s",customerID);
        if(strcmp(customerID,"#")==0){
            break;
        }
        else{
            scanf("%s%d%s%s",productID,&price,shopID,timepoint);
            insertNode(shopID,price);
            Node *tmp = searchNode(shopID);
            tmp->sub = insertBST(customerID, price, tmp->sub);
            n += 1;
            total += price;
            a[timeFunction(timepoint)] += price;
        }
    }
    for(int i = 1; i < 86401; i++){
        t[i] = t[i-1] + a[i];
    }

    while(1){
        scanf("%s",cmd);
        if(strcmp(cmd,"?total_number_orders")==0){
            printf("%d\n",n);
        }
        if(strcmp(cmd,"?total_revenue")==0){
            printf("%d\n",total);
        }
        if(strcmp(cmd,"?revenue_of_shop")==0){
            scanf("%s",shopID);
            Node * p = searchNode(shopID);
            if(p != NULL){
                printf("%d\n",p->price);
            }
            else{
                printf("0\n");
            }
        }
        if(strcmp(cmd,"?total_consume_of_customer_shop ")==0){
           scanf("%s%s",customerID,shopID);
            Node *p = searchNode(shopID);
            if(p != NULL){
                Node * q = searchBST(customerID, p->sub);
                if(q != NULL){
                    printf("%d\n",q->price);
                }
                else{
                    printf("0\n");
                }
            }
            else{
                printf("0\n");
            }
        }
        if(strcmp(cmd,"?total_revenue_in_period")==0){
            char start[9],end[9];
            scanf("%s%s",start,end);
            printf("%d\n",t[timeFunction(end)]- t[timeFunction(start)-1]);
        }
        if(strcmp(cmd,"#")==0){
            break;
        }
    }
    return 0;
}
