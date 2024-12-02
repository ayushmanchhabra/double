# double

I wrote this program in 2023 with the intention of answering the problem that would eventually arise:

Q: How to onboard software engineers into an AI tech stack?.

A: There should be a small program, using a universally understood language, that could describe the core attributes/features of what the 2020s AI run is all about.

In the process, I learnt "AI" from first principles. The original gist can be found [here](https://gist.github.com/ayushmanchhabra/5631f274d34ba30b27ae898b9dbb7bdf):

## Building

Use any C compiler you want.

Clang:
```shell
clang ./double.c -o ./double.exe
```

GCC:
```shell
gcc ./double.c -o ./double.exe
```

Usage:
```shell
└─$ ./double.exe 
Computed Weight: 1.999501
Estimate double of 10: 19.995007
Sample size: 5
```

## License

MIT