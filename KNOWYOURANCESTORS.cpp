//ALGORITHM PROJECT
//TOPIC: KNOW YOUR ANCESTOR
// ANSHIKA SINGHAL (14103253)
//SOMYAA AGARWAL(14103230)
// MINI AGGARWAL(14103223)




#include<iostream>
#include<string>


using namespace std;

//global variables
int match=1;
int miss=-1;
int gap=-1;



// FORMATION OF DOUBLY MULTI LINK LIST
typedef struct character{

string a;
struct character *next;
struct character *back1;


}character;


typedef struct sequence{

struct sequence *down;
struct character *start;
struct character *end1;
struct sequence *back1;
int index;
int count1;

}sequence;




typedef struct list{

struct sequence *start;
struct sequence *end1;


}list;


character* create_character(string a1)
{
 character *c2= new character();
 c2->next=NULL;
 c2->back1=NULL;


 c2->a=a1;

 return(c2);
}

sequence *create_sequence(int index)
{
 sequence *s2=new sequence();
 s2->start=NULL;
 s2->end1=NULL;
 s2->down=NULL;
 s2->index=index;
 s2->back1=NULL;
 s2->count1=0;
 return(s2);
}


sequence*  insert_sequence(list *ll,int index){


sequence *node1=create_sequence(index);
if(ll->start==NULL)
  {
   ll->start=node1;
   ll->end1=node1;

  }
 else
  {

   ll->end1->down=node1;
   node1->back1=ll->end1;
   ll->end1=node1;


  }


 return(node1);

}



void insert_character(sequence *s,string a)
{

 character *c1=create_character(a);
 if(s->start==NULL)
  {
    s->start=c1;
    s->end1=c1;

  }
 else
 {

   s->end1->next=c1;
   c1->back1=s->end1;
   s->end1=c1;

  }
(s->count1++);

}


void display(list *ll){

	sequence * temp;temp=ll->start;
	character* temp1;




	while(temp!=NULL){
			temp1=temp->start;
//debug
            cout<<endl<<temp->index<<endl;
            cout<<endl<<endl<<temp->count1;
			while(temp1!=NULL){
            cout<<"\n"<<temp1->a;
			temp1=temp1->next;

			}
			cout<<"\n";
			temp=temp->down;

	}

}

list* init()
{

    list *l1=new list();
    l1->start=NULL;
        l1->end1=NULL;
        return l1;
}

list *l1=init();

//MODIFIED NEEDLEMAN WUNSCH ALGORITHM (using linklist)
//global
int max_score=-1000;
int max_index1;
int max_index2;
int ptr1[100][100];
int m1=0,n1=0;

int maxvalue(int a,int b,int c)
{
int d=0;
 d = c > (a > b ? a : b) ? c : ((a > b) ? a : b);
 return d;
 }
 int maxindex(int a,int b,int c)
{
int d=0;
 d = c > (a > b ? a : b) ? c : ((a > b) ? a : b);

 if(d==a)
 return 0;
 if(d==b)
 return 1;
 if(d==c)
 return -1;
//written according to priority :diognal>left>upper in case all three are equal



return 200;
 }




void new_global(sequence * s1, sequence *s2){
int m=s1->count1;
int n=s2->count1;
int i,j,p,q;
character *temp=new character();
character *temp1=new character();
temp=s1->start;
temp1=s2->start;


int matrix[m+1][n+1];
int ptr[m+1][n+1];
int subs[m][n];

for(i=0;i<m+1;i++)
{
for(j=0;j<n+1;j++)
{
matrix[i][j]=0;
ptr[i][j]=0;

}
}
int count2=0;
temp=s1->start;
//fill the sustitution matrix

for(i=0;i<m;i++)
{
    temp1=s2->start;

for(j=0;j<n;j++)
{
    count2=0;p=0;q=0;
	for(int p=0;p<(temp->a).size();p++)
	{
	   for(int q=0;q<(temp1->a).size();q++)
	   {


	       if(temp->a[p]==temp1->a[q])
		   {count2++;


	       }
	       if(count2>0) break;
	   }


	}



	if(count2>0)
		subs[i][j]=match;
	else
		subs[i][j]=miss;



    temp1=temp1->next;
}

temp=temp->next;

}




//fill the first rwo and first column of score matrix in case of needleman algorithm
i=0;j=0;
while(i==0){
	for(j=1;j<n+1;j++)
		{
			matrix[i][j]=matrix[i][j-1]+gap;
			if(j==n) i=1;
		}

}



j=0;i=0;
while(j==0){
	for(i=1;i<m+1;i++)
		{
				matrix[i][j]=matrix[i-1][j]+gap;
					if(i==m) {j=1;}

				}

}

int diognal;//represented by 0
int left;//represented by 1
int up;//represented by -1



//scoring of the matrix

for(i=1;i<m+1;i++)
{
for(j=1;j<n+1;j++){

 diognal=matrix[i-1][j-1]+subs[i-1][j-1];
 left=matrix[i][j-1]+gap;
 up=matrix[i-1][j]+gap;
	ptr[i][j]=maxindex(diognal,left,up);
	matrix[i][j]=maxvalue(diognal,left,up);


}
}

cout<<endl;
cout<<"::::::scoring matrix:::::"<<endl;
for(i=0;i<m+1;i++){
	for(j=0;j<n+1;j++){
		cout<<matrix[i][j]<<"  ";
	}
	cout<<endl;
	cout<<endl;

}

cout<<endl;
cout<<"::::::pointer matrix:::::::::"<<endl;
        for(i=0;i<m+1;i++){
            for(j=0;j<n+1;j++){
                cout<< ptr[i][j]<<"  ";
            }
            cout<<endl;
        }


	// calculating the max score
	int score=0;
	score=matrix[m][n];
    if(max_score<score)
	  {
	    max_score=score;
		max_index1=s1->index;
		max_index2=s2->index;

		// copying the ptr of max score sequenessss!


		for(int x=0;x<m+1;x++)
		{
		  for(int y=0;y<n+1;y++)
		  {
		  ptr1[x][y]=ptr[x][y];
		  }

		  }

		  m1=m;
		  n1=n;
    }

//debug

cout<<"\n\n ::::::::max_score::::::: \n"<<max_score;
cout<<"\n\n ::::::::score::::::::::::::\n"<< score;
cout<<"\n\n :::::::::index1:::::::::::::\n"<<max_index1;
cout<<"\n \n:::::::::index 2::::::::::\n"<<max_index2;


}
// FOR TRACING BACK THE BEST ALLIGNMENT
//global variables
list *l2= init();
sequence * x1=new sequence();
sequence * x2=new sequence();

