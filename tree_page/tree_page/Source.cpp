#include "Header.h"

void enqueue(queue& queue, node* tree_node) {
	// ������� ����� ������� ��� ���������� � �������
	elem* newel = new elem;
	newel->node = tree_node;
	if (!queue.tail) {
		// ���� ������� ��� �� ����, ����� ������� ���������� ����������� � ���
		queue.head = queue.tail = newel;
	}
	else {
		// ���� ������� ��� ����, ����� ������� ���������� � �����:
		queue.tail->next = newel;
		queue.tail = newel;
	}
	queue.size++;
}
bool dequeue(queue& queue, node*& tree_node) {
	if (!queue.head) return false; // ������� ���. ������� �������� ����������
	// ��������� ������������ ��������
	tree_node = queue.head->node;
	// ��������� ��������� �� ������ �������
	elem* rem = queue.head;
	// �������� ����� ��������� ��������
	queue.head = queue.head->next;
	// ������� ������� � ������ �������
	delete rem;
	// ���� ��������� � ������� �� ��������, �������� � ��������� �� �� �����.
	if (!queue.head) queue.tail = nullptr;
	queue.size--;
	return true;
}
void clear(queue& queue)
{
	// �������� �� ���� ��������� �������, ���� ��� �� ��������
	while (queue.head)
	{
		// ��������� ������ �� ��������� �������
		elem* rem = queue.head;
		// ��������� ��������� ������
		queue.head = queue.head->next;
		// ������� ������� �� ������������ ���������
		delete rem;
	}
	// �������� ������ �������
	queue.size = 0;
	// ��������� ��������� �� ��������� �������
	queue.tail = nullptr;
}

