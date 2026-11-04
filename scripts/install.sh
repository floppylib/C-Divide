#!/usr/bin/env sh
set -eu

if [ "$#" -ne 1 ]; then
  echo "Usage: $0 /path/to/cdiv" >&2
  exit 2
fi

source_file=$1
if [ ! -f "$source_file" ]; then
  echo "Error: file not found: $source_file" >&2
  exit 1
fi
if [ ! -x "$source_file" ]; then
  echo "Error: file is not executable: $source_file" >&2
  exit 1
fi

prefix=\${PREFIX:-"$HOME/.local"}
destination="$prefix/bin"
mkdir -p "$destination"
install -m 755 "$source_file" "$destination/cdiv"

echo "C÷ command-line tool installed to: $destination/cdiv"
case ":$PATH:" in
  *":$destination:"*) echo "You can run: cdiv help" ;;
  *) echo "Add this directory to PATH if needed: $destination" ;;
esac