void insert_bet(string a1,sequence * temp)
{



    character *c1=create_character(a1);

	if(temp->start==NULL)
       {

        temp->start=c1;
        temp->end1=c1;


       }

    else{
temp->start->back1=c1;
c1->next=temp->start;
temp->start=c1;



    }
(temp->count1)++;

}



sequence*  search_sequence(int y)
{
    sequence *temp=new sequence();
    temp=l1->start;
    while(temp->down!=NULL){
            if(temp->index==y) return temp;

            temp=temp->down;
    }
    return temp;

}




void traceback()
{
    int i=m1,j=n1;

	
	x1= search_sequence(max_index1);
	x2= search_sequence(max_index2);
    	character *z1=new character();
    	character *z2=new character();

   character *k=new character();
    k=x1->start;
    while(k!=NULL)
    {

        z1=k;
        k=k->next;

    }

    k=x2->start;
    while(k!=NULL)
    {

        z2=k;
        k=k->next;
    }



   int  size1=(x1->start->a).size();
   int size2=(x2->start->a).size();



    insert_sequence(l2,1);
    insert_sequence(l2,2);


  


	string str1="";
	string str2="";

	for(int dd=0;dd<size1;dd++)
	str1=str1+'-';

	for(int ee=0;ee<size1;ee++)
	str2=str2+'-';





	while(i>0&&j>0)
    {
		if(ptr1[i][j]==0) //diag
		{
			i=i-1;
			j=j-1;


			insert_bet(z1->a,l2->start);
			insert_bet(z2->a,l2->start->down);
			z1=z1->back1;

			z2=z2->back1;




		}


		if(ptr1[i][j]==1) // left
		{

			j=j-1;
			insert_bet(str1,l2->start);
			insert_bet(z2->a,(l2->start)->down);
			z2=z2->back1;


		}

		if(ptr1[i][j]==-1) // up
		{

			i=i-1;
			insert_bet(z1->a,l2->start);
			insert_bet(str2,l2->start->down);
			z1=z1->back1;



     }


	}





}

// DELETING THE PARENT SEQUENCES WITH MAX SCORE
void delete1(){

    sequence *e=new sequence();
    sequence *p=new sequence();
    sequence *q=new sequence();


    int i=0;
    int in[2];
    in[0]=max_index1;
    in[1]=max_index2;
    int flag;
    while(i<2){
            flag=0;
            e=l1->start;

            while(e!=NULL){
                if(e->index==in[i])
                    {
                            if(e==l1->start){
                                    l1->start=e->down;flag++;

                                    break;

                            }

                            if(e->down==NULL){

                                    sequence *k=new sequence();
                                    k=l1->start;
                                    while(k->down!=NULL)
                                    {


                                    k=k->down;

                                    }



                                    k=e->back1;
                                    l1->end1=e->back1;
                                    e->back1=NULL;
                                    flag++;break;


                            }

                            else{
                                p=e->back1;
                                q=e->down;
                                p->down=q;
                                flag++;
                                break;


                            }


                    }

                    e=e->down;


                if(flag>0) break;

                }
            i++;

        }



}

//GIVING EACH SEQUENCE IN MAIN LIST - NEW INDEX OR NUMBER
void give_index(int n){
    sequence *o=new sequence();
    sequence *xyz=new sequence();
    o=l1->start;
    int in=0;

        while(o!=NULL)
        {

            o->index=in+1;
            o=o->down;
            in++;
        }



}


