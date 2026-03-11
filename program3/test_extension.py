import random
import time
import mathutils

def python_variance(data):
    n = len(data)

    mean = sum(data) / n

    var = 0.0
    for x in data:
        var += (x - mean) ** 2

    return var / n


# generate large dataset
N = 10_000_000
data = [random.random() for _ in range(N)]


print("Running pure Python version...")
start = time.time()
v1 = python_variance(data)
end = time.time()

print("Python variance:", v1)
print("Python time:", end - start)


print("\nRunning C extension version...")
start = time.time()
v2 = mathutils.variance(data)
end = time.time()

print("C variance:", v2)
print("C time:", end - start)

