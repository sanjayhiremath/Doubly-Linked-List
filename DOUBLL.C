#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
#define PF printf
#define SF scanf
struct cnode
{
 int info;
 struct cnode *lptr,*rptr;
};
void newnode();
struct cnode *start,*cur,*temp;
void delpos();
void create();
void insertbeg();
void insertend();
void insertafter();
void insertbefore();
void rev();
void insertpos();
void search();
void delete1();
void display();
void erase();
void newnode();
void count();
void reverse();
void sort();
void insasc();
void insdesc();
main()
{
int ch,i;
start=NULL;
  while(1)
  {
   clrscr();
   PF(".............................DOUBLY LINKED LIST.........................");
   PF("\nPRESS 1:     CREATE\nPRESS 2:     INSERT AT BEGINNING\nPRESS 3:     INSERT AT END\nPRESS 4:     INSERT AFTER\nPRESS 5:     INSERT BEFORE\nPRESS 6:     INSERT AT GIVEN POSITION\nPRESS 7:     COUNT THE NODES\nPRESS 8:     SEARCH THE NODE\nPRESS 9:     DELETE NODE\nPRESS 10:    DISPLAY REVESE LINKED LIST\nPRESS 11:    REVERSE THE LIST\nPRESS 12:    DISPLAY LINKED LIST\nPRESS 13:    DESTROY LINKED LIST\nPRESS 14:    SORT THE LIST\nPRESS 15:    INSERT IN ASCENDING\nPRESS 16:    INSERT IN DESCENDING\nPRESS 17:    DELETE ATE GIVEN POSITION\nPRESS 0:     EXIT");
   PF("\nENTER YOUR CHOICE:");
   SF("%d",&ch);
   switch(ch)
   {
     case 0:exit(0);
     case 1:create();       break;
     case 2:insertbeg();    break;
     case 3:insertend();    break;
     case 4:insertafter();  break;
     case 5:insertbefore(); break;
     case 6:insertpos();    break;
     case 7:count();        break;
     case 8:search();       break;
     case 9:delete1();      break;
     case 10:reverse(start);     break;
     case 11:rev();        break;
     case 12:display();     break;
     case 13:erase();       break;
     case 14:sort();        break;
     case 15:insasc();      break;
     case 16:insdesc();     break;
     case 17:delpos();      break;
     default:PF("\nWrong Choice");
   }
     getch();
  }
}
void newnode()
{
 cur=(struct cnode*)malloc(sizeof(struct cnode));
 if(cur==NULL)
 {
  PF("\nSORRY..MEMORY NOT AVAILABLE...");
  return;
 }
 PF("Enter info ");
 SF("%d",&cur->info);
 cur->lptr=cur->rptr=NULL;
}

void create()
{
 int n,i;
 PF("Enter how much nodes you want to create ");
 SF("%d",&n);
 for(i=1;i<=n;i++)
 {
   newnode();
 //insert new node at end
   if(i==1)
   {
     start=cur;
//     start->nxt=NULL;

   }
   else
   {
    temp->rptr=cur;
      cur->lptr=temp;
    }
   temp=cur;
  }

  //insert cur node at beginning

/* if(i==1)
   {
     start=cur;
     start->rptr=NULL;
   }
   else
   {
   cur->rptr=temp;
   temp->lptr=cur->rptr;
    }
   temp=cur;
 }
 start=temp;*/
  PF("\nLINKED LIST IS CREATED....");

}
void insertbeg()
{
newnode();
 if(start==NULL)
 {
   start=cur;

   PF("\n%d IS SUCCESSFULLY INSERTED AT BEGINNING..",cur->info);
  return;
 }
 cur->rptr=start;
 start->lptr=cur;
 start=cur;
  PF("\n%d IS SUCCESSFULLY INSERTED AT BEGINNING..",cur->info);
}
void insertend()
{
   newnode();
   if(start==NULL)
 {
   start=cur;
    PF("\n%d IS SUCCESSFULLY INSERTED AT END..",cur->info);
  return;
 }
 temp=start;
 while(temp->rptr!=NULL)
 {
  temp=temp->rptr;
 }
  temp->rptr=cur;
  cur->lptr=temp;

   PF("\n%d IS SUCCESSFULLY INSERTED AT BEGINNING..",cur->info);
}

void insertafter()
{
   struct cnode *t,*nxt1;
   int se,pos;
   if(start==NULL)
   {
    PF("\nLL IS EMPTY");
    return;
   }
    pos=0;
    t=start;

   PF("\nENTER INFO AFTER YOU WANT TO INSERT:");
   SF("%d",&se);

   while(t!=NULL)
   {
     if(t->info==se)
     {
       newnode();
       /*cur->rptr=t->rptr;
       t->rptr->lptr=cur->rptr;
       t->rptr=cur;
       cur->lptr=t->rptr;
	 */
       nxt1=t->rptr;
       t->rptr=cur;
       cur->lptr=t->rptr;
       cur->rptr=nxt1;
       nxt1->lptr=cur->rptr;

       PF("\n%d IS PROPERLY  INSERTED AFTER %d.",cur->info,se);
       return;
     }
     t=t->rptr;
   }
	  PF("\n%d IS NOT PRESENT IN LINKED LIST..",se);
}

