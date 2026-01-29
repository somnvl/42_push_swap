*This project has been created as part of the 42 curriculum by somenvie.*

# DESCRIPTION

**Push Swap** is a sorting challenge that requires you to sort a random list of integers using two stacks (A and B) and a predefined set of operations. The goal is to minimize the number of operations needed to sort the input.

The project combines several algorithmic concepts:
- **Sorting algorithms** - Understanding of different approaches (small arrays vs large arrays)
- **Stack-based operations** - Manipulation through restricted operations only
- **Optimization** - Cost-based decision making to minimize moves
- **Data structures** - Doubly-linked lists for efficient stack operations

## Project Structure

```
push_swap/
├── includes/
│   └── push_swap.h
├── libft/
├── obj/
├── srcs/
│   ├── debug.c
|   ├── checker.c
|   ├── checker_utils.c
│   ├── low_sort.c
│   ├── lst_creator.c
│   ├── lst_manager.c
│   ├── main.c
│   ├── normalize.c
│   ├── op_push.c
│   ├── op_reverse.c
│   ├── op_rotate.c
│   ├── op_swap.c
│   ├── parsing.c
│   ├── turk_apply.c
│   ├── turk_utils.c
│   ├── turk_pick.c
│   └── turk_sort.c
├── checker_linux
├── Makefile
└── README.md

```

---

# RESOURCES

### Core Concepts
- [Push Swap Algorithm Explained](https://medium.com/@ayogun/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) - Medium article on optimization
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/) - Stack operations overview

---

# INSTRUCTIONS

### Build & Compile

```bash
make              # Compile push_swap executable
make clean        # Remove object files
make fclean       # Remove all compiled files and executable
make re           # Clean rebuild
```

**Compiler flags:** `-Wall -Wextra -Werror -g`

### Basic Test

```bash

# No arguments
./push_swap

# Single number (no output expected)
./push_swap 42

# Already sorted
./push_swap 1 2 3 4 5

# Reverse sorted
./push_swap 5 4 3 2 1

```

### Error handling tests (must print Error)

```bash
# Non-numeric argument
./push_swap 1 2 a 3

# Duplicates
./push_swap 1 2 3 2

# Integer overflow
./push_swap 2147483648
./push_swap -2147483649

# Empty / whitespace arguments
./push_swap "" "   "
```

### Checker validation tests (OK / KO)

```bash
# Simple test
ARG="3 2 1"
./push_swap $ARG | ./checker $ARG

# Random test (100 numbers)
ARG=$(shuf -i 1-100 -n 100 | xargs)
./push_swap $ARG | ./checker $ARG

# Random test (500 numbers)
ARG=$(shuf -i 1-500 -n 500 | xargs)
./push_swap $ARG | ./checker $ARG
```

### Operation count tests

```bash
# Size 3
./push_swap 3 2 1 | wc -l

# Size 5
./push_swap 5 4 3 2 1 | wc -l

# Size 100
./push_swap $(shuf -i 0-1000 -n 100 | xargs) | wc -l

# Size 500
./push_swap $(shuf -i 0-1000 -n 500 | xargs) | wc -l
```

### Validation + operation count

```bash
ARG=$(shuf -i 1-100 -n 100 | xargs)
./push_swap $ARG | tee >(wc -l) | ./checker $ARG

ARG=$(shuf -i 1-1000 -n 500 | xargs)
./push_swap $ARG | tee >(wc -l) | ./checker $ARG
```

### Stress tests (loop)

```bash
# 100 runs, size 100
for i in {1..100}; do
  ARG=$(shuf -i 1-1000 -n 100 | xargs)
  ./push_swap $ARG | ./checker $ARG || break
done

# 50 runs, size 500
for i in {1..50}; do
  ARG=$(shuf -i 1-5000 -n 500 | xargs)
  ./push_swap $ARG | ./checker $ARG || break
done
```

### Valgrind tests (push_swap)

```bash
# Simple memory check
valgrind --leak-check=full --show-leak-kinds=all \
./push_swap 3 2 1

# Random test with checker
ARG=$(shuf -i 1-100 -n 100 | xargs)
valgrind --leak-check=full --show-leak-kinds=all \
./push_swap $ARG | ./checker $ARG
```

### Valgrind tests (checker – pipe safe)

```bash
# Checker only
valgrind --leak-check=full --show-leak-kinds=all \
./checker 3 2 1 << EOF
sa
rra
EOF

# push_swap → checker (pipe)
ARG=$(shuf -i 1-100 -n 100 | xargs)
valgrind --leak-check=full --show-leak-kinds=all \
./push_swap $ARG | ./checker $ARG
```

### Invalid instruction test (checker)

```bash
ARG="3 2 1"
echo -e "sa\nINVALID_OP\nra" | ./checker $ARG
```

### Quick benchmarks (42 goals)

```bash
# 100 numbers (target < 700 operations)
./push_swap $(shuf -i 0-1000 -n 100 | xargs) | wc -l

# 500 numbers (target < 5500 operations)
./push_swap $(shuf -i 0-5000 -n 500 | xargs) | wc -l
```

