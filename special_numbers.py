import time

def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    max_divisor = int(n**0.5) + 1
    for i in range(3, max_divisor, 2):
        if n % i == 0:
            return False
    return True

def is_palindrome(n):
    str_n = str(n)
    return str_n == str_n[::-1]

def main():
    values = []
    timestart = time.time()
    for n in range(1000000000):
        if is_palindrome(n) and is_prime(n):
            values.append(n)
    timeend = time.time()
    #time in minutes
    print("Values: ", values)
    print("Time: ", (timeend - timestart) / 60)
    print("Total values: ", len(values))
    


main()
