#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <string>
#include "header.h"

using namespace std;

// Функция генерирует случайный ключ из 16 символов, где каждый символ - цифра от 0 до 9
void  keyGeneration(vector<unsigned char>& key) {   // функция, которая принимает вектор по ссылке и не возвращает никакого значения
    mt19937_64 gen(random_device{}());  // создание генератора случайных чисел для получения начального значения
    uniform_int_distribution<int> numbers(0, 9);    // создание равномерного распределения случайных чисел от 0 до 9
    for (int i = 1; i <= 16; i++) { // цикл (16 раз)
        key.push_back('0' + numbers(gen));  // генерируется случайное число от 0 до 9, прибавляется к символу '0', и результат добавляется в конец вектора
    }
}

// Функция операции XOR для добавления ключа к данным
vector<unsigned char> AddRoundKey(vector<unsigned char>& first, vector<unsigned char>& second) {    // функция, которая принимает два вектора по ссылке и возвращает новый вектор
    vector<unsigned char> temp; // создание временного вектора, в который будут помещены результаты операций XOR
    for (int i = 0; i < 4; ++i) {   // цикл (4 раза (по размеру векторов))
        temp.push_back(first[i] ^ second[i]);   // операция XOR для i-го элемента в first и i-го элемента в second, результат добавляется в конец вектора temp
    }
    return temp;    // возвращение вектора temp
}

// Функция сдвигает все элементы в векторе влево (первый элемент становится последним)
void ShiftElmnts(vector<unsigned char>& state) {    // функция, которая принимает вектор по ссылке и не возвращает никакого значения
    vector<unsigned char> temp(state.size());   // создание временного вектора той же длины, что и state
    for (int i = 1; i < state.size(); i++) {    // цикл, который проходит по всем элементам вектора (кроме первого)
        temp[i - 1] = state[i]; // каждый элемент вектора state сдвигается влево на одну позицию в векторе temp
    }
    temp[state.size() - 1] = state[0];  // первый элемент вектора state становится последним элементом в векторе temp

    state = temp;   // временный вектор присваивается исходному вектору
}

// Функция выполняет умножение в поле Галуа с использованием полинома (для реализации операций над многочленами в поле Галуа)
unsigned char galuaMn(unsigned char a, unsigned char b) {   // объявление функции, которая принимает два unsigned char и возвращает unsigned char
    unsigned char result = 0;   // переменная для хранения результата умножения
    unsigned char hi_bit_set;   // переменная для проверки, установлен ли самый старший бит в a
    for (unsigned char i = 0; i < 8; i++) { // цикл (8 раз (поля Галуа размером 8 бит))
        if (b & 1) {    // если младший бит в b равен 1
            result ^= a;    // то a прибавляется к result с помощью операции XOR
        }
        hi_bit_set = a & 0x80;  // проверка, установлен ли самый старший бит в a
        a <<= 1;    // сдвиг a влево на один бит
        if (hi_bit_set) {   // если самый старший бит в a был установлен до сдвига
            a ^= 0x1b;  // то к a применяется операция XOR
        }
        b >>= 1;    // сдвиг b вправо на один бит
    }
    return result;  // возвращение результата умножения
}

// Функция создает и возвращает таблицу умножения в поле Галуа для числа 2 для ускорения последующих операций умножения (результаты вычислены и хранятся в таблице)
vector<unsigned char> tabl_2() {    // объявление функции, которая не принимает никаких аргументов и возвращает вектор
    vector<unsigned char> tabl_with_2(256); // создание вектора размером 256 элементов
    for (int i = 0; i < 256; ++i) { // цикл (256 раз)
        tabl_with_2[i] = galuaMn(i, 2); // для каждого значения i в диапазоне от 0 до 255 вызывается функция, которая выполняет умножение в поле Галуа для числа i на 2
    }
    return tabl_with_2; // возвращение заполненной таблицы умножения для числа 2
}

