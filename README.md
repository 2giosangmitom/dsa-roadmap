# DSA Roadmap

Hello, welcome to this DSA Roadmap. This is my personal DSA roadmap with LeetCode.

## 🗺️ The Roadmap

```mermaid
---
title: DSA Roadmap
---
flowchart TD
    %% Basic Foundations
    A[Two Pointers] --> B[Hash Maps and Sets]
    A --> C[Linked Lists]
    B --> E[Binary Search]
    B --> F[Sliding Window]
    B --> G[Prefix Sums]

    %% Intermediate Concepts
    C --> D[Fast and Slow Pointers]
    C --> J[Stacks and Queues]
    J --> R[Heaps]

    %% Advanced Data Structures
    R --> T[Trees]
    R --> W[Intervals]
    R --> Q[Sort]
    T --> U[Tries]
    T --> X[Graphs]
    X --> Y[Backtracking]

    %% Problem-Solving Techniques
    Y --> K[Dynamic Programming]
    K --> O[Bit Manipulation]
    K --> V[Greedy]
    K --> M[Math]

    %% Additional Paths
    W --> Q
    Q --> E
```

## 🚀 Let's Go

> [!NOTE]
> All solutions in this repository are written in **Rust**. If you're not familiar with Rust, I highly recommend learning the basic syntax and core concepts before diving into the problems. You can find a great resource for learning Rust [here](https://doc.rust-lang.org/book/).

### Two Pointers

