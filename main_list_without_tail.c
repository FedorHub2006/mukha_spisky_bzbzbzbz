#include <stdio.h>
#include <stdlib.h>

// Определение структур Node и List
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List {
    Node *head;
} List;

// Функция для создания нового узла
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Функция для вставки узла перед узлом current
void insertBeforeNode(List *list, Node *current, int newData) {
    Node *newNode = createNode(newData);
    
    // Устанавливаем ссылки для нового узла
    newNode->next = current;
    newNode->prev = current->prev;

    // Обновляем ссылки для соседей
    if (current->prev != NULL) {
        current->prev->next = newNode;
    } else {
        // Если это первый узел, обновляем голову списка
        list->head = newNode;
    }
    current->prev = newNode;
}

// Функция для обработки списка
void process5(List *list) {
    Node *current = list->head;

    while (current != NULL) {
        if (current->data % 3 == 0) {
            int newData = current->data / 3;
            insertBeforeNode(list, current, newData);
            current = current->next;  // Переход к следующему элементу (уже перемещенный)
        }
        current = current->next;  // Переход к следующему элементу
    }
}
void process6(List *list) {
    if (list->head == NULL || list->head->next == NULL) {
        return; // Если список пуст или состоит из одного элемента
    }
    
    Node *current = list->head;

    // Перебираем список парами
    while (current != NULL && current->next != NULL) {
        Node *first = current;           // Указатель на первый узел
        Node *second = current->next;    // Указатель на второй узел

        // Меняем местами узлы first и second
        first->next = second->next; // У первого теперь указывает на третий узел
        second->next = first;        // Второй теперь указывает на первый узел

        // Обновляем указатели
        if (first->next != NULL) {
            first->next->prev = first; // Новый следующий элемент теперь указывает на первый
        }

        second->prev = first->prev; // Второй теперь указывает на предыдущий узел первого

        // Обновляем next и prev для первого
        first->prev = second;  // Первый теперь указывает на второй

        // Если первый был головой списка, обновляем голову
        if (first == list->head) {
            list->head = second;
        } else if (second->prev != NULL) {
            second->prev->next = second; // Обновляем следующий у предыдущего узла к текущему второму
        }

        // Переход к следующей паре
        current = first->next; // Переход к узлу после обработанной пары
    }
}
// Функция для печати списка
void printList(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Пример использования
int main() {
    // Создаем список
    List list;
    list.head = NULL;

    // Добавляем элементы в список (пример)
    Node *node1 = createNode(1);
    Node *node2 = createNode(4);
    Node *node3 = createNode(-6);
    Node *node4 = createNode(5);
    Node *node5 = createNode(7);

    list.head = node1;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    printf("Original list:\n");
    printList(&list);

    // Обработка списка
    process6(&list);

    printf("Processed list:\n");
    printList(&list);

    return 0;
}
