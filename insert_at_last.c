#include "main.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int insert_at_last(fn_node **head, char *file_name)
{

     fn_node *temp = *head,*prev;           //temp
     while(temp)                    //traverse to last
     {
         if(strcmp(temp -> file_name,file_name) == 0) //condititon for duplicate checking duplicate
	 {
	     return DUPLICATE_FOUND;
	 }
	 temp =temp -> link;
     }

    fn_node *new = malloc(sizeof(fn_node));
    if(new == NULL)                 //checking memory created or not
    {
	return FAILURE;
    }

    new -> file_name = file_name;   //new updating value
    new -> link =NULL;      //new updating link

    if(*head == NULL)                //checking list is empty or not
    {
	*head = new;
	return SUCCESS;
    }
   
    temp = *head;
        while(temp != NULL)  //traverse to last
        {
	    prev = temp;
	    temp =temp -> link;
        }
        prev -> link =new;         //linking new node with previous last node
    
    return SUCCESS;
    
}
