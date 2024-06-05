// Lab 6.1_ABs-324 SinkoAE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//// Задание 1.1
//#include <iostream> // подключение библиотеки для ввода-вывода
//#include <vector>   // подключение библиотеки для использования векторов
//#include <map>  // подключение библиотеки для использования словарей (map)
//#include <ctime>    // подключение библиотеки для работы с временем
//#include <cstdlib>  // подключение библиотеки для работы с функцией rand()
//#include <locale.h> //подключение библиотеки для задач связанных из локализацией
//
//using namespace std;    // использование стандартного пространства имен
//
//// Функция для заполнения матрицы случайными числами
//void fillMatrixWithRandomNumbers(vector<vector<int>>& matrix) {
//    for (int i = 0; i < matrix.size(); ++i) {   // цикл по строкам матрицы
//        for (int j = 0; j < matrix[i].size(); ++j) {   // цикл по столбцам матрицы
//            matrix[i][j] = rand() % 101;    // заполнение матрицы случайными числами от 0 до 100 (по условию)
//        }
//    }
//}
//
//// Функция для поиска возрастающих последовательностей в матрице
//map<int, vector<int>> findIncreasingSequences(const vector<vector<int>>& matrix) {
//    map<int, vector<int>> sequences;
//    for (int i = 0; i < matrix.size(); ++i) {   // цикл по строкам матрицы
//        int start = 0;  // начальный индекс текущей последовательности
//        for (int j = 1; j < matrix[i].size(); ++j) {    // цикл по столбцам матрицы
//            if (matrix[i][j] <= matrix[i][j - 1]) { // если текущий элемент меньше предыдущего
//                if (j - start > 1) {    // если длина текущей последовательности больше 1
//                    vector<int> sequence(matrix[i].begin() + start, matrix[i].begin() + j); // создание вектора для хранения последовательности
//                    sequences[matrix[i][start]] = sequence; // добавление последовательности в словарь
//                }
//                start = j;  // обновление начала текущей последовательности
//            }
//        }
//        if (matrix[i].size() - start > 1) { // если длина последней последовательности больше 1
//            vector<int> sequence(matrix[i].begin() + start, matrix[i].end());   // создание вектора для хранения последней последовательности
//            sequences[matrix[i][start]] = sequence; // добавление последней последовательности в словарь
//        }
//    }
//    return sequences;
//}
//
//// Функция для вывода матрицы на экран
//void printMatrix(const vector<vector<int>>& matrix) {
//    for (int i = 0; i < matrix.size(); ++i) {   // цикл по строкам матрицы
//        for (int j = 0; j < matrix[i].size(); ++j) {    // цикл по столбцам матрицы
//            cout << matrix[i][j] << " ";    // вывод элемента матрицы на экран
//        }
//        cout << endl;
//    }
//}
//
//// Функция для вывода последовательностей на экран
//void printSequences(const map<int, vector<int>>& sequences) {
//    for (const auto& seq : sequences) { // цикл по всем последовательностям в словаре
//        for (int num : seq.second) {    // цикл по элементам текущей последовательности
//            cout << num << " "; // вывод элемента последовательности на экран
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");   //установка русской локали
//    srand(time(0)); // инициализация генератора случайных чисел текущим временем
//
//    int M, N;   // объявление переменных для количества строк и столбцов матрицы
//    cout << "Введите количество строк (M): ";   // вывод сообщения на экран о необходимости ввести количество строк
//    cin >> M;   // ввод количества строк с клавиатуры
//    cout << "Введите количество столбцов (N): ";    // вывод сообщения на экран о необходимости ввести количество столбцов
//    cin >> N;   // ввод количества столбцов с клавиатуры
//
//    vector<vector<int>> matrix(M, vector<int>(N));  // объявление двумерного вектора (матрицы) размером M x N
//
//    // объявление двумерного вектора (матрицы) с именем matrix
//    // vector<vector<int>> - matrix является вектором векторов целых чисел
//    // M и N - это размеры матрицы, которые были введены с клавиатуры
//    // vector<int>(N) создает временный вектор целых чисел размера N, который используется для инициализации каждой строки матрицы
//    // (M, vector<int>(N)) используется для инициализации матрицы размером M x N, заполняя каждую строку вектором из N нулей
//
//    map<int, vector<int>> sequences;    // объявление словаря для хранения найденных последовательностей
//
//    // объявление словаря sequences, который используется для хранения найденных последовательностей
//    // map<int, vector<int>> - ключами словаря являются целые числа, а значениями - векторы целых чисел
//    // словарь используется для хранения последовательностей, где ключ - первый элемент последовательности, а значение - сама последовательность
//
//    fillMatrixWithRandomNumbers(matrix);
//    sequences = findIncreasingSequences(matrix);
//
//    cout << "Матрица:" << endl;
//    printMatrix(matrix);
//
//    cout << "Найденные последовательности:" << endl;
//    printSequences(sequences);
//
//    return 0;
//}

