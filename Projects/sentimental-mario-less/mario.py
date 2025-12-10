while True:
    try:
        # Ask the user for input
        height = int(input("Height: "))

        # Check if the input is within the valid range
        if 1 <= height <= 8:
            break
    except ValueError:
        # If input is not an integer, ignore and re-prompt
        pass

# Build and print the pyramid
for i in range(1, height + 1):
    spaces = height - i
    hashes = i
    print(" " * spaces + "#" * hashes)
