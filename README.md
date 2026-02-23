# push_swap

A 42 project that sorts a stack of integers using movement operations, attempting to sort the stack with the least amount of movement operations. The goal is to generate a valid sequence of instructions that sorts stack A in ascending order using stack B as helping storage.

## Features

- Validates input (duplicates, non-integers, overflow)
- Generates operations to sort stack A
- Includes a checker program to validate the output sequence

## Project Structure

- includes/          Project headers
- libft/             Custom C library (libft)
- src/push_swap/     push_swap implementation
- src/checker/       checker implementation

## Operations

The program may output these operations:

- sa: swap the first two elements of stack A
- sb: swap the first two elements of stack B
- ss: sa and sb at the same time
- pa: push the top of B to A
- pb: push the top of A to B
- ra: rotate A (first element becomes last)
- rb: rotate B (first element becomes last)
- rr: ra and rb at the same time
- rra: reverse rotate A (last element becomes first)
- rrb: reverse rotate B (last element becomes first)
- rrr: rra and rrb at the same time

## Build

```bash
make
```

This will build:

- push_swap (the sorter)
- checker (the verifier)

## Usage

### push_swap

```bash
./push_swap 3 2 1
```

It prints a list of operations to stdout. You can count the number of moves with:

```bash
./push_swap 3 2 1 | wc -l
```

### checker

The checker validates that the operations sort stack A and respect the rules.

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Expected output:

- OK if sorted
- KO if not sorted
- Error on invalid input or instruction

## Example

```bash
$ ./push_swap 2 1 3
sa
```

## Notes

- Input values must fit in a 32-bit signed integer.
- Duplicates are not allowed.
- No output is produced if the input is already sorted.

## Testing

You can test with random values:

```bash
ARG="$(shuf -i 0-100 -n 5)"; ./push_swap $ARG | ./checker $ARG
```
