#include <stdio.h>
#include<stdlib.h>
#define max 10
 struct DsKe{
  int dinhKe;
  struct DsKe *lienket;
 };
 struct Dothi{
 	int soDinh;
 	struct DsKe *DsKe[max];
 };
 int daTham[max];
 int truoc[max];
 void them (int i , int j ,struct Dothi *g){
 	struct DsKe *p;
 	p = (struct DsKe*)malloc (sizeof (struct DsKe));
 	p->lienket =j;
 	p->lienket = g->DsKe[i];
 	g->DsKe[i]=p;
 }
  void docTep(char *tenTep ,struct Dothi *g){
  	FILE *f ;int i,j,tg;
  	f =fopen(tenTep,"r");
  	fscanf(f,"%d",&g->soDinh);
  	for(i=0;i<g->soDinh;i++);
	   g->DsKe[i]= NULL;
  	for(i=0;i<g->soDinh;i++);
  	        for(j=0;i<g->soDinh;j++)
  	        {
  	        	fscanf(f,"%d",&tg);
  	        	if(tg==i)
				  {
  	        		them(i,j,g);
				  }
				fclose(f);
			  }
  }
  void inDoThi(struct Dothi *g, int i , int j){
  	struct Dske *p;
     printf("so dinh: %d \n", g->soDinh);
     p = (struct DsKe)malloc(sizeof (struct DsKe))
     printf("Cac ds ke:\n");
      for(i=0;i<g->soDinh; i++) 
     printf("Danh sach ke thu %d:", i);
      p = g->DsKe[i];
      while (p != NULL)
       {
      printf("%d",p->dinhKe);
      p = p->lienket;
     }
      printf("\n");
}
void duyetSau(struct Dothi*g, int v){
     struct DsKe *p; int w;
       daTham[v]=1;
         p = g->DsKe[v];
         while (p != NULL){
          w = p->dinhKe;
          if(daTham[w]==0)
             {
          truoc[w] = v;
           duyetSau(g,w);
      }
         p=p->lienket;
     }
}
 int duongDi(struct Dothi*g,int i, int s)
{
     for(i = 0; i < g->soDinh; i++) daTham[i] = 0;
     duyetSau(g, s);
}

  void inDD(int s, int d){
    int z;
     z = d;
     while (z != s){
     printf("%d <= ", z);
          z = truoc[z];}
      printf("%d", s);
}
