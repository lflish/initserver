struct hlist_head {
        struct hlist_node *first;
};

struct hlist_node {
        struct hlist_node *next;
	struct hlist_node *pprev;
};

static inline void __hlist_del(struct hlist_node *n)
{
        struct hlist_node *next = n->next;
        struct hlist_node *pprev = n->pprev;


	//问题来了 如果这里n是第一个节点，那么pprev就是NULL
	//第二个节点如何转变为第一个节点呢，无能为力,除非把头结点也传过来
        pprev->next = next;

        if (next)
                next->pprev = pprev;
}

static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h)
{
        struct hlist_node *first = h->first;
        n->next = first;
        if (first)
                first->pprev = n;
        h->first = n;

	//这里就要出问题了，ppre指向的是(struct hlist_node*)类型， 然而h的类型是 hlist_head
	//或者这里就不来设定第一个节点的pprev了
	//单单这里来说 已经可以有拒绝 *ppre的类型而改用 **ppre了，因为第一个节点的ppre是NULL的用
        n->pprev = &h->first;
}
