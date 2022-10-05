#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ERROR -1
char num1[50],num2[50];
char cmd[102];
char d;//operation
int len1=0,len2=0,len3=0;
void add(char* a,char* b,char* c,int l1,int l2,int l3)
{
    int p=0,q,l4=0,i=0;
    l3=l3-1;
    l1=l1-1;
    l2=l2-1;
    for(i=0;i<=l3-1;i++)
        c[i]=0;
    for(l1,l2;(l1>=0)||(l2>=0);l1--,l2--)
    {
        if(l1>=0&&l2>=0)
        {c[l3-p]=a[l1]+b[l2];
        p++;}
        else
        {if(l1>=0)
        c[l3-p]=a[l1];
        else
        c[l3-p]=b[l2];
        p++;}
    }
    for(q=l3;q>0;q--)
    {
        if(c[q]>=10)
        {c[q-1]=c[q-1]+c[q]/10;
        c[q]=c[q]%10;}
    }
    


}
int compare(char* a,char* b,int l1,int l2,int l3)
{
    int i=0;
    if(l1>l2)
    return 1;
    else if(l1<l2)
    return 0;
    else 
    {
            for(i=0;i<l1;i++)
            {
                    if(a[i]>b[i])
                    return 1;
                    else if(a[i]<b[i])
                    return 0;
            }
            if(i==l1)
            return -1; // same numbers
    
    }
}

int subract(char* a,char* b,char* c,int l1,int l2,int l3)
{
    int i,j,greater;
    greater=compare(a,b,l1,l2,l3);
    l3=l3-1;
    for(i=0;i<=l3-1;i++)
        c[i]=0;
    if(greater==1)
    {
        for(i=l1-1,j=l2-1;i>=0;i--,j--)///change this 
        {
            if(j>=0)
            {if(a[i]-b[j]<0)
            {   if(i>=1)
                a[i-1]--;
                a[i]=a[i]+10-b[j];
            }
            else
            a[i]=a[i]-b[j];
            }
            else
            {
                if(a[i]<0)
                {
                    if(i>=1)
                    a[i-1]--;
                a[i]=a[i]+10;
                }

            }

        }

        for(i=l3,j=l1-1;j>=0;j--,i--)
        c[i]=a[j];
       
       if(a[0]==0)
       {
           for(j=0;!a[0];j++)
           {for(i=0;i<l1-1;i++)
           {
               a[i]=a[i+1];
           }
           if(l1>=1)
           {l1--;}
           }
       }   

       return l1;
    
    }

    else if(greater==0)
    {
        printf("-");
        for(i=l1-1,j=l2-1;j>=0;i--,j--)///chang this 
        {
            if(i>=0)
            {
            if(b[j]-a[i]<0)
            {   
                if(j>=1)
                b[j-1]--;
                b[j]=b[j]+10-a[i];
            }
            else
            b[j]=b[j]-a[i];
            }
            else
            {
                if(b[j]<0)
                {   if(j>=1)
                    b[j-1]--;
                b[j]=b[j]+10;

                }
            }

        }
        for(i=l3,j=l2-1;j>=0;j--,i--)
        c[i]=b[j];


    }

    else 
    {
        a[0]=0;
        l1=0;
        return l1;
    }


    
}
void multiply(char* a,char* b,char* c,int l1,int l2,int l3)
{
    char temp[l3];

    int i, j, k, p = 0,m=0,l4=0;
    for(i=0;i<=l3-1;i++)
        c[i]=0;
    

    for(i=l1-1;i>=0;i--)
    {
        for(p=0;p<l3;p++)
        {temp[p]=0;}
        for(j=l2-1,p=l3-1;j>=0;j--,p--)
        {temp[p]=b[j]*a[i];}
        for(k=0;k<(l1-1)-i;k++)
        {
            for(p=0;p<l3-1;p++)
            temp[p]=temp[p+1];
            
            temp[l3-1]=0;
        }
        for(p=l3-1;p>0;p--)
        {
            if(temp[p]>=10)
            {
                temp[p-1]=temp[p-1]+(temp[p]/10);
                temp[p]=temp[p]%10;
            }
            else
            {temp[p]=temp[p];}
            if(c[p]+temp[p]>=10)
            {
                c[p-1]+=((temp[p]+c[p])/10);
                c[p]=(c[p]+temp[p])%10;
                
            }
            else
           { c[p]=c[p]+temp[p];}
        }
        c[0]=c[0]+temp[0];
    }

}