/// ���������� �������� � ������. ��������������� (����������) �������.
bool _add_to_tree(node*& root, float value, string name);
bool _add_to_treeN(node*& root, float value, string name);
/// �������� �������� �� ������. ��������������� (����������) �������.
int _find_in_tree(const node* root, int value);
/// ���������� ��������� ������ ��������� ��� ��������� ���� 
/// ������������ ��������� ����� ������ ������ ������. ��������������� �������.
enum _traverse_type { infix, prefix, postfix };
/// ������� ������ ������ ������. ��������������� (����������) �������
void _traverse(queue& q, node* root, _traverse_type type);
/// ������� ������ ������ �����
void _wide_traverse(queue& q, node*& root, bool include_empty);
/// ���������� ��������� ������ ��������� ��� ��������� ���� �
/// ���������� (����������) ���������� � ����
int _get_height(node* n);
/// ������� ������������ ������ ��� ��� �����
void _balance(node*& n);
/// ������� ���������� ������ ������ ��������
void _small_left_rotate(node*& n);
/// ������� ���������� ������ ������� ��������
void _small_right_rotate(node*& n);
/// ������� ���������� �������� ������ ��������
void _big_left_rotate(node*& n);
/// ������� ���������� ��������� ������� ��������
void _big_right_rotate(node*& n);
void add_to_tree(tree& t, float value, string name, bool type)
{
	if (!type) {
		if (_add_to_tree(t.root, value, name)) t.elem_count++;
	}
	else
	{
		if (_add_to_treeN(t.root, value, name)) t.elem_count++;
	}
}
bool _add_to_tree(node*& root, float value, string name)
{
	// ���������, ���������� �� ������
	if (root)
	{
		// ������ ��� ����������. ����������, ���� ���������� ����� �������
		// � ����������� �� �������� ������ �������� �������������� ��������
		if (value == root->value)
		{
			// ���� �������� � ����� �������� ��������� �� ��������� � ������� �������� ������
			// ������ ���������� ��������, ����������� ���������� ����� ���������
			root->count++;
			root->name += " ; " + name;
			return false;
		}
		auto& branch =
			value < root->value ? root->left : root->right;
		// ����������� ��������� ������� � ����� ��� ������ ���������
		bool r = _add_to_tree(branch, value, name);
		// ���������� ������������ ������ ����� ���������� ������ ����
		// �������� ������ ����� ������ � ������� ������������
		if (r) _balance(root);
		return r;
	}
	// ���� ������ ���, �� ����� ������� ���������� ��������
	// ������� ����� ���� ��� ���������� � ������
	node* newnode = new node;
	newnode->value = value;
	newnode->name = name;
	// � �������� � �������� �������� (���������) ����
	root = newnode;
	return true;
}
bool _add_to_treeN(node*& root, float value, string name)
{
	// ���������, ���������� �� ������
	if (root)
	{
		// ������ ��� ����������. ����������, ���� ���������� ����� �������
		// � ����������� �� �������� ������ �������� �������������� ��������
		bool flag = false;
		int i = 0;
		while (name[i] == root->name[i]) {
			i++;
			if (i == min(name.size(), root->name.size())) {
				flag = true;
				break;
			}
		}
		if (flag) {
			if (name.size() > root->name.size())
			{
				auto& branch = root->right;
				bool r = _add_to_treeN(branch, value, name);
				if (r) _balance(root);
				return r;
			}
			else {
				auto& branch = root->left;
				bool r = _add_to_treeN(branch, value, name);
				if (r) _balance(root);
				return r;
			}
		}
		else {
			auto& branch = ((int)name[i] > (int)root->name[i]) ? root->left : root->right;
			bool r = _add_to_treeN(branch, value, name);
			if (r) _balance(root);
			return r;
		}
		// ����������� ��������� ������� � ����� ��� ������ ���������
		// ���������� ������������ ������ ����� ���������� ������ ����
		// �������� ������ ����� ������ � ������� ������������
	}
	// ���� ������ ���, �� ����� ������� ���������� ��������
	// ������� ����� ���� ��� ���������� � ������
	node* newnode = new node;
	newnode->value = value;
	newnode->name = name;
	// � �������� � �������� �������� (���������) ����
	root = newnode;
	return true;
}
void find_in_tree(const node* root, string letter, bool& f)
{
	// ���� ������ ����, ������ ������� �������� �� �������, ���������� = 0
	if (!root) return;
	// ���� �������� ������� � �������� ��������, ���������� ����������
	if (root->name[0] == letter[0]) { f = true; cout << root->name << " ; " << endl; }
	// ����� ���������� ����������� ����� � �����������
	if (letter[0] > root->name[0])
		find_in_tree(root->left, letter, f);
	find_in_tree(root->right, letter, f);
}
int _get_height(node* n)
{
	// ���� ���� ����, ����� ��������� ���������� � ���������� ������ = 0.
	if (!n) return 0;
	// ���������� ����������� � ��������� ������ ������ � ������� ����������� (���� ��� ����������)
	auto lh = n->left ? n->left->height : 0;
	auto rh = n->right ? n->right->height : 0;
	// ������ �������� ���� ������������ ��� ���������� �� ����� ����������� + 1
	return n->height = 1 + (lh > rh ? lh : rh);
}
void _traverse(queue& q, node* root, _traverse_type type) {
	// ���������� ������ ������ ������
	if (root)
	{
		switch (type)
		{
		case infix: // ����� ���� LNR
		// ����������� ����� �������� ������ ��������� (L)
			if (root->left) _traverse(q, root->left, type);
			// ����� �������� ���� (N)
			enqueue(q, root);
			// ����������� ����� �������� ������� ��������� (R)
			if (root->right) _traverse(q, root->right, type);
			break;
		case prefix: // ����� ���� NLR
		// ����� �������� ���� (N)
			enqueue(q, root);
			// ����������� ����� �������� ������ ��������� (L)
			if (root->left) _traverse(q, root->left, type);
			// ����������� ����� �������� ������� ��������� (R)
			if (root->right) _traverse(q, root->right, type);
			break;
		case postfix: // ����� ���� LRN
		// ����������� ����� �������� ������ ��������� (L)
			if (root->left) _traverse(q, root->left, type);
			// ����������� ����� �������� ������� ��������� (R)
			if (root->right) _traverse(q, root->right, type);
			// ����� �������� ���� (N)
			enqueue(q, root);
		}
	}
}
queue prefix_traverse(tree t)
{
	queue q;
	_traverse(q, t.root, prefix);
	return q;
}
queue infix_traverse(tree t)
{
	queue q;
	_traverse(q, t.root, infix);
	return q;
}
queue postfix_traverse(tree t)
{
	queue q;
	_traverse(q, t.root, postfix);
	return q;
}
queue wide_traverse(tree t, bool include_empty)
{
	queue q;
	_wide_traverse(q, t.root, include_empty);
	return q;
}
void _wide_traverse(queue& queue, node*& r, bool include_empty)
{
	// �������� ����, ��� ������ ����������
	if (!r) return;
	// ������ ������ ����������� � �������
	enqueue(queue, r);
	// ��������� ��������� �� ������ �������
	auto q = queue.head;
	// ���������� ���������� ������������� ����� ����� ��� ������ ������ ������
	// (��� ����� ���������� ������)
	const auto cnt = 1 << (r->height - 1);
	// ������������ ������ �� �������
	for (int i = 1; i < cnt && q; i++)
	{
		// �������� ��������� �� ����� � ������ ������� ��� ��������
		auto ln = q->node ? q->node->left : nullptr;
		auto rn = q->node ? q->node->right : nullptr;
		// ��������� ���� � ������� ���� ��� �� ������, ����
		// �������� include_empty ��������� ��������� ��� ������ ��������.
		// (��������� ���������� ��� ����������� ������ �� ����� ��������� ������)
		if (ln || include_empty) enqueue(queue, ln);
		if (rn || include_empty) enqueue(queue, rn);
		q = q->next;
	}
}
void _balance(node*& n)
{
	// ���������, ��� ���������� ���� ����������
	if (!n) return;
	// ���������� ������ ������ � ������� �����������
	auto lh = _get_height(n->left);
	auto rh = _get_height(n->right);
	// ���������� �������� ����� ���� �����������
	auto dh = lh - rh;
	// ������� ���������� �������� ��������
	dh = dh >= 0 ? dh : -dh;
	// ���� �������� ����� 2 ��� �����, ��������� ������������
	if (dh >= 2)
	{
		// ���� ������ ����� �������, ������ ����� �������
		if (rh > lh)
		{
			// ��������� ������ ����������� � ������ ���������
			auto rlh = _get_height(n->right->left);
			auto rrh = _get_height(n->right->right);
			// ���� ������ ���-��������� ������, ������ ����� �������
			if (rrh > rlh) _small_left_rotate(n);
			// ����� - �������
			else _big_left_rotate(n);
		}
		// ����� ������ ������ �������, ���� ����� ����� ������
		else
		{
			// ��������� ������ ����������� � ����� ���������
			auto llh = _get_height(n->left->left);
			auto lrh = _get_height(n->left->right);
			// ���� ����� ���-��������� ������, ������ ����� �������
			if (llh > lrh) _small_right_rotate(n);
			// ����� - �������
			else _big_right_rotate(n);
		}
	}
	else
	{
		// ��������������� ���. ������ �������� ������ �������� ����
		_get_height(n);
	}
}
void _small_left_rotate(node*& n)
{
	// ���� ������� ��������� ����� ����� ������
	node* new_root = n->right;
	// ��������� �� ������ ��������� ������� �� ����, ������� ����� ����� �� ������ �����
	n->right = new_root->left;
	// ��������� �� ����� ��������� ��� ������ ����� ������������� �� ������ ������
	new_root->left = n;
	// ��������� �������� ������ ��� ������� �����
	_get_height(n);
	// ��������� ����������� ������� �����
	n = new_root;
	// ��������� �������� ������ ��� ������ �����
	_get_height(n);
}
void _small_right_rotate(node*& n)
{
	// ������ ������� �������� ��������� ���������� ������������ ����������
	// ���� ������ ��������� ����� ����� ������
	node* new_root = n->left;
	// ��������� �� ����� ��������� ������� �� ����, ������� ����� ������ �� ������ �����
	n->left = new_root->right;
	// ��������� �� ������ ��������� ��� ������ ����� ������������� �� ������ ������
	new_root->right = n;
	// ��������� �������� ������ ��� ������� �����
	_get_height(n);
	// ��������� ����������� ������� �����
	n = new_root;
	// ��������� �������� ������ ��� ������ �����
	_get_height(n);
}
void _big_left_rotate(node*& n)
{
	_small_right_rotate(n->right);
	_small_left_rotate(n);
}
void _big_right_rotate(node*& n)
{
	// ������ ������� �������� ��������� ���������� ������������ ����������
	_small_left_rotate(n->left);
	_small_right_rotate(n);
}

