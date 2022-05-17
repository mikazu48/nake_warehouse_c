#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct stringData {
    char product_name[100];
    char product_category[100];
    char product_brand[100];
    char product_stock[100];
    char product_price[100];
    char product_id[100];
    struct stringData *next;
} Node;

Node *createNode(char product_name[100],char product_category[100],char product_brand[100],char product_stock[100],char product_price[100],char product_id[100]) {
	
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->product_name, product_name);
    strcpy(newNode->product_category, product_category);
    strcpy(newNode->product_brand, product_brand);
    strcpy(newNode->product_stock, product_stock);
    strcpy(newNode->product_price, product_price);
    strcpy(newNode->product_id, product_id);

    newNode->next = NULL;
    return newNode;
}


void insert(Node **link, Node *newNode) {
    newNode->next = *link;
    *link = newNode;
}

void printList(Node *head) {
	int pos=1;
	
	printf("=================================================================================\n");
	printf("| ID  |  Product Name  |  Category  |  Brand  |  Stock  |  Price  | \n");
	printf("=================================================================================\n");
    while (head != NULL) {
//    	printf("| %s | ",pos);
        printf("| %s | ", head->product_id);
        printf("| %s | ", head->product_name);
        printf("| %s | ", head->product_category);
        printf("| %s | ", head->product_brand);
        printf("| %s | ", head->product_stock);
        printf("| %s | ", head->product_price);
        printf("\n");

		pos++;
        head = head->next;
    }
	printf("=================================================================================\n");
}
void search_value(Node *head, char value[]) {
	int pos=1;
    while (head != NULL) {
    	int hasil = 0;
    	hasil = strcmp(head->product_name,value);

    	if(hasil == 0) {
    		printf("===== %d =====\n",pos);
        	printf("product_name : %s \n", head->product_name);
        	printf("product_brand : %s \n", head->product_brand);
//        	printf("ID : %s\n============ \n", head->product_id);
        	break;
		}
		else{
        	printf("Data tidak ditemukan!");
		}
		pos++;
        head = head->next;
    }
}
int checkproduct_name(Node *head, char value[]) {
    while (head != NULL) {
    	int hasil = 0;
    	hasil = strcmp(head->product_name,value);
    	if(hasil == 0) {
    		printf("Product Name sudah ada! \n\n");
    		return 1;
		}
		else{
			return 0;
		}
        head = head->next;
		return 0;
    }
}

int lengthData(Node *head) {
	int data=1;
    while (head != NULL) {
    	data++;
        head = head->next;
    }
    return data;
}

int special_character(char str[]){
   int i, flag = 0;
   for (i = 0; i < 100; ++i){
      //checking each character of the string for special character.
      if(str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$'
      || str[i] == '%' || str[i] == '^' || str[i] == '&' || str[i] == '*'
      || str[i] == '(' || str[i] == ')' || str[i] == '-' || str[i] == '{'
      || str[i] == '}' || str[i] == '[' || str[i] == ']' || str[i] == ':'
      || str[i] == ';' || str[i] == '"' || str[i] == '\'' || str[i] == '<'
      || str[i] == '>' || str[i] == '.' || str[i] == '/' || str[i] == '?'
      || str[i] == '~' || str[i] == '`' ){
         printf("Product Name terdapat special character!\n");
         flag = 1;
         return 1;
      }
      else {
   		return 0;
	  }
   }
   return 0;
}
void deleteNode(Node** head_ref, char f_id[100])
{
    struct stringData* prev = *head_ref;
 
    while (*head_ref)
    {
    	int hasil = 0;
    	hasil = strcmp(prev->product_id,f_id);
//        if(hasil == 0){   	
//        	*head_ref = (*head_ref)->next;
//        	free(prev);
//        	prev = *head_ref;
//		}
			*head_ref = (*head_ref)->next;
        	free(prev);
        	prev = *head_ref;
    }
	
}
void deleteNodeData(Node *head, char value[]) {
	int pos=1;
    while (head != NULL) {
    	int hasil = 0;
    	hasil = strcmp(head->product_name,value);

    	if(hasil == 0) {
        	free(head);
        	break;
		}
		else{
        	printf("Data not found");
		}
		pos++;
        head = head->next;
    }
}

int main(void)
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *n;
 	int input = 5;
 	int retval = 0;

	
	while(input != 0) {
		printList(head);
  		printf("\n\n=====Nake Warehouse=====\n\n");
  		printf("1: Insert New Product\n");
  		printf("2: Delete Product\n");
  		printf("3: Exit\n");
  		printf("\>>: ");
  		scanf("%d", &input);
		if(input==3){
    		printf("...Thank You...\n");
    		exit(0);
		}
	else if(input==1){
	 	
    	char _product_name[100] = "";
    	char _product_brand[100]= "";
    	char _product_category[100]= "";
    	char _product_stock[100]= "";
    	char _product_price[100]= "";
    	char _product_id[100]= "NKW";
	 	
    	while(strlen(_product_name) < 5 || strlen(_product_name) > 24)
		{
			printf("Input Name : ");
    		scanf("%s", &_product_name);
		}
		
		while (strstr(_product_category, "Shoes") == NULL && strstr(_product_category, "Bag") == NULL) {
    		printf("Choose Category [Shoes | Bag] (case sensitive) : ");
    		scanf("%s", &_product_category);
		}	
		
		while (strstr(_product_brand, "Nike") == NULL && strstr(_product_brand, "Adidas") == NULL) {
    		printf("Choose Brand [Nike | Adidas] (case sensitive) : ");
    		scanf("%s", &_product_brand);
		}	
		
    	printf("Input Stock [ 50 - 150 ] :");
    	scanf("%s", &_product_stock);
    	printf("Input Price [ 200000 - 1000000 ] : ");
    	scanf("%s", &_product_price);
//    	
//    	strcpy(_product_id, _product_name);
//    	strcat(_product_id, "-");
    	char lengthResult[100] = "";
    	sprintf(lengthResult, "%d", lengthData(head));
    	strcat(_product_id,lengthResult) ;

    	n = createNode(&_product_name,&_product_category,&_product_brand,_product_stock,_product_price,_product_id);
    	// First node at start of list - head is updated.
    	insert(&head, n);
    	// First node is also the tail.
    	tail = n;
	}
	else if(input==2){
    	char findData[100]; 
    	printf("Input ItemID to delete (case insensitive) : ");
    	
    	scanf("%s", &findData);
    	deleteNode(&head,findData);
	}
	
	else if(input==5){
    	printf("Anda Memilih: 'Tampilkan'\n");
    	printList(head);
	}
}
 return(0);
 
 
}