// Функция создает и возвращает таблицу умножения в поле Галуа для числа 3
vector<unsigned char> tabl_3() {
    vector<unsigned char> tabl_with_3(256);
    for (int i = 0; i < 256; ++i) {
        tabl_with_3[i] = galuaMn(i, 3);
    }
    return tabl_with_3;
}

// Функция создает и возвращает таблицу умножения в поле Галуа для числа 14
vector<unsigned char> tabl_14() {
    vector<unsigned char> tabl_with_14(256);
    for (int i = 0; i < 256; ++i) {
        tabl_with_14[i] = galuaMn(i, 14);
    }
    return tabl_with_14;
}

// Функция создает и возвращает таблицу умножения в поле Галуа для числа 9
vector<unsigned char> tabl_9() {
    vector<unsigned char> tabl_with_9(256);
    for (int i = 0; i < 256; ++i) {
        tabl_with_9[i] = galuaMn(i, 9);
    }
    return tabl_with_9;
}

// Функция создает и возвращает таблицу умножения в поле Галуа для числа 13
vector<unsigned char> tabl_13() {
    vector<unsigned char> tabl_with_13(256);
    for (int i = 0; i < 256; ++i) {
        tabl_with_13[i] = galuaMn(i, 13);
    }
    return tabl_with_13;
}

// Функция создает и возвращает таблицу умножения в поле Галуа для числа 11
vector<unsigned char> tabl_11() {
    vector<unsigned char> tabl_with_11(256);
    for (int i = 0; i < 256; ++i) {
        tabl_with_11[i] = galuaMn(i, 11);
    }
    return tabl_with_11;
}

// Функция выполняет операции умножения на 2 и 3 над столбцами матрицы данных (вектор state)
void MnMatrix(vector<unsigned char>& state) {   // объявление функции, которая принимает вектор по ссылке и не возвращает никакого значения
    vector<unsigned char> tabl_with_2 = tabl_2();   // вектор содержит таблицу умножения в поле Галуа для числа 2

    vector<unsigned char> tabl_with_3 = tabl_3();   // вектор содержит таблицу умножения в поле Галуа для числа 3

    vector<unsigned char> temp; // временный вектор для хранения результатов операций
    temp.push_back(tabl_with_2[state[0]] ^ tabl_with_3[state[1]] ^ state[2] ^ state[3]);    // операции умножения на 2 и 3 над столбцами матрицы данных, вычисление новых значений для каждого столбца
    temp.push_back(tabl_with_2[state[1]] ^ tabl_with_3[state[2]] ^ state[0] ^ state[3]);
    temp.push_back(tabl_with_2[state[2]] ^ tabl_with_3[state[3]] ^ state[0] ^ state[1]);
    temp.push_back(tabl_with_2[state[3]] ^ tabl_with_3[state[0]] ^ state[1] ^ state[2]);
    state = temp;   // замена исходного вектора state новым вектором temp с новыми значениями
}

