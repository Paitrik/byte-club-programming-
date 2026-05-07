#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);        // dummy head
    ListNode* cur = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }

        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
    }
    return dummy.next;
}

// Build linked list from vector
ListNode* build(vector<int>& v) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int x : v) { cur->next = new ListNode(x); cur = cur->next; }
    return dummy.next;
}

// Print linked list
void print(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int m; cin >> m;
    vector<int> b(m);
    for (auto& x : b) cin >> x;

    ListNode* l1 = build(a);
    ListNode* l2 = build(b);
    print(addTwoNumbers(l1, l2));
}