---

# PROJECT SETUP

## Algorithm Overview

```
INPUT: ./push_swap 4 67 3 87 23
       ↓
┌─────────────────────────────────────┐
│ STEP 1: PARSING                     │
│ Stack A: [4] → [67] → [3] → [87]→[23]
└─────────────────────────────────────┘
       ↓
┌─────────────────────────────────────┐
│ STEP 2: NORMALIZE (Index mapping)   │
│ Values: [4, 67, 3, 87, 23]          │
│ Indices:[2, 4,  1, 5,  0]           │
└─────────────────────────────────────┘
       ↓
┌─────────────────────────────────────┐
│ STEP 3: CHECK IF SORTED             │
│ YES → Exit (0 operations)           │
│ NO  → Continue                      │
└─────────────────────────────────────┘
       ↓
┌─────────────────────────────────────┐
│ STEP 4: SIZE ≤ 5?                   │
├─────────────────────────────────────┤
│ YES → low_sort()                    │
│       ├─ size 2: sa()               │
│       ├─ size 3: sort_three()       │
│       ├─ size 4: sort_four()        │
│       └─ size 5: sort_five()        │
│                                     │
│ NO  → STEP 5: TURKISH ALGORITHM     │
└─────────────────────────────────────┘
```
---

## Turkish Algorithm (Size > 5)

### Phase A: A → B (Cost-based extraction)

```
PHASE A
┌──────────────────────────────────────────┐
│ while (size > 3):                        │
│   1. Choose element in A with lowest     │
│      rotation cost to reach the top      │
│   2. Rotate A accordingly                │
│   3. pb(a, b)                            │
│   4. Optional rb(b) to improve ordering  │
└──────────────────────────────────────────┘

```
**Purpose:** Reduce stack A to 3 elements by always pushing the cheapest-to-extract element into B, minimizing unnecessary rotations.

### Phase B: B → A (Greedy reinsertion)

```
PHASE B
┌──────────────────────────────────────────┐
│ while (stack B not empty):               │
│   1. Compute position of each B element  │
│      in A (sorted insertion)             │
│   2. Compute rotation costs (A + B)      │
│   3. Pick cheapest element               │
│   4. Apply rotations (rr / rrr if able)  │
│   5. pa(a, b)                            │
└──────────────────────────────────────────┘

```
**Purpose:** Reinsert elements from B into A in sorted order using a greedy, cost-minimizing strategy.

### Cost Calculation

```c
cost_to_top(len, pos):
  if pos <= len / 2:
    return pos
  else:
    return pos - len

total_cost(ca, cb):
  if same direction:
    return max(abs(ca), abs(cb))
  else:
    return abs(ca) + abs(cb)

```

### Final Rotate

```
Once A is fully rebuilt:
- Find position of smallest index
- Rotate A (ra / rra) until minimum is on top
```
This ensures stack A is perfectly aligned.

---

## Operation Set

| Op | Stack A | Stack B | Effect |
|:--:|:-------:|:-------:|--------|
| `sa` | ✓ | | Swap top 2 elements |
| `sb` | | ✓ | Swap top 2 elements |
| `ss` | ✓ | ✓ | Both swap simultaneously |
| `pa` | ← | | Push from B to A |
| `pb` | | → | Push from A to B |
| `ra` | ✓ | | Rotate up (first → last) |
| `rb` | | ✓ | Rotate up |
| `rr` | ✓ | ✓ | Both rotate up simultaneously |
| `rra` | ✓ | | Rotate down (last → first) |
| `rrb` | | ✓ | Rotate down |
| `rrr` | ✓ | ✓ | Both rotate down simultaneously |

---

## Key Functions

```

### Cost Selection

```c
best_pos_global()   // Cheapest element to extract from A
target_pos_a()     // Target insertion position in A
pick_cheapest()    // Best element from B to reinsert
apply_cheapest()   // Optimized rotations (rr / rrr)
```

---

## Data Structure

```c
typedef struct s_dlst {
    struct s_dlst  *prev;      // Previous node (doubly-linked)
    int            content;    // Original value
    int            index;      // Normalized index [0..n-1]
    int            pos;        // Current position in stack
    struct s_dlst  *next;      // Next node
} t_dlst;
```

**Doubly-linked list** allows efficient rotations, reverse rotations, and position tracking during cost computation.

---

# Bonus - CHECKER

This project includes a bonus program: *checker*.

The checker validates whether the list of operations produced by push_swap correctly sorts the given stack according to the project rules.

The checker program:
- Takes the same arguments as push_swap
- Reads a list of operations from standard input
- Applies them to stacks A and B
- Verifies the final state of the stacks

It prints:
- **OK** → if stack A is sorted in ascending order and stack B is empty
- **KO** → if the stacks are not in the expected final state
- **Error** → if an invalid instruction or input is encountered

## Internal Logic
1. Parse arguments → initialize stack A
2. Initialize stack B = NULL
3. Read operations from stdin:
     - Execute operation
     - If invalid → Error
4. Check final state:
     - A sorted and B empty → OK
     - Otherwise → KO
