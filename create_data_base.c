#include"main.h"
#include<string.h>
#include<stdlib.h>
int create_data_base(main_node **head,char* word,char *file_name)
{
    
    
    if(*head == NULL)       //if given index is null then created new main node and sub node and update values
    {
    	main_node *m_new = malloc(sizeof(main_node));
	if(m_new == NULL)
	{
	    return FAILURE;
	}
    	strcpy(m_new -> word, word);
    	m_new -> file_count = 1;
    	m_new -> m_link = NULL;

    	sub_node *s_new = malloc(sizeof(sub_node));
    	s_new -> word_count = 1;
    	strcpy(s_new -> file_name, file_name);
    	s_new -> link = NULL;

    	m_new -> s_link = s_new;
    	*head = m_new;
	return SUCCESS;
    }
    else if(*head != NULL)  //if given index is not null 
    {
        main_node *m_temp,*m_prev;
        sub_node *s_temp,*s_prev;
	m_temp = *head;
	while(m_temp != NULL)
	{
	    m_prev = m_temp;
	    if(strcmp(m_temp -> word, word)==0) //checking the given word is present 
	    {
		s_temp = m_temp -> s_link;
		while(s_temp != NULL)
		{
		    s_prev = s_temp;
		    if(strcmp(s_temp -> file_name, file_name) == 0) //checking filename is present then increase file name count
		    {
			(s_temp -> word_count)++;
			return SUCCESS;
		    }
		        s_temp = s_temp -> link;
		}
		(m_temp -> file_count)++;
                sub_node *s_new = malloc(sizeof(sub_node));    //creating new sub node
	        s_new -> word_count = 1;
		strcpy(s_new -> file_name, file_name);
		s_new -> link = NULL;
		s_prev -> link = s_new;
		return SUCCESS;
	    }
                m_temp = m_temp -> m_link;
	}
        main_node *m_new = malloc(sizeof(main_node));      //insert the main node and sun node at last
        strcpy(m_new -> word, word);
        m_new -> file_count = 1;
    	m_new -> m_link = NULL;

    	sub_node *s_new = malloc(sizeof(sub_node));
    	s_new -> word_count = 1;
    	strcpy(s_new -> file_name,file_name);
    	s_new -> link = NULL;

    	m_new -> s_link = s_new;
	m_prev -> m_link = m_new;
	return SUCCESS;
    }    
}
