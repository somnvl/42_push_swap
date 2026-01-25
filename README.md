*This project has been created as part of the 42 curriculum by somenvie.*

# DESCRIPTION

**Push Swap** is a sorting challenge that requires you to sort a random list of integers using two stacks (A and B) and a predefined set of operations. The goal is to minimize the number of operations needed to sort the input.

The project combines several algorithmic concepts:
- **Sorting algorithms** - Understanding of different approaches (small arrays vs large arrays)
- **Stack-based operations** - Manipulation through restricted operations only
- **Optimization** - Cost-based decision making to minimize moves
- **Data structures** - Doubly-linked lists for efficient stack operations

This implementation uses the **Turkish Algorithm** (also known as the Turk algorithm) for optimal sorting of larger datasets, achieving competitive operation counts through chunking and greedy cost-based insertion.

## Project Structure

```
push_swap/
├── includes/
│   └── push_swap.h
├── libft/
├── obj/
├── srcs/
│   ├── debug.c
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
│   ├── turk_chunk.c
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
- [Sorting Algorithms Comparison](https://www.geeksforgeeks.org/sorting-algorithms-in-python/) - Algorithm fundamentals
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/) - Stack operations overview

### Turkish Algorithm Resources
- Turk algorithm blog posts discussing chunk-based sorting strategies
- Cost optimization in two-stack sorting environments


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

### Test Commands

```bash
# Test with validation (pass/fail check)
ARG=$(shuf -i 1-100 -n 100 | xargs); ./push_swap $ARG | ./checker_linux $ARG

# Count total operations for random integers
./push_swap $(shuf -i 0-100 -n 100 | xargs) | wc -l

# Combined: count operations AND validate correctness
ARG=$(shuf -i 1-100 -n 100 | xargs); ./push_swap $ARG | tee >(wc -l) | ./checker_linux $ARG
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

### Phase A: A → B (Chunking)

```
Max Size = 100
Chunk Step = 5

PHASE A: Push elements from A to B by chunks
┌──────────────────────────────────────────┐
│ while (stack_a.size > 3):                │
│   if (top_a.index IN current_chunk):     │
│     pb(a, b)         // push to B        │
│     rb(b)            // optional rotate  │
│   else:                                  │
│     ra(a)            // rotate A         │
│                                          │
│   if (no elements left in chunk):        │
│     chunk_next()     // move to next     │
└──────────────────────────────────────────┘
```

**Purpose:** Distribute elements from stack A to stack B in ordered chunks, reducing the problem space for later insertion.

### Phase B: B → A (Greedy Cost-Based)

```
PHASE B: Insert back from B to A greedily
┌──────────────────────────────────────────┐
│ while (stack_b NOT empty):               │
│   1. Pick cheapest element from B        │
│      (minimum total rotation cost)       │
│   2. Calculate optimal path to place it  │
│      in stack A (position > element < )  │
│   3. Execute moves (optimize with rr/rrr)
│   4. pa(a, b)        // push to A        │
└──────────────────────────────────────────┘
```

**Purpose:** Insert all elements from B back into A at their correct positions, using cost-based selection to minimize total rotations.

### Cost Calculation

```c
cost_to_top(stack, position):
  if position <= size/2:
    return position           // ra() cost
  else:
    return position - size    // rra() cost (negative)

total_cost(cost_a, cost_b):
  if both same direction:
    return max(abs)           // parallel ops: rr or rrr
  if both opposite:
    return sum(abs)           // sequential ops
  else:
    return sum(abs)
```

### Final Rotate

```
After Phase B, stack A is sorted but may need rotation
to place minimum at top:

position = find_min(a)
if position <= size/2:
  rotate forward (ra)   // top rotations
else:
  rotate backward (rra) // bottom rotations
```

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

### Chunking System

```c
chunk_step(size)              // Calculate step based on size
chunk_init(&start, &end, ...) // Initialize first chunk range
chunk_left(stack, start, end) // Check if elements remain in chunk
chunk_next(&start, &end, ...) // Move to next chunk
```

### Cost Selection

```c
pick_cheapest()               // Find optimal element from B
  → pos_a()                   // Position in A (greedy insertion)
  → pos_b()                   // Position in B
  → cost_to_top()             // Calculate rotation cost
  → total_cost()              // Compare all options

apply_cheapest()              // Execute moves with optimization
  → apply_both()              // Parallel rotations (rr/rrr)
  → apply_a()                 // Individual A rotations
  → apply_b()                 // Individual B rotations
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

**Doubly-linked list** enables efficient traversal in both directions and O(1) insertion/deletion operations.


---