void insertbefore()
{
 struct cnode *t,*nxt1;
   int se,pos;
   if(start==NULL)
   {
    PF("\nLL IS EMPTY");
    return;
   }
    t=start;
   PF("\nENTER INFO BEFORE YOU WANT TO INSERT:");
   SF("%d",&se);

   if(se==start->info)
   {
	insertbeg();
	return;
   }

   while(t->rptr!=NULL)
   {
     if(t->rptr->info==se)
     {
	newnode();
	  nxt1=t->rptr;
       t->rptr=cur;
       cur->lptr=t->rptr;
       cur->rptr=nxt1;
       nxt1->lptr=cur->rptr;

       PF("\nPROPERLY INSERTED BEFORE %d.",se);
       return;
     }
     t=t->rptr;
   }
	  PF("\n%d IS NOT PRESENT IN LINKED LIST..",se);
}

void insertpos()
{
 int pos,i=1;
 struct cnode *t;
 if(start==NULL)
 {
  PF("\nSORRY LINKED LIST IS EMPTY...");
  return;
 }
 PF("\nENTER POSITION IN WHICH YOU WANT TO INSERT A NODE(START AT 1):");
 SF("%d",&pos);
 if(pos==1 || pos==0)
 {
  insertbeg();
 // PF("\n%d IS PROPERLY INSERTED AT POS %d",cur->info,pos) ;
 return;
 }
 t=start;
while(i!=pos-1)
{
  t=t->rptr;
  i++;
}
if(t==NULL)
{
 PF("\nNOT A PROPER POSITION");
 return;
}
       newnode();
       cur->rptr=t->rptr;
       t->rptr->lptr=cur->rptr;
       t->rptr=cur;
       cur->lptr=t->rptr;
  PF("\n%d IS PROPERLY INSERTED AT POS %d",cur->info,pos) ;
}

void sort()
{
 struct cnode *p,*q,*r,*s,*end;
 int i,t;
 if(start==NULL)
 {
  PF("\nLINKED LIST IS NOT AVAILABLE...");
  return;
 }
//selection sort by exchanging data
 for(p=start;p->rptr!=NULL;p=p->rptr)
 {
   for(q=p->rptr;q!=NULL;q=q->rptr)
   {
     if(p->info>q->info)
     {
       t=p->info;
       p->info=q->info;
       q->info=t;
     }
   }
 }

 //by rearranging links
/*  for(r=p=start;p->nxt!=NULL;r=p,p=p->nxt)
 {
   for(s=q=p->nxt;q!=NULL;s=q,q=q->nxt)
   {
     if(p->info>q->info)
     {
       t=p->info;
       p->info=q->info;
       q->info=t;
       if(p!=start)
	  r->nxt=q;
      else

       s->nxt=p;
       if(p==start)
	  start=q;
	t=p;
	p=q;
	q=t;
     }
   }
 }*/
 //bubble sort

/* for(end=NULL;end!=start->nxt;end=q)
 {
   for(p=start;p->nxt!=end;p=p->nxt)
   {
     q=p->nxt;
     if(p->info>q->info)
     {
       t=p->info;
       p->info=q->info;
       q->info=t;
     }
   }
 }
 */

 PF("\nLINKED LIST IS SORTED PRESS 1 TO DISPLAY LINKED LIST..");
 SF("%d",&i);
 if(i==1)
 {
  display();
 }
}

void count()
{
int i=0;
struct cnode *t;

if(start==NULL)
{
  PF("\nLINKED LIST IS EMPTY...");
  return;
}
t=start;
while(t!=NULL)
{
  i++;
  t=t->rptr;
}
PF("NUMBER OF NODES IN LINKED LIST=%d",i);
}
void search()
{
struct cnode *t;
 int se,i;
 if(start==NULL)
 {
  PF("\nLINKED LIST IS NOT AVAILABLE...");
  return;
 }
 i=0;
 PF("\nENTER SEARCH ELEMENT");
 SF("%d",&se);
 t=start;
 while(t!=NULL)
 {
  i++;
  if(t->info==se)
  {
    PF("%d IS FOUND AT %d LOCATION.",se,i);
    return;
  }
    t=t->rptr;
 }
       PF("%d IS NOT FOUND IN LINKED LIST",se);
}


