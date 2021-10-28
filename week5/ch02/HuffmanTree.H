#ifndef _HuffmanTree_H

int s1,s2,rear = 26;
char Word[ 27 ] = {'#'	,'E'	,'T'	,'O'
					,'A',	'N',	'I',	'R'
					,'S',	'H',	'D',	'L'
					,'C',	'U',	'F',	'M'
					,'P',	'Y',	'W',	'G'
					,'B',	'V',	'K',	'X'
					,'J',	'Q',	'Z' };

float Weight[ 27 ] = {0.2	,0.105	,0.071	,0.0644
				,0.063	,0.059	,0.054	,0.053
				,0.052	,0.047	,0.035	,0.029
				,0.023	,0.0225	,0.0221	,0.021
				,0.0175	,0.012	,0.012	,0.011
				,0.0105	,0.008	,0.003	,0.002
				,0.001	,0.001	,0.001};

typedef struct Huffman *Position;
Position tree;

void ReadWord();
void CreatTree();		//构建哈夫曼树
void Select();			//比较得出较小的两个节点
void PrintCode();

#endif
