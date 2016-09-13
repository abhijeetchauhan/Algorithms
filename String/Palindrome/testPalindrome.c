/* Author : Avinash Awate, Contest Co-ordinator */
/*****************************************************************************
 *                 Programming Contest IITBombayX Palindrome                  *
 *                 ----------------------------------------                  *
 * To allow contest participants to test a function which accepts a string   *
 * and print all the possible palindromes that can be generated using the    *
 * letters of the string                                                     *
 * For the purpose of this contest single characters are a palindrome        *
 * Input  : I.1) A string of  characters                                     *
 * Outputs: O.1) Total number of palindromes found                           *
 *          O.2) Palindromes output on standard output                       *
 *                                                                           *
 *****************************************************************************/

/*****************************************************************************
 *                       Source Code Organisation                            *
 *                       ------------------------                            *
 * testPalindrome.c                                                          *
 * This file allows the participant to test his function for correctness     *
 * This file contains C++ code which opens the input stream, reads the file  *
 * into an array, calls the contestants encoding function and writes the     *
 * data in the output file                                                   *
 * A correct entry will produce an exactly equivalent file                   *
 *                                                                           *
 *****************************************************************************/

/* System Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>

/* Local function prototypes */
int Palindrome(char *inStr);

/* Local #defines */
#define MAXLENGTH        (100)
#define SUCCESS                (0)
#define FAILURE                (-1)
#define TRUE                (1)
#define FALSE                (0)

/* Globals */
static char  inputStr[1000];  /* The input array */

/* Local Static Globals */
static FILE *inputfp=NULL;    /* Input file pointer */
static FILE *outputfp=NULL;   /* Output file pointer */

int main (int argc, char *argv[])
{
int  retval;                  /* Return value of function */
char *inputfile=NULL;         /* Input file name */
char *outputfile=NULL;        /* Output file name */
int  index;                   /* To traverse arrays */
char optionchar;              /* Option chracter returned by getopt */

    /* Set return value to SUCCESS */
    retval = SUCCESS;

    /* Process command line options */
    while ((optionchar = getopt (argc, argv, "i:o:")) != -1)
    {
        switch (optionchar)
        {
            case 'i':
                inputfile = optarg;
                break;
            case 'o':
                outputfile = optarg;
                break;
            case '?':
                if ( (optopt == 'i') || (optopt == 'o') )
                {
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                }
                else
                {
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                }
                retval = FAILURE;
            default:
                fprintf (stderr, "Usage : Palindrome [-i inputfile] [-o outputfile]\n");
                retval = FAILURE;
                break;
        }
    }

    /* Ignore all non option arguments */
    if (retval == SUCCESS)
    {
        for (index = optind; index < argc; index++)
        {
            fprintf(stderr, "Non-option argument %s\n", argv[index]);
        }
    }

    /* If everything OK so far, open input and output files */
    if (retval == SUCCESS)
    {   /* Correct Options specified */
        /* Open input file */
        inputfp = stdin;      /* Default is standard input */
        if (inputfile != NULL)
        {
            inputfp = fopen(inputfile,"r");
            if (inputfp == NULL)
            {
                fprintf (stderr, "Unable to open input file %s.\n", inputfile);
                retval = FAILURE;
            }
        }
        /* Open output file */
        if (outputfile != NULL)
        {
            outputfp = fopen(outputfile,"w");
            if (outputfp == NULL)
            {
                fprintf (stderr, "Unable to open output file %s.\n", outputfile);
                retval = FAILURE;
            }
            else { stdout = outputfp; }
        }
    }

    /* If everything OK so far, read input file into input array */
    if (retval == SUCCESS)
    {
        if (fscanf(inputfp, "%s", inputStr) == 1)
        {
            (void) Palindrome(inputStr);
        }
    }

    /* Clean up */
    if (inputfp != NULL) { fclose(inputfp); }
    if (outputfp != NULL) { fclose(outputfp); }

    /* Return from main */
    return(retval);
}
/*****************************************
 *********** End of Test Code ************
 *****************************************/

/************************************************
 *********** Beginning of submission ************
 ************************************************/

/* Define local variables (if any) here */
long long int totalCount=0,totalstr=0;
char *str[100001];char *gloStr;