// Задание 1.2
//#include <iostream> // подключение библиотеки для ввода-вывода
//#include <vector>   // подключение библиотеки для использования векторов
//#include <map>  // подключение библиотеки для использования словарей (map)
//#include <ctime>    // подключение библиотеки для работы с временем
//#include <cstdlib>  // подключение библиотеки для работы с функцией rand()
//#include <locale.h> //подключение библиотеки для задач связанных из локализацией
//
//using namespace std;    // использование стандартного пространства имен
//
//// Функция для заполнения матрицы случайными числами
//void fillMatrixWithRandomNumbers(vector<vector<int>>& matrix) {
//    for (int i = 0; i < matrix.size(); ++i) {   // цикл по строкам матрицы
//        for (int j = 0; j < matrix[i].size(); ++j) {    // цикл по столбцам матрицы
//            matrix[i][j] = rand() % 101 - 50;   // заполнение матрицы случайными числами в диапазоне [-50, 50] (по условию)
//        }
//    }
//}
//
//// Функция для подсчета количества элементов в матрице
//map<int, int> countElements(const vector<vector<int>>& matrix) {
//    map<int, int> elementCount; // объявление словаря для подсчета вхождений элементов
//    for (int i = 0; i < matrix.size(); ++i) {   // цикл по строкам матрицы
//        for (int j = 0; j < matrix[i].size(); ++j) {    // цикл по столбцам матрицы
//            elementCount[matrix[i][j]]++;   // увеличение счетчика вхождений текущего элемента
//        }
//    }
//    return elementCount;
//}
//
//// Функция для вывода матрицы на экран
//void printMatrix(const vector<vector<int>>& matrix) {
//    for (int i = 0; i < matrix.size(); ++i) {   // цикл по строкам матрицы
//        for (int j = 0; j < matrix[i].size(); ++j) {    // цикл по столбцам матрицы
//            cout << matrix[i][j] << " ";    // вывод элемента матрицы на экран
//        }
//        cout << endl;
//    }
//}
//
//// Функция для вывода количества элементов на экран
//void printElementCount(const map<int, int>& elementCount) {
//    for (const auto& elem : elementCount) { // цикл по всем элементам словаря
//        cout << elem.first << ": " << elem.second << endl;  // вывод элемента и его количества на экран
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    srand(time(0));
//
//    int M, N;   // объявление переменных для количества строк и столбцов матрицы
//    cout << "Введите количество строк (M): ";   // вывод сообщения на экран о необходимости ввести количество строк
//    cin >> M;   // ввод количества строк с клавиатуры
//    cout << "Введите количество столбцов (N): ";    // вывод сообщения на экран о необходимости ввести количество столбцов
//    cin >> N;   // ввод количества столбцов с клавиатуры
//
//    vector<vector<int>> matrix(M, vector<int>(N));  // объявление двумерного вектора (матрицы) размером M x N
//
//    // объявление двумерного вектора (матрицы) с именем matrix
//    // vector<vector<int>> - matrix является вектором векторов целых чисел
//    // M и N - это размеры матрицы, которые были введены с клавиатуры
//    // vector<int>(N) создает временный вектор целых чисел размера N, который используется для инициализации каждой строки матрицы
//    // (M, vector<int>(N)) используется для инициализации матрицы размером M x N, заполняя каждую строку вектором из N нулей
//
//    map<int, int> elementCount; // объявление словаря для подсчета вхождений элементов
//
//    // map - шаблонный класс, который реализует ассоциативный массив (словарь), где каждый элемент имеет ключ и значение
//    // <int, int> - параметры шаблона, указывающие типы ключей и значений в словаре
//    // ключ будет представлять уникальный элемент из матрицы, а значение - количество его вхождений в матрицу
//    // elementCount - имя словаря
//
//    fillMatrixWithRandomNumbers(matrix);
//    elementCount = countElements(matrix);
//
//    cout << "Матрица:" << endl;
//    printMatrix(matrix);
//
//    cout << "Количество элементов:" << endl;
//    printElementCount(elementCount);
//
//    return 0;
//}