// Функция выполняет расширение ключа (операция сдвига, замена байтов, применение констант для каждого раунда)
void KeyExpansion(vector<unsigned char>& key, vector<vector<unsigned char>>& roundKeys) {   // функция, которая принимает исходный ключ и вектор векторов roundKeys (где расширенные ключи для каждого раунда)
    const vector<unsigned char> Rcon = {    // вектор с константами для операции XOR с ключом в процессе расширения ключа
        0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00,
        0x08, 0x00, 0x00, 0x00,
        0x10, 0x00, 0x00, 0x00,
        0x20, 0x00, 0x00, 0x00,
        0x40, 0x00, 0x00, 0x00,
        0x80, 0x00, 0x00, 0x00,
        0x1b, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00
    };

    vector<unsigned char> temp; // временный вектор для хранения промежуточных значений
    int i = 0;
    int Nk = 4; // размер ключа
    int Nb = 4; // размер блока
    int Nr = 10;    // количество раундов

    roundKeys.resize(Nb * (Nr + 1), vector<unsigned char>(4));  // изменение размера вектора для вмещения расширенных ключей для всех раундов, включая начальный

    // Заполнение первых ключей из исходного ключа
    while (i < Nk) {    // цикл (4 раза)
        temp = { key[4 * i], key[4 * i + 1], key[4 * i + 2], key[4 * i + 3] };  // копирование 4-байтного блока из исходного ключа в temp
        roundKeys[i] = temp;    // копирование блока из temp в roundKeys
        i++;    // увеличение счетчика цикла
    }

    // Расширение ключей
    i = Nk;
    while (i < (Nb * (Nr + 1))) {   // цикл для расширения ключа до необходимого размера
        temp = roundKeys[i - 1];    // копирование предыдущего расширенного ключа в temp
        if (i % Nk == 4) {  // условие, которое проверяет, нужно ли применять операции SubBytes и ShiftElmnts к блоку ключа
            ShiftElmnts(temp);  // функция, которая сдвигает элементы
            SubBytes(temp); // функция, которая заменяет элементы на другие значения
            for (int k = 0; k < temp.size(); ++k) { 
                temp[k] = temp[k] ^ Rcon[i / Nk];   // применение операции XOR к каждому элементу temp с соответствующей константой из Rcon
            }
        }
        else if (Nk > 6 && (i % Nk == 4)) { // доп условие, которое проверяет, нужно ли применять операцию SubBytes к блоку ключа, если Nk > 6
            SubBytes(temp);
        }
        for (int j = 0; j < temp.size(); ++j) {
            roundKeys[i][j] = roundKeys[i - Nk][j] ^ temp[j];   // применение операции XOR между предыдущим расширенным ключом и temp для получения нового расширенного ключа
        }
        i++;    // увеличение счетчика цикла
    }
}

// Функция выполняет обратный сдвиг элементов
void InversionShiftElmnts(vector<unsigned char>& state) {   // функция, которая принимает вектор по ссылке и не возвращает никакого значения
    vector<unsigned char> temp(state.size());   // создание временного вектора temp той же длины, что и state
    for (int i = 0; i < state.size(); i++) {    // цикл проходит по всем элементам вектора state
        temp[i] = state[(i - (i % 4) * (i % 4)) % state.size()];    // обратный сдвиг элементов
    }
    state = temp;   // временный вектор temp присваивается исходному вектору state
}

// Функция выполняет обратные операции умножения над столбцами матрицы данных
void InversionMnMatrix(vector<unsigned char>& state) {  // функция, которая принимает вектор по ссылке и не возвращает никакого значения
    vector<unsigned char> tabl_with_14 = tabl_14(); // вектор, который содержит таблицу умножения в поле Галуа для числа 14
    vector<unsigned char> tabl_with_9 = tabl_9();   // вектор, который содержит таблицу умножения в поле Галуа для числа 9
    vector<unsigned char> tabl_with_13 = tabl_13(); // вектор, который содержит таблицу умножения в поле Галуа для числа 13
    vector<unsigned char> tabl_with_11 = tabl_11(); // вектор, который содержит таблицу умножения в поле Галуа для числа 11

    vector<unsigned char> temp; // временный вектор для хранения результатов операций
    temp.push_back(tabl_with_14[state[0]] ^ tabl_with_9[state[1]] ^ tabl_with_13[state[2]] ^ tabl_with_11[state[3]]);   // вычисление новых значений для каждого столбца
    temp.push_back(tabl_with_14[state[1]] ^ tabl_with_9[state[2]] ^ tabl_with_13[state[3]] ^ tabl_with_11[state[0]]);
    temp.push_back(tabl_with_14[state[2]] ^ tabl_with_9[state[3]] ^ tabl_with_13[state[0]] ^ tabl_with_11[state[1]]);
    temp.push_back(tabl_with_14[state[3]] ^ tabl_with_9[state[0]] ^ tabl_with_13[state[1]] ^ tabl_with_11[state[2]]);
    state = temp;   // замена исходного вектора state новым вектором temp с новыми значениями
}

