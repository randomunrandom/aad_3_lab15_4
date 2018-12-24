/*
 * created by Danil Kireev, PFUR NFI-201, 4.12.18, 09:00
 */
#include <iostream>
#include <ctime>

using namespace std;

/*
 *  №4
 *  программа удаляет дубликаты из связаного списка
 */

struct list{
    int value;
    list* previous;
    list* next;
};

int main() {
    srand(time(nullptr));
    list *lst = nullptr, *tmp_ptr1, *tmp_ptr2;
    int i, tmp_int,  n, choice;
    cout << "Программа удаляет дубликаты из связаного списка" << endl;
    cout << "введите размер списка: ";
    cin >> n;
    while(n <= 0) {
        cout << "введите размер списка не меньше 1: ";
        cin >> n;
    }
    cout << "Выберите тип ввода:\n- *0:заполнение случайными числами*\n-  1:заполнение вручную" << endl;
    cin >> choice;
    switch(choice) {
        case 0: {
            for (int ii = 0; ii < n; ++ii) {
                tmp_int = rand()%100;
                cout << "введите значение "<< ii+1 << "-го элемента : " << tmp_int << endl;
                if(ii==0) {
                    lst = new list;
                    lst->value = tmp_int;
                    lst->previous = lst;
                    lst->next = lst;
                }
                else {
                    tmp_ptr1 = new list;
                    tmp_ptr1->value = tmp_int;
                    tmp_ptr1->previous = lst->previous;
                    tmp_ptr1->next = lst;
            
                    tmp_ptr2 = lst;
                    do{
                        tmp_ptr2 = tmp_ptr2->next;
                    }while(tmp_ptr2->next != lst);
            
                    tmp_ptr2->next=tmp_ptr1;
                    lst->previous = tmp_ptr1;
                }
            }
            break;
        }
        case 1: {
            for (int ii = 0; ii < n; ++ii) {
                cout << "введите значение "<< ii+1 << "-го элемента : ";
                cin >> tmp_int;
                if(ii==0) {
                    lst = new list;
                    lst->value = tmp_int;
                    lst->previous = lst;
                    lst->next = lst;
                }
                else {
                    tmp_ptr1 = new list;
                    tmp_ptr1->value = tmp_int;
                    tmp_ptr1->previous = lst->previous;
                    tmp_ptr1->next = lst;
                    
                    tmp_ptr2 = lst;
                    do{
                        tmp_ptr2 = tmp_ptr2->next;
                    }while(tmp_ptr2->next != lst);
                    
                    tmp_ptr2->next=tmp_ptr1;
                    lst->previous = tmp_ptr1;
                }
            }
            break;
        }
        default:break;
    }
    cout << "полученый список: " << endl;
    tmp_ptr1 = lst;
    i=0;
    do{
        cout << i << ": ";
        cout << tmp_ptr1->value << ", ";
        cout << tmp_ptr1 << ", ";
        cout << tmp_ptr1->previous << ", ";
        cout << tmp_ptr1->next << endl;
        tmp_ptr1 = tmp_ptr1->next;
        i++;
    }while(tmp_ptr1 != lst);
    
    tmp_ptr1 = lst->next;
    i=0;
    do{
        tmp_ptr2 = lst;
        do{
            if(tmp_ptr2->value == tmp_ptr1->value) {
                (tmp_ptr2->previous)->next = tmp_ptr2->next;
                (tmp_ptr2->next)->previous = tmp_ptr2->previous;
                delete tmp_ptr2;
                break;
            }
            tmp_ptr2 = tmp_ptr2->next;
        }while((tmp_ptr2->previous) != (tmp_ptr1->previous));
        tmp_ptr1 = tmp_ptr1->next;
        i++;
    }while(tmp_ptr1 != lst);
    cout << "список без дубликатов: " << endl;
    tmp_ptr1 = lst;
    i=0;
    do{
        cout << i << ": ";
        cout << tmp_ptr1->value << ", ";
        cout << tmp_ptr1 << ", ";
        cout << tmp_ptr1->previous << ", ";
        cout << tmp_ptr1->next << endl;
        tmp_ptr1 = tmp_ptr1->next;
        i++;
    }while(tmp_ptr1 != lst);
    return 0;
}
