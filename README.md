# mukha_spisky_bzbzbzbz
// nomer processa - nomer zadachi - dlya KR na lmske dopolnitelno vstavlyayte functii s prefixom my_
// gcc main.c my_io.c
// or
// gcc main_list_without_tail.c

1) Для списка определенного в заголовочном файле list.h: typedef struct Node {int data, struct Node * next} Node; typedef struct List { Node * head; Node * tail; } List; Написать функцию с именем process, осуществляющую модификацию списка в соответствии с условием, представленным далее. В качестве единственного параметра функция должна принимать указатель на экземпляр структуры List. Модификацию списка необходимо выполнить путем перемещения узлов за счёт изменения указателя next. Изменение атрибута data не допускается (за исключением новых узлов, созданных в вашей функции). Условие: После каждого отрицательного элемента списка вставить новый элемент со значением data, равным модулю аналогичного значения рассматриваемого узла. Например, [1, -2, 3, 4, -5] -> [1, -2, 2, 3, 4, -5, 5].
2) Для списка определенного в заголовочном файле list.h: typedef struct Node {int data, struct Node * next} Node; typedef struct List { Node * head; Node * tail; } List; Написать функцию с именем process, осуществляющую модификацию списка в соответствии с условием, представленным далее. В качестве единственного параметра функция должна принимать указатель на экземпляр структуры List. Модификацию списка необходимо выполнить путем перемещения узлов за счёт изменения указателя next. Изменение атрибута data не допускается (за исключением новых узлов, созданных в вашей функции). Условие: Переместить узлы списка таким образом, чтобы в его начале шли узлы с неотрицательным значением data ( включая 0 ) , а в конце списка все узлы с отрицательным значением. Расположение элементов с одинаковым знаком друг относительно друга необходимо сохранить. Например [1,2,-3,0,-5,6] преобразовать в [1,3,0,6,-2,5]. Модификацию списка необходимо выполнить путём перемещения узлов за счёт изменения указателя next. Изменение аттрибута не допускается, за исключением создания новых узлов
3) Для списка определенного в заголовочном файле list.h: typedef struct Node {int data, struct Node * next} Node; typedef struct List { Node * head; Node * tail; } List; Написать функцию с именем process, осуществляющую модификацию списка в соответствии с условием, представленным далее. В качестве единственного параметра функция должна принимать указатель на экземпляр структуры List. Модификацию списка необходимо выполнить путем перемещения узлов за счёт изменения указателя next. Изменение атрибута data не допускается (за исключением новых узлов, созданных в вашей функции). Условие: Попарно поменять местами все элементы списка. То есть, поменять первый элемент со вторым, третий с четвёртым и т.д. Если количество элементов нечётно - последний элемент оставить на месте. Например : [1,2,3,4,5,6,7] преобразовать в [2,1,4,3,6,5,7]. Модификацию списка необходимо выполнить путём перемещения узлов за счёт изменения указателя next. Изменение аттрибута не допускается, за исключением создания новых узлов
4) Для списка определенного в заголовочном файле list.h: typedef struct Node {int data, struct Node * next} Node; typdef struct List { Node * head; Node * tail; } List; Написать функцию с именем process, осуществляющую модификацию списка в соответствии с условием, представленным далее. В качестве единственного параметра функция должна принимать указатель на экземпляр структуры List. Модификацию списка необходимо выполнить путем перемещения узлов за счёт изменения указателя next. Изменение атрибута data не допускается (за исключением новых узлов, созданных в вашей функции). Условие: Перед каждым элементом списка, кратным 3, вставить результат его деления на 3. Например [69,11, 1488,228, 17] преобразовать в [23,69,11,496,1488,76,228,17] . Модификацию списка необходимо выполнить путём перемещения узлов за счёт изменения указателя next. Изменение аттрибута не допускается, за исключением создания новых узлов

5) Для списка определенного в заголовочном файле list.h: typedef struct Node {int data, struct Node * next; struct Node * prev} Node; typedef struct List { Node * head} List; Написать функцию с именем process, осуществляющую модификацию списка в соответствии с условием, представленным далее. В качестве единственного параметра функция должна принимать указатель на экземпляр структуры List. Модификацию списка необходимо выполнить путем перемещения узлов за счёт изменения указателя next. Изменение атрибута data не допускается (за исключением новых узлов, созданных в вашей функции). Условие: Перед каждым элементом списка, кратным 3, вставить результат его деления на 3. Например [69,11, 1488,228, 17] преобразовать в [23,69,11,496,1488,76,228,17] . Модификацию списка необходимо выполнить путём перемещения узлов за счёт изменения указателя next. Изменение аттрибута не допускается, за исключением создания новых узлов
6) Для списка определенного в заголовочном файле list.h: typedef struct Node {int data, struct Node * next; struct Node * prev} Node; typedef struct List { Node * head} List; Написать функцию с именем process, осуществляющую модификацию списка в соответствии с условием, представленным далее. В качестве единственного параметра функция должна принимать указатель на экземпляр структуры List. Модификацию списка необходимо выполнить путем перемещения узлов за счёт изменения указателя next. Изменение атрибута data не допускается (за исключением новых узлов, созданных в вашей функции). Условие : Поменять местами соседние элементы. Если количество элементов нечетное, последний ни с кем не менять (оставить на месте) Пример: [1,4,-6,5,7] -> [4,1,5,-6,7] . Модификацию списка необходимо выполнить путём перемещения узлов за счёт изменения указателя next. Изменение аттрибута не допускается, за исключением создания новых узлов