int divide(char* a,char* b,char* c,int l1,int l2,int l3)
{
    int i=0,j=0,k=0,greater=0,flag=0,subLEN=0;
     char temp[50],temp2[50],temp1[50],justC[l3];
     for(i=0;i<l2;i++)
     temp2[i]=b[i];
     for(i=0;i<l3;i++)
     c[i]=0;

     for(i=0;i<l2;i++)
     {if(b[i]!=0)
     break;}
     if(i==l2)
    return ERROR;

    greater=compare(a,b,l1,l2,l3);
    if(greater==1)
    {
        subLEN=l2;
       for(k=0;compare(a,b,l1,l2,l3);k++)
       {
           for(i=0;i<50;i++)
            temp2[i]=b[i];
            for(i=0;i<50;i++)
            temp1[i]=0;
            
            subLEN=l2;

        for(i=1;i<l1-l2;i++)
        {
            temp2[subLEN]=0;
            subLEN++;
            
        }
       for(i=1;i<=l1-l2;i++)
       {
           temp[i-1]=0;

       }
       temp[0]=1;
       int t=i-1;
       if(t==0)
       t=1;
       
       l1=subract(a,temp2,justC,l1,subLEN,l3);
       flag=0;
       j=0;
       for(i=0;i<l3;i++)
       {
           if(c[i]||flag)
            {
                temp1[j]=c[i];
                j++;
                flag=1;
            }

       }
       add(temp,temp1,c,t,j,l3);


       }
       printf("\nremainder: ");
       for(i=0;i<l1;i++)
       {printf("%d",a[i]);}
       if(l1==0)
       printf("0");
       printf("\nQuotient");
    return 0;

    }

    else if(greater==0)
    {printf("\nremainder: ");
    for(i=0;i<l1;i++)
    printf("%d",a[i]);
    printf("\nquotient\n");
    return 0;
    }
    else if(greater==-1)
    {
            printf("\nremainder: 0\n");
            printf("quotient\n");
            c[l3-1]=1;
            //return 0;

    }
    else
    return ERROR;
}

int print_result()
{
    int i=0,flag=0;
    int l3=sizeof(cmd);
     printf("\n");

     if(cmd[0]==ERROR)
     return ERROR;
        for(i=0;i<=l3-1;i++)
        {
            if(cmd[i]||flag)
            {
                printf("%d",cmd[i]);
                flag=1;
            }
        }

        if(flag==0)
        printf("0");


}

int do_operation(char* a,char* b,char* c,int l1,int l2,int l3,char d)
{
int flag=0,i=0;


        if(d=='+')
        add(a,b,c,l1,l2,l3);
        else if(d=='-')
        subract(a,b,c,l1,l2,l3);
        else if(d=='*')
        multiply(a,b,c,l1,l2,l3);
        else if(d=='/')
        i=divide(a,b,c,l1,l2,l3);
       else
       return ERROR;
        
        if(i==ERROR)
        return ERROR;

       
       
        
}

int get_command(char* c)
{
    int i,j,k;
    
        int flag=0;
        printf("\ncalc>");
        len3=sizeof(cmd);
        for(i=0;i<102;i++)
        cmd[i]=0;
        fflush(stdin);
        gets(cmd);
        if(strcmp(cmd,"Exit")==0)
        return 0;
        for(i=0;cmd[i];i++)
        {
            if(flag==0&&cmd[i]>47&&cmd[i]<58)
            {
                num1[len1]=cmd[i]-48;
                len1++;
            }
            else if(flag==1&&cmd[i]>47&&cmd[i]<58)
            {num2[len2]=cmd[i]-48;
                len2++;
            }
            else if(flag==0&&i)
            {
                d=cmd[i];
                flag++;
            }

            else
            {printf("invalid inputs\n");
            flag=-1;
            return ERROR;
            break;}
        }

        return 1;

}

int find_operation(char d)
{
    if(d=='*'||d=='+'||d=='-'||d=='/')
    return 1;
    else
    return ERROR;
}
int main()
{


    int i;

    while(1)
    {
        for(i=0;i<50;i++)
        num1[i]=0;
        for(i=0;i<50;i++)
        num2[i]=0;
        for(i=0;i<102;i++)
        cmd[i]=0;
        len1=0;len2=0;len3=0;

        i=get_command(cmd);

        if(i==0)
       { 
           exit(0);
       }// EXIT command given
        else if(i==ERROR)
        {
            printf("wrong command\n");
        exit(0);
        }
        
        if(find_operation(d)==ERROR)
        {printf("could not find operation\n");
         exit(0);}
         

        if(do_operation(num1,num2,cmd,len1,len2,len3,d)==ERROR)
        {printf("unable to perform operation or invalid number entered or divide by zero is asked\n");
        //exit(0);
        continue;
        }
        


        if(print_result()==ERROR)
        {printf("unable to print result\n");
        exit(0);
        }

        

    }
return 0;
   
}