#!/usr/bin/env bash

README="README.md"
DIRS=("C++" "JavaScript")

# Function to check if a solution exists in README
contains() {
  file_name="$1"
  grep -q "$file_name" "$README"
}

MISSINGS=()

# Loop through solution directories
for dir in "${DIRS[@]}"; do
  files=$(find "$dir" -type f -name "solutions_*.hpp" -o -name "solutions_*.js" ! -name "*.spec.js")
  for solution in $files; do
    filename=$(basename "$solution")
    if ! contains "$filename"; then
      MISSINGS+=("$solution")
    fi
  done
done

# Print missing solutions
if [ ${#MISSINGS[@]} -eq 0 ]; then
  echo "All solutions are listed in README.md."
else
  echo "The following solutions are missing from README.md:"
  printf '%s\n' "${MISSINGS[@]}"
fi
