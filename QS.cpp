#include<iostream>
using namespace std;
int Part(int *A,int l,int h)// partition function
{
	int i,j=0; // loop control variables
	int pivot=*(A+h);
	for(i=l;i<h;i++)
	{
		if(*(A+i)<pivot) //checking whether the elemnrts in array is smaller
		{
			int temp=*(A+j+l); //if it is smaller than the pivot
			*(A+j+l)=*(A+i); //then swap
			*(A+i)=temp;
			j++;
		}
	}
	int temp= *(A+l+j);// storing pivot after all the smaller elements
	*(A+j+l) = *(A+h);
	*(A+h) = temp;
	int y=l+j;
	return y;//returning the position of new pivot
}
void QS(int *AR, int L, int H)//sort function
{
	if(L>=H) //condition marking the end of recursion
	{
		
	}
	else
	{
		int Np=Part(AR,L,H); // location of the next pivot								
		if(Np>0)
		QS(AR,L,Np-1); //recusieve call of the function
		QS(AR,Np+1,H);// before and after the partition
	}
}
int main()
{
	int A[10];
	for(int i=0;i<10;i++)
	cin>>A[i];
	QS(A,0,9);
	for(int i=0;i<10;i++)
	cout<<endl<<A[i];
	cout<<endl;
	return 0;
	
}
