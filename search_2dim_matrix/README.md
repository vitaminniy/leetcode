# Search a 2D matrix

Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous
row.

See task [here](https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3497/)

## Example 1

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true

## Example 2

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
Output: false

## Example 3

Input: matrix = [], target = 0
Output: false

## Constraints

* `m == matrix.length`
* `n == matrix[i].length`
* `0 <= m, n <= 100`
* `-10^4 <= matrix[i][j], target <= 10^4`

