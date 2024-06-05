package main

import (
 "fmt"
 "math"
)

const (
 EPS            = 0.001
 MAX_ITERATIONS = 1000
)

// Функция для вывода вектора
func printVector(vec []float64) {
 for _, val := range vec {
  fmt.Printf("%.2f ", val)
 }
 fmt.Println()
}

// Функция для вывода матрицы
func printMatrix(mat [][]float64) {
 for _, row := range mat {
  printVector(row)
 }
}

// Функция для решения системы методом LU-разложения
func solveLU(A [][]float64, b []float64) []float64 {
 n := len(A)
 L := make([][]float64, n)
 U := make([][]float64, n)
 for i := range L {
  L[i] = make([]float64, n)
  U[i] = make([]float64, n)
 }

// Функция для решения системы методом LU-разложения
func solveLU(A [][]float64, b []float64) []float64 {
	n := len(A)
	L := make([][]float64, n)
	U := make([][]float64, n)
	for i := range L {
	 L[i] = make([]float64, n)
	 U[i] = make([]float64, n)
	}
   
	// LU-разложение
	for i := 0; i < n; i++ {
	 for j := 0; j < n; j++ {
	  if i <= j {
	   U[i][j] = A[i][j]
	   for k := 0; k < i; k++ {
		U[i][j] -= L[i][k] * U[k][j]
	   }
	  }
	  if i > j {
	   L[i][j] = A[i][j]
	   for k := 0; k < j; k++ {
		L[i][j] -= L[i][k] * U[k][j]
	   }
	   L[i][j] /= U[j][j]
	  }
	 }
	}
   
	// Прямой ход
	y := make([]float64, n)
	for i := 0; i < n; i++ {
	 y[i] = b[i]
	 for j := 0; j < i; j++ {
	  y[i] -= L[i][j] * y[j]
	 }
	}
   
	// Обратный ход
	x := make([]float64, n)
	for i := n - 1; i >= 0; i-- {
	 x[i] = y[i]
	 for j := i + 1; j < n; j++ {
	  x[i] -= U[i][j] * x[j]
	 }
	 x[i] /= U[i][i]
	}
   
	return x
   }

// Функция для решения системы методом Зейделя
func solveGaussSeidel(A [][]float64, b []float64) []float64 {
 n := len(A)
 x := make([]float64, n)
 xNew := make([]float64, n)
 var sum, normDiff float64
 iteration := 0

 for {
  copy(xNew, x)

  for i := 0; i < n; i++ {
   sum = b[i]
   for j := 0; j < n; j++ {
    if i != j {
     sum -= A[i][j] * x[j]
    }
   }
   xNew[i] = sum / A[i][i]
  }

  normDiff = 0.0
  for i := 0; i < n; i++ {
   normDiff += math.Pow(xNew[i]-x[i], 2)
  }
  normDiff = math.Sqrt(normDiff)

  copy(x, xNew)

  if normDiff <= EPS || iteration >= MAX_ITERATIONS {
   break
  }

  iteration++
 }

 if iteration == MAX_ITERATIONS {
  fmt.Println("Превышено максимальное количество итераций. Метод не сошелся.")
 }

 return xNew
}

// Функция для решения системы методом простых итераций
func solveSimpleIteration(A [][]float64, b []float64, x0 []float64) []float64 {
 n := len(A)
 x := make([]float64, n)
 xNew := make([]float64, n)
 var normDiff float64
 iteration := 0

 copy(x, x0)

 for {
  copy(xNew, x)

  for i := 0; i < n; i++ {
   sum := b[i]
   for j := 0; j < n; j++ {
    if i != j {
     sum -= A[i][j] * x[j]
    }
   }
   if math.Abs(A[i][i]) > EPS {
    xNew[i] = sum / A[i][i]
   } else {
    fmt.Printf("Ошибка: деление на ноль при итерации %d\n", iteration)
    return x // Возвращаем текущее приближение
   }
  }

  normDiff = 0.0
  for i := 0; i < n; i++ {
   normDiff += math.Pow(xNew[i]-x[i], 2)
  }
  normDiff = math.Sqrt(normDiff)

  copy(x, xNew)

  if normDiff <= EPS || iteration >= MAX_ITERATIONS {
   break
  }

  iteration++
 }

 return xNew
}

func main() {
	A := [][]float64{
		{0.89, -0.04, 0.21, -18},
		{0.25, -1.23, 0.08, -0.09},
		{-0.21, 0.08, 0.8, -0.13},
		{0.15, -1.31, 0.06, -1.21},
	   }
	   b := []float64{-1.24, -1.21, 2.56, 0.89}
	  
	   fmt.Println("Матрица A:")
	   printMatrix(A)
	  
	   fmt.Println("Вектор b:")
	   printVector(b)
	  
	   fmt.Println("Решение системы методом LU-разложения:")
	   xLU := solveLU(A, b)
	   printVector(xLU)
	  }

 	fmt.Println("Решение системы методом Зейделя:")
	xGaussSeidel := solveGaussSeidel(A, b)
 	printVector(xGaussSeidel)

 	fmt.Println("Решение системы методом простых итераций:")
 	xSimpleIteration := solveSimpleIteration(A, b, []float64{0, 0, 0})
 	printVector(xSimpleIteration)
}