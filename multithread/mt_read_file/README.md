# wikitext-2

```bash
$ bash get_wikitext2.sh 
$ make
$ ./main
```

## count words and lines

```bash
$ time ./main
nLines 44836, nWords 2596679

real    0m0.165s
user    0m0.161s
sys     0m0.004s

$ time python main.py
nLines 44836 nWords 2507007

real    0m0.674s
user    0m0.661s
sys     0m0.013s
```

## copy and count lines

```bash
$ time ./main
nLines 44836

real    0m0.057s
user    0m0.018s
sys     0m0.039s

$ time python main.py
nLines 44836

real    0m0.170s
user    0m0.125s
sys     0m0.045s
```


# wikitext-103

## count words and lines

```bash
$ time ./main
nLines 1809468, nWords 105499704

real    0m4.807s
user    0m4.716s
sys     0m0.091s

$ time python main.py
nLines 1809468 nWords 101880768

real    0m15.226s
user    0m15.069s
sys     0m0.158s
```


## copy and count lines

```bash
$ time python main.py
nLines 1809468

real    0m3.620s
user    0m2.869s
sys     0m0.751s

$ time ./main		# operator>>
nLines 1809468

real    0m6.055s
user    0m0.455s
sys     0m0.945s

$ time ./main		# `write` function
nLines 1809468

real    0m1.290s
user    0m0.466s
sys     0m0.824s

$ time ./main		# `write` and class
nLines 1809468

real    0m5.642s
user    0m0.461s
sys     0m0.908s

$ time ./main		# `write`, class, 10 threads
nLines 1809468

real    0m5.907s
user    0m0.639s
sys     0m1.023s

$ time ./main		# `write`, class, 4 threads
nLines 1809468

real    0m1.552s
user    0m0.659s
sys     0m0.894s

```
