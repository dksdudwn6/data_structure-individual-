#include <stdio.h>
#include "adjList.h"
#include "stackL.h"
#include "DFS.h"

// 그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산 : [알고리즘 8-1] 구현
void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL;					// 스택의 top 설정
	push(v);					// 깊이 우선 탐색을 시작하는 정점 v를 스택에 push
	g->visited[v] = TRUE;		// 정점 v를 방문했으므로 해당 배열 값을 TRUE로 설정 
	printf(" %c", v + 65);

	// 스택이 공백이 아닌 동안 깊이 우선 탐색 반복
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