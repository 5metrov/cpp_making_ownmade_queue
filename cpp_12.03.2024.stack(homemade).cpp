#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next, *prev;

    Node(int _data) : data(_data) {}
};

class Stack {
public:
    Node* up, * down;

    Stack() {
        this->down = NULL;
        this->up = NULL;
    }

    void push_up(int data) { //создание функций для работы с однонаправленной очереди
        Node* tmp_node = new Node(data);
        if (up != NULL) { 
            tmp_node->prev = up;
            up = tmp_node;
        }
        else {
            up = tmp_node;
        }
        if (down == NULL) {
            down = tmp_node;
        }
        
    }

    void pop_up() {
        Node* tmp_node = up;
        if (up == NULL) {
            cout << "Нет объектов для удаления";
            return;
        }
        if (up == down) {
            delete up;
            up = down = NULL;
            return;
        }

        up = tmp_node->prev;
        delete tmp_node;
    }

    void show_all() {
        Node* tmp_node = up;
        int flag = 0;
        while (true) {
            if (tmp_node != NULL) {
                cout << tmp_node->data << ' ';
                tmp_node = tmp_node->prev;
                flag++;
            }
            else { 
                cout << endl << "Колличество элементов в стэке: " << flag << endl; 
                break; 
            }
        }
    }
};

void osn0() {
    Stack st;
    st.push_up(4);
    st.push_up(5);
    st.push_up(6);
    st.push_up(7);
    st.push_up(8);

    st.pop_up();

    st.show_all();
}

int main(){
    setlocale(LC_ALL, "ru");
    osn0();
    return 0;
}
