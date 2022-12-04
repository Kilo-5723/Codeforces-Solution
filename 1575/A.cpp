#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int alpha = 26, buff = 1e6 + 5;
char s[buff];
struct node {
  node *ch[26];
  int val;
  node() {
    memset(ch, 0, sizeof(ch));
    val = 0;
  }
};
node *root;
void insert(node *&root, char *s, int v) {
  if (!root) root = new node();
  if (!*s) {
    root->val = v;
    return;
  }
  insert(root->ch[*s - 'A'], s + 1, v);
}
void dfs(node *root) {
  if (!root) return;
  if (root->val) printf("%d ", root->val);
  for (int i = 0; i < alpha; i++) dfs(root->ch[i]);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int i = 1; i < m; i += 2) s[i] = 'Z' + 'A' - s[i];
    insert(root, s, i + 1);
  }
  dfs(root);
  puts("");
  return 0;
}