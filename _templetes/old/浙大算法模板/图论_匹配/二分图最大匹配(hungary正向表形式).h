//二分图最大匹配,hungary算法,正向表形式,复杂度O(m*e)
//返回最大匹配数,传入二分图大小m,n和正向表list,buf(只需一边)
//match1,match2返回一个最大匹配,未匹配顶点match值为-1
#include <string.h>
#define MAXN 310
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int hungary(int m,int n,int* list,int* buf,int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k,l;
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (l=list[k=s[p]];l<list[k+1]&&match1[i]<0;l++)
				if (t[j=buf[l]]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}