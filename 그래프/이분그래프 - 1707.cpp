#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)
typedef struct graphnode {
	int data;
	struct graphnode* next;
}GN;

typedef struct graph {
	int size;
	GN* adj;
}G;

int visit[20001];
int V, E;
int u, v;

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
int add_node_edge(G* gph, int src, int dst)
{
	return add_direct_edge(gph, src, dst) && add_direct_edge(gph, dst, src);
}

void reset(G* gph)
{
	gph->size = 0;
	for (int i = 1; i <= gph->size; i++)
	{
		gph->adj[i].next = NULL;
	}
}
bool DFSutil(G* gph, int start, int* visit)
{
	for (GN* current = gph->adj[start].next; current != NULL; current = current->next)
	{
		int neighbor = current->data;
		if (visit[neighbor] == 0)
		{
			visit[neighbor] = 3 - visit[start];
			if (!DFSutil(gph, neighbor, visit))
				return false;
		}
		else if (visit[neighbor] == visit[start])
		{
			return false;
		}
	}
	return true;
}
bool DFS(G* gph)
{
	for (int i = 1; i <= gph->size; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			if (!DFSutil(gph, i, visit))
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	G gph;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &V, &E);
		init_graph(V, &gph);
		for (int i = 0; i < E; i++)
		{
			scanf("%d %d", &u, &v);
			add_node_edge(&gph, u, v);
		}

		if (DFS(&gph))
			printf("YES\n");
		else
			printf("NO\n");
		reset(&gph);
		for (int i = 0; i <= 20000; i++)
		{
			visit[i] = 0;
		}
	}
}