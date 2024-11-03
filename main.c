#include<stdio.h>
FILE *fp;
int cd=0,cn=0;
char title[20],aut[20],gen[10],frm[10],dsc[100];
void getdata();
void sreachdata();
void display();
void sortcataog();
struct data{
 int cn;
 char title[20];
 char aut[20];
 char gen[10];
 char frm[10];
 char dsc[30];
}d;
//ADDING DATA FUNCTION
void getdata()
      {
       printf("Enter Data <BOOK-NUMBER> <TITTLE> <AUTHOR> <GENRE> <FORMAT> <DESCRIPTION> :\n");
       scanf("%d%s%s%s%s%s",&d.cn,&d.title,&d.aut,&d.gen,&d.frm,&d.dsc);
       //opening file to write data
       fp=fopen("db.txt","a");
       fprintf(fp,"%d %s %s %s %s %s\n",d.cn,d.title,d.aut,d.gen,d.frm,d.dsc);
       fclose(fp);
       printf("\n\nAdded Sucessfully\n\n");
      }
//SEARCHING DATA FUNCTION
void searchdata()
    {
      int scn,c=0;
      printf("Enter Item Catalog no to srearch : ");
      scanf("%d",&scn);
      fp=fopen("db.txt","r");
      fseek(fp,0,SEEK_END);
      cd=ftell(fp);      //getting the last position of filpointer in cd
      fseek(fp,0,SEEK_SET);
      printf("Cat.Num\tTitle\t\tAuthor\tGenre\tFormat\tDiscroption");
      printf("\n---------------------------------------------------");
      while(ftell(fp)!=cd)
       {
         fscanf(fp,"%d %s %s %s %s %s",&cn,&title,&aut,&gen,&frm,&dsc);
         if(cn==scn)
          {
           printf("\n%d\t%s\t\t%s\t%s\t%s\t%s",cn,title,aut,gen,frm,dsc);
           c=1;
          }
        }
     if(c==0) printf("\n\nNOT FOUND !!!\n\n");
     fclose(fp);
    }
//DISPLAYING DATA FUNCTION
void display()
       {
         fp=fopen("db.txt","r");
         fseek(fp,0,SEEK_END);
         cd=ftell(fp);
         fseek(fp,0,SEEK_SET);
         printf("\n\nALL CATALOG ITEM :\n\n");
         printf("Cat.Num\tTitle\t\tAuthor\tGenre\tFormat\tDiscroption");
         printf("\n------------------------------------------------------------");
         while(ftell(fp)!=cd)
         {  fscanf(fp,"%d %s %s %s %s %s",&cn,&title,&aut,&gen,&frm,&dsc);
      printf("\n%d\t%s\t\t%s\t%s\t%s\t%s",cn,title,aut,gen,frm,dsc);
         }
         fclose(fp);
       }
//SORTING DATA FUNCTION
void sortcatalog()
       {
       char ch;
       int c=0,i=0;
       struct data *ds;
       struct data *dn;
       fp=fopen("db.txt","r");

        ch=getc(fp);
         while(ch!=EOF)
         {
       if(ch=='\n')
       c++;
       ch=getc(fp);
         }
       fclose(fp);
       ds=(struct data*)malloc(c*sizeof(struct data));
       dn=ds;
       fp=fopen("db.txt","r");
       for(i=0;i<c;i++)
       {	 fscanf(fp,"%d %s %s %s %s %s",&ds->cn,ds->title,ds->aut,ds->gen,ds->frm,ds->dsc);
     ds++;

       }
       ds=dn;
        printf("Cat.Num\tTitle\t\tAuthor\tGenre\tFormat\tDiscroption");
         printf("\n---------------------------------------------------------------");
       for(i=0;i<c;i++)
       { if(strcmp("book",ds->frm)==0)
         printf("\n%d\t%s\t\t%s\t%s\t%s\t%s",ds->cn,ds->title,ds->aut,ds->gen,ds->frm,ds->dsc);
         ds++;
       }
       ds=dn;
       for(i=0;i<c;i++)
       { if(strcmp("cd",ds->frm)==0)
         printf("\n%d\t%s\t\t%s\t%s\t%s\t%s",ds->cn,ds->title,ds->aut,ds->gen,ds->frm,ds->dsc);
         ds++;
       }
       ds=dn;
       for(i=0;i<c;i++)
       { if(strcmp("dvd",ds->frm)==0)
         printf("\n%d\t%s\t\t%s\t%s\t%s\t%s",ds->cn,ds->title,ds->aut,ds->gen,ds->frm,ds->dsc);
         ds++;
       }
       ds=dn;
       for(i=0;i<c;i++)
       { if(strcmp("ebook",ds->frm)==0)
         printf("\n%d\t%s\t\t%s\t%s\t%s\t%s",ds->cn,ds->title,ds->aut,ds->gen,ds->frm,ds->dsc);
         ds++;
        }
       ds=dn;
       printf("\n\nList of items that fall behind the known format:\n");
       for(i=0;i<c;i++)
       { if(strcmp("book",ds->frm)&&strcmp("cd",ds->frm)&&strcmp("dvd",ds->frm)&&strcmp("ebook",ds->frm)!=0)
         printf("\n%d\t%s\t\t%s\t%s\t%s\t%s",ds->cn,ds->title,ds->aut,ds->gen,ds->frm,ds->dsc);
         ds++;
       }
       ds=dn;
       }
//MAIN FUNCTION
void main()
{
 int ch=0;
  char cha;
  printf("\n\nPrepared by Group-1 for PBL (FY-CSBS)\n\n");
 menu:printf("PLEASE ENTER SMALL LETTER ONLY, CAPS NOT ALLOWED\n\nPress Enter to continue...");
 scanf("%c",&cha);
 printf("\n\n******MAIN MENU*******");
 printf("\n1. ADD\n2. DISPLAY ITEM\n3. DISAPLAY CATALOG\n4. DISPLAY SORTED CATALOG\n5. EXIT\n\nENTER YOUR CHOICE : ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:  getdata();
    goto menu;
 case 2:  searchdata();
    goto menu;
 case 3:  display();
    goto menu;
 case 4:  sortcatalog();
    goto menu;
 case 5:  goto z;
 default: printf("\n\n****WRONG CHOICE TRY AGAIN***");
    goto menu;
}
 z:printf("\n\n****PRESS ANY KEY TO EXIT !!******");
}