bool is_get()
{
	size_t realsize;
	char* value = new char[5];
	getenv_s(&realsize, value, 5, "REQUEST_METHOD");
	bool res = !_strcmpi(value, "GET");
	delete[] value;
	return res;
}

/**
 * ��������� ���������� � ����� ��������� �� ������������, �����������
 * ������� POST
 */
size_t get_content_length()
{
	size_t realsize;
	char* value = new char[11];
	getenv_s(&realsize, value, 11, "CONTENT_LENGTH");
	size_t size;
	if (!realsize) size = 0;
	else sscanf_s(value, "%d", &size);
	delete[] value;
	return size;
}

/**
 * ��������� ������ �� ����� � �������������� ����
 */
void get_form_data(char*& data)
{
	delete[] data;
	if (is_get())
	{
		size_t realsize;
		char* value = new char[65536];
		getenv_s(&realsize, value, 65536, "QUERY_STRING");
		data = new char[realsize + 1];
		strcpy_s(data, realsize + 1, value);
		delete[] value;
	}
	else
	{
		size_t buf_size = get_content_length();
		data = new char[buf_size + 1];
		fread_s(
			data,
			buf_size + 1,
			sizeof(char),
			buf_size,
			stdin
		);
		data[buf_size] = 0;
	}
}

/**
 * ��������� �������� ����������� ���������, ����������� �� ������������
 */
