//单源最短路径,bellman_ford算法,邻接阵形式,复杂度O(n^3)
//求出源s到所有点的最短路经,传入图的大小n和邻接阵mat
//返回到各点最短距离min[]和路径pre[],pre[i]记录s到i路径上i的父结点,pre[s]=-1
//可更改路权类型,路权可为负,若图包含负环则求解失败,返回0
//优化:先删去负边使用dijkstra求出上界,加速迭代过程
#define MAXN 200
#define inf 1000000000
typedef int elem_t;

int bellman_ford(int n,elem_t mat[][MAXN],int s,elem_t* min,int* pre){
	int v[MAXN],i,j,k,tag;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[s]=0,j=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,i=0;i<n;i++)
			if (!v[i]&&mat[k][i]>=0&&min[k]+mat[k][i]<min[i])
				min[i]=min[k]+mat[pre[i]=k][i];
	}
	for (tag=1,j=0;tag&&j<=n;j++)
		for (tag=i=0;i<n;i++)
			for (k=0;k<n;k++)
				if (min[k]+mat[k][i]<min[i])
					min[i]=min[k]+mat[pre[i]=k][i],tag=1;
	return j<=n;
}