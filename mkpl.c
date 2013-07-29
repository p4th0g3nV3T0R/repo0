
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SLEN 256
#define bsize 200

char * removeNL( char *);

int getfn( char *);

int main( int argc, char *argv[])
{
  
	/* Begin declaration of variables */
	
	char s0[SLEN], s1[SLEN],s2[SLEN],strfn[SLEN];
	
	char s3[SLEN];
	
	char q,qq;
	
	int j,j0,j1;
	FILE *fin, *fout;
	

	q='\'';
	qq='\"';


	if( argc != 3)
	{
		goto hell;
	}
	
	
	
	/* create a string that has relative address to input file*/
	
	sprintf(s0,"./%s",argv[1]);


	sprintf(s3,"./%s",argv[2]);
	
	fin = fopen( s0, "r");	


	fout = fopen( s3,"w");
	
	

	fprintf(fout,"#EXTM3U\n");
	
	while (  fgets(s1,bsize,fin) != NULL  )
	{
		
		removeNL(s1);
		
		sprintf(strfn, "%s",&s1[getfn(s1)] ); 
		
		sprintf(s2,"%c%s%c",qq,s1,qq);
	  
	  
		fprintf(fout,"#EXTINF:1234,%s\n",strfn);

		fprintf(fout,"%s\n",s1);
	
		
	}
	
	fclose(fout);
	fclose(fin);

	return EXIT_SUCCESS;
	
	hell:
	
	return EXIT_FAILURE;
}



char * removeNL( char * strptr)
{
	char  *cptr;
	int i,j,k;
	
	
	/*set cptr to address of the start of the string */
	cptr=strptr;
	
	/*initialize an index variable */
	i=0;
	
	
	while ( ( cptr[i] != '\0' ) && ( cptr[i] != '\n' ))
	{
		
    	i++;
		if (i>SLEN)
		{
			fprintf(stderr,"error\n\n");
			
			return cptr;
		}
	}
	
	if (cptr[i] == '\n')
	{
		cptr[i]='\0';
		
		return cptr;
		
	}
	
	return cptr;
	
}



int getfn( char *sptr)
{
	int m,n,k;
	char * ptr;
	
	ptr=sptr;

	m=0;
	
	while( ptr[0] != '\0')
	{
		m=m+1;
		ptr++;
		

	}
	
	ptr=sptr;
	

	k=m-1;
	
	while (ptr[k] != '/')
	{
	
		k = k - 1;
	}
	
	return (k+1);
	
	
	
}
