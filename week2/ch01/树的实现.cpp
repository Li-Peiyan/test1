#include<stdio.h>
#include<malloc.h>

#ifndef _Tree_H

struct TreeNode;
typedef struct TreeNode *PtrToNode;

PtrToNode CreatTree( PtrToNode b ) ;
void DeleteAll(PtrToNode T);

void ListDir( PtrToNode D,int Depth);
void ListDirectory( PtrToNode D );

void SizeDir( PtrToNode D,int Depth);
void SizeDirectory( PtrToNode D );

void PrintName( PtrToNode D,int Depth );

#endif 


struct TreeNode
{
	char Element;
	PtrToNode FirstChild;
	PtrToNode NextSibling;
};



PtrToNode CreatTree( PtrToNode b ) 
{
	char ch;
	
	printf("请输入信息（‘#’表示截止）：");
	scanf("%c", &ch );
	if(ch=='#')b=NULL;
	else
	{
		PtrToNode b = (PtrToNode)malloc( sizeof( struct TreeNode ) );
		b->Element=ch;
		b->FirstChild=CreatTree(b->FirstChild);
		b->NextSibling=CreatTree(b->NextSibling);
	}
	return b;
}

void DeleteAll(PtrToNode T)
{
	if( T != NULL )
	{
		DeleteAll(T->FirstChild);
		DeleteAll(T->NextSibling);
		free(T);
	}
}

void ListDir( PtrToNode D,int Depth)
{
	if( D != NULL )
	{
		PrintName( D,Depth );
		if( D->FirstChild != NULL )
			ListDir( D->FirstChild,Depth + 1 );
		else if(D->NextSibling != NULL )
			ListDir( D->NextSibling,Depth );
	}
}

void ListDirectory( PtrToNode D )
{
	ListDir( D,0 );
}

void SizeDir( PtrToNode D,int Depth)
{
	if( D->FirstChild != NULL )
		SizeDir( D->FirstChild , Depth+1 );
	PrintName( D,Depth );
	SizeDir( D->NextSibling , Depth );
}

void SizeDirectory( PtrToNode D )
{	
	SizeDir(D,0);
		
}

void PrintName( PtrToNode D,int Depth )
{
	for(int i=0;i<Depth;i++)
	{
		printf("	");
	}
	printf("%c/n",D->Element);
}


int main()
{
	PtrToNode T = (PtrToNode)malloc( sizeof( struct TreeNode ) );
	T = CreatTree( T ) ;
	
	
	return 0;
}