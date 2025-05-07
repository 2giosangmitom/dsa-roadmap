#include "linked_list.hpp"

#include <sstream>
#include <string>

// Constructors
/**
 * @brief Default constructor for ListNode
 */
ListNode::ListNode() : val{0}, next{nullptr} {}

/**
 * @brief Constructor for ListNode with a value
 * @param val Value to be assigned to the node
 */
ListNode::ListNode(int val) : val{val}, next{nullptr} {}

/**
 * @brief Constructor for ListNode with a value and next node
 * @param val Value to be assigned to the node
 * @param next Pointer to the next node
 */
ListNode::ListNode(int val, ListNode *next) : val{val}, next{next} {}

// Factory function to create linked list
/**
 * @brief Factory function to create linked list
 * @param list Vector of values to create the list from
 * @return Pointer to the head of the created linked list
 */
ListNode *make_list(const std::vector<int> &list) {
  ListNode *head = nullptr;
  ListNode *current = head;

  for (const int &val : list) {
    auto new_node = new ListNode(val);
    if (current == nullptr) {
      head = new_node;
      current = new_node;
    } else {
      current->next = new_node;
      current = new_node;
    }
  }

  return head;
}

// Represent list in string
/**
 * @brief Represent list in string
 * @return String representation of the list
 */
std::string ListNode::to_string() const {
  std::stringstream result;

  for (auto head = this; head != nullptr; head = head->next) {
    result << std::to_string(head->val);
    if (head->next) {
      result << " -> ";
    }
  }

  return result.str();
}

// Overload output operator
/**
 * @brief Overload output operator to print the list
 * @param os Output stream
 * @param head Pointer to the head of the list
 * @return Output stream with the list representation
 */
std::ostream &operator<<(std::ostream &os, ListNode *head) {
  os << head->to_string();
  return os;
}

// Overload equality operator
/**
 * @brief Overload equality operator to compare two linked lists
 * @param lhs Left-hand side list to compare
 * @param rhs Right-hand side list to compare
 * @return True if the lists are equal, false otherwise
 */
bool operator==(const ListNode &lhs, const ListNode &rhs) {
  auto currentA = &lhs;
  auto currentB = &rhs;

  while (currentA != nullptr && currentB != nullptr) {
    if (currentA->val != currentB->val) {
      return false;
    }
    currentA = currentA->next;
    currentB = currentB->next;
  }

  return currentA == currentB;
}

// Release dynamic allocated memory for linked list
/**
 * @brief Release dynamic allocated memory for linked list
 * @param heads Initializer list of pointers to the heads of the lists
 */
void delete_list(std::initializer_list<ListNode *> heads) {
  for (auto head : heads) {
    ListNode *curr = head;

    while (curr != nullptr) {
      ListNode *next_node = curr->next;
      delete curr;
      curr = next_node;
    }
  }
}
