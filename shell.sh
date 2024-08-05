
#!/bin/bash

echo "Select a command to execute:"
echo "1. List files in the current directory"
echo "2. Show the current date and time"
echo "3. Display the current working directory"
echo "4. Display disk usage"
echo "5. Exit"

read -p "Enter your choice: " choice

case $choice in
  1)
    echo "Listing files in the current directory:"
    ls
    ;;
  2)
    echo "Current date and time:"
    date
    ;;
  3)
    echo "Current working directory:"
    pwd
    ;;
  4)
    echo "Displaying disk usage:"
    df -h
    ;;
  5)
    echo "Exiting..."
    exit 0
    ;;
  *)
    echo "Invalid choice. Please try again."
    ;;
esac
