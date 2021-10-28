#include<stdio.h>
#include<stdlib.h>

struct Huffman
{
	char word;				//存储字母
	float weight;			//存储字母所占的权值
	int parent;				//存储该节点父亲节点的位置
	int lchild;				//存储左孩子节点所在位置
	int rchild;				//存储右孩子节点所在位置
};

void ReadWord()
{
	tree = (Position) malloc ( 53 * sizeof( struct Huffman ));
	for(int i = 0; i<27; i++)
	{
		tree[i].word = Word[ i ];
		tree[i].weight = Weight[ i ];
		tree[i].parent = tree[i].lchild = tree[i].rchild = -1;
	}
}
struct Huffman
{
	char word;				//存储字母
	float weight;			//存储字母所占的权值
	int parent;				//存储该节点父亲节点的位置
	int lchild;				//存储左孩子节点所在位置
	int rchild;				//存储右孩子节点所在位置
	char M[15];
};

void ReadWord()
{
	tree = (Position) malloc ( 53 * sizeof( struct Huffman ));
	for(int i = 0; i<27; i++)
	{
		tree[i].word = Word[ i ];
		tree[i].weight = Weight[ i ];
		tree[i].parent = tree[i].lchild = tree[i].rchild = -1;
		tree[i].M[0] = '\0';
	}
}

void CreatTree()
{
	for(;;)
	{
		Select();						//比较得出当前数据权值最小的两个数据
		if(s2==-1)break;				//当只剩下一个数据未处理时无限循环结束
		rear=rear+1;					//队尾指针后移
		tree[s1].parent=rear;	
		tree[s2].parent=rear;
		tree[rear].weight=tree[s1].weight+tree[s2].weight;
		tree[rear].parent=-1;			//初始化
		tree[rear].word='$';			//未存储字母的定义为'$'字符
		tree[rear].lchild=s1;
		tree[rear].rchild=s2;
		tree[rear].M[0] = '\0';
	}
}

void Select()
{
	s1=s2=-1;
	int i;
	for(i=0;i<=rear;i++)
	{		
		if(tree[i].parent==-1)			//判断数据是否已经连接节点
		{
			if(s1 == -1)s1=i;	
			else if(s2 == -1)s2=i;

			if(s2!=-1 && tree[s2].weight<tree[s1].weight)
			{ int n = s2; s2 = s1; s1 = n; }
			
			if(tree[i].weight < tree[s1].weight)
			{
				s2=s1;
				s1=i;
			}
			else if(s2 != -1 && i != s1 && tree[i].weight < tree[s2].weight)s2=i;
		}	
	}
}

void CreatCode()
{
	for(int i=0;i<27;i++)
	{
		char b[15];		//定义临时数组b[15]，y用于读取字母
		int x=0,m,n=i;
		while(n!=rear)					//当读取到树的根节点时循环结束
		{	
			m=tree[n].parent;
			if(n==tree[m].lchild) b[x]='0';		//逆向读取，为左孩子读入'0',右孩子读入'1'
			else b[x]='1';
			x++;
			n=m;
		}
		for(int i1=0; i1<x; i1++)
		{
			tree[i].M[i1] = b[x-1-i1];
		}
		tree[i].M[x]='\0';
	}

}

void PrintCode()
{
	printf("index word  weight  parent lchild rchild code\n");
	int i;
	for(i=0;i<=rear;i++)
	{
		printf("%d    %c     %f    %d    %d    %d     %s\n",i ,tree[i].word  ,tree[i].weight  ,tree[i].parent  ,tree[i].lchild  ,tree[i].rchild ,tree[i].M);
	}
}


int main()
{
	ReadWord();
	CreatTree();
	CreatCode();
	PrintCode();

	return 0;
}
