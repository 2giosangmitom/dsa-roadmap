#!/usr/bin/env bash

# Clear the screen
clear

cat <<'EOF'

██████╗ ██████╗  █████╗  ██████╗████████╗██╗ ██████╗███████╗
██╔══██╗██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██║██╔════╝██╔════╝
██████╔╝██████╔╝███████║██║        ██║   ██║██║     █████╗  
██╔═══╝ ██╔══██╗██╔══██║██║        ██║   ██║██║     ██╔══╝  
██║     ██║  ██║██║  ██║╚██████╗   ██║   ██║╚██████╗███████╗
╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝   ╚═╝ ╚═════╝╚══════╝
EOF

# Ask for language
echo -e "--------------------"
echo "Which language you want to implement?"
echo "  1. C++"
echo "  2. JavaScript"

echo -n "Your choice: "
read -r choice

handle_details() {
  lang=$1
  echo -n "Enter problem's number (or title): "
  read -r pnum

  dir="$lang/solutions_$pnum"
  mkdir -p "$dir"

  case $lang in
  "C++")
    touch "$dir/solutions_$pnum.hpp"
    touch "$dir/solutions_${pnum}_tests.cc"
    ;;
  "JavaScript")
    touch "$dir/solutions_$pnum.js"
    touch "$dir/solutions_${pnum}.spec.js"
    ;;
  esac
}

case $choice in
"1")
  handle_details "C++"
  ;;
"2")
  handle_details "JavaScript"
  ;;
*)
  echo "Unknown"
  ;;
esac
