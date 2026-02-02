#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    struct Student *next;
}Student;

/* สร้าง node ใหม่ */
Student* create_node(int id, char *name) {
    Student *new_node = (Student *)malloc(sizeof(Student));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

/* เพิ่ม node ต่อท้าย list */
void insert_node(Student **head, int id, char *name) {
    Student *new_node = create_node(id, name);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Student *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

/* แสดงข้อมูลทั้งหมด */
void print_list(Student *head) {
    Student *temp = head;
    while (temp != NULL) {
        printf("%d %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

/* ลบ linked list ทั้งหมด */
void free_list(Student *head) {
    Student *temp;
    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
}

int main(int argc, char *argv[]) {
    Student *head = NULL;

    /* รับ input จาก command line */
    for (int i = 1; i < argc; i += 2) {
        int id = atoi(argv[i]);
        char *name = argv[i + 1];
        insert_node(&head, id, name);
    }

    /* แสดงผล */
    print_list(head);

    /* ลบ list */
    free_list(head);
    head = NULL;

    return 0;
}
