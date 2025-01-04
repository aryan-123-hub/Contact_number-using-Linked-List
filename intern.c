#include"header.h"
#include<stdlib.h>
void edit(SLL **);
void add(SLL **);
void delete(SLL **);
void display(SLL *);
void save(SLL *);
int count(SLL *);

int main()
{
SLL *ptr=0;
int op,c=0;
while(1){
printf("\033[31m 1]Add new contact \n 2]Delete Contact \n 3]Edit Contact \n 4]save in file\n 5]exit \n 6]display\n 7]Count Contact List \033[0m\n");
scanf("%d",&op);
switch(op)
{
case 1:
add(&ptr);
break;
case 2: delete(&ptr);
break;
case 3:
edit(&ptr);
break;
case 4:
save(ptr);
break;
case 5:
exit(0);
break;
case 6:
display(ptr);
break;
case 7:
c=count(ptr);
printf("Total number of contact is %d\n",c);
break;
default :
printf("Invalid choice \n");
break;
}
}
}
/****************************************************************/

void add(SLL **ptr)
{

SLL *new,*temp;
new=malloc(sizeof(SLL));
printf("enter name,phone number and mail id\n");
scanf("%s %ld %s",new->name,&new->mbl,new->mail);
new->next=0;



if(*ptr==0)
*ptr=new;
else
{
 temp=*ptr;
while(temp->next)
temp=temp->next;

temp->next=new;
}
printf("\033[32m Contact saved succesfully\033[0m\n");
}
/***********************************************************************/
void display(SLL *temp)
{
if(temp==0)
{
printf("\033[32m No contacts are there\033[0m \n");
return;
}

while(temp)
{
printf("%s %ld %s\n",temp->name,temp->mbl,temp->mail);
temp=temp->next;
}

}
/***************************************************************************/
int count(SLL *ptr)
{
int c=0;
while(ptr)
{
c++;
ptr=ptr->next;
}
return c;
}
/*****************************************************************************/
 void delete(SLL **ptr)
  {
  int c=0,i;
  c=count(*ptr);
  if(c==0)
  {
  printf("\033[32m No contacts are there to delete \033[0m \n");
  return;
  }
  char name[30];
  printf("enter contact name to delete\n");
  scanf("%s",name);
  SLL *temp=*ptr,*prev=*ptr;
 
 
 
 
  for(i=0;i<c;i++)
  {
  if(strcmp(temp->name,name)==0)
  {
  if(temp==*ptr){
  *ptr=temp->next;
  free(temp);
  }
  else
  {
  prev->next=temp->next;
  free(temp);
  }
  }
 prev=temp;
 temp=temp->next;
}
printf("deleted\n");
}
/*****************************************************************************/

void save(SLL *ptr)
{
FILE *fp=fopen("phonebook","w+");
while(ptr)
{
fprintf(fp,"%s %ld %s\n",ptr->name,ptr->mbl,ptr->mail);
ptr=ptr->next;
}
printf("\033[32m Data saved in file \033[0m\n");
fclose(fp);
}
/*****************************************************************************/
void edit(SLL **ptr)
{
char name[30];
display(*ptr);
printf("enter name to modify/edit the existing contact\n");
scanf("%s",name);
int i,c=count(*ptr);
SLL *temp=*ptr;
for(i=0;i<c;i++)
{
if(strcmp(name,temp->name)==0)
{
printf("enter the Correct information name, mobile number and mail Id\n");
scanf("%s %ld %s",temp->name,&temp->mbl,temp->mail);
}
temp=temp->next;
}
}

/*****************************************************************************/
