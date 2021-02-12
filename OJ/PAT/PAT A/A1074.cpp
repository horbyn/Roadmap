/* A1074链表方法PA */
#include <iostream>
#include <iomanip>
using namespace std;

static const int maxn = 100000;

typedef struct static_node_t* static_node;
struct static_node_t {
	int addr;
	int data;
	int next;
}sta_node[maxn];

typedef struct node_t* ptr_node;
struct node_t {
	static_node data;
	ptr_node next;
};

static void head_insert(ptr_node list, static_node val) {
	ptr_node n = new struct node_t;

	n->data = val;
	//头插法会反转，所以要修改指针域
	if (!list->next)    val->next = -1;
	else    val->next = list->next->data->addr;
	n->next = list->next;
	list->next = n;
}

static ptr_node find_node(ptr_node list, int pos) {
	ptr_node tmp = list;
	int cou = 0;
	while (tmp->next && pos > cou) {
		cou++;
		tmp = tmp->next;
	}
	if (pos == cou)    return tmp;
	else    return NULL;
}

static void tail_insert(ptr_node list, int pos, static_node val) {
	ptr_node pre = find_node(list, pos - 1);
	if (!pre) {
		cout << "位置非法\n";
		return;
	}

	ptr_node n = new struct node_t;
	n->data = val;
	n->next = pre->next;
	pre->next = n;
}

int main() {
/*
	while (遍历结构数组) {
		head_ptr;
		if (结构数组剩余长度够一个 sublist) {
			;
		} else {
			;
		}
		head_ptr = sublist;
	}
*/
	//1. INPUT
	int fst_addr, n, k, node_idx, inp;
	cin >> fst_addr >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> inp;
		sta_node[inp].addr = inp;
		cin >> sta_node[inp].data >> sta_node[inp].next;
		if (inp == fst_addr)    node_idx = inp;//记下第一个地址在哪个下标
	}

	//2. EXECUTE
	ptr_node head_ptr = NULL;
	for (int i = 0; i < n; i += k) {
		ptr_node sub_ptr = new struct node_t;
		sub_ptr->next = NULL;

		if (n - i >= k) {
			//头插法
			for (int j = 0; j < k; ++j) {
				static_node n = &sta_node[node_idx];
				node_idx = sta_node[node_idx].next;
				head_insert(sub_ptr, n);
			}
		}
		else {
			//尾插法
			for (int j = 0; j < n - i; ++j) {
				static_node n = &sta_node[node_idx];
				node_idx = sta_node[node_idx].next;
				tail_insert(sub_ptr, j + 1, n);
			}
		}

		//sublist 连接到链表
		if (!head_ptr)    head_ptr = sub_ptr->next;//链表为空时连接到头指针
		else {//链表非空时连接到最后一个结点的 next
			ptr_node tmp = head_ptr;
			while (tmp->next)    tmp = tmp->next;
			tmp->data->next = sub_ptr->next->data->addr;//将最后一个结点数据修改为 sub_ptr
			tmp->next = sub_ptr->next;
		}
		delete(sub_ptr);
	}

	//3. OUTPUT
	while (head_ptr) {
		cout << setw(5) << setfill('0') << head_ptr->data->addr
			<< " " << head_ptr->data->data << " ";
		if (head_ptr->data->next == -1)    cout << "-1\n";
		else    cout << setw(5) << setfill('0')
			<< head_ptr->data->next << endl;

		head_ptr = head_ptr->next;
	}

	return 0;
}