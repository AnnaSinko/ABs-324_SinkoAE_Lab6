package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano()) // инициализация генератора случайных чисел текущим временем

	var M, N int // объявление переменных для количества строк и столбцов матрицы
	fmt.Print("Введите количество строк (M): ") // вывод сообщения на экран о необходимости ввести количество строк
	fmt.Scan(&M) // ввод количества строк с клавиатуры
	fmt.Print("Введите количество столбцов (N): ") // вывод сообщения на экран о необходимости ввести количество столбцов
	fmt.Scan(&N) // ввод количества столбцов с клавиатуры

	matrix := make([][]int, M) // объявление двумерного вектора (матрицы) размером M x N
	for i := range matrix {
		matrix[i] = make([]int, N)
	}

	elementCount := make(map[int]int) // объявление словаря для подсчета вхождений элементов

	// Заполнение матрицы случайными числами
	for i := 0; i < M; i++ { // цикл по строкам матрицы
		for j := 0; j < N; j++ { // цикл по столбцам матрицы
			matrix[i][j] = rand.Intn(101) - 50 // заполнение матрицы случайными числами в диапазоне [-50, 50] (по условию)
			elementCount[matrix[i][j]]++ // увеличение счетчика вхождений текущего элемента
		}
	}

	// Вывод начальной матрицы на экран
	fmt.Println("Матрица:") // вывод сообщения на экран
	for i := 0; i < M; i++ { // цикл по строкам матрицы
		for j := 0; j < N; j++ { // цикл по столбцам матрицы
			fmt.Print(matrix[i][j], " ") // вывод элемента матрицы на экран
		}
		fmt.Println() // переход на новую строку
	}

	// Вывод количества элементов на экран
	fmt.Println("Количество элементов:") // вывод сообщения на экран
	for elem, count := range elementCount { // цикл по всем элементам словаря
		fmt.Println(elem, ":", count) // вывод элемента и его количества на экран
	}
}