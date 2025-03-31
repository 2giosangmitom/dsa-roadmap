# LeetCode Patterns

Welcome to this **DSA roadmap** - a structured guide designed to help you **learn and master Data Structures and Algorithms (DSA)** efficiently.

![loc](https://tokei.rs/b1/github/2giosangmitom/practice?category=code&style=flat-square)

## Why Did I Create This?

As a first-year university student, I set a goal to **master DSA as soon as possible** to prepare for my future career. Like many beginners, I started with **zero knowledge** about DSA and quickly realized that the vast number of coding problems available online was overwhelming. It was hard to figure out **where to start, what to focus on, and how to progress systematically**.

To solve this, I created this repository to **organize and simplify the learning process**. This roadmap is inspired by the [VNOI Roadmap](https://roadmap.sh/r/vnoi-roadmap), originally designed for **competitive programming**. However, I have adapted and restructured it to focus on **LeetCode-style problem-solving**, making it more suitable for **technical interviews and real-world coding assessments**.

## Prerequisites

Before diving into the roadmap, ensure you have a solid foundation in these key areas:

- Comfortable with at least **one programming language** (C++, Java, Python, etc.)
- Understanding of **basic programming concepts** (syntax, loops, functions, OOP)
- Familiarity with **arrays and linked lists**
- Basic knowledge of **recursion**
- Understanding of **Big-O notation** and **complexity analysis**
- Algebra fundamentals (**logarithms, exponents, modular arithmetic**)

## The Roadmap

This is my roadmap to learn DSA.

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
    R --> Q[Sort and Search]
    T --> U[Tries]
    T --> X[Graphs]
    X --> Y[Backtracking]

    %% Problem-Solving Techniques
    Y --> K[Dynamic Programming]
    K --> O[Bit Manipulation]
    K --> V[Greedy]
    K --> M[Math and Geometry]

    %% Additional Paths
    W --> Q
    Q --> E
```

Each topic includes **curated LeetCode problems** and explanations to help you build a **strong problem-solving foundation**.

## Let's Go

### Two Pointers

- [ ]: Add introduction to Two Pointers

| Link                                                                                                            | Solutions                                               | Difficulty |
| --------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------- | ---------- |
| [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)                                             | [C++](./C++/solutions_125/solutions_125.hpp)            | Easy       |
| [Remove Element](https://leetcode.com/problems/remove-element/)                                                 | [C++](./C++/solutions_27/solutions_27.hpp)              | Easy       |
| [Reverse String](https://leetcode.com/problems/reverse-string/)                                                 | [C++](./C++/solutions_344/solutions_344.hpp)            | Easy       |
| [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)                           | [C++](./C++/solutions_11/solutions_11.hpp)              | Medium     |
| [Merge Two 2D Arrays by Summing Values](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/)   | [C++](./C++/solutions_2570/solutions_2570.hpp)          | Easy       |
| [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)       | [C++](./C++/solutions_26/solutions_26.hpp)              | Easy       |
| [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)           | [C++](./C++/solutions_167/solutions_167.hpp)            | Medium     |
| [3Sum](https://leetcode.com/problems/3sum/)                                                                     | [C++](./C++/solutions_15/solutions_15.hpp)              | Medium     |
| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)                   | [C++](./C++/solutions_5/solutions_5.hpp)                | Medium     |
| [Next Permutation](https://leetcode.com/problems/next-permutation/)                                             | [C++](./C++/solutions_31/solutions_31.hpp)              | Medium     |
| [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | [JavaScript](./JavaScript/solutions_80/solutions_80.js) | Medium     |
