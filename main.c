#include"wh.h"



int lexicographal_sort(const void* val1, const void* val2)
{
    const char* word_1=*((const char**)val1);
    const char* word_2=*((const char**)val1);
    return strcmp(word_1, word_2);

}






int main(/*int argc, char* argv[]*/)
{
    FILE *input;
    FILE *output;
    char tmp;
    char**words;
    char*word;
    int symbols=0,word_count=0, word_len=0;
 //   if(argc<=1)
   // {
   //     printf("Error wrong number!\n");
  //      return -1;
  //  }
    input=fopen("t1.txt","r");
    output=fopen("t2.txt","w");
    if(input==NULL || output==NULL)
    {
        printf("Error: cannot open file!\n");
        return -2;
    }
   while(fscanf(input, "%c",&tmp)==1)
   {
    if (tmp==' ' || tmp=='\n' || tmp=9)
       {
           word_count+=1;
       }
       symbols+=1;
   }
   word_count+=1;
   if(symbols==0)
   {
       printf("Error! no symbols\n");
       return -3;
   }

   fseek(input, 0, 0);
   words=(char**)malloc(word_count*sizeof(char*));
   word=(char*)malloc(0);
   int words_processed=0;

   for(int i=0; i<symbols;i++)
   {
       fscanf(input,"%c", &tmp);
       if (tmp==' '  || tmp=='\n' || i==symbols-1 || tmp=9)
       {
           if(i==symbols-1)
           {
              fscanf(input,"%c", &tmp);
               word_len+=1;
               word=(char*)realloc(word,word_len);
               word[word_len-1]=tmp;
           }

        word=(char*)realloc(word,word_len+1);
        word_len+=1;
        word[word_len-1]='\0';
        words[words_processed]=(char*)malloc(word_len*sizeof(char));
        for (int j=0; j<word_len;j++)
        {
            words[words_processed][j]=word[j];
        }
        word_len=0;
        words_processed+=1;
       }
       else
       {
           if(word_len!=0)
           {
               word_len+=1;
               word=(char*)realloc(word, word_len*sizeof(char));
               word[word_len-1]=tmp;
           }
           else
           {
               word_len=1;
               word=(char*)realloc(word,sizeof(char));
               word[0]=tmp;
           }
       }


       }
       qsort(words,(size_t)words_processed, sizeof(char*),lexicographal_sort);

       for (int i=0; i<words_processed;i++)
       {
           int j=0;
           while(words[i][j]!='\0')
           {
               fprintf(output, "%c", words[i][j]);
               j+=1;
           }
           fprintf(output, "%c", '\n');
       }


    fclose(input);
    fclose(output);
    free(words);
    free(word);
    printf("done\n");

    return 0;
}