void delete1()
{
  int pos;
  struct cnode *t;
  struct cnode *pr,*nxt;
  if(start==NULL)
 {
  PF("\nSORRY LINKED LIST IS EMPTY...");
  return;
 }
 PF("\nENTER ELEMENT YOU WANT TO DELETE..");
 SF("%d",&pos);
 pr=t=start;
 if(pos==start->info)
 {
  start=start->rptr;
  start->lptr=NULL;
  free(t);
  return;
 }

 while(t!=NULL)
 {
  if(pos==t->info)
  {
   pr=t->lptr;
   nxt=t->rptr;
   pr->rptr=nxt;
   if(t->rptr!=NULL)
   nxt->lptr=pr;
    free(t);
       PF("%d IS SUCCESSFULLY DELTETED FROM LINKED LIST.",pos);
    return;
  }
  pr=t;
  t=t->rptr;
 }
       PF("%d IS NOT PRESENT IN LINKED LIST.",pos);
}

void reverse(struct cnode *te)
{
  if(te==NULL)
  {
   return;
  }
   reverse(te->rptr);
   PF("->%d\t",te->info);
}

void display()
{
struct cnode *tr;
if(start==NULL)
{
  PF("List is not available");
  return;
}
tr=start;
PF("\nSTART->");
while(tr!=NULL)
{
PF("%d->",tr->info) ;
tr=tr->rptr;
}
PF("NULL");
}

void erase()
{
  struct cnode *t;
  if(start==NULL)
  {
  PF("List is not available");
  return;
  }
 t=start;
/* do {
   t=start;
   start=start->rptr;
   free(t);
  } while(start!=NULL);*/
   while(start!=NULL)
   {
   t=start;
   start=start->rptr;
   free(t);
  }
 PF("linked list is destroyed");
}
void rev()
{

 struct cnode *p1,*p2;
 int i;
 if(start==NULL)
 {
  PF("\nLL IS NOT PRESENT..");
  return;
 }

 p1=start;
 p2=p1->rptr;
 p1->rptr=NULL;

 p1->lptr=p2;
 while(p2!=NULL)
 {
  p2->lptr=p2->rptr;
  p2->rptr=p1;
  p1=p2;
  p2=p2->lptr;
 }
 start=p1;
 PF("\nLINKED LIST IS REVERSED PRESS 1 TO DISPLAY LINKED LIST..");
 SF("%d",&i);
 if(i==1)
 {
   display();
 }
}
void insasc()
{
  int n,i;
  struct cnode *t;
 PF("Enter how much nodes you want to create ");
 SF("%d",&n);
 for(i=1;i<=n;i++)
 {
   newnode();
  if(start==NULL)
  {
    start=cur;
  //  PF("\n%d is inserted according to priority",cur->d);
  }
  else
   if( cur->info<=start->info){
     cur->rptr=start;
    start->lptr=cur;
    start=cur;
    }
else{
 t=start;
 //we have to locate t in a such a way that cur->p
 //should be greater than t->p
 while(t->rptr!=NULL && t->rptr->info<=cur->info)
   t=t->rptr;

  cur->rptr=t->rptr;
  t->rptr->lptr=cur->rptr;
  t->rptr=cur;
  cur->lptr=t->rptr;
  }
 }
  PF("\nLinked list is created.");
 }
void insdesc()
{
  int n,i;
  struct cnode *t;
  start=NULL;
 PF("Enter how much nodes you want to create ");
 SF("%d",&n);
 for(i=1;i<=n;i++)
 {
   newnode();
  if(start==NULL || cur->info>start->info)
  {
      cur->rptr=start;
    start->lptr=cur;
    start=cur;

  //  PF("\n%d is inserted according to priority",cur->d);
  }
else{
 t=start;
 //we have to locate t in a such a way that cur->p
 //should be greater than t->p
 while(t->rptr!=NULL && t->rptr->info>=cur->info)
   t=t->rptr;


  cur->rptr=t->rptr;
  t->rptr->lptr=cur->rptr;
  t->rptr=cur;
  cur->lptr=t->rptr;

  }
 }
  PF("\nLinked list is created.");
 }
void delpos()
{
 int i,pos=0,u=0;
 struct cnode *ptr,*t;
 if(start==NULL)
 {
  PF("\nSORRY..CREATE LINKED LIST FIRST");
  return;
 }
 PF("\nENTER POSITION OF NODE YOU WANT TO DELETE");
 SF("%d",&pos);
 t=start;
 while(t!=NULL)
 {
  u++;
  t=t->rptr;
 }
 if(pos>u)
 {
   PF("\nNOT A PROPER POSITION TRY AGAI...");
   return;
 }
 t=start;
 if(pos==1 || pos==0)
 {
  start=start->rptr;
  free(t);
  return;
 }
 ptr=start;
 for(i=1;i<pos;i++)
 {
   t=ptr;
   ptr=ptr->rptr;
 }
 t->rptr=ptr->rptr;
 ptr->lptr=t->rptr;
 free(ptr);
}

