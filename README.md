*This project has been created as part of the 42 curriculum by somenvie.*

# DESCRIPTION


# INSTRUCTIONS


# RESOURCES


# PROJECT SETUP

MAIN
  ├─ parsing(argc, argv)
  ├─ is_sorted(a)?
  ├─ normalize(a)
  └─ size <= 5?
       ├─ YES: low_sort()
       └─ NO : turk_sort(&a, &b)
            │
            ├─ PHASE 1: Push A → B (chunks)
            │   while (a.size > 3):
            │     for each element in A:
            │       if index in current chunk:
            │         pb() + rb()
            │       else:
            │         ra()
            │
            ├─ sort_three(&a)
            │
            ├─ PHASE 2: Push B → A (greedy cost)
            │   while (b.size > 0):
            │     calculate costs for each B values
            │     find_cheapest()
            │     execute_moves_optimized(rr/rrr)
            │     pa()
            │
            └─ final_rotate(&a)   → put min at top