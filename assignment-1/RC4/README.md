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


## rc4_XOR-SWAP.c
This version uses the logic operator XOR to swap our elements
instead of previous implementation with ints and chars
ITER 1 :
```
$ ./XOR-SWAP Key Plaintext
\xbb \xf3 \x16 \xe8 \xd9 \x40 \xaf \x0a \xd3 

KEY = Key
STRING = Plaintext
HASH = \xbb \xf3 \x16 \xe8 \xd9 \x40 \xaf \x0a \xd3
```

ITER 2:
```
$ ./XOR-SWAP 1088 password
\x56 \x89 \x0d \x9f \x31 \xc0 \x49 \x1e %

KEY = 1088
STRING = password
HASH = \x56 \x89 \x0d \x9f \x31 \xc0 \x49 \x1e 
```

## rc4_XOR-SWAP-ASCII.c
This program runs the RC4 algorithm and converts it back to
its original plaintext. Encoder and Decoder
```
$ ./XOR-SWAP-ASCII Key Plaintext
\xbb\xf3\x16\xe8\xd9\x40\xaf\x0a\xd3
encoded:�3V(@�J
\x50\x6c\x61\x69\x6e\x74\x65\x78\x74
decoded:Plaintext

KEY = Key
STRING = Plaintext
HASH = \xbb\xf3\x16\xe8\xd9\x40\xaf\x0a\xd3

```
We can verify out hash results using the test vectors see 
[here](https://en.wikipedia.org/wiki/RC4#Test_vectors)
https://en.wikipedia.org/wiki/RC4#Test_vectors

```
$ ./rc4-v0 Key Plaintext
BBF316E8D940AF0AD3

KEY = Key
STRING = Plaintext
HASH = BBF316E8D940AF0AD3
```

