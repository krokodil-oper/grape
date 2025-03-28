#ifndef TEST_H
#define TEST_H

#include <QWidget>

// Так выглядит стандартный .h файл класса с реализацией
// графического интерфейса

namespace Ui {
class Test;
}

class Test : public QWidget /* <- родитель каждого класса имеющего ui,
    без родителя большинсво объектов не сможет работать с указателем
    на наш объект */
{
    Q_OBJECT // <- макрос для работы некоторых функций qt, он обязателен

public:
    explicit Test(QWidget *parent = nullptr); // конструктор
    ~Test(); // деструктор

private slots: // <- кастомный модификатор доступа от qt
    // здесь пишется объявление методов, т.е всех функций

    void on_pushButton_clicked(); /* <-
        функция которая вызовется при нажатии на кнопку
        её можно увидеть в src/test/test.ui
        если открыть его в qt creator
    */

private:
    Ui::Test *ui; // объект позволяющий взаимодействие с интерфейсов страницы, посже объясню

};

#endif // TEST_H
