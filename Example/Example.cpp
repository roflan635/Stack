// Example.cpp : В этом файле вы можете отлаживать ваше задание.
// Подклчайте нужные библиотеки, пишите код, как в обычной программе

#include <iostream>
#include "Task.h"

// Task.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "Task.h"

struct Point // структура, описывающая точку
{
    int x, y;
};

struct StackItem // собственно сам элемент стека
{
    Point point; // точка
    StackItem* next;  // указатель на следующий элемент в списке
};

StackItem* stack = nullptr; // указатель на вершину стека, изначально стек пуст

bool IsEmpty() // функция проверяет пуст ли стек
{
    return stack == nullptr;
}

void Push(const Point& point) // Добавление точки в стек (аналог функции AddFirst линейного списка)
{
    //StackItem* item = new StackItem{ point, stack }; // этой строчкой можно заменить следующие 2
    StackItem* item = new StackItem; // создаем новый элемент стека
    item->point = point; //инициализируем данные в элементе
    item->next = stack; //корректируем указатель на следующий элемент
    stack = item; // теперь вершина стека указывает на добавленный элемент
}

Point Pop() // извлекает элемент из стека и возвращает его значение
{
    Point result; // здесь будет результат
    StackItem* temp; // временная переменная
    if (stack == nullptr) // если стек пуст
    {
        result.x = 0;   // то операция извлечения невозможна
        result.y = 0;   // пока мы не умеем реагировать на такую ситуацию
        return result;  // поэтому пока возвращаем Point {0,0}
    }
    result = stack->point; //записываем возвращаемые данные
    temp = stack;   // запоминаем элемент на вершине стека
    stack = temp->next; // перемещаем вершину стека на следующий за извлекаемым элемент
    delete temp;    // освобождаем память, занятую элементом на вершине
    return result; // возвращаем результат
}

Point FindPosition(char maze[15][15])
{
    Point p = { -1 };
    for (int i = 0; i < 15; i++)  // цикл пробегает массив по строкам
    {
        for (int j = 0; j < 15; j++) // цикл пробегает массив по столбцам
        {
            if (maze[i][j] == 'P')
            {
                return p = { i,j };
            }
        }
    }
    return p;
}

bool isMazeValid(Point player, char maze[15][15])
{
    Push(player); // помещаем координаты затравочного пикселя в стек
    while (!IsEmpty()) // пока стек не пуст
    {
        Point p = Pop();  // извлекаем пиксел из стека
        if (maze[p.x][p.y] == 'E')
            return true;
        if (maze[p.x][p.y] != '?') // если ему не присвоено значение заливки
            maze[p.x][p.y] = '?'; // заливаем

        if (maze[p.x + 1][p.y] != '?' && maze[p.x + 1][p.y] != '#') // проверяем пиксел справа от текущего
            Push(Point{ p.x + 1, p.y }); // если он не закрашен и не является границей, то помещаем его координаты в стек
        if (maze[p.x - 1][p.y] != '?' && maze[p.x - 1][p.y] != '#') // то же для левого
            Push(Point{ p.x - 1, p.y });
        if (maze[p.x][p.y - 1] != '?' && maze[p.x][p.y - 1] != '#') // то же для верхнего
            Push(Point{ p.x, p.y - 1 });
        if (maze[p.x][p.y + 1] != '?' && maze[p.x][p.y + 1] != '#') // то же для нижнего
            Push(Point{ p.x, p.y + 1 });
    }
    return false;
}

bool CanMoveToExit(char maze[15][15])
{
    Point player = FindPosition(maze);
    if (player.x == -1) return false;
    isMazeValid(player, maze);
    return true;
}


int main()
{
char m3[15][15] = {
"##############",
"#E#          #",
"# # ######## #",
"# # #      # #",
"# # # #### # #",
"# # # #  # # #",
"# # # #P # # #",
"# # # ## # # #",
"# # # ## # # #",
"# # #    # # #",
"# # ###### # #",
"# #        # #",
"############ #",
"#            #",
"##############",
};
bool result;
result = CanMoveToExit(m3);
std::cout << result;
}

