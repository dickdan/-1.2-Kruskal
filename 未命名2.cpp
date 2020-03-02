#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<fstream>
using namespace std;

int n, m, tot=0, k=0; // n�Ƕ˵�������m�Ǳ�����tot��¼���մ𰸣�k�Ѿ������˶��ٱ� 
int fat[10000]; // ��¼�����ϴ�
 
struct node{
	int from, to, dis; // �ṹ�崢��� 
}edge[200010];
bool cmp(const node &a, const node &b){ // sort����
	return a.dis < b.dis;
}
int father(int x){ // �Ҽ����ϴ󣬲��鼯��һ���� 
	if(fat[x] != x)
	return father(fat[x]);
	else return x;
}
void unionn(int x,int y){ // �ϲ�����ͨ���������鼯��һ���� 
	fat[father(y)] = father(x);
}
int main(){
	scanf("%d%d", &n, &m); // ������������� 
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].dis); // ����ߵ���Ϣ 
	}
	for(int i = 1; i <= n; i++) fat[i] = i; // ��ʼ�� 
	sort(edge+1, edge+1+m, cmp); // ��Ȩֵ���� 
	for(int i = 1; i <= m; i++){ // ��С������� 
		if(k == n-1) break; // n������Ҫn-1�������� 
		if(father(edge[i].from) != father(edge[i].to)){ // ���粻��һ����ͨ���� 
			unionn(edge[i].from, edge[i].to); // ���� 
			tot += edge[i].dis; // ��¼��Ȩ 
			k++; // �����ӱ���+1
		}
	}
	printf("%d", tot);
	return 0;
} 
/* 
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6*/ 
