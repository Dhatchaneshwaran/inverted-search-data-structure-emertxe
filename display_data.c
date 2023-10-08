#include<stdio.h>
#include"main.h"

int display_data(main_node *head,int index)
{
    main_node *m_temp = head;
    sub_node *s_temp;
    if(head == NULL)
    {
	return 0;
    }
    while(m_temp != NULL)    //traversing through main node
    {
	printf("%d        %s        %dfile(s)",index, m_temp -> word, m_temp -> file_count); //printing mainnode data such as word,filecount
	s_temp = m_temp -> s_link;
	while(s_temp != NULL)  //traversing through sub node
	{
	    printf("         %s         %d",s_temp -> file_name,s_temp -> word_count);   //printing subnode data such as file name,word count
	    s_temp = s_temp -> link;
	}
	m_temp = m_temp -> m_link;
	printf("\n");
    }

    return 1;
}