// Функция разбивает входную строку на блоки размером 16 байт
void createBlocks(string& text, vector<vector<vector<unsigned char>>>& block) { // функция, которая принимает строку по ссылке и двумерный вектор, в котором будут храниться блоки
    while (text.size() % 16 != 0) { // цикл пока размер строки не будет кратен 16
        text += ' ';    // добавление пробелов в конец строки
    }

    vector<vector<vector<unsigned char>>> temporary;    // временный вектор для хранения блоков
    vector<vector<unsigned char>> sixteen(4, vector<unsigned char>(4)); // вектор, который представляет собой матрицу 4x4, в которой будут храниться байты из строки text

    for (int i = 0; i < text.size(); ++i) { // цикл, который проходит по всем символам строки
        int a = (i % 16) % 4;   // вычисление индексов для текущего символа в матрице sixteen
        int b = (i % 16) / 4;
        sixteen[a][b] = text[i];    // присваивание текущему элементу матрицы sixteen значения текущего символа из строки text

        if ((i + 1) % 16 == 0) {    // условие, которое проверяет, достиг ли счетчик i размера блока (16)
            temporary.push_back(sixteen);   // текущий блок (матрица sixteen) добавляется в вектор temporary
            sixteen = vector<vector<unsigned char>>(4, vector<unsigned char>(4));   // матрица sixteen обнуляется для следующего блока
        }
    }

    block = temporary;  // вектор temporary, который содержит все блоки (каждый блок представляет собой матрицу 4x4 байт), присваивается вектору block
}

// Функция выполняет шифрование блока данных с использованием ключа и раундовых ключей
vector<vector<unsigned char>> Encrypt(vector<vector<unsigned char>>& block, vector<vector<unsigned char>>& roundKeys, vector<unsigned char> key) {  // принимает блок данных, вектор раундовых ключей и ключ, возвращает зашифрованный блок данных

    vector<vector<unsigned char>> temp(4, vector<unsigned char>(4, 0)); // временный вектор размером 4x4, заполненный нулями (для хранения промежуточных результатов шифрования)
    for (int i = 0; i < 4; ++i) {   // цикл выполняет начальное добавление раундового ключа к блоку данных
        temp[i] = AddRoundKey(block[i], roundKeys[i]);
    }
    
    for (int i = 1; i <= 9; i++) {  // основной цикл шифрования, который выполняется 9 раз для каждого из 10 раундов
        for (int j = 0; j <= 3; j++) {  // цикл, где выполняются операции шифрования для каждого столбца блока данных
            SubBytes(temp[j]);  // функция заменяет каждый байт в столбце на другой байт, используя таблицу замен для шифрования
            ShiftElmnts(temp[j]);   // функция сдвигает элементы в столбце влево на один байт
            MnMatrix(temp[j]);  // функция выполняет операции умножения над столбцом в поле Галуа
            temp[j] = AddRoundKey(temp[j], roundKeys[i]);   // функция добавляет раундовый ключ к столбцу
        }
    }
    
    for (int j = 0; j <= 3; j++) {  // цикл, где выполняются те же операции, что и внутри основного цикла, но для последнего раунда
        SubBytes(temp[j]);
        ShiftElmnts(temp[j]);
        temp[j] = AddRoundKey(temp[j], roundKeys[10]);
    }

    return temp;    // возвращение зашифрованного блока данных
}

