# Run Time and Space Complexities

## BSTSet
`T(n) = (n)`

`T(n) = Θ(n)`

`S(n) = 8 (TNode *)`

`S(n) = Θ(8)`

## Stack
`T(n) = (1)`

`T(n) = Θ(1)`

`S(n) = n * 8 (TNode *)`

`S(n) = Θ(8n)`

## push
`T(n) = (1)`

`T(n) = Θ(1)`

`S(n) = 0`

`S(n) = Θ(0)`

## pop
`T(n) = (1)`

`T(n) = Θ(1)`

`S(n) = 8 (TNode *)`

`S(n) = Θ(8)`

## size
`T(n) = (1)`

`T(n) = Θ(1)`

`S(n) = 0`

`S(n) = Θ(0)`

## isEmpty
`T(n) = (1)`

`T(n) = Θ(1)`

`S(n) = 0`

`S(n) = Θ(0)`

## destroy
`T(n) = n * 1 (recursive delete)`

`T(n) = Θ(n)`

`S(n) = 0`

`S(n) = Θ(0)`

## isIn
`T(n) = log_2(n) (while loop)`

`T(n) = Θ(log_2(n))`

`S(n) = 8 (TNode *)`

`S(n) = Θ(8)`

## add
`T(n) = log_2(n) (isIn) + log_2(n) (while loop)`

`T(n) = Θ(log_2(n))`

`S(n) = 8 (TNode *)`

`S(n) = Θ(8)`

## replceWithRightMin
`T(n) = n (while loop)`

`T(n) = Θ(n)`

where n is the height of the right branch

`S(n) = 2 * (8 (TNode *))`

`S(n) = Θ(16)`

## replceWithLeftMax
`T(n) = n (while loop)`

`T(n) = Θ(n)`

where n is the height of the left branch

`S(n) = 2 * (8 (TNode *))`

`S(n) = Θ(16)`

## remove
`T(n) = log_2(n) (while loop) + n (replace)`

`T(n) = Θ(n)`

`S(n) = 2 * (8 (TNode *))`

`S(n) = Θ(16)`

## union
`T(n) = 1 (push) + n (while loop) * (1 (pop) + 2 * (1 (push)) + log_2(n) (add))`

`T(n) = Θ(n * log_2(n))`

`S(n) = 8 * n (TNode * Stack) + 8 (TNode *)`

`S(n) = Θ(8n)`

## intersection
`T(n) = 1 (push) + n (while loop) * (1 (pop) + 2 * (1 (push)) log_2(m) (isIn)) + l (for loop) * n (remove)`

`T(n) = Θ(n * log_2(m))`

`S(n) = 4 * l (int vector) + 8 * n (TNode * Stack) + 8 (TNode *)`

`S(n) = Θ(8n)`

where n and m are the number of nodes in this and s respectively
where l is the number of nodes to be deleted

## difference
`T(n) = 1 (push) + n (while loop) * (1 (pop) + 2 * (1 (push)) log_2(m) (isIn)) + l (for loop) * n (remove)`

`T(n) = Θ(n * log_2(m))`

`S(n) = 4 * l (int vector) + 8 * n (TNode * Stack) + 8 (TNode *)`

`S(n) = Θ(8n)`

where n and m are the number of nodes in this and s respectively
where l is the number of nodes to be deleted

## size
`T(n) = n (while loop combo)`

`T(n) = Θ(n)`

`S(n) = 8 * n (TNode * vector) + 2 * (4 (int)) + 8 (TNode *)`

`S(n) = Θ(8n)`

## height
`T(n) = n (while loop combo)`

`T(n) = Θ(n)`

`S(n) = 8 * n (TNode * vector) + 2 * (4 (int)) + 8 (TNode *)`

`S(n) = Θ(8n)`

## printNonRec
`T(n) = 1 (push) + n (while loop combo) * (1 (push) + 1 (pop))`

`T(n) = Θ(n)`

`S(n) = 8 * n (TNode * Stack) + 8 (TNode *)`

`S(n) = Θ(8n)`
