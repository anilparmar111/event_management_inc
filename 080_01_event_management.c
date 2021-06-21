#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sugesation();
int main()
{
    int r_no,x,m,k,temp;
    char nm[20],branch[3];
    FILE *fp1,*fp,*fp2;
    fp2=fopen("event.txt","a");
    fp=fopen("registraion.txt","r");
    fseek(fp,0L,2);
    k=ftell(fp);
    fclose(fp);
    printf("\t\t\tWELCOME TO REGISTARTION OF TECH.EVENT 2K19\n\n");
    printf("\t\t\tYOU CAN CHOOSE MORE THAN ONE EVENT. \n\n");
    if(k<=0)
    {
        printf("\t\t\tTOTAL NUMBER OF REGISTARTION IS ---> %d \n\n",0);
        printf("\t\t\tYOU ARE THE FIRST STUDENT OF REGISTARTION  \n\n");
        fp1=fopen("studentno.txt","w");
        fprintf(fp1,"%d",1);
        fclose(fp1);
    }
    else
    {
        fp1=fopen("studentno.txt","r");
        fscanf(fp1,"%d",&m);
        printf("\t\t\tTOTAL NUMBER OF REGISTARTION IS = %d \n\n",m);
        fclose(fp1);
        fp=fopen("registraion.txt","r");
        printf("\t\t\tSTUDENT'S ARE --->\n\n");
        while(!feof(fp))
        {
            fscanf(fp,"%s %s %d",nm,branch,&r_no);
            printf("\t\t\t%s %s %d\n\n",nm,branch,r_no);
        }
        fclose(fp);
        fp1=fopen("studentno.txt","w");
        fprintf(fp1,"%d",(m+1));
        fclose(fp1);
    }
    printf("\t\t\tENTER YOUR NAME BRANCH AND ROLLNO.\n\n");
    fp=fopen("registraion.txt","a");
    fscanf(stdin,"%s%s%d",nm,branch,&r_no);
    fprintf(fp,"%s %s %d",nm,branch,r_no);
    fclose(fp);
    printf("\t\t\tTHESE ARE THE EVENT ------->\n\n");
    printf("\t\t\t[1].ROBOT RECE        \t[2].CPROGRAMING CHALLANGE\n\n");
    printf("\t\t\t[3].MACHINE LERNING \t[4].BUILD BILDING\n\n");
    printf("\t\t\t[5].CIRCUIT DESIGN  \t[6].CONTRAL SYSTEM MANGEMENT\n\n");
    printf("\t\t\t[7].WEB DEVLOPMENT  \t[8].TYPING SPEED CHALENGER\n\n");
    if(k>0)
    {
        sugesation();
    }
    while(1)
    {
        temp=scanf("%d",&x);
        if(temp==-1)
        {
            break;
        }
        putw(x,fp2);
    }
    fclose(fp2);
}
void sugesation()
{
    FILE *fp2;
    fp2=fopen("event.txt","r");
    int s[8]={0},x;
    while(!feof(fp2))
    {
        x=getw(fp2);
        switch (x)
        {
        case 1:
            s[0]++;
            break;
        case 2:
            s[1]++;
            break;
        case 3:
            s[2]++;
            break;
        case 4:
            s[3]++;
            break;
        case 5:
            s[4]++;
            break;
        case 6:
            s[5]++;
            break;
        case 7:
            s[6]++;
            break;
        case 8:
            s[7]++;
            break;
        }
    }
    int max=0,index,i,j;
    for(i=0;i<8;i++)
    {
        if(max<s[i])
        {
            max=s[i];
        }
    }
    for(i=0;i<8;i++)
    {
        if(s[i]==max)
        {
            index=i+1;
            break;
        }
    }
    printf("STUDENT'S ARE SUGGEST FOR %d EVENT \n\n",index);
    fclose(fp2);
}