#include<stdio.h>

int strlen(char *str)
{
    int i=0;
    while(*(str+i) !='\0')
    {
        i++;
    }
    return i;
}

void strcpy(char *destination, char *source)
{
    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

int strcmp(char *str1,char *str2)
{
    while(*str1==*str2 )
    {
        if(*str1=='\0' || *str2=='\0')
            break;
        str1++;
        str2++;
    }
    if(*str1==*str2)
        return 0;
    else if(*str1<*str2)
        return -1;
    else if(*str1>*str2)
        return 1;

        return 0;
}

int strtok(char *str,char *delimiters,char tokens[500][127])
{
    int i=0,j=0,k=0,m;
    while(str[k] != '\0')
    {
        m=0;
        while(delimiters[m]!='\0')
        {
            if(str[k]==delimiters[m])
            {
                tokens[i][j]='\0';
                i++;
                j=0;
                break;
            }
            m++;
        }
        if(delimiters[m]=='\0')
        {
            tokens[i][j]=str[k];
            j++;
        }
        k++;
    }
    return i;
}

int main()
{
    char str[1001],tokens[500][127],com_token[12][5];
    char com_words[12][5]= {"a", "an", "the","am", "is", "are","of", "in", "to", "from", "at"};
    char delimiters[8]= {'.', ',' , '!' , ':' , ';' , '?',' ','\0'};
    int i,j,com_num=0,token_num,word_num,delim_num=0,str_lenth,com_lenth=0,zerolentok=0;
    printf("PASSAGE :\n");
    gets(str);
    token_num=strtok(str,delimiters,tokens);
    str_lenth=strlen(str);
    for(i=0; i<token_num;  i++)
    {
        for(j=0 ; j<11; j++)
        {
            if(!strcmp(tokens[i],com_words[j]))
            {
                strcpy(com_token[com_num],tokens[i]);
                com_num++;
            }
        }
    }
    for(i=0; i<com_num; i++)
    {
        com_lenth=com_lenth+strlen(com_token[i]);
    }
    for(i=0 ; i<str_lenth ; i++)
    {
        for(j=0; delimiters[j]!='\0' ; j++)
            if (str[i]==delimiters[j])
                delim_num++;
    }
    for(i=0; i<token_num; i++)
    {
        if(tokens[i][0]=='\0')
            zerolentok++;
    }
    word_num=token_num-com_num-zerolentok;
    printf("\nNumber of Words            :%d\n", word_num);
    printf("Average Lenth of the Words :%.2f\n",(float)(str_lenth-com_lenth-delim_num)/word_num);
    return 0;
}
