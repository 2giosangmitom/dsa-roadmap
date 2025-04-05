#!/usr/bin/env bash

# Clear the screen
clear

# Print the header
cat <<'EOF'

██████╗ ██████╗  █████╗  ██████╗████████╗██╗ ██████╗███████╗
██╔══██╗██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██║██╔════╝██╔════╝
██████╔╝██████╔╝███████║██║        ██║   ██║██║     █████╗  
██╔═══╝ ██╔══██╗██╔══██║██║        ██║   ██║██║     ██╔══╝  
██║     ██║  ██║██║  ██║╚██████╗   ██║   ██║╚██████╗███████╗
╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝   ╚═╝ ╚═════╝╚══════╝
EOF

# Ask for the problem number or title
echo -n "Enter problem's number (or title): "
read -r pnum

# Check if the input is empty
if [[ -z "$pnum" ]]; then
    echo "Problem number cannot be empty."
    exit 1
fi

# Create the directory structure
dir="src/solutions_${pnum}"
mkdir -p "$dir"
touch "$dir/solutions_$pnum.hpp"
touch "$dir/solutions_${pnum}_test.cc"
