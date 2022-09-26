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
./rc4-v0 1 HELLO
285F8E21D8

KEY = 1
STRING = HELLO
HASH = 285F8E21D8
```

ITER 3 :
```
./rc4-v0 224 secure_software
F96FCDD6802CC1F80298D5C5439B26

KEY = 224
STRING = secure_software
HASH = F96FCDD6802CC1F80298D5C5439B26
```

Produces different hash based on case-type


## rc4_XOR-SWAP-ASCII.c
```

```

## rc4_XOR-SWAP.c
```

```

