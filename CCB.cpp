#include <stdio.h>
#include <stdlib.h>

struct CCB {
  int so ; 
  int cao ;
  struct CCB *trai, *phai ;

};

int max (  int a , int b ){
  if(  a > b )
   return a ;
     else 
        return b ;
}
int chieucao (struct CCB *N){
    if(N==NULL)
         return 0 ;
         // n se lien ket voi du lieu cua cao
      return N->cao;   
}
int layCCB (struct CCB *N){
      if (N==NULL)
         return 0 ;
             // kiem tra lay chieu cao ben trai tru di chieu cao ben phai de duoc cay can bang
            return chieucao(N->trai)-chieucao(N->phai);

}
struct CCB* nutNhoNhat(struct CCB *N)
{
	struct CCB* p = N;	 
	/* Tim nut trai nhat */
	while (p->trai != NULL)
		p = p->trai;
	return p;
}

struct CCB *quayPhai ( struct CCB *y){
  struct CCB *x =y->trai;
  struct CCB *T2=y->phai;
     // thuc hien dieu kien quay 
     x->phai=y;
     y->trai=T2;
     // cap nhat lai chieu cao cua cay 
     y->cao = max(chieucao(y->trai),chieucao(y->phai)+1);
     x->cao = max(chieucao(x->trai),chieucao(x->phai)+1);
     return x ;
}
struct CCB *quayTrai(struct CCB *x){
      struct CCB *y=x->trai;
      struct CCB *T2=x->phai;
      // thuc hien dieu kien quay no 
      y->trai=x;
      x->phai=T2;
      // Cap nhat lai chieu cao cua cay
      x->cao = max(chieucao(x->trai),chieucao(y->phai)+1);
      y->cao = max(chieucao(y->trai),chieucao(y->phai)+1);
      return y ;
}
//struct CCB *them (struct CCB *so, int x )
main()
{
	struct CCB *goc = NULL;
	int i, k, n = 100000;
//	for(i=1; i<=n; i++)
//	{
//		goc = them(goc, i);
//	}
//	printf("Chieu cao cay: %d\n",goc->cao);
//	for(i=1; i<=n/2; i++)
//	{
//		k = rand();
//		goc = xoa(goc, i);
//	}
	
	printf("Chieu cao cay sau khi xoa: %d\n",goc->cao);
}
