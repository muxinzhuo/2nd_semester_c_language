// DBBBD DABBB
//6.1
struct ListNode *readlist()
{
    int val;
    struct ListNode *head = NULL, *tail = NULL;

    while (scanf("%d", &val) == 1 && val != -1)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->data = val;
        newNode->next = NULL;

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

struct ListNode *getodd(struct ListNode **L)
{
    struct ListNode *oddHead = NULL, *oddTail = NULL;
    struct ListNode *curr = *L, *prev = NULL;

    while (curr)
    {
        if (curr->data % 2 == 1)
        {
            // 拆下奇数节点
            struct ListNode *oddNode = curr;
            if (prev)
            {
                prev->next = curr->next;
            }
            else
            {
                // 奇数在头部
                *L = curr->next;
            }
            curr = curr->next;

            // 插入奇数链表
            oddNode->next = NULL;
            if (!oddHead)
            {
                oddHead = oddTail = oddNode;
            }
            else
            {
                oddTail->next = oddNode;
                oddTail = oddNode;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return oddHead;
}

//6.2
struct stud_node *createlist() {
    struct stud_node *head = NULL, *tail = NULL;

    int num, score;
    char name[20];

    while (scanf("%d", &num) == 1 && num != 0) {
        scanf("%s %d", name, &score);
        struct stud_node *newNode = (struct stud_node *)malloc(sizeof(struct stud_node));
        newNode->num = num;
        newNode->score = score;
        newNode->next = NULL;
        strcpy(newNode->name, name);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

struct stud_node *deletelist(struct stud_node *head, int min_score) {
    struct stud_node *curr = head, *prev = NULL;

    while (curr) {
        if (curr->score < min_score) {
            struct stud_node *toDelete = curr;
            if (prev) {
                prev->next = curr->next;
            } else {
                // 删除头结点
                head = curr->next;
            }
            curr = curr->next;
            free(toDelete);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

//6.3
struct ListNode *createlist() {
    int val;
    struct ListNode *head = NULL;

    while (scanf("%d", &val) == 1 && val != -1) {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    return head;
}

//6.4
struct ListNode *createlist() {
    int val;
    struct ListNode *head = NULL, *tail = NULL;

    while (scanf("%d", &val) == 1 && val != -1) {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->data = val;
        newNode->next = NULL;

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

struct ListNode *deleteeven(struct ListNode *head) {
    struct ListNode *curr = head, *prev = NULL;

    while (curr) {
        if (curr->data % 2 == 0) {
            struct ListNode *toDelete = curr;
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;  // 删除头结点
            }
            curr = curr->next;
            free(toDelete);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}