// FOR MAKING A HYBRID OF TWO SEQUENCE
void merge1(int n)
{

sequence *uu=new sequence();
sequence *vv=new sequence();

  character *u=new character();
  character *v=new character();

  uu=l2->start;// the first seq
  vv=l2->start->down; // the second seq

  u=uu->start;
  v=vv->start;

  while(u!=NULL)
  {
    u->a=(u->a)+(v->a);
	u=u->next;
	v=v->next;
  }


  character *c=new character();
  c=uu->start;
  cout<<endl;
while(c!=NULL){
          //  cout<<c->a<<endl;
            c=c->next;

}

// empty the second  sequence
   l2->start->down=NULL;

  // delete max index 1 and max index 2 sequences from mainlist.


   delete1();


  // insert the hybrid sequence in the main list


 sequence * xyz1=new sequence();
 xyz1=insert_sequence(l1,n-1);

  xyz1->start=l2->start->start;
  //calculate count for hybrid
   sequence *k=new sequence();
                                    k=l1->start;
                                    while(k->down!=NULL)
                                    {


                                    k=k->down;

                                    }






  character *a7=new character();
  a7=k->start;

  while(a7!=NULL){
    (k->count1)++;
    a7=a7->next;
  }

  //give index again
   give_index(n);

  //make the l2 list empty for the next operation
  l2->start=NULL;



}



// DISPLAY THE MULTIPLE SEQUENCE ALLIGNMENT
char multi[100][100];

void display_multi(int n){
int i=0,number=n,j=0;
    cout<<endl<<endl<<endl<<endl;


    character *ck1=new character();

    for(i=0;i<number;i++){

        ck1=(l1->start)->start;
        j=0;
        cout<<"S"<<i+1<<":::::::::::";
        while(ck1!=NULL){

            multi[i][j];
            cout<<ck1->a[i]<<""<<"";
            ck1=ck1->next;
        j++;


            }

    cout<<endl<<endl<<endl;
    }
    int count3=0;
    int bb=0;
    for(int K=0;K<n;K++){
        for(i=0;i<j;i++){
            if(multi[j][i]==multi[j][i+1]){
                count3++;
            }
        }
        if(count3==n)  bb++;



    }



//scoring of multiple sequence:

cout<<"::::::::::::::ANALYSIS OF SEQUENCE:::::::::::::::::"<<endl<<endl;

cout<<" THE SCORE OF THE MULTIPLE ALLIGNMENT "<<endl;
cout<<bb<<endl<<endl;

cout<<" THIS SHOWS THAT "<<bb<<"NUCLEOTIDES ARE CONSERVATIVE AND PERSISTED  FOR AGES WITHOUT ANY MUTATION\n\n\n\n\n\n\n\n";
cout<<"+++++++++++++++++++++++++++++++++++++++++END++++++++++++++++++++++++++++";


}









int main(){


cout<<"                           KNOW YOUR ANCESTORS                            "<<endl;
cout<<"                           *******************                            "<<endl;
cout<<"                             ***************                               "<<endl;
cout<<"                               ***********                                 "<<endl;
cout<<"                                 ******                                   "<<endl;
cout<<"                                   ***                                      "<<endl;
cout<<"                                    *                                        "<<endl;
sequence *temp= new sequence();

temp=l1->start;
int i,n=0,j,length;
string s;
cout<<"\n\n\n\n::::::::::::::::::ENTER THE NUMBER OF SEQUENCE::::::::::::::::::::::"<<endl;
cin>>n;
string a;


for(i=0;i<n;i++)
	{
	temp=insert_sequence(l1,i+1);
	cout<<":::::::::::::::::ENTER SEQUENCE NUMBER:::::::::::: "<<i+1<<endl;

	cin>>s;


       int l=s.size();
       //cout<<"\n the len is"<<l;

	for(j=0;j<l;j++){
	       a=s[j];
		insert_character(temp,a);

	}

	}

// start of main loop

     sequence *t=new sequence();
     sequence *t1=new sequence();

      for(i=0;i<n-1;i++) // main loop till all sequences are checked
      {

       t=l1->start;


		 // step1 :: get best alignment

		while(t!=NULL)
		{
			t1=t->down;
			while(t1!=NULL)
				{
                    		cout<<":::::::::::PAIRWISE ALLIGNMENT OF::::::: "<<endl;
	 		 cout<< t->index<<"  ";
                    		cout<<"and "<<t1->index;
			 new_global(t,t1); // calling for max score
			t1=t1->down;
                  			//  cout<<"----------------------------------------------------\n\n\n";

                }
			t=t->down;
        }//  get best alignment

        // step 2 :: alignment of the best score pair and then merging it one new seq!

	traceback();
	cout<<"::::::::::::::::BEST PAIRWISE ALLIGNED SEQUENCE:::::::::::"<<endl;
            	display(l2);

            cout<<endl<<endl;
            merge1(n-1-i);
	cout<<"::::::::::::::::<><><><>SEQUENCE LEFT"<<i+1<<"<><<><><>:::::::::::::::::::::";
           // cout<<""<<endl;

            display(l1);

            max_score=0;
      }
cout<<"::::::::()()()()()<><><><>FINAL ALLIGNMENT<><><><><()()()()()::::::::"<<endl<<endl;

	display_multi(n);



return 0;
}