// Задание 1.3
#include <iostream> // подключение библиотеки для ввода-вывода
#include <vector>   // подключение библиотеки для использования векторов
#include <map>  // подключение библиотеки для использования словарей (map)
#include <set>  // подключение библиотеки для использования множеств
#include <cstdlib>  // подключение библиотеки для работы с функцией rand()
#include <locale.h> //подключение библиотеки для задач связанных из локализацией

using namespace std;    // использование стандартного пространства имен

const int BOARD_SIZE = 8;   // задается размер шахматной доски

// Функция для вывода шахматной доски
void printBoard(vector<vector<char>> board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {  // проходим по строкам доски
        for (int j = 0; j < BOARD_SIZE; ++j) {  // проходим по столбцам доски
            cout << board[i][j] << " "; // вывод символа соответствующей ячейки доски
        }
        cout << endl;   // переход на новую строку после окончания строки доски
    }
}

// Функция для определения атакованных ферзями клеток
set<pair<int, int>> getAttackedCells(int kingX, int kingY, vector<pair<int, int>> queens) {
    set<pair<int, int>> attackedCells;  // создаем множество для хранения атакованных клеток

    for (auto queen : queens) { // проходим по координатам ферзей
        // Если ферзь атакует короля по горизонтали, вертикали или диагонали
        if (queen.first == kingX || queen.second == kingY || abs(queen.first - kingX) == abs(queen.second - kingY)) {
            attackedCells.insert(queen);    // то добавляем координаты атакующего ферзя в множество
        }
    }

    return attackedCells;   // возвращаем множество атакованных клеток
}

int main() {
    setlocale(LC_ALL, "rus");   //установка русской локали
    const int BOARD_SIZE = 8;   // размер шахматной доски
    vector<pair<int, int>> queens;  // вектор для хранения координат ферзей
    pair<int, int> king;    // пара для хранения координат короля

    // Заполнение поля фигурами случайным образом
    for (int i = 0; i < 3; ++i) {
        queens.push_back(make_pair(rand() % BOARD_SIZE, rand() % BOARD_SIZE));  // добавляем случайные координаты ферзя
    }

    king = make_pair(rand() % BOARD_SIZE, rand() % BOARD_SIZE); // генерируем случайные координаты короля

    // Создание шахматной доски
    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, '.'));  // инициализируем доску пустыми клетками

    // Пометка ферзей на доске
    for (auto queen : queens) {
        board[queen.first][queen.second] = 'Q'; // помечаем клетку ферзя на доске
    }

    // Пометка короля на доске
    board[king.first][king.second] = 'K';   // помечаем клетку короля на доске

    // Вывод фигур с их координатами
    cout << "Ферзи и их координаты:" << endl;
    for (int i = 0; i < queens.size(); ++i) {
        cout << "Ферзь " << i + 1 << ": (" << queens[i].first << ", " << queens[i].second << ")" << endl;   // вывод координат ферзей
    }

    // Вывод шахматной доски
    cout << "Шахматная доска:" << endl;
    printBoard(board);  // вывод шахматной доски

    // Определение координат ферзей, которые атакуют короля
    set<pair<int, int>> attackedCells = getAttackedCells(king.first, king.second, queens);  // получаем атакованные клетки

    // Вывод координат атакованных ферзями клеток
    cout << "Ферзи, которые атакуют короля:" << endl;
    for (auto cell : attackedCells) {
        cout << "(" << cell.first << ", " << cell.second << ")" << endl;    // вывод координат атакованных клеток
    }

    return 0;
}

