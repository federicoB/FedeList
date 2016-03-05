## What is FedeList?
It's a simple c++ template class that implements a list.
This means that you can use it with every type you need.

## What can i do with FedeList?

Create a list (of pointer to pineapples)
```cpp
    FedeList<PineApple*> pineApples;
```
Add element to the list
``` cpp
    pineApples.push_back(new PineApple());
``` 
Retrive elements from the list
``` cpp
  pineApples.get(5)->gnam();
```
Remove elements from the list
``` cpp
  pineApples.remove(3);
```

The complete reference can be found [here](http://federicob.github.io/FedeList)

## What are the advantages of using FedeList?
Fedelist implements an internal [iterator](http://www.cplusplus.com/reference/iterator/) and is double linked so most of the time the complexity of an operation is only 1 and at maximum N/2 with N equal to the length of the list.
For comparison: most of the others list implementations can have a maximium complexity of N.

## Why are you doing this
I began to develop Fedelist at the univesity (I study Computer Science) for personal interest and for speed up exercises.
It have been useful fon an another project that i've worked on so i continued the development.

## How can i use FedeList?
Just download the files and include FedeList.hpp in your program.
It's a template class so you don't need to compile and link FedeList.cpp because it's included into FedeList.hpp.

##License
Fedelist is distributed with GPL license.
