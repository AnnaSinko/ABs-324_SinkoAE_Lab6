package main

import (
 "fmt"
 "math/rand"
)

const BOARD_SIZE = 8

// Функция для вывода шахматной доски
func printBoard(board [][]rune) {
 for i := 0; i < BOARD_SIZE; i++ {
  for j := 0; j < BOARD_SIZE; j++ {
   fmt.Printf("%c ", board[i][j])
  }
  fmt.Println()
 }
}

// Функция для определения атакованных ферзями клеток
func getAttackedCells(kingX, kingY int, queens []struct{ x, y int }) map[struct{ x, y int }]bool {
 attackedCells := make(map[struct{ x, y int }]bool)

 for _, queen := range queens {
  if queen.x == kingX || queen.y == kingY || abs(queen.x-kingX) == abs(queen.y-kingY) {
   attackedCells[queen] = true
  }
 }

 return attackedCells
}

func abs(x int) int {
 if x < 0 {
  return -x
 }
 return x
}

func main() {
 rand.Seed(42)
 var queens []struct{ x, y int }
 var king struct{ x, y int }

 // Заполнение поля фигурами случайным образом
 for i := 0; i < 5; i++ {
  queens = append(queens, struct{ x, y int }{rand.Intn(BOARD_SIZE), rand.Intn(BOARD_SIZE)})
 }

 king = struct{ x, y int }{rand.Intn(BOARD_SIZE), rand.Intn(BOARD_SIZE)}

 // Создание шахматной доски
 board := make([][]rune, BOARD_SIZE)
 for i := range board {
  board[i] = make([]rune, BOARD_SIZE)
  for j := range board[i] {
   board[i][j] = '.'
  }
 }

 // Пометка ферзей на доске
 for _, queen := range queens {
  board[queen.x][queen.y] = 'Q'
 }

 // Пометка короля на доске
 board[king.x][king.y] = 'K'

 // Вывод фигур с их координатами
 fmt.Println("Ферзи и их координаты:")
 for i, queen := range queens {
  fmt.Printf("Ферзь %d: (%d, %d)\n", i+1, queen.x, queen.y)
 }

 // Вывод шахматной доски
 fmt.Println("Шахматная доска:")
 printBoard(board)

 // Определение координат ферзей, которые атакуют короля
 attackedCells := getAttackedCells(king.x, king.y, queens)

 // Вывод координат атакованных ферзями клеток
 fmt.Println("Ферзи, которые атакуют короля:")
 for cell := range attackedCells {
  fmt.Printf("(%d, %d)\n", cell.x, cell.y)
 }
}