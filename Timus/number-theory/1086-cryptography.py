N = 200_000
sieve = [True] * N
prime = [2]

for i in range(3, N, 2):
    if not sieve[i]:
        continue

    prime.append(i)

    for j in range(i * i, N, i):
        sieve[j] = False


n = int(input())
for i in range(n):
    k = int(input())
    print(prime[k - 1])
