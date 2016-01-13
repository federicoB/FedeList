## What is FedeList?
It's a simple c++ template class that implements a list.
This means that you can use it with every type you need.

## What can i do with FedeList?

Create a list (of pointer to pineapples)
```
    FedeList<PineApple*> pineApples;
```
Add element to the list
```
    pineApples.push_back(new PineApple());
```
Retrive elements from the list
```
  pineApples.get(5)->gnam();
```
Remove elements from the list
```
  pineApples.remove(3);
```

## Why are you doing this
I began to develop Fedelist at the univesity (I study Computer Science) for personal interest and for speed up exercises.
It have been useful fon an another project that i've worked on so i continued the development.

## How can i use FedeList?
Just download the files and include FedeList.hpp in your program.
It's a template class so you don't need to compile and link FedeList.cpp because it's included into FedeList.hpp.

#License
Fedelist is distributed with GPL license.
