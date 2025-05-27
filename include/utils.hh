#pragma once

#include <fstream>
#include <nlohmann/json.hpp>
#include <optional>
#include <print>
#include <string>
#include <vector>

namespace utils {

namespace json {

// Load a JSON file and parse it into a vector of type T
// Returns std::nullopt if the file cannot be opened or if parsing fails
template <typename T>
std::optional<std::vector<T>> loadJsonArray(const std::string &path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    std::println(stderr, "Failed to open file: {}", path);
    return std::nullopt;
  }

  try {
    nlohmann::json j;
    file >> j;

    if (!j.is_array()) {
      std::println(stderr, "JSON is not an array in file: {}", path);
      return std::nullopt;
    }
    return j.get<std::vector<T>>();
  } catch (const nlohmann::json::parse_error &e) {
    std::println(stderr, "JSON parsing error in file {}: {}", path, e.what());
  } catch (const nlohmann::json::type_error &e) {
    std::println(stderr, "JSON type error in file {}: {}", path, e.what());
  } catch (const std::exception &e) {
    std::println(stderr, "Unexpected error in file {}: {}", path, e.what());
  }

  return std::nullopt;
}

} // namespace json

} // namespace utils