| Link                                                                                                            | Solutions                                                           | Difficulty |
| --------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------- | ---------- |
| [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)                                             | [Rust](./src/two_pointers/valid_palindrome.rs)                      | Easy       |
| [Remove Element](https://leetcode.com/problems/remove-element/)                                                 | [Rust](./src/two_pointers/remove_element.rs)                        | Easy       |
| [Is Subsequence](https://leetcode.com/problems/is-subsequence)                                                  | [Rust](./src/two_pointers/is_subsequence.rs)                        | Easy       |
| [Reverse String](https://leetcode.com/problems/reverse-string/)                                                 | [Rust](./src/two_pointers/reverse_string.rs)                        | Easy       |
| [Merge Two 2D Arrays by Summing Values](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/)   | [Rust](./src/two_pointers/merge_two_2d_arrays_by_summing_values.rs) | Easy       |
| [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)                                         | TODO                                                                | Easy       |
| [Move Zeroes](https://leetcode.com/problems/move-zeroes)                                                        | [Rust](./src/two_pointers/move_zeros.rs)                            | Easy       |
| [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)       | TODO                                                                | Easy       |
| [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)                           | [Rust](./src/two_pointers/container_with_most_water.rs)             | Medium     |
| [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)           | [Rust](./src/two_pointers/two_sum.rs)                               | Medium     |
| [3Sum](https://leetcode.com/problems/3sum/)                                                                     | TODO                                                                | Medium     |
| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)                   | TODO                                                                | Medium     |
| [Next Permutation](https://leetcode.com/problems/next-permutation/)                                             | TODO                                                                | Medium     |
| [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | TODO                                                                | Medium     |
| [Rotate Array](https://leetcode.com/problems/rotate-array)                                                      | TODO                                                                | Medium     |
| [4Sum](https://leetcode.com/problems/4sum)                                                                      | TODO                                                                | Medium     |

### Linked Lists

| Link                                                                                                              | Solutions                                        | Difficulty |
| ----------------------------------------------------------------------------------------------------------------- | ------------------------------------------------ | ---------- |
| [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list)                                          | [Rust](./src/linked_list/reverse_linked_list.rs) | Easy       |
| [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements)                          | TODO                                             | Easy       |
| [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)                             | TODO                                             | Easy       |
| [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)               | TODO                                             | Easy       |
| [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)                                             | TODO                                             | Easy       |
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)                                                 | [Rust](./src/linked_list/add_two_numbers.rs)     | Medium     |
| [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii)                                            | TODO                                             | Medium     |
| [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii)                                    | TODO                                             | Medium     |
| [Rotate List](https://leetcode.com/problems/rotate-list)                                                          | TODO                                             | Medium     |
| [Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/) | TODO                                             | Medium     |
| [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)               | TODO                                             | Medium     |
| [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs)                                          | TODO                                             | Medium     |
| [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list)                                        | TODO                                             | Medium     |

### Hash Maps and Hash Sets

| Link                                                                                                          | Solutions                         | Difficulty |
| ------------------------------------------------------------------------------------------------------------- | --------------------------------- | ---------- |
| [Two Sum](https://leetcode.com/problems/two-sum/)                                                             | [Rust](./src/hash_map/two_sum.rs) | Easy       |
| [Find Missing and Repeated Values](https://leetcode.com/problems/find-missing-and-repeated-values/)           | TODO                              | Easy       |
| [Merge Two 2D Arrays by Summing Values](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/) | TODO                              | Easy       |
| [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)                                   | TODO                              | Easy       |
| [Roman to Integer](https://leetcode.com/problems/roman-to-integer/)                                           | TODO                              | Easy       |
| [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)                                 | TODO                              | Easy       |
| [LRU Cache](https://leetcode.com/problems/lru-cache/)                                                         | TODO                              | Medium     |
| [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)                                                   | TODO                              | Medium     |
| [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)                   | TODO                              | Medium     |
| [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)                                         | TODO                              | Medium     |

### Sliding Window

| Link                                                                                                                                        | Solutions                                                                      | Difficulty |
| ------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ | ---------- |
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)             | [Rust](./src/sliding_window/longest_substring_without_repeating_characters.rs) | Medium     |
| [Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) | TODO                                                                           | Medium     |
| [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)                           | TODO                                                                           | Medium     |

### Binary Search

| Link                                                                                                                                              | Solutions | Difficulty |
| ------------------------------------------------------------------------------------------------------------------------------------------------- | --------- | ---------- |
| [Binary Search](https://leetcode.com/problems/binary-search/)                                                                                     | TODO      | Easy       |
| [Maximum Count of Positive Integer and Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/)   | TODO      | Easy       |
| [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | TODO      | Medium     |
| [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)                                                   | TODO      | Medium     |
| [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)                                                                           | TODO      | Medium     |
| [Find Peak Element](https://leetcode.com/problems/find-peak-element/)                                                                             | TODO      | Medium     |
| [Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/)                                                                 | TODO      | Medium     |
| [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)                                                         | TODO      | Hard       |
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence)                                                    | TODO      | Medium     |

### Math

| Link                                                                                                                                                                   | Solutions                 | Difficulty |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------- | ---------- |
| [Stone Removal Game](https://leetcode.com/problems/stone-removal-game/)                                                                                                | TODO                      | Easy       |
| [Water Bottles](https://leetcode.com/problems/water-bottles/)                                                                                                          | TODO                      | Easy       |
| [Add Digits](https://leetcode.com/problems/add-digits/)                                                                                                                | TODO                      | Easy       |
| [Palindrome Number](https://leetcode.com/problems/palindrome-number/)                                                                                                  | TODO                      | Easy       |
| [Largest Number At Least Twice of Others](https://leetcode.com/problems/largest-number-at-least-twice-of-others/)                                                      | TODO                      | Easy       |
| [Check if Number is a Sum of Powers of Three](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/)                                              | TODO                      | Medium     |
| [Reverse Integer](https://leetcode.com/problems/reverse-integer/)                                                                                                      | TODO                      | Medium     |
| [Pow(x, n)](https://leetcode.com/problems/powx-n/)                                                                                                                     | [Rust](./src/math/pow.rs) | Medium     |
| [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/)                                                                                              | TODO                      | Medium     |
| [Rotate Image](https://leetcode.com/problems/rotate-image)                                                                                                             | TODO                      | Medium     |
| [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)                                                                                      | TODO                      | Medium     |
| [Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion)                                                                                                   | TODO                      | Medium     |
| [Lexicographically Smallest Negated Permutation that Sums to Target](https://leetcode.com/problems/lexicographically-smallest-negated-permutation-that-sums-to-target) | TODO                      | Medium     |
| [Three Divisors](https://leetcode.com/problems/three-divisors)                                                                                                         | TODO                      | Easy       |
| [Ugly Number](https://leetcode.com/problems/ugly-number)                                                                                                               | TODO                      | Easy       |
| [Count Primes](https://leetcode.com/problems/count-primes/)                                                                                                            | TODO                      | Medium     |
| [Closest Prime Numbers in Range](https://leetcode.com/problems/closest-prime-numbers-in-range/)                                                                        | TODO                      | Medium     |

### Stacks and Queues

| Link                                                                                                                | Solutions                                                                 | Difficulty |
| ------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------- | ---------- |
| [Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/) | [Rust](./src/stack_and_queue/remove_all_adjacent_duplicates_in_string.rs) | Easy       |
| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)                                               | TODO                                                                      | Easy       |
| [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)                         | TODO                                                                      | Easy       |
| [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)                                   | TODO                                                                      | Medium     |
| [Decode String](https://leetcode.com/problems/decode-string)                                                        | TODO                                                                      | Medium     |
| [Basic Calculator](https://leetcode.com/problems/basic-calculator/)                                                 | TODO                                                                      | Hard       |
| [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)                                     | TODO                                                                      | Hard       |

### Heaps

| Link                                                                                              | Solutions | Difficulty |
| ------------------------------------------------------------------------------------------------- | --------- | ---------- |
| [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)                 | TODO      | Medium     |
| [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/)                       | TODO      | Medium     |
| [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | TODO      | Medium     |
| [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)                       | TODO      | Hard       |
| [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)       | TODO      | Hard       |

### Intervals

| Link                                                                                      | Solutions | Difficulty |
| ----------------------------------------------------------------------------------------- | --------- | ---------- |
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/)                         | TODO      | Medium     |
| [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/) | TODO      | Medium     |

### Prefix Sum

| Link                                                                                           | Solutions | Difficulty |
| ---------------------------------------------------------------------------------------------- | --------- | ---------- |
| [Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)        | TODO      | Easy       |
| [Find the Middle Index in Array](https://leetcode.com/problems/find-the-middle-index-in-array) | TODO      | Easy       |
| [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)                  | TODO      | Medium     |
| [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)    | TODO      | Medium     |
| [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)          | TODO      | Medium     |

### Trees

| Link                                                                                                                                                 | Solutions | Difficulty |
| ---------------------------------------------------------------------------------------------------------------------------------------------------- | --------- | ---------- |
| [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal)                                                         | TODO      | Easy       |
| [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal)                                                       | TODO      | Easy       |
| [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal)                                                     | TODO      | Easy       |
| [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree)                                                           | TODO      | Easy       |
| [Symmetric Tree](https://leetcode.com/problems/symmetric-tree)                                                                                       | TODO      | Easy       |
| [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)                                                                              | TODO      | Easy       |
| [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree)                                                           | TODO      | Easy       |
| [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)                                                                          | TODO      | Easy       |
| [Path Sum](https://leetcode.com/problems/path-sum)                                                                                                   | TODO      | Easy       |
| [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree)                               | TODO      | Easy       |
| [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)                                                            | TODO      | Medium     |
| [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/)                                                          | TODO      | Medium     |
| [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)                                                            | TODO      | Medium     |
| [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst)                                                         | TODO      | Medium     |
| [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree)                                     | TODO      | Medium     |
| [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal) | TODO      | Medium     |
| [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum)                                                           | TODO      | Hard       |
| [Vertical Order Traversal of a Binary Tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree)                                 | TODO      | Hard       |
| [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree)                                         | TODO      | Hard       |

### Tries

| Link                                                                                                                   | Solutions | Difficulty |
| ---------------------------------------------------------------------------------------------------------------------- | --------- | ---------- |
| [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)                                          | TODO      | Easy       |
| [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree)                               | TODO      | Medium     |
| [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure) | TODO      | Medium     |
| [Word Search](https://leetcode.com/problems/word-search)                                                               | TODO      | Medium     |
| [Partition String](https://leetcode.com/problems/partition-string)                                                     | TODO      | Medium     |
| [Word Search II](https://leetcode.com/problems/word-search-ii)                                                         | TODO      | Hard       |

### Backtracking

| Link                                                                                                         | Solutions                                  | Difficulty |
| ------------------------------------------------------------------------------------------------------------ | ------------------------------------------ | ---------- |
| [Permutations](https://leetcode.com/problems/permutations/)                                                  | [Rust](./src/backtracking/permutations.rs) | Medium     |
| [Permutations II](https://leetcode.com/problems/permutations-ii/)                                            | TODO                                       | Medium     |
| [Combinations](https://leetcode.com/problems/combinations/)                                                  | TODO                                       | Medium     |
| [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number) | TODO                                       | Medium     |
| [Subsets](https://leetcode.com/problems/subsets/)                                                            | TODO                                       | Medium     |
| [Subsets II](https://leetcode.com/problems/subsets-ii)                                                       | TODO                                       | Medium     |
| [Combination Sum](https://leetcode.com/problems/combination-sum)                                             | TODO                                       | Medium     |
| [Combination Sum II](https://leetcode.com/problems/combination-sum-ii)                                       | TODO                                       | Medium     |
| [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence)                       | TODO                                       | Medium     |
| [N-Queens](https://leetcode.com/problems/n-queens)                                                           | TODO                                       | Hard       |
| [N-Queens II](https://leetcode.com/problems/n-queens-ii)                                                     | TODO                                       | Hard       |
| [Sudoku Solver](https://leetcode.com/problems/sudoku-solver)                                                 | TODO                                       | Hard       |

### Sorting

| Link                                                                     | Solutions                              | Difficulty |
| ------------------------------------------------------------------------ | -------------------------------------- | ---------- |
| [Sort an Array](https://leetcode.com/problems/sort-an-array/)            | [Rust](./src/sorting/sort_an_array.rs) | Medium     |
| [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list) | TODO                                   | Medium     |
| [Sort List](https://leetcode.com/problems/sort-list)                     | TODO                                   | Medium     |
| [Sort Colors](https://leetcode.com/problems/sort-colors)                 | TODO                                   | Medium     |

### Dynamic Programming

| Link                                                                               | Solutions                                              | Difficulty |
| ---------------------------------------------------------------------------------- | ------------------------------------------------------ | ---------- |
| [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle)                | [Rust](./src/dynamic_programming/pascal_triangle.rs)   | Easy       |
| [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii)          | [Rust](./src/dynamic_programming/pascal_triangle_2.rs) | Easy       |
| [Fibonacci Number](https://leetcode.com/problems/fibonacci-number)                 | TODO                                                   | Easy       |
| [Climbing Stairs](https://leetcode.com/problems/climbing-stairs)                   | [Rust](./src/dynamic_programming/climbing_stairs.rs)   | Easy       |
| [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs) | TODO                                                   | Easy       |
| [Coin Change](https://leetcode.com/problems/coin-change)                           | TODO                                                   | Medium     |
| [Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets) | TODO                                                   | Medium     |
| [Unique Paths](https://leetcode.com/problems/unique-paths)                         | TODO                                                   | Medium     |
| [Unique Paths II](https://leetcode.com/problems/unique-paths-ii)                   | TODO                                                   | Medium     |
| [Maximal Square](https://leetcode.com/problems/maximal-square)                     | TODO                                                   | Medium     |
| [House Robber](https://leetcode.com/problems/house-robber)                         | TODO                                                   | Medium     |
| [Target Sum](https://leetcode.com/problems/target-sum)                             | TODO                                                   | Medium     |
| [Maximum Subarray](https://leetcode.com/problems/maximum-subarray)                 | TODO                                                   | Medium     |
| [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum)                 | TODO                                                   | Medium     |
| [Coin Change II](https://leetcode.com/problems/coin-change-ii)                     | TODO                                                   | Medium     |

### Greedy

| Link                                                                                                             | Solutions | Difficulty |
| ---------------------------------------------------------------------------------------------------------------- | --------- | ---------- |
| [Maximize Sum Of Array After K Negations](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations) | TODO      | Easy       |
| [Can Place Flowers](https://leetcode.com/problems/can-place-flowers)                                             | TODO      | Easy       |
| [Jump Game](https://leetcode.com/problems/jump-game)                                                             | TODO      | Medium     |
| [Gas Station](https://leetcode.com/problems/gas-station)                                                         | TODO      | Medium     |
| [Candy](https://leetcode.com/problems/candy)                                                                     | TODO      | Hard       |

### Bit Manipulation

| Link                                                                                     | Solutions                                      | Difficulty |
| ---------------------------------------------------------------------------------------- | ---------------------------------------------- | ---------- |
| [Number of Even and Odd Bits](https://leetcode.com/problems/number-of-even-and-odd-bits) | TODO                                           | Easy       |
| [Power of Two](https://leetcode.com/problems/power-of-two/)                              | [Rust](./src/bit_manipulation/power_of_two.rs) | Easy       |
| [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)                      | TODO                                           | Easy       |
| [Reverse Bits](https://leetcode.com/problems/reverse-bits/)                              | TODO                                           | Easy       |
| [Hamming Distance](https://leetcode.com/problems/hamming-distance/)                      | TODO                                           | Easy       |

### Graph

| Link                                                                                       | Solutions                         | Difficulty |
| ------------------------------------------------------------------------------------------ | --------------------------------- | ---------- |
| [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph) | TODO                              | Easy       |
| [Find Center of Star Graph](https://leetcode.com/problems/find-center-of-star-graph)       | TODO                              | Easy       |
| [Flood Fill](https://leetcode.com/problems/flood-fill/)                                    | [Rust](./src/graph/flood_fill.rs) | Easy       |
| [Clone Graph](https://leetcode.com/problems/clone-graph)                                   | TODO                              | Medium     |
| [Number of Islands](https://leetcode.com/problems/number-of-islands)                       | TODO                              | Medium     |
| [Rotting Oranges](https://leetcode.com/problems/rotting-oranges)                           | TODO                              | Medium     |
| [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/)                   | TODO                              | Medium     |
