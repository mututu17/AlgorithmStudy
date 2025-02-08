#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct graphnode {
	int data;
	struct graphnode* next;
}GN;

typedef struct graph {
	int size;
	GN* adj;
}G;

int visit[100001] = { 0, };
int cycle[100001] = { 0, };
int V;
int u;

void init_graph(int size, G* gph) {
	gph->size = size;
	gph->adj = (GN*)malloc((size + 1) * sizeof(GN));
	for (int i = 1; i <= size; i++)
	{
		gph->adj[i].next = NULL;
	}
}

int add_direct_edge(G* gph, int src, int dst)
{
	GN* tmp = (GN*)malloc(sizeof(GN));
	tmp->data = dst;
	tmp->next = gph->adj[src].next;
	gph->adj[src].next = tmp;
	return 1;
}

void reset(G* gph)
{
	gph->size = 0;
	for (int i = 1; i <= gph->size; i++)
	{
		gph->adj[i].next = NULL;
	}
}
void DFSutil(G* gph,int x, int start, int* visit)
{
	for (GN* current = gph->adj[start].next; current != NULL; current = current->next)
	{
		int neighbor = current->data;
		if (visit[neighbor] == 0)
		{
			visit[neighbor] = x;
			DFSutil(gph, x, neighbor, visit);
		}
		else if (cycle[neighbor] == 0 && visit[neighbor] == x)
		{
			cycle[neighbor] = 1;
			DFSutil(gph, x, neighbor, visit);
		}
		else if (visit[neighbor] != x)
		{
			return;
		}
	
	}
}
void DFS(G* gph)
{
	for (int i = 1; i <= gph->size; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = i;
			DFSutil(gph,i, i, visit);
		}
	}
}
int main()
{
	G gph;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &V);
		init_graph(V, &gph);
		for (int i = 1; i <= V; i++)
		{
			scanf("%d", &u);
			add_direct_edge(&gph, i, u);
		}
		DFS(&gph);
		int sum = 0;
		for (int i = 1; i <= V; i++)
		{
			if (cycle[i] == 0)
				sum++;
		}
		printf("%d\n", sum);
		reset(&gph);
		for (int i = 0; i <= V; i++)
		{
			visit[i] = 0;
			cycle[i] = 0;
		}
	}
}