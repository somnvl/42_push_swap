*This project has been created as part of the 42 curriculum by somenvie.*

# DESCRIPTION


# INSTRUCTIONS


# RESOURCES


# PROJECT SETUP

MAIN
│
├─ STEP 1: PARSING
│  INPUT:  ./push_swap 4 67 3 87 23
│  OUTPUT: a = [4] -> [67] -> [3] -> [87] -> [23]
│
├─ STEP 2: NORMALIZE
│  INPUT:  a = [4] -> [67] -> [3] -> [87] -> [23]
│  OUTPUT: a (indices) = [2] -> [4] -> [1] -> [5] -> [0]
│          (4 → index 2, 67 → index 4, etc.)
│
├─ STEP 3: IS_SORTED?
│  YES → end of program
│  NO → continue
│
├─ STEP 4: SIZE <= 5?
│  YES → low_sort(size, &a, &b)
│        ├─ sa()   (if size == 2)
│        ├─ sort_three() (if size == 3)
│        ├─ sort_four()  (if size == 4)
│        └─ sort_five()  (if size == 5)
│
│  NO → STEP 5: TURKISH ALGORITHM
│        │
│        └─ turk_sort(size, &a, &b)
│           │
│           ├─ PHASE 1: A → B (by chunks)
│           │  └─ while (a.size > 3):
│           │     ├─ if (top_a.index IN chunk):
│           │     │  pb(a, b)
│           │     │  rb(b)  [optional placement]
│           │     └─ else:
│           │        ra(a)
│           │
│           ├─ sort_three(&a)
│           │
│           └─ PHASE 2: B → A (greedy cost-based)
│              └─ [Phase 2 code here]
│
└─ CLEANUP: free_list(a), free_list(b)

----

Moves
  |
  |      TAILLE FIXE = 20
8500 |      ●
     |     /|
6300 |    / |                DIVISION PROPORTIONNELLE
5400 |   /  |     ●---------●
2800 |  /   |    /|
1900 | /    |   / |         ●
 630 |●     |  /  |        /|
  45 |      | /   |       / | ●
     |      |/    |      /  |/|
     └──────┴─────┴─────┴───┴─┴────→ Taille
            20   100  200  500 1000


Legende:
● = taille fixe = 20
○ = division proportionnelle

----