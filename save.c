#include<stdio.h>
#include"main.h"

int save(main_node **hashtable)
{
    main_node *m_temp;
    sub_node *s_temp;
    FILE *fptr = fopen("backup.txt","w");   //opening the given file in write mode
    for(int index=0;index<27;index++)
    {
	m_temp = hashtable[index];
   	 while(m_temp != NULL)
    	{	
		fprintf(fptr,"#%d;%s;%d;",index, m_temp -> word, m_temp -> file_count); //writing the main node data in backup file
		s_temp = m_temp -> s_link;
		while(s_temp != NULL)
		{
	    		fprintf(fptr,"%s;%d;",s_temp -> file_name,s_temp -> word_count); //writing the sub node data in backup file
	    		s_temp = s_temp -> link;  //traverse through sub node
		}
		m_temp = m_temp -> m_link;   //traverse through main node
		fprintf(fptr,"#\n");
    	}
    }
    return SUCCESS;
  
}

