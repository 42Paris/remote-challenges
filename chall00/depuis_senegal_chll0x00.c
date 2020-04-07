#include  <stdio.h> 
#include  <stdlib.h>
#include  <string.h>

int ft_necklace  (char *  , char * )  ; 

int
main ( void )  {
    printf("status =  %d \n" ,  ft_necklace("nicole", "icolen"))  ; //1  
    printf("status =  %d \n" ,  ft_necklace("nicole", "lenico"))  ; //1
    printf("status =  %d \n" ,  ft_necklace("nicole", "coneli") )  ; //0
    printf("status =  %d \n" ,  ft_necklace("aabaaaaabaab", "aabaabaabaaa")); //0 
    printf("status =  %d \n" ,  ft_necklace("abc", "cba") )  ; //0
    printf("status =  %d \n" ,  ft_necklace("xxyyy", "xxxyy"))  ; //0
    printf("status =  %d \n" ,  ft_necklace("x", "x"))  ; //1
    printf("status =  %d \n" ,  ft_necklace("x", "xx"))  ; //0
    printf("status =  %d \n" ,  ft_necklace("x", ""))  ; //0
    printf("status =  %d \n" ,  ft_necklace("", ""))  ; //1

    return  EXIT_SUCCESS; 
}

int ft_necklace ( char  *origine  ,  char *derive ) {
    int status = 0  , incre = 0  , origine_len  =strlen(origine) ;  

    if(origine_len !=  strlen(derive))return status  ; 

    char *m_origine  =  malloc(sizeof(int)  * (origine_len *2) );  
    char *container =   malloc(sizeof(char) * (origine_len +1) ) ;

    if(m_origine == NULL || container== NULL  ) exit(EXIT_FAILURE) ;  
    if(strcpy(m_origine ,  origine)  == NULL  ) exit(EXIT_FAILURE) ;  
 
    while (origine_len >  incre ) 
    {
        char  *start_point  =  NULL , *end_point =  NULL ;

        //! get the  first  letter at each itteration  and  move  it at the  end ...   
        start_point   =  strrchr(m_origine,  m_origine[incre]) ;  
        end_point     =  strrchr(m_origine,  m_origine[strlen(m_origine)+1]) ; 
        *end_point    =  *start_point; 
        //! replace   the first  by an empty space   
        *start_point  =  ' ' ; 
        
        // reorganizee by removing empty space  
        for ( int i= 0 ,j=0 ; i < strlen(m_origine) ; i++ )  {
            if  ( m_origine[i] != ' ')  
            {
                container[j] = m_origine[i] ; 
                j++ ; 
            }
        }

        if  ( status =  strcmp(container  ,  derive) == 0 )  
        {
            free(m_origine)  ; 
            free(container) ; 
            break  ;   
        }
        incre ++ ;  
    } 
    return  status  == 1 ? 1 : 0  ;
}
