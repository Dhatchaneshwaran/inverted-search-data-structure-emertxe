#include<stdio.h>
#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY 2
#define DATA_NOT_FOUND 3
#define DUPLICATE_FOUND 4

typedef struct file_name{     //structure for storing filenames
    char *file_name;
    struct file_name *link;
}fn_node;

typedef struct sub_node{      //structure for sub node
    int word_count;
    char file_name[20];
    struct sub_node *link;

}sub_node;

typedef struct main_node{     //structure for main node
    char word[20];
    int file_count;
    struct main_node *m_link;
    struct sub_node *s_link;
}main_node;
//function protype for all functions
int file_validate(int argc, char *argv[]);
int insert_at_last(fn_node **head, char *file_name);
int create_data_base(main_node **head,char *word,char *filename);
void print_list(fn_node *head);
int display_data(main_node *head,int index);
int search_data(main_node *head,int index,char *word);
int save(main_node **head);

int update_database(FILE *fptr,main_node *hash_t[27]);			
int update_validation(char file[50],main_node **hash_t);
