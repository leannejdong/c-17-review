## Rvalue References

Suppose we write a class called Dinosaur, a function can take a Dinosaur parameter many ways:

* `Dinosaur x` - a solid instance of Dinosaur

* `Dinosaur* x - a pointer to some solid instance of Dinosaur

* `Dinosaur &x` - a reference to some solid instance of Dinosaur

* `Dinosaur &&x` - an rvalue referece to some disappearing instance of Dinosaur

## Lvalue, Rvalue References
* An lvalue (locator value) represents an object that occupies some identifiable location in memory (i.e. has an address)

* Rvalues are defined by exclusion, by saying that every expression is either an lvalue or an rvalue. Therefore, from the above definition of lvalue, an rvalue is an expression that does not represent an object occupying some identifiable location in memory.


## Move sematic

std::move takes an object and allows you to treat it as a temporary (an rvalue). Although it isn’t a semantic requirement, typically a function accepting a reference to an rvalue will invalidate it. When you see std::move, it indicates that the value of the object should not be used afterwards, but you can still assign a new value and continue using it.

## Perfect forwarding

std::forward has a single use case: to cast a templated function parameter (inside the function) to the value category (lvalue or rvalue) the caller used to pass it. This allows rvalue arguments to be passed on as rvalues, and lvalues to be passed on as lvalues, a scheme called ``perfect forwarding.”

## Example

[Difference between `std::move` vs `std::forward`](https://compiler-explorer.com/z/jPxvEefTr)

ref: https://isocpp.org/blog/2018/02/quick-q-whats-the-difference-between-stdmove-and-stdforward