// Функция выполняет дешифрование блока данных с использованием ключа и раундовых ключей
vector<vector<unsigned char>> Decrypt(vector<vector<unsigned char>>& block, vector<vector<unsigned char>>& roundKeys, vector<unsigned char> key) {  // принимает зашифрованный блок данных, вектор раундовых ключей и ключ, возвращает дешифрованный блок данных
    vector<vector<unsigned char>> roundKeysDec(44, vector<unsigned char>(4));   // вектор размером 44x4 для хранения раундовых ключей после расширения ключа
    KeyExpansion(key, roundKeysDec);    // функция расширяет ключ key и сохраняет расширенные ключи в roundKeysDec

    vector<vector<unsigned char>> temporary(4, vector<unsigned char>(4, 0));    // временный вектор размером 4x4, заполненный нулями (для хранения промежуточных результатов дешифрования)

    for (int j = 0; j <= 3; j++) {  // цикл выполняет начальное добавление последнего раундового ключа к блоку данных
        temporary[j] = AddRoundKey(block[j], roundKeys[10]);
    }

    for (int i = 9; i >= 1; i--) {  // основной цикл дешифрования, который выполняется 9 раз для каждого из 10 раундов в обратном порядке
        for (int j = 0; j <= 3; j++) {  // цикл, где выполняются обратные операции шифрования для каждого столбца блока данных
            temporary[j] = AddRoundKey(temporary[j], roundKeys[i]); // функция добавляет раундовый ключ к столбцу 
            InversionMnMatrix(temporary[j]);    // функция выполняет обратные операции умножения над столбцом в поле Галуа
            InversionShiftElmnts(temporary[j]); // функция выполняет обратный сдвиг элементов в столбце
            InversionSubBytes(temporary[j]);    // функция выполняет обратную замену байтов в столбце
        }
    }

    for (int j = 0; j <= 3; j++) {  // цикл добавляет первый раундовый ключ к каждому столбцу
        temporary[j] = AddRoundKey(temporary[j], roundKeys[0]);
    }
    for (int j = 0; j <= 3; j++) {  // цикл выполняет обратные операции шифрования для первого раунда
        InversionShiftElmnts(temporary[j]);
        InversionSubBytes(temporary[j]);
    }

    return temporary;   // возвращение дешифрованного блока данных
}

