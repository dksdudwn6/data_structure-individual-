#include <stdio.h>
#include "adjList.h"
#include "stackL.h"
#include "DFS.h"

// �׷��� g���� ���� v�� ���� ���� �켱 Ž�� ���� : [�˰��� 8-1] ����
void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL;					// ������ top ����
	push(v);					// ���� �켱 Ž���� �����ϴ� ���� v�� ���ÿ� push
	g->visited[v] = TRUE;		// ���� v�� �湮�����Ƿ� �ش� �迭 ���� TRUE�� ���� 
	printf(" %c", v + 65);

	// ������ ������ �ƴ� ���� ���� �켱 Ž�� �ݺ�
	while (!isStackEmpty()) {
		w = g->adjList_H[v];
		
		while (w) {
		 
			if (!g->visited[w->vertex]) {
				push(w->vertex);					
				g->visited[w->vertex] = TRUE;	
				printf(" %c", w->vertex + 65);	
				v = w->vertex;
				w = g->adjList_H[v];
			}
			
			else w = w->link;
		}
		v = pop();
	} 
}