// Добавление на поле коней и определение координат тех, которые атакуют короля
//#include <iostream> // подключение библиотеки для ввода-вывода
//#include <vector>   // подключение библиотеки для использования векторов
//#include <map>  // подключение библиотеки для использования словарей (map)
//#include <set>  // подключение библиотеки для использования множеств
//#include <cstdlib>  // подключение библиотеки для работы с функцией rand()
//#include <locale.h> //подключение библиотеки для задач связанных из локализацией
//
//using namespace std;    // использование стандартного пространства имен
//
//const int BOARD_SIZE = 8;   // задается размер шахматной доски
//
//// Функция для вывода шахматной доски
//void printBoard(vector<vector<char>> board) {
//    for (int i = 0; i < BOARD_SIZE; ++i) {  // проходим по строкам доски
//        for (int j = 0; j < BOARD_SIZE; ++j) {  // проходим по столбцам доски
//            cout << board[i][j] << " "; // вывод символа соответствующей ячейки доски
//        }
//        cout << endl;   // переход на новую строку после окончания строки доски
//    }
//}
//
//// Функция для определения атакованных ферзями клеток
//set<pair<int, int>> getAttackedCells(int kingX, int kingY, vector<pair<int, int>> queens) {
//    set<pair<int, int>> attackedCells;  // создаем множество для хранения атакованных клеток
//
//    for (auto queen : queens) { // проходим по координатам ферзей
//        // Если ферзь атакует короля по горизонтали, вертикали или диагонали
//        if (queen.first == kingX || queen.second == kingY || abs(queen.first - kingX) == abs(queen.second - kingY)) {
//            attackedCells.insert(queen);    // то добавляем координаты атакующего ферзя в множество
//        }
//    }
//
//    return attackedCells;   // возвращаем множество атакованных клеток
//}
//
//// Функция для определения атакованных конями клеток
//set<pair<int, int>> getAttackedKnights(int kingX, int kingY, vector<pair<int, int>> knights) {
//    set<pair<int, int>> attackedCells;  // создаем множество для хранения атакованных клеток
//
//    for (auto knight : knights) {   // цикл по всем коням
//        int dx = abs(knight.first - kingX); // вычисляем разницу координат по оси X
//        int dy = abs(knight.second - kingY);    // вычисляем разницу координат по оси Y
//        if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) { // если клетка атакована
//            attackedCells.insert(knight);   // добавляем ее в множество
//        }
//    }
//
//    return attackedCells;   // возвращаем множество атакованных клеток
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");   //установка русской локали
//    const int BOARD_SIZE = 8;   // размер шахматной доски
//    vector<pair<int, int>> queens;  // вектор для хранения координат ферзей
//    vector<pair<int, int>> knights; // вектор для хранения координат коней
//    pair<int, int> king;    // пара для хранения координат короля
//
//    // Добавление ферзей и коней на поле случайным образом
//    for (int i = 0; i < 5; ++i) {
//        queens.push_back(make_pair(rand() % BOARD_SIZE, rand() % BOARD_SIZE));  // добавляем случайные координаты ферзя
//        knights.push_back(make_pair(rand() % BOARD_SIZE, rand() % BOARD_SIZE)); // добавляем случайные координаты коня
//    }
//
//    king = make_pair(rand() % BOARD_SIZE, rand() % BOARD_SIZE); // генерируем случайные координаты короля
//    
//    // Создание шахматной доски
//    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, '.'));  // инициализируем доску пустыми клетками
//
//    for (auto queen : queens) {
//        board[queen.first][queen.second] = 'Q'; // расставляем ферзей на доске
//    }
//
//    for (auto knight : knights) {
//        board[knight.first][knight.second] = 'N';   // расставляем коней на доске
//    }
//
//    board[king.first][king.second] = 'K';   // расставляем короля на доске
//
//    cout << "Ферзи и их координаты:" << endl;
//    for (int i = 0; i < queens.size(); ++i) {
//        cout << "Ферзь " << i + 1 << ": (" << queens[i].first << ", " << queens[i].second << ")" << endl;   // вывод координат ферзей
//    }
//
//    cout << "Кони и их координаты:" << endl;
//    for (int i = 0; i < knights.size(); ++i) {
//        cout << "Конь " << i + 1 << ": (" << knights[i].first << ", " << knights[i].second << ")" << endl;  // вывод координат коней
//    }
//
//    cout << "Шахматная доска:" << endl;
//    printBoard(board);  // вывод шахматную доску
//
//    set<pair<int, int>> attackedQueens = getAttackedCells(king.first, king.second, queens); // получаем атакованные ферзями клетки
//    set<pair<int, int>> attackedKnights = getAttackedKnights(king.first, king.second, knights); // получаем атакованные конями клетки
//
//    cout << "Ферзи, которые атакуют короля:" << endl;
//    for (auto cell : attackedQueens) {
//        cout << "(" << cell.first << ", " << cell.second << ")" << endl;    // вывод координат атакованных ферзями клеток
//    }
//
//    cout << "Кони, которые атакуют короля:" << endl;
//    for (auto cell : attackedKnights) {
//        cout << "(" << cell.first << ", " << cell.second << ")" << endl;    // вывод координаты атакованных конями клеток
//    }
//
//    return 0;
//}