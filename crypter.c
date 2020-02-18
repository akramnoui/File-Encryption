#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypter.h"

 int crypter(char * FILENAME, char * NEW_FILENAME ,  char* key )    // fonction de cryptage ajoute une cle entree par l'utilisateur 
{
    FILE *inFile;   //Declaration inFile					// fait un nombre de decalages circulaires sur des blocs de 10 caracteres 
    FILE *outFile;  //Declaration outFile					// fait une operation de xor logique sur les blocs
    char word1[50] , sum[50] ;
    char result[50] , decal[50] ;
	char word2[] = "PPPP";
    char newCaract , caract;
    int n ,cpt = 0;
    int i=0 , j ,k;

    inFile = fopen(FILENAME,"rb");
    outFile = fopen(NEW_FILENAME, "w");
    
    if(inFile == NULL || outFile == NULL){
        printf("Probleme d'ouverture");
            return 1;
    } else {
        printf("\nFichier ouvert, cryptage\n");
           while(1){
                while ( !feof( inFile ))
				{
					i=0;
					strcpy(word1,"");
					while (i < 10) 
					{
					 	  caract=fgetc(inFile);
			  		 	  if(caract==EOF)
			            {
				          break;
				          
			            } 
						else{
						
					
						word1[i] = caract; 
						i++;
						}
	     			
					 }
					 word1[i] = '\0';
			           
			            
					 	addkey(word1 , word2 , sum);
					 	strcpy(word1,sum);
		 	 	        strcpy(result,"");
			 			strcpy(decal , ""); 
			 			if (i ==10){
						strcpy(decal , ""); 
					    decCirculaire(word1 , decal); 
					    xorop(decal , word2 , result );
    					}else
    					{
    						strcpy(result,word1);
						}
		            j = 0;
		            while(j < strlen(result))
		            {
		            	newCaract = result[j];
	            	    fputc(newCaract,outFile);
	            	    j++;
					}
					strcpy(result,"");
		       }   
             printf("Fin du fichier");
             break;
         }
		 
        }
        fclose(inFile);
        fclose(outFile);
    }
    /**********************************************************************************************************************************************/




int decrypter(char *FILENAME, char *NEW_FILENAME , char* key) // fonction de decryptage
{
    FILE *inFile; //Declararation inFile
    FILE *outFile; //Declaration outFile

    char caract;
    char word1[50] , final[50] ;
    char result[50] , decal[50] ;
	char word2[] = "PPPP";
    char newCaract;
    int i=0 , j;

    inFile = fopen(FILENAME,"rb");
    outFile = fopen(NEW_FILENAME, "w");

    if(inFile == NULL || outFile == NULL){
        printf("Probleme d'ouverture'");
        return 1;
    } else {
        printf("Fichier ouvert, Decryptage");
        while(1){
            while ( !feof( inFile ) )
				{
					i=0;
					strcpy(word1,"");
					while (i < 10)
					{
					     caract=fgetc(inFile);
			  			  if(caract==EOF)
			            {
				          break;
				          	 word1[i]='\0';
			            }
			           
						else
			            {
					
						word1[i] = caract; 
						i++;
						}
	     			
					 }	
					 word1[i]='\0';	
						
					 	if ( i == 10)
					 	{
						 
					 	 xorop(word1 , word2 , result );
					 
					    decCirculaireg(result , decal);
	   				
					   		strcpy(word1,decal);
	                	minuskey(word1 , word2 , final);
	                	 }
	                	 else{
               	 		    minuskey(word1 , word2 , final);
						 }
		            j = 0;
		            while(j < strlen(final))
		            {
		            	newCaract = final[j];
	            	    fputc(newCaract,outFile);
	            	    j++;
					}
					strcpy(result,"");
				
            } 
            printf("Fin du fichier");
            break;
        }
        fclose(inFile);
        fclose(outFile);
    }
}

/**********************************************************************************************************************************************/