void get_param_value(char*& value, const char* param_name, const char* data)
{
	delete[] value;
	value = nullptr;
	char* str = _strdup(data);
	char* tmp = str;
	char* cont;
	while (char* part = strtok_s(tmp, "&", &cont))
	{
		tmp = nullptr;
		char* val;
		char* key = strtok_s(part, "=", &val);
		if (!_strcmpi(param_name, key))
		{
			str_decode(value, val);
			//value = _strdup(val);
			delete[] str;
			return;
		}
	}
	delete[] str;
	value = new char[1];
	value[0] = 0;
}

/**
 * �������������� ���������� ������
 */
void str_decode(char*& dec_str, const char* enc_str)
{
	char* res = new char[strlen(enc_str) + 1];
	int i = 0, j = 0;
	while (enc_str[i])
	{
		if (enc_str[i] == '+')
		{
			res[j] = ' ';
		}
		else
		{
			if (enc_str[i] == '%')
			{
				char ch[3] = { enc_str[i + 1], enc_str[i + 2], 0 };
				int c;
				sscanf_s(ch, "%X", &c);
				res[j] = c;
				i += 2;
			}
			else
			{
				res[j] = enc_str[i];
			}
		}
		i++;
		j++;
	}
	res[j] = 0;
	size_t len = strlen(res) + 1;
	delete[] dec_str;
	dec_str = new char[len];
	strcpy_s(dec_str, len, res);
	delete[] res;
}