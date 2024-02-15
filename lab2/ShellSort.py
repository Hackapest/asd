import random


def generate_random_array(length, min_val=0, max_val=100):
    return [random.randint(min_val, max_val-1) for _ in range(length)]

