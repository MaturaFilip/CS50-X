import sys

while True:
    try:
        height = int(input("Height: "))
    except ValueError:
        continue

    if height > 0 and height <= 8:
        break


for i in range(0, height):
    for j in range(height-1, i, -1):
        print(" ", end="")

    for j in range(0, i+1):
        print("#", end="")

    print("  ", end="")

    for j in range(0, i+1):
        print("#", end="")
    print()
