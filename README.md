# memesort

### Proof of Concept for MemeSort Algorithm, which sorts by meme. 
For most cases it will be faster than mergesort or qsort.

## Compilation: 
```bash
make
```

## Usage:
```bash
cat "somefilewithwords.txt" | ./a.out
```

### A text file containing over 466k English words. (randomize it using shuf): 
https://raw.githubusercontent.com/dwyl/english-words/master/words_alpha.txt

### Compare with GNU Sort (mergesort)

```
time sort    < <(head -n 1000000 somefilewithwords.txt) # head used here to trick GNU Sort to work in single threaded mode
time ./a.out < <(head -n 1000000 somefilewithwords.txt)
```
# Goals:
* Needs proper explaination, visalisation of how data structure and whole sorting works. Sometimes even i get confused.
* ~~Has huge memory footprint, probably leaks.. definitively needs further optimisations.~~
* Multi-threading support. For now it's single-threaded.

# License:
### GNU General Public License v3.0
