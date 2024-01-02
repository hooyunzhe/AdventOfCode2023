def read_input():
    with open("input.txt") as input_file:
        test = input_file.readlines()
        return [[c for c in line] for line in test]

def check_adjacent_symbols(schematic, line, c):
    symbols = "#-*&+=/$%@"
    prev_line = line - 1 if line > 0 else line
    next_line = line + 1 if line < len(schematic) - 1 else line
    prev_c = c - 1 if c > 0 else c
    next_c = c + 1 if c < len(schematic[line]) - 1 else c

    return (schematic[line][prev_c] in symbols or
            schematic[line][next_c] in symbols or
            schematic[prev_line][prev_c] in symbols or
            schematic[prev_line][c] in symbols or
            schematic[prev_line][next_c] in symbols or
            schematic[next_line][prev_c] in symbols or
            schematic[next_line][c] in symbols or
            schematic[next_line][next_c] in symbols)

schematic = read_input()

part_number_sum = 0

for line in range(len(schematic)):

    current_number = 0
    is_part_number = False

    for c in range(len(schematic[line])):
        if schematic[line][c].isdigit():
            if current_number:
                current_number *= 10
            current_number += int(schematic[line][c])
            if not is_part_number:
                is_part_number = check_adjacent_symbols(schematic, line, c)

        if not schematic[line][c].isdigit() or c == len(schematic[line]) - 1:
            if is_part_number:
                part_number_sum += current_number
            current_number = 0
            is_part_number = False

print(f"Sum of all part numbers of the schematic: {part_number_sum}")