int main() {
    system("chcp 1251");
    string text;    // ввод строки текста
    cout << "Input message: ";
    getline(cin, text); // считывает строку текста, включая пробелы, и сохраняет ее в переменную text

    // Вывод блоков данных
    vector<vector<vector<unsigned char>>> block;    // трехмерный вектор (массив) внутри которого будут храниться блоки данных (генерация матрицы для работы)
    createBlocks(text, block);  // функция разбивает строку на блоки и сохраняет их в векторе
    cout << "----------------------------------------------";
    cout << "\nThe encryption block: \n";
    for (auto i : block) {  // вложенные циклы, которые проходят по всем элементам вектора и выводят их на экран
        for (auto j : i) {
            for (auto k : j) {
                cout << setw(4) << k << " ";    // вывод каждого байта k с отступом в 4 символа
            }
            cout << endl;
        }
    }
    cout << "\n----------------------------------------------" << endl;

    vector<unsigned char> key;  // вектор для записи сгенерированного ключа
     keyGeneration(key);    // функция генерирует ключ и записывает его в вектор
    cout << "128-bit key: ";
    for (auto i : key) {    // цикл проходит по каждому байту в векторе и выводит его на экран
        cout << i;
    }
    cout << "\n----------------------------------------------\n";

    vector<vector<unsigned char>> roundKeys;    // двумерный вектор для записи раундовых ключей
    KeyExpansion(key, roundKeys);   // функция расширяет ключ и записывает их в вектор 
    cout << "Generated round keys: \n";
    for (auto i : roundKeys) {  // вложенные циклы, которые проходят по всем элементам вектора и выводят их на экран
        for (auto j : i) {
            cout << hex << setw(4) << static_cast<int>(j) << " ";   // вывод каждого байта в шестнадцатеричном формате с отступом в 4 символа

        }
        cout << endl;
    }
    cout << "\n----------------------------------------------" << endl;

    // Для хранения промежуточных данных
    vector<vector<unsigned char>> PREV(4, vector<unsigned char>(4, 0)); // двумерный вектор размером 4x4, заполненный нулями
    vector<vector<unsigned char>> DEFOLT = PREV;    // те же размеры и содержимое, что и PREV
    // Для хранения ключей
    vector<vector<unsigned char>> TEK;  // двумерный вектор
    // Для хранения зашифрованных данных
    vector<vector<vector<unsigned char>>> ECRYPT;   // трехмерный вектор

    for (int i = 0; i < block.size(); i++) {    // цикл проходит по каждому блоку в векторе

        vector<vector<unsigned char>> res(4, vector<unsigned char>(4, 0));  // двумерный вектор размером 4x4, заполненный нулями (для хранения результата XOR-операции)
        vector<vector<unsigned char>> B = block[i]; // переменная для хранения i-го блока из вектора block
        TEK = Encrypt(PREV, roundKeys, key);

        for (int i = 0; i < 4; ++i) {   // проходит по каждому элементу в TEK и B
            for (int j = 0; j < 4; ++j) {
                res[i][j] = (TEK[i][j] ^ B[i][j]);  // выполняет XOR-операцию между ними и записывает результат в res

            }
        }
        ECRYPT.push_back(res);  // добавляет вектор res в конец вектора ECRYPT

        PREV = TEK; // обновление значения для следующей итерации цикла
    }

    cout << "The encrypted message: \n" << endl;
    for (auto t : ECRYPT) { // вложенные циклы, которые проходят по всем элементам вектора и выводят их на экран
        for (auto i : t) {
            for (auto j : i) {
                cout << setw(4) << j << " ";
            }
            cout << endl;
        }
    }

    cout << "\n----------------------------------------------\n";

    PREV = DEFOLT;  // обновление значения обратно до исходного состояния
    // Для хранения расшифрованных данных
    vector<vector<vector<unsigned char>>> DECRYPT;  // трехмерный вектор

    for (int i = 0; i < ECRYPT.size(); ++i) {   // цикл проходит по каждому блоку в векторе, который содержит зашифрованные данные
        vector<vector<unsigned char>> res(4, vector<unsigned char>(4, 0));  // двумерный вектор размером 4x4, заполненный нулями (для хранения результата XOR-операции)
        vector<vector<unsigned char>> B = ECRYPT[i];    // переменная для хранения i-го блока из вектора ECRYPT
        TEK = Encrypt(PREV, roundKeys, key);

        for (int i = 0; i < 4; ++i) {   // проходит по каждому элементу в TEK и B
            for (int j = 0; j < 4; ++j) {
                res[i][j] = (B[i][j] ^ TEK[i][j]);  // выполняет XOR-операцию между ними и записывает результат в res
            }
        }
        DECRYPT.push_back(res); // добавляет вектор res в конец вектора DECRYPT
        PREV = TEK; // обновление значения для следующей итерации цикла
    }

    vector<vector<vector<unsigned char>>> DECRYPT_1;    // новый трехмерный вектор для хранения расшифрованных данных

    for (int i = 0; i < ECRYPT.size(); ++i) {   // цикл проходит по каждому блоку в векторе, который содержит зашифрованные данные
        vector<vector<unsigned char>> res(4, vector<unsigned char>(4, 0));  // двумерный вектор размером 4x4, заполненный нулями (для хранения результата дешифрования)
        vector<vector<unsigned char>> B = ECRYPT[i];    // переменная для хранения i-го блока из вектора ECRYPT
        TEK = Decrypt(B, roundKeys, key);

        for (int i = 0; i < 4; ++i) {   // проходит по каждому элементу в TEK
            for (int j = 0; j < 4; ++j) {
                res[i][j] = TEK[i][j];  // копирует его в res
            }
        }
        DECRYPT_1.push_back(res);   // добавляет вектор res в конец вектора DECRYPT_1
    }

    cout << "The decrypted message: \n" << endl;
    for (int i = 0; i < DECRYPT.size(); i++) {  // внешний цикл проходит по каждому блоку в векторе DECRYPT
        vector<vector<unsigned char>>& decrypt = DECRYPT[i];    // ссылка на i-й блок в DECRYPT
        for (int j = 0; j < decrypt.size(); j++) {  // внутренний цикл проходит по каждому элементу в блоке
            for (int k = 0; k < decrypt[j].size(); k++) {   // цикл проходит по каждому элементу внутри элемента блока
                cout << decrypt[k][j];  // выводит k-й элемент j-го элемента блока
            }
        }
    }
    cout << "\n----------------------------------------------\n" << endl;

    return 0;
}