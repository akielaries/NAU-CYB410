## rc4-v0.c

ITER 1 :
```
$ ./rc4-v0 1 hello
087FAE01F8

KEY = 1
STRING = hello
HASH = 087FAE01F8
```
ITER 2 :
```
$ ./rc4-v0 1 HELLO
285F8E21D8

KEY = 1
STRING = HELLO
HASH = 285F8E21D8
```

ITER 3 :
```
$ ./rc4-v0 224 secure_software
F96FCDD6802CC1F80298D5C5439B26

KEY = 224
STRING = secure_software
HASH = F96FCDD6802CC1F80298D5C5439B26
```
ITER 4 :
```
$ ./rc4-v0 int too
28BEF0 

KEY = int
STRING = too
HASH = 28BEF0
```

Produces different hash based on case-type


## rc4_XOR-SWAP-ASCII.c
```

```

## rc4_XOR-SWAP.c
```

```
We can verify out hash results using the test vectors see 
[here](https://en.wikipedia.org/wiki/RC4#Test_vectors)
https://en.wikipedia.org/wiki/RC4#Test_vectors