int comparer(char * FILENAME, char * NEW_FILENAME)
{
	int erreur=0;
	int a,b;
	FILE *inFile; 
    FILE *outFile;
    
    inFile = fopen(FILENAME,"r");
    outFile = fopen(NEW_FILENAME, "r");
 
	if(inFile != NULL && outFile != NULL)
	{
		while( (!feof(inFile)) && (!feof(outFile)) && (!erreur))
		{
			if ( fgetc(inFile) != 10 &&fgetc(outFile) != 10)
			{
			
			a=fgetc(inFile);
			b=fgetc(outFile);
			printf("\n a = %c " , a);
			printf("        b = %c " , b);
			}
			
			if (a!=b && a!= 10 && a != 13 && b!= 10 && b!= 13 )
			{
				erreur = 0;
			
			}
			if ( a == EOF || b == EOF )
			{

				break;
			
			}
		}
    }
	return erreur;
}
	 

 void decCirculaire(char  string[]  , char result[]) // prend une chaine de caractaire et effectue c decalages circulaires 
 	  					   		   	 	  			//tq c est le plus grand chiffre de la sommme de ses codes ASCII
 {
 	int i=0 , j , nb  , x ;
 	int c=0;
 	char string1[50];
 	strcpy(string1 , string);
 		strcpy(result,"");	
 	while ( i < strlen(string1)-1)    
 	{
 		c +=string1[i];		 
 		i++;
	}
	nb= 6;	
	// decalage circulaire  droit nb fois
	string[i+1] = '\0';
	while ( nb!= 0)
	{
        result[0] = string[strlen(string)-1];
		i = 0;
  		j = 1;	
		while ( i < strlen(string1) - 1)
		{

			result[j] = string[i];
			j++;
			i ++;
			
		}
		nb--;
			
	}
		
 	
 }
 /**********************************************************************************************************************************************/


  void decCirculaireg(char  string[]  , char result[]) // prend une chaine de caractaire et effectue c decalages circulaires gauche
 {
 	int i=0 , j , nb  , x ;
 	int c=0;
 	char string1[50];
 
	nb= 6;		
	// decalage circulaire  gauche c fois
		strcpy(result,"");	
	while ( nb!= 0)
	{
       
		i = 1;
  		j = 0;	
  			 result[strlen(string)-1] = string[0];
		while ( i < strlen(string) )
		{

			result[j] = string[i];
			j++;
			i ++;
			
		}
		nb--;
			
	}
	result[i] = '\0'; 

 	
 }
 /**********************************************************************************************************************************************/




void xorop(char * word1 , char * word2 , char  result[])
 {
 	char c  ;
 	int j = 0 ;
 	int i = 0;
 	strcpy(result , "");
 while  ( i < strlen(word1) ) 
 	{ 		
 	
 	  	  	c = word1[i] ^ word2[j] ;
		     result[i]  = c;
 	 	 
	  	i++;
	  	j++;
	  	if (j>= strlen(word2))
	  	{
	  		j = 0;
        }
    
	  	
	  	
	 }
	 result[i]  = '\0'; 
	
 	
 }
 /**********************************************************************************************************************************************/


 void addkey(char  word1[] , char  key[] , char  result[])
 {
 	int  c =0  ;
 	char chr;
 	int j = 0 ;
 	int i = 0;
 while  ( i < strlen(word1) ) 
 	{ 
 	  	  if ( (word1[i] != 13) && (word1[i]!= 10)) // retour de ligne
       	  	 {				    	
			    result[i]  = word1[i] + key[j] ;
	     } else{
	     	result[i]= word1[i];
		 } 
	   
	  	i++;
	  	j++;
	  	if (j>= strlen(key))
	  	{
	  		j = 0;
        }
    
	  	
	 }
	 result[i] = '\0';
	
 	
 }
 /**********************************************************************************************************************************************/


  void minuskey(char  word1[] , char  key[] , char  result[])
 {
 	int  c =0  ;
 	char chr;
 	int j = 0 ;
 	int i = 0;
 while  ( i < strlen(word1) ) 
 	{ 
 	  	   if ( (word1[i] != 13) && (word1[i]!= 10)) // retour de ligne
       	  	 {				    	
			    result[i]  = word1[i] - key[j] ;
	     } else{
	     	result[i]= word1[i];
		 } 	
 	  	 
	  	i++;
	  	j++;
	  	if (j>= strlen(key))
	  	{
	  		j = 0;
        }
    
	  	
	 }
	 result[i] = '\0';
	
 	
 }
 /**********************************************************************************************************************************************/





