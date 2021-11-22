/*Systems Programing Lap , OpenU , Fall 2022
11 Assignment , Q1 
by Hamza Sharabati 
this program gets char string from user and shorten it by replacing the alpha-numerical series with 1st-last char
assumed max number of char is defined MAX-1 
the input is holded in char array and copied to other one replacing each series of alpha-numerical char with 1st-last char .

 */


#include<stdio.h>
#define MAX 81
#define IN 1
#define OUT 0
/*  this function copies its first string para to the 2nd one in shortened way */
void contract (char s1[],char s2[]) 
    { int i=0 ;
      int j=0 ;
      int stat=OUT ;
      
      /* this is the main loop in the func , moving on the first string ---> the MAX */
      while(i<MAX)
      {
          /* non alpha-num char copied directly to s2 */
          if ((s1[i]<'0') || ((s1[i]>'9')&&(s1[i]<'A')) || ((s1[i]>'Z')&&(s1[i]<'a')) || (s1[i]>'z'))
            
          {s2[j]=s1[i] ;
          i++ ;
          j++ ;
          stat=OUT ;
          }
          /* alpha-num before entering a series */
          else if (stat==OUT)
          {
           s2[j]=s1[i] ;
           i++ ;
           j++ ;
           /* IF a new seris begins here */
           if(((s1[i]-s1[i-1])==1)&&((s1[i+1]-s1[i])==1))
            stat=IN ;  
          
          }
          /* inside a series */
          else if (stat==IN)
          { 
              
              if ((s1[i+1]-s1[i])==1)
              
              i++ ; 
              /* adding '-' and last char at the end of series */
              else 
              {
                  s2[j]='-';
                  j++ ;
                  s2[j]=s1[i] ;
                  i++ ;
                  j++ ;
                  stat=OUT ;

              }
          }
   
        }


     }    
/* the main func get the string from standard input (user keybourd) and print it again along with the modified string to the standard output */     
int main() 
    {
char s1[MAX] ;
char s2[MAX] ;
printf("please insert your text \n ") ;
fgets(s1,MAX,stdin) ;
contract(s1,s2) ;
printf("The orginal TEXT : \n") ;
fputs(s1,stdout) ;
printf("The Modiefied text : \n");
fputs(s2,stdout);
return 0 ;
    }