/* Define your support function ptototypes here */
#define ll long long int
#include <stdbool.h>
typedef struct pair{
  ll first,second;
}pair;
typedef struct pairs{
  pair data;
  struct pairs *next; 
}pairs;
void InsertFirst(pairs **start,pair data){
  // This algorithm inserts ll as the first pairs of the linked list pointed by START
  pairs *p;
  p=(pairs*)malloc(sizeof(pairs));
  if(!p){
    printf("Overflow\n");
  }
  p->data=data;
  if(*start==NULL){
    p->next=NULL;
  }
  else{
    p->next=*start;
  }
  *start=p;
}
bool InsertLast(pairs **start,pair data){
  // This algorithm inserts an item at the last of the linked list
  pairs *p,*loc;
  p=(pairs*)malloc(sizeof(pairs));
  if(!p){
    printf("Overflow\n");
    return false;
  }
  p->data=data;
  p->next=NULL;
  if(*start==NULL){
    *start=p;
  }
  else{
    loc=*start;
    while(loc->next!=NULL){
      loc=loc->next;
    }
    loc->next=p;
  }
  return true;
}
void Traverse(pairs **start){
  pairs *p;
  p=*start;
  str[totalstr]=malloc(sizeof(char) * (strlen(gloStr)));
  while(p){
    printf("(%lld,%lld)",p->data.first,p->data.second);
    char *a,*b;
    a=malloc(sizeof(char) * (strlen(gloStr)+1));b=malloc(sizeof(char));
    a[0]=gloStr[p->data.first];b[0]=gloStr[p->data.second];
    str[totalstr]=strcat(a,str[totalstr]);
    strcat(str[totalstr],b);
    printf("%s",str[totalstr]);
    p=p->next;
  }
  // printf("%s",str[totalstr]);
  totalstr++;
}
bool DeleteFirst(pairs **start){
  pairs *temp;
  if(*start==NULL){
    printf("UnderFlow\n");
    return false;
  }
  temp=*start;
  *start=(*start)->next;
  free(temp);
  return true;
}
void Check(pairs **one,pairs **kdec,pairs **k,ll *count,ll no){
  pairs *in,*check,*out;
  in=*kdec;check=*one;out=*k;
  while(in){
    if((check->data.first)>(in->data.first) && (check->data.second)<(in->data.second)){
      in=in->next;
    }
    else{
      break;
    }
  }
  if(in!=NULL){
    return;
  }
  else{
    in=*kdec;
    while(in){
      InsertLast(k,in->data);
      in=in->next;
    }
    InsertFirst(k,check->data);
    *count=*count+1;
    totalCount++;
    return;
  }
}
void printPal(pairs **pal1,ll size){
  ll i;
  for(i=0;i<size;i++){
      Traverse(&pal1[i]);
      printf(",");
  }
  printf("\n");
}
/********************************************
 *********** Submission function ************
 *******************************************/
/*
 * The function Palindrome accepts one parameter
 * Inputs
 *     The parameter inStr contains the input string
 * Outputs
 *     The function returns the number of unique palindromes generated
 *     The function also prints each unique palindrome on a separate standard output line
 *
 * Algorithm
 *
 */
int Palindrome(char *inStr)
{
    /* Return number of sequences */
    ll j,i;
    gloStr = malloc(sizeof(char) * strlen(inStr));
    strcpy(gloStr,inStr);
    ll str_size=strlen(inStr);
    printf("%lld",str_size);
    // ----------------------------------------------Finding all 1-palindromes----------------------------------------------
      pairs *pal[str_size/2][str_size];
      ll count[str_size/2];totalCount=0;
      for(i=0;i<str_size/2;i++) count[i]=0;
      for(i=0;i<str_size/2;i++){
        for(j=0;j<str_size;j++)
        pal[i][j]=NULL;
      }
      for(i=0;i<str_size;i++){
        for(j=i+1;j<str_size;j++){
          if(inStr[i]==inStr[j]){
            pair no;
            no.first=i;no.second=j;
            InsertFirst(&pal[0][count[0]],no);
            InsertFirst(&pal[1][count[1]],no);
            count[0]++;
            count[1]++;
            totalCount++;
          }
        }
      }
      // for(i=0;i<str_size;i++){
      //   pair no;
      //   no.first=i;no.second=i;
      //   InsertFirst(&pal[2][count[2]],no);
      //   count[2]++;
      // }
      // printf("%lld\n",count[1]);
      printPal(pal[1],count[1]);
      // ---------------------------------------------Finding all palindromes-------------------------------------------
      ll k;
      for(k=2;k<str_size/2;k++){
        for(i=0;i<count[k-1];i++){
          for(j=0;j<count[0];j++){
            Check(&pal[1][j],&pal[k-1][i],&pal[k][count[k]],&count[k],k);
          }
        }
        printPal(pal[k],count[k]);
      }
       // ----------------------------------------------Finding all 1-palindromes----------------------------------------------
      for(i=0;i<str_size/2;i++) count[i]=0;
      for(i=0;i<str_size/2;i++){
        for(j=0;j<str_size;j++)
        pal[i][j]=NULL;
      }
      for(i=0;i<str_size;i++){
        for(j=i+1;j<str_size;j++){
          if(inStr[i]==inStr[j]){
            pair no;
            no.first=i;no.second=j;
            InsertFirst(&pal[1][count[1]],no);
            count[1]++;
            totalCount++;
          }
        }
      }
      for(i=0;i<str_size;i++){
        pair no;
        no.first=i;no.second=i;
        InsertFirst(&pal[0][count[0]],no);
        count[0]++;
      }
      printf("%lld\n",count[0]);
      printPal(pal[0],count[0]);
      // ---------------------------------------------Finding all palindromes-------------------------------------------
      for(k=2;k<str_size/2;k++){
        for(i=0;i<count[k-1];i++){
          for(j=0;j<count[0];j++){
            Check(&pal[0][j],&pal[k-1][i],&pal[k][count[k]],&count[k],k);
          }
        }
        printPal(pal[k],count[k]);
      }

      printf("%lld\n",totalCount);
}
