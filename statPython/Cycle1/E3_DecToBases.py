dec_num = int(input("Enter a Number: "))

octal=oct(dec_num)
binary=bin(dec_num)
hexa=(hex(dec_num)).upper()


print(f"Binary: {binary[2:]}\nOctal: {octal[2:]}\nHexa: {hexa[2:]}")
