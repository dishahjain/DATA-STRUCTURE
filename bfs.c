#include<stdio.h>

void bfs(int);
int a[10][10],vis[10],n;

void main() {
    int i,j,src;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            scanf("%d",&a[i][j]);
        }
        vis[i]=0;
    }
    printf("Enter the source vertex: ");
    scanf("%d",&src);
    printf("Nodes reachable from source vertex %d:\n", src);
    bfs(src);
}
void bfs(int v) {
    int q[10],f=1,r=1,u,i;
    q[r]=v;
    vis[v]=1;
    while(f<=r) {
        u=q[f];
        printf("%d ", u);
        for(i=1;i<=n;i++) {
            if(a[u][i]==1 && vis[i]==0) {
                vis[i]=1;
                r=r+1;
                q[r]=i;
            }
        }
        f=f+1;
    }
} cv