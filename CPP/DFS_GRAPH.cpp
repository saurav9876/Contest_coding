#include <bits/stdc++.h>

using namespace std;

struct Adjlistnode{
	int data;
	struct Adjlistnode* next;
};

struct Adjlist{
	struct Adjlistnode* head;
};

struct Graph{
	int v;
	struct Adjlist* array;
};

struct Adjlistnode* newnode(int dest)
{
	struct Adjlistnode* temp = (Adjlistnode*)malloc(sizeof(struct Adjlistnode));
	temp->data = dest;
	temp->next = NULL;

	return temp;
}
void Adjlist_graph(Graph* graph,int src,int dest)
{
	if(graph->array[src].head==NULL){
		graph->array[src].head = newnode(dest);
		return;
	}
    Adjlistnode* temp= newnode(dest);
	temp->next= graph->array[src].head;
	graph->array[src].head = temp;
}
void print(Graph* graph,int v)
{
	for(int i=0;i<v;i++){
		Adjlistnode* temp=graph->array[i].head;
		cout << "Array[" <<i << "] - "; 
		while(temp!=NULL){
			cout << temp->data << " ";
			temp=temp->next;
		}
		cout << endl << endl;
	}
}
void DFS(Graph* graph,int src,int visit[],stack <int> &s)
{
	Adjlistnode* temp=graph->array[src].head;
	//cout << src << " ";
	visit[src]=1;
	while(temp!=NULL){
		if(visit[temp->data]==0){
		    DFS(graph,temp->data,visit,s);
		}
		temp=temp->next;
	}
	s.push(src);
}
int main()
{
	int V;
	cin >> V;
	struct Graph* graph=(Graph*)malloc(sizeof(Graph));
	graph->v = V;
	graph->array = NULL;
    
    graph->array = (Adjlist*)malloc(V*sizeof(Adjlist));
    for(int i=0;i<V;i++){
    	graph->array[i].head= NULL;
    }

	int src,dest,n_edge;
	cin >> n_edge;
	for(int i=0;i<n_edge;i++){
		cin >> src >> dest;
		Adjlist_graph(graph,src,dest);
	}
	print(graph,V);
	int visit[V];
	for(int i=0;i<V;i++){
		visit[i]=0;
	}
	stack<int> s;
	for(int i=0;i<V;i++){
		if(visit[i]==0){
			DFS(graph,i,visit,s);
		}
	}
	while(!s.empty()){
		cout<<s.top() << " ";
		s.pop();
	}
    return 0;
}