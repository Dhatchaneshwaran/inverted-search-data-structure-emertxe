#include <stdio.h>
#include "main.h"
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

int update_database(FILE *fptr,main_node *hash_t[27]);			
int update_validation(char file[50],main_node **hash_t)    //file validation
{
    FILE *fptr = fopen(file,"r");    //opening the backup file in read mode                   
    if (fptr == NULL)
    {
	perror("fopen");					
	fprintf(stderr, "ERROR: Unable to open file %s\n",file);
	return FAILURE;
    }
    else
    {
	fseek(fptr,0,SEEK_END);					
	if(!(ftell(fptr)))         //checking file is empty or not
	{
	    fprintf(stderr,"ERROR : File %s is an empty file\n",file);
	    printf("Hence we can not update database\n");
	}
	else
	{
	    if(strcmp((strstr(file,".")),".txt"))    //checking the given file is of type .txt	
	    {
		printf("FAILURE in %s: Pass .txt file\n",file);
		return FAILURE;
	    }
	    else
	    {
		rewind(fptr);   //setting offset to starting of a file				
		if(update_database(fptr,hash_t) != SUCCESS)   //updating database from backup file
		{
		    return FAILURE;
		}
		return SUCCESS;
	    }
	}
    }
}


int update_database(FILE *fptr,main_node *hash_t[27])
{
    char arr[50];					
    int index=0;
    char word[50];
    int file_count =0;
    char file_name[50];
    int word_count=0;					
    while(fscanf(fptr,"%s",arr) != EOF)
    {
	if(arr[0] == '#')				
	{
	    index=atoi(strtok(&arr[1],";"));
	    strcpy(word,(strtok(NULL,";")));
	    file_count=atoi(strtok(NULL,";"));		
	    int i= file_count;
	    if(hash_t[index]== NULL)   //if the index is empty, it will create new main node and sub node and update the values
	    {
		main_node *main_n =malloc(sizeof(main_node));		
		if(main_n == NULL)
		    return FAILURE;
		else
		{
		    main_n->file_count = file_count;	
		    strcpy(main_n->word,word);
		    main_n->m_link=NULL;
		    main_n->s_link=NULL;
		    strcpy(file_name,(strtok(NULL,";")));
		    word_count = atoi(strtok(NULL,";"));
		    sub_node *sub=malloc(sizeof(sub_node));
		    if(sub == NULL)
			return FAILURE;
		    else
		    {
			strcpy( sub->file_name, file_name);
			sub->word_count = word_count;
			sub->link=NULL;
			main_n->s_link= sub;
		    }
		    sub_node *temp=sub;
		    while(--i)				
		    {
			sub_node *sub=malloc(sizeof(sub_node));
			if(sub == NULL)
			    return FAILURE;
			else
			{
			    strcpy(file_name,(strtok(NULL,";")));
			    word_count = atoi(strtok(NULL,";"));
			    strcpy( sub->file_name, file_name);
			    sub->word_count = word_count;
			    sub->link=NULL;
			    temp->link= sub;
			    temp=sub;

			}

		    }
		}
		hash_t[index]=main_n;				
	    }
	    else        // if given index is not empty
	    {
		main_node *tempt=hash_t[index],*prev=NULL;
		while(tempt != NULL)				
		{
		    prev=tempt;					
		    tempt=tempt->m_link; 
		}
		main_node *main_n =malloc(sizeof(main_node));
		if(main_n == NULL)
		    return FAILURE;	
		else
		{
		    main_n->file_count = file_count;
		    strcpy(main_n->word,word);
		    main_n->m_link=NULL;			
		    main_n->s_link=NULL;
		    strcpy(file_name,(strtok(NULL,";")));
		    word_count = atoi(strtok(NULL,";"));
		    sub_node *sub=malloc(sizeof(sub_node));
		    if(sub == NULL)
			return FAILURE;
		    else
		    {
			strcpy( sub->file_name, file_name);
			sub->word_count = word_count;
			sub->link=NULL;
			main_n->s_link= sub;
		    }
		    sub_node *temp=sub;
		    while(--i)
		    {
			sub_node *sub=malloc(sizeof(sub_node));
			if(sub == NULL)
			    return FAILURE;
			else
			{
			    strcpy(file_name,(strtok(NULL,";")));
			    word_count = atoi(strtok(NULL,";"));
			    strcpy( sub->file_name, file_name);
			    sub->word_count = word_count;
			    sub->link=NULL;
			    temp->link= sub;
			    temp=sub;

			}

		    }
		}
		prev->m_link=main_n;				

	    }
	}
	else								
	{
	    printf("Invalid file format\n");
	    return FAILURE;
	}

    }
    return SUCCESS;
}


